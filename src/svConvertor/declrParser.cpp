#include <hdlConvertor/svConvertor/declrParser.h>
#include <hdlConvertor/svConvertor/typeParser.h>
#include <hdlConvertor/svConvertor/paramDefParser.h>
#include <hdlConvertor/svConvertor/exprParser.h>

#include <hdlConvertor/createObject.h>
#include <hdlConvertor/notImplementedLogger.h>

using namespace std;
using namespace sv2017_antlr;
using namespace hdlConvertor::hdlObjects;

namespace hdlConvertor {
namespace sv {

VerDeclrParser::VerDeclrParser(SVCommentParser &_commentParser) :
		commentParser(_commentParser) {
}

void VerDeclrParser::visitData_declaration(
		sv2017Parser::Data_declarationContext *ctx,
		vector<unique_ptr<iHdlObj>> &res) {
	// data_declaration:
	//  ( KW_CONST )? ( KW_VAR ( lifetime )? ( data_type_or_implicit )?
	//                   | ( lifetime )? data_type_or_implicit
	//                   ) list_of_variable_decl_assignments SEMI
	//   | type_declaration
	//   | package_import_declaration
	//   | net_type_declaration
	// ;
	auto lvda = ctx->list_of_variable_decl_assignments();
	if (lvda) {
		VerTypeParser tp(commentParser);
		auto is_const = ctx->KW_CONST() != nullptr;
		auto is_static = tp.visitLifetime(ctx->lifetime());
		vector<unique_ptr<HdlVariableDef>> res_tmp;
		auto dti = ctx->data_type_or_implicit();
		auto t = tp.visitData_type_or_implicit(dti, nullptr);
		visitList_of_variable_decl_assignments(lvda, move(t), res_tmp);
		for (auto & vd : res_tmp) {
			vd->is_const = is_const;
			vd->is_static = is_static;
			res.push_back(move(vd));
		}
		return;
	}

	auto _td = ctx->type_declaration();
	if (_td) {
		auto td = visitType_declaration(_td);
		res.push_back(move(td));
		return;
	}
	auto _pid = ctx->package_import_declaration();
	if (_pid) {
		// auto pid = visitPackage_import_declaration(_pid);
		// res.push_back(pid);
		NotImplementedLogger::print(
				"VerDeclrParser.visitData_declaration.package_import_declaration",
				_pid);
		return;
	}
	auto _ntd = ctx->net_type_declaration();
	assert(_ntd);
	visitNet_type_declaration(_ntd, res);
	return;
}

void VerDeclrParser::visitList_of_variable_decl_assignments(
		sv2017Parser::List_of_variable_decl_assignmentsContext *ctx,
		unique_ptr<iHdlExpr> base_type,
		vector<unique_ptr<HdlVariableDef>> &res) {
	// list_of_variable_decl_assignments:
	//     variable_decl_assignment ( COMMA variable_decl_assignment )*;
	VerExprParser ep(commentParser);
	VerTypeParser tp(commentParser);
	auto base_type_tmp = base_type.get();
	bool first = false;
	for (auto vda : ctx->variable_decl_assignment()) {
		// variable_decl_assignment:
		//     identifier (
		//         ASSIGN ( expression | class_new )
		//         | ( variable_dimension )+ ( ASSIGN ( expression | dynamic_array_new ) )?
		//     )?
		// ;
		auto _id = vda->identifier();
		auto name = ep.getIdentifierStr(_id);
		unique_ptr<iHdlExpr> t;
		if (first)
			t = move(base_type);
		else
			t = make_unique<iHdlExpr>(*base_type_tmp);
		auto vds = vda->variable_dimension();
		t = tp.applyVariable_dimension(move(t), vds);
		unique_ptr<iHdlExpr> v = nullptr;
		auto e = vda->expression();
		if (e) {
			v = ep.visitExpression(e);
		} else {
			auto cn = vda->class_new();
			if (cn) {
				NotImplementedLogger::print(
						"VerDeclrParser.visitList_of_variable_decl_assignments"
								".variable_decl_assignment.class_new", vda);
			} else {
				auto dan = vda->dynamic_array_new();
				if (dan) {
					NotImplementedLogger::print(
							"VerDeclrParser.visitList_of_variable_decl_assignments"
									".variable_decl_assignment.dynamic_array_new",
							dan);
				}
			}
		}
		auto var = create_object<HdlVariableDef>(vda, name, move(t), move(v));
		res.push_back(move(var));
	}

}
unique_ptr<HdlVariableDef> VerDeclrParser::visitType_declaration(
		sv2017Parser::Type_declarationContext *ctx) {
	// type_declaration:
	//     KW_TYPEDEF (
	//         data_type identifier ( variable_dimension )*
	//         | ( KW_ENUM
	//             | KW_STRUCT
	//             | KW_UNION
	//             | identifier_with_bit_select DOT identifier
	//             | ( KW_INTERFACE )? KW_CLASS
	//           )? identifier
	//     ) SEMI;
	VerExprParser ep(commentParser);
	VerTypeParser tp(commentParser);
	auto id0 = ctx->identifier(0);
	auto _dt = ctx->data_type();
	if (_dt) {
		auto dt = tp.visitData_type(_dt);
		auto vds = ctx->variable_dimension();
		dt = tp.applyVariable_dimension(move(dt), vds);
		auto name = ep.getIdentifierStr(id0);
		return create_object<HdlVariableDef>(ctx, name, iHdlExpr::TYPE_T(), move(dt));
	} else if (ctx->KW_ENUM() || ctx->KW_STRUCT() || ctx->KW_UNION()
			|| ctx->KW_CLASS()) {
		// forward typedef without actual type specified
		auto name = ep.getIdentifierStr(id0);
		return create_object<HdlVariableDef>(ctx, name, iHdlExpr::TYPE_T(), iHdlExpr::null());
	} else {
		auto iwbs = ctx->identifier_with_bit_select();
		auto val = ep.visitIdentifier_with_bit_select(iwbs, nullptr);
		auto ids = ctx->identifier();
		assert(ids.size() == 2);
		auto id = ep.visitIdentifier(ids[0]);
		val = create_object<iHdlExpr>(iwbs, move(val), HdlOperatorType::DOT, move(id));
		auto name = ep.getIdentifierStr(ids[1]);
		return create_object<HdlVariableDef>(ctx, name, iHdlExpr::TYPE_T(), move(val));
	}
}
void VerDeclrParser::visitNet_type_declaration(
		sv2017Parser::Net_type_declarationContext *ctx,
		vector<unique_ptr<iHdlObj>> &res) {
	// net_type_declaration:
	//     KW_NETTYPE ( data_type identifier ( KW_WITH package_or_class_scoped_id )? ) SEMI;
	NotImplementedLogger::print("VerDeclrParser::visitNet_type_declaration",
			ctx);
}

}
}
