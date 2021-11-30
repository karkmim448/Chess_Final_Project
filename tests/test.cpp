
#include "gtest/gtest.h"

//game include
#include "../header/game.hpp"

//square include
#include "../header/square.hpp"

//all of the piece includes
#include "../header/pieces/piece.hpp"
#include "../header/pieces/bishop.hpp"
#include "../header/pieces/king.hpp"
#include "../header/pieces/knight.hpp"
#include "../header/pieces/pawn.hpp"
#include "../header/pieces/queen.hpp"
#include "../header/pieces/rook.hpp"

//factory includes
#include "../header/PieceFactory.hpp"
#include "../header/BlackPieceFactory.hpp"
#include "../header/WhitePieceFactory.hpp"

TEST(SquareTest, ColorAccessorTest){
  Square test(1);

  EXPECT_EQ(test.getColor(), 1);
}

TEST(SquareTest, HighlightAccessorTest){
  Square test(1);

  EXPECT_EQ(test.getHighlight(), 0);
}

TEST(SquareTest, HighlightMutatorTest){
  Square test(1);

  test.setHighlight(1);

  EXPECT_EQ(test.getHighlight(), 1);
}

TEST(SquareTest, PieceNullPtrTest){
  Square test(1);

  EXPECT_EQ(test.getPiece(), nullptr);
}

TEST(SquareTest, ShouldFail){
  Square test(1);

  EXPECT_EQ(test.getColor(), 0);
}

TEST(PieceTest, ColorAccessorTest){
  pawn test(1, "test", nullptr);

  EXPECT_EQ(test.getColor(), 1);
}

TEST(PieceTest, IconAccessorTest){
  pawn test(1, "test", nullptr);

  EXPECT_EQ(test.getIcon(), "test");
}

TEST(PieceTest, HasMovedAccessorTest){
  pawn test(1, "test", nullptr);

  EXPECT_EQ(test.getHasMoved(), 0);
}

TEST(PieceTest, GameAccessorTest){
  pawn test(1, "test", nullptr);

  EXPECT_EQ(test.getGame(), nullptr);
}

TEST(PieceTest, ColorMutatorTest){
  pawn test(1, "test", nullptr);

  test.setColor(0);

  EXPECT_EQ(test.getColor(), 0);
}

TEST(PieceTest, HasMovedMutatorTest){
  pawn test(1, "test", nullptr);

  test.setHasMoved(1);

  EXPECT_EQ(test.getHasMoved(), 1);
}

TEST(PieceTest, ShouldFail){
  pawn test(1, "test", nullptr);

  test.setHasMoved(1);

  EXPECT_EQ(test.getHasMoved(), 0);
}

TEST(WhiteFactoryTest, PawnTest){
  WhitePieceFactory factory;

  piece* test = factory.DrawPawn(nullptr);

  EXPECT_EQ(test->getColor(), 1);
  EXPECT_EQ(test->getIcon(), "images/white_pawn.png");
  EXPECT_EQ(test->getHasMoved(), 0);
  EXPECT_EQ(test->getGame(), nullptr);
}

TEST(WhiteFactoryTest, RookTest){
  WhitePieceFactory factory;

  piece* test = factory.DrawRook(nullptr);

  EXPECT_EQ(test->getColor(), 1);
  EXPECT_EQ(test->getIcon(), "images/white_rook.png");
  EXPECT_EQ(test->getHasMoved(), 0);
  EXPECT_EQ(test->getGame(), nullptr);
}

TEST(WhiteFactoryTest, KnightTest){
  WhitePieceFactory factory;

  piece* test = factory.DrawKnight(nullptr);

  EXPECT_EQ(test->getColor(), 1);
  EXPECT_EQ(test->getIcon(), "images/white_knight.png");
  EXPECT_EQ(test->getHasMoved(), 0);
  EXPECT_EQ(test->getGame(), nullptr);
}

TEST(WhiteFactoryTest, BishopTest){
  WhitePieceFactory factory;

  piece* test = factory.DrawPawn(nullptr);

  EXPECT_EQ(test->getColor(), 1);
  EXPECT_EQ(test->getIcon(), "images/white_bishop.png");
  EXPECT_EQ(test->getHasMoved(), 0);
  EXPECT_EQ(test->getGame(), nullptr);
}

