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
#include "ofxJansson.h"
namespace comms {
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
	void handleMessage(const int i, const string msg);

};
} /* namespace comms */
#endif /* SPACEBROADCASTER_H_ */
