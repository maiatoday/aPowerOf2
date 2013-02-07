/*
 * TxSpaceMessage.h
 *
 *  Created on: Feb 1, 2013
 *      Author: maia
 */

#ifndef TXSPACEMESSAGE_H_
#define TXSPACEMESSAGE_H_

#include "SpaceMessage.h"
#include "ofPoint.h"
#include "ofColor.h"
#include "UserDetail.h"

namespace comms {

class TxSpaceMessage: public comms::SpaceMessage {
public:
	TxSpaceMessage();
	virtual ~TxSpaceMessage();
	// Reporter Tx Messages - client
	void makeSpaceInfoResponse(vector<UserDetail*>& usersDetail, ofColor foreground);

	// Broadcaster Tx Messages - server
	void makeHelloResponse();
	void makeSpaceInfoAllResponse();
};

} /* namespace comms */
#endif /* TXSPACEMESSAGE_H_ */
