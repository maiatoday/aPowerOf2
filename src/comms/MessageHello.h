/*
 * MessageHello.h
 *
 *  Created on: Jan 11, 2013
 *      Author: maia
 */

#ifndef MESSAGEHELLO_H_
#define MESSAGEHELLO_H_

#include "SpaceMessage.h"

namespace comms {

class MessageHello: public SpaceMessage {
public:
	MessageHello();
	virtual ~MessageHello();
};

} /* namespace comms */
#endif /* MESSAGEHELLO_H_ */
