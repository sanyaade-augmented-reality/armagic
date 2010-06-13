#ifndef ARMAGIC_MATCH_H_
#define ARMAGIC_MATCH_H_

#include <vector>
#include "irrAR.h"
#include <irrKlang.h>
#include "EventHandler.h"
#include "Card.h"
#include "CreatureCard.h"
#include "LandCard.h"

class Match {
public:
	Match(irr::IrrlichtDevice* device, irrklang::ISoundEngine* soundEngine,
		EventHandler* eventHandler_);
	~Match();
	
	bool isRunning() const;
	void mainLoop();

private:
	int numberOfCards_;
	// Vector of cards, with associated model and marker
	std::vector<Card*> cards_;
	// Vector of nodes
	std::vector<irr::scene::IAnimatedMeshSceneNode*> sceneNodes_;
	// Camera stuff
	irr::core::vector3df camPosition_;
	irr::core::vector3df camTarget_;
	irr::scene::ICameraSceneNode* camera_;
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

	//Color selectColor(const std::string& color);
	int loadCards();

	Card::Color returnColorEnum(const char* color);
	CreatureCard::Ability returnAbilityEnum(const char* ability);

	void createNodes(const int numberOfCards);
	void setupCamera();
};

#endif