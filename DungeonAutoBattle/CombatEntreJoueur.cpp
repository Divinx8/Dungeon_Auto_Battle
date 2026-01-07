#include <vector>
#include <iostream>
using namespace std;

void combatEquipes(vector<Hero*>& equipe1, vector<Hero*>& equipe2) {

    cout << "=== Combat d'equipes ===" << endl;

    int i = 0;
    int j = 0;

    // Tant qu'il reste des héros vivants dans chaque équipe
    while (i < equipe1.size() && j < equipe2.size()) {

        Hero& h1 = *equipe1[i];
        Hero& h2 = *equipe2[j];

        cout << "------ Nouveau duel ---------" << endl;
        cout << "Equipe 1: " << h1.getNom() << endl;
        cout << "Equipe 2: " << h2.getNom() << endl;

        combatEntreDeuxHeros(h1, h2);

        // Si h1 est mort, on passe au héros suivant
        if (h1.getPV() == 0) {
            cout << h1.getNom() << " est elimine !" << endl;
            i++;
        }

        // Si h2 est mort, on passe au héros suivant
        if (h2.getPV() == 0) {
            cout << h2.getNom() << " est elimine !" << endl;
            j++;
        }
    }

    cout << "\n=== Fin du combat d'equipes ===" << endl;

    if (i == equipe1.size())
        cout << "Equipe 2 gagne !" << endl;
    else
        cout << "Equipe 1 gagne !" << endl;
}