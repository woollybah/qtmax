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

#ifndef MAX_QT_QEVENTLOOP
#define MAX_QT_QEVENTLOOP

#include "../core.mod/glue.h"
#include <QtCore>
#include <QEventLoop>

class MaxQEventLoop;

extern "C" {

#include <blitz.h>

	QEventLoop * bmx_qt_qeventloop_create(BBObject * handle, QObject * parent);
	
	int bmx_qt_qeventloop_exec(QEventLoop * eventloop, int flags);
	void bmx_qt_qeventloop_exit(QEventLoop * eventloop, int returnCode);
	int bmx_qt_qeventloop_isrunning(QEventLoop * eventloop);
	int bmx_qt_qeventloop_processevents(QEventLoop * eventloop, int flags);
	void bmx_qt_qeventloop_processeventstime(QEventLoop * eventloop, int flags, int maxTime);
	void bmx_qt_qeventloop_wakeup(QEventLoop * eventloop);
	void bmx_qt_qeventloop_quit(QEventLoop * eventloop);

	QEventLoop::ProcessEventsFlags bmx_qt_qeventloop_geteventflags(int f);
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQEventLoop : public QEventLoop
{
	Q_OBJECT
	
public:
	MaxQEventLoop(BBObject * handle, QObject * parent);
	~MaxQEventLoop();

private:
	BBObject * maxHandle;

};

#endif
