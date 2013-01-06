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
	weConnected = false;
	connectTime = ofGetElapsedTimeMillis();
	deltaTime = ofGetElapsedTimeMillis() - connectTime;
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
	setVerbose(true);
}

void SpaceReporter::update() {
	if(weConnected){
//		tcpClient.send(msgTx);
//
//		//if data has been sent lets update our text
//		string str = tcpClient.receive();
//		if( str.length() > 0 ){
//			msgRx = str;
//		}
	}else{
		//if we are not connected lets try and reconnect every 5 seconds
		deltaTime = ofGetElapsedTimeMillis() - connectTime;

		if( deltaTime > 5000 ){
			weConnected = ofxTCPClient::setup(serverAddress, serverPort);
			connectTime = ofGetElapsedTimeMillis();
		}

	}
}

