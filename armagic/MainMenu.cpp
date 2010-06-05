#include "MainMenu.h"
#include <iostream>

using namespace std;

MainMenu::MainMenu(irr::IrrlichtDevice *device,
				   irrklang::ISoundEngine *soundEngine, EventHandler *eventHandler)
				   : Menu(device, soundEngine, eventHandler)
{
	driver_ = device_->getVideoDriver();
	guienv_ = device->getGUIEnvironment();

	texMenu_ = driver_->getTexture("../data/menu/menu1024x768.jpg");
}

MainMenu::~MainMenu() { }

int MainMenu::posToSelection(const core::position2di& pos) {
		if (pos.X > 620 && pos.X < 960) {
			if (pos.Y > 120 && pos.Y < 170)
			{
				cout << pos.Y << " " << pos.X << endl;
				return MAIN_MENU_START;
			}
			else if (pos.Y > 210 && pos.Y < 260)
			{
				cout << pos.Y << " " << pos.X << endl;
				return MAIN_MENU_SETTINGS;
			}
			else if (pos.Y > 290 && pos.Y < 340)
			{cout << pos.Y << " " << pos.X << endl;
				return MAIN_MENU_ABOUT;

			}
			else if (pos.Y > 365 && pos.Y < 415)
			{cout << pos.Y << " " << pos.X << endl;
				return MAIN_MENU_EXIT;
			}
		}
		return MAIN_MENU_NONE;
	}

int MainMenu::show() {
	device_->getCursorControl()->setVisible(true);
	soundEngine_->stopAllSounds();
	soundEngine_->play2D("../data/sounds/music/back.mp3");

	while (device_->run() && driver_) {
		driver_->beginScene(true, true, video::SColor(0, 0, 0, 0));
		video::ITexture* tex = texMenu_;
		switch (posToSelection(eventHandler_->getMousePosition())) {
			case MAIN_MENU_START:
				break;
			case MAIN_MENU_SETTINGS:
				break;
			case MAIN_MENU_ABOUT:
				break;
			case MAIN_MENU_EXIT:
				break;
		}
		// FIXME
		driver_->draw2DImage(tex, core::position2di(0, 0), core::recti(0, 0, RESOLUTION_X, RESOLUTION_Y),
			0, video::SColor(255, 255, 255, 255), true);
		if (eventHandler_->IsMouseClicked()) {
			const int res = posToSelection(eventHandler_->getMousePosition());
			if (res != MAIN_MENU_NONE) {
				return res;
			}
		}
		guienv_->drawAll();
		driver_->endScene();
	}
}