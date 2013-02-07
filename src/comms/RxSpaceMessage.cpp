/*
 * RxSpaceMessage.cpp
 *
 *  Created on: Feb 1, 2013
 *      Author: maia
 */

#include "RxSpaceMessage.h"

namespace comms {

RxSpaceMessage::RxSpaceMessage() {

}
/**
 * Constructor for when we received a message
 * Contents of the message will be extracted
 * Call Getter functions to get the incoming values
 */
RxSpaceMessage::RxSpaceMessage(const string message) {
	root = json_loads(message.c_str(), 0, &error);
	msgIdString = getValueS(root, MSG_ID_KEY, "");
	setMsgIdFromString();
	extractMessageContents();
}

RxSpaceMessage::~RxSpaceMessage() {

}
//--------- receive message methods  -----------------

void RxSpaceMessage::extractMessageContents() {
	switch (msgId) {
	case MSG_ID_HELLO:
		//TODO extract contents for hello message
		break;
	case MSG_ID_SPACE_INFO:
		//TODO extract contents for hello message
		break;
	case MSG_ID_SPACE_INFO_ALL:
		//TODO extract contents for hello message
		break;
	}
	//TODO extract contents for spaceInfo Message
}

} /* namespace comms */
