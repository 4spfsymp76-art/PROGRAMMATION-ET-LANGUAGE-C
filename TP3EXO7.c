#include <stdio.h>

int main() {
    int nombreClasses, nombreEleves, somme = 0;

    printf("Entrez le nombre de classes ouvertes : ");
    scanf("%d", &nombreClasses);

    for (int i = 1; i <= nombreClasses; i++) {
        printf("Entrez le nombre d'eleves dans la classe %d : ", i);
        scanf("%d", &nombreEleves);
        somme += nombreEleves;
    }

    printf("Le nombre total d'eleves dans l'ecole est : %d\n", somme);

    return 0;
}

