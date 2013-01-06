/*
 * SpaceReporter.cpp
 *
 *  Created on: Jan 6, 2013
 *      Author: maia
 */

#include "SpaceReporter.h"

SpaceReporter::SpaceReporter() {
	serverPort = 11999;
	serverAddress = "127.0.0.1";

}

SpaceReporter::~SpaceReporter() {
	// TODO Auto-generated destructor stub
}

void SpaceReporter::setup() {
	if (XML.loadFile("mySettings.xml")) {
			serverAddress = XML.getValue("NETWORK:SERVER_ADDRESS", "localhost");
			updateTime = XML.getValue("NETWORK:UPDATE_INTERVAL", 2000);
			serverPort = XML.getValue("NETWORK:SERVER_PORT", 11999);
	}
	//are we connected to the server - if this fails we
		//will check every few seconds to see if the server exists
//	weConnected = ofxTCPClient::setup("127.0.0.1", 11999);
	weConnected = ofxTCPClient::setup(serverAddress, serverPort);
}

