#include <stdio.h>

int main() {
    int n;

    printf("Saisir un nombre entier : ");
    scanf("%d", &n);

    while (n % 2 != 0 || n % 7 != 0) {
        printf("Le nombre doit être multiple de 2 et de 7, ressaisissez : ");
        scanf("%d", &n);
    }

    printf("Bravo, %d est bien multiple de 2 et de 7 !\n", n);

    return 0;
}

