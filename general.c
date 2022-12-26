#include "general.h"
#include "account.h"
#include "thirty.h"

extern Biodata bioUser;

// Modular untuk menampilkan pengenalan program
void introduction() {
    char option;
    printf("                    . .   . .  . .  . . .\n");
    printf("                    . .   . .  . .  . .  . .\n");
    printf("                    . .   . .  . .  . .  . . .\n");
    printf("                    . .                     . .\n");
    printf("                    . .        . .           . .\n");
    printf("                    . .        . .            . .");
    printf("                    . .    . . . . . .        . .\n");
    printf("                    . .     TERMIDOC          . .\n");
    printf("                    . .    . . . . . .        . .\n");
    printf("                    . .        . .            . .\n");
    printf("                    . .        . .            . .\n");
    printf("                    . .        . .      . .   . .\n");
    printf("                    . .         . . .  . .    . .\n");
    printf("                    . .           . . . .     . .\n");
    printf("                    . .                       . .\n");
    printf("                    . .                     . .\n");
    printf("                    . .   . .  . .  . .  . . .\n");
    printf("                    . .   . .  . .  . .  . .\n");
    printf("                    . .   . .  . .  . . .\n\n");
    printf("Termidoc\n");
    printf("-------------------------------------------\n");
    printf("Halo, Termy disini!\n");
    printf("-------------------------------------------\n");
    printf("Termidoc adalah program berbasis CLI\n");
    printf("yang dapat membantu Anda untuk menjaga\n");
    printf("kesehatan dan kebugaran badan.\n");
    printf("-------------------------------------------\n");
    printf("Sebelumnya, apakah Anda telah memiliki\n");
    printf("akun Termidoc? Jika sudah maka Termy\n");
    printf("akan mengarahkan Anda ke menu Sign In.\n");
    printf("*(Y/N)\n");
    printf("------------------------------------------\n> ");
    while(true) {
        option = scanChar();
        option = toupper(option);
        if(option == 'Y') {
            system("cls || clear");
            signIn();
            mainMenu(bioUser.gender);
            break;
        } else if(option == 'N') {
            system("cls || clear");
            signUp();
            mainMenu(bioUser.gender);
            break;
        } else {
            printf("Format salah\n> ");
        }
    }
}

// Modular untuk menampilkan menu utama
void mainMenu(char gender) {
    system("cls || clear");
    char option;
    int random;
    printf(BOLD "Menu Utama\n" BOLD_END);
    printf("---------------\n");
    printf("[ 1] Profil Saya\n");
    printf("[ 2] #30DaysChallenges\n");
    printf("[ 3] Kalkulator Stres\n");
    printf("[ 4] Kalkulator Risiko Diabetes\n");
    printf("[ 5] Kalkulator Risiko Jantung\n");
    printf("[ 6] Kalkulator Menstruasi\n");
    printf("[ 7] Rumah sakit Terdekat\n");
    printf("[ 8] Apotik Terdekat\n");
    printf("[ 9] Lapangan Terdekat\n");
    printf("[10] Gym Terdekat\n");
    printf("[11] Berita Kesehatan dan Olahraga\n");
    printf("[12] Keluar\n");
    printf("---------------\n");
    printf("Mohon masukkan kode pada []\n> ");
    option = scanInteger();
    switch(option) {
        case 1:
            myProfile();
            break;
        case 2:
            challenges();
            printf("Maaf, masih dalam perbaikan.\n");
            break;
        case 3:
            printf("Maaf, masih dalam perbaikan.\n");
            break;
        case 4:
            printf("Maaf, masih dalam perbaikan.\n");
            break;
        case 5:
            printf("Maaf, masih dalam perbaikan.\n");
            break;
        case 6:
            if(gender == 'L') {
                printf("Maaf, gender Anda tidak sesuai.\n");
            } else {
                printf("Maaf, masih dalam perbaikan.\n");
            }
            break;
        case 7:
            system("start https://www.google.com/search?q=Rumah+Sakit+Terdekat");
            break;
        case 8:
            system("start https://www.google.com/search?q=Apotik+Terdekat");
            break;
        case 9:
            system("start https://www.google.com/search?q=Lapangan+Olahraga+Terdekat");
            break;
        case 10:
            system("start https://www.google.com/search?q=Gym+Terdekat");
            break;
        case 11:
            random = rand() % 30;
            printf("%d", random);
            if(random > 25) {
                system("start https://kumparan.com/channel/bola-sports");
            } else if(random > 20) {
                system("start https://health.detik.com/");
            } else if(random > 15) {
                system("start https://sport.detik.com/");
            } else if(random > 10) {
                system("start https://www.cnnindonesia.com/olahraga");
            } else if(random > 5) {
                system("start https://www.cnnindonesia.com/gaya-hidup");
            } else {
                system("start https://health.kompas.com/");
            }
            break;
        case 12: 
            exit(0);
        default:
            printf("Maaf, opsi tidak ada\n");
    }
    mainMenu(gender);
}

