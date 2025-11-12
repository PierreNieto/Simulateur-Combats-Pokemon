#include "IncludesGlobaux.h"

std::map<std::string, Pokemon*> chargerPokemonDepuisCSV(const std::string& chemin) {
    std::map<std::string, Pokemon*> pokedex;
    std::ifstream fichier(chemin);
    std::string ligne;
    std::getline(fichier, ligne);
    while (std::getline(fichier, ligne)) {
        Pokemon* p = creerPokemonDepuisLigne(ligne);
        if (p != nullptr) {
            pokedex[p->getNom()] = p;
        }
    }
    return pokedex;
}

Joueur* chargerJoueurDepuisCSV(const std::string& chemin, const std::map<std::string, Pokemon*>& pokedex) {
    std::ifstream fichier(chemin);
    std::string ligne;
    std::getline(fichier, ligne); // entête
    if (std::getline(fichier, ligne)) {
        std::stringstream ss(ligne);
        std::string nom;
        std::getline(ss, nom, ',');

        Joueur* joueur = new Joueur(nom);
        std::string pnom;
        while (std::getline(ss, pnom, ',')) {
            if (pokedex.count(pnom)) {
                joueur->ajouterPokemon(clonerPokemon(pokedex.at(pnom)));
            }
        }
        return joueur;
    }
    return nullptr;
}

std::vector<LeaderGym*> chargerLeadersDepuisCSV(const std::string& chemin, const std::map<std::string, Pokemon*>& pokedex) {
    std::ifstream fichier(chemin);
    std::string ligne;
    std::getline(fichier, ligne);
    std::vector<LeaderGym*> leaders;

    while (std::getline(fichier, ligne)) {
        std::stringstream ss(ligne);
        std::string nom, badge, gym, liste, message;
        std::getline(ss, nom, ',');
        std::getline(ss, badge, ',');
        std::getline(ss, gym, ',');
        std::getline(ss, liste, ',');
        std::getline(ss, message, ',');

        LeaderGym* l = new LeaderGym(nom, badge, gym, message);
        std::stringstream pokemons(liste);
        std::string pnom;
        while (std::getline(pokemons, pnom, ';')) {
            if (pokedex.count(pnom)) {
                l->ajouterPokemon(clonerPokemon(pokedex.at(pnom)));
            }
        }
        leaders.push_back(l);
    }
    return leaders;
}

std::vector<MaitrePokemon*> chargerMaitresDepuisCSV(const std::string& chemin, const std::map<std::string, Pokemon*>& pokedex) {
    std::ifstream fichier(chemin);
    std::string ligne;
    std::getline(fichier, ligne);
    std::vector<MaitrePokemon*> maitres;

    while (std::getline(fichier, ligne)) {
        std::stringstream ss(ligne);
        std::string nom, liste;
        std::getline(ss, nom, ',');
        std::getline(ss, liste, ',');

        MaitrePokemon* m = new MaitrePokemon(nom);
        std::stringstream pokemons(liste);
        std::string pnom;
        while (std::getline(pokemons, pnom, ';')) {
            if (pokedex.count(pnom)) {
                m->ajouterPokemon(clonerPokemon(pokedex.at(pnom)));
            }
        }
        maitres.push_back(m);
    }
    return maitres;
}
