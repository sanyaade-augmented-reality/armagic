#include "Match.h"
#include <irrXML.h>
//using namespace irr; // irrXML is located 
//using namespace io;  // in the namespace irr::io

#include <string> // we use STL strings to store data

using namespace irrAr;
using namespace irrklang;
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

Match::Match(IrrlichtDevice* device, ISoundEngine* soundEngine,
			 EventHandler* eventHandler)
	: device_(device), soundEngine_(soundEngine), eventHandler_(eventHandler)
{
	armgr_ = new IARManager(device_);
	driver_ = device_->getVideoDriver();
	smgr_ = device_->getSceneManager();
	guienv_ = device_->getGUIEnvironment();	
	
	setupCamera();
	loadCards();
	createNodes();
}

Match::~Match() {
	delete armgr_;
	arVideoCapStop();
	arVideoClose();
}

// AQUI DEVE FICAR A CARGA DAS CARTAS
// O XML FICA EM ALGUM LUGAR PRE-DETERMINADO
// LE-SE O XML E CRIA-SE UMA CARD POR CARTA
void Match::loadCards() {
	
	// create the reader using one of the factory functions
	IrrXMLReader* xml = createIrrXMLReader("../data/CardsXML.xml");
	
	cards_.resize(NUMBER_OF_CARDS);	//<- NUMBER OF CARDS DEVE SER LIDO DO XML, ESTA VAR DEVE *SUMIR*
	sceneNodes_.resize(NUMBER_OF_CARDS);
	for (int i = 0; i < NUMBER_OF_CARDS; i++) {
		Card& c = cards_[i];
		c.setMarkerId(markers::Marker(i));
		c.setModel(models::SYDNEY);				// FIXME
	}
}

// PARA CADA CARTA CRIA-SE UM NODE SEGUINDO O MODELO ABAIXO
// TODOS NO VETOR
void Match::createNodes() {
	for (int i = 0; i < NUMBER_OF_CARDS; i++) {
		sceneNodes_[i] = smgr_->addAnimatedMeshSceneNode(smgr_->getMesh("../data/models/dragon.3DS"));
		if (sceneNodes_[i]) {
			sceneNodes_[i]->setMaterialTexture(0,driver_->getTexture("../data/models/dragon.jpg"));
			sceneNodes_[i]->setRotation(vector3df(0,180,0));
			sceneNodes_[i]->setMaterialFlag(video::EMF_LIGHTING, false);
			sceneNodes_[i]->setAnimationSpeed(15);
			sceneNodes_[i]->setScale(vector3df(15,15,15));
			sceneNodes_[i]->setPosition(vector3df(0,75,0));
			/*bird
			sceneNodes_[i]->setScale(vector3df(0.1,0.1,0.1));
			sceneNodes_[i]->setPosition(vector3df(-100,-200,-100));*/
		}
		// Bind with artoolkit
		armgr_->addARSceneNode("../data/markers/patt.hiro",
			sceneNodes_[i]);
	}
}

void Match::setupCamera() {
	armgr_->beginCamera("../data/ardata/camera_para.dat",
		"../data/ardata/WDM_camera_flipV.xml", "-dev=/dev/video0");
	camera_ = smgr_->addCameraSceneNode(0, camPosition_, camTarget_);
	armgr_->fixCamera(camera_);
}

bool Match::isRunning() const {
	return device_->run();
}

void Match::mainLoop() {
	soundEngine_->play2D("../data/sounds/music/medievalpilgrim.mp3");

	while (isRunning()) {
		driver_->beginScene(true, true, SColor(255,100,101,140));
		//make movements and bring in new image
		armgr_->run();
		//draw the background image centered and scaled
		armgr_->drawBackground();

		// Event handling
		if (eventHandler_->IsKeyDown(EKEY_CODE::KEY_ESCAPE))
			return;

		smgr_->drawAll();
		guienv_->drawAll();
		driver_->endScene();
	}
}