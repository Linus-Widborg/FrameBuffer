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

private:
	ImageHandle* m_ImageHandle;
};

#endif /* FRAME_H_ */
