#include "../../header/pieces/bishop.hpp"

bishop::bishop(): piece() {}

bishop::bishop(bool color, std::string icon, Game* game): piece(color, icon, game) {}

bishop::~bishop() {}