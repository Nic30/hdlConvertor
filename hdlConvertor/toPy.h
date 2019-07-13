#pragma once
#include <Python.h>
#include <vector>
#include <typeinfo>

#include <hdlConvertor/hdlObjects/hdlCompInstance.h>
#include <hdlConvertor/hdlObjects/hdlContext.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/hdlCall.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>
#include <hdlConvertor/hdlObjects/hdlNamespace.h>
#include <hdlConvertor/hdlObjects/hdlNamespace.h>
#include <hdlConvertor/hdlObjects/hdlStmProcess.h>
#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/hdlModuleDec.h>
#include <hdlConvertor/hdlObjects/hdlModuleDef.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>
#include "../include/hdlConvertor/hdlObjects/hdlFunctionDef.h"

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
	PyObject* HdlTypeAutoCls;
	PyObject* HdlStmIfCls;
	PyObject* HdlStmAssignCls;
	PyObject* HdlStmProcessCls;
	PyObject* HdlStmCaseCls;
	PyObject* HdlStmForCls;
	PyObject* HdlStmForInCls;
	PyObject* HdlStmWhileCls;
	PyObject* HdlStmReturnCls;
	PyObject* HdlStmBreakCls;
	PyObject* HdlStmContinueCls;
	PyObject* HdlStmWaitCls;
	PyObject* HdlImportCls;
	PyObject* HdlComponentInstCls;
	PyObject* HdlFunctionDefCls;
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
					+ prop_name + std::string(" : ") + PyObject_repr(parent));
			PyErr_SetString(PyExc_ValueError, err_msg.c_str());
			return -1;
		}
		return toPy_arr<OBJ_T>(parent_list, objs);
	}

	template<typename OBJ_T>
	int toPy_arr(PyObject * py_list, const std::vector<OBJ_T> & objs) {
		for (auto o : objs) {
			auto py_obj = toPy(o);
			if (py_obj == nullptr) {
				return -1;
			}
			auto e = PyList_Append(py_list, py_obj);
			Py_DECREF(py_obj);
			if (e) {
				Py_DECREF(py_list);
				return e;
			}
		}
		return 0;
	}
	std::pair<PyObject *, size_t> cases_toPy(
			std::vector<hdlObjects::iHdlExpr*>::const_iterator cond_begin,
			std::vector<hdlObjects::iHdlExpr*>::const_iterator cond_end,
			std::vector<std::vector<hdlObjects::iHdlObj*>*>::const_iterator stms_begin);
	static constexpr size_t SIZE_T_ERR = std::numeric_limits<size_t>::max();
public:
	ToPy();

	int toPy(const hdlObjects::WithNameAndDoc * o, PyObject * py_inst);
	int toPy(const hdlObjects::WithDoc * o, PyObject * py_inst);

	PyObject* toPy(const hdlObjects::HdlModuleDef * o);
	PyObject* toPy(const hdlObjects::HdlCompInstance * o);
	PyObject* toPy(const hdlObjects::HdlContext * o);
	PyObject* toPy(const hdlObjects::HdlDirection o);
	PyObject* toPy(const hdlObjects::HdlModuleDec * o);
	PyObject* toPy(const hdlObjects::iHdlExpr * o);
	PyObject* toPy(const hdlObjects::HdlFunctionDef * o);
	PyObject* toPy(const hdlObjects::iHdlObj * o);
	PyObject* toPy(const hdlObjects::HdlCall * o);
	PyObject* toPy(const hdlObjects::HdlOperatorType o);
	PyObject* toPy(const hdlObjects::HdlNamespace* o);
	PyObject* toPy(const hdlObjects::iHdlStatement * o);
	PyObject* toPy(const hdlObjects::HdlValue * o);
	PyObject* toPy(const hdlObjects::HdlVariableDef * o);
	PyObject* toPy(const std::string & o);

	~ToPy();
};

}
