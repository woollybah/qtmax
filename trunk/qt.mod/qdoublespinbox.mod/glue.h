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

#ifndef MAX_QT_QDOUBLESPINBOX
#define MAX_QT_QDOUBLESPINBOX

#include "../core.mod/glue.h"
#include "../qabstractspinbox.mod/glue.h"
#include <QtCore>
#include <QDoubleSpinBox>

class MaxQDoubleSpinBox;

extern "C" {

#include <blitz.h>

	void _qt_qdoublespinbox_QDoubleSpinBox__OnValueChanged(BBObject * handle, double value);

	QDoubleSpinBox * bmx_qt_qdoublespinbox_create(BBObject * handle, QWidget * parent);
	BBString * bmx_qt_qdoublespinbox_cleantext(QDoubleSpinBox * box);
	int bmx_qt_qdoublespinbox_decimals(QDoubleSpinBox * box);
	double bmx_qt_qdoublespinbox_maximum(QDoubleSpinBox * box);
	double bmx_qt_qdoublespinbox_minimum(QDoubleSpinBox * box);
	BBString * bmx_qt_qdoublespinbox_prefix(QDoubleSpinBox * box);
	void bmx_qt_qdoublespinbox_setdecimals(QDoubleSpinBox * box, int prec);
	void bmx_qt_qdoublespinbox_setmaximum(QDoubleSpinBox * box, double value);
	void bmx_qt_qdoublespinbox_setminimum(QDoubleSpinBox * box, double value);
	void bmx_qt_qdoublespinbox_setprefix(QDoubleSpinBox * box, BBString * prefix);
	void bmx_qt_qdoublespinbox_setrange(QDoubleSpinBox * box, double minimum, double maximum);
	void bmx_qt_qdoublespinbox_setsinglestep(QDoubleSpinBox * box, double val);
	void bmx_qt_qdoublespinbox_setsuffix(QDoubleSpinBox * box, BBString * suffix);
	double bmx_qt_qdoublespinbox_singlestep(QDoubleSpinBox * box);
	BBString * bmx_qt_qdoublespinbox_suffix(QDoubleSpinBox * box);
	double bmx_qt_qdoublespinbox_value(QDoubleSpinBox * box);

	void bmx_qt_qdoublespinbox_setvalue(QDoubleSpinBox * box, double value);

	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQDoubleSpinBox : public QDoubleSpinBox
{
	Q_OBJECT

public:
	MaxQDoubleSpinBox(BBObject * handle, QWidget * parent);
	~MaxQDoubleSpinBox();

private:
	BBObject * maxHandle;

private slots:
	void onValueChanged(double value);
	void onEditingFinished();
	void onCustomContextMenuRequested(const QPoint & pos);

protected:
	void timerEvent(QTimerEvent * event);
};

#endif
