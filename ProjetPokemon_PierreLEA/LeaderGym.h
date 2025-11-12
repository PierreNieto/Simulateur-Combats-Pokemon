#ifndef LEADERGYM_H
#define LEADERGYM_H

#include "Entraineur.h"

class LeaderGym : public Entraineur {
private:
    std::string badge;
    std::string gymnase;
    std::string message;

public:
    LeaderGym(std::string n, std::string b, std::string g, std::string m)
    : Entraineur(n), badge(b), gymnase(g), message(m) {}

    std::string getBadge() const { return badge; }
    std::string getGymnase() const { return gymnase; }
	std::string getMessage() const { return message; }

    void interagir() override {
    	std::cout << nom << " (Leader du gymnase " << gymnase << ") : " << message << "\n";
		}

};

#endif
