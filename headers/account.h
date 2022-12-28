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

void premium(char *username);
bool checkPremium(char *username);
void payment(char *username);

void myProfile();
void konsultasiBarengTermy(char *username);
int  checkConsult(char *username);
int  updateConsult(char *username);

typedef struct Biodata {
    char   username[100];
    char   fullName[100];
    int    birthDate;
    int    birthMonth;
    int    birthYear;
    char   gender;
    int    height;
    int    weight;
    double bmiScore;
} Biodata;

#endif