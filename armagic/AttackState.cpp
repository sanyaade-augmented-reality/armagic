#include "AttackState.h"

#include <iostream>

using namespace std;

AttackState::AttackState(std::vector<Card*> &cards, const int player, ArenaDim* adim)
	: MatchState(cards, player, adim)
{
	cout << "Attack state, player :" << player << endl;

}

AttackState::~AttackState() { }


int AttackState::run() {
	/*Card* currCard;
	for (int i = 0; i < cards_.size(); i++) {
		currCard = cards_[i];
		if (currCard->getNode()->isVisible()) {
			if (whichPlayerCard(cards_[i]->getNode()->getAbsolutePosition()) == player_) {
				if (isFighting(cards_[i]->getNode()->getAbsolutePosition()))
					return STATE_ATT;

			}
		}
	}*/
	cout << "Prepare-se para o ataque" << endl;
	return MatchState::STATE_RES;
}