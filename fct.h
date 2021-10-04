
#ifndef fct
#define fct

#include <iostream>
#include <cstdlib>
#include <string>
#include "Contig.h"
#include "Chaine.h"
#include "color.h"
using namespace std ;
                                  
void write_log(string msg);
int choix();
int choixCouleur();
void lire(bloc *&tete,liste &L,int re,char* tab[], int nbrjoueur);
void dessinarc(int r1,int r2,char* c[],int nbrjoueur,int couleur);
void dessinelli(int k1,int k2,int nbrjoueur,int r);
void supp(char* y,int n,char* tab[]);
void afficherLog();
void dessinchaine(int nbrjoueur,char* c[],int couleur,char* z);
void bkcolor();
void bkcolor2(char* z);

#endif

