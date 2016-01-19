#ifndef _MENU
#define _MENU

#include <string>
#include <vector>
// Fichier menu.h---YishuoLYU
using namespace std;

class Menu;

class OptionMenu
{
    string nom_;//nom de option.
    string description_;//description de option.
  public:
    OptionMenu(const string &nom,const string &description);
    string getNom() const {return nom_;}
    string getDescription() const {return description_;}

};


class Menu
{
    string titre_;
    vector<OptionMenu> listeOptions_;
  public:
    Menu(const string & titre);
    void setTitre(const string &titre);
    void ajouterOption(const string &nom,const string &description);
    void afficher();
    int demander();
    void executer();
    virtual void executerOption(const string &nom,bool &fin);
    bool quitter();
    void artificiel();
	void lire_document();
};


#endif

