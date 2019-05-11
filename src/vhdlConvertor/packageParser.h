#pragma once

#include <vector>

#include "vhdlParser/vhdlParser.h"

#include "../hdlObjects/statement.h"
#include "../hdlObjects/package.h"
#include "../hdlObjects/packageHeader.h"

namespace hdlConvertor {
namespace vhdl {

class PackageParser {
public:
	using Variable = hdlObjects::Variable;
	using Statement = hdlObjects::Statement;
	using vhdlParser = vhdl_antlr::vhdlParser;

	hdlObjects::Package * p;
	bool hierarchyOnly;

	PackageParser(bool _hierarchyOnly);
	hdlObjects::Package * visitPackage_body(
			vhdlParser::Package_bodyContext* ctx);
	void visitPackage_body_declarative_part(hdlObjects::aPackage * p,
			vhdlParser::Package_body_declarative_partContext* ctx);
	void visitPackage_body_declarative_item(
			vhdlParser::Package_body_declarative_itemContext* ctx);
	static hdlObjects::Function * visitSubprogram_body(
			vhdlParser::Subprogram_bodyContext* ctx);
	static std::vector<Variable*>* visitSubprogram_declarative_part(
			vhdlParser::Subprogram_declarative_partContext* ctx);
	static std::vector<Variable *> * visitSubprogram_declarative_item(
			vhdlParser::Subprogram_declarative_itemContext* ctx);
	static std::vector<Variable*> * visitVariable_declaration(
			vhdlParser::Variable_declarationContext* ctx);
	void visitSubprogram_declaration(
			vhdlParser::Subprogram_declarationContext* ctx);
	static std::vector<hdlObjects::Statement *> * visitSubprogram_statement_part(
			vhdlParser::Subprogram_statement_partContext* ctx);

};

}
}
