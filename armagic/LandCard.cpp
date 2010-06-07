#include "LandCard.h"

using std::string;

LandCard::LandCard(Color color, const	std::string marker, const std::string texture, const bool isCreature,
				   const double scaleX, const double scaleY, const double scaleZ, const double positionX, const double positionY, const double positionZ)
{
	color_ = color;
	marker_ = marker;
	texture_ = texture;
	isCreature_ = isCreature;
	
	scaleX_ = scaleX;
	scaleY_ = scaleY;
	scaleZ_ = scaleZ;

	positionX_ = positionX;
	positionY_ = positionY;
	positionZ_ = positionZ;
}

LandCard::~LandCard()
{

}