#include <iostream>
using namespace std;
#include <string>
#include "Hero.h"
oid combatEntreDeuxHeros(Hero& h1, Hero& h2) {

    cout << "Début du combat !!!" << endl;
    h1.afficherStats();
    h2.afficherStats();

    // Déterminer l'ordre d'attaque (vitesse)
    Hero* attaquant;
    Hero* defenseur;

    if (h1.getVitesse() >= h2.getVitesse()) {
        attaquant = &h1;
        defenseur = &h2;
    } else {
        attaquant = &h2;
        defenseur = &h1;
    }

    // Boucle de combat
    while (h1.getPV() > 0 && h2.getPV() > 0) {

        // Effet début de tour
        attaquant->effetDebutTour();

        // Calcul des dégâts
        int degats = attaquant->calculerDegats(*defenseur);

        // Application des dégâts
        defenseur->perdrePV(degats);

        cout << attaquant->getNom()
             << " attaque "
             << defenseur->getNom()
             << " et inflige "
             << degats
             << " dégâts." << endl;

        cout << defenseur->getNom()
             << " a maintenant "
             << defenseur->getPV()
             << " PV." << endl;

        // Effet fin de tour
        attaquant->effetFinTour();

        // Changement de rôle
        Hero* temp = attaquant;
        attaquant = defenseur;
        defenseur = temp;
    }

    // Résultat du combat
    cout << " Fin du combat  !!" << endl;

    if (h1.getPV>0)
        cout << h1.getNom() << " a gagné !" << endl;
    else
        cout << h2.getNom() << " a gagné !" << endl;
}
