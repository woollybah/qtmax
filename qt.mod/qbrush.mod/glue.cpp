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

MaxQBrush::MaxQBrush(const QBrush & b)
	: brush(b)
{
}

MaxQBrush::~MaxQBrush()
{
}

QBrush & MaxQBrush::Brush() {
	return brush;
}


// *********************************************

MaxQBrush * bmx_qt_qbrush_create() {
	return new MaxQBrush(QBrush());
}

MaxQBrush * bmx_qt_qbrush_createwithglobalcolor(int color, int style) {
	QBrush b((Qt::GlobalColor)color, (Qt::BrushStyle)style);
	return new MaxQBrush(b);
}

void bmx_qt_qbrush_free(MaxQBrush * brush) {
	delete brush;
}

MaxQBrush * bmx_qt_qbrush_createwithpixmap(MaxQPixmap * pixmap) {
	QBrush b(pixmap->Pixmap());
	return new MaxQBrush(b);
}

MaxQPixmap * bmx_qt_qbrush_texture(MaxQBrush * brush) {
	return new MaxQPixmap(brush->Brush().texture());
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
