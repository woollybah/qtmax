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

#ifndef MAX_QT_QABSTRACTBUTTON
#define MAX_QT_QABSTRACTBUTTON

#include "../core.mod/glue.h"
#include "../qicon.mod/glue.h"
#include <QtCore>
#include <QAbstractButton>

extern "C" {

#include <blitz.h>

	void _qt_qabstractbutton_QAbstractButton__checkStateSet(BBObject * handle);
	int _qt_qabstractbutton_QAbstractButton__hitButton(BBObject * handle, int x, int y);
	void _qt_qabstractbutton_QAbstractButton__nextCheckState(BBObject * handle);


	int bmx_qt_qabstractbutton_autoexclusive(QAbstractButton * button);
	int bmx_qt_qabstractbutton_autorepeat(QAbstractButton * button);
	int bmx_qt_qabstractbutton_autorepeatdelay(QAbstractButton * button);
	int bmx_qt_qabstractbutton_autorepeatinterval(QAbstractButton * button);
	QButtonGroup * bmx_qt_qabstractbutton_group(QAbstractButton * button);
	void bmx_qt_qabstractbutton_iconsize(QAbstractButton * button, int * w, int * h);
	int bmx_qt_qabstractbutton_ischeckable(QAbstractButton * button);
	int bmx_qt_qabstractbutton_ischecked(QAbstractButton * button);
	int bmx_qt_qabstractbutton_isdown(QAbstractButton * button);
	void bmx_qt_qabstractbutton_setautoexclusive(QAbstractButton * button, int value);
	void bmx_qt_qabstractbutton_setautorepeat(QAbstractButton * button, int value);
	void bmx_qt_qabstractbutton_setautorepeatdelay(QAbstractButton * button, int value);
	void bmx_qt_qabstractbutton_setautorepeatinterval(QAbstractButton * button, int value);
	void bmx_qt_qabstractbutton_setcheckable(QAbstractButton * button, int value);
	void bmx_qt_qabstractbutton_setdown(QAbstractButton * button, int value);
	void bmx_qt_qabstractbutton_settext(QAbstractButton * button, BBString * text);
	BBString * bmx_qt_qabstractbutton_text(QAbstractButton * button);
	void bmx_qt_qabstractbutton_animateclick(QAbstractButton * button, int msec);
	void bmx_qt_qabstractbutton_click(QAbstractButton * button);
	void bmx_qt_qabstractbutton_setchecked(QAbstractButton * button, int value);
	void bmx_qt_qabstractbutton_seticonsize(QAbstractButton * button, int w, int h);
	void bmx_qt_qabstractbutton_toggle(QAbstractButton * button);
	MaxQIcon *  bmx_qt_qabstractbutton_icon(QAbstractButton * button);
	void bmx_qt_qabstractbutton_seticon(QAbstractButton * button, MaxQIcon * icon);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif
