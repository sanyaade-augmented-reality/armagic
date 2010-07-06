#ifndef ARMAGIC_STATESWITCHER_H_
#define ARMAGIC_STATESWITCHER_H_

#include "Card.h"

class StateSwitcher {
public:
	StateSwitcher(Card* a, Card* b);
	~StateSwitcher();

	int whichSide();

private:
	Card* ca_;
	Card* cb_;

};


#endif