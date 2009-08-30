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

MaxQTextCharFormat::MaxQTextCharFormat(const QTextCharFormat & f)
	: textcharformat(f), MaxQTextFormat(f)
{
}

QTextCharFormat & MaxQTextCharFormat::Format() {
	return textcharformat;
}


// *********************************************

MaxQTextCharFormat * bmx_qt_qtextcharformat_create() {
	QTextCharFormat f;
	return new MaxQTextCharFormat(f);
}

void bmx_qt_qtextcharformat_free(MaxQTextCharFormat * format) {
	delete format;
}

BBString * bmx_qt_qtextcharformat_anchorhref(MaxQTextCharFormat * format) {
	return bbStringFromQString(format->Format().anchorHref());
}

BBArray * bmx_qt_qtextcharformat_anchornames(MaxQTextCharFormat * format) {
	//return format->Format().
}

MaxQFont * bmx_qt_qtextcharformat_font(MaxQTextCharFormat * format) {
	return new MaxQFont(format->Format().font());
}

int bmx_qt_qtextcharformat_fontcapitalization(MaxQTextCharFormat * format) {
	return format->Format().fontCapitalization();
}

BBString * bmx_qt_qtextcharformat_fontfamily(MaxQTextCharFormat * format) {
	return bbStringFromQString(format->Format().fontFamily());
}

int bmx_qt_qtextcharformat_fontfixedpitch(MaxQTextCharFormat * format) {
	return static_cast<int>(format->Format().fontFixedPitch());
}

int bmx_qt_qtextcharformat_fontitalic(MaxQTextCharFormat * format) {
	return static_cast<int>(format->Format().fontItalic());
}

int bmx_qt_qtextcharformat_fontkerning(MaxQTextCharFormat * format) {
	return static_cast<int>(format->Format().fontKerning());
}

double bmx_qt_qtextcharformat_fontletterspacing(MaxQTextCharFormat * format) {
	return format->Format().fontLetterSpacing();
}

int bmx_qt_qtextcharformat_fontoverline(MaxQTextCharFormat * format) {
	return static_cast<int>(format->Format().fontOverline());
}

double bmx_qt_qtextcharformat_fontpointsize(MaxQTextCharFormat * format) {
	return format->Format().fontPointSize();
}

int bmx_qt_qtextcharformat_fontstrikeout(MaxQTextCharFormat * format) {
	return static_cast<int>(format->Format().fontStrikeOut());
}

int bmx_qt_qtextcharformat_fontstylehint(MaxQTextCharFormat * format) {
	return format->Format().fontStyleHint();
}

int bmx_qt_qtextcharformat_fontstylestrategy(MaxQTextCharFormat * format) {
	return format->Format().fontStyleStrategy();
}

int bmx_qt_qtextcharformat_fontunderline(MaxQTextCharFormat * format) {
	return static_cast<int>(format->Format().fontUnderline());
}

int bmx_qt_qtextcharformat_fontweight(MaxQTextCharFormat * format) {
	return format->Format().fontWeight();
}

double bmx_qt_qtextcharformat_fontwordspacing(MaxQTextCharFormat * format) {
	return format->Format().fontWordSpacing();
}

int bmx_qt_qtextcharformat_isanchor(MaxQTextCharFormat * format) {
	return static_cast<int>(format->Format().isAnchor());
}

int bmx_qt_qtextcharformat_isvalid(MaxQTextCharFormat * format) {
	return static_cast<int>(format->Format().isValid());
}

void bmx_qt_qtextcharformat_setanchor(MaxQTextCharFormat * format, int anchor) {
	format->Format().setAnchor(static_cast<bool>(anchor));
}

void bmx_qt_qtextcharformat_setanchorhref(MaxQTextCharFormat * format, BBString * value) {
	format->Format().setAnchorHref(qStringFromBBString(value));
}

void bmx_qt_qtextcharformat_setanchornames(MaxQTextCharFormat * format, BBArray * names) {
	//format->Format().setAnchorNames
}

void bmx_qt_qtextcharformat_setfont(MaxQTextCharFormat * format, MaxQFont * font) {
	format->Format().setFont(font->Font());
}

void bmx_qt_qtextcharformat_setfontcapitalization(MaxQTextCharFormat * format, int capitalization) {
	format->Format().setFontCapitalization((QFont::Capitalization)capitalization);
}

