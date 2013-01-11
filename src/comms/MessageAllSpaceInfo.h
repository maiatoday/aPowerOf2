/*
 * MessageAllSpaceInfo.h
 *
 *  Created on: Jan 11, 2013
 *      Author: maia
 */

#ifndef MESSAGEALLSPACEINFO_H_
#define MESSAGEALLSPACEINFO_H_

#include "SpaceMessage.h"

namespace comms {

class MessageAllSpaceInfo: public comms::SpaceMessage {
public:
	MessageAllSpaceInfo();
	virtual ~MessageAllSpaceInfo();
};

} /* namespace comms */
#endif /* MESSAGEALLSPACEINFO_H_ */
