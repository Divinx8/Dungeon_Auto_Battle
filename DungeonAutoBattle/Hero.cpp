#include <iostream>
using namespace std;
#include <string>

// definition de la classe hero
class Hero {
    //attributs
    protected :
    string nom;
    int pv ;
    int attaque;
    int defence;
    int vitesse;
    int pvMax;
    
    //Constructeur

    public:
    Hero(string name,int pv int att,int def,int vit,int Max)
    : nom(name),pvMax(pv),attaque(att),defence(def),vitesse(vit),pvMax(max)

    //destructeur
    virtual ~Hero(){}


  
     // Méthodes virtuelles
    virtual void afficherStats() const;
    virtual void perdrePV(int montant);
    virtual void effetDebutTour() {}
    virtual void effetFinTour() {}

    // Afficher les stats
    void Hero::afficherStats()const{
        cout << " Nom : "<< nom <<" Pv: "<< pv <<" Attaque: "
        << attaque <<" Defence : " <<defence <<" Vitesse : " 
        << vitesse <<endl

    };
  
    virtual int getClasse() const=0;
    //virtual int calculeDegat(Const Hero& cible);

    // Perte de PV 
    void perdrePV(int montant) {
        pv -= montant;
        if (pv < 0)
            pv = 0;
        };

   //les getters
   int getPV() const{
    return pv;
   }
   int getDefence() const{
    return defence;
   }
   int geteVitesse(){
    return vitesse;
   }
   string getNom(){
    return nom;
   }
   int getpvMax(){
    return pvMax;
   }

   //Reinitialiser les PV aprés un combat 
   void resetPV() {
    //pv=pvMax
   }

    void void effetDebutTour();
    void void effetFinTour();


}