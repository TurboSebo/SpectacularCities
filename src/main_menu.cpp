#include <iostream>
#include <ncurses.h>
#include <menu.h>
#include "../include/main_menu.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 4

using namespace std;
char *choices[] = {
    (char *)"Start Game",
    (char *)"Load Game",
    (char *)"Options",
    (char *)"Exit",

};


void main_menu() {
    cbreak(); 
    noecho();
    keypad(stdscr, TRUE);

    ITEM **menu_items; 
    MENU *m_menu;
    ITEM *cur_item;
    int choice; // User choice
    int n_choices = ARRAY_SIZE(choices); // Number of choices
    
    menu_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *)); // Alokuje pamięć dla tablicy wskaźników na elementy menu. 
    // Tablica ma rozmiar n_choices + 1, aby pomieścić wszystkie elementy menu oraz wskaźnik NULL na końcu.
    for (int i = 0; i < n_choices; i++) {
        menu_items[i] = new_item(choices[i], "");
    }
    menu_items[n_choices] = (ITEM *)NULL; // Ostatni element tablicy wskaźników musi być NULL.
    
    m_menu = new_menu((ITEM **)menu_items); // Tworzy nowe menu z tablicy wskaźników na elementy menu.
    post_menu(m_menu); // Wyświetla menu na ekranie.
    refresh(); // Odświeża ekran.

    while(choice=wgetch(stdscr)) {
        switch(choice) {
            case KEY_DOWN:
                menu_driver(m_menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(m_menu, REQ_UP_ITEM);
                break;
            case 10: // Enter
                move(20, 0);
                clrtoeol();
                mvprintw(20, 0, "Wybrano: %s", item_name(current_item(m_menu)));
                pos_menu_cursor(m_menu);
                break;
        }
        if(choice == 10) break; // Jeśli wybrano Enter, przerwij pętlę.
    }
   
    unpost_menu(m_menu);
    for(int i = 0; i < n_choices; ++i) free_item(menu_items[i]); // Usuwa elementy menu.
    free_menu(m_menu); // Usuwa menu.
    
}