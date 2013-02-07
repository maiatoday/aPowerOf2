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

/**
 * create a json object from an ofColor object
 */
json_t* SpaceMessage::colorToJson(ofColor color) {
	json_t* obj = json_object();
	json_object_set_new(obj, "r", json_integer(color.r));
	json_object_set_new(obj, "g", json_integer(color.g));
	json_object_set_new(obj, "b", json_integer(color.b));
	json_object_set_new(obj, "a", json_integer(color.a));
	return obj;

}

/**
 * create a json object from an ofPoint object
 */
json_t* SpaceMessage::pointToJson(ofPoint point) {
	json_t* obj = json_object();
	json_object_set_new(obj, "x", json_integer(point.x));
	json_object_set_new(obj, "y", json_integer(point.y));
	json_object_set_new(obj, "z", json_integer(point.z));
	return obj;

}

/**
 * create a ofColor object from a json object
 */
void SpaceMessage::jsonToColor(json_t* obj, ofColor& color){

}
/**
 * ofPoint a ofColor object from a json object
 */
void SpaceMessage::jsonToPoint(json_t* obj, ofPoint& point){

}

} /* namespace comms */

