#include <hdlConvertor/hdlAst/iHdlStatement.h>

using namespace std;

namespace hdlConvertor {
namespace hdlAst {

HdlExprAndiHdlObj::HdlExprAndiHdlObj() {
}

HdlExprAndiHdlObj::HdlExprAndiHdlObj(std::unique_ptr<iHdlExprItem> _expr,
		std::unique_ptr<iHdlObj> _stm) :
		expr(move(_expr)), obj(move(_stm)) {
}

iHdlStatement::iHdlStatement() :
		iHdlObj() {
	in_preproc = false;
}

iHdlStatement::~iHdlStatement() {
}

}
}
