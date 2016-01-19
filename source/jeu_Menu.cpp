#include <iostream>
#include <cstdlib>
#include "jeu_Menu.h"

using namespace std;


JeuMenu::JeuMenu()  : Menu("Jeu de menu :")//on donne 3 options dans notre menu.
{
  ajouterOption("artificiel","Vous pouvez modifier la grille selon vous.");
  ajouterOption("lire du document","Vous pouvez modifier la grille par le document.");
  ajouterOption("quitter","Vous pouvez quitter la jeu.");
}

void JeuMenu::executerOption(const string &nom,bool &fin)
{
  if (nom=="nouvelleOption") nouvelleOption();
  else Menu::executerOption(nom,fin);
}

void JeuMenu::nouvelleOption()
{
  cout<<"Vous avez choisi la nouvelle option"<<endl<<endl;
  system("pause");
}

