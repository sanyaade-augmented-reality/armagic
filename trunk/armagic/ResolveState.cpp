#include "ResolveState.h"

ResolveState::ResolveState(std::vector<Card*> &cards, const int player)
	: MatchState(cards, player)
{ }

ResolveState::~ResolveState() { }


int ResolveState::run() {
	return MatchState::STATE_BAS;
}