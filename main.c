#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_char 100

// proto
int open_file(char *chemin,char * resultat );
int print_array(char *tab,int taille);
int clean_array(char * r, int taille );
int getLength(char *tab,int taille);
int criptage(int length_src, int length_peroq, char * tab_pero);




int main (){
	char * path_src = "file_usr/source.txt";
	char * path_peroq = "peroq.def";
	char tab_source [MAX_char] = "";
	char tab_chiffre [MAX_char] = "";
	char resultat [MAX_char] = "";
	int length_peroq = 0;
	int length_src = 0;
	char tab_pero [MAX_char] = "";
	
	// Pour le fichier source
	open_file(path_src,resultat); // on recupere le resultat du fichier dans resultat
	stpcpy(tab_source,resultat); // copy resultat dans tab_source
	clean_array(resultat,MAX_char);
	print_array(tab_source,MAX_char); // print le contenu de tab_source
	
	// pour le fichier peroq
	open_file(path_peroq,resultat);
	stpcpy(tab_pero,resultat); // copy resultat dans tab_source
	clean_array(resultat,MAX_char);
	print_array(tab_pero,MAX_char); // print le contenu de tab_source
	
	// faire le criptage 
	
	
	length_peroq = getLength(tab_pero,MAX_char);
	length_src = getLength(tab_source,MAX_char);
	printf(" taille src : %d taille peroq % d \n",length_src,length_peroq);
	
	criptage(length_src,length_peroq,tab_pero);
	
	

}
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
int criptage(int length_src, int length_peroq, char * tab_pero){
	for (int l = 0 ;l < length_src;l++){
			
			char lettre = tab_pero[(l%length_peroq)];
			
			
			printf("nouvelle lettre : %c \n ",lettre);
	}
}
