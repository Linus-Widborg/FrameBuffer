/*
 * Frame.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: linus
 */

#include "Frame.h"
#include <stdio.h>

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

bool operator==(const Frame& lhs,const Frame& rhs) {
	fprintf(stderr, "LIZ: %p == %p\n", &lhs, &rhs);
	return &lhs == &rhs;
}

bool operator!=(const Frame& lhs, const Frame& rhs) {
	return !(lhs == rhs);
}

void Frame::addImageHandle(ImageHandle* imageHandle) {
	m_ImageHandle = imageHandle;
}
