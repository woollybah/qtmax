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

#ifndef MAX_QT_QCOLOR
#define MAX_QT_QCOLOR

#include "../core.mod/glue.h"
#include <QtCore>
#include <QColor>

class MaxQColor;

extern "C" {

#include <blitz.h>

	void bmx_qt_qcolor_free(MaxQColor * handle);

	MaxQColor * bmx_qt_qcolor_create(int r, int g, int b, int a);
	MaxQColor * bmx_qt_qcolor_createwithglobalcolor(int color);
	MaxQColor * bmx_qt_qcolor_lighter(MaxQColor * color, int factor);

	void bmx_qt_qcolor_getrgb(MaxQColor * color, int * r, int * g, int * b);
	void bmx_qt_qcolor_getrgba(MaxQColor * color, int * r, int * g, int * b, int * a);
	int bmx_qt_qcolor_isvalid(MaxQColor * color);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQColor
{
public:
	MaxQColor(const QColor & c);
	~MaxQColor();
	
	QColor & Color();

private:
	QColor color;
};

#endif
