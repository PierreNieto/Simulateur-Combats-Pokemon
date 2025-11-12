#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
#include <iostream>

class Entraineur; /// Cela informe le compilateur qu’un type nommé Entraineur existe, sans devoir inclure Entraineur.h


class Pokemon {
protected:
    std::string nom;
    std::vector<std::string> types;
    int hp;
    std::string attaque;
    int puissance;
	Entraineur* owner = nullptr; // propriétaire du Pokémon

public:
    void setOwner(Entraineur* o) { owner = o; } 
    Entraineur* getOwner() const { return owner; } // Permet d'attribuer le propriétaire au pokemon
    Pokemon(std::string n, std::vector<std::string> t, int h, std::string a, int p)
        : nom(n), types(t), hp(h), attaque(a), puissance(p) {}

    virtual ~Pokemon() {}
	
	virtual void interagir() const = 0;

    std::string getNom() const { return nom; }
    int getHP() const { return hp; }
    void setHP(int h) { hp = h; }

    virtual int calculerDegats(Pokemon* cible) = 0;
    void recevoirDegats(int degats) {
        hp -= degats;
        if (hp < 0) hp = 0;
    }

    virtual void afficher() const {
        std::cout << nom << " [";
        for (size_t i = 0; i < types.size(); ++i) {
            std::cout << types[i];
            if (i < types.size() - 1) std::cout << "/";
        }
        std::cout << "] - HP: " << hp << " - Attaque: " << attaque << " (" << puissance << ")" << std::endl;
    }

    std::vector<std::string> getTypes() const { return types; }
    std::string getAttaque() const { return attaque; }
    int getPuissance() const { return puissance; }
};

#endif