// Modular untuk input bertipe data integer
int scanInteger() {
    char scan[100], wrongFormat;
    int ret;
    while(true) {
        scanf("%[^\n]", scan);
        fflush(stdin);
        if (sscanf(scan, "%d%c", &ret, &wrongFormat) == 1) {
            return ret;
            break;
        } else {
            printf("Format salah\n> ");
        }
    }
}

// Modular untuk input bertipe data integer
double scanDouble() {
    char scan[100], wrongFormat;
    double ret;
    while(true) {
        scanf("%[^\n]", scan);
        fflush(stdin);
        if (sscanf(scan, "%lf%c", &ret, &wrongFormat) == 1) {
            return ret;
            break;
        } else {
            printf("Format salah\n> ");
        }
    }
}

// Modular untuk input bertipe data integer
char scanChar() {
    char scan[100], wrongFormat;
    char ret;
    while(true) {
        scanf("%[^\n]", scan);
        fflush(stdin);
        if (sscanf(scan, "%c%c", &ret, &wrongFormat) == 1) {
            return ret;
            break;
        } else {
            printf("Format salah\n> ");
        }
    }
}

// Modular untuk menerima input nama dan mengubah ke sentence case
void scanName(char *name) {
    while(true) {
        int wrongFormat = 0;
        scanf("%[^\n]", name);
        fflush(stdin);
        for(int i = 0; i < strlen(name); i++) {
            if(!isupper(name[i]) && !islower(name[i]) && !isspace(name[i])) {
                wrongFormat++;
            }
        }
        if(wrongFormat > 0) {
            printf("Format nama salah\n> ");
        } else {
            name[0] = toupper(name[0]);
            for(int i = 0; i < strlen(name); i++) {
                if(isspace(name[i])) {
                    name[i + 1] = toupper(name[i + 1]);
                }
            }
            break;
        }
    }
}

// Modular untuk menerima input tanggal
void scanDate(char *tempDate, int *date, int *month, int *year) {
    while(true) {
        scanf("%[^\n]", tempDate);
        fflush(stdin);
        if(sscanf(tempDate, "%d-%d-%d", date, month, year) == 3) {
            if(checkDate(*date, *month, *year)) {
                break;
            } else {
                printf("Format tanggal salah\n> ");
            }
        } else {
            printf("Format tanggal salah\n> ");
        }
    }
}

// Modular untuk mengonversi angka bulan ke nama bulan
void convertMonth(int monthNumber, char *monthString) {
    if(monthNumber == 1) {
        strcpy(monthString, "Januari");
    } else if(monthNumber == 2) {
        strcpy(monthString, "Februari");
    } else if(monthNumber == 3) {
        strcpy(monthString, "Maret");
    } else if(monthNumber == 4) {
        strcpy(monthString, "April");
    } else if(monthNumber == 5) {
        strcpy(monthString, "Mei");
    } else if(monthNumber == 6) {
        strcpy(monthString, "Juni");
    } else if(monthNumber == 7) {
        strcpy(monthString, "Juli");
    } else if(monthNumber == 8) {
        strcpy(monthString, "Agustus");
    } else if(monthNumber == 9) {
        strcpy(monthString, "Sebtember");
    } else if(monthNumber == 10) {
        strcpy(monthString, "Oktober");
    } else if(monthNumber == 11) {
        strcpy(monthString, "November");
    } else {
        strcpy(monthString, "Desember");
    }
}

