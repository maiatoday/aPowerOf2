/*
 * MessageNodeId.h
 *
 *  Created on: Jan 11, 2013
 *      Author: maia
 */

#ifndef MESSAGENODEID_H_
#define MESSAGENODEID_H_

#include "SpaceMessage.h"

namespace comms {

class MessageNodeId: public comms::SpaceMessage {
public:
	MessageNodeId();
	virtual ~MessageNodeId();
};

} /* namespace comms */
#endif /* MESSAGENODEID_H_ */
