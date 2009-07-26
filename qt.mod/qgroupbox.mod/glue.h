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

#ifndef MAX_QT_QGROUPBOX
#define MAX_QT_QGROUPBOX

#include "../core.mod/glue.h"
#include <QtCore>
#include <QGroupBox>

class MaxQGroupBox;

extern "C" {

#include <blitz.h>

	QGroupBox * bmx_qt_qgroupbox_create(BBObject * handle, BBString * title, QWidget * parent);
	int bmx_qt_qgroupbox_alignment(QGroupBox * gb);
	int bmx_qt_qgroupbox_ischeckable(QGroupBox * gb);
	int bmx_qt_qgroupbox_ischecked(QGroupBox * gb);
	int bmx_qt_qgroupbox_isflat(QGroupBox * gb);
	void bmx_qt_qgroupbox_setalignment(QGroupBox * gb, int alignment);
	void bmx_qt_qgroupbox_setcheckable(QGroupBox * gb, int checkable);
	void bmx_qt_qgroupbox_setflat(QGroupBox * gb, int flat);
	void bmx_qt_qgroupbox_settitle(QGroupBox * gb, BBString * title);
	BBString * bmx_qt_qgroupbox_title(QGroupBox * gb);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQGroupBox: public QGroupBox
{
	Q_OBJECT

public:
	MaxQGroupBox(BBObject * handle, const QString & title, QWidget * parent);
	~MaxQGroupBox();

private:
	BBObject * maxHandle;

private slots:
	void onClicked(bool checked);
	void onToggled(bool on);
	void onCustomContextMenuRequested(const QPoint & pos);
};

#endif
