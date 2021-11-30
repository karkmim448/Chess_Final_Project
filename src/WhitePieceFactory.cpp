#include "../header/WhitePieceFactory.hpp"
#include "../header/pieces/rook.hpp"
#include "../header/pieces/pawn.hpp"
#include "../header/pieces/bishop.hpp"
#include "../header/pieces/knight.hpp"
#include "../header/pieces/king.hpp"
#include "../header/pieces/queen.hpp"


WhitePieceFactory::WhitePieceFactory(){}

piece* WhitePieceFactory::DrawPawn(Game* g ){
    pawn* p = new pawn(1, "images/white_pawn.png", g);
    return p;
}
piece* WhitePieceFactory::DrawRook(Game* g ){
    rook* p = new rook(1, "images/white_rook.png", g);
    return p;
}
piece* WhitePieceFactory::DrawKing(Game* g ){
    king* p = new king(1, "images/white_king.png", g);
    return p;
}
piece*  WhitePieceFactory::DrawKnight(Game* g ){
    knight* p = new knight(1, "images/white_knight.png", g);
    return p;
}
piece* WhitePieceFactory::DrawBishop(Game* g ){
    bishop* p = new bishop(1, "images/white_bishop.png", g);
    return p;
}
piece* WhitePieceFactory::DrawQueen(Game* g ){
    queen* p = new queen(1, "images/white_queen.png", g);
    return p;
}


