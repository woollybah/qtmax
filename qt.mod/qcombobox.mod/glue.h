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

#ifndef MAX_QT_QCOMBOBOX
#define MAX_QT_QCOMBOBOX

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QComboBox>

class MaxQComboBox;

extern "C" {

#include <blitz.h>

	void _qt_qcombobox_QComboBox__OnActivated(BBObject * handle, int index);
	void _qt_qcombobox_QComboBox__OnCurrentIndexChanged(BBObject * handle, int index);
	void _qt_qcombobox_QComboBox__OnEditTextChanged(BBObject * handle, BBString * text);
	void _qt_qcombobox_QComboBox__OnHighlighted(BBObject * handle, int index);

	QComboBox * bmx_qt_qcombobox_create(BBObject * handle, QWidget * parent);
	void bmx_qt_qcombobox_addItem(QComboBox * cb, BBString * text, BBInt64 itemId);
	void bmx_qt_qcombobox_addItems(QComboBox * cb, BBArray * texts);
	int bmx_qt_qcombobox_count(QComboBox * cb);
	int bmx_qt_qcombobox_currentindex(QComboBox * cb);
	void bmx_qt_qcombobox_insertitem(QComboBox * cb, int index, BBString * text, BBInt64 itemId);
	void bmx_qt_qcombobox_itemdata(QComboBox * cb, int index, BBInt64 * id);
	void bmx_qt_qcombobox_removeitem(QComboBox * cb, int index);
	void bmx_qt_qcombobox_setitemdata(QComboBox * cb, int index, BBInt64 id);
	BBString * bmx_qt_qcombobox_currenttext(QComboBox * cb);
	int bmx_qt_qcombobox_findtext(QComboBox * cb, BBString * text, int flags);
	void bmx_qt_qcombobox_setcurrentindex(QComboBox * cb, int index);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQComboBox : public QComboBox
{
	Q_OBJECT

public:
	MaxQComboBox(BBObject * handle, QWidget * parent);
	~MaxQComboBox();

private:
	BBObject * maxHandle;

private slots:
	void onActivated(int index);
	void onCurrentIndexChanged(int index);
	void onEditTextChanged(const QString & text);
	void onHighlighted(int index);
	
	void customContextMenuRequested(const QPoint & pos);
};

#endif
