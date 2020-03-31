from hdlConvertor.to.hdl_ast_visitor import HdlAstVisitor
from hdlConvertor.to.verilog.utils import collect_array_dims
from hdlConvertor.hdlAst._expr import HdlIntValue
from hdlConvertor.translate._verilog_to_basic_hdl_sim_model.utils import hdl_getattr


class AssignmentToUpdateAssignment(HdlAstVisitor):
    """
    Convert an assignment to an assignment of a update.
    Assignment of a update has folowing format:

    .. code-block:: python

        # dst is a name of destination signal
        # src is name of source signal or value
        # is_clock_edge_dependent is a flag which tells if
        # the assignment is updating some clock edge memory

        # scalar updater
        dst.val_next = (src, is_clock_edge_dependent)

        # updater for array element
        dst.val_next = (src, indexes, is_clock_edge_dependent)

    """

    def pop_index_list(self, o):
        """
        :type o: iHdlExpr
        """
        return collect_array_dims(o)

    def is_clock_edge_dependent(self, o):
        """
        :type o: HdlStmAssign
        """
        return HdlIntValue(0, 1, None)

    def visit_HdlStmAssign(self, o):
        """
        :type o: HdlStmAssign
        """
        assert o.event_delay is None, o
        assert o.time_delay is None, o
        is_clock_edge_dependent = self.is_clock_edge_dependent(o)
        dst, dst_index = self.pop_index_list(o.dst)
        o.dst = hdl_getattr(dst, "val_next")
        if dst_index:
            o.src = [o.src, dst_index, is_clock_edge_dependent]
        else:
            o.src = [o.src,  is_clock_edge_dependent]
