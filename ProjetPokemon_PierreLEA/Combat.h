#ifndef COMBAT_H
#define COMBAT_H

#include "Entraineur.h"
#include "MaitrePokemon.h"
#include <thread>
#include <chrono>
#include <limits>

class Combat {
public:
    static void lancerCombat(Entraineur* joueur, Entraineur* adversaire, bool contreMaitre = false) {
        std::cout << "Début du combat entre " << joueur->getNom() << " et " << adversaire->getNom() << "\n";

        auto& eqJoueur = joueur->getEquipe();
        auto& eqAdversaire = adversaire->getEquipe();

        int i = choisirPremierPokemon(joueur);
        int j = 0;
        bool joueurCommence = true;

        while (i < (int)eqJoueur.size() && j < (int)eqAdversaire.size()) {
            Pokemon* pJoueur = eqJoueur[i];
            Pokemon* pAdv = eqAdversaire[j];

            std::cout << "\n" << joueur->getNom() << " envoie " << pJoueur->getNom() << "!\n";
            std::cout << adversaire->getNom() << " envoie " << pAdv->getNom() << "!\n";

            while (pJoueur->getHP() > 0 && pAdv->getHP() > 0) {
                if (joueurCommence) {
                    if (attaque(pJoueur, pAdv, contreMaitre)) break;
                    if (attaque(pAdv, pJoueur, contreMaitre)) break;
                } else {
                    if (attaque(pAdv, pJoueur, contreMaitre)) break;
                    if (attaque(pJoueur, pAdv, contreMaitre)) break;
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(600));
            }

            if (pJoueur->getHP() == 0) {
                std::cout << pJoueur->getNom() << " est K.O.!\n";
                if (joueur->getEquipeVivante().empty()) break;
                i = choisirProchainPokemon(joueur);
                joueurCommence = false;
            }

            if (pAdv->getHP() == 0) {
                std::cout << pAdv->getNom() << " est K.O.!\n";
                ++j;
                if (adversaire->getEquipeVivante().empty()) break;
                joueurCommence = true;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(800));
        }

        if (i >= (int)eqJoueur.size() || joueur->getEquipeVivante().empty()) {
            std::cout << joueur->getNom() << " a perdu le combat...\n";
            for (auto* p : eqJoueur) {
    			p->setHP(0); // tous KO, mais pas supprimés 
    			}
        } else {
    	std::cout << adversaire->getNom() << " a perdu le combat !\n";

    	if (contreMaitre) {
        	std::cout << "🎉 Félicitations ! Vous avez remporté la Ligue Pokémon ! 👑\n";
        	int choixFin;
        	do {
            	std::cout << "\nQue voulez-vous faire ?\n";
            	std::cout << "1. Rejouer (Recompiler et redémarrer le jeu)\n";
            	std::cout << "0. Quitter\n";
            	std::cout << "Choix : ";
            	std::cin >> choixFin;
            	if (choixFin == 1) {
                	std::cout << "🔄 Recompilation...\n";
                	int status = system("g++ -std=c++17 -o pokemon_simulator main.cpp chargement.cpp");
                	if (status == 0) {
                    	std::cout << "✅ Compilation réussie ! Redémarrage du jeu...\n";
                    	system("./pokemon_simulator");
                	} else {
                    	std::cout << "❌ Erreur de compilation. Le jeu ne redémarrera pas.\n";
                	}
                	exit(0);
            	} else if (choixFin == 0) {
                	std::cout << "À bientôt, Maître Pokémon !\n";
                	exit(0);
            	} else {
                	std::cout << "Choix invalide.\n";
            	}
        	} while (true);
    	}

    	for (auto* p : eqAdversaire) {
        	p->setHP(0); // KO les Pokémon du maître (si tu veux aussi les neutraliser)
    	}
	}
}

private:
    static bool attaque(Pokemon* attaquant, Pokemon* cible, bool contreMaitre) {
        int degats = attaquant->calculerDegats(cible);
        if (contreMaitre && dynamic_cast<MaitrePokemon*>(attaquant->getOwner()) != nullptr)
    		degats = MaitrePokemon::appliquerBonus(degats); /// applique le bonus uniquement si l'attaquant est un adversaire(et non le joueur)
        cible->recevoirDegats(degats);
        std::cout << attaquant->getNom() << " attaque " << cible->getNom()
                  << " et inflige " << degats << " dégâts. (HP: " << cible->getHP() << ")\n";
        return cible->getHP() == 0;
    }

    static int choisirPremierPokemon(Entraineur* joueur) {
        joueur->afficherEquipe();
        std::cout << "Quel Pokémon veux-tu envoyer en premier ? (1-" << joueur->getEquipe().size() << "): ";
        int choix;
        std::cin >> choix;
        while (choix < 1 || choix > (int)joueur->getEquipe().size() || joueur->getEquipe()[choix - 1]->getHP() <= 0) {
            std::cout << "Choix invalide. Réessaie : ";
            std::cin >> choix;
        }
        return choix - 1;
    }

    static int choisirProchainPokemon(Entraineur* joueur) {
        while (true) {
            std::cout << "\nChoisis le prochain Pokémon à envoyer :\n";
            joueur->afficherEquipe();
            int choix;
            std::cin >> choix;
            if (choix >= 1 && choix <= (int)joueur->getEquipe().size()
                && joueur->getEquipe()[choix - 1]->getHP() > 0) {
                return choix - 1;
            }
            std::cout << "Choix invalide ou Pokémon K.O. !\n";
        }
    }
};

#endif
