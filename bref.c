#include <stdio.h>
int IncrementationAfficher(int n)
{

 n=n+1;

return n;
}
int main ()
{
    int x=3;
    printf("avant la fonction la valeur de x est:%d\n",x);
    x=IncrementationAfficher(x);
    printf("Apres la fonction, la valeur de x est:%d\n",x);
    return 0;
}
