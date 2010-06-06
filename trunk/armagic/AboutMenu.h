#ifndef ARMAGIC_ABOUTMENU_H_
#define ARMAGIC_ABOUTMENU_H_

#include "Menu.h"

class AboutMenu : public Menu {
public:
	AboutMenu(irr::IrrlichtDevice *device, irrklang::ISoundEngine *soundEngine,
		EventHandler *eventHandler);
	virtual ~AboutMenu();

	virtual int show();
	int posToSelection(const core::position2di& pos);

private:
	irr::video::ITexture *texMenu_;
};

#endif