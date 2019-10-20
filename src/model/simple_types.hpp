#ifndef SIMPLE_TYPES_HPP
#define SIMPLE_TYPES_HPP

namespace sw {
namespace model {

enum class Color {
  WHITE,
  BLACK
};

struct Position {
  Position(unsigned row, unsigned col) : row(row), col(col) {};
  unsigned row;
  unsigned col;
};


}
}

#endif // SIMPLE_TYPES_HPP