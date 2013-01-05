#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	if (XML.loadFile("mySettings.xml")) {
		serverAddress = XML.getValue("NETWORK:SERVER_ADDRESS", "localhost");
		updateTime = XML.getValue("NETWORK:UPDATE_INTERVAL", 2000);
		moteCount = XML.getValue("GENERAL:MOTE_COUNT", 100);
		fullscreen = (XML.getValue("GENREAL:FULLSCREEN", 1) == 1) ? true : false;
		ofLogNotice("settings read from mySettings.xml");
	}

    gui = new ofxUICanvas(0,0,320,320);
    gui->addWidgetDown(new ofxUILabel("OFXUI TUTORIAL", OFX_UI_FONT_LARGE));
    gui->addSlider("BACKGROUND VALUE",0.0,255.0,100.0,304,16);
    gui->addWidgetDown(new ofxUIToggle(32, 32, false, "FULLSCREEN"));
    ofAddListener(gui->newGUIEvent, this, &testApp::guiEvent);
    gui->loadSettings("GUI/guiSettings.xml");

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
        gui->setDrawWidgetPadding(true);
        break;
    case 'P':
        gui->setDrawWidgetPadding(false);
        break;
	case 't':
	case 'T':
		break;
	case 'h':
	case 'H':
		gui->toggleVisible();
//        gui1->toggleVisible();
//        gui2->toggleVisible();
		break;
	case 'f':
	case 'F':
		fullscreen = !fullscreen;
		ofSetFullscreen(fullscreen);
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
void testApp::exit()
{
    gui->saveSettings("GUI/guiSettings.xml");
    delete gui;
}
//--------------------------------------------------------------
void testApp::guiEvent(ofxUIEventArgs &e)
{
    if(e.widget->getName() == "BACKGROUND VALUE")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        ofBackground(slider->getScaledValue());
    }
    else if(e.widget->getName() == "FULLSCREEN")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        ofSetFullscreen(toggle->getValue());
    }
}

void testApp::setGUI1()
{
//	red = 233; blue = 52; green = 27;

	float dim = 16;
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = 255-xInit;
	hideGUI = false;

    vector<string> names;
	names.push_back("RAD1");
	names.push_back("RAD2");
	names.push_back("RAD3");

	gui1 = new ofxUICanvas(0, 0, length+xInit, ofGetHeight());
	gui1->addWidgetDown(new ofxUILabel("PANEL 1: BASICS", OFX_UI_FONT_LARGE));
    gui1->addWidgetDown(new ofxUILabel("Press 'h' to Hide GUIs", OFX_UI_FONT_LARGE));

    gui1->addSpacer(length-xInit, 2);
	gui1->addWidgetDown(new ofxUILabel("H SLIDERS", OFX_UI_FONT_MEDIUM));
//	gui1->addSlider("RED", 0.0, 255.0, red, length-xInit, dim);
//	gui1->addSlider("GREEN", 0.0, 255.0, green, length-xInit,dim);
//	gui1->addSlider("BLUE", 0.0, 255.0, blue, length-xInit,dim);

    gui1->addSpacer(length-xInit, 2);
    gui1->addWidgetDown(new ofxUILabel("V SLIDERS", OFX_UI_FONT_MEDIUM));
	gui1->addSlider("0", 0.0, 255.0, 150, dim, 160);
	gui1->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);
	gui1->addSlider("1", 0.0, 255.0, 150, dim, 160);
	gui1->addSlider("2", 0.0, 255.0, 150, dim, 160);
	gui1->addSlider("3", 0.0, 255.0, 150, dim, 160);
	gui1->addSlider("4", 0.0, 255.0, 150, dim, 160);
	gui1->addSlider("5", 0.0, 255.0, 150, dim, 160);
	gui1->addSlider("6", 0.0, 255.0, 150, dim, 160);
	gui1->addSlider("7", 0.0, 255.0, 150, dim, 160);
	gui1->addSlider("8", 0.0, 255.0, 150, dim, 160);
	gui1->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);

    gui1->addSpacer(length-xInit, 2);
	gui1->addRadio("RADIO HORIZONTAL", names, OFX_UI_ORIENTATION_HORIZONTAL, dim, dim);
	gui1->addRadio("RADIO VERTICAL", names, OFX_UI_ORIENTATION_VERTICAL, dim, dim);

    gui1->addSpacer(length-xInit, 2);
	gui1->addWidgetDown(new ofxUILabel("BUTTONS", OFX_UI_FONT_MEDIUM));
	gui1->addButton("DRAW GRID", false, dim, dim);
	gui1->addWidgetDown(new ofxUILabel("TOGGLES", OFX_UI_FONT_MEDIUM));
	gui1->addToggle( "D_GRID", false, dim, dim);

    gui1->addSpacer(length-xInit, 2);
    gui1->addWidgetDown(new ofxUILabel("RANGE SLIDER", OFX_UI_FONT_MEDIUM));
	gui1->addRangeSlider("RSLIDER", 0.0, 255.0, 50.0, 100.0, length-xInit,dim);

    gui1->addSpacer(length-xInit, 2);
	gui1->addWidgetDown(new ofxUILabel("2D PAD", OFX_UI_FONT_MEDIUM));
	gui1->add2DPad("PAD", ofPoint(0,length-xInit), ofPoint(0,120), ofPoint((length-xInit)*.5,120*.5), length-xInit,120);



