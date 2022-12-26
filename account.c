#include "headers\general.h"
#include "headers\account.h"
#include "headers\thirty.h"
#include "headers\calculator.h"

Biodata bioUser;

// Modular untuk masuk atau login
void signIn() {
    char username[100];
    char password[100];
    char encodedPass[100];
    char tempFullName[100];
    char tempUsername[100];
    char tempPassword[100];
    int  tempBirthDate;
    int  tempBirthMonth;
    int  tempBirthYear;
    char tempGender;
    int  tempHeight;
    int  tempWeight;

    printf(BOLD "Sign In\n" BOLD_END);
    printf("---------------\n");
    printf("Mohon masukkan username untuk akun Anda\n> ");
    while (true) {
        scanUsername(username);
        if(checkUsername(username)) {
            break;
        } else {
            printf("Username tidak ada\n> ");
        }
    }    

    printf("Mohon masukkan password untuk akun Anda\n> ");
    while (true) {
        scanPassword(password);
        encode(password, encodedPass);
        if(checkPassword(username, encodedPass)) {
            break;
        } else {
            printf("Password salah\n> ");
        }
    }
    FILE *profileFile = fopen("files/profile.txt", "r");
    do {
        fscanf(profileFile, "%99[^,],%99[^,],%d-%d-%d,%c,%d,%d\n", tempUsername, tempFullName, &tempBirthDate, &tempBirthMonth, &tempBirthYear, &tempGender, &tempHeight, &tempWeight);
        if(strcmp(username, tempUsername) == 0) {
            // Copy data ke struct biodata
            strcpy(bioUser.username, tempUsername);
            strcpy(bioUser.fullName, tempFullName);
            bioUser.birthDate  = tempBirthDate;
            bioUser.birthMonth = tempBirthMonth;
            bioUser.birthYear  = tempBirthYear;
            bioUser.gender     = tempGender;
            bioUser.height     = tempHeight;
            bioUser.weight     = tempWeight;
            break;
        }
    } while(!feof(profileFile));
    fclose(profileFile);
    system("cls || clear");
}

// Modular untuk mendaftar atau sign up
void signUp() {
    char username[100];
    char password[100];
    char encodedPassword[100];
    char confirmPassword[100];
    char fullName[100];
    char tempDate[100];
    int  birthDate;
    int  birthMonth;
    int  birthYear;
    char gender;
    int  height;
    int  weight;

    printf(BOLD "Sign Up\n" BOLD_END);
    printf("---------------\n");
    printf("Mohon masukkan username untuk akun Anda\n");
    printf("*(terdiri dari 4 sampai 16 digit & berupa angka dan huruf)\n> ");
    scanUsername(username);

    printf("Mohon masukkan password untuk akun Anda\n");
    printf("*(lebih dari 8 digit & tidak dapat menggunakan simbol koma)\n> ");
    scanPassword(password);

    printf("Mohon masukkan konfirmasikan password Anda\n");
    printf("*(password yang sama)\n> ");
    while(true) {
        scanPassword(confirmPassword);
        if(strcmp(confirmPassword, password) == 0) {
            encode(password, encodedPassword);
            break;
        } else {
            printf("Password tidak sama\n> ");
        }
    }

    // Input Biodata
    system("cls || clear");
    printf("Biodata\n");
    printf("---------------\n");
    printf("Mohon masukkan nama lengkap Anda\n> ");
    scanName(fullName);

    printf("Mohon masukkan tanggal lahir Anda\n");
    printf("*(mm-dd-yyyy)\n> ");
    scanDate(tempDate, &birthDate, &birthMonth, &birthYear);

    printf("Mohon masukkan gender Anda\n");
    printf("*(L/P)\n> ");
    while (true) {
        gender = scanChar();
        gender = toupper(gender);
        if(gender == 'L' || gender == 'P') {
            break;
        } else {
            printf("Format gender salah\n> ");
        }
    }

    printf("Mohon masukkan tinggi badan Anda\n");
    printf("*(dalam cm)\n> ");
    height = scanInteger();

    printf("Mohon masukkan berat badan Anda\n");
    printf("*(dalam kg)\n> ");
    weight = scanInteger();

    // Copy data ke file .txt
    FILE *accountFile = fopen("files/account.txt", "a+");
    fprintf(accountFile, "%s,%s", username, encodedPassword);
    fclose(accountFile);
    FILE *profileFile = fopen("files/profile.txt", "a+");
    fprintf(profileFile, "%s,%s,%d-%d-%d,%c,%d,%d\n", username, fullName, birthDate, birthMonth, birthYear, gender, height, weight);
    fclose(profileFile);
    system("cls || clear");
    // Melakukan login
    signIn();
}

