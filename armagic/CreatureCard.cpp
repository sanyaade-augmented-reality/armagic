#include "CreatureCard.h"

using std::string;

CreatureCard::CreatureCard(Color color, const	std::string marker, const std::string model, const std::string texture, const bool isCreature,
						   const std::string& name, const int attack, const int defense, const int colorlessCost, const int colorCost,
						   const double scaleX, const double scaleY, const double scaleZ, const double positionX, const double positionY, const double positionZ)
{
	color_ = color;
	marker_ = marker;
	model_ = model;
	texture_ = texture;
	isCreature_ = isCreature;

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