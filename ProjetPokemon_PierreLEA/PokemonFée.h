
#ifndef POKEMONFEE_H
#define POKEMONFEE_H

#include "Pokemon.h"

class PokemonFée : public Pokemon {
public:
    PokemonFée(std::string n, int h, std::string a, int p)
        : Pokemon(n, {"Fée"}, h, a, p) {}

    int calculerDegats(Pokemon* cible) override {
        double multiplicateur = 1.0;
        for (const std::string& type : cible->getTypes()) {
            // Implémenter les faiblesses/résistances ici si nécessaire
        }
        return static_cast<int>(puissance * multiplicateur);
    }
    void interagir() const override {
    std::cout << nom << "est très féérique\n";
}

};

#endif
