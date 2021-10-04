#include<graphics.h> 
#include <conio.h>
#include <dos.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <string>
#include "Contig.h"
#include "Chaine.h"
#include "color.h"
using namespace std ;



//--------------CREER ET ECRIRE DANS UN FICHIER LOG-----------
void write_log(string msg){ 
	
	ofstream ofs("jeu.log",ofstream::app); 
	
	if(ofs){ 
	struct  tm temps;
		time_t a;
		a=time(NULL);
		temps=*localtime(&a); 
		ofs<<temps.tm_mday<<"-"<<temps.tm_mon+1<<"-"<<temps.tm_year+1900<<"__";
		ofs<<temps.tm_hour<<":"<<temps.tm_min<<":"<<temps.tm_sec<<"__";
		ofs<<"->"<<msg<<endl; 
	        } 
	else cout<<"Imposible d ouvrire le fichier log ...\n";
	
	ofs.close(); 
}
//--------------choix-------------------
int choix(){
	int re;
	
	do{
		cout<<"\n--------------------------- \n";
		cout<<"Choisir une representation : \n";
		cout<<"1- Chainee\n2- Contigue\n =>  ";
		cin>>re;
	}while(re!=1&&re!=2);
	
	return re;
	
}

//--------------choix couleur-------------------
int choixCouleur(){
	int coul;
	do{
		cout<<"\n--------------------------- \n";
		cout<<"Choisir une couleur pour votre joueurs : \n";
		cout<<"1-  BLUE\n2-  GREEN\n3-  CYAN\n";
		cout<<"4-  RED\n5-  MAGENTA\n6-  BROWN \n";
		cout<<"7-  LIGHTGRAY\n8-  DARKGRAY\n9-  LIGHTBLUE\n";
		cout<<"10- LIGHTGREEN\n11- LIGHTCYAN\n12- LIGHTRED\n";
		cout<<"13- LIGHTMAGENTA\n14- YELLOW\n";
	
		cin>>coul;
	}while(coul<1&&coul>14);
	
	return coul;
}


//----------lire--------------
void lire(bloc *&tete,liste &L,int re,char* tab[], int nbrjoueur){
	cout<<" Entrez les noms des joueurs :\n  ";
	int i;
	string n;
	for( i=0;i<nbrjoueur;i++) 
	{
		cin>>n;
		tab[i]=new char[30];
		strcpy(tab[i],n.c_str());
		
		if(re==1) ajout(tab[i],tete);	
          else   ajout2(tab[i],L,nbrjoueur);
	}
	
}

//--------dessin arc2-------------
void dessinarc(int r1,int r2,char* c[],int nbrjoueur,int couleur){
	struct arccoordstype a,b;
	int j=0,angle=0,angle2=0;
	
	while(angle2<=360)
   {
   	setcolor(LIGHTGRAY);
	arc(getmaxx()/2,getmaxy()/2,angle2/5,angle2+2,r2);
	
	 angle2 = angle2+1;
	
  }
	
	
	while(angle<=360&&j<nbrjoueur)                                            
   {
   	setcolor(BLACK);
	arc(getmaxx()/2,getmaxy()/2,angle/1,angle+2,r1);
	getarccoords(&a);
	
	arc(getmaxx()/2,getmaxy()/2,angle/1,angle+2,r2);
	getarccoords(&b);
	
	setcolor(couleur);
	outtextxy(a.xend, a.yend,c[j]); 
	setfillstyle(1,couleur);
	fillellipse(b.xend,b.yend,5,5);
	
	 angle = angle+360/nbrjoueur;
      delay(300);
      j++;
  }
}

//----------ellipse------------
void dessinelli(int k1,int k2,int nbrjoueur,int r){
	struct arccoordstype a,b,a1,b1;
	int angle=0,deb,fin;
	int nbr=360/nbrjoueur;
	int k3=k1+k2;
	if(k3>=nbrjoueur) k3-=nbrjoueur;
	while(angle<=360)
   {
   	setcolor(LIGHTGRAY);
	arc(getmaxx()/2,getmaxy()/2,angle/5,angle+2,r);
	getarccoords(&a);
	getarccoords(&b);
	
	if(angle==k1*nbr)
	{	deb=angle;a1=a;}
	if(angle==k3*nbr)	
	{	fin=angle;b1=b;}
			
	angle +=1;	
	
   }	
	setcolor(RED);	
	setfillstyle(1,4);
	
	fillellipse(a1.xend,a1.yend,5,5);

	
	if(k3==k1||k1>k2||fin==0||k1==k2) fin+=360;
	
	
	angle=deb;
	while(angle<=fin){
		arc(getmaxx()/2,getmaxy()/2,angle,angle+2,r);
		angle+=1;
		delay(30);
	}

	fillellipse(b1.xend,b1.yend,5,5);
	
  
}
//--------supprimer-----------------
void supp(char* y,int n,char* tab[])
{
	for(int i=0;i<n;i++)	
	{	if(tab[i]==y)
			for(int j=i;j<n-1;j++)	
				tab[j]=tab[j+1];
		
	}

}


//---------afficherLog----------
void afficherLog(){
	string line;

	ifstream mon;
	  mon.open("jeu.log");
		if(mon){
		   while(getline(mon,line)){
			    mon>>line;
			    cout<<line<<endl;
		     }
			mon.close();
		}
		else cout<<"ERREUR : Imposible d ouvrire le fichier\n";
}


