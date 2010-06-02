#ifndef ARMAGIC_CAMERA_H_
#define ARMAGIC_CAMERA_H_

#include <string>
#include <ar/ar.h>
#include <ar/gsub.h>
#include <ar/video.h>

#include "Exception.h"

namespace track {

/// This class interfaces with ARTOOLKIT getting the frames from the camera
class Camera {
public:
	Camera(const std::string& videoConfig, const std::string& cparamPath);
	virtual ~Camera();

	char* getFrame() const;
	void capNext() const;

	inline ARParam getCParam() const { return cparam_; }

private:
	std::string videoConfig_;
	std::string cparamPath_;
	ARParam cparam_;
	int sizex_, sizey_;

	mutable char* frame_;
};

}

#endif
