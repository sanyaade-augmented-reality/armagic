#ifndef ARMAGIC_CARD_H_
#define ARMAGIC_CARD_H_

#include "markers.h"
#include "models.h"

const int NUMBER_OF_CARDS = NUMBER_OF_MARKERS;

class Card {
public:
	enum Color {
		COLOR_WHITE,
		COLOR_BLACK,
		COLOR_GREEN,
		COLOR_BLUE,
		COLOR_RED
	};

	inline Color getColor() { return color_; }
	inline std::string getMarker() const { return marker_; }
	inline std::string getModel() const { return model_; }
	inline std::string getTexture() const { return texture_; }
	inline bool getIsCreature() const { return isCreature_; }

	inline double getScaleX() const { return scaleX_; }
	inline double getScaleY() const { return scaleY_; }
	inline double getScaleZ() const { return scaleZ_; }

	inline double getPositionX() const { return positionX_; }
	inline double getPositionY() const { return positionY_; }
	inline double getPositionZ() const { return positionZ_; }

protected:
	Color color_;
	std::string marker_;
	std::string model_;
	std::string texture_;
	bool isCreature_;

	double scaleX_;
	double scaleY_;
	double scaleZ_;

	double positionX_;
	double positionY_;
	double positionZ_;
};

#endif