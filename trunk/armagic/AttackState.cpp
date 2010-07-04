#include "AttackState.h"

AttackState::AttackState(std::vector<Card*> &cards, const int player)
	: MatchState(cards, player)
{

}

AttackState::~AttackState() { }


int AttackState::run() {
	return MatchState::STATE_BAS;
}