// Modular untuk menghitung umur
void calculateAge(int birthDate, int birthMonth, int birthYear, int *finalDate, int *finalMonth, int *finalYear) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int presentDate = tm.tm_mday;
    int presentMonth = tm.tm_mon + 1;
    int presentYear = tm.tm_year + 1900;

    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (birthDate > presentDate) {
        presentDate = presentDate + months[birthMonth - 1];
        presentMonth = presentMonth - 1;
    }
    if (birthMonth > presentMonth) {
        presentYear = presentYear - 1;
        presentMonth = presentMonth + 12;
    }

    *finalDate = presentDate - birthDate;
    *finalMonth = presentMonth - birthMonth;
    *finalYear = presentYear - birthYear;
}

// Modular untuk menghitung hari
int calculateDays(int fromDate, int fromMonth, int fromYear) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int presentDate = tm.tm_mday;
    int presentMonth = tm.tm_mon + 1;
    int presentYear = tm.tm_year + 1900;

    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (fromDate > presentDate) {
        presentDate = presentDate + months[fromMonth - 1];
        presentMonth = presentMonth - 1;
    }
    if (fromMonth > presentMonth) {
        presentYear = presentYear - 1;
        presentMonth = presentMonth + 12;
    }

    int finalDate = presentDate - fromDate;
    int finalMonth = presentMonth - fromMonth;
    int finalYear = presentYear - fromYear;

    finalDate = finalDate + (finalMonth * 30) + (finalYear * 365);
    return finalDate;
}

// Modular untuk validasi tanggal
bool checkDate(int date, int month, int year) {
    // Validasi tahun
    if(year >= 1900 && year <= 2022) {
            //check month
            if(month >= 1 && month <= 12) {
                //check days
                if((date >= 1 && date <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) {
                    return true;
                } else if((date >= 1 && date <= 30) && (month == 4 || month == 6 || month == 9 || month == 11)) {
                    return true;
                } else if((date>=1 && date<=28) && (month==2)) {
                    return true;
                } else if(date == 29 && month == 2 && (year % 400 == 0 ||(year % 4 == 0 && year % 100 != 0))) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
}

// Modular untuk menghitung skor BMI
double calculateBMI(int heightCM, int weightKG, char *bmiCategory) {
    double bmiScore;
    bmiScore = (float)weightKG / pow(((float)heightCM / 100), 2);

    if(bmiScore < 18.5) {
        strcpy(bmiCategory, "Kurang Berat Badan");
    } else if(bmiScore >= 18.5 && bmiScore <= 24.9) {
        strcpy(bmiCategory, "Normal atau Ideal");
    } else if(bmiScore > 24.9 && bmiScore <= 29.9) {
        strcpy(bmiCategory, "Kelebihan Berat Badan");
    } else if(bmiScore > 24.9 && bmiScore <= 34.9) {
        strcpy(bmiCategory, "Obesitas (Kelas I)");
    } else if(bmiScore > 34.9 && bmiScore <= 39.9) {
        strcpy(bmiCategory, "Obesitas (Kelas II)");
    } else {
        strcpy(bmiCategory, "Obesitas Ekstrim");
    }

    return bmiScore;
}

// Modular untuk mengonversi satuan centimeter ke kaki dan inci
void centimetresToFeet(int cms, int *feet, int *inches) {
    int tempCMs    = cms - (cms % 30);
    int tempInches = (cms % 30) / 2.54;
    int tempFeet   = ((float)tempCMs / 30.48) + 1;

    // Return nilai
    *feet = tempFeet;
    *inches = tempInches;
}

// Modular untuk mengonversi satuan kilogram ke pound
int kilogramsToPounds(int kgs) {
    return kgs * 2.205;
}

// Modular untuk menampilkan countdown 
void displayCountdown(int seconds) {
    while(seconds != 0) {
        printf("Waktu tersisa %d detik\n", seconds);
        sleep(1);
        seconds--;
        system("cls || clear");
    }
}
