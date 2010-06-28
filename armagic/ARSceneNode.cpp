#include "ARSceneNode.h"

using namespace irr::core;

ARSceneNode::ARSceneNode(irr::IrrlichtDevice* device, const std::string& patt,
						 const std::string& model, const std::string& texture, const float scale)
{
	driver_ = device->getVideoDriver();
	smgr_ = device->getSceneManager();

	// Node
	node_ = smgr_->addAnimatedMeshSceneNode(smgr_->getMesh(model.c_str()));
	node_->setMaterialTexture(0, driver_->getTexture(texture.c_str()));
	node_->setRotation(vector3df(0,180,0));
	node_->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	node_->setAnimationSpeed(15);
	node_->setScale(vector3df(scale, scale, scale));

	// Pattern
	pattId_ = arLoadPatt(patt.c_str());
}

ARSceneNode::ARSceneNode(irr::IrrlichtDevice* device, const std::string& patt, irr::scene::IAnimatedMeshSceneNode* node) {
	driver_ = device->getVideoDriver();
	smgr_ = device->getSceneManager();

	node_ = node;
	pattId_ = arLoadPatt(patt.c_str());
}

ARSceneNode::~ARSceneNode() {
	delete node_;
}

