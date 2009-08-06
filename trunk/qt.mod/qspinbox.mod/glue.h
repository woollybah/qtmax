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

#ifndef MAX_QT_QSPINBOX
#define MAX_QT_QSPINBOX

#include "../core.mod/glue.h"
#include "../qabstractspinbox.mod/glue.h"
#include <QtCore>
#include <QSpinBox>

class MaxQSpinBox;

extern "C" {

#include <blitz.h>

	void _qt_qspinbox_QSpinBox__OnValueChanged(BBObject * handle, int value);

	QSpinBox * bmx_qt_qspinbox_create(BBObject * handle, QWidget * parent);
	BBString * bmx_qt_qspinbox_cleantext(QSpinBox * box);
	int bmx_qt_qspinbox_maximum(QSpinBox * box);
	int bmx_qt_qspinbox_minimum(QSpinBox * box);
	BBString * bmx_qt_qspinbox_prefix(QSpinBox * box);
	void bmx_qt_qspinbox_setmaximum(QSpinBox * box, int value);
	void bmx_qt_qspinbox_setminimum(QSpinBox * box, int value);
	void bmx_qt_qspinbox_setprefix(QSpinBox * box, BBString * prefix);
	void bmx_qt_qspinbox_setrange(QSpinBox * box, int minimum, int maximum);
	void bmx_qt_qspinbox_setsinglestep(QSpinBox * box, int val);
	void bmx_qt_qspinbox_setsuffix(QSpinBox * box, BBString * suffix);
	int bmx_qt_qspinbox_singlestep(QSpinBox * box);
	BBString * bmx_qt_qspinbox_suffix(QSpinBox * box);
	int bmx_qt_qspinbox_value(QSpinBox * box);

	void bmx_qt_qspinbox_setvalue(QSpinBox * box, int value);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQSpinBox : public QSpinBox
{
	Q_OBJECT

public:
	MaxQSpinBox(BBObject * handle, QWidget * parent);
	~MaxQSpinBox();

private:
	BBObject * maxHandle;

private slots:
	void onValueChanged(int i);
	void onEditingFinished();
	void onCustomContextMenuRequested(const QPoint & pos);
};

#endif
