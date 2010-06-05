#ifndef ARMAGIC_CARD_H_
#define ARMAGIC_CARD_H_

#include "MarkerInformation.h"

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

protected:
	Color color_;
	markers::Marker markerId_;

};

#endif