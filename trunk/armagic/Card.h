#ifndef ARMAGIC_CARD_H_
#define ARMAGIC_CARD_H_

#include <string>
#include <irrlicht.h>

using namespace irr;

class Card {
public:
	enum Color {
		COLOR_WHITE,
		COLOR_BLACK,
		COLOR_GREEN,
		COLOR_BLUE,
		COLOR_RED
	};
	enum Type {
		CARD_LAND,
		CARD_CREATURE
	};

	Card(const Color color, const std::string& marker, const std::string& name,
		irr::scene::IAnimatedMeshSceneNode* node);

	Card();
	virtual ~Card();

	inline Color getColor() { return color_; }
	inline std::string getMarker() const { return marker_; }
	//inline std::string getModel() const { return model_; }
	//inline std::string getTexture() const { return texture_; }
	inline std::string getName() const { return name_; }
	//inline double getScale() const { return scale_; }
	inline core::vector3df getPosition() const { return position_; }
	inline Type getType() const { return type_; }
	inline irr::scene::IAnimatedMeshSceneNode* getNode() const { return node_; }

protected:
	Color color_;
	Type type_;
	std::string name_;
	std::string marker_;

	irr::core::vector3df position_;
	irr::scene::IAnimatedMeshSceneNode* node_;
};

#endif