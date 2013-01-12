/*
 * SpaceMessage.h
 *
 *  Created on: Jan 6, 2013
 *      Author: maia
 */

#ifndef SPACEMESSAGE_H_
#define SPACEMESSAGE_H_
#include "ofConstants.h"

#define MINMSG_LENGTH 6
#define MSG_UNKNOWN 0x0000

// Messages originating from the Server
#define SMSG_NODE_ID_INFO 0x1001
#define SMSG_ALL_SPACE_INFO 0x1002

// Messages originating from the Client
#define CMSG_HELLO 0x0001
#define CMSG_NODE_SPACE_INFO 0x0002
namespace comms {
class SpaceMessage {
public:
	SpaceMessage();
	SpaceMessage(unsigned int id);
	virtual ~SpaceMessage();
	virtual string toString();
	virtual void getBytes(char * pbuffer, unsigned int buflen); // TODO return the byte array

	unsigned int getId() const {
		return id;
	}

	void setId(unsigned int id) {
		this->id = id;
	}

	unsigned int getLength() const {
		return length;
	}
	void addBytes(char *pbuffer, unsigned int buflen, unsigned int offset);

	bool isServerProcess() const {
		return serverProcess;
	}

	void setServerProcess(bool serverProcess) {
		this->serverProcess = serverProcess;
	}

protected:
	unsigned int id;
	unsigned int length;
	bool serverProcess;
};

} /* namespace comms */

#endif /* SPACEMESSAGE_H_ */
