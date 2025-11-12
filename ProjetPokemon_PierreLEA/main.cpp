
#include "IncludesGlobaux.h"

// Ajoute ici les fonctions chargerLeadersDepuisCSV et chargerMaitresDepuisCSV...
// [Fonctions supprimées ici pour compacité mais incluses dans le fichier]

int main() {
	srand(time(NULL)); // initialise le générateur de nombres aléatoires
    const std::string basePath = "./";
    auto pokedex = chargerPokemonDepuisCSV(basePath + "pokemon.csv");
    Joueur* joueur = chargerJoueurDepuisCSV(basePath + "joueur.csv", pokedex);
    auto leaders = chargerLeadersDepuisCSV(basePath + "leaders.csv", pokedex);
    auto maitres = chargerMaitresDepuisCSV(basePath + "maitres.csv", pokedex);

    std::vector<Entraineur*> vaincus;
    int choix = -1;
    while (choix != 0) {
        std::cout << "\n+++ MENU +++\n";
        std::cout << "1. Afficher l'équipe\n";
        std::cout << "2. Soigner l'équipe\n";
        std::cout << "3. Changer l'ordre des Pokémons\n";
        std::cout << "4. Statistiques\n";
        std::cout << "5. Affronter un leader\n";
        std::cout << "6. Affronter un Maître\n";
        std::cout << "7. MENU INTERACTION \n";
        std::cout << "8. Redémarrer le jeu\n";
        std::cout << "0. Quitter\n";
        std::cout << "Choix : ";
        std::cin >> choix;

        switch (choix) {
            case 1:
                joueur->afficherEquipe(); break;
            case 2:
                joueur->soignerEquipe(); std::cout << "Équipe soignée.\n"; break;
            case 3: {
                int i, j; joueur->afficherEquipe();
                std::cout << "Entrez deux indices à échanger (1-6) : ";
                std::cin >> i >> j;
                joueur->changerOrdre(i - 1, j - 1); break;
            }
            case 4:
                joueur->afficherStats(); break;
            case 5: {
                std::cout << "\nLeaders disponibles :\n";
                for (size_t k = 0; k < leaders.size(); ++k)
                    std::cout << k + 1 << ". " << leaders[k]->getNom()
                              << " - Gymnase " << leaders[k]->getGymnase() << "\n";
                int choixLeader; std::cout << "Choix du leader : ";
                std::cin >> choixLeader;
                if (choixLeader >= 1 && choixLeader <= (int)leaders.size()) {
                    auto* leader = leaders[choixLeader - 1];
                    Combat::lancerCombat(joueur, leader);
                    if (leader->getEquipeVivante().empty()) {
                        joueur->ajouterBadge(); joueur->enregistrerVictoire(); vaincus.push_back(leader);
                    } else joueur->enregistrerDefaite();
                }
                break;
            }
            case 6: {
                if (joueur->getEquipe().size() < 6) {
                    std::cout << "Tu dois avoir 6 Pokémon et tous les badges pour défier un Maître !\n"; break;
                }
                if (joueur->getNbBadges() < leaders.size()) {
    				std::cout << "Tu dois obtenir tous les badges avant de défier un Maître Pokémon !\n";
    				break;
				}
                if (maitres.empty()) { std::cout << "Aucun Maître disponible.\n"; break; }
                auto* maitre = maitres[rand() % maitres.size()];
                Combat::lancerCombat(joueur, maitre, true);
                if (maitre->getEquipe().empty()) {
                    joueur->enregistrerVictoire(); vaincus.push_back(maitre);
                } else joueur->enregistrerDefaite();
                break;
            }
           case 7: {
    			std::cout << "\nMENU INTERACTION\n";
    			std::cout << "1. Interagir avec un entraîneur vaincu\n";
    			std::cout << "2. Interagir avec un de mes Pokémon\n";
    			std::cout << "Choix : ";
    			int choixInter;
    			std::cin >> choixInter;

    			if (choixInter == 1) {
       				if (vaincus.empty()) {
            		std::cout << "Aucun entraîneur vaincu pour le moment.\n";
            		break;
        		}
        		std::cout << "Choisis un entraîneur avec qui interagir :\n";
        		for (size_t i = 0; i < vaincus.size(); ++i) {
            		std::cout << i + 1 << ". " << vaincus[i]->getNom() << "\n";
        	}
        	int choixVaincu;
        	std::cin >> choixVaincu;
        	if (choixVaincu >= 1 && choixVaincu <= static_cast<int>(vaincus.size())) {
            	auto* v = vaincus[choixVaincu - 1];
            	std::cout << "Interaction avec " << v->getNom() << " :\n";
            	v->interagir();
        	} else {
            	std::cout << "Choix invalide.\n";
        	}
    	}
    	else if (choixInter == 2) {
        	const auto& equipe = joueur->getEquipe();
        	if (equipe.empty()) {
            	std::cout << "Aucun Pokémon dans l'équipe.\n";
            	break;
        	}
        	std::cout << "Choisis un Pokémon pour interagir :\n";
        	for (size_t i = 0; i < equipe.size(); ++i) {
            std::cout << i + 1 << ". " << equipe[i]->getNom() << "\n";
        	}
        	int choixPoke;
        	std::cin >> choixPoke;
        	if (choixPoke >= 1 && choixPoke <= static_cast<int>(equipe.size())) {
            	auto* p = equipe[choixPoke - 1];
            	std::cout << "Interaction avec " << p->getNom() << " :\n";
            	p->interagir();
        	} else {
            	std::cout << "Choix invalide.\n";
        	}
    	}
    	else {
        	std::cout << "Choix invalide.\n";
    	}
    	break;
	}

			case 8: {
    			std::cout << "Recompilation...\n";
    			int status = system("g++ -std=c++17 -o pokemon_simulator main.cpp chargement.cpp");
    			if (status == 0) {
       				std::cout << "✅ Compilation réussie ! Redémarrage du jeu...\n";
        			system("./pokemon_simulator"); // relance le programme à neuf
       				exit(0); // termine le processus courant
    			} else {
        			std::cout << "❌ Erreur de compilation.\n";
    			}
    			break;
			}

			case 0: std::cout << "Au revoir, Dresseur !\n"; break;
            default: std::cout << "Option invalide.\n";
        }
    }

    delete joueur;
    for (auto& p : pokedex) delete p.second;
    for (auto* l : leaders) delete l;
    for (auto* m : maitres) delete m;
    return 0;
}
