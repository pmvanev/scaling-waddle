
#ifndef TERMINAL_VIEW_HPP
#define TERMINAL_VIEW_HPP

#include "view.hpp"
#include "model/board.hpp"

  std::stringstream toStringStream(); // TODO: overload <<

namespace sw {
namespace view {

class TerminalView {
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
public:
  static std::map<model::Piece::Type, char> charMap = {
    {PAWN, 'p'},
    {ROOK, 'r'},
    {KNIGHT, 'k'},
    {BISHOP, 'b'},
    {QUEEN, 'Q'},
    {KING, 'K'}
  };
  TerminalView(std::shared_ptr<model::Board> board);
  void draw() override;
  void update() override;
private:
  std::shared_ptr<model::Board> m_board;
  std::vector<std::string> m_view;
};

} // namespace view
} // namespace sw

#endif // TERMINAL_VIEW_HPP