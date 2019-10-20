#ifndef PIECE_HPP
#define PIECE_HPP

#include "simple_types.hpp"

namespace sw {
namespace model {

class Piece {

public:
    enum class Type {
        PAWN,
        ROOK,
        KNIGHT,
        BISHOP,
        QUEEN,
        KING
    };

    Color getColor() {return m_color;}
    Position getPosition() {return m_position;}
    Type getType() {return m_type;}
    void setPosition(Position position) {m_position = position;}
    // virtual bool canMoveTo(Board::Position position) = 0; // TODO:

private:
    model::Position m_position;
    Color m_color;
    Type m_type;

};

} // namespace sw
} // namespace model

#endif