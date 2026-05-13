#include<stdio.h>
int main()
{
    float note;
    float somme=0;
    int i;
    for(i=1;i<=3;i++)
    {
    do
    {
        printf("Saisissez une note:\n");
        scanf("%f",&note);
        if(note < 0.0f || note > 20.0f)
        {
            printf("Note incorrecte, recommencer\n");
        }
    }
    while(note < 0.0f || note >20.0f);
    somme+=note;
    }
    printf("Moyenne =%f", somme/3.0f);
    return 0;













}
