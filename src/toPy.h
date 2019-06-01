#pragma once
#include <Python.h>
#include <vector>

#include "hdlObjects/named.h"
#include "hdlObjects/context.h"
#include "hdlObjects/entity.h"
#include "hdlObjects/arch.h"
#include "hdlObjects/expr.h"
#include "hdlObjects/variable.h"
#include "hdlObjects/operator.h"
#include "hdlObjects/operatorType.h"
#include "hdlObjects/statement.h"

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
	PyObject* HdlTypeTypeCls;
	PyObject* HdlIfStmCls;
	PyObject* HdlAssignStmCls;
	PyObject* HdlProcessStmCls;
	PyObject* HdlCaseStmCls;
	PyObject* HdlForStmCls;
	PyObject* HdlWhileStmCls;
	PyObject* HdlReturnCls;
	PyObject* HdlBreakStmCls;
	PyObject* HdlContinueStmCls;
	PyObject* HdlImportCls;

	template<typename OBJ_T>
	void toPy_arr(PyObject * parent, const std::string & prop_name,
			const std::vector<OBJ_T> & objs) {
		PyObject * parent_list = PyObject_GetAttrString(parent,
				prop_name.c_str());
		for (auto o : objs) {
			auto py_obj = toPy(o);
			if (py_obj) {
				throw std::runtime_error("ToPy::toPy_arr: toPy failed");
			}
			auto e = PyList_Append(parent_list, py_obj);
			Py_DECREF(py_obj);
			if (e) {
				throw std::runtime_error("ToPy::toPy_arr: can not add items to list");
			}
		}
	}
	std::pair<PyObject *, size_t> cases_toPy(
			std::vector<hdlObjects::Expr*>::const_iterator cond_begin,
			std::vector<hdlObjects::Expr*>::const_iterator cond_end,
			std::vector<std::vector<hdlObjects::iHdlObj*>*>::const_iterator stms_begin);
public:
	ToPy();

	void toPy(const hdlObjects::WithNameAndDoc * o, PyObject * py_inst);
	void toPy(const hdlObjects::WithDoc * o, PyObject * py_inst);
	PyObject* toPy(const hdlObjects::Symbol * o);
	PyObject* toPy(const hdlObjects::Operator * o);
	PyObject* toPy(const hdlObjects::OperatorType o);
	PyObject* toPy(const hdlObjects::Direction o);
	PyObject* toPy(const hdlObjects::Context * o);
	PyObject* toPy(const hdlObjects::iHdlObj * o);
	PyObject* toPy(const hdlObjects::Entity * o);
	PyObject* toPy(const hdlObjects::Expr * o);
	PyObject* toPy(const hdlObjects::Variable * o);
	PyObject* toPy(const hdlObjects::Statement * o);
	PyObject* toPy(const std::string & o);


	~ToPy();
};

}
