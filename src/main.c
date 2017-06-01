#include "bulls.h"
#include <ncurses.h>

int main() {
	initscr(); 
	scrollok(stdscr, TRUE); 
	noecho(); 
	int item;
	int lvl = 0;
	while (1) {
		Menu(&item);
		if (item == 1) Game(&lvl);
		if (item == 2) GameRules();
		if (item == 3) DifficultyLVL(&lvl);		
		if (item == 4) {
			endwin();
			return 0;
		}
		if (item == 5) Authors();
	}
	return 0;
}
