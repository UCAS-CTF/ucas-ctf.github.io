# from https://docs.python.org/3/howto/curses.html#starting-and-ending-a-curses-application
from curses import window, wrapper

def main(stdscr : window):
    # Clear screen
    stdscr.clear()

    for i in range(0, 11):
        v = i + 1
        stdscr.addstr(i, 0, f"10 divided by {v} is {10 / v}")

    stdscr.refresh()
    stdscr.getkey()

if __name__ == "__main__":
    wrapper(main)
