#ifndef ARMAGIC_LAND_CARD_H_
#define ARMAGIC_LAND_CARD_H_

#include "Card.h"

class LandCard : public Card {
public:
	LandCard(const Color color, const std::string& marker,
		const std::string& name, irr::scene::IAnimatedMeshSceneNode* node);

	virtual ~LandCard();

	inline bool isActive() const { return active_; }
	inline void activate() { active_ = true; }
	inline void deactivate() { active_ = false; }
	inline void setActive(const bool a) { active_ = a; }

private:
	bool active_;
};

#endif