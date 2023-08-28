#ifndef ENTETE_INCLUDED
#define ENTETE_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_char 100
// proto
int open_file(char *chemin,char * resultat );
int print_array(char *tab,int taille);
int clean_array(char * r, int taille );
int getLength(char *tab,int taille);
int criptage(int length_src, int length_peroq, char * tab_pero,char * p);
#endif // ENTETE_INCLUDED
