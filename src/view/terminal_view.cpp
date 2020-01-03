#include "terminal_view.hpp"
#include "model/simple_types.hpp"

#include <iostream> // TODO: remove

namespace sw {
namespace view {

std::map<model::Piece::Type, char> TerminalView::pieceCharMap = {
    {model::Piece::Type::PAWN, 'p'},   {model::Piece::Type::ROOK, 'r'},
    {model::Piece::Type::KNIGHT, 'k'}, {model::Piece::Type::BISHOP, 'b'},
    {model::Piece::Type::QUEEN, 'Q'},  {model::Piece::Type::KING, 'K'}};

std::map<model::Color, color_t> TerminalView::spaceColorMap = {
    {model::Color::BLACK, COLOR_CYAN}, {model::Color::WHITE, COLOR_BLACK}};

std::map<model::Color, color_t> TerminalView::pieceColorMap = {
    {model::Color::BLACK, COLOR_BLUE}, {model::Color::WHITE, COLOR_WHITE}};

const unsigned TerminalView::SPACE_HEIGHT = 3;
const unsigned TerminalView::SPACE_WIDTH = 5;

TerminalView::TerminalView(std::shared_ptr<model::Board> board)
    : m_board(board) {
  initscr();
  initColor();
  initBorder();
  initSpaces();
}

void TerminalView::initColor() {
  if (has_colors() == FALSE) {
    throw std::runtime_error("Terminal does not support colors.");
  }
  start_color();
  unsigned color_pair = 0;
  for (const auto &space_color : spaceColorMap) {
    for (const auto &piece_color : pieceColorMap) {
      // piece on space
      init_pair(color_pair, piece_color.second, space_color.second);
      m_colorPairMap.emplace(
          std::make_pair(piece_color.second, space_color.second), color_pair);
      color_pair++;
    }
    // empty space
    init_pair(color_pair, space_color.second, space_color.second);
    m_colorPairMap.emplace(
        std::make_pair(space_color.second, space_color.second), color_pair);
    color_pair++;
  }
}

void TerminalView::initBorder() {
  std::string colLabels = " 12345678 ";
  std::string rowLabels = " ABCDEFGH ";
  for (unsigned col = 0; col < 10; col++) {
    // TODO: would std::move be better here?
    m_view[0][col] = std::make_shared<Window>(
        SPACE_HEIGHT, SPACE_WIDTH, model::Position(0, col), COLOR_BLACK);
    m_view[0][col]->setChar(colLabels[col], COLOR_WHITE);
    m_view[9][col] = std::make_shared<Window>(
        SPACE_HEIGHT, SPACE_WIDTH, model::Position(9, col), COLOR_BLACK);
    m_view[9][col]->setChar(colLabels[col], COLOR_WHITE);
  }
  for (unsigned row = 1; row < 9; row++) {
    m_view[row][0] = std::make_shared<Window>(
        SPACE_HEIGHT, SPACE_WIDTH, model::Position(row, 0), COLOR_BLACK);
    m_view[row][0]->setChar(rowLabels[row], COLOR_WHITE);
    m_view[row][9] = std::make_shared<Window>(
        SPACE_HEIGHT, SPACE_WIDTH, model::Position(row, 9), COLOR_BLACK);
    m_view[row][9]->setChar(rowLabels[row], COLOR_WHITE);
  }
}

void TerminalView::initSpaces() {
  for (unsigned row = 1; row < 9; row++) {
    for (unsigned col = 1; col < 9; col++) {
      m_view[row][col] = std::make_shared<Window>(
          SPACE_HEIGHT, SPACE_WIDTH, model::Position(row, col),
          spaceColorMap[m_board->getColor(model::Position(row - 1, col - 1))]);
      m_view[row][col]->box();
      std::shared_ptr<model::Piece> piece =
          m_board->getPiece(model::Position(row - 1, col - 1));
      if (piece != nullptr) {
        m_view[row][col]->setChar(pieceCharMap[piece->getType()],
                                  pieceColorMap[piece->getColor()]);
      }
    }
  }
}

TerminalView::~TerminalView() { endwin(); }

void TerminalView::draw() {
  // TODO: stationary terminal mode
  drawBoard();
  // drawPrompt();
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
  for (unsigned row = 0; row < 10; row++) {
    for (unsigned col = 0; col < 10; col++) {
      m_view[row][col]->refresh(m_colorPairMap);
    }
  }
}

Window::Window(unsigned height, unsigned width, model::Position position,
               color_t bgColor)
    : m_height(height), m_width(width), m_colorPair(bgColor, bgColor),
      m_char(' ') {
  m_window = newwin(height, width, (height - 1) * position.row,
                    (width - 1) * position.col);
  // m_window = newwin(height, width, height * position.row, width *
  // position.col);
}

void Window::box() {
  // wborder(m_window, '|', '|', '-', '-', '+', '+', '+', '+'); // TODO:
  // better?
  ::box(m_window, 0, 0);
}

void Window::unBox() {
  wborder(m_window, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
}

void Window::setChar(char character, color_t fgColor = COLOR_BLACK) {
  m_char = character;
  m_colorPair.first = fgColor;
  mvwaddch(m_window, m_height / 2, m_width / 2, character);
}

void Window::clear() { setChar(' '); }

void Window::refresh(
    const std::map<std::pair<color_t, color_t>, color_t> &colorPairMap) {
  wbkgd(m_window,
        colorPairMap.at(std::make_pair(m_colorPair.first, m_colorPair.second)));
  wrefresh(m_window);
}

Window::~Window() {
  // clear borders
  unBox();
  // TODO: clear colors
  // clear char
  clear();
  // deallocate window
  delwin(m_window);
}

} // namespace view
} // namespace sw
