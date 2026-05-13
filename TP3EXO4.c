#include <stdio.h>
#include <stdbool.h>

// Définition des macros pour les tarifs
#define TARIF_ENFANT 4
#define TARIF_JEUNE 6
#define TARIF_SENIOR 6
#define TARIF_PLEIN 9

// Définition des macros pour les bornes d'âge
#define AGE_ENFANT_MAX 12
#define AGE_JEUNE_MIN 12
#define AGE_JEUNE_MAX 17
#define AGE_ETUDIANT_MAX 27
#define AGE_SENIOR_MIN 65

int calculerTarif(int age, bool estEtudiant) {
    if (age < AGE_ENFANT_MAX) {
        return TARIF_ENFANT;
    } else if ((age >= AGE_JEUNE_MIN && age <= AGE_JEUNE_MAX)
               || (estEtudiant && age < AGE_ETUDIANT_MAX)) {
        return TARIF_JEUNE;
    } else if (age >= AGE_SENIOR_MIN) {
        return TARIF_SENIOR;
    } else {
        return TARIF_PLEIN;
    }
}

int main() {
    int age;
    char reponse;
    bool estEtudiant;

    printf("Entrez votre âge : ");
    scanf("%d", &age);

    printf("Êtes-vous étudiant (o/n) ? ");
    scanf(" %c", &reponse);
    estEtudiant = (reponse == 'o' || reponse == 'O');

    int prix = calculerTarif(age, estEtudiant);
    printf("Le prix de votre billet est : %d €\n", prix);

    return 0;
}
