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

#ifndef MAX_QT_QDIALOGBUTTONBOX
#define MAX_QT_QDIALOGBUTTONBOX

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QDialogButtonBox>

class MaxQDialogButtonBox;

extern "C" {

#include <blitz.h>

	QDialogButtonBox * bmx_qt_qdialogbuttonbox_create(BBObject * handle, int orientation, QWidget * parent);
	void bmx_qt_qdialogbuttonbox_addbutton(QDialogButtonBox * bb, QAbstractButton * button, int role);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQDialogButtonBox : public QDialogButtonBox
{
	Q_OBJECT

public:
	MaxQDialogButtonBox(BBObject * handle, Qt::Orientation orientation, QWidget * parent);
	~MaxQDialogButtonBox();

private:
	BBObject * maxHandle;

private slots:
	void onAccepted();
	void onClicked(QAbstractButton * button);
	void onHelpRequested();
	void onRejected();
	void onCustomContextMenuRequested(const QPoint & pos);

protected:
	void timerEvent(QTimerEvent * event);
};

#endif
