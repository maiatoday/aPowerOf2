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
#include "RxSpaceMessage.h"
#include "TxSpaceMessage.h"
#include "NodeDetail.h"
namespace comms {
/**
 * Collects User details from all the client nodes and tells each node about the other nodes: the server
 */
class SpaceBroadcaster: public ofxTCPServer {
public:
	SpaceBroadcaster();
	virtual ~SpaceBroadcaster();
	void setup();
	void update();

	bool isServerActive() const {
		return serverActive;
	}

private:
	ofxXmlSettings XML;
	string serverAddress;
	unsigned int serverPort;
	void handleMessage(const int i, const string msg);
	map<string, NodeDetail*> nodes;
	bool serverActive;
	string myLocalAddress;

};
} /* namespace comms */
#endif /* SPACEBROADCASTER_H_ */
