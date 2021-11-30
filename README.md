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
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II.
 > * You should also update this README file by adding the following:
 >   * What design patterns did you use? For each design pattern you must explain in 4-5 sentences:
 >     * Why did you pick this pattern? And what feature did you implement with it?
 >     * How did the design pattern help you write better code?
 >   * An updated class diagram that reflects the design patterns you used. You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).
 >   * Make sure your README file (and Project board) are up-to-date reflecting the current status of your project. Previous versions of the README file should still be visible through your commit history.
> 
> During the meeting with your TA you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
