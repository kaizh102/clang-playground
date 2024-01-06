#include <ncurses.h>

int main(void) {
    initscr();  // ncurses function
    raw();
    keypad(stdscr, TRUE);

    int ch;
    while ((ch = getch()) != KEY_F(2)) {
        printw("Key pressed: %d\n", ch);
        refresh();
    }

    endwin();

    return 0;
}