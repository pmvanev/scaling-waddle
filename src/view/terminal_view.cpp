#include "terminal_view.hpp"

namespace sw {
namespace view {

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
      Board::Position boardPosition(i,j);
      Board::Position viewPosition = toViewPosition(boardPosition);
      m_view[viewPosition.row][viewPosition.col] = toChar(m_board.getPiece(boardPostion));
    }
  }
}

char TerminalView::toChar(std::shared_ptr<model::Piece> piece) {
  if (piece == nullptr) {
    return ' ';
  }
  return charMap[piece->getType()];
}

Position TerminalView::toViewPosition(Board::Position boardPosition) {
  return Board::Position(4 + 3*boardPosition.row, 8 + 6*boardPosition.col);
}

void TerminalView::draw() {
  //TODO: stationary terminal mode
  drawBoard();
  drawPrompt();
}
    
void TerminalView::update() {
  std::vector<Position> changes = m_board.getChanges();
}

void TerminalView::drawPrompt() {
  // TODO: track whos move it is
  std::cout << "Enter Move: "
}

void TerminalView::drawBoard() {
  for (const auto& row : m_view) {
    std::cout << row << std::endl;
  }
}

std::stringstream TerminalView::toStringStream() {
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

} // namespace view
} // namespace sw

