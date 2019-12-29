#include "piece.hpp"

namespace sw {
namespace model {
Piece::Piece(Position position, Color color, Type type)
    : m_position(position), m_color(color), m_type(type){}
}
} // namespace sw