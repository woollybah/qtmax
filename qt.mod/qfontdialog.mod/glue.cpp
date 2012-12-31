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



// *********************************************

QFontDialog::FontDialogOptions bmt_qt_getfontdialogoptions(int o) {
	QFontDialog::FontDialogOptions options;
	
	if (o & 0x0001) options |= QFontDialog::NoButtons;
	if (o & 0x0002) options |= QFontDialog::DontUseNativeDialog;
	
	return options;
}

MaxQFont * bmx_qt_qfontdialog_getfont(int * ok, QWidget * parent) {
	bool bok;
	QFont f = QFontDialog::getFont(&bok, parent);
	*ok = static_cast<int>(bok);
	return new MaxQFont(f);
}

MaxQFont * bmx_qt_qfontdialog_getfontwithinitial(int * ok, MaxQFont * initial, QWidget * parent) {
	bool bok;
	QFont f = QFontDialog::getFont(&bok, initial->Font(), parent);
	*ok = static_cast<int>(bok);
	return new MaxQFont(f);
}

MaxQFont * bmx_qt_qfontdialog_getfontwithoptions(int * ok, MaxQFont * initial, QWidget * parent, BBString * title, int options) {
	bool bok;
	QFont f = QFontDialog::getFont(&bok, initial->Font(), parent, qStringFromBBString(title), bmt_qt_getfontdialogoptions(options));
	*ok = static_cast<int>(bok);
	return new MaxQFont(f);
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
