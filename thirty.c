#include "general.h"
#include "account.h"
#include "thirty.h"

extern Biodata bioUser;

Challengers challUser;

// Username,tanggalMulai,tanggalTerakhir,tanggalSekarang,skor[30]

void challenges() {
    // Pengenalan dari #30DaysChallenges
    if(checkChallenger(bioUser.username)) {
        oldChallenger();
    } else {
        newChallenger();
    }
}

void newChallenger() {
    FILE *thirtyFile = fopen("thirty.txt", "a+");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int startDate  = tm.tm_mday;
    int startMonth = tm.tm_mon + 1;
    int startYear  = tm.tm_year + 1900;
    printf("%s,%d-%d-%d,%d,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0\n", bioUser.username, startDate, startMonth, startYear);
    fclose(thirtyFile);
    oldChallenger();
}

void oldChallenger() {
    // Pengenalan...
    printf("1. Skor Saya\n");
    printf("2. Tantangan Hari Ini\n");
    printf("3. Keluar\n");
    displayScore(bioUser.username);
    getchar();
}

// Modular menampilkan skor sementara
void displayScore(char *username) {
    char tempUsername[100];
    int  tempStartDate;
    int  tempStartMonth;
    int  tempStartYear;
    int  tempScore[30];

    FILE *thirtyFile = fopen("thirty.txt", "r");
    int  read;
    do {
        read = fscanf(thirtyFile, "%99[^,],%d-%d-%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", tempUsername, &tempStartDate, &tempStartMonth, &tempStartYear, &tempScore[0], &tempScore[1], &tempScore[2], &tempScore[3], &tempScore[4], &tempScore[5], &tempScore[6], &tempScore[7], &tempScore[8], &tempScore[9], &tempScore[10], &tempScore[12], &tempScore[13], &tempScore[14], &tempScore[15], &tempScore[16], &tempScore[17], &tempScore[18], &tempScore[19], &tempScore[20], &tempScore[21], &tempScore[22], &tempScore[23], &tempScore[24], &tempScore[25], &tempScore[26], &tempScore[27], &tempScore[28], &tempScore[29], &tempScore[30]);
        if(read == 34) {
            if(strcmp(username, tempUsername) == 0) {
                for(int i = 0; i < 30; i++) {
                    if(tempScore[i] != 0) {
                        printf("Skor Anda pada hari ke-%d : %d pts\n", i + 1, tempScore[i]);
                    }
                }
                break;
            } 
        }
    } while(!feof(thirtyFile));
    fclose(thirtyFile);
}

// Modular untuk mengecek apakah user telah memulai tantangan
bool checkChallenger(char *username) {
    char tempUsername[100];
    int  tempStartDate;
    int  tempStartMonth;
    int  tempStartYear;
    int  tempScore[30];

    FILE *thirtyFile = fopen("thirty.txt", "r");
    int  read;
    bool found;
    do {
        read = fscanf(thirtyFile, "%99[^,],%d-%d-%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", tempUsername, &tempStartDate, &tempStartMonth, &tempStartYear, &tempScore[0], &tempScore[1], &tempScore[2], &tempScore[3], &tempScore[4], &tempScore[5], &tempScore[6], &tempScore[7], &tempScore[8], &tempScore[9], &tempScore[10], &tempScore[12], &tempScore[13], &tempScore[14], &tempScore[15], &tempScore[16], &tempScore[17], &tempScore[18], &tempScore[19], &tempScore[20], &tempScore[21], &tempScore[22], &tempScore[23], &tempScore[24], &tempScore[25], &tempScore[26], &tempScore[27], &tempScore[28], &tempScore[29], &tempScore[30]);
        if(read == 34) {
            if(strcmp(username, tempUsername) == 0) {
                found = true;
                break;
            } else {
                found = false;
            }
        }
    } while(!feof(thirtyFile));
    fclose(thirtyFile);

    if(found) {
        return true;
    } else {
        return false;
    }
}