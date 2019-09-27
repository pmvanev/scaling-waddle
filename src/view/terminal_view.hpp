
#ifndef TERMINAL_VIEW_HPP
#define TERMINAL_VIEW_HPP

#include "view.hpp"
#include "model/board.hpp"

  std::stringstream toStringStream(); // TODO: overload <<

namespace sw {
namespace terminal {

class TerminalView : public View {
public:
  void draw() override;
  void update() override;
  TerminalView(std::shared_ptr<model::Board> board);
private:
  std::shared_ptr<model::Board> m_board;
};

} // namespace view
} // namespace sw

#endif // TERMINAL_VIEW_HPP