#include "LandCard.h"

using std::string;

LandCard::LandCard(const Color color, const std::string& marker,
				   const std::string& name, irr::scene::IAnimatedMeshSceneNode* node)
		: Card(color, marker, name, node)		
{
	type_ = Type::CARD_LAND;
}

LandCard::~LandCard() { }