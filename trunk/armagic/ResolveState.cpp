#include "ResolveState.h"

#include <iostream>

using namespace std;

ResolveState::ResolveState(std::vector<Card*> &cards, const int player, ArenaDim* adim)
	: MatchState(cards, player, adim)
{
	cout << "resolving state, player " << player << endl;
}

ResolveState::~ResolveState() { }


int ResolveState::run() {
	/*std::vector<Card*> pcards[2];
	for (int i = 0; i < cards_.size(); i++) {
		if (isFighting(cards_[i]->getNode()->getAbsolutePosition())) {
			pcards[whichPlayerCard(cards_[i]->getNode()->getAbsolutePosition())].push_back(cards_[i]);
		}
	}

	for (int i = 0; i < pcards[player_].size(); i++) {
		float minDist = 100000000;
		int minIdx = -1;
		Card* cp1;
		// Finds closer
		for (int j = 0; j < pcards[!player_].size(); j++) {
			cp1 = pcards[player_][i];
			Card* cp2 = pcards[!player_][j];
			const float dist = cp1->getNode()->getAbsolutePosition().getDistanceFrom(cp2->getNode()->getAbsolutePosition());
			if (dist < minDist) {
				minDist = dist;
				minIdx = j;
			}
		}
		// If none found
		if (minIdx == -1) {
			// TODO: !player perde pontos de vida
			cout << "ninguem marcando, gol" << endl;
		}
		else {
			// TODO: Resolve as mortes
			//pcards[player_][i]->getNode()->get

			cout << pcards[player_][i]->getName() << " VS " << pcards[!player_][minIdx]->getName() << endl;


			pcards[player_].erase(pcards[player_].begin() + minIdx);
		}

	}*/
	return STATE_BAS;
}