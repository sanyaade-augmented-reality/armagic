#ifndef ARMAGIC_ARMANAGER_H_
#define ARMAGIC_ARMANAGER_H_

#include <vector>
#include <string>
#include <irrlicht.h>

#include "Card.h"
#include "Tracker.h"
#include "Camera.h"
#include "ARSceneNode.h"

#define __DEBUG

class ARManager {
public:
	ARManager(irr::IrrlichtDevice* device);
	~ARManager();

	void run();
	void addARSceneNode(ARSceneNode* node);
	void drawBackground();
	void fixCamera(irr::scene::ICameraSceneNode* camera);

private:
	Camera* camera_;
	Tracker* tracker_;

	std::vector<ARSceneNode*> nodes_;
	irr::video::ITexture* cameraTexture_;

	irr::IrrlichtDevice* device_;

	void updateCameraTexture(ARUint8* frame);

	// For camera adjustment	FIXME FIXME FIXME FIXME
	float gl_cpara[16];
	void createProjectionMatrix();
	void convertGLPara(double cparam[3][4], int width, int height, double gnear, double gfar, float m[16]);
};


#endif