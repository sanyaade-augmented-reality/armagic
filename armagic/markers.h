#ifndef ARMAGIC_MARKERS_H_
#define ARMAGIC_MARKERS_H_

#include <string>

const int NUMBER_OF_MARKERS = 9;

namespace markers {
enum Marker {
	HIRO,
	SIMPLE_1,
	SIMPLE_2,
	KANJI,
	multiA,
	multiB,
	multiC,
	multiD,
	multiE
};

static const std::string markerInfo[NUMBER_OF_MARKERS];
};


#endif