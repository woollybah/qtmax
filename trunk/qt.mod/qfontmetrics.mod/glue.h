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

#ifndef MAX_QT_QFONTMETRICS
#define MAX_QT_QFONTMETRICS

#include "../core.mod/glue.h"
#include "../qfont.mod/glue.h"
#include <QtCore>
#include <QFontMetrics>

class MaxQFontMetrics;

extern "C" {

#include <blitz.h>

	MaxQFontMetrics * bmx_qt_qfontmetrics_create(MaxQFont * font);
	int bmx_qt_qfontmetrics_ascent(MaxQFontMetrics * fm);
	int bmx_qt_qfontmetrics_averagecharwidth(MaxQFontMetrics * fm);
	MaxQRect * bmx_qt_qfontmetrics_boundingrect(MaxQFontMetrics * fm, BBString * text);
	void bmx_qt_qfontmetrics_free(MaxQFontMetrics * fm);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQFontMetrics
{
public:
	MaxQFontMetrics(const QFontMetrics & m);
	~MaxQFontMetrics();

	QFontMetrics & Metrics();

private:
	QFontMetrics metrics;
};

#endif