// Modular untuk mengecek eksistensi username pada account.txt
bool checkUsername(char *username) {
    char tempUsername[100]; // Variabel untuk menyimpan username dari file
    char tempPassword[100]; // Variabel untuk menyimpan password dari file
    int  found;
    FILE *accountFile = fopen("files/account.txt", "r");
    do {
        int read = fscanf(accountFile, "%99[^,],%99[^\n]\n", tempUsername, tempPassword);
        if(read == 2) {
            if(strcmp(username, tempUsername) == 0) {
                found = 1; // Username ada atau sudah digunakan
                break;
            }
        }
    } while(!feof(accountFile));
    fclose(accountFile);

    if(found == 1) {
        return true; // Username ada atau sudah digunakan
    } else {
        return false; // Username tidak ada atau belum digunakan (boleh digunakan)
    }
}

// Modular untuk mengecek kesesuaian antara username dan password
bool checkPassword(char *username, char *encodedPass) {
    char tempUsername[100]; // Variabel untuk menyimpan username dari file
    char tempEncodedPass[100]; // Variabel untuk menyimpan password dari file
    int  valid;
    FILE *accountFile;
    accountFile = fopen("files/account.txt", "r");
    do {
        fscanf(accountFile, "%99[^,],%99[^\n]\n", tempUsername, tempEncodedPass);
        if(strcmp(username, tempUsername) == 0) {
            if(strcmp(encodedPass, tempEncodedPass) == 0) {
                valid = 1; // Username dan password sesuai
                break;
            }
        }
    } while(!feof(accountFile));
    fclose(accountFile);    

    if(valid == 1) {
        return true;
    } else {
        return false;
    }
}

// Modular untuk membuat username
void scanUsername(char *username) {
    // Input dan validasi username
    while(true) {
        scanf("%[^\n]", username);
        fflush(stdin);

        int wrongFormat = 0;
        if(strlen(username) < 4 || strlen(username) > 16) wrongFormat++;
        for(int i = 0; i < strlen(username); i++) {
            if(!isdigit(username[i]) && !islower(username[i]) && !isupper(username[i])) wrongFormat++;
        }

        if(wrongFormat > 0) {
            printf("Format username salah\n> ");
        } else {
            break;
        }
    }
    // Selesai input dan validasi username
}

// Modular untuk membuat password
void scanPassword(char *password) {
    char tempPassword[100];
    char charsPassword; // Karakter untuk yang diinput ke password
    while(true) {
        // Input password
        int i = 0;
        while ((charsPassword = getch()) != 13) {
            if (charsPassword == '\b' && i > 0) {
                i--;
                tempPassword[i] = 0;
                printf("\b \b");
            } else {
                if (charsPassword > 31 && charsPassword < 127) {
                    tempPassword[i] = charsPassword;
                    i++;
                    printf("*");
                }
            }
        }
        tempPassword[i] = '\0';
        fflush(stdin);

        // Validasi password
        int wrongFormat = 0;
        if(strlen(tempPassword) < 8) wrongFormat++;
        for(int i = 0; i < strlen(tempPassword); i++) {
            if(!(tempPassword[i] > 31 && tempPassword[i] < 127) || tempPassword[i] == 44) wrongFormat++;
        }

        if(wrongFormat > 0) {
            printf("\nFormat password salah\n> ");
        } else {
            break;
        }
    }

    printf("\n");
    strcpy(password, tempPassword);
}

// Modular untuk menampilkan profil pengguna
void myProfile() {
    system("cls || clear");
    printf(BOLD "Profil Saya" BOLD_END);
    printf("\n---------------\n");
    printf(BOLD "%s" BOLD_END, bioUser.username);
    printf("\n---------------\n");
    printf("Nama     : %s\n", bioUser.fullName);

    char monthString[20];
    convertMonth(bioUser.birthMonth, monthString);
    printf("Lahir    : %d %s %d\n", bioUser.birthDate, monthString, bioUser.birthYear);

    printf("Umur     : ");
    displayAge(bioUser.birthDate, bioUser.birthMonth, bioUser.birthYear);
    
    char gender[20];
    if(bioUser.gender == 'L') {
        strcpy(gender, "Laki-Laki");
    } else {
        strcpy(gender, "Perempuan");
    }
    printf("Gender   : %s\n", gender);

    int feet;
    int inches;
    centimetresToFeet(bioUser.height, &feet, &inches);
    printf("Tinggi   : %d cm (%d\' %d\")\n", bioUser.height, feet, inches);

    int pounds;
    pounds = kilogramsToPounds(bioUser.weight);
    printf("Berat    : %d kg (%d lb)\n", bioUser.weight, pounds);

    char   bmiCategory[20];
    double bmiScore;
    bmiScore = calculateBMI(bioUser.height, bioUser.weight, bmiCategory);
    printf("Skor BMI : %.2lf\n", bmiScore);
    printf("Kategori : %s\n", bmiCategory);
    printf("---------------\n");
    printf("Kembali? (Y/N)\n> ");
    char option = scanChar();
    if(toupper(option) == 'Y') {
        premium(bioUser.username);
    } else {
        myProfile();
    }
}