TEST(WhiteFactoryTest, QueenTest){
  WhitePieceFactory factory;

  piece* test = factory.DrawPawn(nullptr);

  EXPECT_EQ(test->getColor(), 1);
  EXPECT_EQ(test->getIcon(), "images/white_queen.png");
  EXPECT_EQ(test->getHasMoved(), 0);
  EXPECT_EQ(test->getGame(), nullptr);
}

TEST(WhiteFactoryTest, KingTest){
  WhitePieceFactory factory;

  piece* test = factory.DrawKing(nullptr);

  EXPECT_EQ(test->getColor(), 1);
  EXPECT_EQ(test->getIcon(), "images/white_king.png");
  EXPECT_EQ(test->getHasMoved(), 0);
  EXPECT_EQ(test->getGame(), nullptr);
}

TEST(WhiteFactoryTest, ShouldFail){
  WhitePieceFactory factory;

  piece* test = factory.DrawKing(nullptr);

  EXPECT_EQ(test->getColor(), 0);
  EXPECT_EQ(test->getIcon(), "images/white_king.png");
  EXPECT_EQ(test->getHasMoved(), 0);
  EXPECT_EQ(test->getGame(), nullptr);
}


TEST(BlackFactoryTest, PawnTest){
  BlackPieceFactory factory;

  piece* test = factory.DrawPawn(nullptr);

  EXPECT_EQ(test->getColor(), 0);
  EXPECT_EQ(test->getIcon(), "images/black_pawn.png");
  EXPECT_EQ(test->getHasMoved(), 0);
  EXPECT_EQ(test->getGame(), nullptr);
}

TEST(BlackFactoryTest, RookTest){
  BlackPieceFactory factory;

  piece* test = factory.DrawRook(nullptr);

  EXPECT_EQ(test->getColor(), 0);
  EXPECT_EQ(test->getIcon(), "images/black_rook.png");
  EXPECT_EQ(test->getHasMoved(), 0);
  EXPECT_EQ(test->getGame(), nullptr);
}

TEST(BlackFactoryTest, KnightTest){
  BlackPieceFactory factory;

  piece* test = factory.DrawKnight(nullptr);

  EXPECT_EQ(test->getColor(), 0);
  EXPECT_EQ(test->getIcon(), "images/black_knight.png");
  EXPECT_EQ(test->getHasMoved(), 0);
  EXPECT_EQ(test->getGame(), nullptr);
}

TEST(BlackFactoryTest, BishopTest){
  BlackPieceFactory factory;

  piece* test = factory.DrawPawn(nullptr);

  EXPECT_EQ(test->getColor(), 0);
  EXPECT_EQ(test->getIcon(), "images/black_bishop.png");
  EXPECT_EQ(test->getHasMoved(), 0);
  EXPECT_EQ(test->getGame(), nullptr);
}

TEST(BlackFactoryTest, QueenTest){
  BlackPieceFactory factory;

  piece* test = factory.DrawPawn(nullptr);

  EXPECT_EQ(test->getColor(), 0);
  EXPECT_EQ(test->getIcon(), "images/black_queen.png");
  EXPECT_EQ(test->getHasMoved(), 0);
  EXPECT_EQ(test->getGame(), nullptr);
}

TEST(BlackFactoryTest, KingTest){
  BlackPieceFactory factory;

  piece* test = factory.DrawKing(nullptr);

  EXPECT_EQ(test->getColor(), 0);
  EXPECT_EQ(test->getIcon(), "images/black_king.png");
  EXPECT_EQ(test->getHasMoved(), 0);
  EXPECT_EQ(test->getGame(), nullptr);
}

TEST(BlackFactoryTest, ShouldFail){
  BlackPieceFactory factory;

  piece* test = factory.DrawKing(nullptr);

  EXPECT_EQ(test->getColor(), 1);
  EXPECT_EQ(test->getIcon(), "images/black_king.png");
  EXPECT_EQ(test->getHasMoved(), 0);
  EXPECT_EQ(test->getGame(), nullptr);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

