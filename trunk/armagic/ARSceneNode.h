#ifndef ARMAGIC_ARSCENENODE_H_
#define ARMAGIC_ARSCENENODE_H_

#include <irrlicht.h>
#include <ar/ar.h>
#include <string>
#include <map>

class ARSceneNode{
public:
	ARSceneNode(irr::IrrlichtDevice* device, const std::string& patt,
		const std::string& model, const std::string& texture, const float scale);
	ARSceneNode(irr::IrrlichtDevice* device, const std::string& patt,
		irr::scene::IAnimatedMeshSceneNode* node);
	~ARSceneNode();

	irr::scene::IAnimatedMeshSceneNode* getNode() const { return node_; }
	int getPattId() const { return pattId_; }

private:
	static std::map<std::string, int> patterns_;

	std::string pattPath_;
	int pattId_;
	irr::scene::IAnimatedMeshSceneNode* node_;

	irr::scene::ISceneManager* smgr_;
	irr::video::IVideoDriver* driver_;
};

#endif