#ifndef JOUEUR_H
#define JOUEUR_H

#include "Entraineur.h"

class Joueur : public Entraineur {
private:
    int nbBadges;
    int combatsGagnes;
    int combatsPerdus;

public:
    Joueur(std::string n, int badges = 0, int g = 0, int p = 0)
        : Entraineur(n), nbBadges(badges), combatsGagnes(g), combatsPerdus(p) {}

    void ajouterBadge() { nbBadges++; }
    void enregistrerVictoire() { combatsGagnes++; }
    void enregistrerDefaite() { combatsPerdus++; }

    void afficherStats() const {
        std::cout << "Badges : " << nbBadges
                  << ", Victoires : " << combatsGagnes
                  << ", Défaites : " << combatsPerdus << "\n";
    }
	int getNbBadges() const {
    	return nbBadges;
	}

    void interagir() override {
        std::cout << nom << " dit : Je suis prêt pour le prochain combat !\n";
    }
};

#endif
