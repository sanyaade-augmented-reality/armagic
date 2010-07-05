#ifndef ARMAGIC_RESOLVESTATE_H_
#define ARMAGIC_RESOLVESTATE_H_

#include "MatchState.h"

class ResolveState : public MatchState {
public:
	ResolveState(std::vector<Card*>& cards, const int player, ArenaDim* adim);
	~ResolveState();

	virtual int run();

private:

};

#endif