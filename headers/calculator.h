#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#ifndef CALCULATOR_H
#define CALCULATOR_H

int  hHistory;
int  awal_subur;
int  ovulation;
int  akhir_subur;
int  bulan;
int  tahun;

// Prosedur-prosedur pada kalkulator stress
void sHeader(); 
int  stressChecking();
void stressLevel(int stressChecking);

// Prosedur-prosedur pada kalkulator risiko diabetes
void dOpening();
int  diabetesCheck();
void dCalculation(int diabetesCheck);

// Prosedur-prosedur pada kalkulator risiko jantung
void jStart();
int  jQuiz();
void calculateRisk(int jQuiz);

// Prosedur & fungsi pada fitur tracking menstruasi
void mStart();
void hHistory_f();
void ovulation_f();
void awalSubur_f();
void akhirSubur_f();
void trackResult(int hHistory, int ovulation, int awalSubur, int akhirSubur);

#endif