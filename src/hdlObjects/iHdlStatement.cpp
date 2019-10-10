#include <hdlConvertor/hdlObjects/iHdlStatement.h>

using namespace std;

namespace hdlConvertor {
namespace hdlObjects {

HdlExprAndStm::HdlExprAndStm() {
}

HdlExprAndStm::HdlExprAndStm(std::unique_ptr<iHdlExpr> _expr,
		std::unique_ptr<iHdlStatement> _stm) :
		expr(move(_expr)), stm(move(_stm)) {
}

iHdlStatement::iHdlStatement() :
		iHdlObj() {
	in_preproc = false;
}

iHdlStatement::~iHdlStatement() {
}

}
}
