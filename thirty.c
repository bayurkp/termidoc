#include "headers\general.h"
#include "headers\account.h"
#include "headers\thirty.h"

extern Biodata bioUser;

// Modular untuk mengidentifikasi eksitensi user pada #30DaysChallenges - Bayu
void thirtyDaysChallenges() {
    if(checkChallenger(bioUser.username)) {
        oldChallenger();
    } else {
        newChallenger();
    }
}

// Modular untuk user baru pada #30DaysChallenges - Bayu
void newChallenger() {
    char option;
    system("cls || clear");
    printf(BOLD "#30DaysChallenges" BOLD_END);
    printf("\n---------------\n");
    printf("#30DaysChallenges adalah program kebugaran dengan sistem\n");
    printf("yang menantang Anda untuk menyelesaikan tantangan selama\n");
    printf("30 hari kedepan. Anda siap?\n");
    printf("*(Y untuk SIAP! / N untuk KEMBALI)\n> ");
    while (true) {
        option = toupper(scanChar());
        if(option == 'Y') {
            FILE *thirtyFile = fopen("files/thirty.txt", "a+");
            time_t t = time(NULL);
            struct tm tm = *localtime(&t);
            int startDate  = tm.tm_mday;
            int startMonth = tm.tm_mon + 1;
            int startYear  = tm.tm_year + 1900;
            fprintf(thirtyFile, "%s,%d-%d-%d,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0\n", bioUser.username, startDate, startMonth, startYear);
            fclose(thirtyFile);
            oldChallenger();
            break;
        } else if (option == 'N') {
            premium(bioUser.username);
            break;
        } else {
            printf("Maaf, opsi tidak ada\n> ");
        }
    }   
}

// Modular untuk user lama pada #30DaysChallenges - Bayu
void oldChallenger() {
    printf("#30DaysChallanges");
    system("cls || clear");
    printf(BOLD "#30DaysChallenges" BOLD_END);
    printf("\n---------------\n");
    printf("[1] Skor Saya\n");
    printf("[2] Tantangan Hari Ini\n");
    printf("[3] Leaderboard\n");
    printf("[9] Kembali\n");
    printf("Mohon masukkan kode pada []\n> ");
    while(true) {
        int option = scanInteger();
        if(option == 1) {
            system("cls || clear");
            myScore(bioUser.username);
            break;
        } else if(option == 2) {
            system("cls || clear");
            todaysChallenges(bioUser.username);
            break;
        } else if(option == 3) {
            system("cls || clear");
            leaderboard(bioUser.username);
            break;
        } else if(option == 9) {
            system("cls || clear");
            premium(bioUser.username);
            break;
        } else {
            printf("Maaf, opsi tidak ada\n> ");
        }
    }
    printf("\n\n*(tekan apapun untuk kembali ke menu sebelumnya)");
    getch();
    oldChallenger();
}

// Modular menampilkan skor sementara - Bayu
void myScore(char *username) {
    printf(BOLD "Skor Saya" BOLD_END);
    printf("\n---------------\n");
    char tempUsername[100];
    int  tempStartDate;
    int  tempStartMonth;
    int  tempStartYear;
    int  tempScore[30] = {};

    FILE *thirtyFile = fopen("files/thirty.txt", "r");
    do {
        fscanf(thirtyFile, "%99[^,],%d-%d-%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", tempUsername, &tempStartDate, &tempStartMonth, &tempStartYear, &tempScore[0], &tempScore[1], &tempScore[2], &tempScore[3], &tempScore[4], &tempScore[5], &tempScore[6], &tempScore[7], &tempScore[8], &tempScore[9], &tempScore[10], &tempScore[11], &tempScore[12], &tempScore[13], &tempScore[14], &tempScore[15], &tempScore[16], &tempScore[17], &tempScore[18], &tempScore[19], &tempScore[20], &tempScore[21], &tempScore[22], &tempScore[23], &tempScore[24], &tempScore[25], &tempScore[26], &tempScore[27], &tempScore[28], &tempScore[29]);
        if(strcmp(username, tempUsername) == 0) {
            for(int i = 0; i < 30; i++) {
                if(tempScore[i] != 0) {
                    printf("Skor Anda pada hari ke-%d : %d pts\n", i + 1, tempScore[i]);
                }
            }
            break;
        } 
    } while(!feof(thirtyFile));
    fclose(thirtyFile);
}

