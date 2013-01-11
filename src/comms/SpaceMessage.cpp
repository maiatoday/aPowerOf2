/*
 * SpaceMessage.cpp
 *
 *  Created on: Jan 6, 2013
 *      Author: maia
 */

#include "SpaceMessage.h"

namespace comms {
SpaceMessage::SpaceMessage() {
	this->id = MSG_UNKNOWN;
	serverProcess = false;
	length = sizeof(id) + sizeof(length); // minimum length
}

SpaceMessage::SpaceMessage(unsigned int id) {
	this->id = id;
	serverProcess = false;
	length = sizeof(id) + sizeof(length); // minimum length
}

SpaceMessage::~SpaceMessage() {
	// TODO Auto-generated destructor stub
}

void SpaceMessage::getBytes(char * pbuffer, unsigned int buflen) {

}

string SpaceMessage::toString() {
	string reply = "";
	switch (id) {
	case SMSG_NODE_ID_INFO:
		isServerProcess()? reply = "server says ":reply = "client hears ";
		reply.append("NODE_ID_INFO");
		break;
	case SMSG_ALL_SPACE_INFO:
		isServerProcess()? reply = "server says ":reply = "client hears ";
		reply.append("ALL_SPACE_INFO");
		break;
	case CMSG_NODE_SPACE_INFO:
		isServerProcess()? reply = "server hears ":reply = "client says ";
		reply.append("NODE_SPACE_INFO");
		break;
	case CMSG_HELLO:
		isServerProcess()? reply = "server hears ":reply = "client says ";
		reply.append("HELLO");
		break;
	default:
		reply = "unknown message";
		break;

	}
	return reply;
}

void SpaceMessage::addBytes(char *pbuffer, unsigned int buflen,
		unsigned int offset) {
}
} /* namespace comms */

