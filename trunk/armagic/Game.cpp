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
	resx_ = 800;
	resy_ = 600;
	device_ = createDevice(video::EDT_OPENGL, dimension2d<unsigned int>(resx_, resy_),
		32, false, false, false, &receiver_);
	device_->setWindowCaption(L"ARMagic");
	driver_ = device_->getVideoDriver();
	smgr_ = device_->getSceneManager();
	guienv_ = device_->getGUIEnvironment();
	soundEngine_ = createIrrKlangDevice();

	// Start up the menu
}

Game::~Game() {
	// delete the menu
	device_->drop();
}

bool Game::isRunning() const {
	return device_->run();
}

void Game::mainLoop() {
	while (isRunning()) {
		// DO STUFF
	}
}