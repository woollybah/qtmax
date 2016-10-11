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

#ifndef MAX_QT_QFONTINFO
#define MAX_QT_QFONTINFO

#include "../core.mod/glue.h"
#include "../qfont.mod/glue.h"
#include <QtCore>
#include <QFontInfo>

class MaxQFontInfo;

extern "C" {

#include <blitz.h>

	MaxQFontInfo * bmx_qt_qfontinfo_create(MaxQFont * font);
	int bmx_qt_qfontinfo_bold(MaxQFontInfo * info);
	int bmx_qt_qfontinfo_exactmatch(MaxQFontInfo * info);
	BBString * bmx_qt_qfontinfo_family(MaxQFontInfo * info);
	int bmx_qt_qfontinfo_fixedpitch(MaxQFontInfo * info);
	int bmx_qt_qfontinfo_italic(MaxQFontInfo * info);
	int bmx_qt_qfontinfo_pixelsize(MaxQFontInfo * info);
	int bmx_qt_qfontinfo_pointsize(MaxQFontInfo * info);
	double bmx_qt_qfontinfo_pointsizef(MaxQFontInfo * info);
	int bmx_qt_qfontinfo_rawmode(MaxQFontInfo * info);
	int bmx_qt_qfontinfo_style(MaxQFontInfo * info);
	int bmx_qt_qfontinfo_stylehint(MaxQFontInfo * info);
	BBString * bmx_qt_qfontinfo_stylename(MaxQFontInfo * info);
	int bmx_qt_qfontinfo_weight(MaxQFontInfo * info);
	void bmx_qt_qfontinfo_free(MaxQFontInfo * info);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQFontInfo
{
public:
	MaxQFontInfo(const QFontInfo & i);
	~MaxQFontInfo();
	
	QFontInfo & Info();

private:
	QFontInfo info;
};

#endif