// Modular untuk menjalankan tantangan hari ini - Bayu
void todaysChallenges(char *username) {
    char tempUsername[100];
    int  tempStartDate;
    int  tempStartMonth;
    int  tempStartYear;
    int  tempScore[30] = {};

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentDate  = tm.tm_mday;
    int currentMonth = tm.tm_mon + 1;
    int currentYear  = tm.tm_year + 1900;

    FILE *thirtyFile = fopen("files/thirty.txt", "r");
    do {
        fscanf(thirtyFile, "%99[^,],%d-%d-%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", tempUsername, &tempStartDate, &tempStartMonth, &tempStartYear, &tempScore[0], &tempScore[1], &tempScore[2], &tempScore[3], &tempScore[4], &tempScore[5], &tempScore[6], &tempScore[7], &tempScore[8], &tempScore[9], &tempScore[10], &tempScore[11], &tempScore[12], &tempScore[13], &tempScore[14], &tempScore[15], &tempScore[16], &tempScore[17], &tempScore[18], &tempScore[19], &tempScore[20], &tempScore[21], &tempScore[22], &tempScore[23], &tempScore[24], &tempScore[25], &tempScore[26], &tempScore[27], &tempScore[28], &tempScore[29]);
        if(strcmp(username, tempUsername) == 0) {
            break;
        }
    } while(!feof(thirtyFile));
    fclose(thirtyFile);

    int today = differenceDate(tempStartDate, tempStartMonth, tempStartYear, currentDate, currentMonth, currentYear);
    char option;
    if(today < 30) {
        if(tempScore[today] == 0) {
            printf(BOLD "Tantangan Hari ke-%d\n" BOLD_END, today + 1);
            printf("Skor BMI Anda adalah %0.2lf\n", bioUser.bmiScore);
            printf("Apakah Anda sudah siap? Jika ingin kembali silakan input 'N'\n");
            printf("*(Y/N)\n> ");
            while(true) {
                option = toupper(scanChar());
                if(option == 'Y') {
                    system("cls || clear");
                    warmUp();
                    system("cls || clear");
                    int pushUpScore = pushUp(today, bioUser.bmiScore);
                    system("cls || clear");
                    int sitUpScore  = sitUp(today, bioUser.bmiScore);
                    system("cls || clear");
                    double runScore = run(today, bioUser.bmiScore);
                    system("cls || clear");
                    int totalScore  = pushUpScore + sitUpScore + runScore;

                    printf(BOLD "Tantangan Hari ke-%d\n" BOLD_END, today + 1);
                    printf("\n---------------\n");       
                    printf("Anda telah menyelesaikan tantangan hari ke-%d\n", today + 1);
                    printf("*(tekan apapun untuk kembali ke menu sebelumnya)");
                    updateScore(username, today, totalScore);
                    updateWeight(username);
                    getch();
                    oldChallenger();
                    break;
                } else if(option == 'N') {
                    oldChallenger();
                    break;
                } else {
                    printf("Maaf, opsi tidak ada\n> ");
                }
            }
        } else {
            printf("Anda telah menyelesaikan #30DaysChallenges hari ini\n");
            printf("*(tekan apapun untuk kembali)\n");
            getch();  
            oldChallenger();
        }
    } else {
        printf("Selamat! Anda telah menyelesaikan #30DaysChallenges\n");
        printf("*(tekan apapun untuk kembali)\n");
        getch();  
        oldChallenger();
    }
}

// Modular pemanasan - Bayu
void warmUp() {
    printf(BOLD "0. Pemanasan" BOLD_END);
    printf("\n---------------\n");
    printf("Sebelum menyelesaikan tantangan, ayo lakukan pemanasan!\n");
    printf("*(lakukan pemanasan selama 10 menit!)\n\n");
    countdown(0, 10, 0);
    printf("\n*(tekan apapun untuk melanjutkan)\n");
    getch();
}

