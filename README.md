# Chess Dot Com
 
 > Authors: [Gurman Singh Dhaliwal](https://github.com/gsinghd)\
 > Authors: [Mark Kim](https://github.com/karkmim448)\
 > Authors: [Suhail-Anand Singh Dhillon](https://github.com/DhillonSuhail)\
 > Authors: [Cody Kurpanek](https://github.com/CodyKurpanek)

## Project Description
 > * The project will be a chess board that will allow for a two-player game of chess, with the ability to save/load games, undo moves, and all presented with a GUI.
 > * The project is interesting to us because of the sheer amount of complexity in any typical game of chess.  All of the moving parts will need to interact in harmony, and we will have to make major decisions around how a chess board will function.  We envision an interesting class stucture that allows updates to game functionality in a way that it doesn't change the overall structure. 
 > * We plan on building the program in C++
 >   * QTCreator(https://www.qt.io/product/development-tools) - This is the tool we plan on using to build our GUI for the game.
 > * The input will be taken through the GUI, likely using the mouse to select which piece to move and where, and output will got to the same GUI. We also plan on building a main menu to use for saving/loading games in progress. 
 > * The project will provide the ability to play a game of chess against another player locally, being able to undo moves, save a game in progress, and load a game in progress. For specific games, we will need to create a user interface for seeing the board and moving pieces, determine how the user will move the pieces, create all the different chess pieces, determine legal moves (includes castling and determining whether checks/checkmates are present), and save states of the game. The entire program will be presented in a GUI and, if time permits, we will allow a player to play against a basic AI.

 
## Class Diagram
![Screenshot from 2021-11-30 12-05-52](https://user-images.githubusercontent.com/51354509/144120081-5cb4861e-46fd-4fe8-9256-394ad7a92edc.png)

Link:
https://lucid.app/lucidchart/ea02bd3d-c8e0-4026-8497-5b377b4eb6fd/edit?viewport_loc=354%2C782%2C3882%2C2089%2CHWEp-vi-RSFO&invitationId=inv_7ed6851d-aafa-4f09-bf35-9f2f46e8d252

Our class diagram uses the strategy pattern for each piece's moves. When a piece moves, the from square will change to empty strategy, and the to square will get the strategy that the previous square had.

The class diagram uses the abstract factory pattern to draw black pieces and white pieces differently. It interacts with each square; the squares draw their own color and the piece that is on them. 
 
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.

 
 ## Screenshots
 https://youtu.be/e1k1t8uioH0
 
 Menu:
 ![Imgur Image](https://imgur.com/UBE6ons)
 
 New Game Load:
 ![Imgur Image](https://imgur.com/pztGuoi)
 
 Loading from save:
 ![Imgur Image](https://imgur.com/dUVl7aJ)
 
 Pre-Pawn Capture
 ![Imgur Image](https://imgur.com/5WlFAlO)
 
 Pos-Pawn Capture:
 ![Imgur Image](https://imgur.com/dakwlcz)

## Installation/Usage
Prerequisite installations:
-For Windows:
> Install mingw g++ onto your operating system 
> Download SFML for your operating system (https://www.sfml-dev.org/download/sfml/2.5.1/)

-For Linux:
> type sudo apt install libsfml-dev into terminal to download sfml
> install cmake and gcc/gpp

Running the game:
Create a game executable:
 > Move to the directory with CMakeLists.txt
 > "CMake ." (or "CMake3 ." when sshing onto sledge or hammer)
 > "make"
 Run the game executable
 > Move into build folder and type ./chess to run executable

## Testing
We used the googletest framework to test our program.
 - We tested Square, PieceFactory, and well as parts of piece.
 - The rest of the program we manually tested using the GUI
In order to run the unit tests, you will need to create and run the test executable.

Create a test executable:
 > Move to the directory with CMakeLists.txt
 > "CMake ." (or "CMake3 ." when sshing onto sledge or hammer)
 > "make"
 Run the test executable:
 > "./test

Current implementation status is:
- Panw works but the en-passant case does not
- Bishop works as intended
- No other piece works as intended
 
