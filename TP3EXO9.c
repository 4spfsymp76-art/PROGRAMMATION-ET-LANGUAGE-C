#include <stdio.h>

int main() {
    int pierres, etages = 0, besoin = 1;

    printf("Entrez le nombre de pierres disponibles : ");
    scanf("%d", &pierres);

    while (pierres >= besoin) {
        pierres -= besoin;   // on utilise les pierres pour l'étage courant
        etages++;            // on a construit un étage
        besoin++;            // l'étage suivant demandera une pierre de plus
    }

    printf("Nombre d'étages construits : %d\n", etages);

    return 0;
}
