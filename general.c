#include "headers\general.h"
#include "headers\account.h"
#include "headers\thirty.h"
#include "headers\calculator.h"

extern Biodata bioUser;

// Modular untuk menampilkan pengenalan program
void introduction() {
    system("cls || clear");
    printf(BLUE BOLD ". . . . . . . . . . . .\n" RESET);
    printf(BLUE BOLD ". . . . . . . . . . . . .\n" RESET);
    printf(BLUE BOLD ". .                     . .\n" RESET);
    printf(BLUE BOLD ". .                      . .\n" RESET);
    printf(BLUE BOLD ". .                       . .\n" RESET);
    printf(BLUE BOLD ". .    TERMIDOC           . .\n" RESET);
    printf(BLUE BOLD ". .    . . . . . .        . .\n" RESET);
    printf(BLUE BOLD ". .    . . . . . .        . .\n" RESET);
    printf(BLUE BOLD ". .        . .            . .\n" RESET);
    printf(BLUE BOLD ". .        . .            . .\n" RESET);
    printf(BLUE BOLD ". .        . .      . .   . .\n" RESET);
    printf(BLUE BOLD ". .         . . .  . .    . .\n" RESET);
    printf(BLUE BOLD ". .           . . . .     . .\n" RESET);
    printf(BLUE BOLD ". .                       . .\n" RESET);
    printf(BLUE BOLD ". .                      . .\n" RESET);
    printf(BLUE BOLD ". . . . . . . . . . . . . .\n" RESET);
    printf(BLUE BOLD ". . . . . . . . . . . . .\n" RESET);
    getch();
    
    system("cls || clear");
    char option;
    printf(BOLD "Termidoc\n" BOLD_END);
    printf("---------------\n");
    printf("Halo, Termy disini!\n");
    printf("---------------\n");
    printf("Termidoc adalah program berbasis CLI\n");
    printf("yang dapat membantu Anda untuk menjaga\n");
    printf("kesehatan dan kebugaran badan.\n");
    printf("---------------\n");
    printf("Sebelumnya, apakah Anda telah memiliki\n");
    printf("akun Termidoc? Jika sudah maka Termy\n");
    printf("akan mengarahkan Anda ke menu Sign In.\n");
    printf("*(Y/N)\n");
    printf("---------------\n> ");
    while(true) {
        option = scanChar();
        option = toupper(option);
        if(option == 'Y') {
            system("cls || clear");
            signIn();
            premium(bioUser.username);
            break;
        } else if(option == 'N') {
            system("cls || clear");
            signUp();
            premium(bioUser.username);
            break;
        } else {
            printf("Format salah\n> ");
        }
    }
}

// Modular untuk menampilkan menu utama dari user premium
void mainMenuPremium(char gender) {
    system("cls || clear");
    char option;
    int random;
    printf(BOLD "Menu Utama\n" BOLD_END);
    printf("---------------\n");
    printf("[ 1] Profil Saya\n");
    printf("[ 2] #30DaysChallenges\n");
    printf("[ 3] #KonsultasiBarengTermy\n");
    printf("[ 4] Kalkulator Stres\n");
    printf("[ 5] Kalkulator Risiko Diabetes\n");
    printf("[ 6] Kalkulator Risiko Jantung\n");
    printf("[ 7] Tracking Menstruasi\n");
    printf("[ 8] Rumah sakit Terdekat\n");
    printf("[ 9] Apotek Terdekat\n");
    printf("[10] Lapangan Terdekat\n");
    printf("[11] Gym Terdekat\n");
    printf("[12] Berita Kesehatan dan Olahraga\n");
    printf("[99] Keluar\n");
    printf("---------------\n");
    printf("Mohon masukkan kode pada []\n> ");
    option = scanInteger();
    switch(option) {
        case 1:
            myProfile();
            break;
        case 2:
            thirtyDaysChallenges();
            break;
        case 3:
            konsultasiBarengTermy(bioUser.username);
            break;
        case 4:
            sHeader();
            break;
        case 5:
            dOpening();
            break;
        case 6:
            jStart();
            break;
        case 7:
            if(gender == 'L') {
                printf("Maaf, gender Anda tidak sesuai.\n");
                break;
            } else {
                mStart();
                break;
            }
        case 8:
            system("start https://www.google.com/search?q=Rumah+Sakit+Terdekat");
            break;
        case 9:
            system("start https://www.google.com/search?q=Apotik+Terdekat");
            break;
        case 10:
            system("start https://www.google.com/search?q=Lapangan+Olahraga+Terdekat");
            break;
        case 11:
            system("start https://www.google.com/search?q=Gym+Terdekat");
            break;
        case 12:
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
        case 99: 
            exit(0);
        default:
            printf("Maaf, opsi tidak ada\n> ");
    }
    premium(bioUser.username);
}