// Modular push up - Bayu
int pushUp(int day, int bmiScore) {
    int ret = 0;
    char option;
    printf(BOLD "1. Tantangan Push Up" BOLD_END);
    printf("\n---------------\n"); 
    printf("Tekan 'Y' untuk menantang dan 'N' untuk menyerah\n");
    printf("*(Y/N)\n> ");
    while(true) {
        option = toupper(scanChar());
        if(option== 'N') {
            return 0;
        } else if (option == 'Y') {
            break;
        } else {
            printf("Maaf, opsi tidak ada\n> ");
        }
    }

    printf("\n\nTantangan : \n");
    if(bmiScore < 18.5) {
        if(day < 10) {
            printf("*(lakukan 5 repetisi)\n");
            ret += 10;
        } else if(day >= 10 && day < 15) {
            printf("*(lakukan 8 repetisi)\n");
            ret += 15;
        } else if(day >= 15 && day < 20) {
            printf("*(lakukan 10 repetisi)\n");
            ret += 20;
        } else if (day >= 20) {
            printf("*(lakukan 15 atau lebih repetisi)\n");
            ret += 25;
        }
    } else if(bmiScore >= 18.5 && bmiScore <= 24.9) {
        if(day < 10) {
            printf("*(lakukan 10 repetisi)\n");
            ret += 10;
        } else if(day >= 10 && day < 15) {
            printf("*(lakukan 15 repetisi)\n");
            ret += 15;
        } else if(day >= 15 && day < 20) {
            printf("*(lakukan 20 repetisi)\n");
            ret += 20;
        } else if (day >= 20) {
            printf("*(lakukan 25 atau lebih repetisi)\n");
            ret += 25;
        }
    } else if(bmiScore > 24.9 && bmiScore <= 29.9) {
        if(day < 10) {
            printf("*(lakukan 5 repetisi)\n");
            ret += 10;
        } else if(day >= 10 && day < 15) {
            printf("*(lakukan 7 repetisi)\n");
            ret += 15;
        } else if(day >= 15 && day < 20) {
            printf("*(lakukan 9 repetisi)\n");
            ret += 20;
        } else if (day >= 20) {
            printf("*(lakukan 12 atau lebih repetisi)\n");
            ret += 25;
        }
    } else if(bmiScore > 24.9 && bmiScore <= 34.9) {
        if(day < 10) {
            printf("*(lakukan 4 repetisi)\n");
            ret += 10;
        } else if(day >= 10 && day < 15) {
            printf("*(lakukan 6 repetisi)\n");
            ret += 15;
        } else if(day >= 15 && day < 20) {
            printf("*(lakukan 8 repetisi)\n");
            ret += 20;
        } else if (day >= 20) {
            printf("*(lakukan 10 atau lebih repetisi)\n");
            ret += 25;
        }
    } else if(bmiScore > 34.9 && bmiScore <= 39.9) {
        if(day < 10) {
            printf("*(lakukan 3 repetisi)\n");
            ret += 10;
        } else if(day >= 10 && day < 15) {
            printf("*(lakukan 4 repetisi)\n");
            ret += 15;
        } else if(day >= 15 && day < 20) {
            printf("*(lakukan 5 repetisi)\n");
            ret += 20;
        } else if (day >= 20) {
            printf("*(lakukan 6 atau lebih repetisi)\n");
            ret += 25;
        }
    } else {
        if(day < 10) {
            printf("*(lakukan 3 repetisi)\n");
            ret += 10;
        } else if(day >= 10 && day < 15) {
            printf("*(lakukan 4 repetisi)\n");
            ret += 15;
        } else if(day >= 15 && day < 20) {
            printf("*(lakukan 5 repetisi)\n");
            ret += 20;
        } else if (day >= 20) {
            printf("*(lakukan 6 atau lebih repetisi)\n");
            ret += 25;
        }
    }
    
    printf("*(tekan apapun untuk melanjutkan)\n");
    getch();

    return ret;
}

