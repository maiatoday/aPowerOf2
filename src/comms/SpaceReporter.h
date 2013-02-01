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

namespace comms {
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
	unsigned int connectTime;
	unsigned int deltaTime;
	bool sendHello;
};
} /* namespace comms */
#endif /* SPACEREPORTER_H_ */
