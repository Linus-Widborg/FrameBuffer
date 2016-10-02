/*
 * FrameBuffer.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: linus
 */
#include "FrameBuffer.h"

FrameBuffer::FrameBuffer() {
	//Empty

}

FrameBuffer::~FrameBuffer() {
	//Empty
}

FrameBuffer::result FrameBuffer::addImageToFrame(uint64_t frameNumber,
												 ImageHandle* imageHandle) {
	m_Frame[frameNumber].addImageHandle(imageHandle);
	return OK;
}

Frame FrameBuffer::getFrame(uint64_t frameNumber) {
	return m_Frame[frameNumber];
}
