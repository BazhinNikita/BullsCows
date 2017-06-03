#include "bulls.h"
#include <ncurses.h>

int main() {
    initscr();
    scrollok(stdscr, TRUE);
    noecho();
    int lvl = 0;
    while(1) {
        clear();
        Logo();
        printw("\t\tWelcome to menu!\n");
        printw("\t\t1.Play\n\t\t2.Game rules\n\t\t3.Difficulty level");
        printw("\n\t\t4.Exit\n\t\t5.About authors\n");
        printw("\tMenu item number: ");
        char tmp = getch();
        Menu(tmp);
        if (Menu(tmp) == 1) Game(&lvl);
        if (Menu(tmp) == 2) GameRules();
        if (Menu(tmp) == 3) DifficultyLVL(&lvl);
        if (Menu(tmp) == 4) {
            endwin();
            return 0;
        };
        if (Menu(tmp) == 5) Authors();
    };
    return 0;
}