// Modular sit up - Bayu
int sitUp(int day, int bmiScore) {
    int ret = 0;
    char option;
    printf(BOLD "2. Tantangan Sit Up" BOLD_END);
    printf("\n---------------\n"); 
    printf("Tekan 'Y' untuk menantang dan 'N' untuk menyerah\n");
    printf("*(Y/N)\n> ");
    while(true) {
        option = toupper(scanChar());
        if(option== 'N') {
            return 0;
        } else if (option == 'Y') {
            break;
        } else {
            printf("Maaf, opsi tidak ada\n> ");
        }
    }

    if(bmiScore < 18.5) {
        if(day < 10) {
            printf("*(lakukan 5 repetisi)\n");
            ret += 10;
        } else if(day >= 10 && day < 15) {
            printf("*(lakukan 8 repetisi)\n");
            ret += 15;
        } else if(day >= 15 && day < 20) {
            printf("*(lakukan 10 repetisi)\n");
            ret += 20;
        } else if (day >= 20) {
            printf("*(lakukan 15 atau lebih repetisi)\n");
            ret += 25;
        }
    } else if(bmiScore >= 18.5 && bmiScore <= 24.9) {
        if(day < 10) {
            printf("*(lakukan 10 repetisi)\n");
            ret += 10;
        } else if(day >= 10 && day < 15) {
            printf("*(lakukan 15 repetisi)\n");
            ret += 15;
        } else if(day >= 15 && day < 20) {
            printf("*(lakukan 20 repetisi)\n");
            ret += 20;
        } else if (day >= 20) {
            printf("*(lakukan 25 atau lebih repetisi)\n");
            ret += 25;
        }
    } else if(bmiScore > 24.9 && bmiScore <= 29.9) {
        if(day < 10) {
            printf("*(lakukan 5 repetisi)\n");
            ret += 10;
        } else if(day >= 10 && day < 15) {
            printf("*(lakukan 7 repetisi)\n");
            ret += 15;
        } else if(day >= 15 && day < 20) {
            printf("*(lakukan 9 repetisi)\n");
            ret += 20;
        } else if (day >= 20) {
            printf("*(lakukan 12 atau lebih repetisi)\n");
            ret += 25;
        }
    } else if(bmiScore > 24.9 && bmiScore <= 34.9) {
        if(day < 10) {
            printf("*(lakukan 4 repetisi)\n");
            ret += 10;
        } else if(day >= 10 && day < 15) {
            printf("*(lakukan 6 repetisi)\n");
            ret += 15;
        } else if(day >= 15 && day < 20) {
            printf("*(lakukan 8 repetisi)\n");
            ret += 20;
        } else if (day >= 20) {
            printf("*(lakukan 10 atau lebih repetisi)\n");
            ret += 25;
        }
    } else if(bmiScore > 34.9 && bmiScore <= 39.9) {
        if(day < 10) {
            printf("*(lakukan 3 repetisi)\n");
            ret += 10;
        } else if(day >= 10 && day < 15) {
            printf("*(lakukan 4 repetisi)\n");
            ret += 15;
        } else if(day >= 15 && day < 20) {
            printf("*(lakukan 5 repetisi)\n");
            ret += 20;
        } else if (day >= 20) {
            printf("*(lakukan 6 atau lebih repetisi)\n");
            ret += 25;
        }
    } else {
        if(day < 10) {
            printf("*(lakukan 3 repetisi)\n");
            ret += 10;
        } else if(day >= 10 && day < 15) {
            printf("*(lakukan 4 repetisi)\n");
            ret += 15;
        } else if(day >= 15 && day < 20) {
            printf("*(lakukan 5 repetisi)\n");
            ret += 20;
        } else if (day >= 20) {
            printf("*(lakukan 6 atau lebih repetisi)\n");
            ret += 25;
        }
    }

    printf("*(tekan apapun untuk melanjutkan)\n");
    getch();

    return ret;
}

