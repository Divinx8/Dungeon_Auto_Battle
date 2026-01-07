#include <iostream>
#include <vector>
#include <ctime>

#include "Hero.h"
#include "Mage.h"
#include "Archer.h"
#include "Guerrier.h" 

using namespace std;

// Déclarations (si elles sont dans un autre fichier .cpp)


int main() {
    // Initialisation du générateur aléatoire
    srand((unsigned)time(nullptr));

    // ===== Création des héros =====
    Guerrier g1("Gandalf");
    g1.afficherStats();
    
    return 0;
}
