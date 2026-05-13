#include <stdio.h>

// Procédure d'échange
void echange(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main() {
    int a = 18;
    int b = 10;

    printf("Avant echange : a = %d, b = %d\n", a, b);

    // Appel de la procédure
    echange(&a, &b);

    printf("Apres echange : a = %d, b = %d\n", a, b);

    return 0;
}

