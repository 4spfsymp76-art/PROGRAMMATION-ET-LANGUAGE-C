#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int** AllouerMatrice(int* nbligne,int* nbcolonne)
{
    int** M;
    printf("Saisir le nombre de lignes et de colonnes :\n");
    scanf("%d %d",nbligne,nbcolonne);
    M=(int**)calloc(*nbligne,sizeof(int*));
    for(int i=0;i<*nbligne;i++)
    {
        M[i]=(int*)calloc(*nbcolonne,sizeof(int));
    }
    return M;
}
void Remplissage(int** M,int L,int C)
{
for(int i=0;i<L;i++)
{
    for(int j=0;j<C;j++)
    {
        M[i][j]=rand()%256;
    }
}

}
void AfficheMatrice(int** M,int L,int C)
{
for(int i=0;i<L;i++)
{
    for(int j=0;j<C;j++)
    {
        printf("%d \t",M[i][j]);
    }
}
int** TriMatrice(int**M,int nbligne,int nbcolonne)
int** TabAux=malloc(sizeof(int*)(nbligne*nbcolonne));
int k=0;
for(int i=0;i<nbligne;i++)

{
    for(int j=0;nbcolonne<C;j++)
    {
       TabAux[k]=M[i][j];
       k++;
    }
}

int main()
{
int L,C;
int** Matrice=AllouerMatrice(&L,&C);
Remplissage(Matrice, L, C);
TriMatrice
printf("Voila le contenu de la matrice :\n");
for(int i=0;i<L;i++)
{
    for(int j=0;j<C;j++)
    {
        printf("%d \t",Matrice[i][j]);
    }
    printf("\n");
}

return 0;
}




