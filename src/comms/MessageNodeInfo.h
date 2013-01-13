/*
 * MessageNodeInfo.h
 *
 *  Created on: Jan 13, 2013
 *      Author: maia
 */

#ifndef MESSAGENODEINFO_H_
#define MESSAGENODEINFO_H_

#include "SpaceMessage.h"

namespace comms {

class MessageNodeInfo: public comms::SpaceMessage {
public:
	MessageNodeInfo();
	virtual ~MessageNodeInfo();
};

} /* namespace comms */
#endif /* MESSAGENODEINFO_H_ */
