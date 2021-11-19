#include "../header/game.hpp"
#include "rook.hpp"
#include "bishop.hpp"
#include "knight.hpp"
#include "king.hpp"
#include "queen.hpp"
#include "pawn.hpp"

Game::Game(){
    //setup board of squares
    board = new Square* [8];
    for(int i = 0; i < 8; i++){
		board[i] = new Square[8];
    }
	
	//put pieces on squares in regular chess fashion
    factory = new BlackPieceFactory();
	//for all rows, fill them in
    for(int row = 0; row < 8; row++){
		//fill for outside rows
		if(row == 0 || row == 7){
			board[0][row]->piece = factory.DrawRook(std::make_pair(col,row));
			board[7][row]->piece = factory.DrawRook(std::make_pair(col,row));
			board[1][row]->piece = factory.DrawBishop(std::make_pair(col,row));
			board[6][row]->piece = factory.DrawBishop(std::make_pair(col,row));
			board[2][row]->piece = factory.DrawKnight(std::make_pair(col,row));
			board[5][row]->piece = factory.DrawKnight(std::make_pair(col,row));
			board[3][row]->piece = factory.DrawQueen(std::make_pair(col,row));
			board[4][row]->piece = factory.DrawKing(std::make_pair(col,row));
		}
		//fill for rows of pawns
		if(row == 1 || row == 6){
			for(int col = 0; col < 7; col++){
				board[col][row]->piece = factory.DrawPawn(std::make_pair(col,row));
			}
		}
		//fill for middle rows
		else{
			for(int col = 0; col < 7; col++){
                		board[col][row]->piece = factory.DrawEmpty(std::make_pair(col,row));
            		}
		}

		//once you reach the middle of the board, change from creating black pieces to creating white pieces
		if(row == 3){
			factory = new WhitePieceFactory();
		}
			
	}
}
Square** Game::getBoard(){
	return board;
}

void DrawBoard(string filename){};

	    	
