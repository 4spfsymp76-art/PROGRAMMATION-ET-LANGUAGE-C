#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAILLE_MOT 64
#define TAILLE_DEFINITION 256
#define NOM_FICHIER "dictionnaire.txt"

// ===================== Structures =====================

typedef struct {
    char mot[TAILLE_MOT];
    char definition[TAILLE_DEFINITION];
    char **traductions;   // tableau dynamique de traductions
    int nbTraductions;
    int capaciteTraductions;
} Entree;

typedef struct {
    Entree *entrees;
    int taille;
    int capacite;
} Dictionnaire;

// ===================== Utilitaires chaîne =====================

void enlever_retour_ligne(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}

void vider_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// ===================== Gestion des traductions =====================

void init_traductions(Entree *e) {
    e->traductions = NULL;
    e->nbTraductions = 0;
    e->capaciteTraductions = 0;
}

int agrandir_traductions(Entree *e) {
    int nouvelleCapacite = (e->capaciteTraductions == 0) ? 2 : e->capaciteTraductions * 2;
    char **nv = realloc(e->traductions, nouvelleCapacite * sizeof(char *));
    if (nv == NULL) {
        return 0; // échec
    }
    e->traductions = nv;
    e->capaciteTraductions = nouvelleCapacite;
    return 1;
}

int ajouter_traduction(Entree *e, const char *traduction) {
    if (e->capaciteTraductions == 0 || e->nbTraductions >= e->capaciteTraductions) {
        if (!agrandir_traductions(e)) {
            return 0;
        }
    }
    e->traductions[e->nbTraductions] = malloc(strlen(traduction) + 1);
    if (e->traductions[e->nbTraductions] == NULL) {
        return 0;
    }
    strcpy(e->traductions[e->nbTraductions], traduction);
    e->nbTraductions++;
    return 1;
}

void liberer_traductions(Entree *e) {
    for (int i = 0; i < e->nbTraductions; i++) {
        free(e->traductions[i]);
    }
    free(e->traductions);
    e->traductions = NULL;
    e->nbTraductions = 0;
    e->capaciteTraductions = 0;
}

// ===================== Gestion du dictionnaire =====================

void init_dictionnaire(Dictionnaire *d) {
    d->capacite = 10;
    d->taille = 0;
    d->entrees = malloc(d->capacite * sizeof(Entree));
    if (d->entrees == NULL) {
        printf("Erreur d'allocation mémoire pour le dictionnaire.\n");
        exit(EXIT_FAILURE);
    }
}

void liberer_dictionnaire(Dictionnaire *d) {
    for (int i = 0; i < d->taille; i++) {
        liberer_traductions(&d->entrees[i]);
    }
    free(d->entrees);
    d->entrees = NULL;
    d->taille = 0;
    d->capacite = 0;
}

int agrandir_dictionnaire(Dictionnaire *d) {
    int nouvelleCapacite = d->capacite * 2;
    Entree *nv = realloc(d->entrees, nouvelleCapacite * sizeof(Entree));
    if (nv == NULL) {
        return 0;
    }
    d->entrees = nv;
    d->capacite = nouvelleCapacite;
    return 1;
}

// retourne index ou -1 si non trouvé
int chercher_mot(const Dictionnaire *d, const char *mot) {
    for (int i = 0; i < d->taille; i++) {
        if (strcmp(d->entrees[i].mot, mot) == 0) {
            return i;
        }
    }
    return -1;
}

// ===================== Fonctions de menu =====================

void afficher_dictionnaire(const Dictionnaire *d) {
    if (d->taille == 0) {
        printf("Le dictionnaire est vide.\n");
        return;
    }
    for (int i = 0; i < d->taille; i++) {
        Entree *e = &d->entrees[i];
        printf("\nMot : %s\n", e->mot);
        printf("Definition : %s\n", e->definition);
        printf("Traductions : ");
        if (e->nbTraductions == 0) {
            printf("(aucune)\n");
        } else {
            for (int j = 0; j < e->nbTraductions; j++) {
                printf("%s", e->traductions[j]);
                if (j < e->nbTraductions - 1) printf(", ");
            }
            printf("\n");
        }
    }
    printf("\n");
}

