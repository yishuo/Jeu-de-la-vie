#ifndef _JEU_MENU
#define _JEU_MENU
#include "menu.h"

// Fichier jeu_Menu.h--ZunzunWANG
class JeuMenu : public Menu
{
  public:
    JeuMenu();
    void executerOption(const string &nom,bool &fin);
    void nouvelleOption();//creer nouvelle option.
};


#endif
