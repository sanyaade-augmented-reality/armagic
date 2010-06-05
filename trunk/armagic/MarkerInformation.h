#ifndef ARMAGIC_MARKERINFORMATION_H_
#define ARMAGIC_MARKERINFORMATION_H_

#include <string>

const int NUMBER_OF_MARKERS = 4;

namespace markers {
enum Marker {
	HIRO,
	SIMPLE_1,
	SIMPLE_2,
	KANJI
};

static const std::string markerInfo[NUMBER_OF_MARKERS];
};


#endif