#include "Match.h"
#include <irrXML.h>

#include <iostream>
using namespace std;

#include <fstream>

using namespace irrAr;
using namespace irrklang;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
using namespace std;

Match::Match(IrrlichtDevice* device, ISoundEngine* soundEngine,	EventHandler* eventHandler)
			 : device_(device), soundEngine_(soundEngine), eventHandler_(eventHandler)
{
	driver_ = device_->getVideoDriver();
	smgr_ = device_->getSceneManager();
	guienv_ = device_->getGUIEnvironment();	
#ifdef IRRAR_ENGINE
	armgr_ = new IARManager(device_);
#else
	armgr_ = new ARManager(device_);
#endif

	setupCamera();
	numberOfCards_ = loadCards();
	getArenaDim();

	player_ = 0;
	BasicState *bs =  new BasicState(cards_, player_, &adim_);
	mstate_ = bs;

	const char* patt_a = "../data/markers/patt.t";
	const char* patt_b = "../data/markers/patt.l";
	IAnimatedMeshSceneNode* na = smgr_->addAnimatedMeshSceneNode(smgr_->getMesh("../data/models/wolf.3ds"));
	na->setMaterialTexture(0,driver_->getTexture("../data/models/wolf.jpg"));
	na->setRotation(vector3df(0,180,0));
	na->setMaterialFlag(video::EMF_LIGHTING, false);
	na->setAnimationSpeed(15);
	na->setScale(vector3df(10, 10, 10));

	IAnimatedMeshSceneNode* nb = smgr_->addAnimatedMeshSceneNode(smgr_->getMesh("../data/models/wolf.3ds"));
	nb->setMaterialTexture(0,driver_->getTexture("../data/models/wolf.jpg"));
	nb->setRotation(vector3df(0,180,0));
	nb->setMaterialFlag(video::EMF_LIGHTING, false);
	nb->setAnimationSpeed(15);
	nb->setScale(vector3df(10, 10, 10));
	Card* ssa = new Card(Card::COLOR_WHITE, patt_a, "ampulheta_a", na);
	Card* ssb = new Card(Card::COLOR_WHITE, patt_b, "ampulheta_b", nb);

	ssw_ = new StateSwitcher(ssa, ssb);
	armgr_->addARSceneNode(ssa);
	armgr_->addARSceneNode(ssb);

	p1b = driver_->getTexture("../data/bar/bar_11.jpg");
	p1a = driver_->getTexture("../data/bar/bar_12.jpg");
	p1r = driver_->getTexture("../data/bar/bar_13.jpg");
	p2b = driver_->getTexture("../data/bar/bar_21.jpg");
	p2a = driver_->getTexture("../data/bar/bar_22.jpg");
	p2r = driver_->getTexture("../data/bar/bar_23.jpg");
	bar = p1b;
}

Match::~Match() {
	delete armgr_;
	arVideoCapStop();
	arVideoClose();
}

Card::Color Match::returnColorEnum(const char* color) {
	if(strcmp(color,"green")==0)
		return Card::COLOR_GREEN;
	else if(strcmp(color,"red")==0)
		return Card::COLOR_RED;
	else if(strcmp(color,"blue")==0)
		return Card::COLOR_BLUE;
	else if(strcmp(color,"white")==0)
		return Card::COLOR_WHITE;
	else if(strcmp(color,"black")==0)
		return Card::COLOR_BLACK;
}


CreatureCard::Ability Match::returnAbilityEnum(const char* ability) {
	if(strcmp(ability,"FLY")==0)
		return CreatureCard::ABLITY_FLY;
	else if (strcmp(ability,"TRA")==0)
		return CreatureCard::ABILITY_TRAMPLE;
	else if(strcmp(ability,"INI")==0)
		return CreatureCard::ABILITY_INICIATIVE;
	else 
		return CreatureCard::NO_ABILITY;
}

