
#ifndef POKEMONCOMBAT_H
#define POKEMONCOMBAT_H

#include "Pokemon.h"

class PokemonCombat : public Pokemon {
public:
    PokemonCombat(std::string n, int h, std::string a, int p)
        : Pokemon(n, {"Combat"}, h, a, p) {}

    int calculerDegats(Pokemon* cible) override {
        double multiplicateur = 1.0;
        for (const std::string& type : cible->getTypes()) {
            // Implémenter les faiblesses/résistances ici si nécessaire
        }
        return static_cast<int>(puissance * multiplicateur);
    }
    void interagir() const override {
    std::cout << nom << " est un vrai judoka\n";
}

};

#endif