//--------dessin chaine-------------
void dessinchaine(int nbrjoueur,char* c[],int couleur,char* z){
	float i=100;
	int dx=100,dy=300;
	
	 for(int j=0;j<nbrjoueur;j++){
	 	                       
	 	
	 	if(dx==1000){
	 		dx=100;
	 		dy+=200;
		 }
		delay(500);
	 	setcolor(couleur);
	 	rectangle(dx,dy,dx+150,dy+50);
		 delay(500);
		 
	 	setcolor(WHITE);
	 	outtextxy(dx+120,dy+45,c[j]);
	 	
	 	delay(500);
	 	setcolor(couleur);
	 	line(dx+150,dy+30,dx+250,dy+30);                              
	 	outtextxy(dx+250,dy+45,">");                      
	 	
	 	dx+=250;
	 	i+=100;
	 }
	                  
	 delay(500);
	 rectangle(dx,dy,dx+150,dy+50);
	 setcolor(WHITE);
	 delay(500);
	 outtextxy(dx+120,dy+45,z);
}

//--------bk-color--------------
void bkcolor(){
	
	int h1,h2,h3,h4,h5,h6;
	int dx=getmaxx()/4,dy=getmaxy()/4;
	h1=coul(0,224,230);
	h2=coul(0,184,210);
	h3=coul(208,184,210);
	h4=coul(255,0,109);
	h5=coul(0,0,109);
	h6=coul(0,62,119);
	char* t[5]={"1","2","3","4","5"};
	setbkcolor(h1);						
   	cleardevice();
   	 
   	 rectangle(dx,dy,3*dx,3*dy);
   	 
	for(int i=4;i>=0;i--){
		settextstyle(4,4,2);
		setcolor(h2);
		outtextxy(getmaxx()-70,getmaxy()-100," Chargement du jeu ... ");
		outtextxy(getmaxx()-50,getmaxy()-100,t[i]);
		
		settextstyle(4,4,4);
		setcolor(h2);	
		outtextxy((3*dx)-95,2*dy," BIENVENU AU JEU DE RONDE ");	
		delay(500);
		setcolor(h3);	
		outtextxy((3*dx)-95,2*dy," BIENVENU AU JEU DE RONDE ");
		delay(500);
		setcolor(h4);	
		outtextxy((3*dx)-95,2*dy," BIENVENU AU JEU DE RONDE ");
		delay(500);
		setcolor(h5);	
		outtextxy((3*dx)-95,2*dy," BIENVENU AU JEU DE RONDE ");	
		delay(500);
	
	}	
	
	settextstyle(4,4,2);
	setcolor(h1);
	outtextxy(getmaxx()-50,getmaxy()-100," Chargement du jeu ... ");
	delay(50);
	settextstyle(4,4,2);
	setcolor(h2);
	outtextxy(getmaxx()-50,getmaxy()-100," Appuyer pour commencer le jeu ... ");
	delay(500);
	
}

//--------bk-color2--------------
void bkcolor2(char* z){
	
	int h1,h2,h3,h4,h5,h6;
	int dx=getmaxx()/4,dy=getmaxy()/4;
	h1=coul(0,224,230);
	h2=coul(0,184,210);
	h3=coul(208,184,210);
	h4=coul(255,0,109);
	h5=coul(0,0,109);
	h6=coul(0,62,119);
	setbkcolor(h1);						
   	cleardevice();
   	 
   	 
	for(int i=3;i>=0;i--){
		
		
		//---effacer les rect
		setcolor(h1);
		rectangle(dx,dy,3*dx,3*dy);
		rectangle(dx-50,dy-50,(3*dx)+50,(3*dy)+50);
		rectangle(dx-100,dy-100,(3*dx)+100,(3*dy)+100);
		rectangle(dx-150,dy-150,(3*dx)+150,(3*dy)+150);
		
		
		settextstyle(4,4,4);
		setcolor(h2);	
		outtextxy((2*dx)-50,2*dy,z);
		outtextxy((3*dx)-200,2*dy," GAGNE ");
		setcolor(WHITE);
		rectangle(dx,dy,3*dx,3*dy);	//rect1
		delay(500);
		
		setcolor(h3);	
		outtextxy((2*dx)-50,2*dy,z);
		outtextxy((3*dx)-200,2*dy," GAGNE ");
		setcolor(WHITE);
		rectangle(dx-50,dy-50,(3*dx)+50,(3*dy)+50);//rect2
		delay(500);
		
		setcolor(h4);	
		outtextxy((2*dx)-50,2*dy,z);
		outtextxy((3*dx)-200,2*dy," GAGNE ");
		setcolor(WHITE);
		rectangle(dx-100,dy-100,(3*dx)+100,(3*dy)+100); //rect3
		delay(500);
		
		setcolor(h5);
		outtextxy((2*dx)-50,2*dy,z);	
		outtextxy((3*dx)-200,2*dy," GAGNE ");
		setcolor(WHITE);
		rectangle(dx-150,dy-150,(3*dx)+150,(3*dy)+150); //rect4	
		delay(500);
		
		
	}	
	
	settextstyle(4,4,2);
	setcolor(h2);
	outtextxy(getmaxx()-50,getmaxy()-50," Appuyer pour continuer ... ");
	delay(500);
	
	
	
}



