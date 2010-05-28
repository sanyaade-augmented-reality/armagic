#ifndef ARMAGIC_CAMERA_H_
#define ARMAGIC_CAMERA_H_

#ifdef _WIN32
#include <windows.h>
#endif

#include <string>

#include <AR/gsub.h>
#include <AR/video.h>
#include <AR/param.h>
#include <AR/ar.h>

#include "Exception.h"

namespace track {

/// This class interfaces with ARTOOLKIT getting the frames from the camera
class Camera {
public:
	Camera(const std::string& videoConfig, const std::string& cparamPath);
	virtual ~Camera();

	ARUint8* getFrame();

private:
	std::string videoConfig_;
	std::string cparamPath_;
	ARParam cparam_;
	int sizex_, sizey_;

	ARUint8* frame_;
};

}

#endif