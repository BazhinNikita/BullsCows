#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

void Logo() {
	printw("\t+-+-+-+-+-+ +-+-+-+ +-+-+-+-+\n");
 	printw("\t|B|U|L|L|S| |A|N|D| |C|O|W|S|\n");
 	printw("\t+-+-+-+-+-+ +-+-+-+ +-+-+-+-+\n");
}

void Menu(int *item) {
 	char tmp;
 	clear();
 	Logo();
 	*item = 0;
	printw("\t\tWelcome to menu!\n");
	printw("\t\t1.Play\n\t\t2.Game rules\n\t\t3.Difficulty level");
	printw("\n\t\t4.Exit\n\t\t5.About authors\n");
	printw("\tMenu item number: ");
	do {
		tmp = getch();
	} while(tmp < '1' || tmp > '6');
	*item = tmp - '0';
	clear();
}


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