void ajouter_mot(Dictionnaire *d) {
    char mot[TAILLE_MOT];
    char definition[TAILLE_DEFINITION];
    char buffer[TAILLE_MOT];
    int nbTrads = 0;

    printf("Entrez le mot en francais : ");
    if (fgets(mot, sizeof(mot), stdin) == NULL) return;
    enlever_retour_ligne(mot);

    if (strlen(mot) == 0) {
        printf("Mot vide, annulation.\n");
        return;
    }

    // Prévention des doublons
    if (chercher_mot(d, mot) != -1) {
        printf("Ce mot existe deja dans le dictionnaire.\n");
        return;
    }

    printf("Entrez la definition : ");
    if (fgets(definition, sizeof(definition), stdin) == NULL) return;
    enlever_retour_ligne(definition);

    if (d->taille >= d->capacite) {
        if (!agrandir_dictionnaire(d)) {
            printf("Erreur : impossible d'agrandir le dictionnaire.\n");
            return;
        }
    }

    Entree *e = &d->entrees[d->taille];
    strncpy(e->mot, mot, TAILLE_MOT - 1);
    e->mot[TAILLE_MOT - 1] = '\0';
    strncpy(e->definition, definition, TAILLE_DEFINITION - 1);
    e->definition[TAILLE_DEFINITION - 1] = '\0';
    init_traductions(e);

    printf("Combien de traductions voulez-vous ajouter pour ce mot ? ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return;
    nbTrads = atoi(buffer);

    for (int i = 0; i < nbTrads; i++) {
        char trad[TAILLE_MOT];
        printf("Traduction %d : ", i + 1);
        if (fgets(trad, sizeof(trad), stdin) == NULL) break;
        enlever_retour_ligne(trad);
        if (strlen(trad) == 0) {
            printf("Traduction vide ignoree.\n");
            continue;
        }
        if (!ajouter_traduction(e, trad)) {
            printf("Erreur d'allocation pour la traduction.\n");
            break;
        }
    }

    d->taille++;
    printf("Mot ajoute avec succes.\n");
}

void supprimer_mot(Dictionnaire *d) {
    char mot[TAILLE_MOT];
    printf("Entrez le mot a supprimer : ");
    if (fgets(mot, sizeof(mot), stdin) == NULL) return;
    enlever_retour_ligne(mot);

    int index = chercher_mot(d, mot);
    if (index == -1) {
        printf("Mot introuvable.\n");
        return;
    }

    liberer_traductions(&d->entrees[index]);

    // Décaler les éléments suivants
    for (int i = index; i < d->taille - 1; i++) {
        d->entrees[i] = d->entrees[i + 1];
    }
    d->taille--;

    printf("Mot supprime avec succes.\n");
}

void afficher_definition(const Dictionnaire *d) {
    char mot[TAILLE_MOT];
    printf("Entrez le mot : ");
    if (fgets(mot, sizeof(mot), stdin) == NULL) return;
    enlever_retour_ligne(mot);

    int index = chercher_mot(d, mot);
    if (index == -1) {
        printf("Mot introuvable.\n");
        return;
    }
    printf("Definition de '%s' : %s\n", d->entrees[index].mot, d->entrees[index].definition);
}

void afficher_traductions(const Dictionnaire *d) {
    char mot[TAILLE_MOT];
    printf("Entrez le mot : ");
    if (fgets(mot, sizeof(mot), stdin) == NULL) return;
    enlever_retour_ligne(mot);

    int index = chercher_mot(d, mot);
    if (index == -1) {
        printf("Mot introuvable.\n");
        return;
    }

    Entree *e = &d->entrees[index];
    printf("Traductions de '%s' : ", e->mot);
    if (e->nbTraductions == 0) {
        printf("(aucune)\n");
    } else {
        for (int i = 0; i < e->nbTraductions; i++) {
            printf("%s", e->traductions[i]);
            if (i < e->nbTraductions - 1) printf(", ");
        }
        printf("\n");
    }
}

// ===================== Sauvegarde / Chargement =====================
// Format texte simple :
// nb_entrees
// mot
// definition
// nb_traductions
// trad1
// trad2
// ...

int sauvegarder_dictionnaire(const Dictionnaire *d, const char *nomFichier) {
    FILE *f = fopen(nomFichier, "w");
    if (!f) {
        perror("Erreur d'ouverture du fichier de sauvegarde");
        return 0;
    }

    fprintf(f, "%d\n", d->taille);
    for (int i = 0; i < d->taille; i++) {
        Entree *e = &d->entrees[i];
        fprintf(f, "%s\n", e->mot);
        fprintf(f, "%s\n", e->definition);
        fprintf(f, "%d\n", e->nbTraductions);
        for (int j = 0; j < e->nbTraductions; j++) {
            fprintf(f, "%s\n", e->traductions[j]);
        }
    }

    fclose(f);
    return 1;
}

int charger_dictionnaire(Dictionnaire *d, const char *nomFichier) {
    FILE *f = fopen(nomFichier, "r");
    if (!f) {
        // Pas grave si le fichier n'existe pas encore
        return 0;
    }

    int nbEntrees = 0;
    if (fscanf(f, "%d\n", &nbEntrees) != 1) {
        fclose(f);
        return 0;
    }

    for (int i = 0; i < nbEntrees; i++) {
        char mot[TAILLE_MOT];
        char definition[TAILLE_DEFINITION];
        int nbTrads = 0;

        if (!fgets(mot, sizeof(mot), f)) break;
        enlever_retour_ligne(mot);
        if (!fgets(definition, sizeof(definition), f)) break;
        enlever_retour_ligne(definition);
        if (fscanf(f, "%d\n", &nbTrads) != 1) break;

        if (d->taille >= d->capacite) {
            if (!agrandir_dictionnaire(d)) {
                printf("Erreur : memoire insuffisante lors du chargement.\n");
                fclose(f);
                return 0;
            }
        }

        Entree *e = &d->entrees[d->taille];
        strncpy(e->mot, mot, TAILLE_MOT - 1);
        e->mot[TAILLE_MOT - 1] = '\0';
        strncpy(e->definition, definition, TAILLE_DEFINITION - 1);
        e->definition[TAILLE_DEFINITION - 1] = '\0';
        init_traductions(e);

        for (int j = 0; j < nbTrads; j++) {
            char trad[TAILLE_MOT];
            if (!fgets(trad, sizeof(trad), f)) break;
            enlever_retour_ligne(trad);
            if (strlen(trad) == 0) continue;
            if (!ajouter_traduction(e, trad)) {
                printf("Erreur d'allocation lors du chargement d'une traduction.\n");
                fclose(f);
                return 0;
            }
        }

        d->taille++;
    }

    fclose(f);
    return 1;
}

// ===================== Jeu d'apprentissage =====================

void jeu_apprentissage(const Dictionnaire *d) {
    if (d->taille == 0) {
        printf("Le dictionnaire est vide. Ajoutez des mots avant de jouer.\n");
        return;
    }

    int index = rand() % d->taille;
    Entree *e = &d->entrees[index];

    if (e->nbTraductions == 0) {
        printf("Le mot choisi n'a pas de traduction enregistree. Reessayez.\n");
        return;
    }

    char reponse[TAILLE_MOT];
    printf("Traduisez le mot francais suivant : %s\n", e->mot);
    printf("Votre reponse : ");
    if (fgets(reponse, sizeof(reponse), stdin) == NULL) return;
    enlever_retour_ligne(reponse);

    int correct = 0;
    for (int i = 0; i < e->nbTraductions; i++) {
        if (strcmp(reponse, e->traductions[i]) == 0) {
            correct = 1;
            break;
        }
    }

    if (correct) {
        printf("Bravo ! C'est correct.\n");
    } else {
        printf("Incorrect. Traductions possibles : ");
        for (int i = 0; i < e->nbTraductions; i++) {
            printf("%s", e->traductions[i]);
            if (i < e->nbTraductions - 1) printf(", ");
        }
        printf("\n");
    }
}

// ===================== Menu =====================

void afficher_menu() {
    printf("\n===== Gestionnaire de dictionnaire bilingue =====\n");
    printf("1. Afficher le dictionnaire complet\n");
    printf("2. Ajouter un mot\n");
    printf("3. Supprimer un mot\n");
    printf("4. Afficher la definition d'un mot\n");
    printf("5. Afficher la traduction d'un mot\n");
    printf("6. Jeu d'apprentissage linguistique\n");
    printf("7. Sauvegarder et quitter\n");
    printf("Choix : ");
}

int main() {
    Dictionnaire d;
    init_dictionnaire(&d);

    srand((unsigned int)time(NULL));

    // Chargement initial (si fichier existe)
    charger_dictionnaire(&d, NOM_FICHIER);

    int choix = 0;
    char buffer[32];

    do {
        afficher_menu();
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) break;
        choix = atoi(buffer);

        switch (choix) {
            case 1:
                afficher_dictionnaire(&d);
                break;
            case 2:
                ajouter_mot(&d);
                break;
            case 3:
                supprimer_mot(&d);
                break;
            case 4:
                afficher_definition(&d);
                break;
            case 5:
                afficher_traductions(&d);
                break;
            case 6:
                jeu_apprentissage(&d);
                break;
            case 7:
                if (sauvegarder_dictionnaire(&d, NOM_FICHIER)) {
                    printf("Dictionnaire sauvegarde dans '%s'.\n", NOM_FICHIER);
                } else {
                    printf("Erreur lors de la sauvegarde.\n");
                }
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Reessayez.\n");
                break;
        }

    } while (choix != 7);

    liberer_dictionnaire(&d);
    return 0;
}

