#include "Camera.h"

using namespace track;

Camera::Camera(const std::string& videoConfig, const std::string& cparamPath) {
	ARParam wparam;

	videoConfig_ = videoConfig;
	cparamPath_ = cparamPath;
	if (arVideoOpen(const_cast<char*>(videoConfig_.c_str())) < 0)
		throw Exception("arVideoOpen exception");
	if (arVideoInqSize(&sizex_, &sizey_) < 0)
		throw Exception("arVideoInqSize exception");
	if (arParamLoad(cparamPath_.c_str(), 1, &wparam) < 0)
		throw Exception("arParamLoad exception");
	arParamChangeSize(&wparam, sizex_, sizey_, &cparam_);
	arInitCparam(&cparam_);
	arParamDisp(&cparam_);
}

Camera::~Camera() {
	arVideoCapStop();
	arVideoClose();
	argCleanup();
}

ARUint8* Camera::getFrame() const {
	while ( (frame_ = (ARUint8*)arVideoGetImage()) == NULL )
		arUtilSleep(2);
	return frame_;
}

void Camera::capNext() const {
	arVideoCapNext();
}