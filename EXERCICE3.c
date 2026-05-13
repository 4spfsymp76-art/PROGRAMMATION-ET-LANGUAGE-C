#include<stdio.h>
int main(void)
{
   char carac1,carac2,aux;
   printf("Saisissez le premier caractere:\n"  );
   scanf("%c",&carac1);
   getchar();
   printf("Saisissez le deuxieme caractere:\n");
   scanf("%c",&carac2);


   printf ("avant permutation les deux caracteres sont %c et %c" ,carac1,carac2);

   aux=carac1;
   carac1=carac2;
   carac2=aux;

   printf("Apres permutation les deux caracteres sont %c et %c" ,carac1,carac2 );








return 0;
}
