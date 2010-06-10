#ifndef ARMAGIC_PLAYER_H_
#define ARMAGIC_PLAYER_H_

#include <vector>

class Player
{
public:
	Player(void);
	~Player(void);


	/// <summary>
	/// Gets the current life of the player
	/// </summary>
	/// <returns></returns>
	inline int getCurrentLife() const { return currentLife_; }
	/// <summary>
	/// Sets the current life of the player
	/// </summary>
	/// <param name="val"></param>
	inline void setCurrentLife(int val) { currentLife_ = val; }
	/// <summary>
	/// Gets the current available mana generated from the tapped lands.
	/// </summary>
	/// <returns></returns>
	inline int getCurrentMana() const { return currentMana_; }
	/// <summary>
	/// Sets the current available mana. Each time a player taps a land, CurrentMana++
	/// </summary>
	/// <param name="val"></param>
	inline void setCurrentMana(int val) { currentMana_ = val; }
	/// <summary>
	/// Gets if the player choose focus in split the damage from a blocked attacking creature
	/// he controls to kill the most blocking creatures he can.
	/// </summary>
	/// <returns></returns>
	inline bool getKillMoreCreatures() const { return killMoreCreatures_; }
	/// <summary>
	/// Set this attacking strategy option on. This can only be done in the 'Settings' menu -
	/// it can not be changed during the game. This option is the opposite of setKillStrongerCreatures
	/// (both cannot be true at the same time)
	/// </summary>
	/// <param name="val"></param>
	inline void setKillMoreCreatures(bool val) { killMoreCreatures_ = val; }
	/// <summary>
	/// Gets if the player choose focus the damage from a attacking creature he controls in the
	/// most powerful (possible to kill) creature from the set of multi-blocking creatures.
	/// </summary>
	/// <returns></returns>
	inline bool getKillStrongerCreatures() const { return killStrongerCreatures_; }
	/// <summary>
	/// Set this attacking strategy option on. This can only be done in the 'Settings' menu -
	/// it can not be changed during the game. This option is the opposite of setKillMoreCreatures
	/// (both cannot be true at the same time)
	/// </summary>
	/// <param name="val"></param>
	inline void setKillStrongerCreatures(bool val) { killStrongerCreatures_ = val; }
	/// <summary>
	/// Gets if is the player current turn.
	/// </summary>
	/// <returns></returns>
	inline bool getIsCurrentTurn() const { return isCurrentTurn_; }
	/// <summary>
	/// Sets the turn for this player. This will cause the right-tapped creatures to attack.
	/// This option should only be set by the Game Manager Class.
	/// </summary>
	/// <param name="val"></param>
	inline void setIsCurrentTurn(bool val) { isCurrentTurn_ = val; }
	/// <summary>
	/// Get a card that has been putted in the *in game*
	/// </summary>
	/// <returns></returns>
	inline std::vector<Card*> getPlayedCards() const { return playedCards_; }
	/// <summary>
	/// Sets the played card list. Every time a card in put *in game* and its marker is
	/// detected by the AR engine, that card is added to this list.
	/// </summary>
	/// <param name="val"></param>
	inline void setPlayedCards(std::vector<Card*> val) { playedCards_ = val; }
	/// <summary>
	/// Gets a vector of all current creatures *in game*, aka the creatures invoked by the player
	/// that still alive. 
	/// </summary>
	/// <returns></returns>
	inline std::vector<Card*> getInGameCreatures() const { return inGameCreatures_; }
	/// <summary>
	/// Sets a creature card. Every time a *creature* card in put *in game* and its marker is
	/// detected by the AR engine, that card is added to this list.
	/// </summary>
	/// <param name="val"></param>
	inline void InGameCreatures(std::vector<Card*> val) { inGameCreatures_ = val; }

private:
	int currentLife_;
	int currentMana_;
	bool killMoreCreatures_;
	bool killStrongerCreatures_;
	bool isCurrentTurn_;
	std::vector<Card*> playedCards_;
	std::vector<Card*> inGameCreatures_;

};
