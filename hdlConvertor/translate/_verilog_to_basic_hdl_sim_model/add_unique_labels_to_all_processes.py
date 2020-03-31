from hdlConvertor.hdlAst._statements import HdlStmProcess
from hdlConvertor.hdlAst._structural import HdlModuleDef, HdlModuleDec


class AddUniqueLabelsToAllProcesses():

    def __init__(self, name_scope, stm_outputs):
        """
        :type name_scope: NameScope
        :type stm_outputs: Dict[iHdlStatement, ]
        """
        self.name_scope = name_scope
        self.stm_outputs = stm_outputs

    def module_def(self, m):
        """
        :type m: HdlModuleDef
        """
        for o in m.objs:
            if isinstance(o, HdlStmProcess):
                if not o.labels:
                    outputs = self.stm_outputs[o]
                    if outputs:
                        suggested_name = "assig_process_" + outputs[0]
                    else:
                        suggested_name = "proc"

                    o.labels.append(self.name_scope.checkedName(suggested_name, o))

    def context(self, context):
        """
        :type context: HdlContext
        """
        for o in context.objs:
            if isinstance(o, HdlModuleDec):
                try:
                    self.name_scope = self.name_scope.get_child(o.name)
                    self.module_def(o.body)
                finally:
                    self.name_scope = self.name_scope.level_pop()
