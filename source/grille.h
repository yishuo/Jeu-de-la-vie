#ifndef _GRILLE
#define _GRILLE
#include "Cellule.h"
#include<fstream>

// Fichier grille.h---ZunzunWANG
using namespace std;

class Grille
{
    int ligne_;//la nombre de ligne.
	int colone_;//la nombre de colone.
	int nombre_;//Tout le cellule qui est vivant.
	Cellule** grille_element;
public:
	//void Grille();
	void InitialiserGrille_artificiel();//par artificiel.
	void InitialiserGrille_document();//par lire document.
	void Evaluation();
	void setTaille();
	void getTaille();
	void afficher();
	void sauver(ofstream &ofs);
};

#endif