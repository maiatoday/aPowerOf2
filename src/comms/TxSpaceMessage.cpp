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
	msgIdString = MSG_ID_HELLO_STRING;
	setMsgIdFromString();
	root = json_pack("{s:s}", MSGID_KEY, msgIdString.c_str());
}

void TxSpaceMessage::makeSpaceInfoResponse(vector<ofPoint>& userCenters, ofColor foreground) {
	msgIdString = MSG_ID_SPACE_INFO_STRING;
	setMsgIdFromString();
	root = json_pack("{s:s}", MSGID_KEY, msgIdString.c_str());
}

void TxSpaceMessage::makeSpaceInfoAllResponse() {
	msgIdString = MSG_ID_SPACE_INFO_ALL_STRING;
	setMsgIdFromString();
	root = json_pack("{s:s}", MSGID_KEY, msgIdString.c_str());
}

} /* namespace comms */
