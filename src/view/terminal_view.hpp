
#ifndef TERMINAL_VIEW_HPP
#define TERMINAL_VIEW_HPP

#include <map>
#include <ncurses.h>

#include "model/board.hpp"
#include "model/simple_types.hpp"
#include "observer/observable.hpp"

namespace sw {
namespace view {

using color_t = NCURSES_COLOR_T;

class Window {
public:
  Window(unsigned height, unsigned width, model::Position position,
         color_t color);
  void
  refresh(const std::map<std::pair<color_t, color_t>, color_t> &colorPairMap);
  void setChar(char character, color_t color);
  void clear();
  void box();
  void unBox();

  virtual ~Window();

private:
  WINDOW *m_window;
  std::pair<color_t, color_t> m_colorPair;
  unsigned m_height;
  unsigned m_width;
  char m_char;
};

class TerminalView : public observer::Observer {

public:
  TerminalView(std::shared_ptr<model::Board> board);
  void draw();
  void update() override;

  virtual ~TerminalView();

private:
  static std::map<model::Piece::Type, char> pieceCharMap;
  static std::map<model::Color, color_t> spaceColorMap;
  static std::map<model::Color, color_t> pieceColorMap;
  static const unsigned SPACE_HEIGHT;
  static const unsigned SPACE_WIDTH;

  std::shared_ptr<model::Board> m_board; // TODO: m_model?
  // TODO: separate containers for border windows and spaces?
  std::array<std::array<std::shared_ptr<Window>, 10>, 10> m_view;
  std::map<std::pair<color_t, color_t>, color_t> m_colorPairMap;

  char toChar(std::shared_ptr<model::Piece>);
  void drawBoard();
  void drawPrompt();
  void initSpaces();
  void initBorder();
  void initColor();
};

} // namespace view
} // namespace sw

#endif // TERMINAL_VIEW_HPP