// This methods reads XML file which contains all cards and
// the information to build the virtual objects of them (model, markers, textures...)
// Returns the total number of cards in the XML file
int Match::loadCards() {
	// create the reader using one of the factory functions
	IrrXMLReader* xml = createIrrXMLReader("../data/CardsXML.xml");

	//The total number of cards in the game (including creatures and lands)
	int numberOfCards = -1;
	int numberOfCreatures = -1;
	int numberOfLands = -1;

	//This bool controls the end of read of a card. When it is true, we can 
	//instantiate the new card.
	bool isCardRead = false;

	//The number of the current card
	std::string name = "";
	int cardNumber = -1;
	bool isCreature = false;

	std::string model, texture, marker, color, ability;
	double scale = -1;
	int colorlessCost = -1;
	int colorCost = -1;
	int attack = -1;
	int defense = -1;

	while (xml && xml->read()) {
		if (xml->getNodeType() == EXN_ELEMENT) {
			if (strcmp("cards", xml->getNodeName()) == 0) {
				numberOfCards = xml->getAttributeValueAsInt("numberOfCards");
				cards_.resize(numberOfCards);

				numberOfCreatures = xml->getAttributeValueAsInt("creatureCards");
				numberOfLands = xml->getAttributeValueAsInt("landCards");
			}
			else if (strcmp("card", xml->getNodeName()) == 0) {
				name = xml->getAttributeValue("name");
				cardNumber = xml->getAttributeValueAsInt("cardNumber");
				if(strcmp("creature",xml->getAttributeValue("cardType"))==0)
					isCreature = true;
				else
					isCreature = false;
			}
			else if (strcmp("model",xml->getNodeName())==0) {
				model = xml->getAttributeValue("value");
			}
			else if (strcmp("texture",xml->getNodeName()) == 0) {
				texture = xml->getAttributeValue("value");
			}
			else if(strcmp("marker",xml->getNodeName()) == 0) {
				marker = xml->getAttributeValue("value");
			}
			else if(strcmp("scale",xml->getNodeName()) == 0) {
				scale = xml->getAttributeValueAsFloat("value");
			}
			else if(strcmp("colors",xml->getNodeName()) == 0) {
				color = xml->getAttributeValue("value");
			}
			else if(strcmp("ability",xml->getNodeName()) == 0) {
				if(isCreature)
					ability = xml->getAttributeValue("value");
			}
			else if(strcmp("registers",xml->getNodeName()) == 0) {
				//<registers colorless="1" green="0" red="1" blue="0" white="0" black="0" power="1" toughness="2"/>
				if(isCreature) {
					colorlessCost = xml->getAttributeValueAsInt("colorless");
					colorCost = xml->getAttributeValueAsInt(color.c_str());
					attack = xml->getAttributeValueAsInt("power");
					defense = xml->getAttributeValueAsInt("toughness");
				}
				isCardRead = true;
			}

			if(isCardRead) {
				if (isCreature) {
					// Create a node
					IAnimatedMeshSceneNode* node = smgr_->addAnimatedMeshSceneNode(smgr_->getMesh(model.c_str()));
					node->setMaterialTexture(0,driver_->getTexture(texture.c_str()));
					node->setRotation(vector3df(0,180,0));
					node->setMaterialFlag(video::EMF_LIGHTING, false);
					node->setAnimationSpeed(15);
					node->setScale(vector3df(scale, scale, scale));

					// Create the card
					cards_[cardNumber] = new CreatureCard(returnColorEnum(color.c_str()), marker, name, attack, defense,
						colorlessCost, colorCost, returnAbilityEnum(ability.c_str()), node);

					std::string s = cards_[cardNumber]->getMarker();
					isCardRead = false;

					// Bind with artoolkit
#ifdef IRRAR_ENGINE
					//armgr_->addARSceneNode(marker.c_str(), node);
					armgr_->addARSceneNode(cards_[cardNumber]);
#else
					ARSceneNode* arnode = new ARSceneNode(device_, marker.c_str(), node);
					armgr_->addARSceneNode(arnode);
#endif

				}
				else
				{
					//Instantiate the lands
					cards_[cardNumber] = new LandCard(returnColorEnum(color.c_str()), marker, "Land", NULL);

					isCardRead = false;
				}
			}
		}
	}
	return numberOfCards;
}

void Match::setupCamera() {
#ifdef IRRAR_ENGINE
	armgr_->beginCamera("../data/camera/camera_para.dat",
		"../data/camera/WDM_camera_flipV.xml", "-dev=/dev/video0");
#endif
	camera_ = smgr_->addCameraSceneNode(0, camPosition_, camTarget_);
	armgr_->fixCamera(camera_);
}

bool Match::isRunning() const {
	return device_->run();
}

void Match::drawAll() {
	armgr_->drawBackground();
	driver_->draw2DImage(bar, rect<s32>(0,0,1024,70),
		rect<s32>(0,0,1024,70));
	smgr_->drawAll();
	guienv_->drawAll();
}

void Match::getArenaDim() {
	std::ifstream in;
	in.open("../data/arconfig.txt");
	
	in >> adim_.ld.X >> adim_.ld.Y >> adim_.ld.Z
		>> adim_.lu.X >> adim_.lu.Y >> adim_.lu.Z
		>> adim_.rd.X >> adim_.rd.Y >> adim_.rd.Z
		>> adim_.ru.X >> adim_.ru.Y >> adim_.ru.Z
		>> adim_.fld.X >> adim_.fld.Y >> adim_.fld.Z
		>> adim_.flu.X >> adim_.flu.Y >> adim_.flu.Z
		>> adim_.frd.X >> adim_.frd.Y >> adim_.frd.Z
		>> adim_.fru.X >> adim_.fru.Y >> adim_.fru.Z;

	in.close();
}

void Match::mainLoop() {
	soundEngine_->play2D("../data/sounds/music/medievalpilgrim.mp3");

	while (isRunning()) {
		driver_->beginScene(true, true, SColor(255,100,101,140));

		armgr_->run();

		static int laststate = 0;
		bool stateSwitch = false;

		int cs = ssw_->whichSide();
		if (cs != -1) {
			if (cs != laststate) {
				laststate = cs;
				stateSwitch = true;
			}
			else
				stateSwitch = false;
		}

		if (stateSwitch) cout << "MAH OE" << endl;


	//	cout << ssw_->whichSide() << endl;

		if (stateSwitch) {
			switch (mstate_->run()) {
				case MatchState::STATE_BAS:
					delete mstate_;
					mstate_ = new BasicState(cards_, !player_, &adim_);
					player_ = !player_;
					if (player_ == 0) bar = p1b;
					else bar = p2b;
					break;
				case MatchState::STATE_ATT:
					delete mstate_;
					mstate_ = new AttackState(cards_, player_, &adim_);
					if (player_ == 0) bar = p2a;
					else bar = p1a;
					break;
				case MatchState::STATE_RES:
					delete mstate_;
					mstate_ = new ResolveState(cards_, player_, &adim_);
					if (player_ == 0) bar = p1r;
					else bar = p2r;
					break;
			}
		}

		// Event handling
		if (eventHandler_->IsKeyDown(KEY_ESCAPE))
			return;

		drawAll();
		driver_->endScene();
	}
}
