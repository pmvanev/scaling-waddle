
#ifndef TERMINAL_VIEW_HPP
#define TERMINAL_VIEW_HPP

#include "view.h"

  std::stringstream toStringStream(); // TODO: overload <<

namespace sw {
namespace terminal {

class TerminalView :: public View {
public:
  void draw() override;
  void update() override;
};

} // namespace view
} // namespace sw

#endif // TERMINAL_VIEW_HPP