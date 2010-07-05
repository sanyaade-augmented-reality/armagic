#include "BasicState.h"

#include <iostream>

using namespace std;

BasicState::BasicState(std::vector<Card*> &cards, const int player, ArenaDim* adim)
	: MatchState(cards, player, adim)
{
	cout << "Basic state, player " << player << endl;
}

BasicState::~BasicState() { }


int BasicState::run() {
	Card* currCard;
	for (int i = 0; i < cards_.size(); i++) {
		currCard = cards_[i];
		if (currCard->getNode()->isVisible()) {
			if (whichPlayerCard(cards_[i]->getNode()->getAbsolutePosition()) == player_) {
				// seta modelo real da carta

				if (isFighting(cards_[i]->getNode()->getAbsolutePosition()))
					return STATE_ATT;

			}
		}
	}
	return MatchState::STATE_BAS;
}