#ifndef Contig
#define Contig

using namespace std;


typedef struct liste{
	int der;
	char* ele[50];
}liste;





void ajout2(char* x,liste &l,int nbrjoueur);
char* supprimer2(liste &l, int k,int n,int k2);







#endif
