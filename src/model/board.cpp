#include "board.hpp"

namespace sw {
namespace model {

std::shared_ptr<Piece> Board::getPiece(Board::Position position) {
  return getSpace(position).getPiece();
}

void Board::setPiece(Board::Position position, std::shared_ptr<Piece> piece) {
  getSpace(position).setPiece(piece);
  m_changes.push_back(position);
}

std::shared_ptr<Piece> Board::removePiece(Board::Position position) {
  if (!getSpace(position).isEmpty()) {
    m_changes.push_back(position);
  }
  return getSpace(position).removePiece();
}

bool Board::clear(Board::Position position) {
  Space &space = getSpace(position);
  if (space.isEmpty()) {
    return false;
  }
  space.setPiece(nullptr);
  m_changes.push_back(position);
  return true;
}

Space& Board::getSpace(Board::Position position) {
  return m_spaces.at(position.row).at(position.col);
}

std::vector<Board::Position> Board::getChanges() {
  return m_changes;
}

void Board::clearChanges() {
  m_changes.clear();
}

void Board::updateObservers() {
  Observable::updateObservers();
  m_changes.clear();
}

Board::Position(unsigned row, unsigned col) : row(row), col(col) {
}

} // namespace model
} // namespace sw
