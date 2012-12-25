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

#ifndef MAX_QT_QPALETTE
#define MAX_QT_QPALETTE

#include "../core.mod/glue.h"
#include "../qbrush.mod/glue.h"
#include <QtCore>
#include <QPalette>

class MaxQPalette;

extern "C" {

#include <blitz.h>

	MaxQBrush * bmx_qt_qpalette_alternatebase(MaxQPalette * palette);
	MaxQBrush * bmx_qt_qpalette_base(MaxQPalette * palette);
	MaxQBrush * bmx_qt_qpalette_brighttext(MaxQPalette * palette);
	MaxQBrush * bmx_qt_qpalette_brushforgroup(MaxQPalette * palette, int group, int role);
	MaxQBrush * bmx_qt_qpalette_brush(MaxQPalette * palette, int role);
	MaxQBrush * bmx_qt_qpalette_button(MaxQPalette * palette);
	MaxQBrush * bmx_qt_qpalette_buttontext(MaxQPalette * palette);
	void bmx_qt_qpalette_cachekey(MaxQPalette * palette, BBInt64 * key);
	MaxQColor * bmx_qt_qpalette_colorforgroup(MaxQPalette * palette, int group, int role);
	MaxQColor * bmx_qt_qpalette_color(MaxQPalette * palette, int role);
	int bmx_qt_qpalette_currentcolorgroup(MaxQPalette * palette);
	MaxQBrush * bmx_qt_qpalette_dark(MaxQPalette * palette);
	MaxQBrush * bmx_qt_qpalette_highlight(MaxQPalette * palette);
	MaxQBrush * bmx_qt_qpalette_highlightedtext(MaxQPalette * palette);
	int bmx_qt_qpalette_isbrushset(MaxQPalette * palette, int cg, int cr);
	int bmx_qt_qpalette_iscopyof(MaxQPalette * palette, MaxQPalette * p);
	int bmx_qt_qpalette_isequal(MaxQPalette * palette, int cg1, int cg2);
	MaxQBrush * bmx_qt_qpalette_light(MaxQPalette * palette);
	MaxQBrush * bmx_qt_qpalette_link(MaxQPalette * palette);
	MaxQBrush * bmx_qt_qpalette_linkvisited(MaxQPalette * palette);
	MaxQBrush * bmx_qt_qpalette_mid(MaxQPalette * palette);
	MaxQBrush * bmx_qt_qpalette_midlight(MaxQPalette * palette);
	MaxQPalette * bmx_qt_qpalette_resolve(MaxQPalette * palette, MaxQPalette * other);
	void bmx_qt_qpalette_setbrush(MaxQPalette * palette, int role, MaxQBrush * brush);
	void bmx_qt_qpalette_setbrushforgroup(MaxQPalette * palette, int group, int role, MaxQBrush * brush);
	void bmx_qt_qpalette_setcolorforgroup(MaxQPalette * palette, int group, int role, MaxQColor * color);
	void bmx_qt_qpalette_setcolor(MaxQPalette * palette, int role, MaxQColor * color);
	void bmx_qt_qpalette_setcolorgroup(MaxQPalette * palette, int cg, MaxQBrush * windowText, MaxQBrush * button, MaxQBrush * light, MaxQBrush * dark, MaxQBrush * Mid, MaxQBrush * text, MaxQBrush * brightText, MaxQBrush * base, MaxQBrush * window);
	void bmx_qt_qpalette_setcurrentcolorgroup(MaxQPalette * palette, int cg);
	MaxQBrush * bmx_qt_qpalette_shadow(MaxQPalette * palette);
	MaxQBrush * bmx_qt_qpalette_text(MaxQPalette * palette);
	MaxQBrush * bmx_qt_qpalette_tooltipbase(MaxQPalette * palette);
	MaxQBrush * bmx_qt_qpalette_tooltiptext(MaxQPalette * palette);
	MaxQBrush * bmx_qt_qpalette_window(MaxQPalette * palette);
	MaxQBrush * bmx_qt_qpalette_windowtext(MaxQPalette * palette);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQPalette
{
public:
	MaxQPalette(const QPalette & p);
	~MaxQPalette();
	
	QPalette & Palette();

private:
	QPalette palette;
};

#endif
