#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
    int* AllouerTableau(int* Tab , int* n)
    {

        printf("Saisir la taille de votre tableau: \n");
        scanf("%d",n);
        Tab=(int*)calloc (*n,sizeof(int));
        assert(Tab!=NULL);
        return Tab;

    }


int main()
{
int taille;
int* T=AllouerTableau(T,&taille);
printf("Voila le contenu de votre tableau:\n");
for(int i=0;i<taille;i++)
{
    printf("%d \t", T[i]);
}
free(T);



    return 0;
}











#include <stdio.h>
#include <stdlib.h>

// Fonction de comparaison pour qsort
int comparer(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Sous-programme : tri d'une matrice et création d'une nouvelle
int** trier_matrice(int **A, int n, int m) {
    int taille = n * m;
    int *temp = malloc(taille * sizeof(int));
    if (!temp) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        return NULL;
    }

    // Copier les valeurs de la matrice A dans un tableau linéaire
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[k++] = A[i][j];
        }
    }

    // Trier le tableau
    qsort(temp, taille, sizeof(int), comparer);

    // Créer une nouvelle matrice résultat
    int **B = malloc(n * sizeof(int*));
    if (!B) {
        free(temp);
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        B[i] = malloc(m * sizeof(int));
        if (!B[i]) {
            fprintf(stderr, "Erreur d'allocation mémoire.\n");
            // Libérer ce qui a déjà été alloué
            for (int t = 0; t < i; t++) free(B[t]);
            free(B);
            free(temp);
            return NULL;
        }
    }

    // Remplir la matrice B avec les valeurs triées
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            B[i][j] = temp[k++];
        }
    }

    free(temp); // libérer le tableau temporaire
    return B;
}

// Exemple d'utilisation
int main(void) {
    int n = 2, m = 3;
    int **A = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        A[i] = malloc(m * sizeof(int));
    }

    // Remplir la matrice A
    int valeurs[2][3] = {{5, 2, 9}, {1, 7, 3}};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            A[i][j] = valeurs[i][j];

    // Appeler le sous-programme
    int **B = trier_matrice(A, n, m);

    // Afficher la matrice triée
    printf("Matrice triée :\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    // Libérer la mémoire
    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
    }
    free(A);
    free(B);

    return 0;
}
