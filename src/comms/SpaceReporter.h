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
	void update();
private:
	bool weConnected;
	ofxXmlSettings XML;
	string serverAddress;
	unsigned int updateTime;
	unsigned int serverPort;

	float counter;
	int connectTime;
	int deltaTime;
};

#endif /* SPACEREPORTER_H_ */
