#include "headers\general.h"
#include "headers\account.h"
#include "headers\thirty.h"
#include "headers\calculator.h"

extern Biodata bioUser;

void sHeader()
{
    system("cls || clear");
    printf(BOLD "Kalkulator Stress\n" BOLD_END);
    printf("---------------\n");
    printf("Fitur Termidoc yang dapat mengkalkulasi\n");
    printf("tingkat stress Anda\n");
    printf("---------------\n");
    printf("*(tekan apapun untuk melanjutkan)");
    getch();
    stressLevel(stressChecking());
    premium(bioUser.username);
}

int stressChecking()
{
    system("cls || clear");
    FILE *fStresscheck;
    char question[200];
    char optionA[30];
    char optionB[30];
    char optionC[30];
    char optionD[30];
    char optionE[30];
    char ans;
    char score[10];
    int result = 0;

    fStresscheck = fopen ("files/stress-quiz.txt", "r");
    int i = 0;
    do
    {
        fscanf(fStresscheck, "%199[^\n]\n%29[^\n]\n%29[^\n]\n%29[^\n]\n%29[^\n]\n%29[^\n]\n", question, optionA, optionB, optionC, optionD, optionE);
        printf("\n%s\n%s\n%s\n%s\n%s\n%s\n", question, optionA, optionB, optionC, optionD, optionE);
        printf("Masukkan jawaban Anda\n> ");
        while (true)
        {
            ans = toupper(scanChar());
            if(ans == 'A' || ans == 'B' || ans == 'C' || ans == 'D' || ans == 'E') {
                score[i] = ans;
                break;
            } else {
                printf("Maaf, opsi tidak ada\n> ");
            }
        }
        i++; 
    } 
    while (!feof (fStresscheck));
    fclose (fStresscheck);

    for (int j=0; j<i; j++)
    {
        if (score[j] == 'A') 
            result += 1;
        else if (score[j] == 'B')
            result += 2;
        else if (score[j] == 'C')
            result += 3;
        else if (score[j] == 'D')
            result += 4;
        else if (score[j] == 'E')
            result += 5;
    }
    return result;
}

void stressLevel(int stressChecking)
{
    system("cls || clear");
    char level [50];
    int finalDate;
    int finalMonth;
    int finalYear;
    if (stressChecking >= 0 && stressChecking <=13)
    {
        strcpy(level, "Anda ada pada level stress rendah");
    }
    else if (stressChecking >=14 && stressChecking <=30)
    {
        strcpy(level, "Anda ada pada level stress sedang");
    }
    else
    {
        strcpy(level, "Anda ada pada level stress tinggi");
    }

    printf(BOLD "Hasil\n" BOLD_END);
    printf("---------------\n");
    printf("Gender      : " );
    if(bioUser.gender = 'P') printf("Perempuan\n");
    else printf("Laki-Laki\n");
    printf("Umur        : ");
    displayAge(bioUser.birthDate, bioUser.birthMonth, bioUser.birthYear);
    printf("Total skor  : %d pts \n", stressChecking);
    printf("Hasil       : %s \n\n", level);
    printf("*(tekan apapun untuk melanjutkan)");
    getch();
}

// Function-function cek risiko diabetes
void dOpening()
{
    system("cls || clear");
    printf(BOLD "Kalkulator Risiko Diabetes\n" BOLD_END);
    printf("---------------\n");
    printf("Fitur Termidoc yang dapat mengkalkulasi\n");
    printf("tingkat risiko diabetes Anda\n");
    printf("---------------\n");
    printf("*(tekan apapun untuk melanjutkan)");
    getch();
    int res = diabetesCheck();
    dCalculation(res);
    premium(bioUser.username);
}

