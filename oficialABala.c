#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct TpAluno
{
    char nome[100];
    float mediaP,mediaF;
};
typedef struct TpAluno tpAluno;

struct DadosAlunos
{
    char nome[100];
    float p1,p2,p3,p4,pf,mediaP,mediaF;
}; 
typedef struct DadosAlunos dadosAlunos;

void iniciaStructDA(dadosAlunos* stru)
{
    int i;
    for(i=0;i<100;i++)
    {
        strcpy(stru[i].nome,NULL);
        stru[i].p1=0;
        stru[i].p2=0;
        stru[i].p3=0;
        stru[i].p4=0;
        stru[i].pf=0;
        stru[i].mediaF=0;
        stru[i].mediaP=0;

    }
}

void iniciaStrutcDf(tpAluno *stru,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        strcpy(stru[n].nome,NULL);
        stru[n].mediaF=0;
        stru[n].mediaP=0;

    } 
}


/* tpAluno* veQuemPassou(dadosAlunos *stru)
{
    int i;
    for()
}*/
float media(dadosAlunos *alunos,int i)
{
    float m1=0,m2=0,m3=0,media=0;
    m1=alunos[i].p1;
    if(alunos[i].p2> alunos[i].p1)
    {
        m2= alunos[i].p2;
    }
    else
    {
        m2= alunos[i].p1;
        m1= alunos[i].p2;
    }
    
    if(alunos[i].p3 > m1 && alunos[i].p3 > m2)
    {
        m3 = alunos[i].p3;
    }
    else if(alunos[i].p3 > m1)
        {
            m3=m2;
            m2 = alunos[i].p3;
        }
        else
        {   
            m3=m2;
            m2= m1;
            m1 = alunos[i].p3;
        }
    
    if(alunos[i].p4 > m1 && alunos[i].p4 > m2 && alunos[i].p4 > m3)
    {
        m1=m2;
        m2=m3;
        m3= alunos[i].p4; 
    }
    else if(alunos[i].p4 > m1 && alunos[i].p4 > m2)
    {
        m1=m2;
        m2 = alunos[i].p4;
    }
        else if (alunos[i].p4 > m1)
        {
            m1 = alunos[i].p4;
        }
  

    media = (m1+m2+m3)/3;
    return media;
}

void leArq(char *nomeArq,dadosAlunos *aluno,int *i)
{
    int x,i2=*i;
    FILE *arquivo;
    arquivo= fopen(nomeArq,"r");
    if(arquivo == NULL)
    printf("Erro, nao foi possivel abrir o arquivo\n");
    else
    {
        for(x=0;x<10;x++)
        {
            fscanf(arquivo,"%s",&aluno[i2].nome);
            fscanf(arquivo," %f %f %f %f %f",&aluno[i2].p1,&aluno[i2].p2,&aluno[i2].p3,&aluno[i2].p4,&aluno[i2].pf);
            
            aluno[i2].mediaP=media(aluno,i2);
            aluno[i2].mediaF=(aluno[i2].mediaP + aluno[i2].pf)/2;
        //printf("%f %i %s\n",aluno[i2].mediaF,i2,aluno[i2].nome);
        i2++;
        }
    *i=i2;
    }
    fclose(arquivo);
}


void veQuemPassou(dadosAlunos *aluno,tpAluno *alunoaprovado,int *i)
{
    int quantAprovados=0,x=0,cont=0;
    
    for(x=0;x<100;x++)
    {
        
        if(aluno[x].mediaF>6)
        {
           
            quantAprovados++;
        }
    
    }
    *i=quantAprovados;
    
    alunoaprovado = realloc(alunoaprovado,quantAprovados*(sizeof(tpAluno)));
    //printf("%i",x);
    for(x=0;x<100;x++)
    {
        if(aluno[x].mediaF>6)
        {
            strcpy(alunoaprovado[cont].nome,aluno[x].nome);
            alunoaprovado[cont].mediaP = aluno[x].mediaP;
            alunoaprovado[cont].mediaF = aluno[x].mediaF;
            cont ++;

        
        }
    
    }



}

