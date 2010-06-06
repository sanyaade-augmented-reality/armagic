#include "Splash.h"

using namespace irrklang;
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

Splash::Splash(irr::IrrlichtDevice *device, irrklang::ISoundEngine *soundEngine, EventHandler *eventHandler)
	: device_(device), soundEngine_(soundEngine), eventHandler_(eventHandler)
{
	driver_ = device->getVideoDriver();
	guienv_ = device->getGUIEnvironment();

	splash_ = driver_->getTexture("../data/menu/splash1024x768.jpg");
}

Splash::~Splash() { }

void Splash::show() {
	driver_->beginScene(true, true, video::SColor(0, 0, 0, 0));
	driver_->draw2DImage(splash_, core::position2di(0, 0), core::recti(0, 0, RESOLUTION_X, RESOLUTION_Y),
		0, video::SColor(255, 255, 255, 255), true);
	guienv_->drawAll();
	driver_->endScene();
}