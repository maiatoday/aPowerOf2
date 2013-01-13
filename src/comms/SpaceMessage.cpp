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
	msgId = "";
	root = json_pack("{s:s}", "fg", "ttt"); // test should be a specific one for a specific message
}

/**
 * Constructor for when we received a message
 */
SpaceMessage::SpaceMessage(const string message) {
	root = json_loads(message.c_str(), 0, &error);
	msgId = getValueS(root, MSGID_KEY, "");
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

} /* namespace comms */

