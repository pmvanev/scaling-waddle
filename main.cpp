#include "logger/logger.hpp"
#include <boost/log/trivial.hpp>

#include <model/board.hpp>
#include <view/terminal_view.hpp>

using namespace sw;

int main(int, char **) {
  sw::logger::init();
  // TODO: print banner
  // TODO: set up board
  std::shared_ptr<model::Board> board = std::make_shared<model::Board>();
  std::shared_ptr<view::TerminalView> view = std::make_shared<view::TerminalView>(board);
  view->draw();
  bool keep_running = false;
  while (keep_running) {
    // TODO: display board
    // TODO: prompt for command
    // TODO: parse command
    // TODO: if command is invalid format, explain and re-prompt
    // TODO: if command is help, show commands
    // TODO: if command is display, show board
    // TODO: if command is exit, q, quit, etc... then quit
    // TODO: create move from command
    // TODO: check move for validity
    // TODO: if move is valid, execute
  }
  SW_LOG(debug) << "debug message";
  return 0;
}
