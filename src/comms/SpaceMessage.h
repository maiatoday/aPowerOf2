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

namespace comms {
class SpaceMessage: public ofxJansson {
public:
	SpaceMessage();
	SpaceMessage(const string msg);
	virtual ~SpaceMessage();
	virtual string toString();

	const string& getMsgId() const {
		return msgId;
	}

	void setMsgId(const string& msgId) {
		this->msgId = msgId;
	}

protected:
	json_t *root;
	json_error_t error;
	string msgId;

//	ofxJansson json;
};

} /* namespace comms */

#endif /* SPACEMESSAGE_H_ */
