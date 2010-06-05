#include "irrAR.h"
#include <iostream>

#define DPATH "../data/"


using namespace irrAr;
using std::cout;
using std::endl;

IrrlichtDevice* device;
IVideoDriver* driver;
ISceneManager* smgr;
IARManager* armgr;

class MyEventReceiver : public IEventReceiver
{
public:
	virtual bool OnEvent(const SEvent &event)
	{ 
		if (event.EventType == EET_KEY_INPUT_EVENT && !event.KeyInput.PressedDown)
		{
			switch(event.KeyInput.Key)
			{
			case KEY_ESCAPE:
				device->closeDevice();
				return true;
			}
		}
		return false;
	}
};

int main()
{
	const bool fullscreen = false;
	MyEventReceiver receiver;


	device = createDevice( video::EDT_OPENGL, dimension2d<u32>(640, 480), 32, fullscreen, false, true, &receiver);
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();

	device->setWindowCaption(L"ARMagic");

	//something for 3d reference
	IAnimatedMesh* mesh = smgr->getMesh(DPATH"models/sydney.md2");
	IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(mesh);
	if (node)
	{
		node->setMaterialTexture( 0, driver->getTexture(DPATH"media/sydney.bmp") );
		node->setMaterialFlag(EMF_LIGHTING, false);
		node->setMD2Animation(scene::EMAT_POINT);
		node->setPosition(vector3df(0,50,0));
		node->setScale(vector3df(2,2,2));
	}
	else {
		cout << "no node" << endl;
		exit(-1);
	}

	//fairy
	IAnimatedMeshSceneNode* fairy = smgr->addAnimatedMeshSceneNode(smgr->getMesh(DPATH"models/faerie.md2"));
	if (fairy)
	{
		fairy->setMaterialTexture(0, driver->getTexture(DPATH"media/faerie2.bmp"));
		fairy->setMaterialFlag(video::EMF_LIGHTING, false);
		fairy->setMD2Animation(scene::EMAT_POINT);
		fairy->setScale(vector3df(2,2,2));
		fairy->setPosition(vector3df(0,45,0));
		fairy->setRotation(vector3df(0,180,0));
	}
	else {
		cout << "no fairy" << endl;
		exit(-1);
	}

	//dwarf
	IAnimatedMeshSceneNode* skeleton = smgr->addAnimatedMeshSceneNode(smgr->getMesh(DPATH"models/skeleton.3DS"));
	if (skeleton) {
		skeleton->setMaterialTexture(0,driver->getTexture(DPATH"media/skeleton.jpg"));
		skeleton->setRotation(vector3df(0,180,0));
		skeleton->setMaterialFlag(video::EMF_LIGHTING, false);
		//skeleton->setAnimationSpeed(15);
	}
	else {
		cout << "no skeleton" << endl;
		exit(-1);
	}
	

	//water
	mesh = smgr->addHillPlaneMesh("myHill", dimension2d<f32>(20,20), dimension2d<u32>(3,2), 0, 0, dimension2d<f32>(0,0), dimension2d<f32>(10,10));
	ISceneNode* water = smgr->addWaterSurfaceSceneNode(mesh->getMesh(0), 3.0f, 300.0f, 30.0f);
	//water->setMaterialTexture(0, driver->getTexture(DPATH"media/lands/stones.jpg"));
	water->setMaterialTexture(1, driver->getTexture(DPATH"media/lands/blue1.jpg"));
	water->setMaterialType(video::EMT_REFLECTION_2_LAYER);
	water->setMaterialFlag(video::EMF_LIGHTING, false);
	water->setPosition(vector3df(0,-50,0));
	water->setParent(node);

	//grass
	mesh = smgr->addHillPlaneMesh("faerieHill",dimension2d<f32>(20,20),dimension2d<u32>(3,2),0,0,dimension2d<f32>(0,0),dimension2d<f32>(10,10));
	ISceneNode* grass = smgr->addWaterSurfaceSceneNode(mesh->getMesh(0), 3.0f, 300.0f, 30.0f);
	grass->setMaterialTexture(0,driver->getTexture(DPATH"media/lands/green1.jpg"));
	grass->setMaterialType(video::EMT_REFLECTION_2_LAYER);
	grass->setMaterialType(video::EMT_LIGHTMAP_LIGHTING);
	grass->setPosition(vector3df(0,-25,0));
	grass->setParent(fairy);

	//camera stuff
	vector3df camera_pos = vector3df(0,0,0);
	vector3df camera_target = vector3df(0,0,1);
	ICameraSceneNode* camera = smgr->addCameraSceneNode(0, camera_pos, camera_target);

	//AR stuff
	IARManager* armgr = new IARManager(device);
	//init the camera
	armgr->beginCamera(DPATH"ardata/camera_para.dat",DPATH"ardata/WDM_camera_flipV.xml", "-dev=/dev/video0");
	
	//node for the lady, attached the the hiro pattern
	armgr->addARSceneNode(DPATH"markers/patt.hiro", node);
	//node for the fairy and water, attached the the sample1 pattern
	armgr->addARSceneNode(DPATH"markers/multi/patt.c", fairy);
	//node for the dwarf, attached to a multi-pattern
	//armgr->addARMultiSceneNode(DPATH"markers/patt.simple1", skeleton);
	//now fix our camera to display right
	armgr->fixCamera(camera);

	while(device->run())
	{
		driver->beginScene(true, true, SColor(255,100,101,140));

		//make movements and bring in new image
		armgr->run();

		//draw the background image centered and scaled
		armgr->drawBackground();

		smgr->drawAll();

		driver->endScene();
	}

	device->drop();

	return 0;
}
