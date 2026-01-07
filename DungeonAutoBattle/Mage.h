using namespace std;

class Mage : public Hero {
public:
    Mage(const string& name, int pvInit, int att, int def, int vit, int maxPv);

    int getClasse() const override;

    int calculerDegats(const Hero& cible) const override;
};
