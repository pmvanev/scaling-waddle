from enum import Enum
import observer

"""Code for a Model (game board) in a Model-View-Controller Pattern game"""

class Color(Enum):
    "color of space, piece, etc."
    WHITE = 1
    BLACK = 2

class Direction(Enum):
    "direction to move around board"
    UP = 1
    DOWN = 2
    LEFT = 3
    RIGHT = 4


class Piece(object): 
    "abstract game piece"
    def __init__(self, color):
        self.color = color


class Pawn(Piece):
    "chess pawn"
    pass


class Rook(Piece):
    "chess rook"
    pass
    

class Knight(Piece):
    "chess night"
    pass


class Bishop(Piece):
    "chess bishop"
    pass


class Queen(Piece):
    "chess queen"
    pass


class King(Piece):
    "chess king"
    pass



class Space(object):
    """
    Space on a game board.
    A Space must have a color and may optionally hold a piece.
    """

    def __init__(self, color, piece=None):
        self.color = color
        self.piece = piece

    def isEmpty(self):
        return self.piece is None



class Board(observer.Observable):
    """
    Game board -- the Model in the Model-View-Controller Pattern. The Model
    is observable by the View, and therefore updates the View when changes
    occur via the Observer Pattern.
    Piece can be moved by selecting a from space and a to space with the 
    moveFocus and select methods.
    """
    def __init__(self):
        observer.Observable.__init__(self)
        # model the board as an array of spaces that alternate color
        self._board = [[Space(Color.BLACK) if (i+j) % 2 else Space(Color.WHITE) for i in range(8)] for j in range(8)]
        self.selectedSpace = None # the currently selected space, used for piece movement
        self.focusSpace = (3,3) # the currently focused space, used for piece movement
        self.turnColor = Color.WHITE # the color who's turn it is to move

    def addPiece(self, piece, row, col):
        self._board[row][col].piece = piece
        self.notifyObservers([(row, col)])

    def removePiece(self, row, col):
        piece = self._board[row][col].piece
        self._board[row][col].piece = None
        self.notifyObservers([(row,col)])
        return piece

    def __getitem__(self, row):
        return self._board[row]

    def select(self): 
        "select the currently focused space"
        frow, fcol = self.focusSpace
        if not self.selectedSpace:
            # only select an occupied space of the current player's color
            if not self._board[frow][fcol].isEmpty() and self._board[frow][fcol].piece.color == self.turnColor:
                self.selectedSpace = self.focusSpace
        elif self.selectedSpace == self.focusSpace:
            self.unselect()
        else:
            # selecting a second space signifies a move
            sp = self.selectedSpace
            self.selectedSpace = None
            self.movePiece(sp, self.focusSpace)

    def unselect(self):
        "unselect the currently selected space"
        if self.selectedSpace:
            old_space = self.selectedSpace 
            self.selectedSpace = None
            self.notifyObservers([old_space])

    def movePiece(self, space_1, space_2):
        self.swapTurnColor()
        self.addPiece(self.removePiece(*space_1), *space_2)

    def swapTurnColor(self):
        self.turnColor = Color.WHITE if self.turnColor == Color.BLACK else Color.BLACK

    def moveFocus(self, direction):
        old_row, old_col = self.focusSpace
        if direction == Direction.UP:
            self.focusSpace = ((old_row - 1) % 8, old_col)
        elif direction == Direction.DOWN:
            self.focusSpace = ((old_row + 1) % 8, old_col)
        elif direction == Direction.LEFT:
            self.focusSpace = (old_row, (old_col - 1) % 8)
        elif direction == Direction.RIGHT:
            self.focusSpace = (old_row, (old_col + 1) % 8)
        else:
            pass
        self.notifyObservers([self.focusSpace, (old_row, old_col)])



class ChessBoard(Board):
    "A game board specifically layed out for Chess."

    START_POSITIONS = {
        Color.BLACK: {
            Pawn: [(1, col) for col in range(8)],
            Rook: [(0, 0), (0, 7)],
            Knight: [(0, 1), (0, 6)],
            Bishop: [(0, 2), (0, 5)],
            Queen: [(0, 3)],
            King: [(0, 4)]
        },
        Color.WHITE: {
            Pawn: [(6, col) for col in range(8)],
            Rook: [(7, 0), (7, 7)],
            Knight: [(7, 1), (7, 6)],
            Bishop: [(7, 2), (7, 5)],
            Queen: [(7, 3)],
            King: [(7, 4)]
        }
    }

    def setupPieces(self):
        for color, pieces in ChessBoard.START_POSITIONS.items():
            for piece_type, positions in pieces.items():
                for row, col in positions:
                    self.addPiece(piece_type(color), row, col)