// Modular tantangan berlari - Bayu
double run(int day, int bmiScore) {
    double time;
    char option;
    double range;
    printf(BOLD "3. Tantangan Berlari" BOLD_END);
    printf("\n---------------\n"); 
    printf("Tekan 'Y' untuk menantang dan 'N' untuk menyerah\n");
    printf("*(Y/N)\n> ");
    while(true) {
        option = toupper(scanChar());
        if(option== 'N') {
            return 0;
        } else if (option == 'Y') {
            break;
        } else {
            printf("Maaf, opsi tidak ada\n> ");
        }
    }

    printf("\n\nTantangan : \n");
    if(bmiScore < 18.5) {
        if(day < 10) {
            printf("*(berlari selama 5 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 5, 0);
            time = 15;
        } else if(day >= 10 && day < 15) {
            printf("*(berlari selama 7 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 7, 0);
            time = 20;
        } else if(day >= 15 && day < 20) {
            printf("*(berlari selama 10 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 10, 0);
            time = 25;
        } else if (day >= 20) {
            printf("*(berlari selama 15 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 15, 0);
            time = 35;
        }

        printf("Masukkan jarak tempuh lari Anda\n");
        printf("*(dalam meter)\n");
        range = scanDouble();

    } else if(bmiScore >= 18.5 && bmiScore <= 24.9) {
        if(day < 10) {
            printf("*(berlari selama 15 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 15, 0);
            time = 15;
        } else if(day >= 10 && day < 15) {
            printf("*(berlari selama 20 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 20, 0);
            time = 20;
        } else if(day >= 15 && day < 20) {
            printf("*(berlari selama 20 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 25, 0);
            time = 25;
        } else if (day >= 20) {
            printf("*(berlari selama 35 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 35, 0);
            time = 35;
        }

        printf("Masukkan jarak tempuh lari Anda\n");
        printf("*(dalam meter)\n");
        range = scanDouble();

    } else if(bmiScore > 24.9 && bmiScore <= 29.9) {
        if(day < 10) {
            printf("*(berlari selama 5 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 5, 0);
            time = 15;
        } else if(day >= 10 && day < 15) {
            printf("*(berlari selama 7 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 7, 0);
            time = 20;
        } else if(day >= 15 && day < 20) {
            printf("*(berlari selama 10 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 10, 0);
            time = 25;
        } else if (day >= 20) {
            printf("*(berlari selama 15 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 15, 0);
            time = 35;
        }

        printf("Masukkan jarak tempuh lari Anda\n");
        printf("*(dalam meter)\n");
        range = scanDouble();

    } else if(bmiScore > 24.9 && bmiScore <= 34.9) {
        if(day < 10) {
            printf("*(berlari selama 5 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 5, 0);
            time = 15;
        } else if(day >= 10 && day < 15) {
            printf("*(berlari selama 7 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 7, 0);
            time = 20;
        } else if(day >= 15 && day < 20) {
            printf("*(berlari selama 8 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 8, 0);
            time = 25;
        } else if (day >= 20) {
            printf("*(berlari selama 10 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 10, 0);
            time = 35;
        }

        printf("Masukkan jarak tempuh lari Anda\n");
        printf("*(dalam meter)\n");
        range = scanDouble();

    } else if(bmiScore > 34.9 && bmiScore <= 39.9) {
        if(day < 10) {
            printf("*(berlari selama 5 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 5, 0);
            time = 15;
        } else if(day >= 10 && day < 15) {
            printf("*(berlari selama 7 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 7, 0);
            time = 20;
        } else if(day >= 15 && day < 20) {
            printf("*(berlari selama 8 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 8, 0);
            time = 25;
        } else if (day >= 20) {
            printf("*(berlari selama 10 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 10, 0);
            time = 35;
        }

        printf("Masukkan jarak tempuh lari Anda\n");
        printf("*(dalam meter)\n");
        range = scanDouble();

    } else {
        if(day < 10) {
            printf("*(berlari selama 5 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 5, 0);
            time = 15;
        } else if(day >= 10 && day < 15) {
            printf("*(berlari selama 6 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 6, 0);
            time = 20;
        } else if(day >= 15 && day < 20) {
            printf("*(berlari selama 7 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 7, 0);
            time = 25;
        } else if (day >= 20) {
            printf("*(berlari selama 8 menit!)\n\n");
            printf("Sudah siap untuk lari?\n");
            printf("*(tekan apapun untuk SIAP)\n");
            getch();

            countdown(0, 8, 0);
            time = 35;
        }

        printf("Masukkan jarak tempuh lari Anda\n");
        printf("*(dalam meter)\n");
        range = scanDouble();
    }

    return range / time;
}

// Modular untuk menampilkan leaderboard - Bayu
void leaderboard(char *username) {
    struct Challengers {
        char username[100];
        int  totalScore;
    };

    char tempUsername[100];
    int  tempStartDate;
    int  tempStartMonth;
    int  tempStartYear;
    int  tempScore[30] = {};

    int lines = 0;
    FILE *thirtyFiles = fopen("files/thirty.txt", "r");
    do {
        fscanf(thirtyFiles, "%99[^,],%d-%d-%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", tempUsername, &tempStartDate, &tempStartMonth, &tempStartYear, &tempScore[0], &tempScore[1], &tempScore[2], &tempScore[3], &tempScore[4], &tempScore[5], &tempScore[6], &tempScore[7], &tempScore[8], &tempScore[9], &tempScore[10], &tempScore[11], &tempScore[12], &tempScore[13], &tempScore[14], &tempScore[15], &tempScore[16], &tempScore[17], &tempScore[18], &tempScore[19], &tempScore[20], &tempScore[21], &tempScore[22], &tempScore[23], &tempScore[24], &tempScore[25], &tempScore[26], &tempScore[27], &tempScore[28], &tempScore[29]);
        lines++;
    } while(!feof(thirtyFiles));
    fclose(thirtyFiles);

    struct Challengers challenger[lines];
    
    FILE *thirtyFile = fopen("files/thirty.txt", "r");
    int i = 0;
    do {
        fscanf(thirtyFile, "%99[^,],%d-%d-%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", tempUsername, &tempStartDate, &tempStartMonth, &tempStartYear, &tempScore[0], &tempScore[1], &tempScore[2], &tempScore[3], &tempScore[4], &tempScore[5], &tempScore[6], &tempScore[7], &tempScore[8], &tempScore[9], &tempScore[10], &tempScore[11], &tempScore[12], &tempScore[13], &tempScore[14], &tempScore[15], &tempScore[16], &tempScore[17], &tempScore[18], &tempScore[19], &tempScore[20], &tempScore[21], &tempScore[22], &tempScore[23], &tempScore[24], &tempScore[25], &tempScore[26], &tempScore[27], &tempScore[28], &tempScore[29]);
        strcpy(challenger[i].username, tempUsername);
        challenger[i].totalScore = 0;
        for(int k = 0; k < 30; k++) {
            challenger[i].totalScore += tempScore[k];
        }
        i++;
    } while(!feof(thirtyFile));
    fclose(thirtyFile);

    printf(BOLD "Leaderboard" BOLD_END);
    printf("\n---------------\n");
    struct Challengers temp;
    for(int j = 0; j < lines - 1; j++){
        for(int k = 0; k < lines - 1; k++) {
            if(challenger[k].totalScore < challenger[k + 1].totalScore){
                temp = challenger[k];
                challenger[k] = challenger[k + 1];
                challenger[k + 1] = temp;
            }
        }
    }
    
    for(int j = 0; j < lines; j++) {
        if(strcmp(challenger[j].username, username) == 0) {
            printf(BOLD "%d. %s : %d pts\n" BOLD_END, j + 1, challenger[j].username, challenger[j].totalScore);
        } else {
            printf("%d. %s : %d pts\n", j + 1, challenger[j].username, challenger[j].totalScore);
        }
    }
    printf("---------------\n");
}
 
// Modular untuk mengecek apakah user telah memulai tantangan - Bayu
bool checkChallenger(char *username) {
    char tempUsername[100];
    int  tempStartDate;
    int  tempStartMonth;
    int  tempStartYear;
    int  tempScore[30] = {};

    FILE *thirtyFile = fopen("files/thirty.txt", "r");
    if(thirtyFile == NULL) {
        printf("Maaf, file tidak ada\n");
    }

    int found = 0;
    do {
        fscanf(thirtyFile, "%99[^,],%d-%d-%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", tempUsername, &tempStartDate, &tempStartMonth, &tempStartYear, &tempScore[0], &tempScore[1], &tempScore[2], &tempScore[3], &tempScore[4], &tempScore[5], &tempScore[6], &tempScore[7], &tempScore[8], &tempScore[9], &tempScore[10], &tempScore[11], &tempScore[12], &tempScore[13], &tempScore[14], &tempScore[15], &tempScore[16], &tempScore[17], &tempScore[18], &tempScore[19], &tempScore[20], &tempScore[21], &tempScore[22], &tempScore[23], &tempScore[24], &tempScore[25], &tempScore[26], &tempScore[27], &tempScore[28], &tempScore[29]);
        if(strcmp(username, tempUsername) == 0) {
            found = 1;
            break;
        }
    } while(!feof(thirtyFile));
    fclose(thirtyFile);

    if(found == 1) {
        return true;
    } else {
        return false;
    }
}

// Modular untuk memperbarui skor - Bayu
void updateScore(char *username, int day, int score) {
    char tempUsername[100];
    int  tempStartDate;
    int  tempStartMonth;
    int  tempStartYear;
    int  tempScore[30] = {};

    FILE *thirtyFiles = fopen("files/thirty.txt", "r");
    FILE *tempThirtyFile = fopen("files/temp_thirty.txt", "w");
    do {
        fscanf(thirtyFiles, "%99[^,],%d-%d-%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", tempUsername, &tempStartDate, &tempStartMonth, &tempStartYear, &tempScore[0], &tempScore[1], &tempScore[2], &tempScore[3], &tempScore[4], &tempScore[5], &tempScore[6], &tempScore[7], &tempScore[8], &tempScore[9], &tempScore[10], &tempScore[11], &tempScore[12], &tempScore[13], &tempScore[14], &tempScore[15], &tempScore[16], &tempScore[17], &tempScore[18], &tempScore[19], &tempScore[20], &tempScore[21], &tempScore[22], &tempScore[23], &tempScore[24], &tempScore[25], &tempScore[26], &tempScore[27], &tempScore[28], &tempScore[29]);
        if(strcmp(username, tempUsername) == 0) {
            tempScore[day] = score;
            fprintf(tempThirtyFile, "%s,%d-%d-%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", tempUsername, tempStartDate, tempStartMonth, tempStartYear, tempScore[0], tempScore[1], tempScore[2], tempScore[3], tempScore[4], tempScore[5], tempScore[6], tempScore[7], tempScore[8], tempScore[9], tempScore[10], tempScore[11], tempScore[12], tempScore[13], tempScore[14], tempScore[15], tempScore[16], tempScore[17], tempScore[18], tempScore[19], tempScore[20], tempScore[21], tempScore[22], tempScore[23], tempScore[24], tempScore[25], tempScore[26], tempScore[27], tempScore[28], tempScore[29]);
            continue;
        } else {
            fprintf(tempThirtyFile, "%s,%d-%d-%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", tempUsername, tempStartDate, tempStartMonth, tempStartYear, tempScore[0], tempScore[1], tempScore[2], tempScore[3], tempScore[4], tempScore[5], tempScore[6], tempScore[7], tempScore[8], tempScore[9], tempScore[10], tempScore[11], tempScore[12], tempScore[13], tempScore[14], tempScore[15], tempScore[16], tempScore[17], tempScore[18], tempScore[19], tempScore[20], tempScore[21], tempScore[22], tempScore[23], tempScore[24], tempScore[25], tempScore[26], tempScore[27], tempScore[28], tempScore[29]);
        }
    } while(!feof(thirtyFiles));
    fclose(tempThirtyFile);
    fclose(thirtyFiles);

    remove("files/thirty.txt");
    rename("files/temp_thirty.txt", "files/thirty.txt");
}

// Modular untuk memperbarui berat badan - Bayu
void updateWeight(char *username) {
    char tempFullName[100];
    char tempUsername[100];
    char tempPassword[100];
    int  tempBirthDate;
    int  tempBirthMonth;
    int  tempBirthYear;
    char tempGender;
    int  tempHeight;
    int  tempWeight;
    int  newWeight;

    printf("Mohon masukkan berat badan Anda saat ini\n");
    printf("*(dalam kg)\n> ");
    newWeight = scanInteger();

    FILE *profileFile = fopen("files/profile.txt", "r");
    FILE *tempProfileFile = fopen("files/temp_profile.txt", "w");
    do {
        fscanf(profileFile, "%99[^,],%99[^,],%d-%d-%d,%c,%d,%d\n", tempUsername, tempFullName, &tempBirthDate, &tempBirthMonth, &tempBirthYear, &tempGender, &tempHeight, &tempWeight);
        if(strcmp(username, tempUsername) == 0) {
            fprintf(tempProfileFile, "%s,%s,%d-%d-%d,%c,%d,%d\n", tempUsername, tempFullName, tempBirthDate, tempBirthMonth, tempBirthYear, tempGender, tempHeight, newWeight);
        } else {
            fprintf(tempProfileFile, "%s,%s,%d-%d-%d,%c,%d,%d\n", tempUsername, tempFullName, tempBirthDate, tempBirthMonth, tempBirthYear, tempGender, tempHeight, tempWeight);
        }
    } while(!feof(profileFile));
    fclose(profileFile);
    fclose(tempProfileFile);

    remove("files/profile.txt");
    rename("files/temp_profile.txt", "files/profile.txt");
}