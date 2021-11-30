# Ensure that this script can only be run with modern versions of CMake that
# use config files
cmake_minimum_required(VERSION 3.0)


# Tell CMake what our project is called
project(MyWindow)

# Find version 2.5.0 of the SFML library on this computer,
# but only use the graphics package
# If the package can't be found, terminate the script
find_package(SFML 2.5 COMPONENTS graphics REQUIRED )

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test 
    tests/test.cpp 
    src/WhitePieceFactory.cpp 
    src/BlackPieceFactory.cpp 
    src/pieces/piece.cpp
    src/pieces/pawn.cpp 
    src/pieces/rook.cpp 
    src/pieces/bishop.cpp 
    src/pieces/knight.cpp 
    src/pieces/king.cpp 
    src/pieces/queen.cpp
    src/square.cpp
    src/game.cpp
)

# Tell the compiler where the source code is, and add it to the executable
#add_executable(sfml-test src/main.cpp src/menu.cpp src/menu_gui.cpp src/game.cpp src/game_gui.cpp)# header/pieces/images/)
#add_executable(sfml-test src/main.cpp src/menu.cpp src/menu_gui.cpp src/game_gui.cpp)# header/pieces/images/)
add_executable(sfml-test 
    src/pieces/piece.cpp
    src/main.cpp 
    src/menu.cpp 
    src/menu_gui.cpp 
    src/game.cpp 
    src/game_gui.cpp 
    src/square.cpp 
    src/WhitePieceFactory.cpp
    src/BlackPieceFactory.cpp
    src/pieces/pawn.cpp 
    src/pieces/rook.cpp 
    src/pieces/bishop.cpp 
    src/pieces/knight.cpp 
    src/pieces/king.cpp 
    src/pieces/queen.cpp

)



# Add the following SFML module to the application:
target_link_libraries(sfml-test sfml-graphics)
