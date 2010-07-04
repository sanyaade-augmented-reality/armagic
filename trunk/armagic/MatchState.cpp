#include "MatchState.h"

MatchState::MatchState(std::vector<Card*>& cards, const int player)
	: cards_(cards), player_(player)
{ }

MatchState::~MatchState() { }