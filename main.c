#include "lib.h"

int choix_cryptage (char* path_src, char* path_dest,char*path_peroq,int decrypter , int info);
int choix_decryptage(char* path_dest,char* path_src,char* path_peroq, int info);
int choix_ecrire(char* path);
int choix_lecture(char* path_src, char* path_dest,char*path_peroq);

int main (){
	/** definition des chemins **/
	
	char * path_src = "file_usr/source.txt";
	char * path_dest = "file_usr/dest.txt";
	char * path_peroq = "peroq.def";
	
	/** initialisations des variables utilisees par le menu **/
	int menu = 0;
	int choix = 0;
	
	int info = 0; // affiche les info 
	
	char* choix_menu="Menu : 1) crypter , 2) ecrire dans le fichier source , 3) ecrire dans le fichier peroq , 4) lire les fichiers,5) decrypter 6) quitter";
	printf("%s \n",choix_menu);
	while (menu == 0 ){
		
		scanf("%d",&choix);
		switch(choix)
		{
			case 1:
			choix_cryptage(path_src,path_dest,path_peroq,0,info);
			break;
			
			case 2:
			choix_ecrire(path_src);
			break;
			
			case 3:
			choix_ecrire(path_peroq);
			break;
			
			case 4:
			choix_lecture(path_src, path_dest,path_peroq);
			printf("\n");
			break;
			case 5:
			choix_decryptage(path_dest,path_src,path_peroq,info);
			break;
			
			case 6: 
				printf("Vous allez quitter le programme\n");
				menu = 1;
				return 0;
				
			default :
				printf("Selectionnez un choix disponible : ");
				printf("\n \t %s\n",choix_menu);
			
		}
		printf("Retour au menu  principal: \n"); 
	}
	
	
	
	

}

int choix_cryptage (char* path_src, char* path_dest,char*path_peroq,int decrypter , int info){
	
	char tab_source [MAX_char] = "";
	char tab_pero [MAX_char] = "";
	char resultat [MAX_char] = "";
	int r=1;
	int length_peroq = 0;
	int length_src = 0;

	// Pour le fichier source
	r=open_file(path_src,resultat,0); // on recupere le resultat du fichier dans resultat
	stpcpy(tab_source,resultat); // copy resultat dans tab_source
	clean_array(resultat,MAX_char);
	
	if (info){
		printf("affiche les elements du tableaux source \n");
		print_array(tab_source,MAX_char); // print le contenu de tab_source
	}
	// pour le fichier peroq
	r=r+open_file(path_peroq,resultat,0);
	stpcpy(tab_pero,resultat); // copy resultat dans tab_source
	clean_array(resultat,MAX_char);
	
	if (info){
		printf("affiche les elements du tableaux perroq \n");
		print_array(tab_pero,MAX_char); // print le contenu de tab_source
	}
	// faire le cryptage 
	
	
	length_peroq = getLength(tab_pero,MAX_char);
	length_src = getLength(tab_source,MAX_char);
	//printf(" taille src : %d taille peroq % d \n",length_src,length_peroq);
	if (r==0){
		r=r+cryptage(length_src,length_peroq,tab_pero,tab_source,path_dest,decrypter ,info);
	}
	
	if (info){
		
		printf("\nAffiche le contenu du fichier destination %d\n",r); 
		open_file(path_dest,resultat,1);
	}
	if (r==0)
	{
		printf("le fichier a bien ete crypte voir les modifications dans le fichier %s \n ",path_dest);
	}
	if (!decrypter){
		supp_f(path_src,info);	
	} 

}
int choix_decryptage(char* path_dest,char* path_src,char* path_peroq, int info)
{
	choix_cryptage(path_dest, path_src,path_peroq,1,info);
}

int choix_ecrire(char* path){
	
	FILE *fp = NULL;
	fp = fopen(path, "w+");
	if (fp == NULL)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }else{
		write_f(path,fp);
		int retClose = fclose(fp);
		if (retClose!= 0){
			printf("Erreur Open !");
			return EXIT_FAILURE;
		}
		printf("les changements ont bien ete pris en compte");
		return 0;
	}
	

}
int choix_lecture(char* path_src, char* path_dest,char*path_peroq){
	int menu_lecture = 0;
	int choix_letcure=0;
	printf("Menu lecture : 1) lire tous les fichiers  , 2) lire le fichier source , 3) lire le fichier peroq , 4) lire le fichier crypte , 5) quitter \n");
	scanf("%d",&choix_letcure);
	char resultat [MAX_char] = "";
	switch(choix_letcure)
	{
			case 1:
			open_file(path_src,resultat,1);
			printf("\n ---\n");
			open_file(path_dest,resultat,1);
			printf("\n ---\n");
			open_file(path_peroq,resultat,1);
			break;
			
			case 2:
			open_file(path_src,resultat,1);
			break;
			
			case 3:
			open_file(path_peroq,resultat,1);
			break;
			
			case 4:
			open_file(path_dest,resultat,1);
				
			break;
			
			case 5: 
				printf("Vous allez quitter le programme\n");
				return 0;
				
			default :
				printf("Selectionnez un choix disponible : \n");
				
			
		
	}
		
}
