#include<graphics.h> 
#include <conio.h>
#include <dos.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <string>
#include "fct.h"
using namespace std ;

//--------main---------------------------------
main()
{
	ofstream monFlux("jeu.log"); monFlux.close();
	write_log("Logging_started\nFile:jeu.log\nSystem:Microsoft_windows_7\nComputer:Samsung\n------------------------------------------\n");

	//partie declaration
	bloc *tete=NULL,*tete2=NULL;
	liste L,L2;
	L.der=-1;
	L2.der=-1;                             
	srand(time(0));
	int k,nbrjoueur,i,dx,dy=200,rayon,couleur,reprs,tappe,k2;
	
	
	char* tab[500],*s=new char[20],* tab2[500],*rep=new char[20];
	
	
	//choisir&lire......
	do{
		cout<<"Entrer le nombre des joueurs entre 2 et 11 :  ";
		cin>>nbrjoueur;
	}while(nbrjoueur<2||nbrjoueur>11);
	
	reprs=choix();
	couleur = choixCouleur();
	lire(tete,L,reprs,tab,nbrjoueur);
	
	if(nbrjoueur<=5)  rayon=200;
	else if(nbrjoueur<=10)  rayon=250;
	else rayon=300;
	
	//Le graphe ..........
	initwindow(2000, 1500);
	settextstyle(3,5,3);
	dx=getmaxx()-100;
	i=0;
	int nbrjoueur2=nbrjoueur;
	
	bkcolor();
	delay(1000);
	cin>>tappe;
	
	setbkcolor(0);
	cleardevice();
          
	settextstyle(4,4,1);
	setcolor(WHITE);                 
	outtextxy(350,50," JEU DE RONDE ");                                                                                                                                            
	outtextxy(250,100," Representation  ");
		
	if(reprs==1) rep="chainee";
	else rep="contigue";
		
	setcolor(couleur);                   
	outtextxy(400,100,rep);                             
		
	setcolor(WHITE);
	outtextxy(200,150," Vos joueurs : ");
	
	setcolor(WHITE);
	outtextxy(getmaxx()-50,100," Les joueurs sortants : ");
	setlinestyle(1,1,1);
	line(getmaxx()-350,120,getmaxx()-350,getmaxy()-200);
		
	rectangle(10,getmaxy()-200,390,getmaxy()-50);
	outtextxy(270, getmaxy()-160,"On commence par ");
	outtextxy(370,getmaxy()-110,"quitte la ronde");
	outtextxy(getmaxx()-100,getmaxy()-100,"Appuyer pour continuer ...");
		
	while(nbrjoueur2>1){
		
		//dessin des joueurs
		setlinestyle(0,1,1);
		dessinarc(rayon+90,rayon,tab,nbrjoueur2,couleur);
		delay(500);
		
		//on commence par k
		k=rand()%nbrjoueur2;
		setcolor(couleur);
		outtextxy(360, getmaxy()-160,tab[k]);
		
		//on supprime k2
		k2=rand()%nbrjoueur2;
		cout<<"k= "<<k<<"  k2= "<<k2<<endl;
		
		tab2[i]=new char[20];
		if(reprs==1){ s=supprimer(tete,k,nbrjoueur2,k2); tab2[i]=s; ajout(s,tete2); }
		else{ s=supprimer2(L,k,nbrjoueur2,k2);  tab2[i]=s; ajout2(s,L2,nbrjoueur2); }
		i++;	
		
		cin>>tappe;  
		dessinelli(k,k2,nbrjoueur2,rayon);
		delay(100);           
		setcolor(couleur);
		outtextxy(120,getmaxy()-110,s);
		
		setcolor(CYAN) ;
		outtextxy(dx,dy,s);
		dy+=70;
		
		cin>>tappe;
		
		//effacer tous
		dessinarc(rayon+90,rayon,tab,nbrjoueur2,0);
		
		setfillstyle(1,BLACK);                          
		bar(260 ,getmaxy()-190,363,getmaxy()-130);
		bar(11,getmaxy()-140,150,getmaxy()-110);
		
		supp(s,nbrjoueur2,tab);
		nbrjoueur2--;
		
		
		write_log(s);
			
	}
	
	
	//------------z gagne -------
	char* z= new char[20];
	
	if(reprs==1)
	 z=tete->val;
	 else 
	 z=tab[L.der];
	
	clearviewport(); 
	delay(1500);
	
	settextstyle(4,4,4);
	
	bkcolor2(z);
	cin>>tappe;
	
	clearviewport(); 
	delay(1000);
	
	setbkcolor(0);						
   	cleardevice();
   	
   	//dessin de La liste des joueur dans l ordre ou ils sont sortis de la ronde
	settextstyle(4,4,3);
	setcolor(WHITE);
	
	outtextxy(1000,100,"La liste des joueur dans l ordre ou ils sont sortis de la ronde :");
	dessinchaine(nbrjoueur-1,tab2,couleur,z);
	outtextxy(getmaxx()-100,getmaxy()-100, "Appuyer pour quitter...");
	delay(500);
	cin>>tappe;
	closegraph();

	afficherLog();
}
