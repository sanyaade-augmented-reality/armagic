#ifndef ARMAGIC_CARD_H_
#define ARMAGIC_CARD_H_

class Card {
public:
	enum Color {
		COLOR_WHITE,
		COLOR_BLACK,
		COLOR_GREEN,
		COLOR_BLUE,
		COLOR_RED
	};


protected:
	Color color_;
	int markerId_;

};

#endif