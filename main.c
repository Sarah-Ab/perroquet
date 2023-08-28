#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_char 100

// proto
int open_file(char *chemin,char *resultat );
int print_array(char *tab,int taille);



int main (){
	char * chemin = "file_usr/source.txt";
	//char tab_source [MAX_char] = "";
	//char tab_chiffre [MAX_char] = "";
	char resultat [MAX_char] = "";
	
	char tab_pero [MAX_char] = "";
	open_file(chemin,resultat);
	//print_array(resultat,MAX_char);
	
	
	

}
int open_file(char *chemin, char *resultat ){
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
		while(!feof(fp))
		{
			fread(&lettreLu, sizeof(lettreLu), sizeof(char), fp);
			resultat[i] = lettreLu;
			printf("\nLettre Lu : %c", lettreLu);
			printf(" tab .. = %c",resultat[i]);
			if (feof(fp))
			{
			printf("\n\t Fichier Fini !!! \n");
			return 0;
			}
			
		}
		
		
		return 0;
	}


}
int print_array(char *tab,int taille){

	for (int i=0; i <taille ; i++){
		if (tab[i] == '\0' && i < 2){
			
			//return 0;
		}
		printf(" \n tab = %c ",tab[i]);
		
	}
	printf("\n");
	return 0;
	
}