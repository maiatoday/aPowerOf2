/*
 * SpaceBroadcaster.h
 *
 *  Created on: Jan 6, 2013
 *      Author: maia
 */

#ifndef SPACEBROADCASTER_H_
#define SPACEBROADCASTER_H_
#include "ofxNetwork.h"
#include "ofxXmlSettings.h"

class SpaceBroadcaster: public ofxTCPServer {
public:
	SpaceBroadcaster();
	virtual ~SpaceBroadcaster();
	void setup();
	void update();
private:
	ofxXmlSettings XML;
	string serverAddress;
	unsigned int serverPort;
};

#endif /* SPACEBROADCASTER_H_ */
