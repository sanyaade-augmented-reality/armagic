#ifndef ARMAGIC_ATTACKSTATE_H_
#define ARMAGIC_ATTACKSTATE_H_

#include "MatchState.h"

class AttackState : public MatchState {
public:
	AttackState(std::vector<Card*>& cards, const int player, ArenaDim* adim);
	~AttackState();

	virtual int run();

private:

};


#endif