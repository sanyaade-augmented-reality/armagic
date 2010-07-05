#include "BasicState.h"

BasicState::BasicState(std::vector<Card*> &cards, const int player, ArenaDim* adim)
	: MatchState(cards, player, adim)
{

}

BasicState::~BasicState() { }


int BasicState::run() {
	for (int i = 0; i < cards_.size(); i++) {
		if (cards_[i]->getNode()->isVisible()) {
			
		}
	}
	return MatchState::STATE_BAS;
}