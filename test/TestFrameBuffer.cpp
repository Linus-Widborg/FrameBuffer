/*
 * TestMain.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: linus
 */
#include <CUnit/Basic.h>
#include "../src/FrameBuffer.h"
#include "../src/ImageHandle.h"

int setup() {
	return 0;
}
int teardown() {
	return 0;
}
//TODO Add debug data to frame in frame buffer
//TODO Frame buffer overflow
//TODO Clean up. Who owns the image handle pointer?
//TODO A more dynamic container then array to store frames
//TODO Constness
//TODO Remove addFrame
void testAddOneFrame() {
	FrameBuffer frameBuffer;
	uint64_t frameNumber = 0;
	CU_ASSERT_EQUAL(frameBuffer.getFrame(frameNumber), frameBuffer.getFrame(frameNumber));
}

void testToAddSeveralFrames() {
	FrameBuffer frameBuffer;
	CU_ASSERT_NOT_EQUAL(frameBuffer.getFrame(0), frameBuffer.getFrame(1));
	CU_ASSERT_EQUAL(frameBuffer.getFrame(0), frameBuffer.getFrame(0));
	CU_ASSERT_NOT_EQUAL(frameBuffer.getFrame(0), frameBuffer.getFrame(8));
}

void testAddDataToFrame() {
	FrameBuffer frameBuffer;
	ImageHandle* imageHandle = new ImageHandle();
	frameBuffer.getFrame(8).addImageHandle(imageHandle);
	CU_ASSERT_PTR_EQUAL(imageHandle, frameBuffer.getFrame(8).getImageHandle());
}

int main()
{
   CU_pSuite suite = NULL;

   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   suite = CU_add_suite("A suite of frame buffer tests", setup, teardown);
   if (NULL == suite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   if (
		   (NULL == CU_add_test(suite, "Add one frame to the frame buffer", testAddOneFrame)) ||
		   (NULL == CU_add_test(suite, "Add several frames to the frame buffer", testToAddSeveralFrames)) ||
		   (NULL == CU_add_test(suite, "Add data to a frame", testAddDataToFrame))
   ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}



