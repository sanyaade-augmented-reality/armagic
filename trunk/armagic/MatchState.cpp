#include "MatchState.h"

MatchState::MatchState(std::vector<Card*>& cards, const int player, ArenaDim* adim)
	: cards_(cards), player_(player), adim_(adim)
{ }

MatchState::~MatchState() { }

bool MatchState::isFighting(const irr::core::vector3df& vec) const {
	const bool x = vec.X > adim_->fld.X && vec.X < adim_->fru.X;
	const bool y = vec.Y > adim_->flu.Y && vec.Y < adim_->frd.Y;
	return x && y;
}

int MatchState::whichPlayerCard(const irr::core::vector3df& vec) { 
	const float hx = (adim_->ld.X + adim_->lu.X)/2;
	//const float hy = (ld + rd)/2;
	if (vec.X < hx)
		return 0;
	return 1;
}