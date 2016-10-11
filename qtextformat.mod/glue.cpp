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

MaxQTextFormat::MaxQTextFormat(const QTextFormat & t)
	: textformat(t)
{
}

QTextFormat & MaxQTextFormat::Format() {
	return textformat;
}


// *********************************************

MaxQBrush * bmx_qt_textformat_background(MaxQTextFormat * format) {
	return new MaxQBrush(format->Format().background());
}

int bmx_qt_textformat_boolproperty(MaxQTextFormat * format, int propertyId) {
	return static_cast<int>(format->Format().boolProperty(propertyId));
}

MaxQBrush * bmx_qt_textformat_brushproperty(MaxQTextFormat * format, int propertyId) {
	return new MaxQBrush(format->Format().brushProperty(propertyId));
}

void bmx_qt_textformat_clearbackground(MaxQTextFormat * format) {
	format->Format().clearBackground();
}

void bmx_qt_textformat_clearforeground(MaxQTextFormat * format) {
	format->Format().clearForeground();
}

void bmx_qt_textformat_clearproperty(MaxQTextFormat * format, int propertyId) {
	format->Format().clearProperty(propertyId);
}

MaxQColor * bmx_qt_textformat_colorProperty(MaxQTextFormat * format, int propertyId) {
	return new MaxQColor(format->Format().colorProperty(propertyId));
}

double bmx_qt_textformat_doubleproperty(MaxQTextFormat * format, int propertyId) {
	return format->Format().doubleProperty(propertyId);
}

MaxQBrush * bmx_qt_textformat_foreground(MaxQTextFormat * format) {
	return new MaxQBrush(format->Format().foreground());
}

int bmx_qt_textformat_hasproperty(MaxQTextFormat * format, int propertyId) {
	return static_cast<int>(format->Format().hasProperty(propertyId));
}

int bmx_qt_textformat_intproperty(MaxQTextFormat * format, int propertyId) {
	return format->Format().intProperty(propertyId);
}

int bmx_qt_textformat_isblockformat(MaxQTextFormat * format) {
	return static_cast<int>(format->Format().isBlockFormat());
}

int bmx_qt_textformat_ischarformat(MaxQTextFormat * format) {
	return static_cast<int>(format->Format().isCharFormat());
}

int bmx_qt_textformat_isframeformat(MaxQTextFormat * format) {
	return static_cast<int>(format->Format().isFrameFormat());
}

int bmx_qt_textformat_isimageformat(MaxQTextFormat * format) {
	return static_cast<int>(format->Format().isImageFormat());
}

int bmx_qt_textformat_islistformat(MaxQTextFormat * format) {
	return static_cast<int>(format->Format().isListFormat());
}

int bmx_qt_textformat_istablecellformat(MaxQTextFormat * format) {
	return static_cast<int>(format->Format().isTableCellFormat());
}

int bmx_qt_textformat_istableformat(MaxQTextFormat * format) {
	return static_cast<int>(format->Format().isTableFormat());
}

int bmx_qt_textformat_isvalid(MaxQTextFormat * format) {
	return static_cast<int>(format->Format().isValid());
}

int bmx_qt_textformat_layoutdirection(MaxQTextFormat * format) {
	return format->Format().layoutDirection();
}

void bmx_qt_textformat_merge(MaxQTextFormat * format, MaxQTextFormat * other) {
	format->Format().merge(other->Format());
}

int bmx_qt_textformat_objectindex(MaxQTextFormat * format) {
	return format->Format().objectIndex();
}

int bmx_qt_textformat_objecttype(MaxQTextFormat * format) {
	return format->Format().objectType();
}

MaxQPen * bmx_qt_textformat_penproperty(MaxQTextFormat * format, int propertyId) {
	return new MaxQPen(format->Format().penProperty(propertyId));
}

int bmx_qt_textformat_propertycount(MaxQTextFormat * format) {
	return format->Format().propertyCount();
}

void bmx_qt_textformat_setbackground(MaxQTextFormat * format, MaxQBrush * brush) {
	format->Format().setBackground(brush->Brush());
}

void bmx_qt_qtextformat_setforeground(MaxQTextFormat * format, MaxQBrush * brush) {
	format->Format().setForeground(brush->Brush());
}

void bmx_qt_textformat_setlayoutdirection(MaxQTextFormat * format, int direction) {
	format->Format().setLayoutDirection(bmx_qt_inttolayoutdirection(direction));
}

void bmx_qt_textformat_setobjectindex(MaxQTextFormat * format, int index) {
	format->Format().setObjectIndex(index);
}

void bmx_qt_textformat_setobjecttype(MaxQTextFormat * format, int _type) {
	format->Format().setObjectType(_type);
}

BBString * bmx_qt_textformat_stringproperty(MaxQTextFormat * format, int propertyId) {
	return bbStringFromQString(format->Format().stringProperty(propertyId));
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
