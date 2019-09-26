#ifndef SPACE_HPP
#define SPACE_HPP

#include "piece.hpp"
#include "color.hpp"

namespace sw {
namespace model {

class Space {
public:
  Space(Color color, const std::shared_ptr<Piece> piece = nullptr);
  void setPiece(const std::shared_ptr<Piece> piece);
  std::shared_ptr<Piece> getPiece();
  std::shared_ptr<Piece> removePiece();
  bool isEmpty();

private:
  Color m_color;
  std::shared_ptr<Piece> m_piece;
}

} // namespace model
} // namespace sw

#endif