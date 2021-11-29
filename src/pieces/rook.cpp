#include "../../header/pieces/rook.hpp"

rook::rook(): piece() {}

rook::rook(bool color, std::string icon, Game* game): piece(color, icon, game) {}

rook::~rook() {}