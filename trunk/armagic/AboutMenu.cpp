#include "AboutMenu.h"
#include <cassert>

AboutMenu::AboutMenu(irr::IrrlichtDevice *device,
				   irrklang::ISoundEngine *soundEngine, EventHandler *eventHandler)
				   : Menu(device, soundEngine, eventHandler)
{
	texMenu_ = driver_->getTexture("../data/menu/about1024x768.jpg");
	assert(texMenu_);
}

AboutMenu::~AboutMenu() { }

int AboutMenu::posToSelection(const core::position2di& pos) {
	return MENU_NONE;
}

int AboutMenu::show() {
	while (device_->run() && driver_) {
		driver_->beginScene(true, true, video::SColor(0, 0, 0, 0));
		driver_->draw2DImage(texMenu_, core::position2di(0, 0), core::recti(0, 0, RESOLUTION_X, RESOLUTION_Y),
			0, video::SColor(255, 255, 255, 255), true);
		if (eventHandler_->IsMouseClicked()) {
			return MENU_NONE;
		}
		guienv_->drawAll();
		driver_->endScene();
	}
}

