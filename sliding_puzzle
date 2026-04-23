#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define size 3
int sayi_tablosu[size][size]=
{   
    {1,2,3},
    {4,0,5},
    {6,7,8 }
};

void tablo()

{
    printf("-PUZZLE OYUNU-\n");
    printf("-------------\n");

    for(int i=0;i<size;i++)
    {
        printf("| ");

        for(int j=0;j<size;j++)
        {
            if (sayi_tablosu[i][j] == 0)
                printf("  | ");
            else
                printf("%d | ", sayi_tablosu[i][j]);
        }
        printf("\n-------------\n");
    }
}

    int bos_satir=1;
    int bos_sutun=1;
void kaydirma(int yeni_satir,int yeni_sutun)
{
    
    if (yeni_satir >= 0 && yeni_satir < size && yeni_sutun >= 0 && yeni_sutun < size) {
            
            int gecici = sayi_tablosu[yeni_satir][yeni_sutun];
            sayi_tablosu[yeni_satir][yeni_sutun] = 0;
            sayi_tablosu[bos_satir][bos_sutun] = gecici;

            // Boşluğun yeni yerini güncelle
            bos_satir = yeni_satir;
            bos_sutun = yeni_sutun;
    }
}

int main() {
    char tus;

    while (1)
    {
        tablo();

        tus = getch();

        switch (tus) {
            case 's':
                kaydirma(bos_satir - 1, bos_sutun);
                break;
            case 'w':
                kaydirma(bos_satir + 1, bos_sutun);
                break;
            case 'd':
                kaydirma(bos_satir, bos_sutun - 1);
                break;
            case 'a':
                kaydirma(bos_satir, bos_sutun + 1);
                break;
        }
    }

    return 0;
}
