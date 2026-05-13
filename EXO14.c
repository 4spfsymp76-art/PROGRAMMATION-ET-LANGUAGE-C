#include<stdio.h>
int main()
{
  int n=0,i;
  int res=1;


  printf("Saisissez un nombre entier:");
  scanf("%d",&n);
  for(i=1;i<=5;i++)
  {
      res=res*n;
  }

  printf("Resultat :%d\n",res);


  return 0;



}

