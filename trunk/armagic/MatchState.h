#ifndef ARMAGIC_STATE_H_
#define ARMAGIC_STATE_H_

#include <irrlicht.h>
#include <vector>

#include "Card.h"

class MatchState {
public:
	enum States {
		STATE_BAS,
		STATE_ATT,
		STATE_RES,
		STATE_NONE
	};

	MatchState(std::vector<Card*>& cards, const int player);
	virtual ~MatchState();

	virtual int run() = 0;

protected:
	std::vector<Card*>& cards_;
	int player_;
};

#endif