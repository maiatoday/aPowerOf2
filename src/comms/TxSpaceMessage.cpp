/*
 * TxSpaceMessage.cpp
 *
 *  Created on: Feb 1, 2013
 *      Author: maia
 */

#include "TxSpaceMessage.h"

namespace comms {

TxSpaceMessage::TxSpaceMessage() :
		SpaceMessage() {

}

TxSpaceMessage::~TxSpaceMessage() {
	// base class destructor will be called
}

//------------- response message methods ------------
void TxSpaceMessage::makeHelloResponse() {
	msgIdString = MSG_ID_HELLO;
	setMsgIdFromString();
	root = json_pack("{s:s}", MSGID_KEY, msgIdString);
}

void TxSpaceMessage::makeSpaceInfoResponse() {
	msgIdString = MSG_ID_SPACE_INFO;
	setMsgIdFromString();
	root = json_pack("{s:s}", MSGID_KEY, msgIdString);
}

} /* namespace comms */
