#ifndef BOARD_HPP
#define BOARD_HPP

#include "space.hpp"
#include "observable.hpp"

namespace sw {
namespace model {

class Board : public Observable {
  struct Position {
    Position(unsigned row, unsigned col);
    unsigned row;
    unsigned col;
  };

public:
  std::shared_ptr<Piece> getPiece(Position position);
  void setPiece(Position position, std::shared_ptr<Piece> piece);
  bool clear(Position position);
  std::vector<Position> getChanges(); 
  void updateObservers() override;
  std::shared_ptr<Piece> removePiece(Position position);

private:
  Space& getSpace(Position position);
  std::array<std::array<Space, 8>, 8> m_spaces;
  std::vector<Position> m_changes;
}

} // namespace model
} // namespace sw

#endif