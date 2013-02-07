/*
 * UserDetail.h
 *
 *  Created on: Feb 7, 2013
 *      Author: maia
 */

#ifndef USERDETAIL_H_
#define USERDETAIL_H_

#include "ofPoint.h"

/**
 * Contains the detail of one User as seen by the kinect
 */
class UserDetail {
public:
	UserDetail();
	virtual ~UserDetail();
	const ofPoint& getCenter() const {
		return center;
	}

	void setCenter(const ofPoint& center) {
		centerSet = true;
		this->center = center;
	}

	bool isCenterSet() const {
		return centerSet;
	}

	const ofPoint& getHandLeft() const {
		return handLeft;
	}

	void setHandLeft(const ofPoint& handLeft) {
		this->handLeft = handLeft;
		handLset = true;
	}

	bool isHandLset() const {
		return handLset;
	}

	const ofPoint& getHandRight() const {
		return handRight;
	}

	void setHandRight(const ofPoint& handRight) {
		this->handRight = handRight;
		handRset = true;
	}

	bool isHandRset() const {
		return handRset;
	}

private:
	ofPoint center;
	ofPoint handLeft;
	ofPoint handRight;
	bool handLset;
	bool handRset;
	bool centerSet;
};

#endif /* USERDETAIL_H_ */
