#include<stdio.h>
int main ()
{
   char carac1,carac2,aux;
   printf("Saisir un premier caractere:\n");
   scanf("%c",&carac1);
   getchar();
   printf("Saisir un deuxieme caractere:\n");
   scanf("%c",&carac2);


   printf("Avant permutation les deux caracteres sont %c et %c",carac1,carac2);

   aux=carac1;
   carac1=carac2;
   carac2=aux;


   printf("Apres permutation les deux caracteres sont %c et %c",carac1,carac2);



return 0;
}

