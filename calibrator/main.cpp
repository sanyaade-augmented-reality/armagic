#include "../armagic/irrar.h"

#include <iostream>
#include <fstream>

using namespace std;

using namespace irrAr;

#define WIN_WIDTH 1024
#define WIN_HEIGHT 768

IrrlichtDevice *device;
IVideoDriver* driver;
ISceneManager* smgr;
IARManager* armgr;

ofstream out;
vector3df pos;

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
					default:
						cout << "asd" << endl;
						out << pos.X << " " << pos.Y << " " << pos.Z << endl;
						break;
				}
			}
			return false;
		}
};

int main()
{
	out.open("../data/arconfig.txt");

	bool fullscreen = false;
	MyEventReceiver receiver;

	
	device = createDevice( video::EDT_OPENGL, dimension2d<u32>(WIN_WIDTH, WIN_HEIGHT), 16, fullscreen, false, false, &receiver);
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();

	device->setWindowCaption(L"ARMagic Calibrator");

	//something for 3d reference
	IAnimatedMesh* mesh = smgr->getMesh("../data/models/sydney.md2");
	IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(mesh);
	if (node)
	{
		node->setMaterialTexture( 0, driver->getTexture("../data/models/sydney.bmp") );
		node->setMaterialFlag(EMF_LIGHTING, false);
		node->setMD2Animation(scene::EMAT_POINT);
		node->setPosition(vector3df(0,50,0));
		node->setScale(vector3df(2,2,2));
	}

	//camera stuff
	vector3df camera_pos = vector3df(0,0,0);
	vector3df camera_target = vector3df(0,0,1);
	ICameraSceneNode* camera = smgr->addCameraSceneNode(0, camera_pos, camera_target);
	
	//AR stuff
	IARManager* armgr = new IARManager(device);
	//init the camera
	armgr->beginCamera("../data/camera/camera_para.dat","../data/camera/WDM_camera_flipV.xml", "-dev=/dev/video0");
	//node for the lady, attached the the hiro pattern
	armgr->addARSceneNode("../data/markers/patt.hiro", node);
	//now fix our camera to display right
	armgr->fixCamera(camera);


	cout << "BOARD";
	cout << "\nLeft Down";
	cout << "\nLeft Up";
	cout << "\nRight Down";
	cout << "\nRight Up";
	
	cout << "FIGHT";
	cout << "\nLeft Down";
	cout << "\nLeft Up";
	cout << "\nRight Down";
	cout << "\nRight Up";

	while(device->run())
	{
		driver->beginScene(true, true, SColor(255,100,101,140));
		
		//make movements and bring in new image
		armgr->run();

		pos = node->getAbsolutePosition();

		//cout << pos.X << " " << pos.Y << " " << pos.Z << endl;

		
		//draw the background image centered and scaled
		armgr->drawBackground();

		smgr->drawAll();

		driver->endScene();
	}

	device->drop();

	return 0;
}
