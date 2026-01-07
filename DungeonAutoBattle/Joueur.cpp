#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
class Joueur{
    private:
    string nom;
    Hero* equipe[6];  // Max 6 hero
    int nbHero;
    //Constructeur 
    public :
    Joueur(string n): nom(n),nbHero(0){

        for (int i=0;i<6;i++) equipe[i]=nullptr;
            
    }

    // Destructeur 
    ~Joueur(){
        for(int i=0; i<=nbHero; i++) {
            delete equipe[i]; // liberer chaque héros
            equipe[i]=nullptr; 
        }
       cout << "Joueur " << nom << " détruit\n";
    }
    // Ajouter un joueur dans un equipe
void  ajouterHero(Hero* h){
    if (nbHeros<6){
        equipe[nbHero++]=h;
    }
};
//Generer aleatoirement un héro 
*Hero genererHeroAleatoire(){
    string noms[]={"Moussa","Divin","Jean","Dupon","Robert","Martin"};
    string nom=noms[rand() % 6];
    int classe = rand()%3 +1;
    switch(classe){
        case 1:return new Guerrier(nom);
        case 2:return new Mage(nom);
        case 3:return new Archer(nom);

    }
    return nullptr;
}
// Creer une equipe
void SelectinnerEquipe(){
    for(int i=0;i<6,i++){
        ajouterHero(genererHeroAleatoire());
    }
}
// Veeifier qu'un héro est vivant
bool HeroVivants() const {
    for(int i=0;i<nbHero;i++){
        if ( equipe[i]&&equipe[i]->estvivant()) return true; // Eviter un pointeur null
    }
    return false;
}
}
Hero* getHero(int index ) const {
    if (index>=0 && index <nbHero) return equipe[index];
    return nullptr;


}