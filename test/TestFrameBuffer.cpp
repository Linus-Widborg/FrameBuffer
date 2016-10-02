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
//TODO Frame created in AddImageToFrame
//TODO Add several frames
//TODO Add debug data to frame in frame buffer
//TODO Frame buffer overflow
//TODO Ask for a frame that's not added
void testAddImageToFrameInFrameBuffer() {
	FrameBuffer frameBuffer;
	ImageHandle* imageHandle = new ImageHandle();
	uint64_t frameNumber = 0;
	CU_ASSERT_EQUAL(FrameBuffer::OK, frameBuffer.AddImageToFrame(frameNumber, imageHandle));
	CU_ASSERT_PTR_EQUAL(imageHandle, frameBuffer.getFrame(frameNumber).getImageHandle());
}

int main()
{
   CU_pSuite suite = NULL;

   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   suite = CU_add_suite("FrameBufferTests", setup, teardown);
   if (NULL == suite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   if (NULL == CU_add_test(suite, "Add image to frame in frame buffer", testAddImageToFrameInFrameBuffer)) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}



