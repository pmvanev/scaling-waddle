#ifndef BOARD_HPP
#define BOARD_HPP

#include "space.hpp"
#include <strstream>

namespace sw {
namespace board {

struct Position {
  unsigned int row;
  unsigned int col;
}

class Board {
public:
  std::shared_ptr<Piece> getPiece(Position position);
  void setPiece(Position position, std::shared_ptr<Piece> piece);
  bool clear(Position position);

private:
  Space &getSpace(Position position);
  std::array<std::array<Space, 8>, 8> m_spaces;
}

} // namespace board
} // namespace sw

#endif