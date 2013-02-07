/*
 * SpaceBroadcaster.cpp
 *
 *  Created on: Jan 6, 2013
 *      Author: maia
 */

#include "SpaceBroadcaster.h"
#include "SpaceMessage.h"
#include "IpUtils.h"

namespace comms {
SpaceBroadcaster::SpaceBroadcaster() {
	serverPort = 11999;
	serverAddress = "localhost";
	serverActive = false;
	myLocalAddress = IpUtils::getMyIp();
}

SpaceBroadcaster::~SpaceBroadcaster() {
	// TODO Auto-generated destructor stub
}

void SpaceBroadcaster::setup() {
	if (XML.loadFile("mySettings.xml")) {
		serverAddress = XML.getValue("NETWORK:SERVER_ADDRESS", "127.0.0.1");
		ofLog(OF_LOG_NOTICE, "Server IP setting is %s", serverAddress.c_str());
		serverPort = XML.getValue("NETWORK:SERVER_PORT", 11999);
	}
	ofLog(OF_LOG_NOTICE, "My IP is %s", myLocalAddress.c_str());
	if ((serverAddress == "127.0.0.1") || (serverAddress == myLocalAddress)) {
		// I am the server
		ofLog(OF_LOG_NOTICE, "This Node is the server %s", serverAddress.c_str());
		serverActive = true;
		ofxTCPServer::setup(serverPort);
	}
}

/**
 * Check if there are messages from the connected nodes, update the details for the nodes and send it to the clients.
 */
void SpaceBroadcaster::update() {
//	ofLog(OF_LOG_NOTICE, "num connected clients  %d ", getNumClients());
	if (isServerActive()) {
		//for each client lets answer their message
		for (int i = 0; i < getNumClients(); i++) {
			string msg = receive(i);
			if (!msg.empty()) {
				handleMessage(i, msg);
			}
		}
	}
}

/**
 * handle the incoming messages by responding with the correct response
 */
void SpaceBroadcaster::handleMessage(const int i, const string msg) {
	ofLog(OF_LOG_NOTICE, "server: the msg from client %d is %s", i, msg.c_str());

	RxSpaceMessage* inmsg = new RxSpaceMessage(msg);
	TxSpaceMessage* outmsg = new TxSpaceMessage();
	switch (inmsg->getMsgId()) {
	case MSG_ID_HELLO:
		//Register the node in the nodes hashmap
//		NodeDetail newNode = new NodeDetail();
//		newNode.setFgColor(inmsg->getColor());
//		nodes.add(newNode);
		outmsg->makeHelloResponse();
		break;
	case MSG_ID_SPACE_INFO:
		// update the nodes hashmap with this node' info

		outmsg->makeSpaceInfoAllResponse();
		break;
	}
	send(i, outmsg->toString());
	delete (inmsg);
	delete (outmsg);

}

} /* namespace comms */
