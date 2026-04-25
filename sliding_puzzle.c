#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#define size 3

typedef struct {
    char isim[30];
    double sure;
} Kayit;

int sayi_tablosu[size][size]=
{   
    {1,2,3},
    {4,5,6},
    {7,8,0 }
};

void renk_ayarla(int renk_kodu) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, renk_kodu);
}


int kazandimi() {
    int dogru_sayi = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
        	
            if (i == size - 1 && j == size - 1) {
                if (sayi_tablosu[i][j] == 0) return 1; 
                else return 0;
            }
            
            
            if (sayi_tablosu[i][j] != dogru_sayi) {
                return 0;
            }
            dogru_sayi++;
        }
    }
    return 1;
}


void imleci_basa_al() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    SetConsoleCursorPosition(hOut, coord);
}


void tablo()
{
    imleci_basa_al(); 
    printf("\n  - PUZZLE OYUNU -\n\n");

    
    printf("  %c%c%c%c%c%c%c%c%c%c%c%c%c\n", 218, 196, 196, 196, 194, 196, 196, 196, 194, 196, 196, 196, 191);

    for(int i = 0; i < size; i++)
    {
        printf("  %c ", 179); 

        for(int j = 0; j < size; j++)
        {
            if (sayi_tablosu[i][j] == 0) {
                printf("  %c ", 179); 
            } 
            else {
               
                int olmasi_gereken = (i * size) + j + 1;
                
                if (sayi_tablosu[i][j] == olmasi_gereken) {
                    renk_ayarla(10); 
                    printf("%d", sayi_tablosu[i][j]);
                    renk_ayarla(7); 
                    printf(" %c ", 179);
                } 
                else {
                    
                    printf("%d %c ", sayi_tablosu[i][j], 179);
                }
            }
        }

        if (i < size - 1)
            printf("\n  %c%c%c%c%c%c%c%c%c%c%c%c%c\n", 195, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 180);
        else
            printf("\n  %c%c%c%c%c%c%c%c%c%c%c%c%c\n", 192, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196, 217);
    }
    
    printf("\n  Cikis icin 'Q' tusuna basiniz.\n");
}

    int bos_satir=2;
    int bos_sutun=2;
void kaydirma(int yeni_satir,int yeni_sutun)
{
    
    if (yeni_satir >= 0 && yeni_satir < size && yeni_sutun >= 0 && yeni_sutun < size) {
            
            int gecici = sayi_tablosu[yeni_satir][yeni_sutun];
            sayi_tablosu[yeni_satir][yeni_sutun] = 0;
            sayi_tablosu[bos_satir][bos_sutun] = gecici;

            bos_satir = yeni_satir;
            bos_sutun = yeni_sutun;
    }
}

void karistir() {
    int son_yon = -1; 
    int i = 0;
    
    while(i < 500) { 
    
        int yon = rand() % 4; 
        
        if ((son_yon == 0 && yon == 1) || (son_yon == 1 && yon == 0) ||
            (son_yon == 2 && yon == 3) || (son_yon == 3 && yon == 2)) {
            continue; 
        }

        switch(yon) {
            case 0: kaydirma(bos_satir - 1, bos_sutun); break;
            case 1: kaydirma(bos_satir + 1, bos_sutun); break;
            case 2: kaydirma(bos_satir, bos_sutun - 1); break;
            case 3: kaydirma(bos_satir, bos_sutun + 1); break;
        }
        
        son_yon = yon;
        i++;
    }
}

void skor(char isim[],double gecen_sure)
{

    FILE *dosya = fopen("skorlar.txt", "a");

    if (dosya != NULL) {
    
        fprintf(dosya, "%s %.2f\n", isim, gecen_sure);
    
        fclose(dosya);
        printf("Skorunuz basariyla kaydedildi!\n");
    }
    else {
        printf("Skor dosyasi acilamadi!\n");
    }
}

void skor_tablosu()
{

    FILE *dosya = fopen("skorlar.txt", "r");

    if (dosya == NULL) {
        printf("Skor tablosu henuz olusturulmamis.\n");
        return; // Dosya yoksa fonksiyondan çık
    }

    Kayit tablo[100];
    int toplam = 0;

    while (fscanf(dosya, "%s %lf", tablo[toplam].isim, &tablo[toplam].sure) != EOF) {
        toplam++;
        if (toplam >= 100) break; // Dizi sınırını aşmamak için
    }
    fclose(dosya);


    for (int i = 0; i < toplam - 1; i++) {
        for (int j = 0; j < toplam - i - 1; j++) {
            if (tablo[j].sure > tablo[j+1].sure) { 
                Kayit gecici = tablo[j];
                tablo[j] = tablo[j+1];
                tablo[j+1] = gecici;
            }
        }
    }

    printf("\n===== EN IYI 5 SURE ======\n");
    for (int i = 0; i < 5 && i < toplam; i++) {
        // %-10s ismi sola yaslar, %.2f süreyi virgülden sonra 2 hane ile gösterir
        printf("%d. %-10s : %.2f saniye\n", i + 1, tablo[i].isim, tablo[i].sure);
    }
    printf("===========================\n\n");
}


int main() {
    char tus;
    char isim[30];

    printf("\nIsminizi giriniz: ");
    gets(isim);

    system("cls");
    
    srand(time(NULL));
    karistir();

    time_t baslangic = time(NULL);

    while (1)
    {
    	imleci_basa_al();	
        tablo();

        if (kazandimi()) {
            printf("\n"); 
            renk_ayarla(10); 
            printf("*** TEBRIKLER! OYUNU KAZANDINIZ! ***\n");
            renk_ayarla(7);  

            time_t bitis = time(NULL);
            double gecen_sure =difftime(bitis, baslangic);

            printf("Cozum %.2f sn surdu.\n",gecen_sure);
            skor(isim,gecen_sure);
            skor_tablosu();

            printf("Cikmak icin bir tusa basin...");
            getch();
            return 0; 
        }

        tus = getch();

        switch (tus) {
            case 'q': case 'Q':
                return 0;

            case 'w': case 'W': case 72: 
                kaydirma(bos_satir + 1, bos_sutun); 
                break;

            case 's': case 'S': case 80: 
                kaydirma(bos_satir - 1, bos_sutun);
                break;

            case 'a': case 'A': case 75: 
                kaydirma(bos_satir, bos_sutun + 1);
                break;

            case 'd': case 'D': case 77: 
                kaydirma(bos_satir, bos_sutun - 1);
                break;
        }
    }
    
    return 0;
}