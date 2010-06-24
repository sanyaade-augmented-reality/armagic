#ifndef ARMAGIC_LAND_CARD_H_
#define ARMAGIC_LAND_CARD_H_

#include "Card.h"

class LandCard : public Card {
public:
	LandCard(const Color color, const std::string& marker,
		const std::string& name, irr::scene::IAnimatedMeshSceneNode* node);

	virtual ~LandCard();

	void use();
	void reset();

private:
	bool used_;
};

#endif