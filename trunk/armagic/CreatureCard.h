#ifndef ARMAGIC_CREATURE_CARD_H_
#define ARMAGIC_CREATURE_CARD_H_

#include <string>
#include "Card.h"

class CreatureCard : public Card {
public:
	CreatureCard(const std::string& name, const int attack, const int defense);
	virtual ~CreatureCard();

	inline std::string getName() const { return name_; }
	inline int getAttack() const { return attack_; }
	inline int getDefense() const { return defense_; }
	inline int getCost() const { return cost_; }
	inline int getAttackModifier() const { return attackModifier_; }
	inline void setAttackModifier(int val) { attackModifier_ = val; }
	inline int getDefenseModifier() const { return defenseModifier_; }
	inline void setDefenseModifier(int val) { defenseModifier_ = val; }

private:
	std::string name_;
	int attack_;
	int defense_;
	int attackModifier_;
	int defenseModifier_;
	int cost_;
};

#endif