#ifndef ARCHER_H
#define ARCHER_H

#include <string>
#include "Hero.h"

using namespace std;

class Archer : public Hero {
public:
    Archer(const string& name, int pvInit, int att, int def, int vit, int maxPv);

    int getClasse() const override;

    bool esquive() const;

    int calculerDegats(const Hero& cible) const override;

    void perdrePV(int montant) ;
};

#endif