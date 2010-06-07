#ifndef ARMAGIC_CREATURE_CARD_H_
#define ARMAGIC_CREATURE_CARD_H_

#include <string>
#include "Card.h"

class CreatureCard : public Card {
public:
	CreatureCard(
		Color color, const	std::string marker, const std::string model, const std::string texture, const bool isCreature,
		const std::string& name, const int attack, const int defense, const int colorlessCost, const int colorCost,
		const double scaleX, const double scaleY, const double scaleZ, const double positionX, const double positionY, const double positionZ);
	
	virtual ~CreatureCard();

	inline std::string getName() const { return name_; }
	inline int getAttack() const { return attack_; }
	inline int getDefense() const { return defense_; }
	inline int getColorCost() const { return colorCost_; }
	inline int getColorlessCost() const { return colorlessCost_; }

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
	int colorlessCost_;
	int colorCost_;




};

#endif