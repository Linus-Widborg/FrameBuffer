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

#include <stdio.h>
FrameBuffer::result FrameBuffer::addFrame(uint64_t frameNumber,
										  Frame& frame) {
	m_FrameBuffer[frameNumber] = frame;
	return OK;
}

Frame& FrameBuffer::getFrame(uint64_t frameNumber) {
	//fprintf(stderr, "LIZ: getFrame %p\n", &m_FrameBuffer[frameNumber]);
	return m_FrameBuffer[frameNumber];
}
