#include "lib.h"


int main (){
	char * path_src = "file_usr/source.txt";
	char * path_dest = "file_usr/dest.crt";
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
	
	criptage(length_src,length_peroq,tab_pero,path_dest);
	
	

}
