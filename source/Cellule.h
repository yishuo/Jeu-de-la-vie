#ifndef _CELLULE
#define _CELLULE

// Fichier cellule.h---YishuoLYU
using namespace std;

class Cellule
{
	int etat_;//mort = 0, vivant=1;
	int nbvivant_;
	int etat_pro_;//l'etat apres evaluation.
	Cellule** situe_;
	int Cellule_ligne_;
	int Cellule_colone_;
public :
	void Initcellule();
	void set_ligne(const int l);
	void set_colone(const int c);
	void Calculer_Cellule();//calculer prochain etat.
	void set_etat(const int v);
	int get_etat(){return etat_;};
	int get_etat_pro(){return etat_pro_;};
    void set_situe(Cellule** grille_element);
};
#endif