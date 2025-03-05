#include <ncurses.h>
#include <iostream>
using namespace std;
int main() {
    initscr(); // Start ncurses
    printw("Hello, World!"); // Print Hello, World!
    getch(); // Wait for user input
    endwin(); // End ncurses
    
    return 0;
}
