
#ifndef POKEMONINSECTE_H
#define POKEMONINSECTE_H

#include "Pokemon.h"

class PokemonInsecte : public Pokemon {
public:
    PokemonInsecte(std::string n, int h, std::string a, int p)
        : Pokemon(n, {"Insecte"}, h, a, p) {}

    int calculerDegats(Pokemon* cible) override {
        double multiplicateur = 1.0;
        for (const std::string& type : cible->getTypes()) {
            // Implémenter les faiblesses/résistances ici si nécessaire
        }
        return static_cast<int>(puissance * multiplicateur);
    }
    void interagir() const override {
    std::cout << nom << " a 6 pattes\n";
}

};

#endif
