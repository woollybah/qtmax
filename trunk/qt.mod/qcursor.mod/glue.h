/*
  Copyright (c) 2009-2013 Bruce A Henderson
 
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

#ifndef MAX_QT_QCURSOR
#define MAX_QT_QCURSOR

#include "../core.mod/glue.h"
#include "../qpixmap.mod/glue.h"
#include <QtCore>
#include <QCursor>

class MaxQCursor;

extern "C" {

#include <blitz.h>

	MaxQCursor * bmx_qt_qcursor_create(int shape);
	void bmx_qt_qcursor_free(MaxQCursor * cursor);
	MaxQBitmap * bmx_qt_qcursor_bitmap(MaxQCursor * cursor);
	void bmx_qt_qcursor_hotspot(MaxQCursor * cursor, int * x, int * y);
	MaxQBitmap * bmx_qt_qcursor_mask(MaxQCursor * cursor);
	MaxQPixmap * bmx_qt_qcursor_pixmap(MaxQCursor * cursor);
	void bmx_qt_qcursor_setshape(MaxQCursor * cursor, int shape);
	int bmx_qt_qcursor_shape(MaxQCursor * cursor);
	void bmx_qt_qcursor_pos(int * x, int * y);
	void bmx_qt_qcursor_setpos(int x, int y);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQCursor
{
public:
	MaxQCursor(const QCursor & c);
	~MaxQCursor();
	
	QCursor & Cursor();

private:
	QCursor cursor;
};

#endif
