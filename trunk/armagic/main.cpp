#ifdef _WIN32
#include <windows.h>
#endif
#ifndef __APPLE__
#include <GL/gl.h>
#include <GL/glut.h>
#else
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#endif

#include <AR/gsub.h>
#include <AR/video.h>
#include <AR/param.h>
#include <AR/ar.h>

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

#include "Camera.h"
#include "Exception.h"

using std::string;
using std::cout;
using std::endl;
//
// Camera configuration.
//
#ifdef _WIN32
/*const string*/char*	vconf = "../data/WDM_camera_flipV.xml";
#else
char			*vconf = "";
#endif

int             thresh = 100;
int             count = 0;

/*const string*/const char*    cparam_name    = "../data/camera_para.dat";
ARParam         cparam;

char           *patt_name      = "../data/patt.hiro";
int             patt_id;
double          patt_width     = 80.0;
double          patt_center[2] = {0.0, 0.0};
double          patt_trans[3][4];

static void   init(void);
static void   cleanup(void);
static void   keyEvent( unsigned char key, int x, int y);
static void   mainLoop(void);
static void   draw( void );

track::Camera* camera;

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	init();
	arVideoCapStart();
	argMainLoop( NULL, keyEvent, mainLoop );
	return (0);
}

static void keyEvent( unsigned char key, int x, int y) {
	/* quit if the ESC key is pressed */
	if( key == 0x1b ) {
		printf("*** %f (frame/sec)\n", (double)count/arUtilTimer());
		cleanup();
		exit(0);
	}
}

/* main loop */
static void mainLoop() {
	ARUint8         *dataPtr;
	ARMarkerInfo    *marker_info;
	int             marker_num;
	int             j, k;

	// grab a video frame
	dataPtr = camera->getFrame();

	if( count == 0 ) arUtilTimerReset();
	count++;

	argDrawMode2D();
	argDispImage( dataPtr, 0,0 );

	/* detect the markers in the video frame */
	if( arDetectMarker(dataPtr, thresh, &marker_info, &marker_num) < 0 ) {
		cleanup();
		exit(0);
	}

	arVideoCapNext();

	/* check for object visibility */
	k = -1;
	for( j = 0; j < marker_num; j++ ) {
		if( patt_id == marker_info[j].id ) {
			if( k == -1 ) k = j;
			else if( marker_info[k].cf < marker_info[j].cf ) k = j;
		}
	}
	if( k == -1 ) {
		argSwapBuffers();
		return;
	}

	/* get the transformation between the marker and the real camera */
	arGetTransMat(&marker_info[k], patt_center, patt_width, patt_trans);

	draw();

	argSwapBuffers();
}

static void init( void ) {
	try {
		camera = new track::Camera(vconf, cparam_name);
	}
	catch (Exception e) {
		cout << e.getMessage() << endl;
		exit(-1);
	}

	if( (patt_id=arLoadPatt(patt_name)) < 0 ) {
		printf("pattern load error !!\n");
		exit(0);
	}

	/* open the graphics window */
	argInit(&camera->getCParam(), 1.0, 0, 0, 0, 0);
}

/* cleanup function called when program exits */
static void cleanup(void)
{
	arVideoCapStop();
	arVideoClose();
	argCleanup();
}

static void draw( void )
{
	double    gl_para[16];
	GLfloat   mat_ambient[]     = {0.0, 0.0, 1.0, 1.0};
	GLfloat   mat_flash[]       = {0.0, 0.0, 1.0, 1.0};
	GLfloat   mat_flash_shiny[] = {50.0};
	GLfloat   light_position[]  = {100.0,-200.0,200.0,0.0};
	GLfloat   ambi[]            = {0.1, 0.1, 0.1, 0.1};
	GLfloat   lightZeroColor[]  = {0.9, 0.9, 0.9, 0.1};

	argDrawMode3D();
	argDraw3dCamera( 0, 0 );
	glClearDepth( 1.0 );
	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	/* load the camera transformation matrix */
	argConvGlpara(patt_trans, gl_para);
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd( gl_para );

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambi);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightZeroColor);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_flash);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_flash_shiny);	
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef( 0.0, 0.0, 25.0 );
	glutSolidCube(50.0);
	glDisable( GL_LIGHTING );

	glDisable( GL_DEPTH_TEST );
}