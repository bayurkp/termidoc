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

typedef struct Challengers {
    char username[100];
    int startDate;
    int score[30];
} Challengers;

void challenges();
void newChallenger();
void oldChallenger();
void displayScore(char *username);
bool checkChallenger(char *username);

#endif