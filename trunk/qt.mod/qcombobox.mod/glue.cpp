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

MaxQComboBox::MaxQComboBox(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QComboBox(parent)
{
	qbind(this, handle);

	connect(this, SIGNAL(activated(int)), SLOT(onActivated(int)));
	connect(this, SIGNAL(currentIndexChanged(int)), SLOT(onCurrentIndexChanged(int)));
	connect(this, SIGNAL(editTextChanged(QString)), SLOT(onEditTextChanged(QString)));
	connect(this, SIGNAL(highlighted(int)), SLOT(onHighlighted(int)));
}

MaxQComboBox::~MaxQComboBox()
{
	qunbind(this);
}

void MaxQComboBox::onActivated(int index) {
	_qt_qcombobox_QComboBox__OnActivated(maxHandle, index);
}

void MaxQComboBox::onCurrentIndexChanged(int index) {
	_qt_qcombobox_QComboBox__OnCurrentIndexChanged(maxHandle, index);
}

void MaxQComboBox::onEditTextChanged(const QString & text) {
	_qt_qcombobox_QComboBox__OnEditTextChanged(maxHandle, bbStringFromQString(text));
}

void MaxQComboBox::onHighlighted(int index) {
	_qt_qcombobox_QComboBox__OnHighlighted(maxHandle, index);
}

void MaxQComboBox::customContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}

// *********************************************

QComboBox * bmx_qt_qcombobox_create(BBObject * handle, QWidget * parent) {
	return new MaxQComboBox(handle, parent);
}

void bmx_qt_qcombobox_addItem(QComboBox * cb, BBString * text, BBInt64 itemId) {
	cb->addItem(qStringFromBBString(text), QVariant(itemId));
}

void bmx_qt_qcombobox_addItems(QComboBox * cb, BBArray * texts) {
	// TODO
}

int bmx_qt_qcombobox_count(QComboBox * cb) {
	return cb->count();
}

int bmx_qt_qcombobox_currentindex(QComboBox * cb) {
	return cb->currentIndex();
}

void bmx_qt_qcombobox_insertitem(QComboBox * cb, int index, BBString * text, BBInt64 itemId) {
	cb->insertItem(index, qStringFromBBString(text), itemId);
}

void bmx_qt_qcombobox_itemdata(QComboBox * cb, int index, BBInt64 * id) {
	QVariant v = cb->itemData(index);
	if (v.type() != QVariant::Invalid) {
		*id = v.toLongLong();
	}
}

void bmx_qt_qcombobox_removeitem(QComboBox * cb, int index) {
	cb->removeItem(index);
}

void bmx_qt_qcombobox_setitemdata(QComboBox * cb, int index, BBInt64 id) {
	cb->setItemData(index, QVariant(id));
}

BBString * bmx_qt_qcombobox_currenttext(QComboBox * cb) {
	return bbStringFromQString(cb->currentText());
}

int bmx_qt_qcombobox_findtext(QComboBox * cb, BBString * text, int flags) {
	return cb->findText(qStringFromBBString(text), (Qt::MatchFlags)flags);
}

void bmx_qt_qcombobox_setcurrentindex(QComboBox * cb, int index) {
	cb->setCurrentIndex(index);
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
