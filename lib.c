#include "lib.h"

int open_file(char *path, char * resultat ){
	char lettreLu = ' ';
	
	int i = 0;
	
	printf("le chemin : %s",path);
	FILE *fp = NULL;
    fp = fopen (path, "rt");
	if (fp == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }else{
		fread(&lettreLu, sizeof(lettreLu), sizeof(char), fp);
		if (feof(fp))
		{
			printf("\nFichier Vide !!!");
		}
		
		while(!feof(fp))
		{	
			printf("\nLettre Lu : %c", lettreLu);
			resultat[i] = lettreLu;
			fread(&lettreLu, sizeof(lettreLu), sizeof(char), fp);
			i=i+1;
			
			
			if (feof(fp))
			{
			printf("\n\t Fichier Fini !!! \n");
			
			}
			
		}
		
    int retClose = fclose(fp);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }
		return 0;
	}


}
int print_array(char *tab,int taille){

	for (int i=0; i <taille ; i++){
		if (tab[i] == '\0'){
			printf(" \n ");
			return 0;
		}
		printf(" \n tab = %c ",tab[i]);
		
	}
	
	return 0;
	
}

int clean_array(char * r, int taille ){
	for (int i=0 ; i< taille ; i++){
		r[i] = '\0';
	}
	return 0;
}


int getLength(char *tab,int taille){
	int l = 0;
	for (int i=0; i <taille ; i++){
		if (tab[i] == '\0'){
			return l;
		}
		l++;
		
	}
	return l;
}
int criptage(int length_src, int length_peroq, char * tab_pero,char* p){
	 FILE *fp = NULL;

    fp = fopen(p, "w+t");
    if (fp == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }
	for (int l = 0 ;l < length_src;l++){
			char lettre = tab_pero[(l%length_peroq)];
			printf("nouvelle lettre : %c \n ",lettre);
			 fwrite(&lettre, sizeof(lettre), sizeof(char), fp);
	}
}
