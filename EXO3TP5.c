#include <stdio.h>
#define nbreligne 3
#define nbrcolonne 4

int main() {
    int matrice[nbreligne] [nbrcolonne];

    // Remplissage de la matrice
    printf("Entrez les valeurs pour un tableau 3x4 :\n");
    for (int i = 0; i < nbreligne; i++) {
        for (int j = 0; j < nbrcolonne; j++) {
            printf("Saisir l'element de la matrice(%d,%d) ", i+1, j+1);
            scanf("%d", &matrice[i][j]);
        }
    }
printf("Voila le contenu de la matrice :\n");
    // Affichage de la matrice
    for (int i = 0; i < nbreligne; i++)
    {
    for (int j = 0; j < nbrcolonne; j++)
    {
      printf("%d ",matrice[i][j]);
    }
     }
    return 0;
}
