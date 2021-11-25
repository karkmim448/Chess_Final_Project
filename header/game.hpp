#ifndef __GAME_HPP__
#define __GAME_HPP__

//#include </SFML/Graphics.hpp>
#include <fstream>

#include "square.hpp"
#include "PieceFactory.hpp"
#include "WhitePieceFactory.hpp"
#include "BlackPieceFactory.hpp"
#include "pieces/piece.hpp"

class Game{
  private:
    /*
      -2D array used for movement and GUI
      -The core of the game that is being edited by the back-end and diplayed via the gui
      -Squares themselves never need to be instantiated/moved/deleted during runtime
      -Square member variables that need to be moved/edited are:
        -_highlight when a piece is selected but has notmoved yet and then again after the piece has moved.
        -_piece whenever a piece moves
    */
    Square *_board[8][8];

    /*
      -True means white can move, False means black can move
      -Updated whenever a piece moves
    */
    bool _playerTurn;

    /*
      -Used by undoMove
      -Position where the piece used to be, treated as the destination square for the piece
    */
    std::pair<int, int>* _mostRecentStartingSquare;


    /*
      -Used to undoMove
      -Position where the piece currently is, treating as the initial square for the piece
    */
    std::pair<int, int>* _mostRecentEndingSquare;

    /*
      -Used by undoMove
      -used to recover any piece that may have been captured prior to the undo, stores the piece pointer that was in mostRecentEndingSquare prioor to the initial move
    */
    piece* _undoMovePieceStorage;
  public:
    //Constructor
    Game();
    Game(std::string fileName);

    //Destructor
    ~Game();

    //Basic Accessors
    bool getPlayerTurn();
    Square* getSquare(std::pair<int, int> position);
    std::pair<int, int>* getMostRecentStartingSquare();
    std::pair<int, int>* getMostRecentEndingSquare();
    piece* getUndoMovePieceStorage();

    //Basic Mutators
    void setPlayerTurn(bool playerTurn);
    void setMostRecentStartingSquare(std::pair<int, int>* tobeSet);
    void setMostRecentEndingSquare(std::pair<int, int>* toBeSet);
    void setUndoMovePieceStorage(piece* toBeSet);

    /*
      -Called during run-time by user input
      -Takes the game state and exports it to Save.txt for use in a later load
      -Tracks board state and well as player turn and undo storage
      -Use Template.txt or reference Default.txt to see what Save.txt should look like
    */
    void save();

    /*
      -Called during run-time by user input
      -Takes game state stored in Save.txt and imports it to the current board state
      -Loads current board state as well as player turn and undo storage
      -Use Template.txt or reference Dafault.txt to see what Save.txt should look like
    */
    void load();

    /*
      -Called when a piece is selected, updates the board by highlighting legal moves for said piece
      -Checks if piece can be moved by current player:
        -if current player cannot move piece, returns false
        -if current player can move piece, returns true at end of function
      -Calls getPossibleMoves for piece, takes the result and uses it to update the squares
    */
    bool selectPiece(std::pair<int, int> initialPosition);

    /*
      -Called when a piece has been selected and then another square has been selected as a target square
      -Checks if destiniation square is a valid move for square
        -Does this by checking if the square is highlighted
        -If move is invalid, returns false
        -If move is valid, return true at end of function
      -Then de-highlights all squares and updates the playerTurn
    */
    bool movePiece(std::pair<int, int> initialPosition, std::pair<int, int> destinationSquare);

    /*
      -Called via the gui
      -Reverses the most recent move, can only undo one move
      -Bypasses move checks, assumption is that the move will be valid
    */
    void undoMove();
};

#endif //__GAME_HPP__//
