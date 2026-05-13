#include <stdio.h>

int nbOccurence( char* chaine, char c)
{
    int i,nb=0;
    for(i=0;chaine[i]!='\0';i++)
    {
        if(chaine[i]==c)
        {nb++;}

    }
 return nb;
}

 int main()
 {
  char c;
  char chaine[10];
  //char* chaine;
  //char* chaine=(sizeof(char)*10);
  printf("donner la chaine de caractere \n");
  scanf("%s",chaine);
  getchar();//consommer le \n dans le buffer(elle permet de lire un caractre donc elle lit \n);
  printf("donner le carctere\n");
  scanf("%c",&c);
  printf("Le nbre d occurence est %d", nbOccurence(chaine,c));

     return 0;
 }




