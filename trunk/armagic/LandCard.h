#ifndef ARMAGIC_LAND_CARD_H_
#define ARMAGIC_LAND_CARD_H_

#include "Card.h"

class LandCard : public Card {
public:
	LandCard(Color color, const	std::string marker, const std::string texture, const bool isCreature,
		     const double scaleX, const double scaleY, const double scaleZ, const double positionX, const double positionY, const double positionZ);
	virtual ~LandCard();

	void use();
	void reset();

private:
	bool used_;
};

#endif