// Modular untuk menampilkan iklan 
void premium(char *username) {
    system("cls || clear");
    if(!checkPremium(username)) {
        printf(BOLD "Akun Premium\n" BOLD_END);
        printf("---------------\n");
        printf("Gunakan akun premium untuk dapat menggunakan\n");
        printf("fitur unggulan dari Termidoc hanya dengan\n");
        printf(BOLD "Rp 10.000 per bulan\n\n" BOLD_END);

        printf(BOLD "Fitur                      | Premium | Basic \n" BOLD_END);
        printf("#30DaysChallenges          |    V    |   X   \n");
        printf("#KonslutasiBarengTermy     |    V    |   X   \n");
        printf("Kalkulator Stress          |    V    |   V   \n");
        printf("Kalkulator Risiko Diabetes |    V    |   V   \n");
        printf("Kalkulator Risiko Jantung  |    V    |   V   \n");
        printf("Kalkulator Menstruasi      |    V    |   V   \n");
        printf("Iklan                      |    X    |   V   \n\n");

        printf("*(Y untuk MAU / N untuk LEWATI)\n> ");
        char option;
        while(true) {
            option = toupper(scanChar());
            if(option == 'Y') {
                payment(bioUser.username);
                break;
            } else if(option == 'N') {
                mainMenuBasic(bioUser.gender);
                break;
            } else {
                printf("Maaf, opsi tidak ada\n> ");
            }
        }
    } else {
        mainMenuPremium(bioUser.gender);
    }
}

// Modular untuk pembayaran
void payment(char *username) {
    system("cls || clear");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentDate  = tm.tm_mday;
    int currentMonth = tm.tm_mon + 1;
    int currentYear  = tm.tm_year + 1900;

    int randomCode;
    printf(BOLD "Pembayaran\n" BOLD_END);
    printf("---------------\n");
    printf("Total    : Rp 10.000\n");
    printf("Waktu    : %d:%d:%d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("Tanggal  : %d-%d-%d\n", currentDate, currentMonth, currentYear);
    printf("---------------\n");
    printf("*(Y untuk LANJUT / N untuk BATAL)\n> ");

    char option;
    while(true) {
        option = toupper(scanChar());
        if(option == 'Y') {
            break;
        } else if(option == 'N') {
            mainMenuBasic(bioUser.gender);
            break;
        } else {
            printf("Maaf, opsi tidak ada\n> ");
        }
    }

    srand(time(NULL));
    randomCode = (rand() % (999999 - 100000 + 1)) + 100000;
    printf("Kode konfirmasi : %d\n", randomCode);
    printf("Konfirmasi dengan memasukkan angka acak berikut\n> ");
    FILE *premiumFile = fopen("files/premium.txt", "a+");
    while (true) {
        if(scanInteger() == randomCode) {
            fprintf(premiumFile, "%s,%d-%d-%d,3\n", username, currentDate, currentMonth, currentYear);
            break;
        } else {
            printf("Kode salah\n> ");
        }
    }
    fclose(premiumFile);

    if(checkPremium(bioUser.username)) {
        mainMenuPremium(bioUser.gender);
    }
}

// Modular untuk mengidentifikasi akun premium dari user
bool checkPremium(char *username) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentDate  = tm.tm_mday;
    int currentMonth = tm.tm_mon + 1;
    int currentYear  = tm.tm_year + 1900;

    char tempUsername[100];
    int tempDate;
    int tempMonth;
    int tempYear;
    int remainder;

    int found = 0;

    FILE *premiumFile = fopen("files/premium.txt", "r");
    FILE *tempPremiumFile = fopen("files/temp_premium.txt", "w");
    do {
        fscanf(premiumFile, "%99[^,],%d-%d-%d,%d\n", tempUsername, &tempDate, &tempMonth, &tempYear, &remainder);
        if(strcmp(username, tempUsername) == 0) {
            if(differenceDate(tempDate, tempMonth, tempYear, currentDate, currentMonth, currentYear) > 30) {
                continue;
            } else {
                fprintf(tempPremiumFile, "%s,%d-%d-%d,%d\n", tempUsername, tempDate, tempMonth, tempYear, remainder);
                found = 1;
            }
        } else {
            fprintf(tempPremiumFile, "%s,%d-%d-%d,%d\n", tempUsername, tempDate, tempMonth, tempYear, remainder);
        }
    } while(!feof(premiumFile));
    fclose(tempPremiumFile);
    fclose(premiumFile);

    remove("files/premium.txt");
    rename("files/temp_premium.txt", "files/premium.txt");

    if(found == 1) {
        return true;
    } else {
        return false;
    }
}

