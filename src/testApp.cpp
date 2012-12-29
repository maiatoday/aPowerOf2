#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	if (XML.loadFile("mySettings.xml")) {
		serverAddress = XML.getValue("NETWORK:SERVER_ADDRESS", "localhost");
		updateTime = XML.getValue("NETWORK:UPDATE_INTERVAL", 2000);
		moteCount = XML.getValue("GENERAL:MOTE_COUNT", 100);
		fullscreen = (XML.getValue("GENREAL:FULLSCREEN", 1) == 1) ? true : false;
		ofLogNotice("settings read from mySettings.xml");
		ofLogNotice(serverAddress.c_str());
	}

}

//--------------------------------------------------------------
void testApp::update() {

}

//--------------------------------------------------------------
void testApp::draw() {

}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {

	float smooth;

	switch (key) {
	case 's':
	case 'S':

		break;
	case 'p':
	case 'P':
		break;
	case 't':
	case 'T':
		break;
	case 'h':
	case 'H':
		break;
	case 'f':
	case 'F':
		break;
	case 'm':
	case 'M':
		break;
	case 'c':
	case 'C':
		break;
	case 'b':
	case 'B':
		break;
	case '9':
	case '(':
		break;
	case '0':
	case ')':
		break;
	case '[':
		break;
	case ']':
		break;
	case ';':
	case ':':
		break;
	case '\'':
	case '\"':
	case '>':
	case '.':
	case '<':
	case ',':
		break;

	case '+':
	case '=':
		break;

	case '-':
	case '_':
		break;
	case 'r':
		break;
	default:
		break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h) {

}

