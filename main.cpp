#include "src/logger/logger.hpp"
#include <boost/log/trivial.hpp>

int main(int, char **) {
  sw::logger::init();
  // TODO: print banner
  // TODO: set up board
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
