#ifndef POKEMONFEU_H
#define POKEMONFEU_H

#include "Pokemon.h"

class PokemonFeu : public Pokemon {
public:
    PokemonFeu(std::string n, int h, std::string a, int p)
        : Pokemon(n, {"Feu"}, h, a, p) {}

    int calculerDegats(Pokemon* cible) override {
        std::vector<std::string> typesCible = cible->getTypes();
        double multiplicateur = 1.0;
        for (const std::string& type : typesCible) {
            if (type == "Plante" || type == "Glace" || type == "Insecte" || type == "Acier" || type == "Fée") {
                multiplicateur *= 2.0;
            } else if (type == "Eau" || type == "Roche" || type == "Sol") {
                multiplicateur *= 0.5;
            }
        }
        return static_cast<int>(puissance * multiplicateur);
    }
    void interagir() const override {
    std::cout << nom << " a les narines qui fument \n";
}

};

#endif
