#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "menu.h"
#include"grille.h"
using namespace std;

// Definition des methodes de la classe OptionMenu

OptionMenu::OptionMenu(const string &nom,const string &description)
  : nom_(nom), description_(description)
{
}


// Definition des methodes de la classe Menu

Menu::Menu(const string & titre) : titre_(titre)
{
}

void Menu::setTitre(const string &titre)
{
  titre_=titre;
}

void Menu::ajouterOption(const string &nom,const string &description)
{
  listeOptions_.push_back(OptionMenu(nom,description));
}


void Menu::afficher()
{
  cout<<titre_<<endl;
  for (int i=0;i<listeOptions_.size();i++) {
    cout<<"- "<<setw(2)<<i<<" : "<<listeOptions_[i].getDescription()<<endl;
  }
}

int Menu::demander()
{
  int choix;
  cout<<"Votre choix : ";
  cin>>choix;
  cout<<endl;
  return choix;
}

void Menu::executer()//on choisit la numero pour les options.
{
  bool fin=false;
  while(!fin) {
    system("cls");
    afficher();
    int choix=demander();
    if (choix>=0 && choix<listeOptions_.size())
      executerOption(listeOptions_[choix].getNom(),fin);
    else {
      cout<<"Choix incorrect"<<endl;
      system("pause");
    }
  }
}

void Menu::executerOption(const string &nom,bool &fin)
{
  fin=false;
  if (nom=="quitter") {fin=quitter();}
  else if (nom=="lire du document") {lire_document();}
  else if (nom=="artificiel") {artificiel();}
  else {
    cout<<"Option inexistante"<<endl;
    system("pause");
    }
}


void Menu::artificiel()//acesser la initiation de facon artificiel.
{
	Grille G;
	G.InitialiserGrille_artificiel();
    G.Evaluation();
	cin.get();
	cin.get();
}

void Menu::lire_document()//acesser la initiation de facon lire_document.
{
	Grille G;
	G.InitialiserGrille_document();
    G.Evaluation();
	cin.get();
	cin.get();
}


bool Menu::quitter()
{
  bool fin=false;
  char reponse;
  int caractere=15;
  cout<<"-------------------------------------------------------"<<endl;
  cout<<char(caractere)<<" Voulez-vous vraiment sortir de l'application (o/n)? "<<char(caractere)<<endl;
  cout<<"-------------------------------------------------------"<<endl;
  cin>>reponse;
  if ((reponse=='o')||(reponse=='O')) fin=true;
  return fin;
}




