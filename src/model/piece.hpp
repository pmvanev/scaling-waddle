#ifndef PIECE_HPP
#define PIECE_HPP

#include "simple_types.hpp"

namespace sw {
namespace model {

class Piece {

public:
  enum class Type { PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING };

  Piece(Position position, Color color, Type type);

  Color getColor() { return m_color; }
  Type getType() { return m_type; }
  // virtual bool canMoveTo(Board::Position position) = 0; // TODO:

private:
  Color m_color;
  Type m_type;
};

} // namespace model
} // namespace sw

#endif