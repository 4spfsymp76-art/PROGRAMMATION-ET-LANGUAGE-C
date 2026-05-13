#include <stdio.h>

// Définition du sous-programme
int saisirEntier() {
    int n;
    printf("Veuillez saisir un entier : ");
    scanf("%d", &n);
    return n; // On retourne la valeur saisie à la fonction appelante
}

// Exemple d'utilisation
int main() {
    int a, b;

    // Utilisation systématique de la fonction
    a = saisirEntier();
    b = saisirEntier();

    printf("Vous avez saisi : %d et %d\n", a, b);

    return 0;
}

