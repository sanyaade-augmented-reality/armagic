#include "MainMenu.h"
#include <cassert>

MainMenu::MainMenu(irr::IrrlichtDevice *device,
				   irrklang::ISoundEngine *soundEngine, EventHandler *eventHandler)
				   : Menu(device, soundEngine, eventHandler)
{
	texMenu_ = driver_->getTexture("../data/menu/menu1024x768.jpg");
	texMenuNew_ = driver_->getTexture("../data/menu/menu_new1024x768.jpg");
	texMenuSett_ = driver_->getTexture("../data/menu/menu_settings1024x768.jpg");
	texMenuAbout_ = driver_->getTexture("../data/menu/menu_about1024x768.jpg");
	texMenuExit_ = driver_->getTexture("../data/menu/menu_exit1024x768.jpg");

	assert(texMenu_);
	assert(texMenuNew_);
	assert(texMenuSett_);
	assert(texMenuAbout_);
	assert(texMenuExit_);
}

MainMenu::~MainMenu() { }


/// <summary>
/// Return the option selected by the user in the menu.
/// </summary>
/// <param name="pos"></param>
/// <returns></returns>
int MainMenu::posToSelection(const core::position2di& pos) {
		if (pos.X > 620 && pos.X < 960) {
			if (pos.Y > 120 && pos.Y < 170)	{
				return MAIN_MENU_START;
			}
			else if (pos.Y > 210 && pos.Y < 260) {
				return MAIN_MENU_SETTINGS;
			}
			else if (pos.Y > 290 && pos.Y < 340) {
				return MAIN_MENU_ABOUT;
			}
			else if (pos.Y > 365 && pos.Y < 415) {
				return MAIN_MENU_EXIT;
			}
		}
		return MENU_NONE;
	}

int MainMenu::show() {
	device_->getCursorControl()->setVisible(true);
	soundEngine_->stopAllSounds();
	soundEngine_->play2D("../data/sounds/music/back.mp3", true);

	while (device_->run() && driver_) {
		driver_->beginScene(true, true, video::SColor(0, 0, 0, 0));
		video::ITexture* tex = texMenu_;
		switch (posToSelection(eventHandler_->getMousePosition())) {
			case MAIN_MENU_START:
				tex = texMenuNew_;
				break;
			case MAIN_MENU_SETTINGS:
				tex = texMenuSett_;
				break;
			case MAIN_MENU_ABOUT:
				tex = texMenuAbout_;
				break;
			case MAIN_MENU_EXIT:
				tex = texMenuExit_;
				break;
			default:
				tex = texMenu_;
				break;
		}
		driver_->draw2DImage(tex, core::position2di(0, 0), core::recti(0, 0, RESOLUTION_X, RESOLUTION_Y),
			0, video::SColor(255, 255, 255, 255), true);
		if (eventHandler_->IsMouseClicked()) {
			const int res = posToSelection(eventHandler_->getMousePosition());
			if (res != MENU_NONE) {
				soundEngine_->stopAllSounds();
				soundEngine_->play2D("../data/sounds/sfx/SwordMetalSwingHit.mp3");
				return res;
			}
		}
		guienv_->drawAll();
		driver_->endScene();
	}
}