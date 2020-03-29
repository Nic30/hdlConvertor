from hdlConvertor.hdlAst._statements import HdlStmProcess
from hdlConvertor.hdlAst._structural import HdlModuleDef, HdlModuleDec


class AddUniqueLabelsToAllProcesses():

    def __init__(self):
        self.reset_name_context()

    def reset_name_context(self):
        self.used_names = set()
        self.name_prefix_cntr = {}

    def checked_name(self, n):
        un = self.used_names
        npc = self.name_prefix_cntr
        _n = n
        while _n in un:
            # try find an available name by incrementing counter behind the
            # name
            i = npc.get(n, 0)
            _n = "%s_%d" % (n, i)
            npc[n] = i + 1
        assert len(_n) > 0
        un.add(n)
        return _n

    def module_def(self, m):
        """
        :type m: HdlModuleDef
        """
        self.used_names = set()
        proc_with_missing_name = []
        for o in m.objs:
            if isinstance(o, HdlStmProcess):
                if o.labels:
                    label = o.labels[0]
                    o.labels[0] = self.checked_name(label)
                else:
                    proc_with_missing_name.append(o)
        # named processes are checked first in order to preserver their names
        # and avoid potential collision with generated names
        for o in proc_with_missing_name:
            o.labels.append(self.checked_name("proc"))

    def context(self, context):
        """
        :type context: HdlContext
        """
        for o in context.objs:
            if isinstance(o, HdlModuleDec):
                self.module_def(o.body)
