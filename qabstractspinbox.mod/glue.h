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

#ifndef MAX_QT_QABSTRACTSPINBOX
#define MAX_QT_QABStRACTSPINBOX

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QAbstractSpinBox>

extern "C" {

#include <blitz.h>

	void _qt_qabstractspinbox_QAbstractSpinBox__OnEditingFinished(BBObject * handle);

	int bmx_qt_qabstractspinbox_alignment(QAbstractSpinBox * box);
	int bmx_qt_qabstractspinbox_buttonsybmols(QAbstractSpinBox * box);
	int bmx_qt_qabstractspinbox_correctionmode(QAbstractSpinBox * box);
	BBString * bmx_qt_qabstractspinbox_fixup(QAbstractSpinBox * box, BBString * inp);
	int bmx_qt_qabstractspinbox_hasacceptableinput(QAbstractSpinBox * box);
	int bmx_qt_qabstractspinbox_hasframe(QAbstractSpinBox * box);
	void bmx_qt_qabstractspinbox_interprettext(QAbstractSpinBox * box);
	int bmx_qt_qabstractspinbox_isaccelerated(QAbstractSpinBox * box);
	int bmx_qt_qabstractspinbox_isreadonly(QAbstractSpinBox * box);
	int bmx_qt_qabstractspinbox_keyboardtracking(QAbstractSpinBox * box);
	void bmx_qt_qabstractspinbox_setaccelerated(QAbstractSpinBox * box, int on);
	void bmx_qt_qabstractspinbox_setalignment(QAbstractSpinBox * box, int flag);
	void bmx_qt_qabstractspinbox_setbuttonsymbols(QAbstractSpinBox * box, int bs);
	void bmx_qt_qabstractspinbox_setcorrectionmode(QAbstractSpinBox * box, int cm);
	void bmx_qt_qabstractspinbox_setframe(QAbstractSpinBox * box, int frame);
	void bmx_qt_qabstractspinbox_setkeyboardtracking(QAbstractSpinBox * box, int kt);
	void bmx_qt_qabstractspinbox_setreadonly(QAbstractSpinBox * box, int r);
	void bmx_qt_qabstractspinbox_setspecialvaluetext(QAbstractSpinBox * box, BBString * txt);
	void bmx_qt_qabstractspinbox_setwrapping(QAbstractSpinBox * box, int w);
	BBString * bmx_qt_qabstractspinbox_specialvaluetext(QAbstractSpinBox * box);
	void bmx_qt_qabstractspinbox_stepby(QAbstractSpinBox * box, int steps);
	BBString * bmx_qt_qabstractspinbox_text(QAbstractSpinBox * box);
	int bmx_qt_qabstractspinbox_validate(QAbstractSpinBox * box, BBString * inp, int * pos);
	int bmx_qt_qabstractspinbox_wrapping(QAbstractSpinBox * box);
	void bmx_qt_qabstractspinbox_clear(QAbstractSpinBox * box);
	void bmx_qt_qabstractspinbox_selectall(QAbstractSpinBox * box);
	void bmx_qt_qabstractspinbox_stepdown(QAbstractSpinBox * box);
	void bmx_qt_qabstractspinbox_stepup(QAbstractSpinBox * box);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif
