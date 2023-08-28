#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_char 100

// proto
int open_file(char *chemin,char * resultat );
int print_array(char *tab,int taille);




int main (){
	char * chemin = "file_usr/source.txt";
	//char tab_source [MAX_char] = "";
	//char tab_chiffre [MAX_char] = "";
	char resultat [MAX_char] = "";
	
	char tab_pero [MAX_char] = "";
	
	open_file(chemin,resultat);
	printf("affiche la tab resultat");
	print_array(resultat,MAX_char);
	
	
	

}
int open_file(char *chemin, char * resultat ){
	char lettreLu = ' ';
	
	int i = 0;
	
	printf("le chemin : %s",chemin);
	FILE *fp = NULL;
    fp = fopen (chemin, "rt");
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
			resultat[i] = lettreLu;
			fread(&lettreLu, sizeof(lettreLu), sizeof(char), fp);
			i=i+1;
			printf("\nLettre Lu : %c", lettreLu);
			
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

