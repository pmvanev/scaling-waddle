#ifndef PIECE_HPP
#define PIECE_HPP

#include <color.hpp>
#include <board.hpp>

namespace sw {
namespace model {

class Piece {

enum class Type {
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

public:
    Color getColor() {return m_color;}
    Type getType() {return m_type;}
    // virtual bool canMoveTo(Board::Position position) = 0; // TODO:

private:
    Color m_color;
    Type m_type;

};

} // namespace sw
} // namespace model

#endif