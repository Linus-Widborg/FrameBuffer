/*
 * FrameBuffer.h
 *
 *  Created on: Oct 1, 2016
 *      Author: linus
 */

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_
#include "ImageHandle.h"
#include "Frame.h"
#include <stdint.h>

class FrameBuffer {
public:
	enum result {
		NOT_OK = 0,
		OK = 1
	};

	FrameBuffer();
	virtual ~FrameBuffer();
	result addFrame(uint64_t frameNumber, Frame& frame);
	Frame& getFrame(uint64_t frameNumber);

private:
	Frame m_FrameBuffer[2];
};
#endif /* FRAMEBUFFER_H_ */
