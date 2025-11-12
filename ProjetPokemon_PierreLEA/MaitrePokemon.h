#ifndef MAITREPOKEMON_H
#define MAITREPOKEMON_H

#include "Entraineur.h"

class MaitrePokemon : public Entraineur {
public:
    MaitrePokemon(std::string n) : Entraineur(n) {}

    void interagir() override {
        std::cout << nom << " (Maître Pokémon) : Tu as obtenu tous les badges ? Montre-moi ta vraie force.\n";
    }

    static int appliquerBonus(int degats) {
        return static_cast<int>(degats * 1.25);
    }
};

#endif
