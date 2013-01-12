/*
 * SpaceReporter.cpp
 *
 *  Created on: Jan 6, 2013
 *      Author: maia
 */

#include "SpaceReporter.h"

namespace comms {
SpaceReporter::SpaceReporter() {
	serverPort = 11999;
	serverAddress = "127.0.0.1";
	weConnected = false;
	connectTime = ofGetElapsedTimeMillis();
	deltaTime = ofGetElapsedTimeMillis() - connectTime;
	updateTime = 5000;
}

SpaceReporter::~SpaceReporter() {
	// TODO Auto-generated destructor stub
}

void SpaceReporter::setup() {
	if (XML.loadFile("mySettings.xml")) {
		serverAddress = XML.getValue("NETWORK:SERVER_ADDRESS", "localhost");
		updateTime = XML.getValue("NETWORK:UPDATE_INTERVAL", 1000);
		serverPort = XML.getValue("NETWORK:SERVER_PORT", 11999);
	}
	//are we connected to the server - if this fails we
	//will check every few seconds to see if the server exists
	//	weConnected = ofxTCPClient::setup("127.0.0.1", 11999);
	weConnected = ofxTCPClient::setup(serverAddress, serverPort);
	setVerbose(true);
}

void SpaceReporter::update() {
	//do something on a regular interval, either retry connection or send a message
	deltaTime = ofGetElapsedTimeMillis() - connectTime;
	if (deltaTime > updateTime) {
		connectTime = ofGetElapsedTimeMillis();
		if (weConnected) {
			send("hello server");
			string answer = receive();
			if (!answer.empty()) {
				ofLog(OF_LOG_NOTICE, "client: *** server said %s",
						answer.c_str());
			}
			//		tcpClient.send(msgTx);
			//
			//		//if data has been sent lets update our text
			//		string str = tcpClient.receive();
			//		if( str.length() > 0 ){
			//			msgRx = str;
			//		}
		} else {
			weConnected = ofxTCPClient::setup(serverAddress, serverPort);
		}
	}
}

} /* namespace comms */

