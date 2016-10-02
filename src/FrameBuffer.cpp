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

FrameBuffer::result FrameBuffer::AddImageToFrame(uint64_t frameNumber,
												 ImageHandle* imageHandle) {
	m_Frame = Frame(imageHandle);
	return OK;
}

Frame FrameBuffer::getFrame(uint64_t frameNumber) {
	return m_Frame;
}
