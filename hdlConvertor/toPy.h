#pragma once
#include <Python.h>
#include <vector>
#include <typeinfo>

#include <hdlConvertor/hdlObjects/arch.h>
#include <hdlConvertor/hdlObjects/compInstance.h>
#include <hdlConvertor/hdlObjects/context.h>
#include <hdlConvertor/hdlObjects/entity.h>
#include <hdlConvertor/hdlObjects/expr.h>
#include <hdlConvertor/hdlObjects/function.h>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/operator.h>
#include <hdlConvertor/hdlObjects/operatorType.h>
#include <hdlConvertor/hdlObjects/package.h>
#include <hdlConvertor/hdlObjects/packageHeader.h>
#include <hdlConvertor/hdlObjects/process.h>
#include <hdlConvertor/hdlObjects/statement.h>
#include <hdlConvertor/hdlObjects/variable.h>


namespace hdlConvertor {

class ToPy {
	PyObject* hdlAst_module;
	PyObject* ContextCls;
	PyObject* CodePositionCls;
	PyObject* HdlModuleDefCls;
	PyObject* HdlModuleDecCls;
	PyObject* HdlVariableDefCls;
	PyObject* HdlCallCls;
	PyObject* HdlBuildinFnEnum;
	PyObject* HdlIntValueCls;
	PyObject* HdlNameCls;
	PyObject* HdlDirectionEnum;
	PyObject* HdlAllCls;
	PyObject* HdlOthersCls;
	PyObject* HdlTypeTypeCls;
	PyObject* HdlIfStmCls;
	PyObject* HdlAssignStmCls;
	PyObject* HdlProcessStmCls;
	PyObject* HdlCaseStmCls;
	PyObject* HdlForStmCls;
	PyObject* HdlWhileStmCls;
	PyObject* HdlReturnStmCls;
	PyObject* HdlBreakStmCls;
	PyObject* HdlContinueStmCls;
	PyObject* HdlImportCls;
	PyObject* HdlWaitStmCls;
	PyObject* HdlComponentInstCls;
	PyObject* HdlFunctionCls;
	PyObject* HdlNamespaceCls;

	std::string PyObject_repr(PyObject * o);

	template<typename OBJ_T>
	int toPy_arr(PyObject * parent, const std::string & prop_name,
			const std::vector<OBJ_T> & objs) {

		PyObject * parent_list = PyObject_GetAttrString(parent,
				prop_name.c_str());
		if (parent_list == nullptr) {
			std::string err_msg = (std::string(
					"ToPy::toPy_arr object does not have specified property:")
					+ prop_name + std::string(" : ")
					+ PyObject_repr(parent));
			PyErr_SetString(PyExc_ValueError, err_msg.c_str());
			return -1;
		}
		for (auto o : objs) {
			auto py_obj = toPy(o);
			if (py_obj == nullptr) {
				return -1;
			}
			auto e = PyList_Append(parent_list, py_obj);
			Py_DECREF(py_obj);
			if (e) {
				Py_DECREF(parent_list);
				return e;
			}
		}
		return 0;
	}
	std::pair<PyObject *, size_t> cases_toPy(
			std::vector<hdlObjects::Expr*>::const_iterator cond_begin,
			std::vector<hdlObjects::Expr*>::const_iterator cond_end,
			std::vector<std::vector<hdlObjects::iHdlObj*>*>::const_iterator stms_begin);
	static constexpr size_t SIZE_T_ERR = std::numeric_limits<size_t>::max();
public:
	ToPy();

	int toPy(const hdlObjects::WithNameAndDoc * o, PyObject * py_inst);
	int toPy(const hdlObjects::WithDoc * o, PyObject * py_inst);

	PyObject* toPy(const hdlObjects::Arch * o);
	PyObject* toPy(const hdlObjects::CompInstance * o);
	PyObject* toPy(const hdlObjects::Context * o);
	PyObject* toPy(const hdlObjects::Direction o);
	PyObject* toPy(const hdlObjects::Entity * o);
	PyObject* toPy(const hdlObjects::Expr * o);
	PyObject* toPy(const hdlObjects::Function * o);
	PyObject* toPy(const hdlObjects::iHdlObj * o);
	PyObject* toPy(const hdlObjects::Operator * o);
	PyObject* toPy(const hdlObjects::OperatorType o);
	PyObject* toPy(const hdlObjects::Package* o, bool declaration_only=false);
	PyObject* toPy(const hdlObjects::PackageHeader* o);
	PyObject* toPy(const hdlObjects::Statement * o);
	PyObject* toPy(const hdlObjects::LiteralVal * o);
	PyObject* toPy(const hdlObjects::Variable * o);
	PyObject* toPy(const std::string & o);

	~ToPy();
};

}
