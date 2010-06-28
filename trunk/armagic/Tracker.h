#ifndef ARMAGIC_TRACKER_H_
#define ARMAGIC_TRACKER_H_

#include <irrlicht.h>
#include <AR/video.h>
#include <AR/param.h>
#include <AR/ar.h>

// Tracker is the vision core of ARMagic
// This class interfaces with ARTOOLKIT PLUS providing tracking information
class Tracker {
public:
	Tracker();
	~Tracker();

	void loadImage(ARUint8* image);
	void setTreshold(const int tresh);
	bool trackMarker(const int patt, irr::core::CMatrix4<float>& matrix);

private:
	ARUint8* image_;
	int treshold_;

	int markerNum_;
	ARMarkerInfo* markerInfo_;

	double pattWidth_;
	double pattCenter_[2];

	// Aux functions
	void convertTransPara(double trans[3][4], float gl_para[16]);
};


#endif