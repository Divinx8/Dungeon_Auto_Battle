#ifndef HERO_H
#define HERO_H
#include <iostream>
#include <string>
using namespace std;

class Hero {
protected:
    string nom;
    int pv;
    int attaque;
    int defence;
    int vitesse;
    int pvMax;

public:
    Hero(string name, int pvInit, int att, int def, int vit)
        : nom(name), pv(pvInit), attaque(att), defence(def), vitesse(vit), pvMax(pvInit) {}
    
    virtual ~Hero() = default;
    
    virtual int getClasse() const = 0;
    virtual int calculerDegats(const Hero& cible) const = 0;
    
    void afficherStats() const {
        cout << "Nom : " << nom << " | PV: " << pv << "/" << pvMax 
             << " | ATK: " << attaque << " | DEF: " << defence 
             << " | VIT: " << vitesse << endl;
    }
    
    void perdrePV(int montant) {
        pv -= montant;
        if (pv < 0) pv = 0;
    }
    
    bool estVivant() const { return pv > 0; }
    
    int getPV() const { return pv; }
    int getPvMax() const { return pvMax; }
    int getDefence() const { return defence; }
    int getVitesse() const { return vitesse; }
    string getNom() const { return nom; }
};

#endif

