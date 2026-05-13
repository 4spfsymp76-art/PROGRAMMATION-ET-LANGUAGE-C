#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_INIT 10

typedef struct {
    char mot[50];
    char definition[200];
    char traduction[200];
} Mot;

Mot *dictionnaire = NULL;
int taille = 0;
int capacite = TAILLE_INIT;

/* ================== OUTILS ================== */
void nettoyer(char *str) {
    str[strcspn(str, "\n")] = 0;
}

int chercherMot(char *mot) {
    for (int i = 0; i < taille; i++) {
        if (strcmp(dictionnaire[i].mot, mot) == 0)
            return i;
    }
    return -1;
}

void redimensionner() {
    capacite *= 2;
    dictionnaire = realloc(dictionnaire, capacite * sizeof(Mot));
}

/* ================== FICHIER ================== */
void chargerDictionnaire() {
    FILE *f = fopen("dict.txt", "r");
    if (!f) return;

    char ligne[500];
    while (fgets(ligne, sizeof(ligne), f)) {
        if (taille >= capacite) redimensionner();

        char *mot = strtok(ligne, ":");
        char *def = strtok(NULL, ":");
        char *trad = strtok(NULL, "\n");

        if (mot && def && trad) {
            strcpy(dictionnaire[taille].mot, mot);
            strcpy(dictionnaire[taille].definition, def);
            strcpy(dictionnaire[taille].traduction, trad);
            taille++;
        }
    }
    fclose(f);
}

void sauvegarder() {
    FILE *f = fopen("dict.txt", "w");
    for (int i = 0; i < taille; i++) {
        fprintf(f, "%s:%s:%s\n",
                dictionnaire[i].mot,
                dictionnaire[i].definition,
                dictionnaire[i].traduction);
    }
    fclose(f);
}

/* ================== FONCTIONS ================== */
void afficherDictionnaire() {
    for (int i = 0; i < taille; i++) {
        printf("\nMot : %s\nDefinition : %s\nTraduction : %s\n",
               dictionnaire[i].mot,
               dictionnaire[i].definition,
               dictionnaire[i].traduction);
    }
}

void ajouterMot() {
    Mot m;
    printf("Mot francais : ");
    fgets(m.mot, 50, stdin);
    nettoyer(m.mot);

    if (chercherMot(m.mot) != -1) {
        printf(" Mot déjà existant !\n");
        return;
    }

    printf("Définition : ");
    fgets(m.definition, 200, stdin);
    nettoyer(m.definition);

    printf("Traduction(s): ");
    fgets(m.traduction, 200, stdin);
    nettoyer(m.traduction);

    if (taille >= capacite) redimensionner();
    dictionnaire[taille++] = m;
}

void supprimerMot() {
    char mot[50];
    printf("Mot à supprimer : ");
    fgets(mot, 50, stdin);
    nettoyer(mot);

    int index = chercherMot(mot);
    if (index == -1) {
        printf("Mot introuvable.\n");
        return;
    }

    for (int i = index; i < taille - 1; i++)
        dictionnaire[i] = dictionnaire[i + 1];

    taille--;
}

void afficherDefinition() {
    char mot[50];
    printf("Mot : ");
    fgets(mot, 50, stdin);
    nettoyer(mot);

    int i = chercherMot(mot);
    if (i != -1)
        printf("Definition : %s\n", dictionnaire[i].definition);
    else
        printf("Mot introuvable.\n");
}

void afficherTraduction() {
    char mot[50];
    printf("Mot : ");
    fgets(mot, 50, stdin);
    nettoyer(mot);

    int i = chercherMot(mot);
    if (i != -1)
        printf("Traduction : %s\n", dictionnaire[i].traduction);
    else
        printf("Mot introuvable.\n");
}

/* ================== BONUS : JEU ================== */
void jeu() {
    if (taille == 0) return;

    int r = rand() % taille;
    char rep[100];

    printf("Traduction de \"%s\" : ", dictionnaire[r].mot);
    fgets(rep, 100, stdin);
    nettoyer(rep);

    if (strstr(dictionnaire[r].traduction, rep))
        printf(" Correct !\n");
    else
        printf(" Faux. Reponse : %s\n", dictionnaire[r].traduction);
}

/* ================== MENU ================== */
int main() {
    dictionnaire = malloc(TAILLE_INIT * sizeof(Mot));
    chargerDictionnaire();

    int choix;
    do {
        printf("\n=== Gestionnaire de dictionnaire bilingue ===\n");
        printf("1. Afficher dictionnaire\n");
        printf("2. Ajouter mot\n");
        printf("3. Supprimer mot\n");
        printf("4. Afficher definition\n");
        printf("5. Afficher traduction\n");
        printf("6. Jeu de traduction\n");
        printf("0. Sauvegarder et quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1: afficherDictionnaire(); break;
            case 2: ajouterMot(); break;
            case 3: supprimerMot(); break;
            case 4: afficherDefinition(); break;
            case 5: afficherTraduction(); break;
            case 6: jeu(); break;
        }
    } while (choix != 0);

    sauvegarder();
    free(dictionnaire);
    return 0;
}

