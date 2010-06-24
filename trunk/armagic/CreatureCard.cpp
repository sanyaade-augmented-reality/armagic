#include "CreatureCard.h"

using std::string;

CreatureCard::CreatureCard(const Color color, const std::string& marker,
						   const std::string& name, const int attack, const int defense,
						   const int colorlessCost, const int colorCost, const Ability ability,
						   irr::scene::IAnimatedMeshSceneNode* node)
		: Card(color, marker, name, node),
		attack_(attack), defense_(defense), colorlessCost_(colorlessCost),
		colorCost_(colorCost), ability_(ability)
{
	type_ = CARD_CREATURE;
}

CreatureCard::~CreatureCard() { }