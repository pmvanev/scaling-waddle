#ifndef SPACE_HPP
#define SPACE_HPP

#include "piece/piece.h"

namespace sw {
namespace model {

class Space {
public:
  enum class Color {
    white,
    black
  }

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