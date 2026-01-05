#include <iostream>
using namespace std;
#include <string>
#include "Hero.h"

class Guerrier:public Hero{

 //Contructeur de la classe Guerrier 
    public :
    Guerrier(string n)
     : Hero (n,90,60,80,50){} // Stats orienté defence
     int getClasse() const override{
        return 1;
    }


    //Calculer les degats 
    int calculerDegats(const Hero& cible) const override;
 
    int Guerrier::calculerDegats(const Hero& cible)const{
        int base =(attaque/max(1,cible.getDefence()))*0.9;
        double bonus=1.0;

        //+20% de degats si pv<30   %
        if (getPV<PvMax*0.3){
                bonus=1.2;
            cout << nom << " entre en rage ! (+20%)" <<endl;

        }
        int res=(base*bonus)
        return res;
    }

  
    //La methode getClass 
    int getClass() const{
        return 1;
    }


  
}