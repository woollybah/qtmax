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

#ifndef MAX_QT_QPROPERTYANIMATION
#define MAX_QT_QPROPERTYANIMATION

#include "../core.mod/glue.h"
#include <QtCore>
#include <QVariantAnimation>

class MaxQPropertyAnimation;

extern "C" {

#include <blitz.h>

	void _qt_qpropertyanimation_QPropertyAnimation__updateCurrentValue(BBObject * handle, BBObject * variant);
	MaxQVariant * _qt_qpropertyanimation_QPropertyAnimation__currentValue(BBObject * handle);

	MaxQPropertyAnimation * bmx_qt_qpropertyanimation_create(BBObject * handle, QObject * parent);
	void bmx_qt_qpropertyanimation_setduration(MaxQPropertyAnimation * anim, int value);
	int bmx_qt_qpropertyanimation_duration(MaxQPropertyAnimation * anim);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQPropertyAnimation : public QVariantAnimation
{
    Q_OBJECT

public:
	MaxQPropertyAnimation(BBObject * handle, QObject *parent = 0);
	~MaxQPropertyAnimation();

protected:
    bool event(QEvent *event);
    void updateCurrentValue(const QVariant &value);
    void updateState(QAbstractAnimation::State newState, QAbstractAnimation::State oldState);

private:
	BBObject * maxHandle;
};

#endif
