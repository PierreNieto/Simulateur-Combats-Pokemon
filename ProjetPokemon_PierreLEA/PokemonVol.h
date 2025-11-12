
#ifndef POKEMONVOL_H
#define POKEMONVOL_H

#include "Pokemon.h"

class PokemonVol : public Pokemon {
public:
    PokemonVol(std::string n, int h, std::string a, int p)
        : Pokemon(n, {"Vol"}, h, a, p) {}

    int calculerDegats(Pokemon* cible) override {
        double multiplicateur = 1.0;
        for (const std::string& type : cible->getTypes()) {
            // Implémenter les faiblesses/résistances ici si nécessaire
        }
        return static_cast<int>(puissance * multiplicateur);
    }
    void interagir() const override {
    std::cout << nom << " vol de ses propres ailes\n";
}

};

#endif
