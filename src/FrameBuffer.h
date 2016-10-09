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
#include <vector>
#include <stdexcept>

struct DebugData {
	uint8_t size;
	void* data;
};
class FrameBuffer {
public:
	FrameBuffer(const uint64_t size);
	virtual ~FrameBuffer();
	uint64_t size();

	void insertImage(ImageHandle* imageHandle);
	void insertDebugData(const uint64_t slot, DebugData debugData);

	DebugData getDebugData(const uint64_t slot);

private:
	const uint64_t m_Size;
	std::vector<DebugData> m_DebugData;
	uint64_t m_FirstSlot;
};
#endif /* FRAMEBUFFER_H_ */
