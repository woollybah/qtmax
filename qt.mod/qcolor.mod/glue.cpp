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

#include "glue.h"

// ---------------------------------------------------------------------------------------

MaxQColor::MaxQColor(const QColor & c)
	: color(c)
{
}

MaxQColor::~MaxQColor()
{
}

QColor & MaxQColor::Color() {
	return color;
}

// *********************************************

void bmx_qt_qcolor_free(MaxQColor * handle) {
	delete handle;
}

MaxQColor * bmx_qt_qcolor_create(int r, int g, int b, int a) {
	return new MaxQColor(QColor(r, g, b, a));
}

MaxQColor * bmx_qt_qcolor_createwithglobalcolor(int color) {
	return new MaxQColor(QColor((Qt::GlobalColor)color));
}

MaxQColor * bmx_qt_qcolor_lighter(MaxQColor * color, int factor) {
	return new MaxQColor(color->Color().lighter(factor));
}

void bmx_qt_qcolor_getrgb(MaxQColor * color, int * r, int * g, int * b) {
	color->Color().getRgb(r, g, b, 0);
}

void bmx_qt_qcolor_getrgba(MaxQColor * color, int * r, int * g, int * b, int * a) {
	color->Color().getRgb(r, g, b, a);
}

int bmx_qt_qcolor_isvalid(MaxQColor * color) {
	return static_cast<int>(color->Color().isValid());
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
