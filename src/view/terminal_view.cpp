#include "terminal_view.hpp"

namespace sw {
namespace view {

void TerminalView::draw() {
  drawBoard();
  drawPrompt();
}
    
void TerminalView::update() {

}

void TerminalView::drawPrompt() {

}

void TerminalView::drawBoard() {

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

