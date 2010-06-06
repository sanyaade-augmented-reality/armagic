#ifndef ARMAGIC_SPLASH_H_
#define ARMAGIC_SPLASH_H_

#include <irrlicht.h>
#include <irrKlang.h>
#include "EventHandler.h"
#include "definitions.h"

class Splash {
public:
	Splash(irr::IrrlichtDevice* device, irrklang::ISoundEngine* soundEngine,
		EventHandler* eventHandler);
	~Splash();

	void show();

private:
	irr::video::ITexture *splash_;

	irr::IrrlichtDevice* device_;
	irrklang::ISoundEngine* soundEngine_;
	irr::video::IVideoDriver* driver_;
	irr::gui::IGUIEnvironment* guienv_;
	EventHandler* eventHandler_;
};

#endif