int diabetesCheck()
{
    system("cls || clear");
    FILE *fdiabetesQuiz;
    char question[200];
    char optionA[30];
    char optionB[30];
    char ans;
    char score[10] = {};
    int result = 0;

    fdiabetesQuiz = fopen ("files/diabetes-quiz.txt","r");
    int i = 0;
    do
    {
        fscanf(fdiabetesQuiz, "%199[^\n]\n%29[^\n]\n%29[^\n]\n", question, optionA, optionB);
        printf("\n%s\n%s\n%s\n", question, optionA, optionB);
        printf("Masukkan jawaban Anda\n> ");
        while (true)
        {
            ans = toupper(scanChar());
            if(ans == 'A' || ans == 'B') {
                score[i] = ans;
                break;
            } else {
                printf("Maaf, opsi tidak ada\n> ");
            }
        }
        i++;
    } 
    while (!feof (fdiabetesQuiz));
    fclose (fdiabetesQuiz);
    for (int j=0; j<i; j++)
    {
        if (score[j] == 'A') 
            result += 1;
        else if (score[j] == 'B')
            result += 0;
    }
    return result;
}

void dCalculation(int diabetesCheck)
{
    system("cls || clear");
    double bmiScore;
    int finalDate;
    int finalMonth;
    int finalYear;
    char risk[50];

    if (bmiScore < 18.5 && bmiScore <= 24.5 && diabetesCheck <= 2 )
    {
        strcpy(risk, "Risiko Anda terkena diabetes rendah");
    }
    else if (bmiScore < 18.5 && bmiScore <= 24.5 && diabetesCheck >= 3 && diabetesCheck <= 4)
    {
        strcpy(risk, "Risiko Anda terkena diabetes sedang");
    }
    else
    {
        strcpy(risk, "Risiko Anda terkena diabetes tinggi");
    }

    printf(BOLD "Hasil\n" BOLD_END);
    printf("---------------\n");
    printf("Gender      : " );
    if(bioUser.gender = 'P') printf("Perempuan\n");
    else printf("Laki-laki\n");
    printf("Umur        : ");
    displayAge(bioUser.birthDate, bioUser.birthMonth, bioUser.birthYear);
    printf("Total skor  : %d pts \n", diabetesCheck);
    printf("Hasil       : %s \n\n", risk);
    printf("*(tekan apapun untuk melanjutkan)");
    getch();
}

//function-function cek risiko serangan jantung
void jStart()
{
    system("cls || clear");
    printf(BOLD "Kalkulator Risiko Jantung\n" BOLD_END);
    printf("---------------\n");
    printf("Fitur Termidoc yang dapat mengkalkulasi\n");
    printf("tingkat risiko penyakit jantung Anda\n");
    printf("---------------\n");
    printf("*(tekan apapun untuk melanjutkan)");
    getch();
    int res = jQuiz();
    calculateRisk(res);
    premium(bioUser.username);
}

int jQuiz()
{
    system("cls || clear");
    FILE *fheartrisk;
    char question[200];
    char optionA[30];
    char optionB[30];
    char ans;
    char score[10] = {};
    int result = 0;

    fheartrisk = fopen ("files/heart-risk-quiz.txt","r");
    int i = 0;
    do
    {
        fscanf(fheartrisk, "%199[^\n]\n%29[^\n]\n%29[^\n]\n", question, optionA, optionB);
        printf("\n%s\n%s\n%s\n", question, optionA, optionB);
        printf("Masukkan jawaban Anda\n> ");
        while (true)
        {
            ans = toupper(scanChar());
            if(ans == 'A' || ans == 'B') {
                score[i] = ans;
                break;
            } else {
                printf("Maaf, opsi tidak ada\n> ");
            }
        }
        i++; 
    } 
    while (!feof (fheartrisk));
    fclose (fheartrisk);
    for (int j=0; j<i; j++)
    {
        if (score[j] =='A') 
            result += 1;
        else if (score[j] =='B')
            result += 0;
    }
    return result;
}

