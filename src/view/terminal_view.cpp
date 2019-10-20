#include "terminal_view.hpp"
#include "model/simple_types.hpp"

namespace sw {
namespace view {

std::map<model::Piece::Type, char> TerminalView::charMap = {
    {model::Piece::Type::PAWN, 'p'},
    {model::Piece::Type::ROOK, 'r'},
    {model::Piece::Type::KNIGHT, 'k'},
    {model::Piece::Type::BISHOP, 'b'},
    {model::Piece::Type::QUEEN, 'Q'},
    {model::Piece::Type::KING, 'K'}
  };

TerminalView::TerminalView(std::shared_ptr<model::Board> board) : m_board(board) {
  m_view.reserve(30);
  m_view[0]  = "                                                           ";
  m_view[1]  = "        1     2     3     4     5     6     7     8        ";
  m_view[2]  = "      _______________________________________________      ";
  m_view[3]  = "     |     |     |     |     |     |     |     |     |     ";
  m_view[4]  = "  A  |     |     |     |     |     |     |     |     |  A  ";
  m_view[5]  = "     |_____|_____|_____|_____|_____|_____|_____|_____|     ";
  m_view[6]  = "     |     |     |     |     |     |     |     |     |     ";
  m_view[7]  = "  B  |     |     |     |     |     |     |     |     |  B  ";
  m_view[8]  = "     |_____|_____|_____|_____|_____|_____|_____|_____|     ";
  m_view[9]  = "     |     |     |     |     |     |     |     |     |     ";
  m_view[10] = "  C  |     |     |     |     |     |     |     |     |  C  ";
  m_view[11] = "     |_____|_____|_____|_____|_____|_____|_____|_____|     ";
  m_view[12] = "     |     |     |     |     |     |     |     |     |     ";
  m_view[13] = "  D  |     |     |     |     |     |     |     |     |  D  ";
  m_view[14] = "     |_____|_____|_____|_____|_____|_____|_____|_____|     ";
  m_view[15] = "     |     |     |     |     |     |     |     |     |     ";
  m_view[16] = "  E  |     |     |     |     |     |     |     |     |  E  ";
  m_view[17] = "     |_____|_____|_____|_____|_____|_____|_____|_____|     ";
  m_view[18] = "     |     |     |     |     |     |     |     |     |     ";
  m_view[19] = "  F  |     |     |     |     |     |     |     |     |  F  ";
  m_view[20] = "     |_____|_____|_____|_____|_____|_____|_____|_____|     ";
  m_view[21] = "     |     |     |     |     |     |     |     |     |     ";
  m_view[22] = "  G  |     |     |     |     |     |     |     |     |  G  ";
  m_view[23] = "     |_____|_____|_____|_____|_____|_____|_____|_____|     ";
  m_view[24] = "     |     |     |     |     |     |     |     |     |     ";
  m_view[25] = "  H  |     |     |     |     |     |     |     |     |  H  ";
  m_view[26] = "     |_____|_____|_____|_____|_____|_____|_____|_____|     ";
  m_view[27] = "                                                           ";
  m_view[28] = "        1     2     3     4     5     6     7     8        ";
  m_view[29] = "                                                           ";
  for(unsigned i = 0; i < 8; i++) {
    for(unsigned j = 0; j < 8; j++) {
      model::Position boardPosition(i,j);
      model::Position viewPosition = toViewPosition(boardPosition);
      m_view[viewPosition.row][viewPosition.col] = toChar(m_board->getPiece(boardPosition));
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
  return model::Position(4 + 3*boardPosition.row, 8 + 6*boardPosition.col);
}

void TerminalView::draw() {
  //TODO: stationary terminal mode
  drawBoard();
  drawPrompt();
}

void TerminalView::update() {
  // TODO: save cursor position?
  std::vector<model::Position> changes = m_board->getChanges();
  for (const auto& change : changes) {
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
  // for (const auto& row : m_view) {
  //   std::cout << row << std::endl;
  // }
}


} // namespace view
} // namespace sw

