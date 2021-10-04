#ifndef Chaine
#define Chaine

using namespace std;

typedef struct bloc{
	char* val;
	struct bloc *suiv;
}bloc;


void ajout(char* x, bloc* &tete);


char* supprimer(bloc *&tete, int k,int n,int k2);












#endif


