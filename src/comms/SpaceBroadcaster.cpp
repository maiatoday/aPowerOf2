/*
 * SpaceBroadcaster.cpp
 *
 *  Created on: Jan 6, 2013
 *      Author: maia
 */

#include "SpaceBroadcaster.h"

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
	string myLocalAddress = "localhost";
	if ((serverAddress == "127.0.0.1") || (serverAddress == myLocalAddress)) {
		// I am the server
		ofxTCPServer::setup(serverPort);
	}
}

