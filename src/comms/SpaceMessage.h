/*
 * SpaceMessage.h
 *
 *  Created on: Jan 6, 2013
 *      Author: maia
 */

#ifndef SPACEMESSAGE_H_
#define SPACEMESSAGE_H_
#include "ofConstants.h"
#include "ofxJansson.h"
#include "jansson.h"

#define MSGID_KEY "msgId"

#define MSG_ID_UNKNOWN 0
#define MSG_ID_HELLO 1
#define MSG_ID_SPACE_INFO 2
#define MSG_ID_SPACE_INFO_ALL 3
#define MSG_ID_HELLO_STRING "hello"
#define MSG_ID_SPACE_INFO_STRING "spaceInfo"
#define MSG_ID_SPACE_INFO_ALL_STRING "spaceInfoAll"

namespace comms {
class SpaceMessage: public ofxJansson {
public:
	SpaceMessage();
	virtual ~SpaceMessage();
	virtual string toString();
	void setMsgIdFromString();

	const string& getMsgIdString() const {
		return msgIdString;
	}
	int getMsgId() const {
		return msgId;
	}


protected:
	json_t *root;
	json_error_t error;
	string msgIdString;
	int msgId;

//	ofxJansson json;
};

} /* namespace comms */

#endif /* SPACEMESSAGE_H_ */
