#include<stdio.h>
int main()
{

  int n=0,i=1;
  printf("Saisissez un nombre entier:\n");
  scanf("%d",&n);
  printf("Les %d premiers entiers naturels impairs sont :\n",n);
  int compteur=0;
  while(compteur<n)
 {
  printf("%d\n",i);
  i=i+2;
  compteur++;
 }

  return 0;

}















