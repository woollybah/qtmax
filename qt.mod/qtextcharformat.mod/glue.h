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

#ifndef MAX_QT_QTEXTCHARFORMAT
#define MAX_QT_QTEXTCHARFORMAT

#include "../core.mod/glue.h"
#include "../qtextformat.mod/glue.h"
#include "../qcolor.mod/glue.h"
#include "../qfont.mod/glue.h"
#include "../qpen.mod/glue.h"
#include "../qbrush.mod/glue.h"
#include <QtCore>
#include <QTextCharFormat>

class MaxQTextCharFormat;

extern "C" {

#include <blitz.h>

	MaxQTextCharFormat * bmx_qt_qtextcharformat_create();
	void bmx_qt_qtextcharformat_free(MaxQTextCharFormat * format);
	BBString * bmx_qt_qtextcharformat_anchorhref(MaxQTextCharFormat * format);
	BBArray * bmx_qt_qtextcharformat_anchornames(MaxQTextCharFormat * format);
	MaxQFont * bmx_qt_qtextcharformat_font(MaxQTextCharFormat * format);
	int bmx_qt_qtextcharformat_fontcapitalization(MaxQTextCharFormat * format);
	BBString * bmx_qt_qtextcharformat_fontfamily(MaxQTextCharFormat * format);
	int bmx_qt_qtextcharformat_fontfixedpitch(MaxQTextCharFormat * format);
	int bmx_qt_qtextcharformat_fontitalic(MaxQTextCharFormat * format);
	int bmx_qt_qtextcharformat_fontkerning(MaxQTextCharFormat * format);
	double bmx_qt_qtextcharformat_fontletterspacing(MaxQTextCharFormat * format);
	int bmx_qt_qtextcharformat_fontoverline(MaxQTextCharFormat * format);
	double bmx_qt_qtextcharformat_fontpointsize(MaxQTextCharFormat * format);
	int bmx_qt_qtextcharformat_fontstrikeout(MaxQTextCharFormat * format);
	int bmx_qt_qtextcharformat_fontstylehint(MaxQTextCharFormat * format);
	int bmx_qt_qtextcharformat_fontstylestrategy(MaxQTextCharFormat * format);
	int bmx_qt_qtextcharformat_fontunderline(MaxQTextCharFormat * format);
	int bmx_qt_qtextcharformat_fontweight(MaxQTextCharFormat * format);
	double bmx_qt_qtextcharformat_fontwordspacing(MaxQTextCharFormat * format);
	int bmx_qt_qtextcharformat_isanchor(MaxQTextCharFormat * format);
	int bmx_qt_qtextcharformat_isvalid(MaxQTextCharFormat * format);
	void bmx_qt_qtextcharformat_setanchor(MaxQTextCharFormat * format, int anchor);
	void bmx_qt_qtextcharformat_setanchorhref(MaxQTextCharFormat * format, BBString * value);
	void bmx_qt_qtextcharformat_setanchornames(MaxQTextCharFormat * format, BBArray * names);
	void bmx_qt_qtextcharformat_setfont(MaxQTextCharFormat * format, MaxQFont * font);
	void bmx_qt_qtextcharformat_setfontcapitalization(MaxQTextCharFormat * format, int capitalization);
	void bmx_qt_qtextcharformat_setfontfamily(MaxQTextCharFormat * format, BBString * family);
	void bmx_qt_qtextcharformat_setfontfixedpitch(MaxQTextCharFormat * format, int fixedpitch);
	void bmx_qt_qtextcharformat_setfontitalic(MaxQTextCharFormat * format, int italic);
	void bmx_qt_qtextcharformat_setfontkerning(MaxQTextCharFormat * format, int enable);
	void bmx_qt_qtextcharformat_setfontletterspacing(MaxQTextCharFormat * format, double spacing);
	void bmx_qt_qtextcharformat_setfontoverline(MaxQTextCharFormat * format, int overline);
	void bmx_qt_qtextcharformat_setfontpointsize(MaxQTextCharFormat * format, double size);
	void bmx_qt_qtextcharformat_setfontstrikeout(MaxQTextCharFormat * format, int strikeOut);
	void bmx_qt_qtextcharformat_setfontstylehint(MaxQTextCharFormat * format, int hint, int strategy);
	void bmx_qt_qtextcharformat_setfontstylestrategy(MaxQTextCharFormat * format, int strategy);
	void bmx_qt_qtextcharformat_setfontunderline(MaxQTextCharFormat * format, int underline);
	void bmx_qt_qtextcharformat_setfontweight(MaxQTextCharFormat * format, int weight);
	void bmx_qt_qtextcharformat_setfontwordspacing(MaxQTextCharFormat * format, double spacing);
	void bmx_qt_qtextcharformat_settextoutline(MaxQTextCharFormat * format, MaxQPen * pen);
	void bmx_qt_qtextcharformat_settooltip(MaxQTextCharFormat * format, BBString * text);
	void bmx_qt_qtextcharformat_setunderlinecolor(MaxQTextCharFormat * format, MaxQColor * color);
	void bmx_qt_qtextcharformat_setunderlinestyle(MaxQTextCharFormat * format, int style);
	void bmx_qt_qtextcharformat_setverticalalignment(MaxQTextCharFormat * format, int alignment);
	MaxQPen * bmx_qt_qtextcharformat_textoutline(MaxQTextCharFormat * format);
	BBString * bmx_qt_qtextcharformat_tooltip(MaxQTextCharFormat * format);
	MaxQColor * bmx_qt_qtextcharformat_underlinecolor(MaxQTextCharFormat * format);
	int bmx_qt_qtextcharformat_underlinestyle(MaxQTextCharFormat * format);
	int bmx_qt_qtextcharformat_verticalalignment(MaxQTextCharFormat * format);

	void bmx_qt_qtextcharformat_setforeground(MaxQTextCharFormat * format, MaxQBrush * brush);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


class MaxQTextCharFormat : public MaxQTextFormat
{
public:
	MaxQTextCharFormat(const QTextCharFormat & f);
	QTextCharFormat & Format();

private:
	QTextCharFormat textcharformat;
};

#endif
