#ifndef ARMAGIC_CARD_H_
#define ARMAGIC_CARD_H_

class Card {
public:
	Card();
	virtual ~Card();

	// Just signaling that this is an abstract class
	virtual void foo() = 0;

protected:
private:
};

#endif