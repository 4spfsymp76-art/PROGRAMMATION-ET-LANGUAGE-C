#include <stdio.h>
#define taillephysique 100

int main() {
    int tableau[taillephysique];
    int n;//taille logique
    int max;
    // Demander le nombre d'entiers à insérer
    printf("Saisissez la taille logique de votre tableau ? ");
    scanf("%d", &n);


    // remplissage du tableau
    for (int a = 0; a < n; a++) {
        printf("Entrez l'entier %d : ", a + 1);
        scanf("%d", &tableau[a]);

    }
    printf("Voila le contenu de ton tableau :\n");
    //Affichage du tableau
    for(int a = 0; a < n; a++){
    printf("%d ,",tableau[a]);
    }

    // Rechercher la valeur maximale dans le tableau
    max = tableau[0];
    for (int a = 0; a < n; a++) {
        if (max<tableau[a]) {
            max = tableau[a];
        }
    }

    // Affichage de la valeur maximale dans le tableau
    printf("La valeur maximale dans le tableau est  %d\n", max);
    return 0;
}