void calculateRisk(int jQuiz)
{
    system("cls || clear");
    double bmiScore;
    int finalDate;
    int finalMonth;
    int finalYear;
    char risk [50];

    if (bmiScore < 18.5 && bmiScore <= 24.5 && jQuiz <= 2 )
    {
        strcpy(risk, "Risiko Anda terkena serangan jantung rendah");
    }
    else if (bmiScore < 18.5 && bmiScore <= 24.5 && jQuiz >= 3 && jQuiz <= 4)
    {
        strcpy(risk, "Risiko Anda terkena serangan jantung sedang");
    }
    else
    {
        strcpy(risk, "Risiko Anda terkena serangan jantung tinggi");
    }

    printf(BOLD "Hasil\n" BOLD_END);
    printf("---------------\n");
    printf("Gender      : " );
    if(bioUser.gender = 'P') printf("Perempuan\n");
    else printf("Laki-laki\n");
    printf("Umur        : ");
    displayAge(bioUser.birthDate, bioUser.birthMonth, bioUser.birthYear);
    printf("Total skor  : %d pts \n", jQuiz);
    printf("Hasil       : %s \n", risk);
    printf("---------------\n");
    printf("*(tekan apapun untuk melanjutkan)");
    getch();
}

//fungsi perhitungan track menstruasi
struct Date
{
    int dd;
    int mm;
    int yy;
};
struct Date date;

void hHistory_f()
{
    system("cls || clear");
    int periode, siklus, nextHaid;
    char tempDate[100];
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Masukkan tanggal haid terakhir Anda\n");
    printf("*(dd-mm-yyyy)\n> ");
    scanDate(tempDate, &date.dd, &date.mm, &date.yy);
    printf("Masukkan siklus haid Anda (21-35)\n> ");
    while (true)
    {
        siklus = scanInteger();
        if(siklus >= 21 && siklus <= 35) {
            break;
        } else {
            printf("Maaf, ada kesalahan\n> ");
        }
    }

    printf("Masukkan periode haid Anda\n> ");
    while (true)
    {
        periode = scanInteger();
        if(periode >= 1 && periode <= 10) {
            break;
        } else {
            printf("Maaf, ada kesalahan\n> ");
        }
    }

    nextHaid = tm.tm_mday + siklus;
    if (date.yy % 400 == 0 || date.yy % 4 == 0)
    {
        if (date.mm == 2)
        {
            if (nextHaid > 29)
            {
                nextHaid = nextHaid - 29;
                bulan = date.mm+1;
            }
            else
            {
                nextHaid = nextHaid;
                bulan = date.mm;
            }
        }
        else if (date.mm == 1 || date.mm == 3 || date.mm == 5 || date.mm == 7 || date.mm == 8 ||
                 date.mm == 10 || date.mm == 12)
        {
            if (nextHaid > 31)
            {
                nextHaid = nextHaid - 31;
                if (date.mm == 12)
                {
                    date.mm = 1;
                    date.yy += 1;
                }
                bulan = date.mm+1;
            }
            else
            {
                nextHaid = nextHaid;
                bulan = date.mm;
            }   
        }
        else
        {
            if (nextHaid > 30)
            {
                nextHaid = nextHaid - 30;
                bulan = date.mm + 1;
            }
            else
            {
                nextHaid = nextHaid;
                bulan = date.mm;
            }    
        }
    }
    else
    {
        if (date.mm == 2)
        {
            if (nextHaid > 28)
                nextHaid = nextHaid - 28;
            else
            {
                nextHaid = nextHaid;
                bulan = date.mm;
            } 
        }
        else if (date.mm == 1 || date.mm == 3 || date.mm == 5 || date.mm == 7 || date.mm == 8 ||
                 date.mm == 10 || date.mm == 12)
        {
            if (nextHaid > 31)
                nextHaid = nextHaid - 31;
            else
                nextHaid = nextHaid;
                bulan = date.mm;
        }
        else
        {
            if (nextHaid > 30)
                nextHaid = nextHaid - 30;
            else
                nextHaid = nextHaid;
                bulan = date.mm;
        }
    }
    hHistory = nextHaid;
}

