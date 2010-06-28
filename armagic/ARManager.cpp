#include "ARManager.h"

using namespace irr::core;
using namespace irr::scene;

ARManager::ARManager() {
	camera_ = new Camera("../data/camera/WDM_camera_flipV.xml", "../data/camera/camera_para.dat");
	tracker_ = new Tracker;
}

ARManager::~ARManager() {
	delete camera_;
	delete tracker_;
}

void ARManager::run() {
	ARUint8* frame = camera_->getFrame();
	for (int i = 0; i < nodes_.size(); i++) {
		CMatrix4<float> matrix;
		// Reference to node
		IAnimatedMeshSceneNode* node = nodes_[i]->getNode();
		if (tracker_->trackMarker(nodes_[i]->getPattId(), matrix)) {
			vector3df rotation = matrix.getRotationDegrees();
			vector3df position = matrix.getTranslation();
			rotation.X -= 90;
			node->setRotation(rotation);
			node->setPosition(position);
			node->setVisible(true);			
		}
		else {
			node->setVisible(false);
		}
	}

}

void ARManager::addARSceneNode(ARSceneNode* node) {
	nodes_.push_back(node);
}