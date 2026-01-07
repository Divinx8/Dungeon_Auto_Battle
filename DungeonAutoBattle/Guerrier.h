#ifndef GUERRIER_H
#define GUERRIER_H
#include "Hero.h"
#include <iostream>
#include <algorithm>

class Guerrier : public Hero {
public:
    Guerrier(string n) : Hero(n, 90, 60, 80, 50) {}
    
    int getClasse() const override {
        return 1;
    }
    
    int calculerDegats(const Hero& cible) const override {
        int base = (attaque * 15) / std::max(1, cible.getDefence());
        if (getPV() < getPvMax() * 0.3) {
            cout << nom << " RAGE! ";
            return base * 120 / 100;
        }
        return base;
    }
};

#endif



