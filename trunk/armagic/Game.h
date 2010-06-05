#ifndef ARMAGIC_GAME_H_
#define ARMAGIC_GAME_H_

#include "Menu.h"

class Game {
public:
	Game();
	~Game();

	void mainLoop();

private:
	bool isRunning() const;

	Menu* mainMenu_;
	
	int resx_, resy_;

	// Irrlicht stuff
	irr::IrrlichtDevice* device_;
	irr::video::IVideoDriver* driver_;
	irr::scene::ISceneManager *smgr_;
	irr::gui::IGUIEnvironment* guienv_;

	// Sound engine
	irrklang::ISoundEngine* soundEngine_;

	// Event Receiver
	EventHandler receiver_;
};

#endif