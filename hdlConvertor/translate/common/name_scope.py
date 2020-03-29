from typing import Optional


class LangueKeyword(object):
    """
    Base class for keywords of target language.
    Used to notify that the name represents a language keyword
    and thus shall not be modified.
    """
    pass


class NameOccupiedErr(Exception):
    def __init__(self, usedOn):
        super(NameOccupiedErr, self).__init__()
        self.usedOn = usedOn


class ObjectForNameNotFound(KeyError):
    pass


class NameScope(dict):
    """
    Scope of used names in hdl (node of hierarchical symbol table).
    Used to find an object for a HdlName or HdlName for an object and
    to resolve collision between different object of a same name if required.

    Contains mapping {name: obj}

    if name is discovered in scope it is converted to name_id
    where id is sequential number for prefix name\_

    :ivar ~.level: describes how deeply nested is this NameScopeItem in 
        name hierarchy
    :ivar ~.cntrsForPrefixNames: conters for prefix names (for each name which
        has to be renamed there is a counter which is used to find a non occupied
        name faster)
    :ivar ~.reversed: a reverse dict to this dict ({obj: name})
    :ivar ~.serializer_ctx: an object with metainformations private to a current
        serializer
    :ivar ~.children: a dictionary {object which caused a NameScope fork: new NameScope}
    """
    @classmethod
    def make_top(cls, ignorecase):
        return cls(None, None, ignorecase)

    def update(self, other):
        for k, v in other.items():
            self.__registerName(k, v)

    def __init__(self, parent, name, ignorecase):
        """
        :type parent: Optional[NameScope]
        :param name: name of object which this namescope belongs to
        :type name: Optional[str]
        :note: parent=None, name=None for global namescope
        :param ignorecase: if True the name comparison does not
            care about lowercase/uppercase
        """
        super().__init__()
        self.parent = parent
        self.ignorecase = ignorecase

        # some names are specified just as prefix and serializer
        # should resolve correct name for object
        # this happens for most of generated objects
        self.cntrsForPrefixNames = {}
        self.reversed = {}
        self.serializer_ctx = None
        self.children = {}
        self.name = name

    def getParent(self, parent: "NameScope"):
        if self.level < 1:
            return None
        else:
            return parent[self.level - 1]

    # @internal
    def __incrPrefixCntr(self, prefix,
                         currentVal) -> str:
        # [TODO] check if new name is not defined in any direction (parent-children)
        currentVal += 1
        self.cntrsForPrefixNames[prefix] = currentVal
        usableName = prefix + str(currentVal)
        return usableName

    # @internal
    def __registerName(self, name, obj):
        # search if name is already defined on me and parents
        actual = self
        o = None

        if self.ignorecase:
            _name = name.lower()
        else:
            _name = name

        while actual is not None:
            try:
                o = actual[_name]
            except KeyError:
                actual = actual.parent
                continue
            break

        if o is None or o is obj:
            # we can use use the name, because it is not used
            # in any parent
            self[_name] = obj
            self.reversed[obj] = _name
        else:
            raise NameOccupiedErr(o)

    def get_children(self, name):
        if self.ignorecase:
            name = name.lower()
        return self.children[name]

    def level_push(self, name):
        if self.ignorecase:
            name = name.lower()

        assert name in self, (
            name, "name has to be assigned to something in this scope")
        i = self.__class__(self, name, self.ignorecase)
        self.children[name] = i
        return i

    def level_pop(self):
        return self.pop()

    def checkedName(self, suggestedName, obj) -> str:
        if not suggestedName.endswith("_"):
            try:
                self.__registerName(suggestedName, obj)
                return suggestedName
            except NameOccupiedErr:
                suggestedName += "_"

        actual = self
        while actual is not None:
            try:
                cntrVal = actual.cntrsForPrefixNames[suggestedName]
                break
            except KeyError:
                actual = actual.parent

        if actual is not None:
            # some parrent of self already have such a prefix counter
            usableName = actual.__incrPrefixCntr(
                suggestedName, cntrVal)
        else:
            # parrents and self does not have such a prefix counter
            # delete potentially existing prefix conterrs from children
            # and add prefix counter to self
            cntrVal = self.__discard_prefix_cntrs_from_children(suggestedName)
            usableName = self.__incrPrefixCntr(
                suggestedName, cntrVal)
        # setup for me and propagate to children
        self.__registerName(usableName, obj)
        return usableName

    def __discard_prefix_cntrs_from_children(self, prefix):
        """
        Discard all prefix conters from all childrens in order to prevent
        children from looping trought all occupied names.
        """
        cntr_val = self.cntrsForPrefixNames.pop(prefix, -1)
        for c in self.children.values():
            cntr_val = max(cntr_val, c.__discard_prefix_cntrs_from_children(prefix))
        return cntr_val

    def get_object_name(self, obj):
        assert obj is not None
        actual = self
        while actual is not None:
            n = actual.reversed.get(obj, None)
            if n is not None:
                return n
            actual = actual.parent

        raise ObjectForNameNotFound(obj)
