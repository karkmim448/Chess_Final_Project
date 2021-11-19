#include "../header/BlackPieceFactory.hpp"
#include "../header/pieces/rook.hpp"
#include "../header/pieces/pawn.hpp"
#include "../header/pieces/bishop.hpp"
#include "../header/pieces/knight.hpp"
#include "../header/pieces/king.hpp"
#include "../header/pieces/queen.hpp"

BlackPieceFactory::BlackPieceFactory(){}

piece* BlackPieceFactory::DrawPawn(std::pair<int, int> pos){
    return new pawn(pos);
}
piece* BlackPieceFactory::DrawRook(std::pair<int, int> pos){
    return new rook(pos);
}
piece* BlackPieceFactory::DrawKing(std::pair<int, int> pos){
    return new king(pos);
}
piece*  BlackPieceFactory::DrawKnight(std::pair<int, int> pos){
    return new knight(pos);
}
piece* BlackPieceFactory::DrawBishop(std::pair<int, int> pos){
    return new bishop(pos);
}


