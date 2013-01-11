/*
 * MessageHello.cpp
 *
 *  Created on: Jan 11, 2013
 *      Author: maia
 */

#include "MessageHello.h"

namespace comms {

MessageHello::MessageHello() {

	SpaceMessage(CMSG_HELLO);
}

MessageHello::~MessageHello() {
	// TODO Auto-generated destructor stub
}

} /* namespace comms */
