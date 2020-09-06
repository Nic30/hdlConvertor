#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <vector>

#include <hdlConvertor/hdlAst/hdlCompInst.h>
#include <hdlConvertor/hdlAst/hdlContext.h>
#include <hdlConvertor/hdlAst/hdlLibrary.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/hdlAst/named.h>
#include <hdlConvertor/hdlAst/hdlOp.h>
#include <hdlConvertor/hdlAst/hdlOpType.h>
#include <hdlConvertor/hdlAst/hdlNamespace.h>
#include <hdlConvertor/hdlAst/hdlModuleDec.h>
#include <hdlConvertor/hdlAst/hdlModuleDef.h>
#include <hdlConvertor/hdlAst/hdlIdDef.h>
#include <hdlConvertor/hdlAst/hdlFunctionDef.h>
#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/hdlAst/hdlStm_others.h>
#include <hdlConvertor/hdlAst/hdlStmAssign.h>
#include <hdlConvertor/hdlAst/hdlStmBlock.h>
#include <hdlConvertor/hdlAst/hdlStmCase.h>
#include <hdlConvertor/hdlAst/hdlStmExpr.h>
#include <hdlConvertor/hdlAst/hdlStmFor.h>
#include <hdlConvertor/hdlAst/hdlStmIf.h>
#include <hdlConvertor/hdlAst/hdlStmProcess.h>
#include <hdlConvertor/hdlAst/hdlStmWhile.h>
#include <hdlConvertor/hdlAst/hdlTypes.h>
#include <hdlConvertor/hdlAst/hdlValue.h>

namespace hdlConvertor {

class ToPy {
	PyObject *hdlAst_module;
	PyObject *ContextCls;
	PyObject *CodePositionCls;
	PyObject *HdlModuleDefCls;
	PyObject *HdlModuleDecCls;
	PyObject *HdlIdDefCls;
	PyObject *HdlOpCls;
	PyObject *HdlOpTypeEnum;
	PyObject *HdlValueIntCls;
	PyObject *HdlExprNotImplementedCls;
	PyObject *HdlValueIdCls;
	PyObject *HdlDirectionEnum;
	PyObject *HdlAllCls;
	PyObject *HdlOthersCls;
	PyObject *HdlTypeAutoCls;
	PyObject *HdlTypeTypeCls;
	PyObject *HdlTypeSubtypeCls;
	PyObject *HdlClassTypeEnum;
	PyObject *HdlClassDefCls;
	PyObject *HdlPhysicalDefCls;
	PyObject *HdlEnumDefCls;
	PyObject *HdlStmIfCls;
	PyObject *HdlStmAssignCls;
	PyObject *HdlStmProcessCls;
	PyObject *HdlStmCaseTypeEnum;
	PyObject *HdlStmCaseCls;
	PyObject *HdlStmForCls;
	PyObject *HdlStmForInCls;
	PyObject *HdlStmWhileCls;
	PyObject *HdlStmRepeatCls;
	PyObject *HdlStmReturnCls;
	PyObject *HdlStmBreakCls;
	PyObject *HdlStmContinueCls;
	PyObject *HdlStmWaitCls;
	PyObject *HdlStmBlockCls;
	PyObject *HdlStmBlockJoinTypeCls;
	PyObject *HdlImportCls;
	PyObject *HdlLibraryCls;
	PyObject *HdlCompInstCls;
	PyObject *HdlFunctionDefCls;
	PyObject *HdlValueIdspaceCls;

	std::string PyObject_repr(PyObject *o);

	template<typename OBJ_T>
	int toPy_dict(PyObject *parent, const std::string &prop_name,
			const std::vector<std::pair<std::string, OBJ_T>> &objs) {
		PyObject *parent_dict = PyObject_GetAttrString(parent,
				prop_name.c_str());
		if (parent_dict == nullptr) {
			std::string err_msg = (std::string(
					"ToPy::toPy_arr object does not have specified property:")
					+ prop_name + std::string(" : ") + PyObject_repr(parent));
			Py_DECREF(parent);
			PyErr_SetString(PyExc_ValueError, err_msg.c_str());
			return -1;
		}
		for (const auto &o : objs) {
			const auto &key = o.first;
			const auto &py_val = toPy(o.second);
			if (py_val == nullptr) {
				Py_DECREF(parent_dict);
				return -1;
			}
			auto e = PyDict_SetItemString(parent_dict, key.c_str(), py_val);
			Py_DECREF(py_val); // needed? docs say SetItem doesn't steal a reference
			if (e) {
				Py_DECREF(parent_dict);
				return e;
			}
		}
		return 0;
	}

	template<typename OBJ_T>
	int toPy_arr(PyObject *parent, const std::string &prop_name,
			const std::vector<OBJ_T> &objs) {

		PyObject *parent_list = PyObject_GetAttrString(parent,
				prop_name.c_str());
		if (parent_list == nullptr) {
			std::string err_msg = (std::string(
					"ToPy::toPy_arr object does not have specified property:")
					+ prop_name + std::string(" : ") + PyObject_repr(parent));
			Py_DECREF(parent);
			PyErr_SetString(PyExc_ValueError, err_msg.c_str());
			return -1;
		}
		return toPy_arr<OBJ_T>(parent_list, objs);
	}

