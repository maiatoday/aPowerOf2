/*
 * RxSpaceMessage.cpp
 *
 *  Created on: Feb 1, 2013
 *      Author: maia
 */

#include "RxSpaceMessage.h"

namespace comms {

RxSpaceMessage::RxSpaceMessage() {
	// TODO Auto-generated constructor stub

}
/**
 * Constructor for when we received a message
 * Contents of the message will be extracted
 * Call Getter functions to get the incoming values
 */
RxSpaceMessage::RxSpaceMessage(const string message) {
	root = json_loads(message.c_str(), 0, &error);
	msgIdString = getValueS(root, MSGID_KEY, "");
	setMsgIdFromString();
	extractMessageContents();
}

RxSpaceMessage::~RxSpaceMessage() {

}
//--------- receive message methods  -----------------

void RxSpaceMessage::extractMessageContents() {

}

} /* namespace comms */
