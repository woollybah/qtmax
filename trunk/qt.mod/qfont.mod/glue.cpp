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

#include "glue.h"

// ---------------------------------------------------------------------------------------

MaxQFont::MaxQFont(const QFont & f)
	: font(f)
{
}

MaxQFont::~MaxQFont()
{
}

QFont & MaxQFont::Font() {
	return font;
}


// *********************************************

MaxQFont * bmx_qt_qfont_create(BBString * family, int pointSize, int weight, int italic) {
	if (family != &bbEmptyString) {
		QFont f(qStringFromBBString(family), pointSize, weight, italic);
		return new MaxQFont(f);
	} else {
		return new MaxQFont(QFont());
	}
}

int bmx_qt_qfont_bold(MaxQFont * font) {
	return static_cast<int>(font->Font().bold());
}

int bmx_qt_qfont_capitalization(MaxQFont * font) {
	return font->Font().capitalization();
}

BBString * bmx_qt_qfont_defaultfamily(MaxQFont * font) {
	return bbStringFromQString(font->Font().defaultFamily());
}

int bmx_qt_qfont_exactmatch(MaxQFont * font) {
	return static_cast<int>(font->Font().exactMatch());
}

BBString * bmx_qt_qfont_family(MaxQFont * font) {
	return bbStringFromQString(font->Font().family());
}

int bmx_qt_qfont_fixedpitch(MaxQFont * font) {
	return static_cast<int>(font->Font().fixedPitch());
}

int bmx_qt_qfont_fromstring(MaxQFont * font, BBString * description) {
	return static_cast<int>(font->Font().fromString(qStringFromBBString(description)));
}

int bmx_qt_qfont_iscopyof(MaxQFont * font, MaxQFont * f) {
	return static_cast<int>(font->Font().isCopyOf(f->Font()));
}

int bmx_qt_qfont_italic(MaxQFont * font) {
	return static_cast<int>(font->Font().italic());
}

int bmx_qt_qfont_kerning(MaxQFont * font) {
	return static_cast<int>(font->Font().kerning());
}

BBString * bmx_qt_qfont_key(MaxQFont * font) {
	return bbStringFromQString(font->Font().key());
}

BBString * bmx_qt_qfont_lastresortfamily(MaxQFont * font) {
	return bbStringFromQString(font->Font().lastResortFamily());
}

BBString * bmx_qt_qfont_lastresortfont(MaxQFont * font) {
	return bbStringFromQString(font->Font().lastResortFont());
}

double bmx_qt_qfont_letterspacing(MaxQFont * font) {
	return font->Font().letterSpacing();
}

int bmx_qt_qfont_letterspacingtype(MaxQFont * font) {
	return font->Font().letterSpacingType();
}

int bmx_qt_qfont_overline(MaxQFont * font) {
	return static_cast<int>(font->Font().overline());
}

int bmx_qt_qfont_pixelsize(MaxQFont * font) {
	return font->Font().pixelSize();
}

int bmx_qt_qfont_pointsize(MaxQFont * font) {
	return font->Font().pointSize();
}

double bmx_qt_qfont_pointsizef(MaxQFont * font) {
	return font->Font().pointSizeF();
}

int bmx_qt_qfont_rawmode(MaxQFont * font) {
	return static_cast<int>(font->Font().rawMode());
}

BBString * bmx_qt_qfont_rawname(MaxQFont * font) {
	return bbStringFromQString(font->Font().rawName());
}

MaxQFont * bmx_qt_qfont_resolve(MaxQFont * font, MaxQFont * other) {
	return new MaxQFont(font->Font().resolve(other->Font()));
}

void bmx_qt_qfont_setbold(MaxQFont * font, int enable) {
	font->Font().setBold(static_cast<bool>(enable));
}

void bmx_qt_qfont_setcapitalization(MaxQFont * font, int caps) {
	font->Font().setCapitalization((QFont::Capitalization)caps);
}

