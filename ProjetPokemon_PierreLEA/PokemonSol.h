
#ifndef POKEMONSOL_H
#define POKEMONSOL_H

#include "Pokemon.h"

class PokemonSol : public Pokemon {
public:
    PokemonSol(std::string n, int h, std::string a, int p)
        : Pokemon(n, {"Sol"}, h, a, p) {}

    int calculerDegats(Pokemon* cible) override {
        double multiplicateur = 1.0;
        for (const std::string& type : cible->getTypes()) {
            // Implémenter les faiblesses/résistances ici si nécessaire
        }
        return static_cast<int>(puissance * multiplicateur);
    }
    void interagir() const override {
    std::cout << nom << " semble très poussiereux \n";
}

};

#endif
