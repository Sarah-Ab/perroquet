#ifndef ENTETE_INCLUDED
#define ENTETE_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_char 100
// proto
int open_file(char *chemin,char * resultat,int info);
int print_array(char *tab,int taille);
int clean_array(char * r, int taille );
int getLength(char *tab,int taille);
int cryptage(int length_src, int length_peroq, char * tab_pero,char * p,int info);
int write_f(char* path,FILE* fp);
#endif // ENTETE_INCLUDED