//    bdrawGrid = false;
//	bdrawPadding = false;
	ofAddListener(gui1->newGUIEvent,this,&testApp::guiEvent);
}

void testApp::setGUI2()
{
	float dim = 16;
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING;
    float length = 255-xInit;

//    img = new ofImage();
//    img->loadImage("nerd_me.png");
//    buffer = new float[256];
//    for(int i = 0; i < 256; i++) { buffer[i] = ofNoise(i/100.0); }

    gui2 = new ofxUICanvas(length+xInit+2, 0, length+xInit, ofGetHeight());
	gui2->addWidgetDown(new ofxUILabel("PANEL 2: ADVANCED", OFX_UI_FONT_LARGE));

    gui2->addSpacer(length-xInit, 2);
	gui2->addWidgetDown(new ofxUILabel("TEXT INPUT", OFX_UI_FONT_MEDIUM));
	gui2->setWidgetFontSize(OFX_UI_FONT_LARGE);
	gui2->addTextInput("TEXT INPUT", "Input Text", length-xInit);
    gui2->addWidgetDown(new ofxUILabel("AUTO CLEAR DISABLED", OFX_UI_FONT_MEDIUM));
    gui2->addTextInput("TEXT INPUT2", "Input Text", length-xInit)->setAutoClear(false);
	gui2->setWidgetFontSize(OFX_UI_FONT_MEDIUM);

    gui2->addSpacer(length-xInit, 2);
    gui2->addWidgetDown(new ofxUILabel("WAVEFORM DISPLAY", OFX_UI_FONT_MEDIUM));
//	gui2->addWidgetDown(new ofxUIWaveform(length-xInit, 64, buffer, 256, 0.0, 1.0, "WAVEFORM"));
    gui2->addWidgetDown(new ofxUILabel("SPECTRUM DISPLAY", OFX_UI_FONT_MEDIUM));
//    gui2->addWidgetDown(new ofxUISpectrum(length-xInit, 64, buffer, 256, 0.0, 1.0, "SPECTRUM"));

    gui2->addSpacer(length-xInit, 2);
    gui2->addWidgetDown(new ofxUILabel("IMAGE DISPLAY", OFX_UI_FONT_MEDIUM));
//	gui2->addWidgetDown(new ofxUIImage(img->width*.5, img->height*.5, img, "IMAGE CAPTION"));

    gui2->addSpacer(length-xInit, 2);
    gui2->addWidgetDown(new ofxUILabel("FPS LABEL", OFX_UI_FONT_MEDIUM));
    gui2->addWidgetDown(new ofxUIFPS(OFX_UI_FONT_MEDIUM));

    gui2->addSpacer(length-xInit, 2);
    gui2->addWidgetDown(new ofxUILabel("NUMBER DIALER", OFX_UI_FONT_MEDIUM));
    gui2->addWidgetDown(new ofxUINumberDialer(-10000, 10000, 5000, 1, "NUMBER DIALER", OFX_UI_FONT_MEDIUM));

    gui2->addSpacer(length-xInit, 2);
    gui2->addWidgetDown(new ofxUILabel("LABEL BUTTON", OFX_UI_FONT_MEDIUM));
    gui2->addLabelButton("LABEL BUTTON", false, length-xInit);
    gui2->addLabelButton("AUTOSIZE BUTTON", false);
    gui2->addLabelButton("MEDIUM BUTTON", false);

    gui2->addSpacer(length-xInit, 2);
    gui2->addWidgetDown(new ofxUILabel("LABEL TOGGLES", OFX_UI_FONT_MEDIUM));
    gui2->addLabelToggle("LABEL TOGGLE", false, length-xInit);
    gui2->addLabelToggle("AUTOSIZE TOGGLE", false);
    gui2->addLabelToggle("MEDIUM TOGGLE", false);

	ofAddListener(gui2->newGUIEvent,this,&testApp::guiEvent);
}

