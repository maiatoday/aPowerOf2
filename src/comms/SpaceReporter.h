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
#include "TxSpaceMessage.h"
#include "RxSpaceMessage.h"
#include "UserDetail.h"

namespace comms {
/**
 * Reports the users it can see for this client Node to the broadcaster and gets info about other nodes
 */
class SpaceReporter: public ofxTCPClient {
public:
	SpaceReporter();
	virtual ~SpaceReporter();
	void setup();
	void update(vector<UserDetail*>& usersDetail, ofColor foreground);
private:
	bool weConnected;
	ofxXmlSettings XML;
	string serverAddress;
	unsigned int updateTime;
	unsigned int serverPort;

	float counter;
	unsigned int connectTime;
	unsigned int deltaTime;
	bool sendHello;
};
} /* namespace comms */
#endif /* SPACEREPORTER_H_ */
