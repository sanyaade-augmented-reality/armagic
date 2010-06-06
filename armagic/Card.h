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
	inline void setColor(Color color) { color_ = color; }
	inline std::string getMarker() const { return marker_; }
	inline void setMarker(std::string val) { marker_ = val; }
	inline std::string getModel() const { return model_; }
	inline void setModel(std::string val) { model_ = val; }
	inline std::string getTexture() const { return texture_; }
	inline void setTexture(std::string val) { texture_ = val; }

protected:
	Color color_;
	std::string marker_;
	std::string model_;
	std::string texture_;

};

#endif