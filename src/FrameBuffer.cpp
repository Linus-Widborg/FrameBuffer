/*
 * FrameBuffer.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: linus
 */
#include "FrameBuffer.h"

FrameBuffer::FrameBuffer(const uint64_t size) : m_Size(size), m_FirstSlot(0) {
	//Empty
}

FrameBuffer::~FrameBuffer() {
	//Empty
}

void FrameBuffer::insertImage(ImageHandle* imageHandle) {
}

void FrameBuffer::insertDebugData(const uint64_t slot, DebugData debugData) {
	m_DebugData.push_back(debugData);
	if (m_DebugData.size() > m_Size) {
		m_DebugData.erase(m_DebugData.begin());
		m_FirstSlot++;
	}
}

DebugData FrameBuffer::getDebugData(const uint64_t slot) {
	if (slot < m_FirstSlot) {
		throw std::out_of_range("Tried to access a frame buffer slot out of range");
	}
	return m_DebugData.at(slot- m_FirstSlot);
}

uint64_t FrameBuffer::size() {
	return m_DebugData.size();
}
