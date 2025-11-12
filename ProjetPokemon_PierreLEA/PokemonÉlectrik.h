
#ifndef POKEMONELECTRIK_H
#define POKEMONELECTRIK_H

#include "Pokemon.h"

class PokemonÉlectrik : public Pokemon {
public:
    PokemonÉlectrik(std::string n, int h, std::string a, int p)
        : Pokemon(n, {"Électrik"}, h, a, p) {}

    int calculerDegats(Pokemon* cible) override {
        double multiplicateur = 1.0;
        for (const std::string& type : cible->getTypes()) {
            // Implémenter les faiblesses/résistances ici si nécessaire
        }
        return static_cast<int>(puissance * multiplicateur);
    }
    void interagir() const override {
    std::cout << nom << " est plein de tension\n";
}

};

#endif
