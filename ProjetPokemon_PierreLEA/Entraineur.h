#ifndef ENTRAINEUR_H
#define ENTRAINEUR_H

#include <string>
#include <vector>
#include <iostream>
#include "Pokemon.h"
#include "Interagir.h"

class Entraineur : public Interagir {
protected:
    std::string nom;
    std::vector<Pokemon*> equipe;

public:
    Entraineur(std::string n) : nom(n) {}
    virtual ~Entraineur() {
        for (auto p : equipe) delete p;
    }

    std::string getNom() const { return nom; }

    void ajouterPokemon(Pokemon* p) {
    if (equipe.size() < 6) {
        p->setOwner(this); // lie le Pokémon à son dresseur
        equipe.push_back(p);
    	}
	}
	
    std::vector<Pokemon*>& getEquipe() { return equipe; }

    void afficherEquipe() const {
        std::cout << "Équipe de " << nom << " :\n";
        for (size_t i = 0; i < equipe.size(); ++i) {
            std::cout << i + 1 << ". ";
            equipe[i]->afficher();
        }
    }

    std::vector<Pokemon*> getEquipeVivante() const {
        std::vector<Pokemon*> vivants;
        for (auto* p : equipe) {
            if (p->getHP() > 0) {
                vivants.push_back(p);
            }
        }
        return vivants;
    }

    void soignerEquipe() {
    for (auto* p : equipe) {
        if (p->getHP() <= 0) {
            std::cout << p->getNom() << " est réanimé !\n";
        }
        p->setHP(100); // réanime + soigne
    	}
	}


    void changerOrdre(int i, int j) {
        if (i >= 0 && j >= 0 && i < equipe.size() && j < equipe.size()) {
            std::swap(equipe[i], equipe[j]);
        }
    }

    virtual void interagir() override = 0;
};

#endif
