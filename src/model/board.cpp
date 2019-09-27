#include "board.hpp"

namespace sw {
namespace model {

std::shared_ptr<Piece> Board::getPiece(Board::Position position) {
  return getSpace(position).getPiece();
}

void Board::setPiece(Position position, std::shared_ptr<Piece> piece) {
  getSpace(position).setPiece(piece);
}

bool Board::clear(Position position) {
  Space &space = getSpace(position);
  if (space.isEmpty()) {
    return false;
  }
  space.setPiece(nullptr);
  return true;
}

Space& getSpace(Board::Position position) {
  return m_spaces.at(position.row).at(position.col);
}

Board::Position(unsigned row, unsigned col) : row(row), col(col) {
}

} // namespace model
} // namespace sw
