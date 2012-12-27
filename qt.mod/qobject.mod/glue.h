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

#ifndef MAX_QT_QOBJECT
#define MAX_QT_QOBJECT

#include "../core.mod/glue.h"
#include <QtCore>
#include <QObject>

extern "C" {

#include <blitz.h>

	int _qt_qobject_QObject__event(BBObject * handle, QEvent * event);
	void _qt_qobject_QObject__timerEvent(BBObject * handle, QTimerEvent * event);

	BBString * bmx_qt_qobject_tr(BBString * sourceText, BBString * disambiguation, int n);
	BBString * bmx_qt_qobject_trarg(BBString * sourceText, BBArray * args);
	void bmx_qt_qobject_setobjectname(QObject * obj, BBString * name);
	void bmx_qt_qobject_setparent(QObject * obj, QObject * parent);
	int bmx_qt_qobject_blocksignals(QObject * obj, int block);
	int bmx_qt_qobject_signalsblocked(QObject * obj);
	int bmx_qt_qobject_starttimer(QObject * obj, int interval);
	void bmx_qt_qobject_killtimer(QObject * obj, int id);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif
