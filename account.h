#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#ifndef ACCOUNT_H
#define ACCOUNT_H

void signIn();
void signUp();
void scanUsername(char *username);
bool checkUsername(char *username);
void scanPassword(char *password);
bool checkPassword(char *username, char *password);
void myProfile();

typedef struct Biodata {
    char username[100];
    char fullName[100];
    int  birthDate;
    int  birthMonth;
    int  birthYear;
    char gender;
    int  height;
    int  weight;
} Biodata;

#endif