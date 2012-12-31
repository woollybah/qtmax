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

#ifndef MAX_QT_QFONT
#define MAX_QT_QFONT

#include "../core.mod/glue.h"
#include <QtCore>
#include <QFont>

class MaxQFont;

extern "C" {

#include <blitz.h>

	MaxQFont * bmx_qt_qfont_create(BBString * family, int pointSize, int weight, int italic);
	int bmx_qt_qfont_bold(MaxQFont * font);
	int bmx_qt_qfont_capitalization(MaxQFont * font);
	BBString * bmx_qt_qfont_defaultfamily(MaxQFont * font);
	int bmx_qt_qfont_exactmatch(MaxQFont * font);
	BBString * bmx_qt_qfont_family(MaxQFont * font);
	int bmx_qt_qfont_fixedpitch(MaxQFont * font);
	int bmx_qt_qfont_fromstring(MaxQFont * font, BBString * description);
	int bmx_qt_qfont_iscopyof(MaxQFont * font, MaxQFont * f);
	int bmx_qt_qfont_italic(MaxQFont * font);
	int bmx_qt_qfont_kerning(MaxQFont * font);
	BBString * bmx_qt_qfont_key(MaxQFont * font);
	BBString * bmx_qt_qfont_lastresortfamily(MaxQFont * font);
	BBString * bmx_qt_qfont_lastresortfont(MaxQFont * font);
	double bmx_qt_qfont_letterspacing(MaxQFont * font);
	int bmx_qt_qfont_letterspacingtype(MaxQFont * font);
	int bmx_qt_qfont_overline(MaxQFont * font);
	int bmx_qt_qfont_pixelsize(MaxQFont * font);
	int bmx_qt_qfont_pointsize(MaxQFont * font);
	double bmx_qt_qfont_pointsizef(MaxQFont * font);
	int bmx_qt_qfont_rawmode(MaxQFont * font);
	BBString * bmx_qt_qfont_rawname(MaxQFont * font);
	MaxQFont * bmx_qt_qfont_resolve(MaxQFont * font, MaxQFont * other);
	void bmx_qt_qfont_setbold(MaxQFont * font, int enable);
	void bmx_qt_qfont_setcapitalization(MaxQFont * font, int caps);
	void bmx_qt_qfont_setfamily(MaxQFont * font, BBString * family);
	void bmx_qt_qfont_setfixedpitch(MaxQFont * font, int enable);
	void bmx_qt_qfont_setitalic(MaxQFont * font, int enable);
	void bmx_qt_qfont_setkerning(MaxQFont * font, int enable);
	void bmx_qt_qfont_setletterspacing(MaxQFont * font, int _type, double spacing);
	void bmx_qt_qfont_setoverline(MaxQFont * font, int enable);
	void bmx_qt_qfont_setpixelsize(MaxQFont * font, int pixelSize);
	void bmx_qt_qfont_setpointsize(MaxQFont * font, int pointSize);
	void bmx_qt_qfont_setpointsizef(MaxQFont * font, double pointSize);
	void bmx_qt_qfont_setrawmode(MaxQFont * font, int enable);
	void bmx_qt_qfont_setrawname(MaxQFont * font, BBString * name);
	void bmx_qt_qfont_setstretch(MaxQFont * font, int factor);
	void bmx_qt_qfont_setstrikeout(MaxQFont * font, int enable);
	void bmx_qt_qfont_setstyle(MaxQFont * font, int style);
	void bmx_qt_qfont_setstylehint(MaxQFont * font, int hint, int strategy);
	void bmx_qt_qfont_setstylestrategy(MaxQFont * font, int s);
	void bmx_qt_qfont_setunderline(MaxQFont * font, int enable);
	void bmx_qt_qfont_setweight(MaxQFont * font, int weight);
	void bmx_qt_qfont_setwordspacing(MaxQFont * font, double spacing);
	int bmx_qt_qfont_stretch(MaxQFont * font);
	int bmx_qt_qfont_strikeout(MaxQFont * font);
	int bmx_qt_qfont_style(MaxQFont * font);
	int bmx_qt_qfont_stylehint(MaxQFont * font);
	int bmx_qt_qfont_stylestrategy(MaxQFont * font);
	BBString * bmx_qt_qfont_tostring(MaxQFont * font);
	int bmx_qt_qfont_underline(MaxQFont * font);
	int bmx_qt_qfont_weight(MaxQFont * font);
	double  bmx_qt_qfont_wordspacing(MaxQFont * font);
	void bmx_qt_qfont_free(MaxQFont * font);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQFont
{
public:
	MaxQFont(const QFont & f);
	~MaxQFont();
	
	QFont & Font();

private:
	QFont font;
};

#endif
