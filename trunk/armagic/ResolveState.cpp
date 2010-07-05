#include "ResolveState.h"

ResolveState::ResolveState(std::vector<Card*> &cards, const int player, ArenaDim* adim)
	: MatchState(cards, player, adim)
{ }

ResolveState::~ResolveState() { }


int ResolveState::run() {
	return MatchState::STATE_BAS;
}