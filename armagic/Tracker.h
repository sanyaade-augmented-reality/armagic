#ifndef ARMAGIC_TRACKER_H_
#define ARMAGIC_TRACKER_H_

#include "Camera.h"
#include <ARToolKitPlus/TrackerMultiMarkerImpl.h>


namespace track {

// Tracker is the vision core of ARMagic
// This class interfaces with ARTOOLKIT PLUS providing tracking information
class Tracker {
public:
	Tracker();
	virtual ~Tracker();

private:
	Camera* camera_;
};

}

#endif