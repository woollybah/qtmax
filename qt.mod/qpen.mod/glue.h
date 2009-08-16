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

#ifndef MAX_QT_QPEN
#define MAX_QT_QPEN

#include "../core.mod/glue.h"
#include "../qbrush.mod/glue.h"
#include "../qcolor.mod/glue.h"
#include <QtCore>
#include <QPen>

class MaxQPen;

extern "C" {

#include <blitz.h>

	MaxQPen * bmx_qt_qpen_create(int style);
	MaxQPen * bmx_qt_qpen_createwithattributes(MaxQBrush * brush, double width, int style, int cap, int join);
	MaxQBrush * bmx_qt_qpen_brush(MaxQPen * pen);
	int bmx_qt_qpen_capstyle(MaxQPen * pen);
	MaxQColor * bmx_qt_qpen_color(MaxQPen * pen);
	double bmx_qt_qpen_dashoffset(MaxQPen * pen);
	BBArray * bmx_qt_qpen_dashpattern(MaxQPen * pen);
	int bmx_qt_qpen_iscosmetic(MaxQPen * pen);
	int bmx_qt_qpen_issolid(MaxQPen * pen);
	int bmx_qt_qpen_joinstyle(MaxQPen * pen);
	double bmx_qt_qpen_miterlimit(MaxQPen * pen);
	void bmx_qt_qpen_setbrush(MaxQPen * pen, MaxQBrush * brush);
	void bmx_qt_qpen_setcapstyle(MaxQPen * pen, int style);
	void bmx_qt_qpen_setcolor(MaxQPen * pen, MaxQColor * color);
	void bmx_qt_qpen_setcosmetic(MaxQPen * pen, int cosmetic);
	void bmx_qt_qpen_setdashoffset(MaxQPen * pen, double offset);
	void bmx_qt_qpen_setdashpattern(MaxQPen * pen, BBArray * pattern);
	void bmx_qt_qpen_setjoinstyle(MaxQPen * pen, int style);
	void bmx_qt_qpen_setmiterlimit(MaxQPen * pen, double limit);
	void bmx_qt_qpen_setstyle(MaxQPen * pen, int style);
	void bmx_qt_qpen_setwidth(MaxQPen * pen, int width);
	void bmx_qt_qpen_setwidthf(MaxQPen * pen, double width);
	int bmx_qt_qpen_style(MaxQPen * pen);
	int bmx_qt_qpen_width(MaxQPen * pen);
	double bmx_qt_qpen_widthf(MaxQPen * pen);
	void bmx_qt_qpen_free(MaxQPen * pen);

	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQPen
{
public:
	MaxQPen(const QPen & p);
	~MaxQPen();
	
	QPen & Pen();

private:
	QPen pen;
};

#endif
