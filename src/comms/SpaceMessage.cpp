/*
 * SpaceMessage.cpp
 *
 *  Created on: Jan 6, 2013
 *      Author: maia
 */

#include "SpaceMessage.h"

namespace comms {

SpaceMessage::SpaceMessage() {
//	root = NULL;
	msgIdString = "";
	msgId = MSG_ID_UNKNOWN;
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
	if (msgIdString == MSG_ID_HELLO_STRING) {
		msgId = MSG_ID_HELLO;
	} else if (msgIdString == MSG_ID_SPACE_INFO_STRING) {
		msgId = MSG_ID_SPACE_INFO;
	} else if (msgIdString == MSG_ID_SPACE_INFO_ALL_STRING) {
		msgId = MSG_ID_SPACE_INFO_ALL;
	} else {
		msgId = MSG_ID_UNKNOWN;
	}

}



} /* namespace comms */

