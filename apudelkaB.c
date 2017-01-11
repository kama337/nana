#include <stdio.h>
#include <stdlib.h>

struct pudelko
{
    char nazwa;
    double h;
    double dl;
    double sz;
};
void porownaj(struct pudelko *wsk, int ile, int tab[][2]);
void wczytaj_dane(struct pudelko *wsk, int ile);
int poLICZ(struct pudelko *wsk, int ile);

int main()
{
    int ilosc, ile_parara, i =0;
    struct pudelko *wsk;
    int* *tab;
    printf("==PUDELKA==\n");
    printf("Podaj ile pudelek: ");
    scanf("%d",&ilosc);
    wsk = (struct pudelko *)malloc(sizeof(struct pudelko)*ilosc);
    wczytaj_dane(wsk, ilosc);
    porownaj(wsk, ilosc, tab);
    ile_parara = poLICZ(wsk, ilosc);
    printf("\n%d", ile_parara);
    tab = (int* *)malloc(ile_parara*sizeof(int*));

    for (i; i<ile_parara; i++)
    {
        printf("%d %d", tab, tab+1);
    }

    return 0;


}

void wczytaj_dane(struct pudelko *wsk, int ile)
{
    int i;
    for (i=0; i<ile; i++)
    {
         printf("Wpisz nazwe: ");
         scanf("%s", &(wsk+i)->nazwa);
         printf("Wpisz wysokosc: ");
         scanf("%lf", &(wsk+i)->h);
         printf("Wpisz szerokosc: ");
         scanf("%lf", &(wsk+i)->sz);
         printf("Wpisz dlugosc: ");
         scanf("%lf", &(wsk+i)->dl);
    }
}

void porownaj(struct pudelko *wsk, int ile, int tab[][2])
{
    int i,j, licznika = 0;
    for (i=0; i<ile; i++)
    {
        for (j=i; j<ile; j++)
        {
            if (((wsk+i)->h < (wsk+j)->h) && ((wsk+i)->dl < (wsk+j)->dl) && ((wsk+i)->sz < (wsk+j)->sz))
                {
                printf("%c C %c \n", (wsk+i)->nazwa, (wsk+j)->nazwa);
                tab[licznika][0] = (wsk+i)->nazwa;
                tab[licznika][1] = (wsk+j)->nazwa;
                licznika++;
                }
            if (((wsk+i)->h > (wsk+j)->h) && ((wsk+i)->dl > (wsk+j)->dl) && ((wsk+i)->sz > (wsk+j)->sz))
                {
                printf("%c C %c \n", (wsk+j)->nazwa, (wsk+i)->nazwa);
                tab[licznika][0] = (wsk+j)->nazwa;
                tab[licznika][1] = (wsk+i)->nazwa;
                licznika++;
                }
        }
    }

}

int poLICZ(struct pudelko *wsk, int ile)
{
    int i,j, yy = 0;
    for (i=0; i<ile; i++)
    {
        for (j=i; j<ile; j++)
        {
            if (((wsk+i)->h < (wsk+j)->h) && ((wsk+i)->dl < (wsk+j)->dl) && ((wsk+i)->sz < (wsk+j)->sz))
                yy++;
            if (((wsk+i)->h > (wsk+j)->h) && ((wsk+i)->dl > (wsk+j)->dl) && ((wsk+i)->sz > (wsk+j)->sz))
                yy++;

        }
    }
    return yy;
}
