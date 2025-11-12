#ifndef POKEMONPERSONNALISE_H
#define POKEMONPERSONNALISE_H

#include "Pokemon.h"

class PokemonPersonnalise : public Pokemon {
public:
    PokemonPersonnalise(std::string n, std::vector<std::string> t, int h, std::string a, int p)
        : Pokemon(n, t, h, a, p) {}

    int calculerDegats(Pokemon* cible) override {
    	double multiplicateur = 1.0;
    	std::string typeAttaque = this->types[0]; // On suppose que l'attaque est du premier type du Pokémon

    	for (const std::string& typeCible : cible->getTypes()) {
        	multiplicateur *= getMultiplicateur(typeAttaque, typeCible);
    	}

    	return static_cast<int>(puissance * multiplicateur);
	}
	void interagir() const override {
    std::cout << nom << " est étonné de te voir.\n";
	}


private:
    double getMultiplicateur(const std::string& attaquant, const std::string& cible) const {
        // Faiblesses et résistances simplifiées
        if (attaquant == "Feu") {
            if (cible == "Plante" || cible == "Glace" || cible == "Insecte" || cible == "Acier" || cible == "Fée") return 2.0;
            if (cible == "Eau" || cible == "Roche" || cible == "Sol") return 0.5;
        }
        if (attaquant == "Eau") {
            if (cible == "Feu" || cible == "Sol" || cible == "Roche") return 2.0;
            if (cible == "Plante" || cible == "Électrik") return 0.5;
        }
        if (attaquant == "Plante") {
            if (cible == "Eau" || cible == "Sol" || cible == "Roche") return 2.0;
            if (cible == "Feu" || cible == "Glace" || cible == "Poison" || cible == "Vol" || cible == "Insecte") return 0.5;
        }
        if (attaquant == "Psy") {
            if (cible == "Combat" || cible == "Poison") return 2.0;
            if (cible == "Psy" || cible == "Acier") return 0.5;
            if (cible == "Ténèbres") return 0.0;
        }
        return 1.0;
    }
    
};

#endif
