#include <stdlib.h>
#include <time.h>
#include "bulls.h"
#include <ncurses.h>

void ReadAttempt(int attempt[], int lvl){
	int i = 1;
	int j = 0;
	char c[lvl];
	do {
    	c[0] = getch();
    } while (c[0] <= '0' || c[0] > '9');
    printw("%c", c[0]);
    attempt[0] = c[0] - '0';
    do {
    	int flag = 0;
    	c[i] = getch();
    	if (c[i] < '0' || c[i] > '9')
    		flag = 1;
    	else
    	for (j = i-1; j >= 0; j--)
    		if (c[j] == c[i])
    			flag = 1;
    	if (flag == 1)
    		i--; 
    	if (flag == 0){
    		printw("%c", c[i]);
    		attempt[i] = c[i] - '0';
    	}
    } while (++i != lvl);
}

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

void DifficultyLVL(int *lvl) {
	char tmp;
	clear();
	Logo();
	*lvl = 0;
	printw("You can choose the difficulty level!\n");
	printw("\t\t1.Easy (4 numbers)\n");
	printw("\t\t2.Medium (5 numbers)\n");
	printw("\t\t3.Hard (6 numbers)\n");
	printw("LVL (input number): ");
	do {
		tmp = getch();
	} while(tmp < '1' || tmp > '3');
	*lvl = 3 + tmp - '0';
	clear();
}

void OnePlayer(int *lvl) {
	clear();
	int i = 1;
	int j = 0;
	int generate_num[*lvl];
	int attempt[*lvl];
	int bulls = 0;
	int cows = 0;
	int n = 1;
	int check = 0;
	generate_num[0] = 1 + rand() % 9;
	for (i = 1; i < *lvl; ++i) {
		generate_num[i] = rand() % 10;
		for (j = 0; j < i; ++j) {
			if (generate_num[i] == generate_num[j])
				--i;
		}
	}
	Logo();
	printw("N\tAttempt\tCows\tBulls\n");
	while (bulls != *lvl) {
		bulls = 0;
		cows = 0;
		printw("%d\t", n);
		ReadAttempt(attempt, *lvl);
		i = *lvl - 1;
		for (i = 0; i < *lvl; ++i)
			if (attempt[i] == generate_num[i]) bulls++;
		for (i = 0; i < *lvl; ++i)
			for (j = 0; j < *lvl; ++j)
				if (attempt[i] == generate_num[j]) cows++;
		cows -= bulls;
		printw("\t%d\t%d\n", cows, bulls);
		n++;
	}
	printw("You win!\nInput number for exit to menu: ");
	scanw("%d", &check);
	clear();

}

void Game(int *lvl) {
	srand(time(NULL));
	if (*lvl == 0) DifficultyLVL(&*lvl);
	OnePlayer(&*lvl);
}

void Authors() {
	clear();
	Logo();
	printw("\t\tAbove the game worked\n\t\tStudents of the Faculty of ICT\n");
	printw("\t\tBazhin Nikita\n\t\tAtuchin Stanislav\n\t\tAndreychenko Fillip\n");
	printw("\n\t\tNovosibirsk\n\t\tSibSUTI\n\t\t2017\n\n");
	printw("\tClick any button to return: ");
	getch();
	clear();
}