	template<typename OBJ_T>
	int toPy_arr(PyObject *py_list, const std::vector<OBJ_T> &objs) {
		for (auto &o : objs) {
			auto py_obj = toPy(o);
			if (py_obj == nullptr) {
				Py_DECREF(py_list);
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

	int toPy_property(PyObject *py_inst, const char *prop_name,
			PyObject *py_o) {
		int e = PyObject_SetAttrString(py_inst, prop_name, py_o);
		if (e < 0) {
			Py_DECREF(py_inst);
			return -1;
		}
		return 0;
	}
	template<typename OBJ_T>
	int toPy_property(PyObject *py_inst, const char *prop_name,
			const std::unique_ptr<OBJ_T> &o) {
		auto py_o = toPy(o.get());
		if (!py_o) {
			Py_DECREF(py_inst);
			return -1;
		}
		return toPy_property(py_inst, prop_name, py_o);
	}
	template<typename OBJ_T>
	int toPy_property(PyObject *py_inst, const char *prop_name,
			const OBJ_T &o) {
		auto py_o = toPy(o);
		if (!py_o) {
			Py_DECREF(py_inst);
			return -1;
		}
		return toPy_property(py_inst, prop_name, py_o);
	}
public:
	ToPy();

	// automatic conversion from std::unique_ptr<T> to const T * for any type
	template<typename T>
	PyObject* toPy(const std::unique_ptr<T> &o) {
		return toPy(o.get());
	}

	int toPy(const hdlAst::WithNameAndDoc *o, PyObject *py_inst);
	int toPy(const hdlAst::WithDoc *o, PyObject *py_inst);
	int toPy(const hdlAst::WithPos *o, PyObject *py_inst);

	PyObject* toPy(const hdlConvertor::hdlAst::HdlExprAndiHdlObj &o);
	PyObject* toPy(const hdlAst::iHdlStatement *o);
	PyObject* toPy(const hdlAst::HdlModuleDef *o);
	PyObject* toPy(const hdlAst::HdlCompInst *o);
	PyObject* toPy(const hdlAst::HdlContext *o);
	PyObject* toPy(const hdlAst::HdlLibrary *o);
	PyObject* toPy(const hdlAst::HdlDirection o);
	PyObject* toPy(const hdlAst::HdlModuleDec *o);
	PyObject* toPy(const hdlAst::iHdlExprItem *o);
	PyObject* toPy(const hdlAst::HdlOp *o);
	PyObject* toPy(const hdlAst::HdlValueArr *o);
	PyObject* toPy(const hdlAst::HdlValueFloat *o);
	PyObject* toPy(const hdlAst::HdlValueId *o);
	PyObject* toPy(const hdlAst::HdlValueInt *o);
	PyObject* toPy(const hdlAst::HdlValueStr *o);
	PyObject* toPy(const hdlAst::HdlValueSymbol *o);
	PyObject* toPy(const hdlAst::HdlClassType o);
	PyObject* toPy(const hdlAst::HdlClassDef *o);
	PyObject* toPy(const hdlAst::HdlPhysicalDef *o);
	PyObject* toPy(const hdlAst::HdlEnumDef *o);
	PyObject* toPy(const hdlAst::HdlExprNotImplemented *o);
	PyObject* toPy(const hdlAst::HdlFunctionDef *o);
	PyObject* toPy(const hdlAst::iHdlObj *o);
	PyObject* toPy(const hdlAst::HdlOpType o);
	PyObject* toPy(const hdlAst::HdlValueIdspace *o);
	PyObject* toPy(const hdlAst::HdlIdDef *o);
	PyObject* toPy(const hdlAst::HdlStmExpr *o);
	PyObject* toPy(const hdlAst::HdlStmIf *o);
	PyObject* toPy(const hdlAst::HdlStmBlockJoinType o);
	PyObject* toPy(const hdlAst::HdlStmBlock *o);
	PyObject* toPy(const hdlAst::HdlStmCaseType o);
	PyObject* toPy(const hdlAst::HdlStmCase *o);
	PyObject* toPy(const hdlAst::HdlStmFor *o);
	PyObject* toPy(const hdlAst::HdlStmForIn *o);
	PyObject* toPy(const hdlAst::HdlStmRepeat *o);
	PyObject* toPy(const hdlAst::HdlStmReturn *o);
	PyObject* toPy(const hdlAst::HdlStmAssign *o);
	PyObject* toPy(const hdlAst::HdlStmWhile *o);
	PyObject* toPy(const hdlAst::HdlStmProcess *o);
	PyObject* toPy(const hdlAst::HdlStmWait *o);
	PyObject* toPy(const hdlAst::HdlStmImport *o);
	PyObject* toPy(const hdlAst::CodePosition o);
	PyObject* toPy(const std::string &o);
	PyObject* toPy(size_t o);
	PyObject* toPy(bool o);
	PyObject* toPy(
			const std::pair<const std::string*, const hdlAst::iHdlExprItem*> &o);
	PyObject* toPy(
			const std::pair<std::unique_ptr<std::string>,
					std::unique_ptr<hdlAst::iHdlExprItem>> &o);
	PyObject* toPy(
			const std::pair<std::string, std::unique_ptr<hdlAst::iHdlExprItem>> &o);

	~ToPy();
};

extern const char* get_cpp_py_error_message();

}
