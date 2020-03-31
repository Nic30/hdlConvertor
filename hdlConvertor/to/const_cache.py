
class ConstCache(object):
    """
    Container of constants for serializer.
    Used to extract constants as constant variables.
    """

    def __init__(self, nameCheckFn):
        self.nameCheckFn = nameCheckFn

        # {value:usedName}
        self._cache = {}

    def getConstName(self, val):
        """
        Get constant name for value
        name of constant is reused if same value was used before
        """
        try:
            return self._cache[val]
        except KeyError:
            if isinstance(val.val, int):
                if val.val < 0:
                    name = "const_m%d_" % -val.val
                else:
                    name = "const_%d_" % val.val
            else:
                name = "const_"

            c = self.nameCheckFn(name, val)
            self._cache[val] = c
            return c
