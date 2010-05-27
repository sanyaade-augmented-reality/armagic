#include "CreatureCard.h"

using std::string;

CreatureCard::CreatureCard(const std::string& name, const int attack, const int defense) {
	name_ = name;
	attack_ = attack;
	defense_ = defense;
}

CreatureCard::~CreatureCard() {

}