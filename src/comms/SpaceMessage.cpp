/*
 * SpaceMessage.cpp
 *
 *  Created on: Jan 6, 2013
 *      Author: maia
 */

#include "SpaceMessage.h"

namespace comms {
/**
 * Basic construct for when we are building a message
 */
SpaceMessage::SpaceMessage() {
//	root = NULL;
	msgIdString = "";
	msgId = MSG_ID_UNKNOWN;
}

/**
 * Constructor for when we received a message
 */
SpaceMessage::SpaceMessage(const string message) {
	root = json_loads(message.c_str(), 0, &error);
	msgIdString = getValueS(root, MSGID_KEY, "");
	setMsgIdFromString();
}

SpaceMessage::~SpaceMessage() {
	if (root) {
		json_decref(root);
	}
}

string SpaceMessage::toString() {

	string reply = "";
	if (!json_is_null(root)) {
		char* buf = json_dumps(root, 0);
		reply.append(buf);
		free(buf);
	}
	return reply;
}

void SpaceMessage::setMsgIdFromString() {
	if (msgIdString == "hello") {
		msgId = MSG_ID_HELLO;
	} else if (msgIdString == "spaceInfo") {
		msgId = MSG_ID_SPACE_INFO;
	} else {
		msgId = MSG_ID_UNKNOWN;
	}

}

void SpaceMessage::makeHelloResponse() {
	root = json_pack("{s:s}", MSGID_KEY, "hello"); // test should be a specific one for a specific message
}
void SpaceMessage::makeSpaceInfoResponse() {
	root = json_pack("{s:s}", MSGID_KEY, "spaceInfo"); // test should be a specific one for a specific message
}

} /* namespace comms */

