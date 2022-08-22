import observer
import model
import itertools
import curses
import terminal

"""Code for View in Model-View-Controller Pattern"""

class View(observer.Observer):
    """
    Abstract View class in Model-View-Controller Pattern. The View is an
    observer of the model. The observable model notifies the observing view
    of changes via the Observer.notify(changes) method.
    """

    def __init__(self, board):
        observer.Observer.__init__(self, board) 
        self._board = board  # model in MVC pattern

    def draw(self):
        "Abstract function to display the view for the user."
        pass

    def notify(self, changes=[]):
        """
        Called by Observable board that the View is observing when a change
        occurs.
        """
        for row, col in changes:
            self.update(row, col)

    def update(self, row, col):
        pass


class TerminalView(View):
    """
    A view using ncurses on the terminal.
    """

    CHAR_MAP = {
        type(None): ' ',
        model.Pawn: 'p',
        model.Rook: 'R',
        model.Knight: 'N',
        model.Bishop: 'B',
        model.Queen: 'Q',
        model.King: 'K'
    }

    SPACE_COLOR_MAP = {
        model.Color.BLACK: curses.COLOR_BLUE,
        model.Color.WHITE: curses.COLOR_CYAN
    }

    PIECE_COLOR_MAP = {
        model.Color.BLACK: curses.COLOR_BLACK,
        model.Color.WHITE: curses.COLOR_WHITE
    }

    COLOR_PAIR_MAP = {
        # (piece_color, space_color): color_pair_num
        # map foreground and background colors to curses_pair_num
        # e.g. read as "white on black" for white piece on black space
        (model.Color.WHITE, model.Color.WHITE) : 1,
        (model.Color.WHITE, model.Color.BLACK) : 2,
        (model.Color.BLACK, model.Color.WHITE) : 3,
        (model.Color.BLACK, model.Color.BLACK) : 4
    }

    FOCUS_COLOR_PAIR_MAP = {
        # (piece_color, turn_color): color_pair_num
        (model.Color.WHITE, model.Color.WHITE) : 5,
        (model.Color.WHITE, model.Color.BLACK) : 6,
        (model.Color.BLACK, model.Color.WHITE) : 7,
        (model.Color.BLACK, model.Color.BLACK) : 8
    }

    def _init_color_pairs(self):
        "set up curses color pairs"
        # non focused color pairs 
        for (piece_color, space_color), num in TerminalView.COLOR_PAIR_MAP.items():
            curses.init_pair(num, TerminalView.PIECE_COLOR_MAP[piece_color], TerminalView.SPACE_COLOR_MAP[space_color])
        # focused color pairs
        for (piece_color, turn_color), num in TerminalView.FOCUS_COLOR_PAIR_MAP.items():
            if piece_color == turn_color:
                # use space color for foreground so we can still see the piece
                curses.init_pair(num, TerminalView.SPACE_COLOR_MAP[piece_color], TerminalView.PIECE_COLOR_MAP[turn_color])
            else:
                curses.init_pair(num, TerminalView.PIECE_COLOR_MAP[piece_color], TerminalView.PIECE_COLOR_MAP[turn_color])

    def __init__(self, terminal, board):
        View.__init__(self,board)
        self._terminal = terminal # curses terminal session
        self._init_color_pairs()
        # board view is array of curses windows
        self._boardView = [[curses.newwin(3, 7, 3*i, 7*j) for j in range(8)] for i in range(8)]
        # fill in board colors and characters
        for row, col in itertools.product(range(8), range(8)):
            self.update(row, col)

    def _isFocused(self, row, col):
        "determine whether space is in cursor or select focus"
        return (row, col) in [self._board.selectedSpace, self._board.focusSpace]

    def _colorPairNum(self, row, col):
        "retrieve curses color pair number from appropriate map"
        space = self._board[row][col]
        piece = space.piece
        fg_color = piece.color if piece is not None else space.color
        if self._isFocused(row, col):
            return TerminalView.FOCUS_COLOR_PAIR_MAP[(fg_color, self._board.turnColor)]
        else:
            return TerminalView.COLOR_PAIR_MAP[(fg_color, space.color)]

    def draw(self):
        "overrides View.draw() to display the TerminalView on the terminal"
        for (i,j) in itertools.product(range(8), range(8)):
            self._boardView[i][j].refresh()

    def update(self, row, col):
        "overrides View.update() to update the terminal view when a change in the model (board) happens."
        piece = self._board[row][col].piece
        win = self._boardView[row][col]
        win.bkgd(' ', curses.color_pair(self._colorPairNum(row, col)))
        win.addch(1, 3, TerminalView.CHAR_MAP[type(piece)], curses.color_pair(self._colorPairNum(row, col)))
        win.refresh()
