#include "account.h"
#include "general.h"

Biodata bioUser;

// Modular untuk masuk atau login
void signIn() {
    char username[100];
    char password[100];
    char tempFullName[100];
    char tempUsername[100];
    char tempPassword[100];
    int  tempBirthDate;
    int  tempBirthMonth;
    int  tempBirthYear;
    char tempGender;
    int  tempHeight;
    int  tempWeight;

    int read; // Variabel return value dari fungsi fscanf

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
        if(checkPassword(username, password)) {
            break;
        } else {
            printf("Password salah\n> ");
        }
    }
    FILE *profileFile = fopen("profile.txt", "r");
    do {
        read = fscanf(profileFile, "%99[^,],%99[^,],%d-%d-%d,%c,%d,%d\n", tempUsername, tempFullName, &tempBirthDate, &tempBirthMonth, &tempBirthYear, &tempGender, &tempHeight, &tempWeight);
        if(read == 8) {
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
        }
    } while(!feof(profileFile));
    fclose(profileFile);
    system("cls || clear");
}

// Modular untuk mendaftar atau sign up
void signUp() {
    char username[100];
    char password[100];
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
    FILE *accountFile = fopen("account.txt", "a+");
    fprintf(accountFile, "%s,%s", username, password);
    fclose(accountFile);
    FILE *profileFile = fopen("profile.txt", "a+");
    fprintf(profileFile, "%s,%s,%d-%d-%d,%c,%d,%d,\n", username, fullName, birthDate, birthMonth, birthYear, gender, height, weight);
    fclose(profileFile);
    system("cls || clear");
    // Melakukan login
    signIn();
}

// Modular untuk mengecek eksistensi username pada account.txt
bool checkUsername(char *username) {
    char tempUsername[100]; // Variabel untuk menyimpan username dari file
    char tempPassword[100]; // Variabel untuk menyimpan password dari file
    bool found;
    FILE *accountFile = fopen("account.txt", "r");
    do {
        int read = fscanf(accountFile, "%99[^,],%99[^\n]\n", tempUsername, tempPassword);
        if(read == 2) {
            if(strcmp(username, tempUsername) == 0) {
                found = true; // Username ada atau sudah digunakan
            } else {
                found = false; // Username tidak ada atau belum digunakan (boleh digunakan)
            }
        }
    } while(!feof(accountFile));
    fclose(accountFile);

    if(found) {
        return true; // Username ada atau sudah digunakan
    } else {
        return false; // Username tidak ada atau belum digunakan (boleh digunakan)
    }
}

// Modular untuk mengecek kesesuaian antara username dan password
bool checkPassword(char *username, char *password) {
    char tempUsername[100]; // Variabel untuk menyimpan username dari file
    char tempPassword[100]; // Variabel untuk menyimpan password dari file
    bool valid;
    FILE *accountFile;
    accountFile = fopen("account.txt", "r");
    do {
        int read = fscanf(accountFile, "%99[^,],%99[^\n]\n", tempUsername, tempPassword);
        if(read == 2) {
            if(strcmp(username, tempUsername) == 0) {
                if(strcmp(password, tempPassword) == 0) {
                    valid = true; // Username dan password sesuai
                } else {
                    valid = false; // Username dan password tidak sesuai
                }
            } else {
                valid = false; // Username tidak ada
            }
        }
    } while(!feof(accountFile));
    fclose(accountFile);    

    if(valid) {
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

    int finalDate;
    int finalMonth;
    int finalYear;
    calculateAge(bioUser.birthDate, bioUser.birthMonth, bioUser.birthYear, &finalDate, &finalMonth, &finalYear);
    printf("Umur     : %d Tahun %d Bulan %d Hari\n", finalYear, finalMonth, finalDate);
    
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
        mainMenu(bioUser.gender);
    } else {
        myProfile();
    }
}