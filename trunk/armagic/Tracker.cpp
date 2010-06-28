#include "Tracker.h"

using namespace irr::core;

Tracker::Tracker() {
	image_ = NULL;
	treshold_ = 100;
	markerNum_ = 0;
	markerInfo_ = NULL;
	pattWidth_ = 80.0;
	pattCenter_[0] = pattCenter_[1] = 0.0;
}

Tracker::~Tracker() { }

void Tracker::loadImage(ARUint8 *image) {
	image_ = image;
	// Detect all markers
	arDetectMarker(image_, treshold_, &markerInfo_, &markerNum_);
}

bool Tracker::trackMarker(const int patt, CMatrix4<float> &matrix) {
	int found = -1;
	//find most visible detection of this pattern
	for (int i = 0; i < markerNum_; i++ ) {
		if (patt == markerInfo_[i].id) {
			if(found == -1)
				found = i;
			else if (markerInfo_[found].cf < markerInfo_[i].cf)
				found = i;
		}
	}
	if (found == -1) {
		return false;
	}

	// Now we get the transformation matrix of the marker
	double trans[3][4];
	float glPara[16];
	arGetTransMat(&markerInfo_[found], pattCenter_, pattWidth_, trans);
	// Converts to known format (???)
	convertTransPara(trans, glPara);
	// Sets the matrix
	matrix.setM(glPara);
	return true;
}

void Tracker::convertTransPara(double trans[3][4], float gl_para[16]) {
	int i, j;

	for( j = 0; j < 3; j++ ) {
		for( i = 0; i < 4; i++ ) {
			gl_para[i*4+j] = (float) trans[j][i];
		}
	}
	gl_para[0*4+3] = gl_para[1*4+3] = gl_para[2*4+3] = 0.0f;
	gl_para[3*4+3] = 1.0f;
}