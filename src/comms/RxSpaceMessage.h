/*
 * RxSpaceMessage.h
 *
 *  Created on: Feb 1, 2013
 *      Author: maia
 */

#ifndef RXSPACEMESSAGE_H_
#define RXSPACEMESSAGE_H_

#include "SpaceMessage.h"

namespace comms {

class RxSpaceMessage: public comms::SpaceMessage {
public:
	RxSpaceMessage();
	RxSpaceMessage(const string msg);
	virtual ~RxSpaceMessage();
	void extractMessageContents();
};

} /* namespace comms */
#endif /* RXSPACEMESSAGE_H_ */
