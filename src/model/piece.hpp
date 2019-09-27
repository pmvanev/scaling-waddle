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
    Board::Position getPosition() {return m_position;}
    Type getType() {return m_type;}
    void setPosition(Board::Position position) {m_position = position;}
    // virtual bool canMoveTo(Board::Position position) = 0; // TODO:

private:
    Board::Position m_position;
    Color m_color;
    Type m_type;

};

} // namespace sw
} // namespace model

#endif