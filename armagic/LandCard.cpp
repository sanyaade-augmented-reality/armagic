#include "LandCard.h"

using std::string;

LandCard::LandCard(const Color color, const std::string& marker,
			const std::string& model, const std::string& texture,
			const std::string& name, const double scale,
			const core::vector3df& position)
		: Card(color, marker, model, texture, name, scale, position)		
{
	type_ = Type::CARD_LAND;
}

LandCard::~LandCard() { }