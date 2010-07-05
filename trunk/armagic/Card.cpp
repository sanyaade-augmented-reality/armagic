#include "Card.h"

Card::Card(const Color color, const std::string& marker, const std::string& name,
		   irr::scene::IAnimatedMeshSceneNode* node)
		   : color_(color), marker_(marker), name_(name), node_(node)
{
}

Card::~Card() { }
