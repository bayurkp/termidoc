#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

void signIn();
void signUp();
void createUsername();
void createPassword();
bool checkUsername(char*);

// Fungsi untuk masuk atau login
void signIn() {
    printf("Sign In\n");
    printf("Mohon masukkan username untuk akun Anda\n");
    printf("Username : ");
    printf("Mohon masukkan password untuk akun Anda\n");
    printf("Password : ");
    printf("Mohon masukkan password Anda sekali lagi\n");
    printf("Confirm  : ");
}

// Fungsi untuk mendaftar atau sign up
void signUp() {

}

// Fungsi untuk mengecek apakah username ada atau tidak
bool checkUsername(char *username) {
    char *usernameFile; // Variabel untuk menyimpan username dari file
    char *passwordFile; // Variabel untuk menyimpan password dari file
    FILE *fileAccount;
    fileAccount = fopen("account.txt", "r");
    do {
        int read = fscanf(fileAccount, "%[^,],%[^\n]\n", usernameFile, passwordFile);
        if(read == 2) {
            if(strcmp(username, usernameFile) == 0) {
                return false; // Username sudah terpakai
            } else {
                return true; // Username belum terpakai (boleh digunakan)
            }
        }
    } while(!feof(fileAccount));
}


// Fungsi untuk membuat username
void createUsername() {

}

// Fungsi untuk membuat password
void createPassword() {

}

