#include "terminal_view.hpp"
#include "model/simple_types.hpp"

#include <iostream>

namespace sw {
namespace view {

std::map<model::Piece::Type, char> TerminalView::charMap = {
    {model::Piece::Type::PAWN, 'p'},   {model::Piece::Type::ROOK, 'r'},
    {model::Piece::Type::KNIGHT, 'k'}, {model::Piece::Type::BISHOP, 'b'},
    {model::Piece::Type::QUEEN, 'Q'},  {model::Piece::Type::KING, 'K'}};

TerminalView::TerminalView(std::shared_ptr<model::Board> board)
    : m_board(board) {
  m_view.reserve(30);
  m_view.emplace_back(
      "                                                           ");
  m_view.emplace_back(
      "        1     2     3     4     5     6     7     8        ");
  m_view.emplace_back(
      "      _______________________________________________      ");
  m_view.emplace_back(
      "     |     |     |     |     |     |     |     |     |     ");
  m_view.emplace_back(
      "  A  |     |     |     |     |     |     |     |     |  A  ");
  m_view.emplace_back(
      "     |_____|_____|_____|_____|_____|_____|_____|_____|     ");
  m_view.emplace_back(
      "     |     |     |     |     |     |     |     |     |     ");
  m_view.emplace_back(
      "  B  |     |     |     |     |     |     |     |     |  B  ");
  m_view.emplace_back(
      "     |_____|_____|_____|_____|_____|_____|_____|_____|     ");
  m_view.emplace_back(
      "     |     |     |     |     |     |     |     |     |     ");
  m_view.emplace_back(
      "  C  |     |     |     |     |     |     |     |     |  C  ");
  m_view.emplace_back(
      "     |_____|_____|_____|_____|_____|_____|_____|_____|     ");
  m_view.emplace_back(
      "     |     |     |     |     |     |     |     |     |     ");
  m_view.emplace_back(
      "  D  |     |     |     |     |     |     |     |     |  D  ");
  m_view.emplace_back(
      "     |_____|_____|_____|_____|_____|_____|_____|_____|     ");
  m_view.emplace_back(
      "     |     |     |     |     |     |     |     |     |     ");
  m_view.emplace_back(
      "  E  |     |     |     |     |     |     |     |     |  E  ");
  m_view.emplace_back(
      "     |_____|_____|_____|_____|_____|_____|_____|_____|     ");
  m_view.emplace_back(
      "     |     |     |     |     |     |     |     |     |     ");
  m_view.emplace_back(
      "  F  |     |     |     |     |     |     |     |     |  F  ");
  m_view.emplace_back(
      "     |_____|_____|_____|_____|_____|_____|_____|_____|     ");
  m_view.emplace_back(
      "     |     |     |     |     |     |     |     |     |     ");
  m_view.emplace_back(
      "  G  |     |     |     |     |     |     |     |     |  G  ");
  m_view.emplace_back(
      "     |_____|_____|_____|_____|_____|_____|_____|_____|     ");
  m_view.emplace_back(
      "     |     |     |     |     |     |     |     |     |     ");
  m_view.emplace_back(
      "  H  |     |     |     |     |     |     |     |     |  H  ");
  m_view.emplace_back(
      "     |_____|_____|_____|_____|_____|_____|_____|_____|     ");
  m_view.emplace_back(
      "                                                           ");
  m_view.emplace_back(
      "        1     2     3     4     5     6     7     8        ");
  m_view.emplace_back(
      "                                                           ");
  for (unsigned i = 0; i < 8; i++) {
    for (unsigned j = 0; j < 8; j++) {
      model::Position boardPosition(i, j);
      model::Position viewPosition = toViewPosition(boardPosition);
      m_view[viewPosition.row][viewPosition.col] =
          toChar(m_board->getPiece(boardPosition));
    }
  }
}

char TerminalView::toChar(std::shared_ptr<model::Piece> piece) {
  if (piece == nullptr) {
    return ' ';
  }
  return charMap[piece->getType()];
}

model::Position TerminalView::toViewPosition(model::Position boardPosition) {
  return model::Position(4 + 3 * boardPosition.row, 8 + 6 * boardPosition.col);
}

void TerminalView::draw() {
  // TODO: stationary terminal mode
  drawBoard();
  drawPrompt();
}

void TerminalView::update() {
  // TODO: save cursor position?
  std::vector<model::Position> changes = m_board->getChanges();
  for (const auto &change : changes) {
    //   model::Position viewPos = toViewPosition(change);
    // Piece piece = m_board->getPiece(boardPosition);
    // TODO: move cursor to view position
    // if (m_board->getSpace(boardPosition).isEmpty()) {
    // TODO: print ' ' at cursor location
    // } else {
    // TODO: print ansi color code for piece
    // TODO: print piece character
    // }
  }
  // TODO: print ansi reset
  // TODO: move cursor to saved position or prompt line
  m_board->clearChanges();
}

void TerminalView::drawPrompt() {
  // TODO: track whos move it is
  // TODO: move cursor to prompt line
  // std::cout << "Enter Move: "
}

void TerminalView::drawBoard() {
  for (const auto &row : m_view) {
    std::cout << row << std::endl;
  }
}

} // namespace view
} // namespace sw
