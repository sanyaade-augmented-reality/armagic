#ifndef ARMAGIC_ARMANAGER_H_
#define ARMAGIC_ARMANAGER_H_

#include <vector>
#include <string>
#include <irrlicht.h>

#include "Card.h"
#include "Tracker.h"
#include "Camera.h"
#include "ARSceneNode.h"

class ARManager {
public:
	ARManager();
	~ARManager();

	void run();
	void addARSceneNode(ARSceneNode* node);

private:
	Camera* camera_;
	Tracker* tracker_;

	std::vector<ARSceneNode*> nodes_;
};


#endif