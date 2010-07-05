#ifndef ARMAGIC_STATE_H_
#define ARMAGIC_STATE_H_

#include <irrlicht.h>
#include <vector>

#include "Card.h"
#include "ArenaDimensions.h"

class MatchState {
public:
	enum States {
		STATE_BAS,
		STATE_ATT,
		STATE_RES,
		STATE_NONE
	};

	MatchState(std::vector<Card*>& cards, const int player, ArenaDim* adim);
	virtual ~MatchState();

	virtual int run() = 0;
	bool isFighting(const irr::core::vector3df& vec) const;
	int whichPlayerCard(const irr::core::vector3df& vec);

protected:
	std::vector<Card*>& cards_;
	int player_;
	ArenaDim* adim_;
};

#endif