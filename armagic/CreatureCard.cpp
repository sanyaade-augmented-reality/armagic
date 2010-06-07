#include "CreatureCard.h"

using std::string;

CreatureCard::CreatureCard(const std::string& name, const int attack, const int defense, const int colorlessCost, const int colorCost,
						   const int scaleX, const int scaleY, const int scaleZ, const int positionX, const int positionY, const int positionZ)
{
	name_ = name;
	attack_ = attack;
	defense_ = defense;
	colorlessCost_ = colorlessCost;
	colorCost_ = colorCost;

	scaleX_ = scaleX;
	scaleY_ = scaleY;
	scaleZ_ = scaleZ;

	positionX_ = positionX;
	positionY_ = positionY;
	positionZ_ = positionZ;
}

CreatureCard::~CreatureCard() {

}