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

MaxQPalette::MaxQPalette(const QPalette & p)
	: palette(p)
{
}

MaxQPalette::~MaxQPalette()
{
}

QPalette & MaxQPalette::Palette() {
	return palette;
}


// *********************************************

QPalette::ColorGroup bmx_qt_getcolorgroup(int g) {

	switch(g) {
		case 0:
			return QPalette::Active;
		case 1:
			return QPalette::Disabled;
		case 2:
			return QPalette::Inactive;
	}
	
	return QPalette::Normal;
}

QPalette::ColorRole bmx_qt_getcolorrole(int r) {

	switch(r) {
		case 0:
			return QPalette::WindowText;
		case 1:
			return QPalette::Button;
		case 2:
			return QPalette::Light;
		case 3:
			return QPalette::Midlight;
		case 4:
			return QPalette::Dark;
		case 5:
			return QPalette::Mid;
		case 6:
			return QPalette::Text;
		case 7:
			return QPalette::BrightText;
		case 8:
			return QPalette::ButtonText;
		case 9:
			return QPalette::Base;
		case 10:
			return QPalette::Window;
		case 11:
			return QPalette::Shadow;
		case 12:
			return QPalette::Highlight;
		case 13:
			return QPalette::HighlightedText;
		case 14:
			return QPalette::Link;
		case 15:
			return QPalette::LinkVisited;
		case 16:
			return QPalette::AlternateBase;
		case 18:
			return QPalette::ToolTipBase;
		case 19:
			return QPalette::ToolTipText;
	}
	
	return QPalette::WindowText;
}


MaxQBrush * bmx_qt_qpalette_alternatebase(MaxQPalette * palette) {
	QBrush b(palette->Palette().alternateBase());
	return new MaxQBrush(b);
}

MaxQBrush * bmx_qt_qpalette_base(MaxQPalette * palette) {
	QBrush b(palette->Palette().base());
	return new MaxQBrush(b);
}

MaxQBrush * bmx_qt_qpalette_brighttext(MaxQPalette * palette) {
	QBrush b(palette->Palette().brightText());
	return new MaxQBrush(b);
}

MaxQBrush * bmx_qt_qpalette_brushforgroup(MaxQPalette * palette, int group, int role) {
	QBrush b(palette->Palette().brush(bmx_qt_getcolorgroup(group), bmx_qt_getcolorrole(role)));
	return new MaxQBrush(b);
}

MaxQBrush * bmx_qt_qpalette_brush(MaxQPalette * palette, int role) {
	QBrush b(palette->Palette(). brush(bmx_qt_getcolorrole(role)));
	return new MaxQBrush(b);
}

MaxQBrush * bmx_qt_qpalette_button(MaxQPalette * palette) {
	QBrush b(palette->Palette().button());
	return new MaxQBrush(b);
}

MaxQBrush * bmx_qt_qpalette_buttontext(MaxQPalette * palette) {
	QBrush b(palette->Palette().buttonText());
	return new MaxQBrush(b);
}

void bmx_qt_qpalette_cachekey(MaxQPalette * palette, BBInt64 * key) {
	*key = palette->Palette().cacheKey();
}

MaxQColor * bmx_qt_qpalette_colorforgroup(MaxQPalette * palette, int group, int role) {
	QColor c(palette->Palette().color(bmx_qt_getcolorgroup(group), bmx_qt_getcolorrole(role)));
	return new MaxQColor(c);
}

MaxQColor * bmx_qt_qpalette_color(MaxQPalette * palette, int role) {
	QColor c(palette->Palette().color(bmx_qt_getcolorrole(role)));
	return new MaxQColor(c);
}

int bmx_qt_qpalette_currentcolorgroup(MaxQPalette * palette) {
	return palette->Palette().currentColorGroup();
}

MaxQBrush * bmx_qt_qpalette_dark(MaxQPalette * palette) {
	QBrush b(palette->Palette().dark());
	return new MaxQBrush(b);
}

MaxQBrush * bmx_qt_qpalette_highlight(MaxQPalette * palette) {
	QBrush b(palette->Palette().highlight());
	return new MaxQBrush(b);
}

MaxQBrush * bmx_qt_qpalette_highlightedtext(MaxQPalette * palette) {
	QBrush b(palette->Palette().highlightedText());
	return new MaxQBrush(b);
}

int bmx_qt_qpalette_isbrushset(MaxQPalette * palette, int cg, int cr) {
	return static_cast<int>(palette->Palette().isBrushSet(bmx_qt_getcolorgroup(cg), bmx_qt_getcolorrole(cr)));
}

