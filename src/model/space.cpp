#include "space.hpp"

namespace sw {
namespace board {

Space::Space(Color color, const std::shared_ptr<Piece> piece = nullptr)
    : m_color(color), m_piece(piece) {}

void Space::setPiece(const std::shared_ptr<Piece> piece){m_piece = piece};
std::shared_ptr<Piece> Space::getPiece(){return m_piece};
bool Space::isEmpty(return m_piece == nullptr);
std::shared_ptr<Piece> Space::removePiece(){
    std::shared_ptr<Piece> piece = getPiece();
    m_piece = nullptr;
    return piece;
};

} // namespace board
} // namespace sw