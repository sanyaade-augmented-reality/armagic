#include "Match.h"

using namespace irrAr;
using namespace irrklang;
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

Match::Match(IrrlichtDevice* device, ISoundEngine* soundEngine,
			 EventHandler* eventHandler)
	: device_(device), soundEngine_(soundEngine), eventHandler_(eventHandler)
{
	armgr_ = new IARManager(device_);

	// Initialize cards
	cards_ = new std::vector<Card>(NUMBER_OF_CARDS);
	for (int i = 0; i < NUMBER_OF_CARDS; i++) {
		Card& c = (*cards_)[i];
		c.setMarkerId(markers::Marker(i));
		c.setModel(models::SYDNEY);									// FIXME
	}
}

Match::~Match() {
	delete [] cards_;
	delete armgr_;
}