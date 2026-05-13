
#include <stdio.h>
#define TAILLE_PHYSIQUE 20

void afficher(int tab[TAILLE_PHYSIQUE]) {
    for (int i = 0; i < TAILLE_PHYSIQUE; i++) {
        printf("%d ", tab[i]);
    }

}

int main() {

    int tab[i];


    for (int i = 0; i < 20; i++) {
        tab[i] = 0;
    }

    printf("Affichage du tableau initialise :\n");
    afficherTableau(tab, 20);

    return 0;
}

