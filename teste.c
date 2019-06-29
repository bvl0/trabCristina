#include<stdio.h>
#include<stdlib.h>
int main()
{
    char nomeArq[10][100];
    int x;
     for(x=0;x<10;x++)
    {
        printf("informe o nome do %i arquivo : ",x+1);
        fflush(stdin);
        fscanf(nomeArq[x],"%s",stdin);
    }
return(0);
}