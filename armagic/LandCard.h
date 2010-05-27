#ifndef ARMAGIC_LAND_CARD_H_
#define ARMAGIC_LAND_CARD_H_

#include "Card.h"

class LandCard : public Card {
public:
	LandCard();
	virtual ~LandCard();

	void use();
	void reset();

private:
	bool used_;
};

#endif