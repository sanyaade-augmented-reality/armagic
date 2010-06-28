#include "ARManager.h"

#ifdef __DEBUG
#include <iostream>
using namespace std;
#endif

using namespace irr::core;
using namespace irr::scene;

ARManager::ARManager(irr::IrrlichtDevice* device) {
	device_ = device;
	camera_ = new Camera("../data/camera/WDM_camera_flipV.xml", "../data/camera/camera_para.dat");
	tracker_ = new Tracker;
	
	createProjectionMatrix();
	// Create camera texture
	const dimension2d<u32> dim_u32 = static_cast<dimension2d<u32> >(camera_->getDimensions());
	cameraTexture_ = device->getVideoDriver()->addTexture(dim_u32, "Camera_Texture", video::ECF_A8R8G8B8);
}

ARManager::~ARManager() {
	delete camera_;
	delete tracker_;
}

void ARManager::run() {
	ARUint8* frame = camera_->getFrame();
	updateCameraTexture(frame);
	for (int i = 0; i < nodes_.size(); i++) {
		CMatrix4<float> matrix;
		// Reference to node
		IAnimatedMeshSceneNode* node = nodes_[i]->getNode();
		if (tracker_->trackMarker(nodes_[i]->getPattId(), matrix)) {
			vector3df rotation = matrix.getRotationDegrees();
			vector3df position = matrix.getTranslation();
			rotation.X -= 90;
			node->setRotation(rotation);
			node->setPosition(position);
			node->setVisible(true);			
		}
		else {
			node->setVisible(false);
		}
	}
}

void ARManager::addARSceneNode(ARSceneNode* node) {
	nodes_.push_back(node);
}

void ARManager::updateCameraTexture(ARUint8* frame) {
	u8* pixels;
	pixels = (u8*)(cameraTexture_->lock());
	if (pixels) {
		int max_pixels = cameraTexture_->getSize().Width * cameraTexture_->getSize().Height;

#if (AR_DEFAULT_PIXEL_FORMAT == AR_PIXEL_FORMAT_BGR)
		for(int i=0;i<max_pixels;i++) {
			*pixels = *frame;
			pixels++; frame++;
			*pixels = *frame;
			pixels++; frame++;
			*pixels = *frame;
			pixels++; frame++;

			pixels++;
		}

#elif (AR_DEFAULT_PIXEL_FORMAT == AR_PIXEL_FORMAT_BGRA)
		for(int i=0;i<max_pixels;i++) {
			*pixels = *frame;
			pixels++; frame++;
			*pixels = *frame;
			pixels++; frame++;
			*pixels = *frame;
			pixels++; frame++;
			*pixels = *frame;
			pixels++; frame++;
		}
#endif
		cameraTexture_->unlock();
	}
}

void ARManager::drawBackground() {
	irr::video::IVideoDriver* driver = device_->getVideoDriver();
	const dimension2d<u32> scrnSize = driver->getScreenSize();
	const dimension2d<u32> imgSize = cameraTexture_->getSize();

	driver->draw2DImage(this->cameraTexture_, rect<s32>(0,0,scrnSize.Width,scrnSize.Height), rect<s32>(0,0,imgSize.Width,imgSize.Height));
}

void ARManager::fixCamera(irr::scene::ICameraSceneNode* camera) {
	irr::core::matrix4 projection_matrix;

	projection_matrix.setM(this->gl_cpara);

	camera->setProjectionMatrix(projection_matrix);
	camera->setPosition(vector3df(0,0,0));
	camera->setTarget(vector3df(0,0,1));
}

