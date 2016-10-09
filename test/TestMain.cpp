/*
 * TestMain.cpp
 *
 *  Created on: Oct 6, 2016
 *      Author: linus
 */
#include <CUnit/Basic.h>
#include "TestFrameBuffer.h"
#include "TestFrame.h"

int main()
{
	if (CUE_SUCCESS != CU_initialize_registry()) {
	      return CU_get_error();
	}
	CU_ErrorCode result;
	result = addFrameBufferTestSuite();
	result = addFrameTestSuite();
	if (CUE_SUCCESS != result) {
		CU_cleanup_registry();
		return result;
	}
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}




