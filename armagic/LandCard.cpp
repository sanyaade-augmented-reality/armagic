#include "LandCard.h"

using std::string;

LandCard::LandCard(const Color color, const std::string& marker,
			const std::string& model, const std::string& texture,
			const std::string& name, const double scale)
		: Card(color, marker, model, texture, name, scale)		
{
	type_ = Type::CARD_LAND;
}

LandCard::~LandCard() { }