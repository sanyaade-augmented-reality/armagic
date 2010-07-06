#include "StateSwitcher.h"

StateSwitcher::StateSwitcher(Card* a, Card* b)
	: ca_(a), cb_(b)
{ }

StateSwitcher::~StateSwitcher() { }

int StateSwitcher::whichSide() {
	if (ca_->getNode()->isVisible() && !cb_->getNode()->isVisible()) return 0;
	if (cb_->getNode()->isVisible() && !ca_->getNode()->isVisible()) return 1;
	return -1;
}