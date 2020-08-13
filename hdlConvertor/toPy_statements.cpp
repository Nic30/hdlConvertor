#include "toPy.h"
#include <tuple>

namespace hdlConvertor {

using namespace hdlAst;

PyObject* ToPy::toPy(const HdlStmExpr *o) {
	return toPy(o->expr);
}
PyObject* ToPy::toPy(const HdlStmIf *o) {
	auto py_inst = PyObject_CallObject(HdlStmIfCls, NULL);
	if (!py_inst) {
		return nullptr;
	}
	if (toPy_property(py_inst, "cond", o->cond))
		return nullptr;
	if (toPy_property(py_inst, "if_true", o->ifTrue))
		return nullptr;
	if (toPy_arr(py_inst, "elifs", o->elseIfs))
		return nullptr;

	if (o->ifFalse) {
		if (toPy_property(py_inst, "if_false", o->ifFalse))
			return nullptr;
	}
	return py_inst;
}

PyObject* ToPy::toPy(const HdlStmBlockJoinType o) {
	const char *name;
	try {
		name = HdlStmBlockJoinType_toString(o);
	} catch (const std::runtime_error &e) {
		PyErr_SetString(PyExc_ValueError, e.what());
		return nullptr;
	}
	return PyObject_GetAttrString(HdlStmBlockJoinTypeCls, name);
}

PyObject* ToPy::toPy(const HdlStmBlock *o) {
	auto py_inst = PyObject_CallObject(HdlStmBlockCls, NULL);
	if (!py_inst) {
		return nullptr;
	}
	auto join_t = toPy(o->join_t);
	if (!join_t) {
		Py_DECREF(py_inst);
		return nullptr;
	}
	int e = PyObject_SetAttrString(py_inst, "join_t", join_t);
	if (e) {
		Py_DECREF(join_t);
		Py_DECREF(py_inst);
		return nullptr;
	}

	if (toPy_arr(py_inst, "body", o->statements))
		return nullptr;

	return py_inst;
}

PyObject* ToPy::toPy(const HdlStmCase *o) {
	auto py_inst = PyObject_CallObject(HdlStmCaseCls, NULL);
	if (!py_inst) {
		return nullptr;
	}
	if (toPy_property(py_inst, "type", o->type))
		return nullptr;
	if (toPy_property(py_inst, "switch_on", o->select_on))
		return nullptr;
	if (toPy_arr(py_inst, "cases", o->cases))
		return nullptr;

	if (o->default_) {
		if (toPy_property(py_inst, "default", o->default_))
			return nullptr;
	}
	return py_inst;
}

PyObject* ToPy::toPy(const HdlStmCaseType o) {
	const char *name;
	try {
		name = HdlStmCaseType_toString(o);
	} catch (const std::runtime_error &e) {
		PyErr_SetString(PyExc_ValueError, e.what());
		return nullptr;
	}
	return PyObject_GetAttrString(HdlStmCaseTypeEnum, name);
}
PyObject* ToPy::toPy(const HdlStmFor *o) {
	auto py_inst = PyObject_CallObject(HdlStmForCls, NULL);
	if (!py_inst) {
		return nullptr;
	}
	if (toPy_property(py_inst, "init", o->init))
		return nullptr;
	if (toPy_property(py_inst, "cond", o->cond))
		return nullptr;
	if (toPy_property(py_inst, "step", o->step))
		return nullptr;
	if (toPy_property(py_inst, "body", o->body))
		return nullptr;
	return py_inst;
}

PyObject* ToPy::toPy(const HdlStmForIn *o) {
	auto py_inst = PyObject_CallObject(HdlStmForInCls, NULL);
	if (!py_inst) {
		return nullptr;
	}
	if (toPy_arr(py_inst, "var_defs", o->var_defs))
		return nullptr;
	if (toPy_property(py_inst, "collection", o->collection))
		return nullptr;
	if (toPy_property(py_inst, "body", o->body))
		return nullptr;
	return py_inst;
}

PyObject* ToPy::toPy(const HdlStmReturn *o) {
	auto py_inst = PyObject_CallObject(HdlStmReturnCls, NULL);
	if (!py_inst) {
		return nullptr;
	}
	if (o->val)
		if (toPy_property(py_inst, "val", o->val))
			return nullptr;
	return py_inst;
}

PyObject* ToPy::toPy(const HdlStmAssign *o) {
	PyObject *py_inst = nullptr, *src = nullptr, *dst = nullptr, *time_delay =
			nullptr, *event_delay = nullptr;
	int e = 0;
	do {
		src = toPy(o->src);
		if (!src)
			break;
		dst = toPy(o->dst);
		if (!dst) {
			break;
		}
		if (o->time_delay) {
			time_delay = toPy(o->time_delay);
			if (!time_delay)
				break;
		} else {
			Py_INCREF(Py_None);
			time_delay = Py_None;
		}
		if (o->event_delay && o->event_delay->size()) {
			event_delay = PyList_New(o->event_delay->size());
			if (!event_delay)
				break;
			for (size_t i = 0; i < o->event_delay->size(); i++) {
				auto py_obj = toPy((*o->event_delay)[i]);
				if (py_obj == nullptr) {
					e = -1;
					break;
				}
				if (PyList_SetItem(event_delay, i, py_obj)) {
					e = -1;
					break;
				}
			}
			if (e)
				break;
		}

		py_inst = PyObject_CallFunctionObjArgs(HdlStmAssignCls, src, dst,
				time_delay, event_delay, NULL);
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
	return py_inst;
}

PyObject* ToPy::toPy(const HdlStmWhile *o) {
	auto py_inst = PyObject_CallObject(HdlStmWhileCls, NULL);
	if (!py_inst) {
		return nullptr;
	}
	if (toPy_property(py_inst, "cond", o->cond))
		return nullptr;
	if (toPy_property(py_inst, "body", o->body))
		return nullptr;
	return py_inst;
}

PyObject* ToPy::toPy(const HdlStmProcess *o) {
	auto py_inst = PyObject_CallObject(HdlStmProcessCls, NULL);
	if (!py_inst) {
		return nullptr;
	}

	if (o->sensitivity_list) {
		auto sl = PyList_New(0);
		if (!sl) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		if (PyObject_SetAttrString(py_inst, "sensitivity", sl)) {
			Py_DECREF(py_inst);
			Py_DECREF(sl);
			return nullptr;
		}

		if (toPy_arr(sl, *o->sensitivity_list.get())) {
			Py_DECREF(py_inst);
			return nullptr;
		}
	}
	if (toPy_property(py_inst, "body", o->body))
		return nullptr;
	return py_inst;
}

PyObject* ToPy::toPy(const HdlStmImport *o) {
	auto p = PyList_New(0);
	if (toPy_arr(p, o->path)) {
		return nullptr;
	}

	auto py_inst = PyObject_CallFunctionObjArgs(HdlImportCls, p, NULL);
	if (!py_inst) {
		Py_DECREF(p);
		return nullptr;
	}
	return py_inst;
}

PyObject* ToPy::toPy(const HdlStmWait *o) {
	auto py_inst = PyObject_CallObject(HdlStmWaitCls, NULL);
	if (!py_inst) {
		return nullptr;
	}
	if (toPy_arr(py_inst, "val", o->val)) {
		return nullptr;
	}
	return py_inst;
}

PyObject* ToPy::toPy(const HdlStmRepeat *o) {
	auto py_inst = PyObject_CallObject(HdlStmRepeatCls, NULL);
	if (!py_inst) {
		return nullptr;
	}
	if (toPy_property(py_inst, "n", o->n))
		return nullptr;
	if (toPy_property(py_inst, "body", o->body))
		return nullptr;
	return py_inst;
}

PyObject* ToPy::toPy(const iHdlStatement *o) {
	PyObject *py_inst = nullptr;
	do {
		auto ex = dynamic_cast<const HdlStmExpr*>(o);
		if (ex) {
			// @attention currently ignoring labels, doc etc
			return toPy(ex);
		}
		auto n = dynamic_cast<const HdlStmNop*>(o);
		if (n) {
			// @attention currently ignoring labels, doc etc
			Py_RETURN_NONE;
		}
		auto b = dynamic_cast<const HdlStmBlock*>(o);
		if (b) {
			py_inst = toPy(b);
			break;
		}
		auto i = dynamic_cast<const HdlStmIf*>(o);
		if (i) {
			py_inst = toPy(i);
			break;
		}
		auto c = dynamic_cast<const HdlStmCase*>(o);
		if (c) {
			py_inst = toPy(c);
			break;
		}
		auto f = dynamic_cast<const HdlStmFor*>(o);
		if (f) {
			py_inst = toPy(f);
			break;
		}
		auto fi = dynamic_cast<const HdlStmForIn*>(o);
		if (fi) {
			py_inst = toPy(fi);
			break;
		}
		auto rep = dynamic_cast<const HdlStmRepeat*>(o);
		if (rep) {
			py_inst = toPy(rep);
			break;
		}
		auto ret = dynamic_cast<const HdlStmReturn*>(o);
		if (ret) {
			py_inst = toPy(ret);
			break;
		}
		auto br = dynamic_cast<const HdlStmBreak*>(o);
		if (br) {
			py_inst = PyObject_CallObject(HdlStmBreakCls, NULL);
			break;
		}
		auto cn = dynamic_cast<const HdlStmContinue*>(o);
		if (cn) {
			py_inst = PyObject_CallObject(HdlStmContinueCls, NULL);
			break;
		}
		auto a = dynamic_cast<const HdlStmAssign*>(o);
		if (a) {
			py_inst = toPy(a);
			break;
		}
		auto w = dynamic_cast<const HdlStmWhile*>(o);
		if (w) {
			py_inst = toPy(w);
			break;
		}
		auto p = dynamic_cast<const HdlStmProcess*>(o);
		if (p) {
			py_inst = toPy(p);
			break;
		}
		auto wa = dynamic_cast<const HdlStmWait*>(o);
		if (wa) {
			py_inst = toPy(wa);
			break;
		}
		auto im = dynamic_cast<const HdlStmImport*>(o);
		if (im) {
			py_inst = toPy(im);
			break;
		}
		std::string err_msg = std::string("Invalid StatementType:")
				+ typeid(*o).name();
		PyErr_SetString(PyExc_TypeError, err_msg.c_str());
		return nullptr;
	} while (0);
	if (!py_inst)
		return nullptr;

	if (toPy(static_cast<const WithDoc*>(o), py_inst))
		return nullptr;

	if (toPy_arr(py_inst, "labels", o->labels)) {
		return nullptr;
	}
	if (toPy_property(py_inst, "in_preproc", o->in_preproc))
		return nullptr;

	return py_inst;
}

PyObject* ToPy::toPy(const hdlConvertor::hdlAst::HdlExprAndiHdlObj &o) {
	// build tuple representing the elif item
	auto py_inst = PyTuple_New(2);
	if (!py_inst) {
		return nullptr;
	}
	auto c = toPy(o.expr);
	if (!c) {
		Py_DECREF(py_inst);
		return nullptr;
	}

	int e = PyTuple_SetItem(py_inst, 0, c);
	if (e) {
		Py_DECREF(py_inst);
		return nullptr;
	}

	// fill statements in elif/case
	auto stms = toPy(o.obj);
	if (!stms) {
		Py_DECREF(py_inst);
		return nullptr;
	}
	e = PyTuple_SetItem(py_inst, 1, stms);
	if (e) {
		Py_DECREF(py_inst);
		return nullptr;
	}
	return py_inst;
}

}
