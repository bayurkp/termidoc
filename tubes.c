#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

struct profil {
    char username[100];
    char password[100];
    char nama[100];
    int tanggalLahir;
    int bulanLahir;
    int tahunLahir;
    char jenisKelamin;
    float tinggiBadan;
    float beratBadan;
    float skorBMI;
    char kategoriBMI[100];
};

float bmi(float tinggi, float berat){
    float skorBMI;
    skorBMI = berat / pow((tinggi / 100), 2);
    return skorBMI;
}

int main(void) {
    struct profil test;
    printf("Masukkan username : ");
    scanf("%[^\n]", test.username);
    getchar();
    printf("Masukkan password : ");
    scanf("%[^\n]", test.password);
    getchar();

    printf("Masukkan nama : ");
    scanf("%[^\n]", test.nama);
    getchar();
    
    printf("Masukkan tanggal lahir (dd-mm-yy) : ");
    scanf("%d-%d-%d", &test.tanggalLahir, &test.bulanLahir, &test.tahunLahir);
    getchar();
    
    printf("Masukkan jenis kelamin (L/P) : ");
    while (true) {
        scanf("%c", &test.jenisKelamin);
        getchar();
        tolower(test.jenisKelamin);
        if(test.jenisKelamin == 'p' || test.jenisKelamin == 'l') break;
    }

    printf("Masukkan Berat Badan (kg) : ");
    scanf("%f", &test.beratBadan);

    printf("Masukkan tinggi badan (cm) : ");
    scanf("%f", &test.tinggiBadan);

    test.skorBMI = bmi(test.tinggiBadan, test.beratBadan);
    if (test.skorBMI < 18.5) {
        strcpy(test.kategoriBMI, "Kekuarangan Berat Badan");
    } else if (test.skorBMI >= 18.5 && test.skorBMI <= 24.9) {
        strcpy(test.kategoriBMI, "Normal atau Ideal");
    } else if (test.skorBMI > 24.9 && test.skorBMI <= 29.9) {
        strcpy(test.kategoriBMI, "Kelebihan Berat Badan");
    } else {
        strcpy(test.kategoriBMI, "Obesitas");
    }
    
    FILE *fptr = fopen("ini.txt", "a+");
    fprintf(fptr, "Nama : %s\n", test.nama);
    fprintf(fptr, "Hasil Perhitungan BMI : %f\n", test.skorBMI);
    fprintf(fptr, "Kategori : %s\n", test.kategoriBMI);
    fclose(fptr);
    return (0);
}