#include "space.hpp"

namespace sw {
namespace model {

Space::Space(Board::Position position, Color color, const std::shared_ptr<Piece> piece = nullptr)
    : m_position(position), m_color(color), m_piece(piece) {
        if(!isEmpty()) {
            m_piece->setPosition(m_position);
        }
    }

void Space::setPiece(const std::shared_ptr<Piece> piece){m_piece = piece; m_piece->setPosition(m_position);}
std::shared_ptr<Piece> Space::getPiece(){return m_piece;}
bool Space::isEmpty() {return m_piece == nullptr;}
std::shared_ptr<Piece> Space::removePiece(){
    std::shared_ptr<Piece> piece = getPiece();
    m_piece = nullptr;
    return piece;
}

} // namespace model
} // namespace sw