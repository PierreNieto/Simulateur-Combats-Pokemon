
#ifndef INCLUDES_GLOBAUX_H
#define INCLUDES_GLOBAUX_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Pokemon.h"
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
#include "PokemonPersonnalise.h"

#include "Entraineur.h"
#include "Joueur.h"
#include "LeaderGym.h"
#include "MaitrePokemon.h"
#include "Combat.h"
#include "PokemonFactory.h"
#include "Interagir.h"


#endif


Pokemon* creerPokemonDepuisLigne(const std::string& ligne);
Pokemon* clonerPokemon(Pokemon* original);
std::map<std::string, Pokemon*> chargerPokemonDepuisCSV(const std::string& chemin);
Joueur* chargerJoueurDepuisCSV(const std::string& chemin, const std::map<std::string, Pokemon*>& pokedex);
std::vector<LeaderGym*> chargerLeadersDepuisCSV(const std::string& chemin, const std::map<std::string, Pokemon*>& pokedex);
std::vector<MaitrePokemon*> chargerMaitresDepuisCSV(const std::string& chemin, const std::map<std::string, Pokemon*>& pokedex);
