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
	json_t* users = json_array();
	for (unsigned int i = 0; i < userCenters.size(); i++) {

		json_t* c = json_object();
		json_object_set_new(c, "x", json_integer(userCenters[i].x));
		json_object_set_new(c, "y", json_integer(userCenters[i].y));
		json_object_set_new(c, "z", json_integer(userCenters[i].z));


		json_t* u = json_object();
		json_object_set_new(u, "center", c);

		json_array_append_new(users, u);

	}
	json_t* color = json_object();
	json_object_set_new(color, "r", json_integer(foreground.r));

	root = json_object();
	json_object_set_new(root, MSGID_KEY, json_string(msgIdString.c_str()));
	json_object_set_new(root, "fgColor", color);
	json_object_set_new(root, "users", users);
//	root = json_pack("{s:s}", MSGID_KEY, msgIdString.c_str());


}

void TxSpaceMessage::makeSpaceInfoAllResponse() {
	msgIdString = MSG_ID_SPACE_INFO_ALL_STRING;
	setMsgIdFromString();
	root = json_pack("{s:s}", MSGID_KEY, msgIdString.c_str());
}

} /* namespace comms */
