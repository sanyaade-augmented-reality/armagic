#include "Match.h"
#include <irrXML.h>
//using namespace irr; // irrXML is located 
//using namespace io;  // in the namespace irr::io
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace irrAr;
using namespace irrklang;
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
using namespace std;

Match::Match(IrrlichtDevice* device, ISoundEngine* soundEngine,
			 EventHandler* eventHandler)
			 : device_(device), soundEngine_(soundEngine), eventHandler_(eventHandler)
{
	armgr_ = new IARManager(device_);
	driver_ = device_->getVideoDriver();
	smgr_ = device_->getSceneManager();
	guienv_ = device_->getGUIEnvironment();	

	int numberOfCards = -1;

	setupCamera();
	numberOfCards = loadCards();
	createNodes(numberOfCards);
}

Match::~Match() {
	delete armgr_;
	arVideoCapStop();
	arVideoClose();
}


/// <summary>
/// Return a COLOR enumeration from a Color 
/// </summary>
/// <param name="color">a color CHAR</param>
/// <returns></returns>
Card::Color Match::ReturnColorEnum(char color[6])
{
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



/// <summary>
/// Return a ABILITY enumeration from a ability
/// </summary>
/// <param name="ability">a ability CHAR</param>
/// <returns></returns>
CreatureCard::Ability Match::ReturnAbilityEnum(char ability[3])
{
	if(strcmp(ability,"FLY")==0)
		return CreatureCard::Ability::ABLITY_FLY;
	else if (strcmp(ability,"TRA")==0)
		return CreatureCard::Ability::ABILITY_TRAMPLE;
	else if(strcmp(ability,"INI")==0)
		return CreatureCard::Ability::ABILITY_INICIATIVE;
	else 
		return CreatureCard::Ability::NO_ABILITY;
}
/// <summary>
/// This methods read a pre-located XML file which contains all cards and
/// the information to build the virtual objects of them (model, markers, textures...)
/// </summary>
/// <returns>The total number of cards in the XML file</returns>
int Match::loadCards() {

	// create the reader using one of the factory functions
	IrrXMLReader* xml = createIrrXMLReader("../data/CardsXML.xml");

	
	//The total number of cards in the game (including creatures and lands)
	int numberOfCards = -1;
	int numberOfCreatures = -1;
	int numberOfLands = -1;

	//This bool controls the end of read of a card. When it is true, we can 
	//now instantiate the new card.
	bool IsCardRead = false;

	//The number of the current card
	std::string name = "";
	int cardNumber = -1;
	bool IsCreature = false;

	std::string model;
	std::string texture;
	std::string marker;

	double scaleX = -1;
	double scaleY = -1;
	double scaleZ = -1;

	double positionX = -1;
	double positionY = -1;
	double positionZ = -1;

	char color[6] = "";
	char ability[3] = "";

	int colorlessCost = -1;
	int colorCost = -1;
	int power = -1;
	int toughness = -1;

	while (xml && xml->read())
	{
		switch(xml->getNodeType())
		{
		case EXN_ELEMENT:
			if (strcmp("cards", xml->getNodeName()) == 0)
			{
				numberOfCards = xml->getAttributeValueAsInt("numberOfCards");
				sceneNodes_.resize(numberOfCards);
				cards_.resize(numberOfCards);

				numberOfCreatures = xml->getAttributeValueAsInt("creatureCards");
				numberOfLands = xml->getAttributeValueAsInt("landCards");

			}
			else if (strcmp("card", xml->getNodeName()) == 0)
			{
				name = xml->getAttributeValue("name");
				cardNumber = xml->getAttributeValueAsInt("cardNumber");
				if(strcmp("creature",xml->getAttributeValue("cardType"))==0)
					IsCreature = true;
				else
					IsCreature = false;
			}
			else if (strcmp("model",xml->getNodeName())==0)
				model = xml->getAttributeValue("value");
			else if (strcmp("texture",xml->getNodeName()) == 0)
				texture = xml->getAttributeValue("value");
			else if(strcmp("marker",xml->getNodeName()) == 0)
				marker = xml->getAttributeValue("value");
			else if(strcmp("scale",xml->getNodeName()) == 0)
			{
				scaleX = atof(xml->getAttributeValue("scaleX"));
				scaleY = atof(xml->getAttributeValue("scaleY"));
				scaleZ = atof(xml->getAttributeValue("scaleZ"));
			}
			else if(strcmp("position",xml->getNodeName()) == 0)
			{
				positionX = atof(xml->getAttributeValue("positionX"));
				positionY = atof(xml->getAttributeValue("positionY"));
				positionZ = atof(xml->getAttributeValue("positionZ"));
			}
			else if(strcmp("colors",xml->getNodeName()) == 0)
				strcpy(color, xml->getAttributeValue("value"));
			else if(strcmp("ability",xml->getNodeName()) == 0)
			{
				if(IsCreature)
					strcpy(ability,xml->getAttributeValue("value"));
			}
			else if(strcmp("registers",xml->getNodeName()) == 0)
			{
				//<registers colorless="1" green="0" red="1" blue="0" white="0" black="0" power="1" toughness="2"/>
				if(IsCreature)
				{
					colorlessCost = xml->getAttributeValueAsInt("colorless");

					if(strcmp(color,"green")==0)
						colorCost = xml->getAttributeValueAsInt("green");
					else if(strcmp(color,"red")==0)
						colorCost = xml->getAttributeValueAsInt("red");
					else if(strcmp(color,"blue")==0)
						colorCost = xml->getAttributeValueAsInt("blue");
					else if(strcmp(color,"white")==0)
						colorCost = xml->getAttributeValueAsInt("white");
					else if(strcmp(color,"black")==0)
						colorCost = xml->getAttributeValueAsInt("black");

					power = xml->getAttributeValueAsInt("power");
					toughness = xml->getAttributeValueAsInt("toughness");
				}
				IsCardRead = true;
			}

			if(IsCardRead)
				if(IsCreature)
				{

					//Instantiate the creatures
					cards_[cardNumber] = new CreatureCard(ReturnColorEnum(color),ReturnAbilityEnum(ability),marker,model,texture,true,
						name,power,toughness,colorlessCost,colorCost,
						scaleX,scaleY,scaleZ,positionX,positionY,positionZ);
					
					IsCardRead = false;
				}
				else
				{
					//Instantiate the lands
					cards_[cardNumber] = new LandCard(ReturnColorEnum(color),marker,texture,true,
						scaleX,scaleY,scaleZ,positionX,positionY,positionZ);

					IsCardRead = false;
				}
				break;
		}
	}
	return numberOfCards;
}


// PARA CADA CARTA CRIA-SE UM NODE SEGUINDO O MODELO ABAIXO
// TODOS NO VETOR
void Match::createNodes(const int numberOfCards) {

	for (int i = 0; i < numberOfCards; i++) 
	{
		if(cards_[i]->getIsCreature())
		{
			sceneNodes_[i] = smgr_->addAnimatedMeshSceneNode(smgr_->getMesh((cards_[i]->getModel().c_str())));
			if (sceneNodes_[i]) {
				sceneNodes_[i]->setMaterialTexture(0,driver_->getTexture(cards_[i]->getTexture().c_str()));
				sceneNodes_[i]->setRotation(vector3df(0,180,0));
				sceneNodes_[i]->setMaterialFlag(video::EMF_LIGHTING, false);
				sceneNodes_[i]->setAnimationSpeed(15);
				
				sceneNodes_[i]->setScale(vector3df(((CreatureCard*) cards_[i])->getScaleX(),
					((CreatureCard*) cards_[i])->getScaleY(),
					((CreatureCard*) cards_[i])->getScaleZ()));

				sceneNodes_[i]->setPosition(vector3df(((CreatureCard*) cards_[i])->getPositionX(),
					((CreatureCard*) cards_[i])->getPositionY(),
					((CreatureCard*) cards_[i])->getPositionZ()));
			}
			// Bind with artoolkit
			armgr_->addARSceneNode(cards_[i]->getMarker().c_str(),sceneNodes_[i]);
		}
		else
		{
			//grass
			//sceneNodes_[i] = smgr->addHillPlaneMesh("land",dimension2d<f32>(20,20),dimension2d<u32>(3,2),0,0,dimension2d<f32>(0,0),dimension2d<f32>(10,10));
			//ISceneNode* grass = smgr->addWaterSurfaceSceneNode(mesh->getMesh(0), 3.0f, 300.0f, 30.0f);
			//grass->setMaterialTexture(0,driver->getTexture(cards_[i]->getTexture().c_str()));
			//grass->setMaterialType(video::EMT_REFLECTION_2_LAYER);
			//grass->setMaterialType(video::EMT_LIGHTMAP_LIGHTING);
			//grass->setPosition(vector3df(0,-25,0));
			//grass->setParent(fairy);
		}
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