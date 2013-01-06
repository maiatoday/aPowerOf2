/*
 * SpaceReporter.h
 *
 *  Created on: Jan 6, 2013
 *      Author: maia
 */

#ifndef SPACEREPORTER_H_
#define SPACEREPORTER_H_

#include "ofxNetwork.h"
#include "ofxXmlSettings.h"

class SpaceReporter: public ofxTCPClient {
public:
	SpaceReporter();
	virtual ~SpaceReporter();
	void setup();
private:
	bool weConnected;
	ofxXmlSettings XML;
	string serverAddress;
	uint updateTime;
	uint serverPort;
};

#endif /* SPACEREPORTER_H_ */