// THIS IS NOT MY CODE
// THANKS TO IRRAR
#define   MINIWIN_MAX    8
#define   GMINI          2
void ARManager::createProjectionMatrix() {
	ARParam _cparam = camera_->getCParam();	// OMG FIXME
	ARParam* cparam = &_cparam;
	const double zoom = 1.0;
	const int fullFlag = 0;
	int xwin = 0;
	int ywin = 0;
	const int hmd_flag = 0;

	int i;
	static int      gl_hmd_flag = 0;
	static double   gZoom;
	static int      gImXsize, gImYsize;
	static int      gXsize, gYsize;
	static int      gMiniXsize, gMiniYsize;
	static int      gMiniXnum,  gMiniYnum;
	static int      gWinXsize, gWinYsize;
	static ARParam  gCparam;

	gl_hmd_flag = hmd_flag;
	gZoom  = zoom;
	gImXsize = cparam->xsize;
	gImYsize = cparam->ysize;
	if( gl_hmd_flag == 0 ) 
	{
		gXsize = (int)((double)cparam->xsize * gZoom);
		gYsize = (int)((double)cparam->ysize * gZoom);
	}
	else 
	{
		gXsize = AR_HMD_XSIZE;
		gYsize = AR_HMD_YSIZE;
	}
	gMiniXsize = (int)((double)cparam->xsize * gZoom / GMINI);
	gMiniYsize = (int)((double)cparam->ysize * gZoom / GMINI);

	if( xwin * ywin > MINIWIN_MAX ) 
	{
		if( xwin > MINIWIN_MAX ) xwin = MINIWIN_MAX;
		ywin = MINIWIN_MAX / xwin;
	}
	gMiniXnum = xwin;
	gMiniYnum = ywin;
	gWinXsize = (gMiniXsize*gMiniXnum > gXsize)? gMiniXsize*gMiniXnum: gXsize;
	gWinYsize = gYsize + gMiniYsize*gMiniYnum;

	gCparam = *cparam;
	for( i = 0; i < 4; i++ ) 
		gCparam.mat[1][i] = (gCparam.ysize-1)*(gCparam.mat[2][i]) - gCparam.mat[1][i];

	this->convertGLPara (gCparam.mat, gCparam.xsize, gCparam.ysize, AR_GL_CLIP_NEAR, AR_GL_CLIP_FAR, gl_cpara);
}

void ARManager::convertGLPara(double cparam[3][4], int width, int height, double gnear, double gfar, float m[16])
{
	double   icpara[3][4];
	double   trans[3][4];
	double   p[3][3], q[4][4];
	int      i, j;


	if( arParamDecompMat(cparam, icpara, trans) < 0 ) 
	{
		printf("gConvGLcpara: Parameter error!!\n");
		exit(0);
	}

	for( i = 0; i < 3; i++ ) {
		for( j = 0; j < 3; j++ ) {
			p[i][j] = icpara[i][j] / icpara[2][2];
		}
	}
	m[0] = q[0][0] = (2.0 * p[0][0] / width);
	m[1] = q[0][1] = (2.0 * p[0][1] / width);
	m[2] = q[0][2] = ((2.0 * p[0][2] / width)  - 1.0);
	m[3] = q[0][3] = 0.0;

	m[4] = q[1][0] = 0.0;
	m[5] = q[1][1] = (2.0 * p[1][1] / height);
	m[6] = q[1][2] = ((2.0 * p[1][2] / height) - 1.0);
	m[7] = q[1][3] = 0.0;

	m[8] = q[2][0] = 0.0;
	m[9] = q[2][1] = 0.0;
	m[10] = q[2][2] = (gfar + gnear)/(gfar - gnear);
	m[11] = q[2][3] = -2.0 * gfar * gnear / (gfar - gnear);

	m[12] = q[3][0] = 0.0;
	m[13] = q[3][1] = 0.0;
	m[14] = q[3][2] = 1.0; //-1.0;
	m[15] = q[3][3] = 0.0;


	for( i = 0; i < 4; i++ ) {
		for( j = 0; j < 3; j++ ) {
			m[i+j*4] = q[i][0] * trans[0][j] 
			+ q[i][1] * trans[1][j]
			+ q[i][2] * trans[2][j];
		}
		m[i+3*4] = q[i][0] * trans[0][3]
		+ q[i][1] * trans[1][3]
		+ q[i][2] * trans[2][3]
		+ q[i][3];
	}
}