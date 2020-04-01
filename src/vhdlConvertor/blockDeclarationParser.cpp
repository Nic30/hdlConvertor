#include <hdlConvertor/vhdlConvertor/blockDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/constantParser.h>
#include <hdlConvertor/vhdlConvertor/entityParser.h>
#include <hdlConvertor/vhdlConvertor/packageHeaderParser.h>
#include <hdlConvertor/vhdlConvertor/packageParser.h>
#include <hdlConvertor/vhdlConvertor/signalParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramParser.h>
#include <hdlConvertor/vhdlConvertor/subtypeDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/variableParser.h>

#include <hdlConvertor/createObject.h>

#include <string.h>

namespace hdlConvertor {
namespace vhdl {

VhdlBlockDeclarationParser::VhdlBlockDeclarationParser(bool hierarchyOnly) :
		hierarchyOnly(hierarchyOnly) {
}

/*
 * @note Some declarations can spot multiple objects
 * 		 that is why this function just does not return hdlObjects::iHdlObj*
 * */
void VhdlBlockDeclarationParser::visitBlock_declarative_item(
		vhdlParser::Block_declarative_itemContext *ctx,
		std::vector<std::unique_ptr<hdlObjects::iHdlObj>> &objs) {
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
		auto f = VhdlSubProgramDeclarationParser::visitSubprogram_declaration(
				sp);
		objs.push_back(std::move(f));
		return;
	}
	auto sb = ctx->subprogram_body();
	if (sb) {
		auto f = VhdlSubProgramParser::visitSubprogram_body(sb);
		objs.push_back(std::move(f));
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
		VhdlPackageHeaderParser ph(hierarchyOnly);
		auto pac_header = ph.visitPackage_declaration(pd);
		objs.push_back(std::move(pac_header));
		return;
	}
	auto pb = ctx->package_body();
	if (pb) {
		VhdlPackageParser pp(hierarchyOnly);
		auto p = pp.visitPackage_body(pb);
		objs.push_back(std::move(p));
		return;
	}
	auto pid = ctx->package_instantiation_declaration();
	if (pid) {
		NotImplementedLogger::print(
				"ArchParser.visitBlock_declarative_item - package_instantiation_declaration",
				pid);
		return;
	}
	auto td = ctx->type_declaration();
	if (td) {
		NotImplementedLogger::print("ArchParser.visitType_declaration", td);
		return;
	}
	auto st = ctx->subtype_declaration();
	if (st) {
		auto _st = VhdlSubtypeDeclarationParser::visitSubtype_declaration(st);
		objs.push_back(std::move(_st));
		return;
	}
	auto constd = ctx->constant_declaration();
	if (constd) {
		auto constants = VhdlConstantParser::visitConstant_declaration(constd);
		for (auto & c : *constants) {
			objs.push_back(std::move(c));
		}
		return;
	}
	auto sd = ctx->signal_declaration();
	if (sd) {
		auto signals = VhdlSignalParser::visitSignal_declaration(sd);
		for (auto & s : *signals) {
			objs.push_back(std::move(s));
		}
		return;
	}
	auto vd = ctx->variable_declaration();
	if (vd) {
		auto variables = VhdlVariableParser::visitVariable_declaration(vd);
		for (auto & v : *variables) {
			objs.push_back(std::move(v));
		}
		return;
	}
	auto fd = ctx->file_declaration();
	if (fd) {
		NotImplementedLogger::print("ArchParser.visitFile_declaration", fd);
		return;
	}
	auto aliasd = ctx->alias_declaration();
	if (aliasd) {
		NotImplementedLogger::print("ArchParser.visitAlias_declaration",
				aliasd);
		return;
	}
	auto compd = ctx->component_declaration();
	if (compd) {
		objs.push_back(visitComponent_declaration(compd));
		return;
	}
	auto atrd = ctx->attribute_declaration();
	if (atrd) {
		NotImplementedLogger::print("ArchParser.visitAttribute_declaration",
				atrd);
		return;
	}
	auto as = ctx->attribute_specification();
	if (as) {
		NotImplementedLogger::print("ArchParser.visitAttribute_specification",
				as);
		return;
	}
	auto cs = ctx->configuration_specification();
	if (cs) {
		NotImplementedLogger::print(
				"ArchParser.visitconfiguration_specification", cs);
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
	assert(gd);
	NotImplementedLogger::print("ArchParser.visitGroup_declaration", gd);
}

std::unique_ptr<hdlObjects::HdlModuleDec> VhdlBlockDeclarationParser::visitComponent_declaration(
		vhdlParser::Component_declarationContext *ctx) {
	// component_declaration:
	//       COMPONENT identifier ( IS )?
	//           ( generic_clause )?
	//           ( port_clause )?
	//       END COMPONENT ( identifier )? SEMI
	// ;
	auto e = create_object<hdlObjects::HdlModuleDec>(ctx);
	e->name = ctx->identifier(0)->getText();
	if (!hierarchyOnly) {
		auto gc = ctx->generic_clause();
		if (gc)
			VhdlEntityParser::visitGeneric_clause(gc, e->generics);
		auto pc = ctx->port_clause();
		if (pc)
			VhdlEntityParser::visitPort_clause(pc, e->ports);
	}
	return e;
}

}
}
