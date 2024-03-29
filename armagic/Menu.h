#ifndef ARMAGIC_MENU_H_
#define ARMAGIC_MENU_H_

#include <irrlicht.h>
#include <irrKlang.h>
#include "EventHandler.h"
#include "definitions.h"

class Menu {
public:
	enum Selection {
		MAIN_MENU_START,
		MAIN_MENU_SETTINGS,
		MAIN_MENU_ABOUT,
		MAIN_MENU_EXIT,
		MENU_NONE
	};

	Menu(irr::IrrlichtDevice* device, irrklang::ISoundEngine* soundEngine,
		EventHandler* eventHandler);
	virtual ~Menu();

	virtual int show() = 0;
	virtual int posToSelection(const core::position2di& pos) = 0;

protected:
	irr::IrrlichtDevice* device_;
	irrklang::ISoundEngine* soundEngine_;
	irr::video::IVideoDriver* driver_;
	irr::gui::IGUIEnvironment* guienv_;
	EventHandler* eventHandler_;

};

#endif