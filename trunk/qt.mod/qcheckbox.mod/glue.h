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

#ifndef MAX_QT_QCHECKBOX
#define MAX_QT_QCHECKBOX

#include "../core.mod/glue.h"
#include <QtCore>
#include <QCheckBox>

class MaxQCheckBox;

extern "C" {

#include <blitz.h>

	void _qt_qcheckbox_QCheckBox__OnClicked(BBObject * handle, int checked);
	void _qt_qcheckbox_QCheckBox__OnPressed(BBObject * handle);
	void _qt_qcheckbox_QCheckBox__OnReleased(BBObject * handle);
	void _qt_qcheckbox_QCheckBox__OnToggled(BBObject * handle, int checked);
	void _qt_qcheckbox_QCheckBox__OnStateChanged(BBObject * handle, int state);

	QCheckBox * bmx_qt_qcheckbox_create(BBObject * handle, BBString * text, QWidget * parent);
	int bmx_qt_qcheckbox_checkstate(QCheckBox * cb);
	int bmx_qt_qcheckbox_istristate(QCheckBox * cb);
	void bmx_qt_qcheckbox_setcheckstate(QCheckBox * cb, int state);
	void bmx_qt_qcheckbox_settristate(QCheckBox * cb, int value);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQCheckBox : public QCheckBox
{

	Q_OBJECT

public:
	MaxQCheckBox(BBObject * handle, const QString & text, QWidget * parent);
	~MaxQCheckBox();

private:
	BBObject * maxHandle;

private slots:
	void onClicked(bool checked);
	void onPressed();
	void onReleased();
	void onToggled(bool checked);
	void onStateChanged(int state);
};

#endif
