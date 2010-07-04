#ifndef ARMAGIC_CREATURE_CARD_H_
#define ARMAGIC_CREATURE_CARD_H_

#include "Card.h"

class CreatureCard : public Card {
public:
	enum Ability {
		ABLITY_FLY,
		ABILITY_INICIATIVE,
		ABILITY_TRAMPLE,
		NO_ABILITY
	};

	CreatureCard(const Color color, const std::string& marker,
		const std::string& name, const int attack, const int defense,
		const int colorlessCost, const int colorCost, const Ability ability,
		irr::scene::IAnimatedMeshSceneNode* node);

	virtual ~CreatureCard();

	inline CreatureCard::Ability getAbility() const { return ability_; }

	inline int getAttack() const { return attack_; }
	inline int getDefense() const { return defense_; }
	inline int getColorCost() const { return colorCost_; }
	inline int getColorlessCost() const { return colorlessCost_; }

	inline bool isAttacking() const { return attacking_; }
	inline void setAttacking(const bool a) { attacking_ = a; }

private:
	Ability ability_;
	int attack_;
	int defense_;
	int colorlessCost_;
	int colorCost_;

	bool attacking_;
	
};

#endif