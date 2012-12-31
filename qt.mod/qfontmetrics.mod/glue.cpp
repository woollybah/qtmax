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

MaxQFontMetrics::MaxQFontMetrics(const QFontMetrics & m)
	: metrics(m)
{
}

MaxQFontMetrics::~MaxQFontMetrics()
{
}

QFontMetrics & MaxQFontMetrics::Metrics() {
	return metrics;
}


// *********************************************

MaxQFontMetrics * bmx_qt_qfontmetrics_create(MaxQFont * font) {
	return new MaxQFontMetrics(font->Font());
}

int bmx_qt_qfontmetrics_ascent(MaxQFontMetrics * fm) {
	return fm->Metrics().ascent();
}

int bmx_qt_qfontmetrics_averagecharwidth(MaxQFontMetrics * fm) {
	return fm->Metrics().averageCharWidth();
}

MaxQRect * bmx_qt_qfontmetrics_boundingrect(MaxQFontMetrics * fm, BBString * text) {
	return new MaxQRect(fm->Metrics().boundingRect(qStringFromBBString(text)));
}

void bmx_qt_qfontmetrics_free(MaxQFontMetrics * fm) {
	delete fm;
}

int bmx_qt_qfontmetrics_descent(MaxQFontMetrics * fm) {
	return fm->Metrics().descent();
}

BBString * bmx_qt_qfontmetrics_elidedtext(MaxQFontMetrics * fm, BBString * text, int _mode, int width, int flags) {
	return bbStringFromQString(fm->Metrics().elidedText(qStringFromBBString(text), (Qt::TextElideMode)_mode, width, flags));
}

int bmx_qt_qfontmetrics_height(MaxQFontMetrics * fm) {
	return fm->Metrics().height();
}

int bmx_qt_qfontmetrics_infont(MaxQFontMetrics * fm, int ch) {
	return static_cast<int>(fm->Metrics().inFont(ch));
}

int bmx_qt_qfontmetrics_leading(MaxQFontMetrics * fm) {
	return fm->Metrics().leading();
}

int bmx_qt_qfontmetrics_leftbearing(MaxQFontMetrics * fm, int ch) {
	return fm->Metrics().leftBearing(ch);
}

int bmx_qt_qfontmetrics_linespacing(MaxQFontMetrics * fm) {
	return fm->Metrics().lineSpacing();
}

int bmx_qt_qfontmetrics_linewidth(MaxQFontMetrics * fm) {
	return fm->Metrics().lineWidth();
}

int bmx_qt_qfontmetrics_maxwidth(MaxQFontMetrics * fm) {
	return fm->Metrics().maxWidth();
}

int bmx_qt_qfontmetrics_minleftbearing(MaxQFontMetrics * fm) {
	return fm->Metrics().minLeftBearing();
}

int bmx_qt_qfontmetrics_minrightbearing(MaxQFontMetrics * fm) {
	return fm->Metrics().minRightBearing();
}

int bmx_qt_qfontmetrics_overlinepos(MaxQFontMetrics * fm) {
	return fm->Metrics().overlinePos();
}

int bmx_qt_qfontmetrics_rightbearing(MaxQFontMetrics * fm, int ch) {
	return fm->Metrics().rightBearing(ch);
}


void bmx_qt_qfontmetrics_size(MaxQFontMetrics * fm, int flags, BBString * text, BBArray * tabArray, int * w, int * h) {
// TODO
//	QSize s(fm->Metrics().size(flags, qStringFromBBString(text), )
}

int bmx_qt_qfontmetrics_strikeoutpos(MaxQFontMetrics * fm) {
	return fm->Metrics().strikeOutPos();
}

MaxQRect * bmx_qt_qfontmetrics_tightboundingrect(MaxQFontMetrics * fm, BBString * text) {
	return new MaxQRect(fm->Metrics().tightBoundingRect(qStringFromBBString(text)));
}

int bmx_qt_qfontmetrics_underlinepos(MaxQFontMetrics * fm) {
	return fm->Metrics().underlinePos();
}

int bmx_qt_qfontmetrics_width(MaxQFontMetrics * fm, BBString * text, int length) {
	return fm->Metrics().width(qStringFromBBString(text), length);
}

int bmx_qt_qfontmetrics_xheight(MaxQFontMetrics * fm) {
	return fm->Metrics().xHeight();
}



// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
