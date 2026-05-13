#include <stdio.h>


void calculerSommeProduit(int tab[], int n, int *somme, int *produit) {
    *somme = 0;
    *produit = 1;

    for (int i = 0; i < n; i++) {
        *somme += tab[i];//somme=*sommme +tab[i]
        *produit *= tab[i];//*produit=*produit *tab[i]
    }
}


void calculerSommeProduit(int tab[], int n, int *somme, int *produit);

int main() {
    int n;

    printf("Entrez le nombre d'elements du tableau : ");
    scanf("%d", &n);

    int tab[n];  // Déclaration du tableau

    // Saisie des valeurs
    for (int i = 0; i < n; i++) {
        printf("Entrez l'element %d : ", i + 1);
        scanf("%d", &tab[i]);
    }

    int somme, produit;

    // Appel de la procédure
    calculerSommeProduit(tab, n, &somme, &produit);

    // Affichage des résultats
    printf("Somme des elements = %d\n", somme);
    printf("Produit des elements = %d\n", produit);

    return 0;
}

