#include "AttackState.h"

AttackState::AttackState(std::vector<Card*> &cards, const int player, ArenaDim* adim)
	: MatchState(cards, player, adim)
{

}

AttackState::~AttackState() { }


int AttackState::run() {
	return MatchState::STATE_BAS;
}