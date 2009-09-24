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

MaxQFontComboBox::MaxQFontComboBox(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QFontComboBox(parent)
{
	qbind(this, handle);

	connect(this, SIGNAL(currentFontChanged(const QFont &)), SLOT(onCurrentFontChanged(const QFont &)));
	connect(this, SIGNAL(activated(int)), SLOT(onActivated(int)));
	connect(this, SIGNAL(currentIndexChanged(int)), SLOT(onCurrentIndexChanged(int)));
	connect(this, SIGNAL(editTextChanged(const QString &)), SLOT(onEditTextChanged(const QString &)));
	connect(this, SIGNAL(highlighted(int)), SLOT(onHighlighted(int)));
	connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), SLOT(onCustomContextMenuRequested(const QPoint &)));
}

MaxQFontComboBox::~MaxQFontComboBox()
{
	qunbind(this);
}

void MaxQFontComboBox::onCurrentFontChanged(const QFont & font){
	_qt_qfontcombobox_QFontComboBox__OnCurrentFontChanged(maxHandle, new MaxQFont(font));
}

void MaxQFontComboBox::onActivated(int index) {
	_qt_qcombobox_QComboBox__OnActivated(maxHandle, index);
}

void MaxQFontComboBox::onCurrentIndexChanged(int index) {
	_qt_qcombobox_QComboBox__OnCurrentIndexChanged(maxHandle, index);
}

void MaxQFontComboBox::onEditTextChanged(const QString & text) {
	_qt_qcombobox_QComboBox__OnEditTextChanged(maxHandle, bbStringFromQString(text));
}

void MaxQFontComboBox::onHighlighted(int index) {
	_qt_qcombobox_QComboBox__OnHighlighted(maxHandle, index);
}

void MaxQFontComboBox::onCustomContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}

void MaxQFontComboBox::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

QFontComboBox * bmx_qt_qfontcombobox_create(BBObject * handle, QWidget * parent) {
	return new MaxQFontComboBox(handle, parent);
}

MaxQFont * bmx_qt_qfontcombobox_currentfont(QFontComboBox * cb) {
	return new MaxQFont(cb->currentFont());
}

int bmx_qt_qfontcombobox_fontfilters(QFontComboBox * cb) {
	return cb->fontFilters();
}

void bmx_qt_qfontcombobox_setfontfilters(QFontComboBox * cb, int filters) {
	cb->setFontFilters((QFontComboBox::FontFilters) filters);
}

void bmx_qt_qfontcombobox_setwritingsystem(QFontComboBox * cb, int script) {
	cb->setWritingSystem((QFontDatabase::WritingSystem)script);
}

int bmx_qt_qfontcombobox_writingsystem(QFontComboBox * cb) {
	return cb->writingSystem();
}

void bmx_qt_qfontcombobox_setcurrentfont(QFontComboBox * cb, MaxQFont * font) {
	cb->setCurrentFont(font->Font());
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
