#include<iostream>
#include <cstdlib>
#include<string>
#include<fstream>
#include<vector>
#include"grille.h"
#include"Cellule.h"


using namespace std;
void Grille::setTaille()//mettre la taille de la grille.
{
	cout<<"donner un nombre de ligne:"<<endl;
	cin>>ligne_;
	cout<<"donner un nombre de colone:"<<endl;
	cin>>colone_;
}

void Grille::getTaille()//retourner la taille de la grille.
{
	cout<<"le nombre de ligne:"<<ligne_<<endl;
	cout<<"le nombre de colone:"<<colone_<<endl;
}

void Grille::InitialiserGrille_artificiel()//Initialiser la grille par facon artificiel.
{
	int i;
	int j;
	int nombre=0;
	int caractere=15;
	int grille_valeur[7][7];//on grandit la grille(7x7) pour simplifier la calcul.on cree 2 tableaux. 
    // un pour Cellule** grille_element;
	// un pour conserver les etats initials.
	grille_element=new Cellule*[7];
	for(int i=0; i<7;i++)
		grille_element[i] = new Cellule[7];
	cout<<"---------------------------"<<endl;
	cout<<char(caractere)<<" donner l'etat initiale: "<<char(caractere)<<endl;
	cout<<"---------------------------"<<endl;
	for(i=1;i<6;i++)//la boucle pour mettre le etat et situe a chaque cellule.
	{
		for(j=1;j<6;j++)
		{	
			cin>>grille_valeur[i][j];
			int v=grille_valeur[i][j];
			grille_element[i][j].set_etat(v);
			grille_element[i][j].set_ligne(i);
			grille_element[i][j].set_colone(j);
			grille_element[i][j].set_situe(grille_element);
		    if(v==1)
				nombre++;
		}	
	}
	for(i=0,j=0;i<7;i++) //la premiere ligne est zero
	{
			int v=0;
			grille_element[i][j].set_etat(v);
			grille_element[i][j].set_ligne(i);
			grille_element[i][j].set_colone(j);
	}
	for(i=0,j=0;j<7;j++) //la premiere colone est zero
	{
			int v=0;
			grille_element[i][j].set_etat(v);
			grille_element[i][j].set_ligne(i);
			grille_element[i][j].set_colone(j);
	}
	for(i=0,j=6;i<7;i++) //la derniere colone est zero
	{
			int v=0;
			grille_element[i][j].set_etat(v);
			grille_element[i][j].set_ligne(i);
			grille_element[i][j].set_colone(j);
	}
	for(i=6,j=0;j<7;j++) //la derinere ligne est zero
	{
			int v=0;
			grille_element[i][j].set_etat(v);
			grille_element[i][j].set_ligne(i);
			grille_element[i][j].set_colone(j);
	}
	nombre_=nombre;
	cout<<"--------------------------------------------------"<<endl;
	cout<<char(caractere)<<" Au debut,il y a "<<nombre_<<" cellules qui sont vivantes. "<<char(caractere)<<endl;
	cout<<"--------------------------------------------------"<<endl;

}



