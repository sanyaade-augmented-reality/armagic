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
	inline markers::Marker getMarkerId() { return markerId_; }
	inline void setMarkerId(markers::Marker id) { markerId_ = id; }
	inline models::Model getModel() { return model_; }
	inline void setModel(models::Model m) { model_ = m; }


protected:
	Color color_;
	markers::Marker markerId_;
	models::Model model_;

};

#endif