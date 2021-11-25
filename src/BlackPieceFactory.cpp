#include "../header/BlackPieceFactory.hpp"
#include "../header/pieces/rook.hpp"
#include "../header/pieces/pawn.hpp"
#include "../header/pieces/bishop.hpp"
#include "../header/pieces/knight.hpp"
#include "../header/pieces/king.hpp"
#include "../header/pieces/queen.hpp"

BlackPieceFactory::BlackPieceFactory(){}

piece* BlackPieceFactory::DrawPawn(std::pair<int, int> pos, Game* g){
    pawn* p = new pawn(pos, Game* g);
    p->setColor(false);
    return p;
}
piece* BlackPieceFactory::DrawRook(std::pair<int, int> pos, Game* g){
    rook* p = new rook(pos, Game* g);
    p->setColor(false);
    return p;
}
piece* BlackPieceFactory::DrawKing(std::pair<int, int> pos, Game* g){
    king* p = new king(pos, Game* g);
    p->setColor(false);
    return p;
}
piece*  BlackPieceFactory::DrawKnight(std::pair<int, int> pos, Game* g){
    knight* p = new knight(pos, Game* g);
    p->setColor(false);
    return p;
}
piece* BlackPieceFactory::DrawBishop(std::pair<int, int> pos, Game* g){
    bishop* p = new bishop(pos, Game* g);
    p->setColor(false);
    return p;
}
piece* BlackPieceFactory::DrawQueen(std::pair<int, int> pos, Game* g){
    queen* p = new queen(pos, Game* g);
    p->setColor(false);
    return p;
}


