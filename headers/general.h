#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#ifndef GENERAL_H
#define GENERAL_H

#define BOLD     "\e[1m"
#define BOLD_END "\e[m"
#define RESET    "\e[m"
#define BLUE     "\033[0;34m"
#define RED      "\033[0;31m"


void   introduction();
void   mainMenuPremium(char gender);
void   mainMenuBasic(char gender);

int    scanInteger();
double scanDouble();
char   scanChar();
void   scanName(char *name);
void   scanDate(char *tempDate, int *date, int *month, int *year);

int    countLeapYears(int month, int year);
int    differenceDate(int firstDate, int firstMonth, int firstYear, int currentDate, int currentMonth, int currentYear);
void   displayAge(int birthDate, int birthMonth, int birthYear);
void   convertMonth(int monthNumber, char *monthString);
bool   checkDate(int date, int month, int year);

double calculateBMI(int height, int weight, char *bmiCategory);

void   centimetresToFeet(int cms, int *feet, int *inches);
int    kilogramsToPounds(int kg);

void   countdown(int hours, int minutes, int seconds);
void   encode(char *plain, char *encoded);

#endif