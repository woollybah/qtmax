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

MaxQDial::MaxQDial(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QDial(parent)
{
	qbind(this, handle);

	connect(this, SIGNAL(actionTriggered(int)), SLOT(onActionTriggered(int)));
	connect(this, SIGNAL(rangeChanged(int, int)), SLOT(onRangeChanged(int, int)));
	connect(this, SIGNAL(sliderMoved(int)), SLOT(onSliderMoved(int)));
	connect(this, SIGNAL(sliderPressed()), SLOT(onSliderPressed()));
	connect(this, SIGNAL(sliderReleased()), SLOT(onSliderReleased()));
	connect(this, SIGNAL(valueChanged(int)), SLOT(onValueChanged(int)));
	connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), SLOT(onCustomContextMenuRequested(const QPoint &)));
}

MaxQDial::~MaxQDial()
{
	qunbind(this);
}

void MaxQDial::onActionTriggered(int action) {
	_qt_qabstractslider_QAbstractSlider__OnActionTriggered(maxHandle, action);
}

void MaxQDial::onRangeChanged(int min, int max) {
	_qt_qabstractslider_QAbstractSlider__OnRangeChanged(maxHandle, min, max);
}

void MaxQDial::onSliderMoved(int value) {
	_qt_qabstractslider_QAbstractSlider__OnSliderMoved(maxHandle, value);
}

void MaxQDial::onSliderPressed() {
	_qt_qabstractslider_QAbstractSlider__OnSliderPressed(maxHandle);
}

void MaxQDial::onSliderReleased() {
	_qt_qabstractslider_QAbstractSlider__OnSliderReleased(maxHandle);
}

void MaxQDial::onValueChanged(int value) {
	_qt_qabstractslider_QAbstractSlider__OnValueChanged(maxHandle, value);
}

void MaxQDial::onCustomContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}

// *********************************************

QDial * bmx_qt_qdial_create(BBObject * handle, QWidget * parent) {
	return new MaxQDial(handle, parent);
}

int bmx_qt_qdial_notchsize(QDial * dial) {
	return dial->notchSize();
}

double bmx_qt_qdial_notchtarget(QDial * dial) {
	return dial->notchTarget();
}

int bmx_qt_qdial_notchesvisible(QDial * dial) {
	return static_cast<int>(dial->notchesVisible());
}

void bmx_qt_qdial_setnotchtarget(QDial * dial, double target) {
	return dial->setNotchTarget(target);
}

int bmx_qt_qdial_wrapping(QDial * dial) {
	return static_cast<int>(dial->wrapping());
}

void bmx_qt_qdial_setnotchesvisible(QDial * dial, int visible) {
	return dial->setNotchesVisible(static_cast<bool>(visible));
}

void bmx_qt_qdial_setwrapping(QDial * dial, int on) {
	return dial->setWrapping(static_cast<bool>(on));
}



// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
