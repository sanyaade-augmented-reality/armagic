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
	driver_ = device_->getVideoDriver();
	smgr_ = device_->getSceneManager();
	guienv_ = device_->getGUIEnvironment();
	
	armgr_->beginCamera("../data/ardata/camera_para.dat","../data/ardata/WDM_camera_flipV.xml", "-dev=/dev/video0");

	setupCards();
}

Match::~Match() {
	delete [] cards_;
	delete armgr_;
}

void Match::setupCards() {
	cards_ = new std::vector<Card>(NUMBER_OF_CARDS);
	for (int i = 0; i < NUMBER_OF_CARDS; i++) {
		Card& c = (*cards_)[i];
		//c.setMarkerId(markers::Marker(i));
		//c.setModel(models::SYDNEY);				// FIXME
	}
}

bool Match::isRunning() const {
	return device_->run();
}

void Match::mainLoop() {
	while (isRunning()) {
		driver_->beginScene(true, true, SColor(255,100,101,140));
		//make movements and bring in new image
		armgr_->run();
		//draw the background image centered and scaled
		armgr_->drawBackground();


		if (eventHandler_->IsKeyDown(EKEY_CODE::KEY_ESCAPE))
			return;

		smgr_->drawAll();
		guienv_->drawAll();
		driver_->endScene();
	}
}