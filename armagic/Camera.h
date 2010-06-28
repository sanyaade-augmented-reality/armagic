#ifndef ARMAGIC_CAMERA_H_
#define ARMAGIC_CAMERA_H_

#include <string>
#include <ar/ar.h>
#include <ar/gsub.h>
#include <ar/video.h>
#include <irrlicht.h>

#include "Exception.h"

/// This class interfaces with ARTOOLKIT getting the frames from the camera
class Camera {
public:
	Camera(const std::string& videoConfig, const std::string& cparamPath);
	virtual ~Camera();

	ARUint8* getFrame() const;
	void capNext() const;

	inline ARParam getCParam() const { return cparam_; }
	inline irr::core::dimension2di getDimensions() const { return dimensions_; }

private:
	std::string videoConfig_;
	std::string cparamPath_;
	ARParam cparam_;
	irr::core::dimension2di dimensions_;

	mutable ARUint8* frame_;
};

#endif
