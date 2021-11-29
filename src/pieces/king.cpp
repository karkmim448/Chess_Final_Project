#include "../../header/pieces/king.hpp"

king::king(): piece() {}

king::king(bool color, std::string icon, Game* game): piece(color, icon, game) {}

king::~king() {}