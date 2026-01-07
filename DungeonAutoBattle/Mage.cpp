class Mage : public Hero {
public:
    Mage(const string& nom, int pvInit, int att, int def, int vit, int maxPv)
        : Hero(name, pvInit, att, def, vit, maxPv) {}

    int getClasse() const override {
        return 2; // Mage
    }

    int calculerDegats(const Hero& cible) const override {

        
        int defEff = (cible.getDefence() * 70) / 100;

    
        if (defEff < 1)
            defEff = 1;

        
        
        double facteur = 0.70 + (rand() % 61) / 100.0;

        
        double bonus = 1.0;

        
        double degats =
            ((double)attaque / (double)defEff) * facteur * bonus;

        
        int res = (int)(degats + 0.5);

        if (res < 1)
            res = 1;

        return res;
    }
};