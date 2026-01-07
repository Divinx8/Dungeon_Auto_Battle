#include <iostream>
using namespace std;
#include <string>

class Archer : public Hero {
public:
    Archer(const string name, int pvInit, int att, int def, int vit, int maxPv)
        : Hero(name, pvInit, att, def, vit, maxPv) {}

    int getClasse() const override {
        return 3; 
    }

    
    bool esquive() const {
        int chance = vitesse / 4;

        if (chance > 25) // Fixer la chance à 25% pour le hero ne soit pas invincible
            chance = 25;

        return (rand() % 100) < chance;
    }

    
    int calculerDegats(const Hero& cible) const override {

        int defEff = cible.getDefence();
        if (defEff < 1)
            defEff = 1;

        
        double facteur = 0.90 + (rand() % 21) / 100.0;

        double bonus = 1.0;

        double degats =
            ((double)attaque / (double)defEff) * facteur * bonus;

        int res = (int)(degats + 0.5);
        if (res < 1)
            res = 1;

        
        if ((rand() % 100) < 20)
            res *= 2;

        return res;
    }

    
    void perdrePV(int montant) override {
        if (esquive())
            return;

        Hero::perdrePV(montant);
    }
};
