#include<stdio.h>
 int main()
 {




int i=0,a=0,b=0,somme=0;
do
{
  printf("Saisissez l'entier A:\n");
  scanf("%d",&a);

  printf("Saisissez l'entier B:\n");
  scanf("%d",&b );

}
while(a>b);
for(i=a;i<=b;i++)
{
    somme+=i;
}

printf("la somme des nombres entre %d et %d est %d " ,a,b,somme);

 return 0;
 }

