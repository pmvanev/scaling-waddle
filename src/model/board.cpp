#include "board.hpp"
#include "simple_types.hpp"

namespace sw {
namespace model {

void Board::classicSetup() {
  // pawns
  for (int col = 0; col < 8; col++) {
    setPiece(Position(1, col),
             std::make_shared<Piece>(Color::BLACK, Piece::Type::PAWN));
    setPiece(Position(6, col),
             std::make_shared<Piece>(Color::WHITE, Piece::Type::PAWN));
  }
  setPiece(Position(0, 0),
           std::make_shared<Piece>(Color::BLACK, Piece::Type::ROOK));
  setPiece(Position(0, 7),
           std::make_shared<Piece>(Color::BLACK, Piece::Type::ROOK));
}

std::shared_ptr<Piece> Board::getPiece(Position position) {
  return getSpace(position).getPiece();
}

void Board::setPiece(Position position, std::shared_ptr<Piece> piece) {
  getSpace(position).setPiece(piece);
  m_changes.push_back(position);
}

std::shared_ptr<Piece> Board::removePiece(Position position) {
  if (!getSpace(position).isEmpty()) {
    m_changes.push_back(position);
  }
  return getSpace(position).removePiece();
}

bool Board::clear(Position position) {
  Space &space = getSpace(position);
  if (space.isEmpty()) {
    return false;
  }
  space.setPiece(nullptr);
  m_changes.push_back(position);
  return true;
}

Space &Board::getSpace(Position position) {
  return m_spaces.at(position.row).at(position.col);
}

Color Board::getColor(Position position) {
  return getSpace(position).getColor();
}

std::vector<Position> Board::getChanges() { return m_changes; }

void Board::clearChanges() { m_changes.clear(); }

void Board::updateObservers() {
  Observable::updateObservers();
  m_changes.clear();
}

} // namespace model
} // namespace sw
