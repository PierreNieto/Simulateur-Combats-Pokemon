
#ifndef POKEMONNORMAL_H
#define POKEMONNORMAL_H

#include "Pokemon.h"

class PokemonNormal : public Pokemon {
public:
    PokemonNormal(std::string n, int h, std::string a, int p)
        : Pokemon(n, {"Normal"}, h, a, p) {}

    int calculerDegats(Pokemon* cible) override {
        double multiplicateur = 1.0;
        for (const std::string& type : cible->getTypes()) {
            // Implémenter les faiblesses/résistances ici si nécessaire
        }
        return static_cast<int>(puissance * multiplicateur);
    }
    void interagir() const override {
    std::cout << nom << "est simple, basic\n";
}

};

#endif
