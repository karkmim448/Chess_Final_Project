#include "../../header/pieces/knight.hpp"

knight::knight(): piece() {}

knight::knight(bool color, std::string icon, Game* game): piece(color, icon, game) {}

knight::~knight() {}