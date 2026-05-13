#include <stdio.h>

// Définition de la structure Point
typedef struct {float x;float y;} Point;


void procedure(Point *p1, Point *p2) {
     Point aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

int main() {
    Point A, B;
    printf("Saisir les coordonnées du point A (x y) : ");
    scanf("%f %f", &A.x, &A.y);

    printf("Saisir les coordonnées du point B (x y) : ");
    scanf("%f %f", &B.x, &B.y);


    printf("Avant echange ");
    printf("Point A : (%.2f, %.2f)\n", A.x, A.y);
    printf("Point B : (%.2f, %.2f)\n", B.x, B.y);

     procedure(&A, &B);


    printf("Apres echange ");
    printf("Point A : (%.2f, %.2f)\n", A.x, A.y);
    printf("Point B : (%.2f, %.2f)\n", B.x, B.y);

    return 0;
}

