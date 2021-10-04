#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct bloc{
	char* val;
	struct bloc *suiv;
}bloc;




//----------ajouter-------------
void ajout(char* x, bloc* &tete){
	
	bloc *nov= new bloc;
	nov->val= new char[20];
	nov->val=x;
	nov->suiv=tete;
	

	if(tete==NULL)
			tete=nov;   
	else if(tete->suiv==NULL)
		tete->suiv=nov;		
	else
		{
			bloc* p =tete;
			do	p=p->suiv;  while(p->suiv!=tete);
			p->suiv=nov;
		}	
	
}


//-----supprimer---------------
char* supprimer(bloc *&tete, int k,int n,int k2)
{	
	
	if(tete->suiv!=tete) {
		bloc* p =tete;
		bloc *prec=p;
		int i=0;
		while(i<k+k2){
			prec=p;
			p=p->suiv;  
			i++;
		}
				 
		if(tete==p) tete=p->suiv; 
				 
		prec->suiv=p->suiv;
					
		char* x= p->val;
		delete p;
		return x;

	}
	else return tete->val;
}
	





