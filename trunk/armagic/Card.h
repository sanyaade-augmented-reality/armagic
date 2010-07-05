#ifndef ARMAGIC_CARD_H_
#define ARMAGIC_CARD_H_

#include <string>
#include <vector>
#include <irrlicht.h>

using namespace irr;
using irr::core::vector3df;

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
	inline std::string getName() const { return name_; }
	inline core::vector3df getPosition() const { return node_->getAbsolutePosition(); }
	inline Type getType() const { return type_; }
	inline irr::scene::IAnimatedMeshSceneNode* getNode() const { return node_; }
	inline bool isInGame() const { return inGame_; }
	inline void setInGame(const bool b) { inGame_ = b; }

protected:
	Color color_;
	Type type_;
	std::string name_;

	std::string marker_;
	bool inGame_;

	irr::scene::IAnimatedMeshSceneNode* node_;
};

#endif