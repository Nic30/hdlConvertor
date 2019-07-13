#include "toPy.h"
#include <tuple>
#include <hdlConvertor/hdlObjects/hdlStmAssign.h>

namespace hdlConvertor {

using namespace hdlObjects;

PyObject* ToPy::toPy(const iHdlStatement * o) {
	auto & exprs = o->exprs;
	auto & sub_statements = o->sub_statements;
	auto type = o->type;
	PyObject* py_inst = nullptr;
	int e = 0;

	if (type == s_EXPR) {
		return toPy(exprs[0]);
	} else if (type == s_IF) {
		py_inst = PyObject_CallObject(HdlStmIfCls, NULL);
		if (!py_inst) {
			return nullptr;
		}

		e = PyObject_SetAttrString(py_inst, "cond", toPy(exprs[0]));
		if (e < 0) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		assert(sub_statements.size());
		e = toPy_arr(py_inst, "if_true", *sub_statements[0]);
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		PyObject * elseIfs;
		size_t elif_cnt;
		std::tie(elseIfs, elif_cnt) = cases_toPy(exprs.begin() + 1, exprs.end(),
				sub_statements.begin() + 1);
		if (elseIfs) {
			if (PyObject_SetAttrString(py_inst, "elifs", elseIfs) < 0) {
				Py_DECREF(py_inst);
				return nullptr;
			}
		}
		if (elif_cnt == SIZE_T_ERR) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		if (sub_statements.size() > elif_cnt + 1) {
			auto & if_false = *sub_statements.at(elif_cnt + 1);
			auto py_if_false = PyList_New(0);
			if (!py_if_false)
				e = -1;
			if (!e)
				e = PyObject_SetAttrString(py_inst, "if_false", py_if_false);
			if (!e)
				e = toPy_arr(py_inst, "if_false", if_false);
			if (e) {
				Py_DECREF(py_inst);
				return nullptr;
			}
		}

	} else if (type == s_CASE) {
		py_inst = PyObject_CallObject(HdlStmCaseCls, NULL);
		if (!py_inst) {
			return nullptr;
		}
		e = PyObject_SetAttrString(py_inst, "switch_on", toPy(exprs[0]));
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		PyObject * c;
		size_t c_cnt;
		std::tie(c, c_cnt) = cases_toPy(exprs.begin() + 1, exprs.end(),
				sub_statements.begin());
		if (c) {
			PyObject_SetAttrString(py_inst, "cases", c);
		}
		if (c_cnt == SIZE_T_ERR) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		if (sub_statements.size() > c_cnt) {
			auto & def = *sub_statements.at(c_cnt);
			auto py_def = PyList_New(0);
			if (!py_def)
				e = -1;
			if (!e)
				e = PyObject_SetAttrString(py_inst, "default", py_def);
			if (!e)
				e = toPy_arr(py_inst, "default", def);

			if (e) {
				Py_DECREF(py_inst);
				return nullptr;
			}
		}

	} else if (type == s_FOR) {
		py_inst = PyObject_CallObject(HdlStmForCls, NULL);
		if (!py_inst) {
			return nullptr;
		}

		e = toPy_arr(py_inst, "init", *sub_statements[0]);
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		e = PyObject_SetAttrString(py_inst, "cond", toPy(exprs[0]));
		if (e < 0) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		e = toPy_arr(py_inst, "step", *sub_statements[1]);
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		e = toPy_arr(py_inst, "body", *sub_statements[2]);
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
	} else if (type == s_FOR_IN) {
		py_inst = PyObject_CallObject(HdlStmForInCls, NULL);
		if (!py_inst) {
			return nullptr;
		}

		e = toPy_arr(py_inst, "var", *sub_statements[0]);
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		e = PyObject_SetAttrString(py_inst, "collection", toPy(exprs[0]));
		if (e < 0) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		e = toPy_arr(py_inst, "body", *sub_statements[1]);
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
	} else if (type == s_RETURN) {
		py_inst = PyObject_CallObject(HdlStmReturnCls, NULL);
		if (!py_inst) {
			return nullptr;
		}

		PyObject* v;
		if (exprs.size()) {
			assert(exprs.size() == 1);
			v = toPy(exprs[0]);
		} else {
			Py_INCREF(Py_None);
			v = Py_None;
		}
		e = PyObject_SetAttrString(py_inst, "val", v);
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}

	} else if (type == s_BREAK) {
		py_inst = PyObject_CallObject(HdlStmBreakCls, NULL);
	} else if (type == s_CONTINUE) {
		py_inst = PyObject_CallObject(HdlStmContinueCls, NULL);
	} else if (type == s_ASSIGNMENT) {
		PyObject *src = nullptr, *dst = nullptr, *time_delay = nullptr,
				*event_delay = nullptr;
		do {
			src = toPy(o->exprs[1]);
			if (!src)
				break;
			dst = toPy(o->exprs[0]);
			if (!dst) {
				break;
			}
			if (o->exprs[2]) {
				time_delay = toPy(o->exprs[2]);
				if (!time_delay)
					break;
			} else {
				Py_INCREF(Py_None);
				time_delay = Py_None;
			}
			if (o->exprs.size() > 3) {
				event_delay = PyList_New(o->exprs.size() - 3);
				for (size_t i = 2; i < o->exprs.size(); i++) {
					auto py_obj = toPy(o->exprs[i]);
					if (py_obj == nullptr) {
						break;
					}
					if (PyList_SetItem(event_delay, i, py_obj)) {
						break;
					}
				}
			}

			py_inst = PyObject_CallFunctionObjArgs(HdlStmAssignCls,
					src, dst, time_delay, event_delay, NULL);
			if (!py_inst) {
				break;
			}
			auto _o = dynamic_cast<const HdlStmAssign*>(o);
			e = PyObject_SetAttrString(py_inst, "is_blocking",
					PyBool_FromLong((long) _o->is_blocking));

		} while (0);
		if (e || !py_inst) {
			Py_DECREF(src);
			Py_DECREF(dst);
			Py_DECREF(time_delay);
			Py_DECREF(event_delay);

			return nullptr;
		}

	} else if (type == s_WHILE) {
		py_inst = PyObject_CallObject(HdlStmWhileCls, NULL);
		if (!py_inst) {
			return nullptr;
		}

		e = PyObject_SetAttrString(py_inst, "cond", toPy(exprs[0]));
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		e = toPy_arr(py_inst, "body", *sub_statements[0]);
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
	} else if (type == s_PROCESS) {
		auto p = dynamic_cast<const HdlStmProcess*>(o);
		assert(p);

		py_inst = PyObject_CallObject(HdlStmProcessCls, NULL);
		if (!py_inst) {
			return nullptr;
		}

		if (p->sensitivity_list_specified) {
			auto & sl = p->sensitivity_list();
			auto py_sl = PyList_New(0);
			if (!py_sl)
				e = -1;
			if (!e)
				e = PyObject_SetAttrString(py_inst, "sensitivity", py_sl);
			if (!e)
				e = toPy_arr(py_inst, "sensitivity", sl);
		} else {
			assert(exprs.size() == 0);
		}
		if (!e)
			e = toPy_arr(py_inst, "body", p->objs());
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
	} else if (type == s_WAIT) {
		py_inst = PyObject_CallObject(HdlStmWaitCls, NULL);
		if (!py_inst) {
			return nullptr;
		}
		e = toPy_arr(py_inst, "val", exprs);
	} else if (type == s_IMPORT) {
		py_inst = PyObject_CallObject(HdlImportCls, NULL);
		if (!py_inst) {
			return nullptr;
		}

		e = toPy_arr(py_inst, "path", o->exprs);
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
	} else {
		throw std::runtime_error("Invalid StatementType");
	}
	if (!e)
		e = toPy(static_cast<const WithDoc*>(o), py_inst);
	if (!e)
		e = toPy_arr(py_inst, "labels", o->labels);
	if (!e)
		e = PyObject_SetAttrString(py_inst, "in_prepoc",
				PyBool_FromLong((long) o->in_preproc));
	if (e < 0) {
		Py_XDECREF(py_inst);
		return nullptr;
	}

