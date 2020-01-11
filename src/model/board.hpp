#ifndef BOARD_HPP
#define BOARD_HPP

#include "observer/observable.hpp"
#include "piece.hpp"
#include "simple_types.hpp"
#include "space.hpp"

namespace sw {
namespace model {

class Board : public observer::Observable {
public:
  std::shared_ptr<Piece> getPiece(Position position);
  void setPiece(Position position, std::shared_ptr<Piece> piece);
  bool clear(Position position);
  std::vector<Position> getChanges();
  void clearChanges();
  void updateObservers() override;
  std::shared_ptr<Piece> removePiece(Position position);
  Color getColor(Position postion);
  void classicSetup();

private:
  Space &getSpace(Position position);
  std::array<std::array<Space, 8>, 8> m_spaces;
  std::vector<Position> m_changes;
};

} // namespace model
} // namespace sw

#endif