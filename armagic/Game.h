#ifndef ARMAGIC_GAME_H_
#define ARMAGIC_GAME_H_

#include "MainMenu.h"
#include "Match.h"
#include "Splash.h"
#include "AboutMenu.h"

class Game {
public:
	Game();
	~Game();

	void mainLoop();

private:
	Match* match_;

	// Menu
	Menu* menu_;
	MainMenu* mainMenu_;
	AboutMenu* aboutMenu_;
	Splash* splash_;
	
	int resx_, resy_;

	// Irrlicht stuff
	irr::IrrlichtDevice* device_;
	irr::video::IVideoDriver* driver_;
	irr::scene::ISceneManager* smgr_;
	irr::gui::IGUIEnvironment* guienv_;

	// Sound engine
	irrklang::ISoundEngine* soundEngine_;

	// Event Receiver
	EventHandler eventHandler_;

	bool isRunning() const;
};

#endif