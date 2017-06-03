#ifndef F_F_H
#define F_F_H
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

void ReadAttempt(int attempt[], int lvl);
void Logo();
int Menu(char tmp);
void GameRules();
int TestLVL(int lvl);
int DifficultyLVL(int *lvl);
void OnePlayer(int *lvl);
void Game(int *lvl);
void Authors();
#endif
