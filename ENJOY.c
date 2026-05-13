#include <stdio.h>



int main()
{
    int x,y,h;
    x=3;
    y=2;
    printf("le contenu de x et y avant permutation:\n");
    printf("x=%d\n",x );
    printf("y=%d\n",y);
    h=x;
    x=y;
    y=h;
    printf("le contenu de x et y apres permutation:\n ");
    printf("x=%d,y=%d\n",x,y);


    return 0;



}




