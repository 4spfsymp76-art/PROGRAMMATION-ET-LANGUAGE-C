 #include <stdio.h>
 int main(void) {
 int i = 0;
    FILE* pf = fopen("../monFichier.txt", "w");
 if (pf == NULL) {
 printf("Erreur d'ouverture de fichier.");
 return 1;
    }
 for (i = 0; i < 5; i++) {
 printf("%d caracteres ecrits.\n", fprintf(pf, "%d", i*i));
    }
    fclose(pf);
    pf = NULL;
 return 0;
 }
