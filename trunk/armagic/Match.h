#ifndef ARMAGIC_MATCH_H_
#define ARMAGIC_MATCH_H_

#define IRRAR_ENGINE

#include <vector>
#include "irrAR.h"
#include <irrKlang.h>
#include "EventHandler.h"
#include "Card.h"
#include "CreatureCard.h"
#include "LandCard.h"
#include "ARManager.h"
#include "ARSceneNode.h"

#include "ArenaDimensions.h"

#include "BasicState.h"
#include "AttackState.h"
#include "ResolveState.h"

class Match {
public:
	Match(irr::IrrlichtDevice* device, irrklang::ISoundEngine* soundEngine,
		EventHandler* eventHandler_);
	~Match();
	
	bool isRunning() const;
	void mainLoop();

private:

	ArenaDim adim_;
	int numberOfCards_;
	// Vector of cards, with associated model and marker
	std::vector<Card*> cards_;
	// Camera stuff
	irr::core::vector3df camPosition_;
	irr::core::vector3df camTarget_;
	irr::scene::ICameraSceneNode* camera_;
	// IrrAr stuff
#ifdef IRRAR_ENGINE
	irrAr::IARManager* armgr_;
#else
	ARManager* armgr_;
#endif

	// State Machine
	int player_;
	MatchState* mstate_;

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

	void getArenaDim();
	bool isFighting(const irr::core::vector3df& vec) const;
	void setupCamera();
	void drawAll();
};

#endif