	return py_inst;
}

std::pair<PyObject *, size_t> ToPy::cases_toPy(
		std::vector<iHdlExpr*>::const_iterator cond_begin,
		std::vector<iHdlExpr*>::const_iterator cond_end,
		std::vector<std::vector<iHdlObj*>*>::const_iterator stms_begin) {
	PyObject * cases = nullptr;
	size_t size = cond_end - cond_begin;
	if (size) {
		cases = PyList_New(size);
		if (!cases) {
			Py_DECREF(cases);
			return {nullptr, SIZE_T_ERR};
		}
	}
	for (size_t case_cnt = 0; case_cnt < size; case_cnt++) {
		// build tuple representing the elif item
		auto case_ = PyTuple_New(2);
		if (!case_) {
			Py_DECREF(cases);
			return {nullptr, SIZE_T_ERR};
		}
		// add to elif/case list
		int e = PyList_SetItem(cases, case_cnt, case_);
		if (e) {
			Py_DECREF(cases);
			return {nullptr, SIZE_T_ERR};
		}

		iHdlExpr* _c = *cond_begin;
		auto c = toPy(_c);
		if (!c) {
			Py_DECREF(cases);
			return {nullptr, SIZE_T_ERR};
		}

		e = PyTuple_SetItem(case_, 0, c);
		if (e) {
			Py_DECREF(cases);
			return {nullptr, SIZE_T_ERR};
		}

		// fill statements in elif/case
		auto & stms = **stms_begin;
		PyObject * stm_list = PyList_New(stms.size());
		if (!stm_list) {
			Py_DECREF(cases);
			return {nullptr, SIZE_T_ERR};
		}
		e = PyTuple_SetItem(case_, 1, stm_list);
		if (e) {
			Py_DECREF(cases);
			return {nullptr, SIZE_T_ERR};
		}
		for (size_t i = 0; i < stms.size(); i++) {
			auto _o = stms[i];
			assert(_o);
			PyObject * o = toPy(_o);
			if (!o) {
				Py_DECREF(cases);
				return {nullptr, SIZE_T_ERR};
			}
			e = PyList_SetItem(stm_list, i, o);
			if (e) {
				Py_DECREF(cases);
				return {nullptr, SIZE_T_ERR};
			}
		}

		++cond_begin;
		++stms_begin;
	}
	return {cases, size};
}

}
