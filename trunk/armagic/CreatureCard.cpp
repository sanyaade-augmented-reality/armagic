#include "CreatureCard.h"

using std::string;

CreatureCard::CreatureCard(const std::string& name, const int attack, const int defense, const int colorlessCost, const int colorCost)
{
	name_ = name;
	attack_ = attack;
	defense_ = defense;
	colorlessCost_ = colorlessCost;
	colorCost_ = colorCost;
}

CreatureCard::~CreatureCard() {

}