#include "Game.h"

using namespace irrklang;
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

Game::Game() {
	// FIXME
	resx_ = 1024;
	resy_ = 768;
	device_ = createDevice(video::EDT_OPENGL, dimension2d<unsigned int>(resx_, resy_),
		32, false, false, false, &eventHandler_);
	device_->setWindowCaption(L"ARMagic");
	driver_ = device_->getVideoDriver();
	smgr_ = device_->getSceneManager();
	guienv_ = device_->getGUIEnvironment();
	soundEngine_ = createIrrKlangDevice();

	// Start up the menu
	mainMenu_ = new MainMenu(device_, soundEngine_, &eventHandler_);
	menu_ = mainMenu_;
}

Game::~Game() {
	// delete the menu and the current match
	device_->drop();
}

bool Game::isRunning() const {
	return device_->run();
}

void Game::mainLoop() {
	while (isRunning()) {
		switch(menu_->show()) {
			case MainMenu::MAIN_MENU_START:
				break;
			case MainMenu::MAIN_MENU_SETTINGS:
				break;
			case MainMenu::MAIN_MENU_ABOUT:
				break;
			case MainMenu::MAIN_MENU_EXIT:
				exit(0);
				break;
			case MainMenu::MAIN_MENU_NONE:
				break;
			default:
				break;
		}
	}
}