// Modular untuk menampilkan #KonsultasiBarengTermy
void konsultasiBarengTermy(char *username) {
    system("cls || clear");
    char confirm;
    int option;
    printf(BOLD "#KonsultasiBarengTermy\n" BOLD_END);
    printf("---------------\n");
    printf("#KonsultasiBarengTermy merupakan fitur Termidoc\n");
    printf("yang memungkinkan Anda berkonsultasi langsung\n");
    printf("dengan para ahli.\n\n");
    if(checkConsult(username) == 0) {
        printf("Maaf, sesi konsultasi Anda sudah habis\n");
        printf("*(tekan apapun untuk kembali)");
        getch();
        premium(username);
    } else {
        printf("Apakah Anda yakin? Sesi Anda akan dikurangi\n");
        printf("Sisa sesi konsultasi : %d\n", checkConsult(username));
        printf("*(Y untuk YAKIN / N untuk KEMBALI)\n> ");
        while(true) {
            confirm = toupper(scanChar());
            if(confirm == 'Y') {
                break;
            } else if(confirm == 'N') {
                premium(username);
                break;
            } else {
                printf("Maaf, opsi tidak ada\n> ");
            }
        }

        system("cls || clear");
        printf("Berikut daftar Dokter yang siap membantu Anda : \n");
        printf("[1] dr. Farhan Zubaedi\n");
        printf("[2] dr. Alexandra Clarin Hayes\n");
        printf("[3] dr. Nadia Alaydrus\n");
        printf("[4] dr. Danar Wicaksono,MSc.,SpDV\n");
        printf("---------------\n");
        printf("Mohon masukkan kode pada []\n> ");
        while(true) {
            option = scanInteger();
            if(option == 1) {
                system("start mailto:zubedifarhan@gmail.com?subject=#KonsultasiBarengTermy");
                break;
            } else if(option == 2) {
                system("start mailto:clarinalexandra76@gmail.com?subject=#KonsultasiBarengTermy");
                break;
            } else if(option == 3) {
                system("start mailto:nadialaydrus@gmail.com?subject=#KonsultasiBarengTermy");
                break;
            } else if (option == 4) {
                system("start mailto:dr.danar.wicaksono@gmail.com?subject=#KonsultasiBarengTermy");
                break;
            } else {
                printf("Maaf, opsi tidak ada\n> ");
            }
        }
        updateConsult(username);
        printf("\n*(tekan apapun untuk kembali)");
        getch();
        premium(username);
    }
}

// Modular untuk memperbarui sisa sesi konsultasi
int updateConsult(char *username) {
    char tempUsername[100];
    int tempDate;
    int tempMonth;
    int tempYear;
    int remainder;

    FILE *premiumFile = fopen("files/premium.txt", "r");
    FILE *tempPremiumFile = fopen("files/temp_premium.txt", "w");
    do {
        fscanf(premiumFile, "%99[^,],%d-%d-%d,%d\n", tempUsername, &tempDate, &tempMonth, &tempYear, &remainder);
        if(strcmp(username, tempUsername) == 0) {
            fprintf(tempPremiumFile, "%s,%d-%d-%d,%d\n", tempUsername, tempDate, tempMonth, tempYear, remainder - 1);
        } else {
            fprintf(tempPremiumFile, "%s,%d-%d-%d,%d\n", tempUsername, tempDate, tempMonth, tempYear, remainder);
        }
    } while(!feof(premiumFile));
    fclose(tempPremiumFile);
    fclose(premiumFile);

    remove("files/premium.txt");
    rename("files/temp_premium.txt", "files/premium.txt");
}

// Modular untuk mengidentifikasi sisa sesi konsultasi
int checkConsult(char *username) {
    char tempUsername[100];
    int tempDate;
    int tempMonth;
    int tempYear;
    int remainder;

    FILE *premiumFile = fopen("files/premium.txt", "r");
    do {
        fscanf(premiumFile, "%99[^,],%d-%d-%d,%d\n", tempUsername, &tempDate, &tempMonth, &tempYear, &remainder);
        if(strcmp(username, tempUsername) == 0) {
            break;
        }
    } while(!feof(premiumFile));
    fclose(premiumFile);

    return remainder;
}