#include "lib.h"

int open_file(char *path, char * resultat,int info){
	char lettreLu = ' ';
	
	int i = 0;
	if (info){
		printf("le chemin : %s\n",path);
	}
	
	FILE *fp = NULL;
    fp = fopen (path, "r+");
	if (fp == NULL)
    {
         printf("Erreur %s \n",path);
        return EXIT_FAILURE;
    }else{
		fread(&lettreLu, sizeof(lettreLu), sizeof(char), fp);
		if (feof(fp))
		{
			printf("\nFichier Vide \n");
		}else 
		if (info){
			printf("Lettre Lu : \n");
		}
		while(!feof(fp))
		{	
		if (info){
			printf("%c ", lettreLu);
		}
			resultat[i] = lettreLu;
			fread(&lettreLu, sizeof(lettreLu), sizeof(char), fp);
			i=i+1;
			
			
			if (feof(fp))
			{
				if (info){
					printf("\n");
				}
			
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
int cryptage(int length_src, int length_peroq, char * tab_pero,char* tab_src,char* p,int decrypter ,int info){
	 FILE *fp = NULL;

    fp = fopen(p, "w");
    if (fp == NULL)
    {
        printf("Erreur %s \n",p);
        return EXIT_FAILURE;
    }
	for (int l = 0 ;l < length_src;l++){
		int nouvelle_lettre =0;
			int lettre_peroq = (int) tab_pero[(l%length_peroq)];
			int lettre_src = (int)tab_src[l];
			if (info){
					printf("decrypter : %d\n ",decrypter);
				}
			if (decrypter == 0){
				 nouvelle_lettre = lettre_src-lettre_peroq;
			}else{
				 nouvelle_lettre = lettre_src+lettre_peroq;
			}
			
			if (info){
				
				printf(" lettre peroq: %c \n ",lettre_peroq);
				printf(" lettre src: %c \n ",lettre_src);
				printf("nouvelle lettre %c \n",nouvelle_lettre);
				printf("\necriture dans %s \n ",p);
			}
			char nl = (char) nouvelle_lettre;
			fwrite(&nl, sizeof(nl), sizeof(char), fp); 
			
	}
	int retClose = fclose(fp);
    if (retClose!= 0)
    {
        printf("Erreur Open !");
        return EXIT_FAILURE;
    }
		return 0;


}
int write_f(char* path,FILE* fp){
	char w[MAX_char];
	
    printf("entrer des carateres dans le fichier %s  (note vous pouvez renter jusqu'a %d caracteres )  \n ",path,MAX_char);
   
    scanf("%s",w);
	fputs(w, fp);
	
	
}
int supp_f(char* path,int info){
	if (remove(path)==0)
		
		printf("Suppression du fichier %s \n ",path);
		
    else
        printf("impossible de supprimer le fichier %s \n ",path);
 
    return 0;
}
