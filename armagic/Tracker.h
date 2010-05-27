#ifndef ARMAGIC_TRACKER_H_
#define ARMAGIC_TRACKER_H_

#include <ARToolKitPlus/TrackerMultiMarkerImpl.h>

#include "Camera.h"

namespace track {

// Tracker is the vision core of ARMagic
// This class interfaces with ARTOOLKIT PLUS providing tracking information
class Tracker {
public:
	Tracker();
	virtual ~Tracker();

private:
	Camera camera_;
};

}

#endif