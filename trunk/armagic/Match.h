#ifndef ARMAGIC_MATCH_H_
#define ARMAGIC_MATCH_H_

#include <vector>
#include "irrAR.h"
#include <irrKlang.h>
#include "EventHandler.h"
#include "Card.h"

class Match {
public:
	Match(irr::IrrlichtDevice* device, irrklang::ISoundEngine* soundEngine,
		EventHandler* eventHandler_);
	~Match();
	
	bool isRunning() const;
	void mainLoop();

private:
	// Vector of cards, with associated model and marker
	std::vector<Card>* cards_;

	// IrrAr stuff
	irrAr::IARManager* armgr_;
	// Irrlicht stuff
	irr::IrrlichtDevice* device_;
	irr::video::IVideoDriver* driver_;
	irr::scene::ISceneManager *smgr_;
	irr::gui::IGUIEnvironment* guienv_;
	// Sound engine
	irrklang::ISoundEngine* soundEngine_;
	// Event handler
	EventHandler* eventHandler_;

	void setupCards();
};

#endif