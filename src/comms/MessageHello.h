/*
 * MessageHello.h
 *
 *  Created on: Jan 13, 2013
 *      Author: maia
 */

#ifndef MESSAGEHELLO_H_
#define MESSAGEHELLO_H_

#include "SpaceMessage.h"

namespace comms {

class MessageHello: public comms::SpaceMessage {
public:
	MessageHello();
	virtual ~MessageHello();
};

} /* namespace comms */
#endif /* MESSAGEHELLO_H_ */
