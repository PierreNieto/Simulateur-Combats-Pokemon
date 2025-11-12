#ifndef POKEMONPLANTE_H
#define POKEMONPLANTE_H

#include "Pokemon.h"

class PokemonPlante : public Pokemon {
public:
    PokemonPlante(std::string n, int h, std::string a, int p)
        : Pokemon(n, {"Plante"}, h, a, p) {}

    int calculerDegats(Pokemon* cible) override {
        std::vector<std::string> typesCible = cible->getTypes();
        double multiplicateur = 1.0;
        for (const std::string& type : typesCible) {
            if (type == "Eau" || type == "Sol" || type == "Roche") {
                multiplicateur *= 2.0;
            } else if (type == "Feu" || type == "Glace" || type == "Poison" || type == "Vol" || type == "Insecte") {
                multiplicateur *= 0.5;
            }
        }
        return static_cast<int>(puissance * multiplicateur);
    }
    void interagir() const override {
    std::cout << nom << " bouge ses feuilles !\n";
}

};

#endif
