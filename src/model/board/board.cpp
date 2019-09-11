#include "board.hpp"

namespace sw {
namespace board {

std::stringstream toStringStream() {
  std::stringstream stream;
  // TODO: table header
  stream << "        1     2     3     4     5     6     7     8" << std::endl
         << "      _______________________________________________"
         << std::endl;
  const char rowLabels[] = "ABCDEFGH";
  int r = 0;
  for (const auto &row : m_spaces) { // TODO: numeric iteration?
    // TODO: row header
    stream << "     |     |     |     |     |     |     |     |     |"
           << std::endl;
    // TODO: row content
    stream << "  " << rowLabel(r++) << "  |";
    for (const auto &space : row) { // TODO: numeric iteration?
      // TODO: ANSI colored pieces
      stream << "  " << getPiece() << "  |"
    }
    // TODO: row footer
    // TODO: ANSI colored footers
    stream << "     |_____|_____|_____|_____|_____|_____|_____|_____|"
           << std::endl;
  }
  // TODO: table footer
  stream << std::endl;
  stream << "        1     2     3     4     5     6     7     8" << std::endl;

  return stream;
}

std::shared_ptr<Piece> Board::getPiece(Position position) {
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

Space &getSpace(Position position) {
  return m_spaces.at(position.row).at(position.col);
}

} // namespace board
} // namespace sw
