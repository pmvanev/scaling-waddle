from model import ChessBoard
from terminal import Terminal
from view import TerminalView
from controller import TerminalController
import time

# model
chessBoard = ChessBoard()
chessBoard.setupPieces()

with Terminal() as terminal:
    # view
    terminalView = TerminalView(terminal, chessBoard)
    terminalView.draw()
    # controller
    terminalController = TerminalController(terminal, chessBoard)
    terminalController.run()
