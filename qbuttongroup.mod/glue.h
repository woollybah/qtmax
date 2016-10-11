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

#ifndef MAX_QT_QBUTTONGROUP
#define MAX_QT_QBUTTONGROUP

#include "../core.mod/glue.h"
#include <QtCore>
#include <QButtonGroup>

class MaxQButtonGroup;

extern "C" {

#include <blitz.h>

	void _qt_qbuttongroup_QButtonGroup__OnButtonClicked(BBObject * handle, QAbstractButton * button);
	void _qt_qbuttongroup_QButtonGroup__OnButtonPressed(BBObject * handle, QAbstractButton * button);
	void _qt_qbuttongroup_QButtonGroup__OnButtonReleased(BBObject * handle, QAbstractButton * button);

	QButtonGroup * bmx_qt_qbuttongroup_create(BBObject * handle, QObject * parent);
	void bmx_qt_qbuttongroup_addbutton(QButtonGroup * group, QAbstractButton *button, int id);
	QAbstractButton * bmx_qt_qbuttongroup_button(QButtonGroup * group, int id);
	QAbstractButton * bmx_qt_qbuttongroup_checkedbutton(QButtonGroup * group);
	int bmx_qt_qbuttongroup_checkedid(QButtonGroup * group);
	int bmx_qt_qbuttongroup_exclusive(QButtonGroup * group);
	int bmx_qt_qbuttongroup_id(QButtonGroup * group, QAbstractButton *button);
	void bmx_qt_qbuttongroup_removebutton(QButtonGroup * group, QAbstractButton *button);
	void bmx_qt_qbuttongroup_setexclusive(QButtonGroup * group, int value);
	void bmx_qt_qbuttongroup_setid(QButtonGroup * group, QAbstractButton *button, int id);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQButtonGroup : public QButtonGroup
{
	Q_OBJECT

public:
	MaxQButtonGroup(BBObject * handle, QObject * parent);
	~MaxQButtonGroup();

private:
	BBObject * maxHandle;

private slots:
	void onButtonClicked(QAbstractButton * button);
	void onButtonPressed(QAbstractButton * button);
	void onButtonReleased(QAbstractButton * button);
};

#endif
