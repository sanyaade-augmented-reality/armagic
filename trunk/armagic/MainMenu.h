#ifndef ARMAGIC_MAINMENU_H_
#define ARMAGIC_MAINMENU_H_

#include "Menu.h"

class MainMenu : public Menu {
public:
	enum Selection {
		MAIN_MENU_START,
		MAIN_MENU_SETTINGS,
		MAIN_MENU_ABOUT,
		MAIN_MENU_EXIT,
		MAIN_MENU_NONE
	};
	MainMenu(irr::IrrlichtDevice *device, irrklang::ISoundEngine *soundEngine,
		EventHandler *eventHandler);
	virtual ~MainMenu();
	
	virtual int show();
	int posToSelection(const core::position2di& pos);

private:
	irr::video::ITexture *texMenu_;
};

#endif