#ifndef ARMAGIC_MATCHMANAGER_H_
#define ARMAGIC_MATCHMANAGER_H_

#include <irrlicht.h>
#include <vector>

#include "Card.h"

/* This class manages the entire match
 */
class MatchManager {
public:
	MatchManager(std::vector<Card*>& cards);
	~MatchManager();

	void run();

protected:
private:
	std::vector<Card*>& cards_;

};

#endif