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

#ifndef MAX_QT_QTOOLTIP
#define MAX_QT_QTOOLTIP

#include "../core.mod/glue.h"
#include "../qfont.mod/glue.h"
#include "../qpalette.mod/glue.h"
#include <QtCore>
#include <QToolTip>

extern "C" {

#include <blitz.h>

	MaxQFont * bmx_qt_qtooltip_font();
	void bmx_qt_qtooltip_hidetext();
	int bmx_qt_qtooltip_isvisible();
	MaxQPalette * bmx_qt_qtooltip_palette();
	void bmx_qt_qtooltip_setfont(MaxQFont * font);
	void bmx_qt_qtooltip_setpalette(MaxQPalette * palette);
	void bmx_qt_qtooltip_showtext(int x, int y, BBString * text, QWidget * w, MaxQRect * rect);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif
