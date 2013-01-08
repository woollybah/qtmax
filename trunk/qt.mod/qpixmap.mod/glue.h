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

#ifndef MAX_QT_QPIXMAP
#define MAX_QT_QPIXMAP

#include "../core.mod/glue.h"
#include "../qimage.mod/glue.h"
#include "../qcolor.mod/glue.h"
#include <QtCore>
#include <QPixmap>
#include <QBitmap>

class MaxQPixmap;
class MaxQBitmap;

extern "C" {

#include <blitz.h>

	MaxQPixmap * bmx_qt_qpixmap_create(int width, int height);
	void bmx_qt_qpixmap_free(MaxQPixmap * pixmap);

	MaxQPixmap * bmx_qt_qpixmap_fromimage(MaxQImage * image, int flags);
	MaxQPixmap * bmx_qt_qpixmap_fromfile(BBString * filename, BBString * format, int flags);

	void bmx_qt_qpixmap_fill(MaxQPixmap * pixmap, int color);
	void bmx_qt_qpixmap_fillcolor(MaxQPixmap * pixmap, MaxQColor * color);
	void bmx_qt_qpixmap_size(MaxQPixmap * pixmap, int * w, int * h);
	MaxQImage * bmx_qt_qpixmap_toimage(MaxQPixmap * pixmap);
	MaxQPixmap * bmx_qt_qpixmap_grabwindow(int window, int x, int y, int width, int height);
	MaxQPixmap * bmx_qt_qpixmap_scaled(MaxQPixmap * pixmap, int width, int height, int aspectRatioMode, int transformMode);
	int bmx_qt_qpixmap_height(MaxQPixmap * pixmap);
	int bmx_qt_qpixmap_width(MaxQPixmap * pixmap);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQPixmap
{
public:
	MaxQPixmap(const QPixmap & p);
	~MaxQPixmap();

	QPixmap & Pixmap();

private:
	QPixmap pixmap;
};

class MaxQBitmap
{
public:
	MaxQBitmap(const QBitmap & b);
	~MaxQBitmap();

	QBitmap & Bitmap();

private:
	QBitmap bitmap;
};

#endif
