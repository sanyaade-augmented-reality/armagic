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
	inline bool isVisible() const { return visible_; }
	inline void setVisible(const bool v) {
		visible_ = v;
		node_->setVisible(v);
	}
	inline void setPosition(irr::core::vector3df pos) {
		/*static int not = 0;
		positions_.push_back(pos);
		if (positions_.size() == 5)
			positions_.erase(positions_.begin());
		float x = 0, y = 0, z = 0;
		for (int i = 0; i < positions_.size(); i++) {
			x += positions_[i].X;
			y += positions_[i].Y;
			z += positions_[i].Z;
		}
		node_->setPosition(vector3df(x, y, z));*/
		node_->setPosition(pos);
	}
	inline void setDirection(vector3df dir) { node_->setRotation(dir); }

protected:
	Color color_;
	Type type_;
	std::string name_;

	std::string marker_;
	bool visible_;

	irr::scene::IAnimatedMeshSceneNode* node_;
};

#endif