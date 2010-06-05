#ifndef ARMAGIC_MAINMENU_H_
#define ARMAGIC_MAINMENU_H_

#include "Menu.h"

class MainMenu : public Menu {
public:
	MainMenu(irr::IrrlichtDevice *device, irrklang::ISoundEngine *soundEngine,
		EventHandler *eventHandler);
	virtual ~MainMenu();
	
	virtual int show();
	int posToSelection(const core::position2di& pos);

private:
	irr::video::ITexture *texMenu_;
	irr::video::ITexture *texMenuNew_;
	irr::video::ITexture *texMenuSett_;
	irr::video::ITexture *texMenuAbout_;
	irr::video::ITexture *texMenuExit_;
};

#endif