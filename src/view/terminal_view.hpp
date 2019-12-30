
#ifndef TERMINAL_VIEW_HPP
#define TERMINAL_VIEW_HPP

#include <map>
#include <ncurses.h>

#include "model/board.hpp"
#include "model/simple_types.hpp"
#include "observer/observable.hpp"

namespace sw {
namespace view {

class TerminalView : public observer::Observer {

public:
  static std::map<model::Piece::Type, char> charMap;
  static const unsigned SPACE_HEIGHT;
  static const unsigned SPACE_WIDTH;

  TerminalView(std::shared_ptr<model::Board> board);
  void draw();
  void update() override;

  virtual ~TerminalView();

private:
  std::shared_ptr<model::Board> m_board;
  std::array<std::array<WINDOW *, 10>, 10> m_view;
  model::Position toViewPosition(model::Position boardPosition);
  char toChar(std::shared_ptr<model::Piece>);
  void drawBoard();
  void drawPrompt();
};

} // namespace view
} // namespace sw

#endif // TERMINAL_VIEW_HPP