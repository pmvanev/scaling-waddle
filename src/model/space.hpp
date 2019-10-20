#ifndef SPACE_HPP
#define SPACE_HPP

#include <memory>

#include "piece.hpp"
#include "simple_types.hpp"

namespace sw {
namespace model {

class Piece;

class Space {
public:
  Space(Position position = Position(0,0), Color color = Color::WHITE, const std::shared_ptr<Piece> piece = nullptr);
  void setPiece(const std::shared_ptr<Piece> piece);
  std::shared_ptr<Piece> getPiece();
  std::shared_ptr<Piece> removePiece();
  bool isEmpty();

private:
  Position m_position;
  Color m_color;
  std::shared_ptr<Piece> m_piece;
};

} // namespace model
} // namespace sw

#endif