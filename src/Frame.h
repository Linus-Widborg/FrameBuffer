/*
 * Frame.h
 *
 *  Created on: Oct 2, 2016
 *      Author: linus
 */

#ifndef FRAME_H_
#define FRAME_H_
#include "ImageHandle.h"

class Frame {
public:
	Frame();
	Frame(ImageHandle* imageHandle);
	virtual ~Frame();
	ImageHandle* getImageHandle();
	void addImageHandle(ImageHandle* imageHandle);

private:
	ImageHandle* m_ImageHandle;
};

bool operator==(const Frame& lhs, const Frame& rhs);
bool operator!=(const Frame& lhs, const Frame& rhs);
#endif /* FRAME_H_ */
