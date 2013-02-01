/*
 * TxSpaceMessage.h
 *
 *  Created on: Feb 1, 2013
 *      Author: maia
 */

#ifndef TXSPACEMESSAGE_H_
#define TXSPACEMESSAGE_H_

#include "SpaceMessage.h"

namespace comms {

class TxSpaceMessage: public comms::SpaceMessage {
public:
	TxSpaceMessage();
	virtual ~TxSpaceMessage();
protected:
	void makeHelloResponse();
	void makeSpaceInfoResponse();
};

} /* namespace comms */
#endif /* TXSPACEMESSAGE_H_ */
