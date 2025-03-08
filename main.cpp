#include <ncurses.h>
#include <iostream>
#include "include/main_menu.h"

using namespace std;
int main()
{
    initscr(); // Start ncurses
    main_menu(); // Display menu
    getch();        // Wait for user input
    endwin();       // End ncurses

    return 0;
}
