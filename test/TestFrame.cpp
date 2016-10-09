/*
 *
 *  Created on: Oct 1, 2016
 *      Author: linus
 */
#include <CUnit/Basic.h>
#include "TestFrame.h"
#include "../src/Frame.h"
#include "../src/ImageHandle.h"
void testToAddOneImageHandle() {
	Frame frame;
	ImageHandle* imageHandle = new ImageHandle();
	frame.addImageHandle(imageHandle);
	CU_ASSERT_PTR_EQUAL(imageHandle, frame.getImageHandle());
}

CU_ErrorCode addFrameTestSuite() {
	   CU_pSuite suite = NULL;
	   suite = CU_add_suite("Tests for the Frame object", NULL, NULL);
	   if (NULL == suite) {
	      return CU_get_error();
	   }

	   if (
			   (NULL == CU_add_test(suite, "Add one image handle", testToAddOneImageHandle))
	   ) {
	      return CU_get_error();
	   }
	return CUE_SUCCESS;
}
