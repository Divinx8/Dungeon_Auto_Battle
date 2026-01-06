#include <iostream>
using namespace std;
#include <string>
class Mage : public Hero {

public:
    Mage(string name, int pv, int att, int def, int vit, int Max)
        : Hero(name, pv, att, def, vit, Max) {}

    // Identifiant de classe
    int getClasse() const override {
        return 2; // Mage
    }

    // Calcul des dégâts du Mage
    int calculerDegats(const Hero& cible) const override {

        // 1) Ignorer 30% de la défense
        int defenceEffective = cible.getDefence() * 70 / 100;

        if (defenceEffective <= 0)
            defenceEffective = 1;

        // 2) Dégâts de base (attaque est la stat principale)
        int degats = attaque / defenceEffective;

        if (degats < 1)
            degats = 1;

        // 3) Petit hasard (entre 0 et +5)
        degats += rand() % 6;

        return degats;
    }
};