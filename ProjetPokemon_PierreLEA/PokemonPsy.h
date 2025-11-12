#ifndef POKEMONPSY_H
#define POKEMONPSY_H

#include "Pokemon.h"

class PokemonPsy : public Pokemon {
public:
    PokemonPsy(std::string n, int h, std::string a, int p)
        : Pokemon(n, {"Psy"}, h, a, p) {}

    int calculerDegats(Pokemon* cible) override {
        std::vector<std::string> typesCible = cible->getTypes();
        double multiplicateur = 1.0;
        for (const std::string& type : typesCible) {
            if (type == "Combat" || type == "Poison") {
                multiplicateur *= 2.0;
            } else if (type == "Psy" || type == "Acier") {
                multiplicateur *= 0.5;
            } else if (type == "Ténèbres") {
                multiplicateur *= 0.0;
            }
        }
        return static_cast<int>(puissance * multiplicateur);
    }
    void interagir() const override {
    std::cout << nom << " mentalise..\n";
}

};

#endif
