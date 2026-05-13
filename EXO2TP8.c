#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
   float note;
   float moyenne,somme=0;
   char choix;
   int indice=0;
   float* Tab=NULL;
   bool ok=true;
   while(ok)
   {
      printf("Voulez vous saisir une note?\n (O/N O pour oui, N pour non)\n");
       scanf("%c", &choix);

   if(choix=='O')
       {
           printf("Saisir la note :\n");
           scanf("%f",&note);
           if (Tab==NULL){Tab=(float*)malloc(sizeof(float));}
           else Tab=realloc(Tab,(indice+1)*sizeof(float));
           Tab[indice]=note;
           somme+=note;
           indice++;
       }

  else if(choix== 'N')
  {
      ok=false;
  }
    else {printf("choix invalide. Veuillez entrer 'O' ou 'N' .\n");}
    getchar();
   }
moyenne=somme/indice;
printf("La moyenne des notes saisis est %f",moyenne);
free(Tab);


    return 0;
}

