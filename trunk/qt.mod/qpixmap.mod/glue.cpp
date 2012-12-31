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

#include "glue.h"

// ---------------------------------------------------------------------------------------

MaxQPixmap::MaxQPixmap(const QPixmap & p)
	: pixmap(p)
{
}

MaxQPixmap::~MaxQPixmap()
{
}

QPixmap & MaxQPixmap::Pixmap() {
	return pixmap;
}

// ---------------------------------------------------------------------------------------

MaxQBitmap::MaxQBitmap(const QBitmap & b)
	: bitmap(b)
{
}

MaxQBitmap::~MaxQBitmap()
{
}

QBitmap & MaxQBitmap::Bitmap() {
	return bitmap;
}

// *********************************************

MaxQPixmap * bmx_qt_qpixmap_create(int width, int height) {
	QPixmap p(width, height);
	return new MaxQPixmap(p);
}

void bmx_qt_qpixmap_free(MaxQPixmap * pixmap) {
	delete pixmap;
}

MaxQPixmap * bmx_qt_qpixmap_fromimage(MaxQImage * image, int flags) {
	return new MaxQPixmap(QPixmap::fromImage(image->Image(), (Qt::ImageConversionFlags)flags));
}

MaxQPixmap * bmx_qt_qpixmap_fromfile(BBString * filename, BBString * format, int flags) {
	QPixmap p(qStringFromBBString(filename), (format==&bbEmptyString) ? (char*)0 : (char*)qStringFromBBString(format).data(), (Qt::ImageConversionFlags)flags);
	return new MaxQPixmap(p);
}

void bmx_qt_qpixmap_fill(MaxQPixmap * pixmap, int color) {
	pixmap->Pixmap().fill((Qt::GlobalColor)color);
}

void bmx_qt_qpixmap_fillcolor(MaxQPixmap * pixmap, MaxQColor * color) {
	pixmap->Pixmap().fill(color->Color());
}

void bmx_qt_qpixmap_size(MaxQPixmap * pixmap, int * w, int * h) {
	QSize s(pixmap->Pixmap().size());
	*w = s.width();
	*h = s.height();
}

MaxQImage * bmx_qt_qpixmap_toimage(MaxQPixmap * pixmap) {
	return new MaxQImage(pixmap->Pixmap().toImage());
}

MaxQPixmap * bmx_qt_qpixmap_grabwindow(int window, int x, int y, int width, int height) {
	return new MaxQPixmap(QPixmap::grabWindow((WId)window, x, y, width, height));
}

MaxQPixmap * bmx_qt_qpixmap_scaled(MaxQPixmap * pixmap, int width, int height, int aspectRatioMode, int transformMode) {
	return new MaxQPixmap(pixmap->Pixmap().scaled(width, height, (Qt::AspectRatioMode)aspectRatioMode, (Qt::TransformationMode)transformMode));
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