void Grille::InitialiserGrille_document()
{
	int i;
	int j;
	int k=0;
	int caractere=15;
	int nombre=0;
	string titre;
	cout<<"----------------------------------------"<<endl;
	cout<<char(caractere)<<" Donner le titre de txt (eg:test.txt) "<<char(caractere)<<endl;
	cout<<"----------------------------------------"<<endl;
	cin>>titre;
	ifstream fich(titre);//on lit le document.
	int n=25;
	vector<int>tab_document_(n);
	for(i=0;i<n;i++)
	{
		fich>>tab_document_[i];
	}
	int grille_valeur[7][7];//on cree 2 tableaux.
   // un pour Cellule** grille_element;
   // un pour  les etats initials;
	grille_element=new Cellule*[7];
	for(int i=0; i<7;i++)
		grille_element[i] = new Cellule[7];
	cout<<"--------------------------"<<endl;
	cout<<char(caractere)<<" la grille initiale est:"<<char(caractere)<<endl;
	cout<<"--------------------------"<<endl;
	for(i=1;i<6;i++)
	{
		for(j=1;j<6;j++)
		{	
			grille_valeur[i][j]=tab_document_[k];
			int v=grille_valeur[i][j];
			grille_element[i][j].set_etat(v);
			grille_element[i][j].set_ligne(i);
			grille_element[i][j].set_colone(j);
			grille_element[i][j].set_situe(grille_element);
			cout<<v<<" ";
		    if(v==1)
				nombre++;
			k++;
		}	
		cout<<endl;
	}
	for(i=0,j=0;i<7;i++) //la premiere ligne est zero
	{
			int v=0;
			grille_element[i][j].set_etat(v);
			grille_element[i][j].set_ligne(i);
			grille_element[i][j].set_colone(j);
	}
	for(i=0,j=0;j<7;j++) //la premiere colone est zero
	{
			int v=0;
			grille_element[i][j].set_etat(v);
			grille_element[i][j].set_ligne(i);
			grille_element[i][j].set_colone(j);
	}
	for(i=0,j=6;i<7;i++) //la derniere colone est zero
	{
			int v=0;
			grille_element[i][j].set_etat(v);
			grille_element[i][j].set_ligne(i);
			grille_element[i][j].set_colone(j);
	}
	for(i=6,j=0;j<7;j++) //la derinere ligne est zero
	{
			int v=0;
			grille_element[i][j].set_etat(v);
			grille_element[i][j].set_ligne(i);
			grille_element[i][j].set_colone(j);
	}
	nombre_=nombre;
	cout<<"--------------------------------------------------"<<endl;
	cout<<char(caractere)<<" Au debut,il y a "<<nombre_<<" cellules qui sont vivantes. "<<char(caractere)<<endl;
	cout<<"--------------------------------------------------"<<endl;
}


void Grille::afficher()
{
	int i;
	int j;
	int M=42;
	int V=2;
	int caractere=15;
	char Choix;
	string titre;
	for(i=1;i<6;i++)//la boucle pour retourner l'etat de chaque cellule.
	{
		for(j=1;j<6;j++)
		{
			if(grille_element[i][j].get_etat_pro()==1)
			{
				cout<<char(V)<<" "; 
				grille_element[i][j].set_etat(grille_element[i][j].get_etat_pro());
			}

			else
			{
				cout<<char(M)<<" "; 
				grille_element[i][j].set_etat(grille_element[i][j].get_etat_pro()); //il donne le prochain etat a l'etat maintenant.
			}
		}
		cout<<endl;
	}
	cout<<"-----------------------------------------------------"<<endl;
	cout<<char(caractere)<<" Est-ce que vous voulez sauver le resultat ? (O/N) "<<char(caractere)<<endl;//on sauvegarde le resultat.
	cout<<"-----------------------------------------------------"<<endl;
	cin>>Choix;
	if (Choix == 'O' || Choix =='o')
	{
		cout<<"--------------------------------------------------"<<endl;
		cout<<char(caractere)<<" Donner le tire de la document.txt(eg:test.txt) "<<char(caractere)<<endl;
		cout<<"--------------------------------------------------"<<endl;
		cin>>titre;
		ofstream fich_Grille_(titre);
		sauver(fich_Grille_);
		fich_Grille_.close();
	}
	cout<<"----------------------------------------------------------------"<<endl;
	cout<<char(caractere)<<" Est-ce que vous voulez continuer prochaine evalution ? (O/N) "<<char(caractere)<<endl;
	cout<<"----------------------------------------------------------------"<<endl;
	cin>>Choix;
	if (Choix == 'O' || Choix =='o')
		Evaluation();
	else
	{
		cout<<"---------------"<<endl;
		cout<<char(caractere)<<" C'est fini. "<<char(caractere)<<endl;
		cout<<"---------------"<<endl;
	}
}

void Grille::Evaluation()//Acesser la programme calculer.
{
	int i,j;
	for(i=1;i<6;i++)
	{
		for(j=1;j<6;j++)
			grille_element[i][j].Calculer_Cellule();
	}
	afficher();
}

void Grille::sauver(ofstream &ofs)
{
	int i;
	int j;
	int caractere=15;
	for(i=1;i<6;i++)
	{
		for(j=1;j<6;j++)
		{
			ofs<<grille_element[i][j].get_etat_pro()<<" "; //il faut un escapce entre chaque valeur.
		}
	}
	if(!ofs.fail())
	{
		cout<<"--------------------"<<endl;
		cout<<char(caractere)<<" Ecriture reussie "<<char(caractere)<<endl;
		cout<<"--------------------"<<endl;
	}
	else
	{
		cout<<"--------------------"<<endl;
		cout<<char(caractere)<<" Ecriture d'erreur "<<char(caractere)<<endl;
		cout<<"--------------------"<<endl;
	}
}


