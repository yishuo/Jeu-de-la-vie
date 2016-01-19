#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Cellule.h"
#include "grille.h"

using namespace std;
// Definition des methodes de la classe cellule.

void Cellule::Initcellule()//Definition de l'etats initials.
{
	Cellule_ligne_=0;
    Cellule_colone_=0;
	etat_=0;
}

void  Cellule::set_ligne(const int l)//mettre la valeur ligne a champ.
{
	Cellule_ligne_=l;
}

void  Cellule::set_colone(const int c)//mettre la valeur colone a champ.
{
	Cellule_colone_=c;
}

void Cellule::set_etat(const int v)//mettre la valeur etat a champ.
{
	etat_=v;
	etat_pro_=v;
}


void Cellule::set_situe(Cellule** grille_element)//retourner la pointeur.
{
	situe_=grille_element;
}

void Cellule::Calculer_Cellule()//Calculer le prochain etat par les voisinages. 
{
	nbvivant_=situe_[Cellule_ligne_-1][Cellule_colone_+1].etat_ + situe_[Cellule_ligne_][Cellule_colone_+1].etat_ + situe_[Cellule_ligne_+1][Cellule_colone_+1].etat_ + situe_[Cellule_ligne_-1][Cellule_colone_].etat_ + situe_[Cellule_ligne_+1][Cellule_colone_].etat_ + situe_[Cellule_ligne_-1][Cellule_colone_-1].etat_ + situe_[Cellule_ligne_][Cellule_colone_-1].etat_ + situe_[Cellule_ligne_+1][Cellule_colone_-1].etat_;
    if((situe_[Cellule_ligne_][Cellule_colone_].etat_==1) && (nbvivant_<2))
				{
					etat_pro_ = 0;
				}
	else if((situe_[Cellule_ligne_][Cellule_colone_].etat_ == 1) && (nbvivant_>3))
				{
					etat_pro_ = 0;
				}	
	
	else if((situe_[Cellule_ligne_][Cellule_colone_].etat_== 0) && (nbvivant_== 2) )
				{
					etat_pro_ = 0;
			    }

				
	else if ((situe_[Cellule_ligne_][Cellule_colone_].etat_ == 0) && (nbvivant_== 3))
				{
			        etat_pro_ = 1;
				}

}
