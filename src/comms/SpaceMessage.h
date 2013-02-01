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

namespace comms {
class SpaceMessage: public ofxJansson {
public:
	SpaceMessage();
	SpaceMessage(const string msg);
	virtual ~SpaceMessage();
	virtual string toString();

	const string& getMsgIdString() const {
		return msgIdString;
	}
	int getMsgId() const {
		return msgId;
	}
	void makeHelloResponse();
	void makeSpaceInfoResponse();

protected:
	json_t *root;
	json_error_t error;
	string msgIdString;
	int msgId;
	void setMsgIdFromString();

//	ofxJansson json;
};

} /* namespace comms */

#endif /* SPACEMESSAGE_H_ */
