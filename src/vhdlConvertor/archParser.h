#pragma once

#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/arch.h"

namespace hdlConvertor {
namespace vhdl {

class ArchParser: public hdlObjects::Named {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	hdlObjects::Arch * a;
	bool hierarchyOnly;
	ArchParser(bool _hierarchyOnly);
	hdlObjects::Arch * visitArchitecture_body(
			vhdlParser::Architecture_bodyContext * ctx);
	void visitBlock_declarative_item(
			vhdlParser::Block_declarative_itemContext * ctx);
	void visitArchitecture_statement(
			vhdlParser::Architecture_statementContext * ctx);
	hdlObjects::Entity * visitComponent_declaration(
			vhdlParser::Component_declarationContext* ctx);

};

}
}
