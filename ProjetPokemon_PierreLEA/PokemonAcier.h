
#ifndef POKEMONACIER_H
#define POKEMONACIER_H

#include "Pokemon.h"

class PokemonAcier : public Pokemon {
public:
    PokemonAcier(std::string n, int h, std::string a, int p)
        : Pokemon(n, {"Acier"}, h, a, p) {}

    int calculerDegats(Pokemon* cible) override {
        double multiplicateur = 1.0;
        for (const std::string& type : cible->getTypes()) {
            // Implémenter les faiblesses/résistances ici si nécessaire
        }
        return static_cast<int>(puissance * multiplicateur);
    }
    void interagir() const override {
    std::cout << nom << " est dur comme fer\n";
}

};

#endif
