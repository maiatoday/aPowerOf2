/*
 * NodeDetail.h
 *
 *  Created on: Feb 7, 2013
 *      Author: maia
 */

#ifndef NODEDETAIL_H_
#define NODEDETAIL_H_
#include "ofColor.h"
#include "UserDetail.h"

/**
 * Contains detail of a connected Node or client. This includes it's colour and a vector of UsersDetail for the users that his node can see
 */
class NodeDetail {
public:
	NodeDetail();
	virtual ~NodeDetail();

	const ofColor& getFgColor() const {
		return fgColor;
	}

	void setFgColor(const ofColor& fgColor) {
		this->fgColor = fgColor;
	}

	const vector<UserDetail>& getUsers() const {
		return users;
	}

	void setUsers(const vector<UserDetail>& users) {
		this->users = users;
	}

protected:
	ofColor fgColor;
	vector<UserDetail> users;
};

#endif /* NODEDETAIL_H_ */
