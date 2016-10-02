/*
 * Frame.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: linus
 */

#include "Frame.h"

Frame::Frame() : m_ImageHandle(nullptr) {
	//Empty
}

Frame::Frame(ImageHandle* imageHandle) : m_ImageHandle(imageHandle) {
	//Empty
}

Frame::~Frame() {
	//Empty
}

ImageHandle* Frame::getImageHandle() {
	return m_ImageHandle;
}
