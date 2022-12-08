#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

// Fungsi untuk input bertipe data integer
int scanInteger() {
    char *scan, getError;
    int ret;
    while(true) {
        scanf("%[^\n]", scan);
        fflush(stdin);
        if (sscanf(scan, "%d%c", &ret, &getError) == 1) {
            return ret;
            break;
        } else {
            printf("Error...\n");
        }
    }
}

// Fungsi untuk input bertipe data integer
double scanDouble() {
    char *scan, getError;
    double ret;
    while(true) {
        scanf("%[^\n]", scan);
        fflush(stdin);
        if (sscanf(scan, "%lf%c", &ret, &getError) == 1) {
            return ret;
            break;
        } else {
            printf("Error...\n");
        }
    }
}

