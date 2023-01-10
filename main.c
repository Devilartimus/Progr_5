#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct
{
    char whole[50];
    char frac[50];
}DECIMAL;

void summaraize(DECIMAL a, DECIMAL b)
{
    int wn,fr,fr1,fr2;

    wn=atoi(a.whole)+atoi(b.whole);     //перевод из строки в инт
    fr1=atoi(a.frac);
    fr2=atoi(b.frac);

    if (strlen(a.frac)>strlen(b.frac))
    {
        fr2*=pow(10,(strlen(a.frac)-strlen(b.frac)));
        fr=fr1+fr2;

        if (fr/pow(10,strlen(a.frac))!=0)
        {
            wn+=fr/pow(10,strlen(a.frac));
            fr-=pow(10,strlen(a.frac));
        }
    }else
    {
        if (strlen(a.frac)<strlen(b.frac))
        {
            fr1*=pow(10,(strlen(b.frac)-strlen(a.frac)));
            fr=fr1+fr2;

            if (fr/pow(10,strlen(b.frac))!=0)
            {
                wn+=fr/pow(10,strlen(b.frac));
                fr-=pow(10,strlen(b.frac));
            }
    }else
        {
            fr=fr1+fr2;
        }
    }
    printf("\n\na + b = %i.%i",wn,fr);
}

void substract(DECIMAL a, DECIMAL b)
{
    int wn,fr,fr1,fr2;

    wn=atoi(a.whole)-atoi(b.whole);
    fr1=atoi(a.frac);
    fr2=atoi(b.frac);

    if (strlen(a.frac)>strlen(b.frac))
    {
        fr2*=pow(10,(strlen(a.frac)-strlen(b.frac)));

        if ((atoi(a.whole)<0 && atoi(b.whole)>=0) || (atoi(b.whole)<0 && atoi(a.whole)>=0))
            fr=fr1+fr2;
        else
            fr=abs(fr1-fr2);

        if (fr<0)
        {
            wn-=1;
            fr+=pow(10,strlen(a.frac))-abs(fr2-fr1);
        }
    }else
    {
        if (strlen(a.frac)<strlen(b.frac))
        {
            fr1*=pow(10,(strlen(b.frac)-strlen(a.frac)));

            if ((atoi(a.whole)<0 && atoi(b.whole)>=0) || (atoi(b.whole)<0 && atoi(a.whole)>=0))
                fr=fr1+fr2;
            else
                fr=abs(fr1-fr2);

            if (fr<0)
            {
                wn-=1;
                fr=0;
                fr+=pow(10,strlen(b.frac))-abs(fr1-fr2);
            }
        }else
        {
            if ((atoi(a.whole)<0 && atoi(b.whole)>=0) || (atoi(b.whole)<0 && atoi(a.whole)>=0))
                fr=fr1+fr2;
            else
                fr=abs(fr1-fr2);
        }
    }

    if(wn<0)
    {
        if(fr>=100)
            do
            {
                wn-=1;
                fr-=100;
            }while (fr>=100);
    } else
        if (wn>0)
    {
        if (fr>=100)
            do
            {
                wn++;
                fr-=100;
            } while (fr>=100);
    }
    if (wn==0)
    {
        if ((atoi(a.whole)+pow(10,-1*atoi(a.frac)))<(atoi(b.whole)+pow(10,-1*atoi(b.frac))))
            printf("\n\na - b = -%i.%i",wn,abs(fr));
    }
    else
        printf("\n\na - b = %i.%i",wn,abs(fr));
}

void multiply(DECIMAL a, DECIMAL b)
{
    int wn,fr;

    wn=atoi(a.whole)*atoi(b.whole);
    fr=atoi(a.frac)*atoi(b.frac);
    if (fr >= 100)
    {
        do {
            wn++;
            fr-=100;
        } while (fr >= 100);
    }
    printf("\n\na * b = %i.%i", wn, fr);
}



int main()
{
    DECIMAL a,b; //заполнение структуры
    printf("\nEnter the whole part of the first number: ");
    scanf("%s", a.whole);

    printf("\nEnter the fractional part of the first number [1,99]: ");
    scanf("%s", a.frac);


    printf("\nEnter the whole part of the second number: ");
    scanf("%s", b.whole);

    printf("\nEnter the fractional part of the second number [1,99]: ");
    scanf("%s", b.frac);

    int choose;
    printf ("\nChoose the action: \n[1]-summarize\n[2]-substract\n[3]-multiply\n>> ");
    scanf("%d", &choose);       //выбор вариента действия
    switch (choose)         //непосредственно выбор
    {
        case 1:
        {
            summaraize(a,b);
            break;
        }
    case 2:
        {
            substract(a,b);
            break;
        }
    case 3:
        {
            multiply(a,b);
            break;
        }
    default:
         printf("\nError! Something wrong...\n");
    }


    return 0;
}
