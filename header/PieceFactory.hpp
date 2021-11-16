#ifndef __PIECE_FACTORY_HPP__
#define __PIECE_FACTORY_HPP__

class PieceFactory(){
	drawPiece(_icon): void
	virtual void DrawPawn() = 0;
	virtual void DrawRook() = 0;
	virtual void DrawKing() = 0;
	virtual void DrawKnight() = 0;
	virtual void DrawBishop() = 0;
};

#endif
