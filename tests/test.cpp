
#include "gtest/gtest.h"

#include "../header/game.hpp"



TEST(GAME_TEST, DEFAULT_CONSTRUCTOR){
    Game g;
    std::string s =g.getBoard()[0][0].piece->getIcon();

    ASSERT_EQ(g.getBoard()[0][0].piece->getIcon(), "rook");
    ASSERT_EQ(g.getBoard()[1][0].piece->getIcon(), "bishop");
    ASSERT_EQ(g.getBoard()[2][0].piece->getIcon(), "knight");
    ASSERT_EQ(g.getBoard()[3][0].piece->getIcon(), "queen");
    ASSERT_EQ(g.getBoard()[4][0].piece->getIcon(), "king");
    ASSERT_EQ(g.getBoard()[5][0].piece->getIcon(), "knight");
    ASSERT_EQ(g.getBoard()[6][0].piece->getIcon(), "bishop");
    ASSERT_EQ(g.getBoard()[7][0].piece->getIcon(), "rook");

    ASSERT_EQ(g.getBoard()[0][7].piece->getIcon(), "rook");
    ASSERT_EQ(g.getBoard()[1][7].piece->getIcon(), "bishop");
    ASSERT_EQ(g.getBoard()[2][7].piece->getIcon(), "knight");
    ASSERT_EQ(g.getBoard()[3][7].piece->getIcon(), "queen");
    ASSERT_EQ(g.getBoard()[4][7].piece->getIcon(), "king");
    ASSERT_EQ(g.getBoard()[5][7].piece->getIcon(), "knight");
    ASSERT_EQ(g.getBoard()[6][7].piece->getIcon(), "bishop");
    ASSERT_EQ(g.getBoard()[7][7].piece->getIcon(), "rook");

    for(int col = 0; col < 8; col++){
	int row = 1;
	ASSERT_EQ(g.getBoard([col][row])->piece->getIcon(), "pawn");
        row = 6;
	ASSERT_EQ(g.getBoard([col][row])->piece->getIcon(), "pawn");
    }
}

    
// TEST(KNIGHT_TEST, MOVE){
//     piece ***testBoard = new piece**[8];
//     for(int i = 0; i < 8; i++){
// 	piece[i] = new piece*[8];
//     }
//     //create empty getBoard( with knight at testBoard[4][4]
//     for(int i = 0; i < 8; i++){
// 	for(int i = 0; i < 8; i++){
// 	    if((i == 4) && (j==4)){
// 		std::pair<int, int> pos(4, 4);
// 		testBoard[i][j] = new knight*(pos);
// 	    }
// 	    else{
// 		testBoard[i][j] = new empty*;
// 	    }
// 	}
//     }
//     testBoard[4][4]->moveCheck;
    
//     //insert expected moves (of the knight at 4,4) into expectedMoves 
//     std::unordered_set<pair<int, int>> expectedMoves;
//     pair<int, int> expected(2, 3);
//     expectedMoves.insert(expected);
//     expected->second=5;
//     expectedMoves.insert(expected);
//     expected->first=6;
//     expectedMoves.insert(expected);
//     expected->second=3;
//     expectedMoves.insert(expected);

//     expected->first=3;
//     expected->second=2;
//     expectedMoves.insert(expected);
//     expected->first=5;
//     expectedMoves.insert(expected);
//     expected->second=6;
//     expectedMoves.insert(expected);
//     expected->first=3;
//     expectedMoves.insert(expected);

//     //check that (the knight at 4,4)'s move function returns true for expectedMoves and false for any other moves on the getBoard(.
//     for(int i = 0; i < 8; i++){
// 	for(int j = 0; j <8; j++){
// 	    pair<int, int> tmp(i, j);
// 	    if(expectedMoves.find(tmp) != expectedMoves.end()){
// 		ASSERT_EQ(testBoard[4][4]->move(tmp), true);
// 	    }
// 	    else{
// 		ASSERT_EQ(testBoard[4][4]->move(tmp), false);
// 	    }
// 	}
//     }
// }
    	

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
