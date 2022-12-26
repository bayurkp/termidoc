#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#ifndef THIRTYDAYS_H
#define THIRTYDAYS_H

void   thirtyDaysChallenges();
void   newChallenger();
void   oldChallenger();
void   myScore(char *username);

void   todaysChallenges(char *username);
void   warmUp();
int    pushUp(int day);
int    sitUp(int day);
double run(int day);

void   leaderboard(char *username);

bool   checkChallenger(char *username);
void   updateScore(char *username, int day, int score);

#endif