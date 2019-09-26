#ifndef BOARD_HPP
#define BOARD_HPP

#include "space.hpp"
#include "observable.hpp"

namespace sw {
namespace model {

class Board : public Model {
  struct Position {
    unsigned int row;
    unsigned int col;
  };

public:
  std::shared_ptr<Piece> getPiece(Position position);
  void setPiece(Position position, std::shared_ptr<Piece> piece);
  bool clear(Position position);

private:
  Space &getSpace(Position position);
  std::array<std::array<Space, 8>, 8> m_spaces;
}

} // namespace model
} // namespace sw

#endif