#include <stdio.h>
int main() {
    int n=0,y=10;
    printf("Saisissez un entier :\n");
    scanf("%d",&n);
    if(n % 3 ==0 && n>y)
    {
        printf("Le nombre est un multiple de 3 et il est superieur a 10");

    }

    else if(n % 3 == 0 && n<y)
    {
        printf("le nombre est un multiple de 3 et il est inferieur a 10");
    }

    else if(n % 3 != 0 && n>y)
    {
        printf("Le nombre n'est pas multiple de 3 et il est superieur a 10");
    }
    else if (n % 3 != 0 && n==y)
    {
        printf("Le nombre n'est pas un multiple de 3 mais il est egal a 10");
    }

    else
    {
        printf("Le nombre n'est pas un multiple de 3 et il est inferieur a 10");
    }


    return 0;
}

