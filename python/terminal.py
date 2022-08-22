import curses

class Terminal(object):
    "RAII context manager class for curses terminal setup and teardown."

    def __enter__(self):
        self.stdscr = curses.initscr()
        self.stdscr.refresh()
        curses.start_color()
        curses.noecho()
        curses.cbreak()
        curses.curs_set(0)
        self.stdscr.keypad(True)
        return self

    def __exit__(self, type, value, traceback):
        curses.nocbreak()
        self.stdscr.keypad(False)
        curses.echo()
        curses.endwin()