#include "piece.hpp"

namespace sw {
namespace model {
Piece::Piece(Position position, Color color, Type type)
    : m_color(color), m_type(type) {}
} // namespace model
} // namespace sw