void BubbleSortAlfabetico(tpAluno *vetor, int tamanho)
{
   int troca,i;
   tpAluno aux;
   

	do{
		troca=0;//trocou=0, considera que a principio está ordenado
		for(i=0;i<tamanho-1;i++)
		{
            if(strcmp(vetor[i].nome,vetor[i+1].nome)>0)
            {
               /* passa pro auxiliar*/
               strcpy(aux.nome,vetor[i].nome);
               aux.mediaP=vetor[i].mediaP;
               aux.mediaF=vetor[i].mediaF;
               /* passa pra tras*/
               strcpy(vetor[i].nome,vetor[i+1].nome);
               vetor[i].mediaP=vetor[i+1].mediaP;
               vetor[i].mediaF=vetor[i+1].mediaF;
               /* devolve o auxiliar pra frente*/
               strcpy(vetor[i+1].nome,aux.nome);
               vetor[i+1].mediaP=aux.mediaP;
               vetor[i+1].mediaF=aux.mediaF;
            
                troca =1;
                
            }
        }
		tamanho=tamanho-1;
	}
    while(troca);

}
void printaSaida(tpAluno *vetor,int quant)
{
    int x=0,y;

    
    FILE *saida1;
    if(quant == 0)
    printf("nao foram geradas nenhuma turma de PA devido a falta de alunos aprovados em PB");
    
    if(quant >= 1&& quant <=10)
    {
        
        saida1=fopen("pa1.txt","a");
        for(x=0;x<quant;x++)
        {
            fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
        }
    fclose(saida1);
    }

    if(quant >10&& quant <=20)
    {
        
        saida1=fopen("pa1.txt","a");

        for(x=0;x<10;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa2.txt","a");
        
        for(x=10;x<quant;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
    }

    if(quant >20&& quant <=30)
    {
        
        saida1=fopen("pa1.txt","a");

        for(x=0;x<10;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa2.txt","a");
        
        for(x=10;x<20;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa3.txt","a");
        
        for(x=20;x<quant;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
    
    }

    if(quant >30&& quant <=40)
    {
        
        saida1=fopen("pa1.txt","a");

        for(x=0;x<10;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa2.txt","a");
        
        for(x=10;x<20;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa3.txt","a");
        
        for(x=20;x<30;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa4.txt","a");
        
        for(x=30;x<quant;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
    
    }

    if(quant >40&& quant <=50)
    {
        
        saida1=fopen("pa1.txt","a");

        for(x=0;x<10;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa2.txt","a");
        
        for(x=10;x<20;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa3.txt","a");
        
        for(x=20;x<30;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
         saida1=fopen("pa4.txt","a");
        for(x=30;x<40;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa5.txt","a");
        for(x=40;x<quant;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
    }

    if(quant >50&& quant <=60)
    {
        
        saida1=fopen("pa1.txt","a");

        for(x=0;x<10;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa2.txt","a");
        
        for(x=10;x<20;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa3.txt","a");
        
        for(x=20;x<30;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
         saida1=fopen("pa4.txt","a");
        for(x=30;x<40;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa5.txt","a");
        for(x=40;x<50;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa6.txt","a");
        for(x=50;x<quant;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
    }
    
    if(quant >60&& quant <=70)
    {
        
        saida1=fopen("pa1.txt","a");

        for(x=0;x<10;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa2.txt","a");
        
        for(x=10;x<20;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa3.txt","a");
        
        for(x=20;x<30;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
         saida1=fopen("pa4.txt","a");
        for(x=30;x<40;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa5.txt","a");
        for(x=40;x<50;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa6.txt","a");
        for(x=50;x<60;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa7.txt","a");
        for(x=60;x<quant;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
    }

    if(quant >70&& quant <=80)
    {
        
        saida1=fopen("pa1.txt","a");

        for(x=0;x<10;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa2.txt","a");
        
        for(x=10;x<20;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa3.txt","a");
        
        for(x=20;x<30;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
         saida1=fopen("pa4.txt","a");
        for(x=30;x<40;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa5.txt","a");
        for(x=40;x<50;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa6.txt","a");
        for(x=50;x<60;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa7.txt","a");
        for(x=60;x<70;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa8.txt","a");
        for(x=70;x<quant;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
    
    }

    if(quant >80&& quant <=90)
    {
        
        saida1=fopen("pa1.txt","a");

        for(x=0;x<10;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa2.txt","a");
        
        for(x=10;x<20;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa3.txt","a");
        
        for(x=20;x<30;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
         saida1=fopen("pa4.txt","a");
        for(x=30;x<40;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa5.txt","a");
        for(x=40;x<50;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa6.txt","a");
        for(x=50;x<60;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa7.txt","a");
        for(x=60;x<70;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa8.txt","a");
        for(x=70;x<80;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa9.txt","a");
        for(x=80;x<quant;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
    
    }
    if(quant >90&& quant <=100)
    {
        
        saida1=fopen("pa1.txt","a");

        for(x=0;x<10;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa2.txt","a");
        
        for(x=10;x<20;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa3.txt","a");
        
        for(x=20;x<30;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
         saida1=fopen("pa4.txt","a");
        for(x=30;x<40;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa5.txt","a");
        for(x=40;x<50;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa6.txt","a");
        for(x=50;x<60;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa7.txt","a");
        for(x=60;x<70;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa8.txt","a");
        for(x=70;x<80;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa9.txt","a");
        for(x=80;x<90;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
        saida1=fopen("pa10.txt","a");
        for(x=90;x<quant;x++)
        {
           fprintf(saida1,"%s \n media parcial : %f  , media final : %f \n",vetor[x].nome,vetor[x].mediaP,vetor[x].mediaF);
           
        }
        fclose(saida1);
    
    }

}
void bolsistas(tpAluno *vetor,int tamanho)
{
    int troca,i,cont=0;
    tpAluno aux;
    
    do
    {
        troca = 0;
        for(i=0;i<tamanho-1;i++)
        {
            if(vetor[i].mediaF< vetor[i+1].mediaF)
            {
                /* passa pro auxiliar*/
                strcpy(aux.nome,vetor[i].nome);
                aux.mediaP=vetor[i].mediaP;
                aux.mediaF=vetor[i].mediaF;
                /* passa pra tras*/
                strcpy(vetor[i].nome,vetor[i+1].nome);
                vetor[i].mediaP=vetor[i+1].mediaP;
                vetor[i].mediaF=vetor[i+1].mediaF;
                /* devolve o auxiliar pra frente*/
                strcpy(vetor[i+1].nome,aux.nome);
                vetor[i+1].mediaP=aux.mediaP;
                vetor[i+1].mediaF=aux.mediaF;
                troca=1;
            }              
        }
        tamanho=tamanho-1;
    } 
    while(troca!=0);
  
    i=0;
    do{
        if(vetor[i].mediaF >= 9.5)
        {
            printf("\n %s \n media final : %f\n",vetor[i].nome,vetor[i].mediaF);
            cont++;
        }
    i++;
    }
    while(cont<5 && i <= 100);
    
    if(cont == 0){
        puts("nenhum   aluno aprovado de PB alcancou Media Final ≥ 9,5");
    }
    if (cont==5 && vetor[i].mediaF == vetor[i+1].mediaF)
    {
       printf("%s \n media final : %f",vetor[i].nome,vetor[i].mediaF);
    }
}


int main()
{
    int x,i=0,quantAprovados=0;
    
    char nomeArq[10][100],nomeArqS[10][100];
    dadosAlunos *aluno;
    tpAluno *alunoaprovado;

    /*tirar depois */
    FILE *entradas;
    entradas=fopen("entradas.txt","r");
    
    aluno =malloc(100*(sizeof(dadosAlunos)));
    alunoaprovado =malloc(100*(sizeof(tpAluno)));
    /* iniciaStructDA(aluno);/*

    /*fazer chamar as funções pra um arquivo e depois rodar um for pra todos */

    /*le o nome dos arquivos */
    for(x=0;x<10;x++)
    {
        printf("informe o nome do %i arquivo : ",x+1);
        fflush(stdin);
        fscanf(entradas,"%s",nomeArq[x]);
    }
    
    /*le as infos dos arquivos */
    for(x=0;x<10;x++)
    {
        leArq(nomeArq[x],aluno,&i);
    }
    
    /*ve quem passou */
    veQuemPassou(aluno,alunoaprovado,&quantAprovados);
    

    
    /*ordena o vetor dos que passaram */
    BubbleSortAlfabetico(alunoaprovado,quantAprovados);
    /*cria os arquivos usando o tamanho do vetor dos passantes */
    printaSaida(alunoaprovado,quantAprovados);
    /*pega os 5 primeiros */
    bolsistas(alunoaprovado,quantAprovados);
    return(0);
}