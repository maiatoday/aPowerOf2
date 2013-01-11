/*
 * SpaceBroadcaster.cpp
 *
 *  Created on: Jan 6, 2013
 *      Author: maia
 */

#include "SpaceBroadcaster.h"
namespace comms {
SpaceBroadcaster::SpaceBroadcaster() {
	serverPort = 11999;
	serverAddress = "127.0.0.1";
}

SpaceBroadcaster::~SpaceBroadcaster() {
	// TODO Auto-generated destructor stub
}

void SpaceBroadcaster::setup() {
	if (XML.loadFile("mySettings.xml")) {
		serverAddress = XML.getValue("NETWORK:SERVER_ADDRESS", "localhost");
		serverPort = XML.getValue("NETWORK:SERVER_PORT", 11999);
	}
	string myLocalAddress = "localhost"; // TODO get my local ip Address somehow
	if ((serverAddress == "127.0.0.1") || (serverAddress == myLocalAddress)) {
		// I am the server
		ofxTCPServer::setup(serverPort);
	}
}

void SpaceBroadcaster::update() {
//	string logString = "connected clients ";
//	logString.append(ofToString(getNumClients()));
//	ofLogNotice(logString.c_str());
	//for each client lets send them a message letting them know what port they are connected on
	for (int i = 0; i < getNumClients(); i++) {
		send(i,
				"hello client - you are connected on port - "
						+ ofToString(getClientPort(i)));
	}
}
} /* namespace comms */
