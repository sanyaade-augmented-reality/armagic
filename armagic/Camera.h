#ifndef ARMAGIC_CAMERA_H_
#define ARMAGIC_CAMERA_H_

#ifdef _WIN32
#include <windows.h>
#endif

#include <AR/gsub.h>
#include <AR/video.h>
#include <AR/param.h>
#include <AR/ar.h>

namespace track {

/// This class interfaces with ARTOOLKIT getting the frames from the camera
class Camera {
public:
	Camera();
	virtual ~Camera();



private:
};

}

#endif