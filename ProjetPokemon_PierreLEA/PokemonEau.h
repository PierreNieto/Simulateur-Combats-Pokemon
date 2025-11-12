#ifndef POKEMONEAU_H
#define POKEMONEAU_H

#include "Pokemon.h"

class PokemonEau : public Pokemon {
public:
    PokemonEau(std::string n, int h, std::string a, int p)
        : Pokemon(n, {"Eau"}, h, a, p) {}

    int calculerDegats(Pokemon* cible) override {
        std::vector<std::string> typesCible = cible->getTypes();
        double multiplicateur = 1.0;
        for (const std::string& type : typesCible) {
            if (type == "Feu" || type == "Sol" || type == "Roche") {
                multiplicateur *= 2.0;
            } else if (type == "Plante" || type == "Électrik") {
                multiplicateur *= 0.5;
            }
        }
        return static_cast<int>(puissance * multiplicateur);
    }
    void interagir() const override {
    std::cout << nom << " fait jaillir un jet d'eau !\n";
}
};

#endif
