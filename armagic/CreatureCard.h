#ifndef ARMAGIC_CREATURE_CARD_H_
#define ARMAGIC_CREATURE_CARD_H_

#include <string>
#include "Card.h"

class CreatureCard : public Card {
public:
	CreatureCard(const std::string& name, const int attack, const int defense, const int colorlessCost, const int colorCost,
		const int scaleX, const int scaleY, const int scaleZ, const int positionX, const int positionY, const int positionZ);
	virtual ~CreatureCard();

	inline std::string getName() const { return name_; }
	inline int getAttack() const { return attack_; }
	inline int getDefense() const { return defense_; }
	inline int getColorCost() const { return colorCost_; }
	inline int getAttackModifier() const { return attackModifier_; }
	inline void setAttackModifier(int val) { attackModifier_ = val; }
	inline int getDefenseModifier() const { return defenseModifier_; }
	inline void setDefenseModifier(int val) { defenseModifier_ = val; }

	inline int getScaleX() const { return scaleX_; }
	inline void setScaleX(int val) { scaleX_ = val; }
	inline int getScaleY() const { return scaleY_; }
	inline void setScaleY(int val) { scaleY_ = val; }
	inline int getScaleZ() const { return scaleZ_; }
	inline void setScaleZ(int val) { scaleZ_ = val; }

	inline int PositionX() const { return positionX_; }
	inline void PositionX(int val) { positionX_ = val; }
	inline int PositionY() const { return positionY_; }
	inline void PositionY(int val) { positionY_ = val; }
	inline int PositionZ() const { return positionZ_; }
	inline void PositionZ(int val) { positionZ_ = val; }

private:
	std::string name_;
	int attack_;
	int defense_;
	int attackModifier_;
	int defenseModifier_;
	int colorlessCost_;
	int colorCost_;

	int scaleX_;
	int scaleY_;
	int scaleZ_;

	int positionX_;
	int positionY_;
	int positionZ_;


};

#endif