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

void introduction();
void mainMenu(char gender);

int scanInteger();
double scanDouble();
char scanChar();
void scanName(char *name);
void scanDate(char *tempDate, int *date, int *month, int *year);

void calculateAge(int birthDate, int birthMonth, int birthYear, int *finalDate, int *finalMonth, int *finalYear) ;
int calculateDays(int firstDate, int firstMonth, int firstYear);
void convertMonth(int monthNumber, char *monthString);
bool checkDate(int date, int month, int year);

double calculateBMI(int height, int weight, char *bmiCategory);

void centimetresToFeet(int cms, int *feet, int *inches);
int kilogramsToPounds(int kg);

void displayCountdown(int seconds);

#endif