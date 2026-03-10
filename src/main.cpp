#include <ncurses.h>
#include <unistd.h>

int main(){
    // --- ncurses setup---
    initscr();                      // Starts ncurses
    cbreak();                       // Disable line buffering (get input instantly)
    noecho();                       // Don't print keypresses to screen
    keypad(stdscr, TRUE);           // Enable arrow keys
    curs_set(0);                    // Hide's cursor
    timeout(100);                   // Non-blocking input (100 ms)
    // blocking input means the program freezes and waits until a key is pressed
    // non blocking  means program doesn't wait in this case up to 100 ms only and then moves on.


    // Color setup
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_CYAN); // Color of blocks


    // Start block position
    int x = 10;
    int y = 5;

    while (true){
        clear();                    // Clears screen each frame

        box(stdscr, 0, 0);          // Draws border

        // Draws block
        attron(COLOR_PAIR(1));
        mvprintw(y, x * 2, " ");
        attroff(COLOR_PAIR(1));

        // Player Instructions
        mvprintw(20, 2, "Arrow keys to move. press Q to quit.");

        refresh();                 // pushes chages to screen

        // handles input
        int ch = getch();
        if (ch == 'q') break;
        else if (ch == KEY_LEFT && x > 1) x--;
        else if (ch == KEY_RIGHT && x < 18) x++;
        else if (ch == KEY_UP && y > 1) y--;
        else if (ch == KEY_DOWN && y < 18) y++;
    }

    endwin(); // ends ncurses
    return 0;
}