#ifndef _TEST_APP
#define _TEST_APP

//#define USE_IR // Uncomment this to use infra red instead of RGB cam...

#include "ofMain.h"
#include "ofxOpenNI.h"
#include "ofxXmlSettings.h"
#include "ofxUI.h"
#include "comms/SpaceBroadcaster.h"
#include "comms/SpaceReporter.h"
#include "comms/UserDetail.h"

class testApp: public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);

	ofxXmlSettings XML;
	bool fullscreen;
	uint moteCount;
	ofColor mainDrawColor;
	vector<UserDetail*> usersDetail;

	ofxUICanvas *gui;
	void exit();
	void guiEvent(ofxUIEventArgs &e);
	bool hideGUI;

	ofxUICanvas *gui1;
	ofxUICanvas *gui2;

	void setGUI1();
	void setGUI2();

	comms::SpaceBroadcaster spaceBroadcast;
	comms::SpaceReporter spaceReport;
	string msgTx, msgRx;

	void getUserCenters(ofxUserGenerator &userGenerator);

	/*** kinect stuff ****/
	void setupRecording(string _filename = "");
	void setupPlayback(string _filename);
	void setupKinect();
	void updateKinect();
	void drawKinect();
	string generateFileName();

	bool isLive, isTracking, isRecording, isCloud, isCPBkgnd, isMasking;
	bool isTrackingHands, isFiltering;

	ofxOpenNIContext recordContext, playContext;
	ofxDepthGenerator recordDepth, playDepth;

#ifdef USE_IR
	ofxIRGenerator recordImage, playImage;
#else
	ofxImageGenerator recordImage, playImage;
#endif

	ofxHandGenerator recordHandTracker, playHandTracker;

	ofxUserGenerator recordUser, playUser;
	ofxOpenNIRecorder oniRecorder;

#if defined (TARGET_OSX) //|| defined(TARGET_LINUX) // only working on Mac/Linux at the moment (but on Linux you need to run as sudo...)
	ofxHardwareDriver hardware;
#endif

	void drawMasks();
	void drawPointCloud(ofxUserGenerator * user_generator, int userID);

	int nearThreshold, farThreshold;
	int pointCloudRotationY;

	ofImage allUserMasks, user1Mask, user2Mask, depthRangeMask;

	float filterFactor;
	/*** kinect stuff end ****/

};

#endif
