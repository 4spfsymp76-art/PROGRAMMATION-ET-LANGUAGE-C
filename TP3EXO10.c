#include <stdio.h>

int main() {
    int n;
    int somme = 0;
    int compteur = 0;
    float moyenne;

    printf("Saisir des nombres entiers positifs (nombre négatif pour finir) :\n");
    scanf("%d", &n);

    while (n >= 0) {
        somme += n;
        compteur++;
        scanf("%d", &n);
    }

    if (compteur > 0) {
        moyenne = (float)somme / compteur;
        printf("La moyenne des nombres saisis est : %.2f\n", moyenne);
    } else {
        printf("Aucun nombre positif saisi, moyenne impossible.\n");
    }

    return 0;
}

