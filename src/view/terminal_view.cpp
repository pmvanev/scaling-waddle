#include "terminal_view.hpp"
#include "model/simple_types.hpp"

#include <iostream>

namespace sw {
namespace view {

std::map<model::Piece::Type, char> TerminalView::charMap = {
    {model::Piece::Type::PAWN, 'p'},   {model::Piece::Type::ROOK, 'r'},
    {model::Piece::Type::KNIGHT, 'k'}, {model::Piece::Type::BISHOP, 'b'},
    {model::Piece::Type::QUEEN, 'Q'},  {model::Piece::Type::KING, 'K'}};

const unsigned TerminalView::SPACE_HEIGHT = 3;
const unsigned TerminalView::SPACE_WIDTH = 5;

TerminalView::TerminalView(std::shared_ptr<model::Board> board)
    : m_board(board) {
  // TODO: border
  initscr();
  for (unsigned x = 1; x < 9; x++) {
    for (unsigned y = 1; y < 9; y++) {
      m_view[x][y] = newwin(SPACE_HEIGHT, SPACE_WIDTH, (SPACE_HEIGHT - 1) * y,
                            (SPACE_WIDTH - 1) * x);
      box(m_view[x][y], 0, 0);
      //   wrefresh(m_view[x][y]);
    }
  }
  //   refresh();
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
  refresh(); // TODO: need this?
}

void TerminalView::drawPrompt() {
  // TODO: track whos move it is
  // TODO: move cursor to prompt line
  // std::cout << "Enter Move: "
}

void TerminalView::drawBoard() {
  for (unsigned x = 1; x < 9; x++) {
    for (unsigned y = 1; y < 9; y++) {
      wrefresh(m_view[x][y]);
    }
  }
  //   refresh();
}

TerminalView::~TerminalView() {
  for (unsigned x = 1; x < 9; x++) {
    for (unsigned y = 1; y < 9; y++) {
      // clear borders
      wborder(m_view[x][y], ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
      // TODO: clear colors
      // deallocate window
      delwin(m_view[x][y]);
    }
  }
  endwin();
}

} // namespace view
} // namespace sw
