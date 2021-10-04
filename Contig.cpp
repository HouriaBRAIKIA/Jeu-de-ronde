#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef struct liste{
	int der;
	char* ele[50];
}liste;



//----------ajouter-------------
void ajout2(char* x,liste &l,int nbrjoueur){
		
	if(l.der<nbrjoueur) {
		l.der++;
		
		l.ele[l.der]=new char[20];
		l.ele[l.der]=x;		
	} 
}


//--------supprimer-----------------
char* supprimer2(liste &l, int k,int n,int k2)
{	
	
	if(l.der>-1) {
		char* x;
		if(l.der>0)
		{
			x= l.ele[k+k2];
			for(int i=k+k2;i<l.der;i++)
		 	 l.ele[i]=l.ele[i+1];
			 
			 l.der--;
		 }
		else  x=l.ele[l.der];
		
		return  x; 
	}
	
	
}


