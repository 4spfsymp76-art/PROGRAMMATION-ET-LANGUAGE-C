#include <stdio.h>
#include<stdlib.h>
int main()
{
  int* Tab=(int *)calloc(6 , sizeof(int));

  printf("Voila le contenu de votre tableau :\n");
  for(int i=0;i<6;i++)
  {
      printf("%d \t", *(Tab+i));
  }

    return 0;
}
