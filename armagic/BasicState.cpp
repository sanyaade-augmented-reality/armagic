#include "BasicState.h"

BasicState::BasicState(std::vector<Card*> &cards, const int player)
	: MatchState(cards, player)
{

}

BasicState::~BasicState() { }


int BasicState::run() {
	return MatchState::STATE_BAS;
}