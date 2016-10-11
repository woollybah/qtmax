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

#ifndef MAX_QT_QTEXTFORMAT
#define MAX_QT_QTEXTFORMAT

#include "../core.mod/glue.h"
#include "../qbrush.mod/glue.h"
#include "../qpen.mod/glue.h"
#include <QtCore>
#include <QTextFormat>

class MaxQTextFormat;

extern "C" {

#include <blitz.h>

	MaxQBrush * bmx_qt_textformat_background(MaxQTextFormat * format);
	int bmx_qt_textformat_boolproperty(MaxQTextFormat * format, int propertyId);
	MaxQBrush * bmx_qt_textformat_brushproperty(MaxQTextFormat * format, int propertyId);
	void bmx_qt_textformat_clearbackground(MaxQTextFormat * format);
	void bmx_qt_textformat_clearforeground(MaxQTextFormat * format);
	void bmx_qt_textformat_clearproperty(MaxQTextFormat * format, int propertyId);
	MaxQColor * bmx_qt_textformat_colorProperty(MaxQTextFormat * format, int propertyId);
	double bmx_qt_textformat_doubleproperty(MaxQTextFormat * format, int propertyId);
	MaxQBrush * bmx_qt_textformat_foreground(MaxQTextFormat * format);
	int bmx_qt_textformat_hasproperty(MaxQTextFormat * format, int propertyId);
	int bmx_qt_textformat_intproperty(MaxQTextFormat * format, int propertyId);
	int bmx_qt_textformat_isblockformat(MaxQTextFormat * format);
	int bmx_qt_textformat_ischarformat(MaxQTextFormat * format);
	int bmx_qt_textformat_isframeformat(MaxQTextFormat * format);
	int bmx_qt_textformat_isimageformat(MaxQTextFormat * format);
	int bmx_qt_textformat_islistformat(MaxQTextFormat * format);
	int bmx_qt_textformat_istablecellformat(MaxQTextFormat * format);
	int bmx_qt_textformat_istableformat(MaxQTextFormat * format);
	int bmx_qt_textformat_isvalid(MaxQTextFormat * format);
	int bmx_qt_textformat_layoutdirection(MaxQTextFormat * format);
	void bmx_qt_textformat_merge(MaxQTextFormat * format, MaxQTextFormat * other);
	int bmx_qt_textformat_objectindex(MaxQTextFormat * format);
	int bmx_qt_textformat_objecttype(MaxQTextFormat * format);
	MaxQPen * bmx_qt_textformat_penproperty(MaxQTextFormat * format, int propertyId);
	int bmx_qt_textformat_propertycount(MaxQTextFormat * format);
	void bmx_qt_textformat_setbackground(MaxQTextFormat * format, MaxQBrush * brush);
	void bmx_qt_qtextformat_setforeground(MaxQTextFormat * format, MaxQBrush * brush);
	void bmx_qt_textformat_setlayoutdirection(MaxQTextFormat * format, int direction);
	void bmx_qt_textformat_setobjectindex(MaxQTextFormat * format, int index);
	void bmx_qt_textformat_setobjecttype(MaxQTextFormat * format, int _type);
	BBString * bmx_qt_textformat_stringproperty(MaxQTextFormat * format, int propertyId);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


class MaxQTextFormat
{
public:
	MaxQTextFormat(const QTextFormat & t);
	QTextFormat & Format();

private:
	QTextFormat textformat;
};

#endif
