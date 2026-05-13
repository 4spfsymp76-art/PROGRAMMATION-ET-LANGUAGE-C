
#include<stdio.h>
int main()
{
    int choix;
    printf("Choisissez votre boisson:\n");
    printf("1 - soda:\n");
    printf("2 - jus de pomme:\n");
    printf("3 - jus de fruit:\n");
    printf("10 - chocolat chaud:\n");
    printf("11 - café:\n");
    printf("Entrez le numéros de la boisson:\n");
    scanf("%d",&choix);
 switch(choix)
  {
  case 1:
      {
      printf("Vous avez choisi un soda.\n");
      break;
      }
  case 2:
      {
      printf("Vous avez choisi un jus de pomme.\n");
      break;
      }
  case 3:
      {
      printf("Vous avez choisi un jus de fruit.\n");
  break;
  }
  case 10:
      {
      printf("Vous avez choisi un chocolat chaud.\n");
      break;
      }
  case 11:
      {
      printf("Vous avez choisi un café:\n");
      break;
  }
  default:
    {
     printf("Vous n'avez choisi ni 1 ni 2 ni 3 ni 10 et ni 11.\n");
     break;
    }

  }

 return 0;
}











