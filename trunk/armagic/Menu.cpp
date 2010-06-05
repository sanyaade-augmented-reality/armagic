#include "Menu.h"

using namespace irrklang;
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

Menu::Menu(irr::IrrlichtDevice* device, irrklang::ISoundEngine* soundEngine,
		   EventHandler* eventHandler)
		   : device_(device), soundEngine_(soundEngine), eventHandler_(eventHandler)
{
	driver_ = device->getVideoDriver();
	guienv_ = device->getGUIEnvironment();
}

Menu::~Menu() { }