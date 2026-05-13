
#include <stdio.h>


void procedure(int*entier, float*reel) {
    *entier = 0;
    *reel = 0.0;
}


int main() {
    int a = 5;
    float b = 5.3;

    printf("Avant appel : %d,  %f\n", a, b);
    procedure(&a, &b);
    printf("Apres appel :  %d, %f\n", a, b);

    return 0;
}


