
#ifndef POKEMONGLACE_H
#define POKEMONGLACE_H

#include "Pokemon.h"

class PokemonGlace : public Pokemon {
public:
    PokemonGlace(std::string n, int h, std::string a, int p)
        : Pokemon(n, {"Glace"}, h, a, p) {}

    int calculerDegats(Pokemon* cible) override {
        double multiplicateur = 1.0;
        for (const std::string& type : cible->getTypes()) {
            // Implémenter les faiblesses/résistances ici si nécessaire
        }
        return static_cast<int>(puissance * multiplicateur);
    }
    void interagir() const override {
    std::cout << nom << " est frileux\n";
}

};

#endif
