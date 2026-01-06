class Mage : public Hero {
public:
    Mage(const string& nom, int pvInit, int att, int def, int vit, int maxPv)
        : Hero(name, pvInit, att, def, vit, maxPv) {}

    int getClasse() const override {
        return 2; // Mage
    }

    int calculerDegats(const Hero& cible) const override {

        // 1) Défense effective : le Mage ignore 30%
        int defEff = (cible.getDefence() * 70) / 100;

        // équivalent de max(1, defEff)
        if (defEff < 1)
            defEff = 1;

        
        // facteur entre 0.70 et 1.30
        double facteur = 0.70 + (rand() % 61) / 100.0;

        // 3) Bonus de classe
        double bonus = 1.0;

        // 4) Formule officielle
        double degats =
            ((double)attaque / (double)defEff) * facteur * bonus;

        // 5) Conversion en entier
        int res = (int)(degats + 0.5);

        if (res < 1)
            res = 1;

        return res;
    }
};