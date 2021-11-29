#include "../../header/pieces/queen.hpp"

queen::queen(): piece() {}

queen::queen(bool color, std::string icon, Game* game): piece(color, icon, game) {}

queen::~queen() {}