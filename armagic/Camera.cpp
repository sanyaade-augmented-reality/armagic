#include "Camera.h"


Camera::Camera(const std::string& videoConfig, const std::string& cparamPath) {
	ARParam wparam;

	videoConfig_ = videoConfig;
	cparamPath_ = cparamPath;
	if (arVideoOpen(const_cast<char*>(videoConfig_.c_str())) < 0)
		throw Exception("arVideoOpen exception");
	if (arVideoInqSize(&dimensions_.Width, &dimensions_.Height) < 0)
		throw Exception("arVideoInqSize exception");
	if (arParamLoad(cparamPath_.c_str(), 1, &wparam) < 0)
		throw Exception("arParamLoad exception");
	arParamChangeSize(&wparam, dimensions_.Width, dimensions_.Height, &cparam_);
	arInitCparam(&cparam_);
	arParamDisp(&cparam_);

	arVideoCapStart();
}

Camera::~Camera() {
	arVideoCapStop();
	arVideoClose();
	argCleanup();
}

ARUint8* Camera::getFrame() const {
	while ( (frame_ = arVideoGetImage()) == NULL ) {
		arUtilSleep(2);
	}
	//arVideoCapNext();
	return frame_;
}

void Camera::capNext() const {
	arVideoCapNext();
}