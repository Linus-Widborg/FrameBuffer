/*
 * TestMain.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: linus
 */
#include <CUnit/Basic.h>
#include "../src/FrameBuffer.h"
#include "../src/ImageHandle.h"
//TODO Add debug data to frame in frame buffer
//TODO Frame buffer overflow
//TODO A more dynamic container then array to store frames
//TODO Constness
//TODO Sliding window
//TODO Frame has several images
//TODO Image and debug data in same structure?

void testAddDebugDataToFrameBuffer() {
	//Setup
	uint64_t bufferSize = 1;
	FrameBuffer frameBuffer(bufferSize);
	uint64_t slot = 0;
	uint16_t expectedData[] = {0xDDDD, 0xBBBB};
	DebugData debugData;
	debugData.size = 2;
	debugData.data = expectedData;
	//Execute SUT
	frameBuffer.insertDebugData(slot, debugData);
	//Verify
	CU_ASSERT_EQUAL(debugData.size, frameBuffer.getDebugData(slot).size);
	CU_ASSERT_EQUAL(0, ::memcmp(expectedData, frameBuffer.getDebugData(slot).data, frameBuffer.getDebugData(slot).size));
}

void testAddDebugDataToSeveralSlots() {
	//Setup
	FrameBuffer frameBuffer(2);
	DebugData debugData1;
	debugData1.size = 3;
	uint16_t expectedData1[debugData1.size] = {0xFFFF, 0xEEEE, 0xDDDD};
	debugData1.data = expectedData1;

	DebugData debugData2;
	debugData2.size = 4;
	uint16_t expectedData2[debugData2.size] = {0x1122, 0x3344, 0x5566, 0x7788};
	debugData2.data = expectedData2;
	//Execute SUT
	frameBuffer.insertDebugData(0, debugData1);
	frameBuffer.insertDebugData(1, debugData2);
	//Verify
	CU_ASSERT_EQUAL(0, ::memcmp(expectedData1, frameBuffer.getDebugData(0).data, frameBuffer.getDebugData(0).size));
	CU_ASSERT_EQUAL(0, ::memcmp(expectedData2, frameBuffer.getDebugData(1).data, frameBuffer.getDebugData(1).size));
}

void testToGetSlotOutOfBounds() {
	//Setup
	FrameBuffer frameBuffer(1);
	//Execute SUT & Verify
	try {
		frameBuffer.getDebugData(5);
	} catch (const std::out_of_range& e) {
		return;
	}
	CU_ASSERT(false);
}

void testSlidingWindow() {
	//Setup
	uint64_t windowSize = 1;
	FrameBuffer frameBuffer(windowSize);
	DebugData debugDataEmpty;
	DebugData debugDataFilled;
	debugDataFilled.size = 2;
	uint16_t expectedData[] = {0xABCD, 0xABCD};
	debugDataFilled.data = expectedData;
	//Execute SUT
	frameBuffer.insertDebugData(0, debugDataEmpty);
	frameBuffer.insertDebugData(1, debugDataFilled);
	//Verify
	CU_ASSERT_EQUAL(windowSize, frameBuffer.size());
	CU_ASSERT_EQUAL(0, ::memcmp(expectedData, frameBuffer.getDebugData(1).data, frameBuffer.getDebugData(1).size));
	try {
		frameBuffer.getDebugData(0);
	} catch (std::out_of_range& e) {
		return;
	}
	CU_ASSERT(false);
}
CU_ErrorCode addFrameBufferTestSuite() {
	   CU_pSuite suite = NULL;
	   suite = CU_add_suite("Tests for the frame buffer", NULL, NULL);
	   if (NULL == suite) {
	      return CU_get_error();
	   }

	   if (
			   (NULL == CU_add_test(suite, "Add debug data to a slot", testAddDebugDataToFrameBuffer)) ||
			   (NULL == CU_add_test(suite, "Add debug data to several slots", testAddDebugDataToSeveralSlots)) ||
			   (NULL == CU_add_test(suite, "Get data from out of bounds slot", testToGetSlotOutOfBounds)) ||
			   (NULL == CU_add_test(suite, "Sliding window", testSlidingWindow))
	   ) {
	      return CU_get_error();
	   }
	   return CUE_SUCCESS;
}
