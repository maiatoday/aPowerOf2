/*
 * SpaceMessage.h
 *
 *  Created on: Jan 6, 2013
 *      Author: maia
 */

#ifndef SPACEMESSAGE_H_
#define SPACEMESSAGE_H_
#include "ofConstants.h"
#define MSG_UNKNOWN 0x0000

class SpaceMessage {
public:
	SpaceMessage();
	virtual ~SpaceMessage();

//	const unsigned int MSG_UNKNOWN = 0x0000;
	virtual string toString();
	virtual void getBytes(); // TODO return the byte array

	unsigned int getId() const {
		return id;
	}

	void setId(unsigned int id) {
		this->id = id;
	}

protected:
	unsigned int id;
};

#endif /* SPACEMESSAGE_H_ */
