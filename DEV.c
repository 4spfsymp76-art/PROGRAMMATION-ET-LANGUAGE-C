#include<stdio.h>
int main()
{
  char c=0,cara_Maj, n;
  printf("Saisissez un caractère minuscule:\n");
  scanf("%c",&n);
  if(n>='a'&& n<='z')
  {
      cara_Maj=n-32;
      printf("Le caractère en majuscule c'est %c",cara_Maj);
  }
   else
   {
       printf("Le caractère n'est pas une miniscule:\n");
   }

   return 0;



}




