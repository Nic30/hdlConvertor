#pragma once

#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/arch.h"

class ArchParser: public Named {
public:
	Arch * a;
	bool hierarchyOnly;
	ArchParser(bool _hierarchyOnly);
	Arch * visitArchitecture_body(
			vhdl::vhdlParser::Architecture_bodyContext * ctx);
	void visitBlock_declarative_item(
			vhdl::vhdlParser::Block_declarative_itemContext * ctx);
	void visitArchitecture_statement(
			vhdl::vhdlParser::Architecture_statementContext * ctx);

};
