#include<stdio.h>
int main()
{
int i , n=0 , res=1;
printf("Saisissez un nombre entier:\n");
scanf("%d,&n");
for(int i=1;i<=2;i++){
 res=res*n;
}
printf("la valeur de ce nombre au carre est %d",res);







return 0;


}
