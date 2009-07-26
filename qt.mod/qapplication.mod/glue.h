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

#ifndef MAX_QT_QAPPLICATION
#define MAX_QT_QAPPLICATION

#include "../core.mod/glue.h"
#include "../qcoreapplication.mod/glue.h"
#include "../qsessionmanager.mod/glue.h"
#include <QtGui>

class MaxQApplication;

extern "C" {

#include <blitz.h>

	void _qt_qapplication_QApplication__OnCommitDataRequest(BBObject * handle, MaxQSessionManager * manager);
	void _qt_qapplication_QApplication__OnFocusChanged(BBObject * handle, QWidget* old, QWidget * now);
	void _qt_qapplication_QApplication__OnFontDatabaseChanged(BBObject * handle);
	void _qt_qapplication_QApplication__OnLastWindowClosed(BBObject * handle);
	void _qt_qapplication_QApplication__OnSaveStateRequest(BBObject * handle, MaxQSessionManager * manager);

	QApplication * bmx_qt_qapplication_create(BBObject * handle);
	int bmx_qt_qapplication_exec();

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQApplication : public QApplication
{

	Q_OBJECT

public:
	MaxQApplication(BBObject * handle, int & argc, char ** argv);
	~MaxQApplication();

private:
	BBObject * maxHandle;

private slots:
	void onCommitDataRequest(QSessionManager & manager);
	void onFocusChanged(QWidget * old, QWidget * now);
	void onFontDatabaseChanged();
	void onLastWindowClosed();
	void onSaveStateRequest(QSessionManager & manager);
	void onAboutToQuit(); // from QCoreApplication
};


#endif
