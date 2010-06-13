#ifndef ARMAGIC_PLAYER_H_
#define ARMAGIC_PLAYER_H_

#include "Card.h"
#include <vector>

class Player
{
public:
	Player();
	~Player();


	inline int getLife() const { return life_; }
	inline void setLife(int val) { life_ = val; }
	inline int getMana() const { return mana_; }
	inline void setMana(int val) { mana_ = val; }
	/// Gets if the player choose focus in split the damage from a blocked attacking creature
	/// he controls to kill the most blocking creatures he can.
	inline bool getKillMoreCreatures() const { return killMoreCreatures_; }
	/// Set this attacking strategy option on. This can only be done in the 'Settings' menu -
	/// it can not be changed during the game. This option is the opposite of setKillStrongerCreatures
	/// (both cannot be true at the same time)
	inline void setKillMoreCreatures(bool val) { killMoreCreatures_ = val; }
	/// Gets if the player choose focus the damage from a attacking creature he controls in the
	/// most powerful (possible to kill) creature from the set of multi-blocking creatures.
	inline bool getKillStrongerCreatures() const { return killStrongerCreatures_; }
	/// Set this attacking strategy option on. This can only be done in the 'Settings' menu -
	/// it can not be changed during the game. This option is the opposite of setKillMoreCreatures
	/// (both cannot be true at the same time
	inline void setKillStrongerCreatures(bool val) { killStrongerCreatures_ = val; }
	/// Gets if is the player current turn.
	inline bool getIsCurrentTurn() const { return isCurrentTurn_; }
	/// Sets the turn for this player. This will cause the right-tapped creatures to attack.
	/// This option should only be set by the Game Manager Class.
	inline void setIsCurrentTurn(bool val) { isCurrentTurn_ = val; }
	/// Get a card that has been put in the *in game*
	inline std::vector<Card*> getPlayedCards() const { return playedCards_; }
	/// Sets the played card list. Every time a card in put *in game* and its marker is
	/// detected by the AR engine, that card is added to this list.
	inline void setPlayedCards(std::vector<Card*> val) { playedCards_ = val; }
	/// Gets a vector of all current creatures *in game*, aka the creatures invoked by the player
	/// that still alive. 
	inline std::vector<Card*> getInGameCreatures() const { return inGameCreatures_; }
	/// Sets a creature card. Every time a *creature* card in put *in game* and its marker is
	/// detected by the AR engine, that card is added to this list.
	inline void InGameCreatures(std::vector<Card*> val) { inGameCreatures_ = val; }

private:
	int life_;
	int mana_;
	bool killMoreCreatures_;
	bool killStrongerCreatures_;
	bool isCurrentTurn_;
	std::vector<Card*> playedCards_;
	std::vector<Card*> inGameCreatures_;

};
#endif