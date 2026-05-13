#include <stdio.h>
int incrementParValeur(int n, int i) {
 printf("[incrementParValeur] Adresse : %x, valeur : %d (on travaille sur une copie)\n", &n, n);
 return n + i; // On retourne la valeur telle qu'elle devrait être, sans la modifier directement
}
void incrementParAdresse(int *pN, int i) {
 printf("[incrementParAdresse] Adresse : %x, valeur : %d (on travaille sur le même espace mémoire)\n", pN, *pN);
*pN += i; // On modifie directement la valeur à l'adresse que l'on nous donne
}
int main(void) {
 int n = 5;
 printf("[main] Adresse : %x, valeur : %d\n\n", &n, n);
 incrementParValeur(n, 2);
 printf("[main] Valeur après incrementParValeur (1/2) : %d (la valeur n'a pas été modifiée)\n\n", n);
 n = incrementParValeur(n, 2);
 printf("[main] Valeur après incrementParValeur (2/2) : %d (la valeur retournée a été affectée à n)\n\n", n);
 incrementParAdresse(&n, 2);
 printf("[main] Valeur après incrementParAdresse : %d (la valeur est directement modifiée en mémoire)\n", n);
 return 0;}
