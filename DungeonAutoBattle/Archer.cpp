#include <iostream>
using namespace std;
#include <string>
class Archer : public Hero {
public:
    Archer(string name, int pv, int att, int def, int vit, int Max)
        : Hero(name, pv, att, def, vit, Max) {}

    int getClasse() const override {
        return 3; // Archer
    }

    // Petite chance d'esquive basée sur la vitesse
    bool esquive() const {
        int chance = vitesse / 4;

        // plafond manuel à 25%
        if (chance > 25)
            chance = 25;

        return (rand() % 100) < chance;
    }

    // Dégâts simples + coup critique
    int calculerDegats(const Hero& cible) const override {
        int degats = attaque - cible.getDefence();

        if (degats < 1)
            degats = 1;

        // Coup critique fixe : 20%
        if (rand() % 100 < 20)
            degats = degats * 2;

        return degats;
    }
};
