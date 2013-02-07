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
	root = json_pack("{s:s}", MSG_ID_KEY, msgIdString.c_str());

}

void TxSpaceMessage::makeSpaceInfoResponse(vector<UserDetail>& usersDetail, ofColor foreground) {
	msgIdString = MSG_ID_SPACE_INFO_STRING;
	setMsgIdFromString();
	json_t* users = json_array();
	for (unsigned int i = 0; i < usersDetail.size(); i++) {

		json_t* c = pointToJson(usersDetail[i].getCenter());

		json_t* u = json_object();
		json_object_set_new(u, MSG_CENTRE_KEY, c);
		if (usersDetail[i].isHandLset()) {
			json_t* hl = pointToJson(usersDetail[i].getHandLeft());
			json_object_set_new(u, MSG_HANDL_KEY, hl);
		}
		if (usersDetail[i].isHandRset()) {
			json_t* hr = pointToJson(usersDetail[i].getHandRight());
			json_object_set_new(u, MSG_HANDR_KEY, hr);
		}
		json_array_append_new(users, u);

	}
	json_t* color = colorToJson(foreground);

	root = json_object();
	json_object_set_new(root, MSG_ID_KEY, json_string(msgIdString.c_str()));
	json_object_set_new(root, MSG_FGCOLOR_KEY, color);
	json_object_set_new(root, MSG_USERS_KEY, users);


}

void TxSpaceMessage::makeSpaceInfoAllResponse() {
	//TODO fill the message with all the node info
	msgIdString = MSG_ID_SPACE_INFO_ALL_STRING;
	setMsgIdFromString();
	root = json_pack("{s:s}", MSG_ID_KEY, msgIdString.c_str());
}

} /* namespace comms */
