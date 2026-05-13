#include<stdio.h>
int main()
{

  int n=0,i;
  printf("Saisissez un nombre entier:");
  scanf("%d",&n);

  printf("Entiers naturels impairs inferieurs a %d:\n",n);
  for(i=1; i<n; i+=2)
  {
      printf("%d\n",i);
  }

   return 0;




}
















