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

MaxQPropertyAnimation::MaxQPropertyAnimation(BBObject * handle, QObject *parent)
	: maxHandle(handle), QVariantAnimation(parent)
{
	qbind(this, handle);
}

MaxQPropertyAnimation::~MaxQPropertyAnimation()
{
	qunbind(this);
}

bool MaxQPropertyAnimation::event(QEvent *event) {
//printf("::event\n");fflush(stdout);
	return QVariantAnimation::event(event);
}

void MaxQPropertyAnimation::updateCurrentValue(const QVariant &value) {
//printf("::updateCurrentValue\n");fflush(stdout);
    if (state() == QAbstractAnimation::Stopped) {
        return;
	}

	_qt_qpropertyanimation_QPropertyAnimation__updateCurrentValue(maxHandle, _qt_core_QVariant__CreateVariant(value.type(), new MaxQVariant(value)));
}

void MaxQPropertyAnimation::updateState(QAbstractAnimation::State newState, QAbstractAnimation::State oldState) {
//printf("::updateState\n");fflush(stdout);
	QVariantAnimation::updateState(newState, oldState);

	if (newState == Running) {

		// update the default start value
		if (oldState == Stopped) {
			QVariant v(_qt_qpropertyanimation_QPropertyAnimation__currentValue(maxHandle)->Variant());
			setStartValue(v);
			//let's check if we have a start value and an end value
		}
	}
}
// *********************************************

MaxQPropertyAnimation * bmx_qt_qpropertyanimation_create(BBObject * handle, QObject * parent) {
	return new MaxQPropertyAnimation(handle, parent);
}

void bmx_qt_qpropertyanimation_setduration(MaxQPropertyAnimation * anim, int value) {
	anim->setDuration(value);
}

int bmx_qt_qpropertyanimation_duration(MaxQPropertyAnimation * anim) {
	return anim->duration();
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
