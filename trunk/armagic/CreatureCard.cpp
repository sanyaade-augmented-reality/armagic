#include "CreatureCard.h"

using std::string;

CreatureCard::CreatureCard(const Color color, const std::string& marker,
			const std::string& model, const std::string& texture,
			const std::string& name, const int attack, const int defense,
			const int colorlessCost, const int colorCost, const Ability ability,
			const double scale)
		: Card(color, marker, model, texture, name, scale),
		attack_(attack), defense_(defense), colorlessCost_(colorlessCost),
		colorCost_(colorCost), ability_(ability)
{
	type_ = Type::CARD_CREATURE;
}

CreatureCard::~CreatureCard() { }