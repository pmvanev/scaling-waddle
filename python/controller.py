# import curses
import curses
import model

"""Code for Controller in Model-View-Controller Pattern"""

class Controller(object):
    """
    Abstract Controller in Model-View-Controller Pattern.
    The Controller manipulates the Model (Board) which it encapsulates.
    """

    def __init__(self, board):
        self._board = board

    
class TerminalController(Controller):
    "Controller that takes terminal commands using curses."

    QUIT_KEYS = [ord('q'), ord('Q')]
    SELECT_KEYS = [curses.KEY_ENTER, ord(' '), ord('s'), ord('S')]
    UNSELECT_KEYS = [27, ord('u'), ord('U')]
    UP_KEYS = [curses.KEY_UP, ord('k'), ord('I')]
    DOWN_KEYS = [curses.KEY_DOWN, ord('j'), ord('K')]
    LEFT_KEYS = [curses.KEY_LEFT, ord('h'), ord('J')]
    RIGHT_KEYS = [curses.KEY_RIGHT, ord('l'), ord('L')]

    def __init__(self, terminal, board):
        Controller.__init__(self, board)
        self._terminal = terminal 

    def run(self):
        "Loop to take user input and apply commands to board."
        command = self._terminal.stdscr.getch() 
        while command not in TerminalController.QUIT_KEYS: 
            try:
                if command in TerminalController.SELECT_KEYS:
                    self._board.select()
                elif command in TerminalController.UNSELECT_KEYS:
                    self._board.unselect()
                elif command in TerminalController.UP_KEYS:
                    self._board.moveFocus(model.Direction.UP)
                elif command in TerminalController.DOWN_KEYS:
                    self._board.moveFocus(model.Direction.DOWN)
                elif command in TerminalController.LEFT_KEYS:
                    self._board.moveFocus(model.Direction.LEFT)
                elif command in TerminalController.RIGHT_KEYS:
                    self._board.moveFocus(model.Direction.RIGHT)
                else:
                    pass
            except Exception as e:
                print(e)
            command = self._terminal.stdscr.getch()
    
