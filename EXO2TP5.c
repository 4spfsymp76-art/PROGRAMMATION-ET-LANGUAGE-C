#include <stdio.h>

int main() {
    int tableau[100];
    int n, i;
    int max;

    // Demander le nombre d'entiers
    printf("Combien d'entiers voulez-vous inserer (max 100) ? ");
    scanf("%d", &n);

    // Vérification de la limite
    if (n < 1 || n > 100) {
        printf("Nombre invalide. Veuillez entrer un nombre entre 1 et 100.\n");
        return 1;
    }

    // Saisie des entiers
    for (i = 0; i < n; i++) {
        printf("Entrez l'entier %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }

    // Recherche du maximum
    max = tableau[0];
    for (i = 1; i < n; i++) {
        if (tableau[i] > max) {
            max = tableau[i];
        }
    }

    // Affichage du plus grand entier
    printf("Le plus grand entier du tableau est : %d\n", max);

    return 0;
}

