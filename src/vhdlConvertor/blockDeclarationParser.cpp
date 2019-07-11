#include <hdlConvertor/vhdlConvertor/blockDeclarationParser.h>

#include <string.h>

#include <hdlConvertor/vhdlConvertor/packageHeaderParser.h>
#include <hdlConvertor/vhdlConvertor/packageParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramParser.h>
#include <hdlConvertor/vhdlConvertor/subtypeDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/constantParser.h>
#include <hdlConvertor/vhdlConvertor/signalParser.h>
#include <hdlConvertor/vhdlConvertor/entityParser.h>
#include <hdlConvertor/vhdlConvertor/variableParser.h>

namespace hdlConvertor {
namespace vhdl {

BlockDeclarationParser::BlockDeclarationParser(bool hierarchyOnly) :
		hierarchyOnly(hierarchyOnly) {
}

void BlockDeclarationParser::visitBlock_declarative_part(
		vhdlParser::Block_declarative_partContext * ctx,
		std::vector<hdlObjects::iHdlObj*> & objs) {
	// block_declarative_part:
	//       ( block_declarative_item )*
	// ;
	for (auto bdi : ctx->block_declarative_item()) {
		visitBlock_declarative_item(bdi, objs);
	}
}

/*
 * @note Some declarations can spot multiple objects
 * 		 that is why this function just does not return hdlObjects::iHdlObj*
 * */
void BlockDeclarationParser::visitBlock_declarative_item(
		vhdlParser::Block_declarative_itemContext * ctx,
		std::vector<hdlObjects::iHdlObj*> & objs) {
	// block_declarative_item:
	//       subprogram_declaration
	//       | subprogram_body
	//       | subprogram_instantiation_declaration
	//       | package_declaration
	//       | package_body
	//       | package_instantiation_declaration
	//       | type_declaration
	//       | subtype_declaration
	//       | constant_declaration
	//       | signal_declaration
	//       | variable_declaration
	//       | file_declaration
	//       | alias_declaration
	//       | component_declaration
	//       | attribute_declaration
	//       | attribute_specification
	//       | configuration_specification
	//       | disconnection_specification
	//       | use_clause
	//       | group_template_declaration
	//       | group_declaration
	//      ;
	auto sp = ctx->subprogram_declaration();
	if (sp) {
		objs.push_back(
				SubProgramDeclarationParser::visitSubprogram_declaration(sp));
		return;
	}
	auto sb = ctx->subprogram_body();
	if (sb) {
		auto f = SubProgramParser::visitSubprogram_body(sb);
		objs.push_back(f);
		return;
	}
	auto sid = ctx->subprogram_instantiation_declaration();
	if (sid) {
		NotImplementedLogger::print(
				"ArchParser.visitSubprogram_instantiation_declaration", sid);
		return;
	}
	auto pd = ctx->package_declaration();
	if (pd) {
		PackageHeaderParser ph(hierarchyOnly);
		auto pac_header = ph.visitPackage_declaration(pd);
		objs.push_back(pac_header);
		return;
	}
	auto pb = ctx->package_body();
	if (pb) {
		PackageParser pp(hierarchyOnly);
		auto p = pp.visitPackage_body(pb);
		objs.push_back(p);
		return;
	}
	auto pid = ctx->package_instantiation_declaration();
	if (pid) {
		NotImplementedLogger::print(
				"ArchParser.visitBlock_declarative_item - package_instantiation_declaration", pid);
		return;
	}
	auto td = ctx->type_declaration();
	if (td) {
		NotImplementedLogger::print("ArchParser.visitType_declaration", td);
		return;
	}
	auto st = ctx->subtype_declaration();
	if (st) {
		auto _st = SubtypeDeclarationParser::visitSubtype_declaration(st);
		objs.push_back(_st);
		return;
	}
	auto constd = ctx->constant_declaration();
	if (constd) {
		auto constants = ConstantParser::visitConstant_declaration(constd);
		for (auto c : *constants) {
			objs.push_back(c);
		}
		delete constants;
		return;
	}
	auto sd = ctx->signal_declaration();
	if (sd) {
		auto signals = SignalParser::visitSignal_declaration(sd);
		for (auto s : *signals) {
			objs.push_back(s);
		}
		delete signals;
		return;
	}
	auto vd = ctx->variable_declaration();
	if (vd) {
		auto variables = VariableParser::visitVariable_declaration(vd);
		for (auto v : *variables) {
			objs.push_back(v);
		}
		delete variables;
		return;
	}
	auto fd = ctx->file_declaration();
	if (fd) {
		NotImplementedLogger::print("ArchParser.visitFile_declaration", fd);
		return;
	}
	auto aliasd = ctx->alias_declaration();
	if (aliasd) {
		NotImplementedLogger::print("ArchParser.visitAlias_declaration", aliasd);
		return;
	}
	auto compd = ctx->component_declaration();
	if (compd) {
		objs.push_back(visitComponent_declaration(compd));
		return;
	}
	auto atrd = ctx->attribute_declaration();
	if (atrd) {
		NotImplementedLogger::print("ArchParser.visitAttribute_declaration", atrd);
		return;
	}
	auto as = ctx->attribute_specification();
	if (as) {
		NotImplementedLogger::print("ArchParser.visitAttribute_specification", as);
		return;
	}
	auto discs = ctx->disconnection_specification();
	if (discs) {
		NotImplementedLogger::print(
				"ArchParser.visitDisconnection_specification", discs);
		return;
	}
	auto uc = ctx->use_clause();
	if (uc) {
		NotImplementedLogger::print("ArchParser.visitUse_clause", uc);
		return;
	}
	auto gtd = ctx->group_template_declaration();
	if (gtd) {
		NotImplementedLogger::print(
				"ArchParser.visitGroup_template_declaration", gtd);
		return;
	}
	auto gd = ctx->group_declaration();
#ifndef NDEBUG
	assert(gd);
#endif
	NotImplementedLogger::print("ArchParser.visitGroup_declaration", gd);
}

hdlObjects::HdlModuleDec * BlockDeclarationParser::visitComponent_declaration(
		vhdlParser::Component_declarationContext* ctx) {
	// component_declaration:
	//       COMPONENT identifier ( IS )?
	//           ( generic_clause )?
	//           ( port_clause )?
	//       END COMPONENT ( simple_name )? SEMI
	// ;
	auto e = new hdlObjects::HdlModuleDec();
	e->name = ctx->identifier()->getText();
	if (!hierarchyOnly) {
		auto gc = ctx->generic_clause();
		if (gc)
			EntityParser::visitGeneric_clause(gc, &e->generics);
		auto pc = ctx->port_clause();
		if (pc)
			EntityParser::visitPort_clause(pc, &e->ports);
	}
	return e;
}

}
}
