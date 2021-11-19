#include "../header/WhitePieceFactory.hpp"
#include "../header/pieces/rook.hpp"
#include "../header/pieces/pawn.hpp"
#include "../header/pieces/bishop.hpp"
#include "../header/pieces/knight.hpp"
#include "../header/pieces/king.hpp"
#include "../header/pieces/queen.hpp"

WhitePieceFactory::WhitePieceFactory(){}

piece* WhitePieceFactory::DrawPawn(std::pair<int, int> pos){
    return new pawn(pos);
}
piece* WhitePieceFactory::DrawRook(std::pair<int, int> pos){
    return new rook(pos);
}
piece* WhitePieceFactory::DrawKing(std::pair<int, int> pos){
    return new king(pos);
}
piece*  WhitePieceFactory::DrawKnight(std::pair<int, int> pos){
    return new knight(pos);
}
piece* WhitePieceFactory::DrawBishop(std::pair<int, int> pos){
    return new bishop(pos);
}


