#include <stdio.h>

// Procédure : calcule quotient et reste
void procedure(int a, int b, int *quotient, int *reste) {//pas de motif sur a et b-->> passage par valeur
    *quotient = a / b;
    *reste = a % b;
}
int fonction(int a, int b,int *q)
{
int reste;
*q=a/b;
return reste=a/b;
}
int main() {
    int a = 10, b = 3;
    int q, r;
    procedure(a,b,&q,&r);
    printf("Le quotient est %d, le reste est %d\n", q, r);
    r=fonction(a,b,&q);
    printf("Le quotient et le reste sont %d et %d\n", q, r);




    return 0;
}

