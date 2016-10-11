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

#ifndef MAX_QT_QCOREAPPLICATION
#define MAX_QT_QCOREAPPLICATION

#include "../core.mod/glue.h"
#include "../qobject.mod/glue.h"
#include "../qeventloop.mod/glue.h"
#include <QtCore>

class MaxQCoreApplication;

extern "C" {

#include <blitz.h>
	
	void _qt_qcoreapplication_QCoreApplication__OnAboutToQuit(BBObject * handle);


	QCoreApplication * bmx_qt_qcoreapplication_create(BBObject * handle);

	void bmx_qt_qcoreapplication_addlibrarypath(BBString * path);
	BBString * bmx_qt_qcoreapplication_applicationdirpath();
	BBString * bmx_qt_qcoreapplication_applicationfilepath();
	BBString * bmx_qt_qcoreapplication_applicationname();
	void bmx_qt_qcoreapplication_applicationpid(BBInt64 * pid);
	void bmx_qt_qcoreapplication_flush();
	BBString * bmx_qt_qcoreapplication_translate(BBString * context, BBString * text, BBString * disambiguation, int encoding);

	void bmx_qt_qcoreapplication_quit(QCoreApplication * app);
	void bmx_qt_qcoreapplication_processevents(QCoreApplication * app, int flags);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQCoreApplication : public QCoreApplication
{

	Q_OBJECT
	
public:
	MaxQCoreApplication(BBObject * handle, int & argc, char ** argv);
	~MaxQCoreApplication();

private:
	BBObject * maxHandle;
	
private slots:
	void onAboutToQuit();

protected:
	void timerEvent(QTimerEvent * event);
};


#endif