void bmx_qt_qfont_setfamily(MaxQFont * font, BBString * family) {
	font->Font().setFamily(qStringFromBBString(family));
}

void bmx_qt_qfont_setfixedpitch(MaxQFont * font, int enable) {
	font->Font().setFixedPitch(static_cast<bool>(enable));
}

void bmx_qt_qfont_setitalic(MaxQFont * font, int enable) {
	font->Font().setItalic(static_cast<bool>(enable));
}

void bmx_qt_qfont_setkerning(MaxQFont * font, int enable) {
	font->Font().setKerning(static_cast<bool>(enable));
}

void bmx_qt_qfont_setletterspacing(MaxQFont * font, int _type, double spacing) {
	font->Font().setLetterSpacing((QFont::SpacingType)_type, spacing);
}

void bmx_qt_qfont_setoverline(MaxQFont * font, int enable) {
	font->Font().setOverline(static_cast<bool>(enable));
}

void bmx_qt_qfont_setpixelsize(MaxQFont * font, int pixelSize) {
	font->Font().setPixelSize(pixelSize);
}

void bmx_qt_qfont_setpointsize(MaxQFont * font, int pointSize) {
	font->Font().setPointSize(pointSize);
}

void bmx_qt_qfont_setpointsizef(MaxQFont * font, double pointSize) {
	font->Font().setPointSizeF(pointSize);
}

void bmx_qt_qfont_setrawmode(MaxQFont * font, int enable) {
	font->Font().setRawMode(static_cast<bool>(enable));
}

void bmx_qt_qfont_setrawname(MaxQFont * font, BBString * name) {
	font->Font().setRawName(qStringFromBBString(name));
}

void bmx_qt_qfont_setstretch(MaxQFont * font, int factor) {
	font->Font().setStretch(factor);
}

void bmx_qt_qfont_setstrikeout(MaxQFont * font, int enable) {
	font->Font().setStrikeOut(static_cast<bool>(enable));
}

void bmx_qt_qfont_setstyle(MaxQFont * font, int style) {
	font->Font().setStyle((QFont::Style)style);
}

void bmx_qt_qfont_setstylehint(MaxQFont * font, int hint, int strategy) {
	font->Font().setStyleHint((QFont::StyleHint)hint, (QFont::StyleStrategy)strategy);
}

void bmx_qt_qfont_setstylestrategy(MaxQFont * font, int s) {
	font->Font().setStyleStrategy((QFont::StyleStrategy)s);
}

void bmx_qt_qfont_setunderline(MaxQFont * font, int enable) {
	font->Font().setUnderline(static_cast<bool>(enable));
}

void bmx_qt_qfont_setweight(MaxQFont * font, int weight) {
	font->Font().setWeight(weight);
}

void bmx_qt_qfont_setwordspacing(MaxQFont * font, double spacing) {
	font->Font().setWordSpacing(spacing);
}

int bmx_qt_qfont_stretch(MaxQFont * font) {
	return font->Font().stretch();
}

int bmx_qt_qfont_strikeout(MaxQFont * font) {
	return static_cast<int>(font->Font().strikeOut());
}

int bmx_qt_qfont_style(MaxQFont * font) {
	return font->Font().style();
}

int bmx_qt_qfont_stylehint(MaxQFont * font) {
	return font->Font().styleHint();
}

int bmx_qt_qfont_stylestrategy(MaxQFont * font) {
	return font->Font().styleStrategy();
}

BBString * bmx_qt_qfont_tostring(MaxQFont * font) {
	return bbStringFromQString(font->Font().toString());
}

int bmx_qt_qfont_underline(MaxQFont * font) {
	return static_cast<int>(font->Font().underline());
}

int bmx_qt_qfont_weight(MaxQFont * font) {
	return font->Font().weight();
}

double  bmx_qt_qfont_wordspacing(MaxQFont * font) {
	return font->Font().wordSpacing();
}

void bmx_qt_qfont_free(MaxQFont * font) {
	delete font;
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
