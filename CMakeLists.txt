# Ensure that this script can only be run with modern versions of CMake that
# use config files
cmake_minimum_required(VERSION 3.0)

# Tell CMake what our project is called
project(MyWindow)

# Find version 2.5.0 of the SFML library on this computer,
# but only use the graphics package
# If the package can't be found, terminate the script
find_package(SFML 2.5 COMPONENTS graphics REQUIRED )

ADD_EXECUTABLE(test tests/test.cpp src/WhitePieceFactory.cpp src/BlackPieceFactory.cpp src/pieces/pawn.cpp src/pieces/rook.cpp src/pieces/bishop.cpp src/pieces/knight.cpp src/pieces/king.cpp src/pieces/queen.cpp)

# Tell the compiler where the source code is, and add it to the executable
add_executable(sfml-test src/main.cpp)# header/pieces/images/)


# Add the following SFML module to the application:
target_link_libraries(sfml-test sfml-graphics)