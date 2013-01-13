/*
 * MessageNodeSpaceInfo.h
 *
 *  Created on: Jan 13, 2013
 *      Author: maia
 */

#ifndef MESSAGENODESPACEINFO_H_
#define MESSAGENODESPACEINFO_H_

#include "SpaceMessage.h"

namespace comms {

class MessageNodeSpaceInfo: public comms::SpaceMessage {
public:
	MessageNodeSpaceInfo();
	virtual ~MessageNodeSpaceInfo();
};

} /* namespace comms */
#endif /* MESSAGENODESPACEINFO_H_ */
