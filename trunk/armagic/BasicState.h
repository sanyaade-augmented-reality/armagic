#ifndef ARMAGIC_BASICSTATE_H_
#define ARMAGIC_BASICSTATE_H_

#include "MatchState.h"

class BasicState : public MatchState {
public:
	BasicState(std::vector<Card*>& cards, const int player, ArenaDim* adim);
	~BasicState();

	virtual int run();

private:

};


#endif