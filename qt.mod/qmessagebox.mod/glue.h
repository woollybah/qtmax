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

#ifndef MAX_QT_QMESSAGEBOX
#define MAX_QT_QMESSAGEBOX

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include "../qdialog.mod/glue.h"
#include <QtCore>
#include <QMessageBox>

extern "C" {

#include <blitz.h>

	void _qt_qmessagebox_QMessageBox__OnButtonClicked(BBObject * handle, QAbstractButton * button);

	QMessageBox * bmx_qt_qmessagebox_create(BBObject * handle, QWidget * parent);
	void bmx_qt_qmessagebox_removebutton(QMessageBox * messageBox, QAbstractButton * button);
	void bmx_qt_qmessagebox_setdefaultbutton(QMessageBox * messageBox, QPushButton * button);
	void bmx_qt_qmessagebox_setdefaultbuttontype(QMessageBox * messageBox, int button);
	void bmx_qt_qmessagebox_setdetailedtext(QMessageBox * messageBox, BBString * text);
	void bmx_qt_qmessagebox_setescapebutton(QMessageBox * messageBox, QAbstractButton * button);
	void bmx_qt_qmessagebox_setescapebuttontype(QMessageBox * messageBox, int button);
	void bmx_qt_qmessagebox_setinformativetext(QMessageBox * messageBox, BBString * text);
	void bmx_qt_qmessagebox_setstandardbuttons(QMessageBox * messageBox, int buttons);
	void bmx_qt_qmessagebox_settext(QMessageBox * messageBox, BBString * text);
	void bmx_qt_qmessagebox_settextformat(QMessageBox * messageBox, int format);
	void bmx_qt_qmessagebox_setwindowmodality(QMessageBox * messageBox, int windowModality);
	void bmx_qt_qmessagebox_setwindowtitle(QMessageBox * messageBox, BBString * text);

	void bmx_qt_qmessagebox_about(QWidget * parent, BBString * title, BBString * text);
	void bmx_qt_qmessagebox_aboutqt(QWidget * parent, BBString * title);
	int bmx_qt_qmessagebox_critical(QWidget * parent, BBString * title, BBString * text, int buttons, int defaultButton);
	int bmx_qt_qmessagebox_information(QWidget * parent, BBString * title, BBString * text, int buttons, int defaultButton);
	int bmx_qt_qmessagebox_question(QWidget * parent, BBString * title, BBString * text, int buttons, int defaultButton);
	int bmx_qt_qmessagebox_warning(QWidget * parent, BBString * title, BBString * text, int buttons, int defaultButton);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQMessageBox : public QMessageBox
{
	Q_OBJECT
	
public:
	MaxQMessageBox(BBObject * handle, QWidget * parent);
	~MaxQMessageBox();

private:
	BBObject * maxHandle;

private slots:
	void onButtonClicked(QAbstractButton * button);
	void onAccepted();
	void onFinished(int result);
	void onRejected();
	void onCustomContextMenuRequested(const QPoint & pos);

protected:
	void timerEvent(QTimerEvent * event);
};

#endif