int bmx_qt_qpalette_iscopyof(MaxQPalette * palette, MaxQPalette * p) {
	return static_cast<int>(palette->Palette().isCopyOf(p->Palette()));
}

int bmx_qt_qpalette_isequal(MaxQPalette * palette, int cg1, int cg2) {
	return static_cast<int>(palette->Palette().isEqual(bmx_qt_getcolorgroup(cg1), bmx_qt_getcolorgroup(cg2)));
}

MaxQBrush * bmx_qt_qpalette_light(MaxQPalette * palette) {
	QBrush b(palette->Palette().light());
	return new MaxQBrush(b);
}

MaxQBrush * bmx_qt_qpalette_link(MaxQPalette * palette) {
	QBrush b(palette->Palette().link());
	return new MaxQBrush(b);
}

MaxQBrush * bmx_qt_qpalette_linkvisited(MaxQPalette * palette) {
	QBrush b(palette->Palette().linkVisited());
	return new MaxQBrush(b);
}

MaxQBrush * bmx_qt_qpalette_mid(MaxQPalette * palette) {
	QBrush b(palette->Palette().mid());
	return new MaxQBrush(b);
}

MaxQBrush * bmx_qt_qpalette_midlight(MaxQPalette * palette) {
	QBrush b(palette->Palette().midlight());
	return new MaxQBrush(b);
}

MaxQPalette * bmx_qt_qpalette_resolve(MaxQPalette * palette, MaxQPalette * other) {
	QPalette p(palette->Palette().resolve(other->Palette()));
	return new MaxQPalette(p);
}

void bmx_qt_qpalette_setbrush(MaxQPalette * palette, int role, MaxQBrush * brush) {
	palette->Palette().setBrush(bmx_qt_getcolorrole(role), brush->Brush());
}

void bmx_qt_qpalette_setbrushforgroup(MaxQPalette * palette, int group, int role, MaxQBrush * brush) {
	palette->Palette().setBrush(bmx_qt_getcolorgroup(group), bmx_qt_getcolorrole(role), brush->Brush());
}

void bmx_qt_qpalette_setcolorforgroup(MaxQPalette * palette, int group, int role, MaxQColor * color) {
	palette->Palette().setColor(bmx_qt_getcolorgroup(group), bmx_qt_getcolorrole(role), color->Color());
}

void bmx_qt_qpalette_setcolor(MaxQPalette * palette, int role, MaxQColor * color) {
	palette->Palette().setColor(bmx_qt_getcolorrole(role), color->Color());
}

void bmx_qt_qpalette_setcolorgroup(MaxQPalette * palette, int cg, MaxQBrush * windowText, MaxQBrush * button, MaxQBrush * light, MaxQBrush * dark, MaxQBrush * Mid, MaxQBrush * text, MaxQBrush * brightText, MaxQBrush * base, MaxQBrush * window) {
	palette->Palette().setColorGroup(bmx_qt_getcolorgroup(cg), windowText->Brush(), button->Brush(), light->Brush(), dark->Brush(),
		Mid->Brush(), text->Brush(), brightText->Brush(), base->Brush(), window->Brush());
}

void bmx_qt_qpalette_setcurrentcolorgroup(MaxQPalette * palette, int cg) {
	palette->Palette().setCurrentColorGroup(bmx_qt_getcolorgroup(cg));
}

MaxQBrush * bmx_qt_qpalette_shadow(MaxQPalette * palette) {
	QBrush b(palette->Palette().shadow());
	return new MaxQBrush(b);
}

MaxQBrush * bmx_qt_qpalette_text(MaxQPalette * palette) {
	QBrush b(palette->Palette().text());
	return new MaxQBrush(b);
}

MaxQBrush * bmx_qt_qpalette_tooltipbase(MaxQPalette * palette) {
	QBrush b(palette->Palette().toolTipBase());
	return new MaxQBrush(b);
}

MaxQBrush * bmx_qt_qpalette_tooltiptext(MaxQPalette * palette) {
	QBrush b(palette->Palette().toolTipText());
	return new MaxQBrush(b);
}

MaxQBrush * bmx_qt_qpalette_window(MaxQPalette * palette) {
	QBrush b(palette->Palette().window());
	return new MaxQBrush(b);
}

MaxQBrush * bmx_qt_qpalette_windowtext(MaxQPalette * palette) {
	QBrush b(palette->Palette().windowText());
	return new MaxQBrush(b);
}

void bmx_qt_qpalette_free(MaxQPalette * palette) {
	delete palette;
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
