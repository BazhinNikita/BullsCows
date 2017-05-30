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

void GameRules()  {
	clear();
	Logo();
	printw("\t\t  +-+-+-+-+-+\n");
 	printw("\t\t  |R|U|L|E|S|\n");
 	printw("\t\t  +-+-+-+-+-+\n");
 	printw("The numerical version of the game is usually played with 4 digits, but can also be played with 3 or any other number of digits\nBy keybord the players each input a 4(5- or 6-)-digit secret number. The digits must be all different. Then, in turn, the players try to guess their opponent's number who gives the number of matches. If the matching digits are in their right positions, they are bulls, if in different positions, they are cows .\nExample:\nSecret number: 4271\nOpponent's try: 1234\nAnswer: 1 bull and 2 cows. (The bull is 2, the cows are 4 and 1.)\nThe first one to reveal the other's secret number wins the game.\n");
 	getch();
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

