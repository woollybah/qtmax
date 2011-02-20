/*
  Copyright (c) 2009 Bruce A Henderson
 
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/ 

#ifndef MAX_QT_QTRANSFORM
#define MAX_QT_QTRANSFORM

#include "../core.mod/glue.h"
#include <QtCore>
#include <QTransform>

class MaxQTransform;

extern "C" {

#include <blitz.h>

	MaxQTransform * bmx_qt_qtransform_create();
	void bmx_qt_qtransform_free(MaxQTransform * trans);
	void bmx_qt_qtransform_mappointf(MaxQTransform * trans, double x, double y, double * xp, double * yp);
	void bmx_qt_qtransform_rotate(MaxQTransform * trans, double angle, int axis);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQTransform
{
public:
	MaxQTransform(const QTransform & t);
	~MaxQTransform();
	
	QTransform & Transform();

private:
	QTransform transform;
};


#endif
