#ifndef _TEST_APP
#define _TEST_APP

//#define USE_IR // Uncomment this to use infra red instead of RGB cam...

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxUI.h"

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
	string serverAddress;
	uint updateTime;
	bool fullscreen;
	uint moteCount;

	ofxUICanvas *gui;
	void exit();
	void guiEvent(ofxUIEventArgs &e);
	bool hideGUI;

	ofxUICanvas *gui1;
	ofxUICanvas *gui2;

	void setGUI1();
	void setGUI2();
};

#endif