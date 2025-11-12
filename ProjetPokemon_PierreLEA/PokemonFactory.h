#ifndef POKEMONFACTORY_H
#define POKEMONFACTORY_H

#include "PokemonFeu.h"
#include "PokemonEau.h"
#include "PokemonPlante.h"
#include "PokemonPsy.h"
#include "PokemonAcier.h"
#include "PokemonCombat.h"
#include "PokemonDragon.h"
#include "PokemonFée.h"
#include "PokemonGlace.h"
#include "PokemonInsecte.h"
#include "PokemonNormal.h"
#include "PokemonPoison.h"
#include "PokemonRoche.h"
#include "PokemonSol.h"
#include "PokemonSpectre.h"
#include "PokemonVol.h"
#include "PokemonÉlectrik.h"
#include <sstream>

inline Pokemon* creerPokemonDepuisLigne(const std::string& ligne) {
    std::stringstream ss(ligne);
    std::string nom, type1, type2, hpStr, attaque, puissanceStr;

    std::getline(ss, nom, ',');
    std::getline(ss, type1, ',');
    std::getline(ss, type2, ',');
    std::getline(ss, hpStr, ',');
    std::getline(ss, attaque, ',');
    std::getline(ss, puissanceStr, ',');

    int hp = std::stoi(hpStr);
    int puissance = std::stoi(puissanceStr);

    std::vector<std::string> types;
	types.push_back(type1);
	if (!type2.empty()) types.push_back(type2);

	if (type1 == "Feu") return new PokemonFeu(nom, hp, attaque, puissance);
	if (type1 == "Eau") return new PokemonEau(nom, hp, attaque, puissance);
	if (type1 == "Plante") return new PokemonPlante(nom, hp, attaque, puissance);
	if (type1 == "Psy") return new PokemonPsy(nom, hp, attaque, puissance);
	if (type1 == "Acier") return new PokemonAcier(nom, hp, attaque, puissance);
	if (type1 == "Combat") return new PokemonCombat(nom, hp, attaque, puissance);
	if (type1 == "Dragon") return new PokemonDragon(nom, hp, attaque, puissance);
	if (type1 == "Fée") return new PokemonFée(nom, hp, attaque, puissance);
	if (type1 == "Glace") return new PokemonGlace(nom, hp, attaque, puissance);
	if (type1 == "Insecte") return new PokemonInsecte(nom, hp, attaque, puissance);
	if (type1 == "Normal") return new PokemonNormal(nom, hp, attaque, puissance);
	if (type1 == "Poison") return new PokemonPoison(nom, hp, attaque, puissance);
	if (type1 == "Roche") return new PokemonRoche(nom, hp, attaque, puissance);
	if (type1 == "Sol") return new PokemonSol(nom, hp, attaque, puissance);
	if (type1 == "Spectre") return new PokemonSpectre(nom, hp, attaque, puissance);
	if (type1 == "Vol") return new PokemonVol(nom, hp, attaque, puissance);
	if (type1 == "Électrik") return new PokemonÉlectrik(nom, hp, attaque, puissance);

	// Si le type n’est pas reconnu, fallback :
	return new PokemonPersonnalise(nom, types, hp, attaque, puissance);

}

inline Pokemon* clonerPokemon(Pokemon* original) {
    return creerPokemonDepuisLigne(
        original->getNom() + "," + original->getTypes()[0] + ",," +
        std::to_string(original->getHP()) + "," +
        original->getAttaque() + "," +
        std::to_string(original->getPuissance()));
}

#endif
