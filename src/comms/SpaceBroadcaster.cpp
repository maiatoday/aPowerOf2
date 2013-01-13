/*
 * SpaceBroadcaster.cpp
 *
 *  Created on: Jan 6, 2013
 *      Author: maia
 */

#include "SpaceBroadcaster.h"
#include "SpaceMessage.h"

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
//	ofLog(OF_LOG_NOTICE, "num connected clients  %d ", getNumClients());
	//for each client lets answer their message
	for (int i = 0; i < getNumClients(); i++) {
		string msg = receive(i);
		if (!msg.empty()) {
			handleMessage(i, msg);
		}
	}
}


void SpaceBroadcaster::handleMessage(const int i, const string msg) {
	ofLog(OF_LOG_NOTICE, "server: the msg from client %d is %s", i,
				msg.c_str());

	SpaceMessage* inmsg = new SpaceMessage(msg);
	SpaceMessage* outmsg = new SpaceMessage();
//	switch(inmsg->getMsgId()) {
//	case "hello":
//		outmsg = new SpaceMessage();
//		break;
//	case "mySpaceInfo":
//		outmsg = new SpaceMessage();
//		break;
//	}
//	json_t* root = json_pack("{s:s}", "fg", "ttt");
	send(i, outmsg->toString());
	delete(inmsg);
	delete(outmsg);



}

} /* namespace comms */
