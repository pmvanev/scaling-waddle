
#ifndef TERMINAL_VIEW_HPP
#define TERMINAL_VIEW_HPP

#include <map>
#include <ncurses.h>

#include "model/board.hpp"
#include "model/simple_types.hpp"
#include "observer/observable.hpp"

namespace sw {
namespace view {

using bg_color_t = NCURSES_COLOR_T;
using fg_color_t = NCURSES_COLOR_T;
using color_pair_t = NCURSES_COLOR_T;

class Window {
public:
  Window(unsigned height = 1, unsigned width = 1,
         model::Position position = {0, 0}, bg_color_t color = COLOR_BLACK);
  void refresh();
  void setChar(char character, fg_color_t color);
  void clear();
  void box();
  void unBox();

  virtual ~Window();

private:
  WINDOW *m_window;
  bg_color_t m_bgColor;
  fg_color_t m_fgColor;
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
  static std::map<model::Color, bg_color_t> spaceColorMap;
  static std::map<model::Color, fg_color_t> pieceColorMap;
  static const unsigned SPACE_HEIGHT;
  static const unsigned SPACE_WIDTH;

  std::shared_ptr<model::Board> m_board; // TODO: m_model?
  // TODO: separate containers for border windows and spaces?
  std::array<std::array<std::shared_ptr<Window>, 10>, 10> m_view;

  char toChar(std::shared_ptr<model::Piece>);
  void drawBoard();
  void drawPrompt();
  void initSpaces();
  void initBorder();
};

} // namespace view
} // namespace sw

#endif // TERMINAL_VIEW_HPP