void ovulation_f()
{
    system("cls || clear");
    int ovulasi;
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);

    ovulasi = tm.tm_mday + 14;
    if (date.yy % 400 == 0 || date.yy % 4 == 0)
    {
        if (date.mm == 2)
        {
            if (ovulasi > 29)
            {
                ovulasi = ovulasi - 29;
                bulan = date.mm + 1;
            }
                
            else
                ovulasi = ovulasi;
                bulan = date.mm;
        }
        else if (date.mm == 1 || date.mm == 3 || date.mm == 5 || date.mm == 7 || date.mm == 8 ||
                 date.mm == 10 || date.mm == 12)
        {
            if (ovulasi > 31)
            {
                ovulasi = ovulasi - 31;
                if (date.mm == 12)
                {
                    date.mm = 1;
                    date.yy += 1;
                }
                bulan = date.mm+1;
            }
            else
            {
                ovulasi = ovulasi;
                bulan = date.mm;
            }
        }
        else
        {
            if (ovulasi > 30)
            {
                ovulasi = ovulasi - 30;
                bulan = date.mm + 1;
            }   
            else {
                ovulasi = ovulasi;
                bulan = date.mm;
            }
        }
    }
    else
    {
        if (date.mm == 2)
        {
            if (ovulasi > 28)
            {
                ovulasi = ovulasi - 28;
                bulan = date.mm +1;
            }
            else
            {   ovulasi = ovulasi;
                bulan = date.mm;
            }
        }
        else if (date.mm == 1 || date.mm == 3 || date.mm == 5 || date.mm == 7 || date.mm == 8 ||
                 date.mm == 10 || date.mm == 12)
        {
            if (ovulasi > 31)
            {
                ovulasi = ovulasi - 31;
                if (date.mm == 12)
                {
                    date.mm = 1;
                    date.yy += 1;
                }
                bulan = date.mm+1;
            }
            else
            {
                ovulasi = ovulasi;
                bulan = date.mm;
            }    
        }
        else
        {
            if (ovulasi > 30)
            {    
                ovulasi = ovulasi - 30;
                bulan = date.mm +1;
            }
            else
            {
                ovulasi = ovulasi;
                bulan = date.mm;
            }
        }
    }
    ovulation = ovulasi;
}

void awalSubur_f()
{
    system("cls || clear");
    int awalSubur;
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);

    awal_subur = tm.tm_mday + 14;
    if (date.yy % 400 == 0 || date.yy % 4 == 0)
    {
        if (date.mm == 2)
        {
            if (awal_subur > 29)
            {
                awal_subur = awal_subur - 29;
                bulan = date.mm + 1;
            }
                
            else
                awal_subur = awal_subur;
                bulan = date.mm;
        }
        else if (date.mm == 1 || date.mm == 3 || date.mm == 5 || date.mm == 7 || date.mm == 8 ||
                 date.mm == 10 || date.mm == 12)
        {
            if (awal_subur > 31)
            {
                awalSubur = awalSubur - 31;
                if (date.mm == 12)
                {
                    date.mm = 1;
                    date.yy += 1;
                }
                bulan = date.mm+1;
            }
            else
            {
                awalSubur = awalSubur;
                bulan = date.mm;
            }
        }
        else
        {
            if (awalSubur > 30)
            {
                awalSubur = awalSubur - 30;
                bulan = date.mm + 1;
            }   
            else
                awalSubur = awalSubur;
                bulan = date.mm;
        }
    }
    else
    {
        if (date.mm == 2)
        {
            if (awalSubur > 28)
            {
                awalSubur = awalSubur - 28;
                bulan = date.mm +1;
            }
            else
            {   awalSubur = awalSubur;
                bulan = date.mm;
            }
        }
        else if (date.mm == 1 || date.mm == 3 || date.mm == 5 || date.mm == 7 || date.mm == 8 ||
                 date.mm == 10 || date.mm == 12)
        {
            if (awalSubur > 31)
            {
                awalSubur = awalSubur - 31;
                if (date.mm == 12)
                {
                    date.mm = 1;
                    date.yy += 1;
                }
                bulan = date.mm+1;
            }
            else
            {
                awalSubur = awalSubur;
                bulan = date.mm;
            }    
        }
        else
        {
            if (awalSubur > 30)
            {    
                awalSubur = awalSubur - 30;
                bulan = date.mm +1;
            }
            else
            {
                awalSubur = awalSubur;
                bulan = date.mm;
            }
        }
    }
    awal_subur = awalSubur;
}