void bmx_qt_qtextcharformat_setfontfamily(MaxQTextCharFormat * format, BBString * family) {
	format->Format().setFontFamily(qStringFromBBString(family));
}

void bmx_qt_qtextcharformat_setfontfixedpitch(MaxQTextCharFormat * format, int fixedpitch) {
	format->Format().setFontFixedPitch(static_cast<bool>(fixedpitch));
}

void bmx_qt_qtextcharformat_setfontitalic(MaxQTextCharFormat * format, int italic) {
	format->Format().setFontItalic(static_cast<bool>(italic));
}

void bmx_qt_qtextcharformat_setfontkerning(MaxQTextCharFormat * format, int enable) {
	format->Format().setFontKerning(static_cast<bool>(enable));
}

void bmx_qt_qtextcharformat_setfontletterspacing(MaxQTextCharFormat * format, double spacing) {
	format->Format().setFontLetterSpacing(spacing);
}

void bmx_qt_qtextcharformat_setfontoverline(MaxQTextCharFormat * format, int overline) {
	format->Format().setFontOverline(static_cast<bool>(overline));
}

void bmx_qt_qtextcharformat_setfontpointsize(MaxQTextCharFormat * format, double size) {
	format->Format().setFontPointSize(size);
}

void bmx_qt_qtextcharformat_setfontstrikeout(MaxQTextCharFormat * format, int strikeOut) {
	format->Format().setFontStrikeOut(static_cast<bool>(strikeOut));
}

void bmx_qt_qtextcharformat_setfontstylehint(MaxQTextCharFormat * format, int hint, int strategy) {
	format->Format().setFontStyleHint((QFont::StyleHint)hint, (QFont::StyleStrategy)strategy);
}

void bmx_qt_qtextcharformat_setfontstylestrategy(MaxQTextCharFormat * format, int strategy) {
	format->Format().setFontStyleStrategy((QFont::StyleStrategy)strategy);
}

void bmx_qt_qtextcharformat_setfontunderline(MaxQTextCharFormat * format, int underline) {
	format->Format().setFontUnderline(static_cast<bool>(underline));
}

void bmx_qt_qtextcharformat_setfontweight(MaxQTextCharFormat * format, int weight) {
	format->Format().setFontWeight(weight);
}

void bmx_qt_qtextcharformat_setfontwordspacing(MaxQTextCharFormat * format, double spacing) {
	format->Format().setFontWordSpacing(spacing);
}

void bmx_qt_qtextcharformat_settextoutline(MaxQTextCharFormat * format, MaxQPen * pen) {
	format->Format().setTextOutline(pen->Pen());
}

void bmx_qt_qtextcharformat_settooltip(MaxQTextCharFormat * format, BBString * text) {
	format->Format().setToolTip(qStringFromBBString(text));
}

void bmx_qt_qtextcharformat_setunderlinecolor(MaxQTextCharFormat * format, MaxQColor * color) {
	format->Format().setUnderlineColor(color->Color());
}

void bmx_qt_qtextcharformat_setunderlinestyle(MaxQTextCharFormat * format, int style) {
	format->Format().setUnderlineStyle((QTextCharFormat::UnderlineStyle)style);
}

void bmx_qt_qtextcharformat_setverticalalignment(MaxQTextCharFormat * format, int alignment) {
	format->Format().setVerticalAlignment((QTextCharFormat::VerticalAlignment)alignment);
}

MaxQPen * bmx_qt_qtextcharformat_textoutline(MaxQTextCharFormat * format) {
	return new MaxQPen(format->Format().textOutline());
}

BBString * bmx_qt_qtextcharformat_tooltip(MaxQTextCharFormat * format) {
	return bbStringFromQString(format->Format().toolTip());
}

MaxQColor * bmx_qt_qtextcharformat_underlinecolor(MaxQTextCharFormat * format) {
	return new MaxQColor(format->Format().underlineColor());
}

int bmx_qt_qtextcharformat_underlinestyle(MaxQTextCharFormat * format) {
	return format->Format().underlineStyle();
}

int bmx_qt_qtextcharformat_verticalalignment(MaxQTextCharFormat * format) {
	return format->Format().verticalAlignment();
}

void bmx_qt_qtextcharformat_setforeground(MaxQTextCharFormat * format, MaxQBrush * brush) {
	format->Format().setForeground(brush->Brush());
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
