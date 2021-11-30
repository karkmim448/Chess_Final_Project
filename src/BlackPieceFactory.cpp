#include "../header/BlackPieceFactory.hpp"
#include "../header/pieces/rook.hpp"
#include "../header/pieces/pawn.hpp"
#include "../header/pieces/bishop.hpp"
#include "../header/pieces/knight.hpp"
#include "../header/pieces/king.hpp"
#include "../header/pieces/queen.hpp"

BlackPieceFactory::BlackPieceFactory(){}

piece* BlackPieceFactory::DrawPawn(Game* g){
    pawn* p = new pawn(0, "images/black_pawn.png", g);
    return p;
}
piece* BlackPieceFactory::DrawRook(Game* g){
    rook* p = new rook(0, "images/black_rook.png", g);
    return p;
}
piece* BlackPieceFactory::DrawKing(Game* g){
    king* p = new king(0, "images/black_king.png", g);
    return p;
}
piece*  BlackPieceFactory::DrawKnight(Game* g){
    knight* p = new knight(0, "images/black_knight.png", g);
    return p;
}
piece* BlackPieceFactory::DrawBishop(Game* g){
    bishop* p = new bishop(0, "images/black_bishop.png", g);
    return p;
}
piece* BlackPieceFactory::DrawQueen(Game* g){
    queen* p = new queen(0, "images/black_queen.png", g);
    return p;
}