void akhirSubur_f()
{
    system("cls || clear");
    int akhirSubur;
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);

    akhirSubur = tm.tm_mday + 14;
    if (date.yy % 400 == 0 || date.yy % 4 == 0)
    {
        if (date.mm == 2)
        {
            if (akhirSubur > 29)
            {
                akhirSubur = akhirSubur - 29;
                bulan = date.mm + 1;
            }
                
            else
                akhirSubur = akhirSubur;
                bulan = date.mm;
        }
        else if (date.mm == 1 || date.mm == 3 || date.mm == 5 || date.mm == 7 || date.mm == 8 ||
                 date.mm == 10 || date.mm == 12)
        {
            if (akhirSubur > 31)
            {
                akhirSubur = akhirSubur - 31;
                if (date.mm == 12)
                {
                    date.mm = 1;
                    date.yy += 1;
                }
                bulan = date.mm+1;
            }
            else
            {
                akhirSubur = akhirSubur;
                bulan = date.mm;
            }
        }
        else
        {
            if (akhirSubur > 30)
            {
                akhirSubur = akhirSubur - 30;
                bulan = date.mm + 1;
            }   
            else
                akhirSubur = akhirSubur;
                bulan = date.mm;
        }
    }
    else
    {
        if (date.mm == 2)
        {
            if (akhirSubur > 28)
            {
                akhirSubur = akhirSubur - 28;
                bulan = date.mm +1;
            }
            else
            {   akhirSubur = akhirSubur;
                bulan = date.mm;
            }
        }
        else if (date.mm == 1 || date.mm == 3 || date.mm == 5 || date.mm == 7 || date.mm == 8 ||
                 date.mm == 10 || date.mm == 12)
        {
            if (akhirSubur > 31)
            {
                akhirSubur = akhirSubur - 31;
                if (date.mm == 12)
                {
                    date.mm = 1;
                    date.yy += 1;
                }
                bulan = date.mm+1;
            }
            else
            {
                akhirSubur = akhirSubur;
                bulan = date.mm;
            }    
        }
        else
        {
            if (akhirSubur > 30)
            {    
                akhirSubur = akhirSubur - 30;
                bulan = date.mm +1;
            }
            else
            {
                akhirSubur = akhirSubur;
                bulan = date.mm;
            }
        }
    }
    akhir_subur = akhirSubur;
}

void trackResult(int hHistory, int ovulation, int awalSubur, int akhirSubur)
{
    system("cls || clear");
    printf(BOLD "Tracking Menstruasi\n" BOLD_END);
    printf("---------------\n");
    printf("Anda subur pada tanggal  %d-%d-%d hingga tanggal %d-%d-%d\n", awal_subur,bulan,date.yy,akhir_subur,bulan,date.yy);
    printf("Puncak ovulasi Anda terjadi pada tanggal %d-%d-%d\n", ovulation, bulan, date.yy);
    printf("Anda kemungkinan haid kembali pada tanggal " RED "%d-%d-%d" RESET " di bulan berikutnya\n", hHistory, bulan, date.yy);
    printf("---------------\n");
    printf("*(tekan apapun untuk melanjutkan)");
    getch();
}



void mStart()
{
    system("cls || clear");
    printf(BOLD "Tracking Menstruasi\n" BOLD_END);
    printf("---------------\n");
    printf("Fitur Termidoc yang memungkinkan Anda\n");
    printf("untuk melakukan tracking menstruasi\n\n");
    printf("*(tekan apapun untuk melanjutkan)");
    getch();
    hHistory_f();
    ovulation_f();
    awalSubur_f();
    akhirSubur_f();
    trackResult(hHistory, ovulation, awal_subur, akhir_subur);
    premium(bioUser.username);
}