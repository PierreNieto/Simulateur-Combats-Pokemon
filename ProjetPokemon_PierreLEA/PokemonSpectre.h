
#ifndef POKEMONSPECTRE_H
#define POKEMONSPECTRE_H

#include "Pokemon.h"

class PokemonSpectre : public Pokemon {
public:
    PokemonSpectre(std::string n, int h, std::string a, int p)
        : Pokemon(n, {"Spectre"}, h, a, p) {}

    int calculerDegats(Pokemon* cible) override {
        double multiplicateur = 1.0;
        for (const std::string& type : cible->getTypes()) {
            // Implémenter les faiblesses/résistances ici si nécessaire
        }
        return static_cast<int>(puissance * multiplicateur);
    }
    void interagir() const override {
    std::cout << nom << " émet une aura spectrale!\n";
}

};

#endif