// Modular untuk menampilkan menu utama dari user basic
void mainMenuBasic(char gender) {
    system("cls || clear");
    char option;
    int random;
    printf(BOLD "Menu Utama\n" BOLD_END);
    printf("---------------\n");
    printf("[ 1] Profil Saya\n");
    printf("[ 2] Kalkulator Stres\n");
    printf("[ 3] Kalkulator Risiko Diabetes\n");
    printf("[ 4] Kalkulator Risiko Jantung\n");
    printf("[ 5] Tracking Menstruasi\n");
    printf("[ 6] Rumah sakit Terdekat\n");
    printf("[ 7] Apotek Terdekat\n");
    printf("[ 8] Lapangan Terdekat\n");
    printf("[ 9] Gym Terdekat\n");
    printf("[10] Berita Kesehatan dan Olahraga\n");
    printf("[99] Keluar\n");
    printf("---------------\n");
    printf("Mohon masukkan kode pada []\n> ");
    option = scanInteger();
    switch(option) {
        case 1:
            myProfile();
            break;
        case 2:
            sHeader();
            break;
        case 3:
            dOpening();
            break;
        case 4:
            jStart();
            break;
        case 5:
            if(gender == 'L') {
                printf("Maaf, gender Anda tidak sesuai.\n");
            } else {
                mStart();
            }
            break;
        case 6:
            system("start https://www.google.com/search?q=Rumah+Sakit+Terdekat");
            break;
        case 7:
            system("start https://www.google.com/search?q=Apotik+Terdekat");
            break;
        case 8:
            system("start https://www.google.com/search?q=Lapangan+Olahraga+Terdekat");
            break;
        case 9:
            system("start https://www.google.com/search?q=Gym+Terdekat");
            break;
        case 10:
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
        case 99: 
            exit(0);
        default:
            printf("Maaf, opsi tidak ada\n> ");
    }
    premium(bioUser.username);
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

// Modular untuk menghitung jumlah tahun kabisat
int countLeapYears(int month, int year) {
    int years = year;
    
    if(month <= 2) {
        years--;
    }

    return years / 4 - years / 100 + years / 400;
}

// Modular untuk menghitung jumlah hari dari dua tanggal yang berbeda
int  differenceDate(int firstDate, int firstMonth, int firstYear, int currentDate, int currentMonth, int currentYear) {
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long int n1 = firstYear * 365 + firstDate;

    for (int i = 0; i < firstMonth - 1; i++) {
        n1 += monthDays[i];
    }

    n1 += countLeapYears(firstMonth, firstYear);
  
    long int n2 = currentYear * 365 + currentDate;
    for (int i = 0; i < currentMonth - 1; i++) {
        n2 += monthDays[i];
    }

    n2 += countLeapYears(currentMonth, currentYear);
  
    return n2 - n1;
}

// Menampilkan umur
void displayAge(int birthDay, int birthMonth, int birthYear) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentDate  = tm.tm_mday;
    int currentMonth = tm.tm_mon + 1;
    int currentYear  = tm.tm_year + 1900;

    int diff = differenceDate(birthDay, birthMonth, birthYear, currentDate, currentMonth, currentYear);
    
    int years  = diff / 365;
    int months = (diff - years * 365) / 30;
    int days   = diff - years * 365 - months * 30;

    printf("%d Tahun %d Bulan %d Hari\n", years, months, days);
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
void countdown(int hours, int minutes, int seconds) {
    while(true) {
		printf("       \r%d:%d:%d", hours, minutes, seconds);
		sleep(1);
		if(seconds != 0){
			seconds--;
		} else if(seconds == 0 && minutes != 0){
			seconds = 59;
			minutes--;
		} else if(seconds == 0 && minutes == 0 && hours != 0){
			hours--;
			minutes = 59;
			seconds = 59;
		} else if(hours == 0 && minutes == 0 && seconds == 0){
			break;
		}
	}
    printf("\n");
}

// Modular untuk melakukan encoding terhadap plain text
void encode(char *plain, char *encoded) {
    int i;
    int j;
    for(i = 0, j = 0; i < strlen(plain); i++, j += 2) {
        sprintf((char*)encoded + j, "%02x", plain[i] ^ 0xAA);
    }
    encoded[j] = '\0';
}