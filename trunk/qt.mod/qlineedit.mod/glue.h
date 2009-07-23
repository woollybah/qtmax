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

#ifndef MAX_QT_QLINEEDIT
#define MAX_QT_QLINEEDIT

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QLineEdit>

class MaxQLineEdit;

extern "C" {

#include <blitz.h>

	void _qt_qlineedit_QLineEdit__OnCursorPositionChanged(BBObject * handle, int oldPos, int newPos);
	void _qt_qlineedit_QLineEdit__OnEditingFinished(BBObject * handle);
	void _qt_qlineedit_QLineEdit__OnReturnPressed(BBObject * handle);
	void _qt_qlineedit_QLineEdit__OnSelectionChanged(BBObject * handle);
	void _qt_qlineedit_QLineEdit__OnTextChanged(BBObject * handle, BBString * text);
	void _qt_qlineedit_QLineEdit__OnTextEdited(BBObject * handle, BBString * text);

	QLineEdit * bmx_qt_qlineedit_create(BBObject * handle, QWidget * parent);
	void bmx_qt_qlineedit_setreadonly(QLineEdit * edit, int value);

	void bmx_qt_qlineedit_clear(QLineEdit * edit);
	void bmx_qt_qlineedit_copy(QLineEdit * edit);
	void bmx_qt_qlineedit_cut(QLineEdit * edit);
	void bmx_qt_qlineedit_paste(QLineEdit * edit);
	void bmx_qt_qlineedit_redo(QLineEdit * edit);
	void bmx_qt_qlineedit_selectall(QLineEdit * edit);
	void bmx_qt_qlineedit_settext(QLineEdit * edit, BBString * text);
	void bmx_qt_qlineedit_undo(QLineEdit * edit);

	BBString * bmx_qt_qlineedit_text(QLineEdit * edit);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQLineEdit : public QLineEdit
{
	Q_OBJECT

public:
	MaxQLineEdit(BBObject * handle, QWidget * parent);
	~MaxQLineEdit();

private:
	BBObject * maxHandle;

private slots:
	void onCursorPositionChanged(int oldPos, int newPos);
	void onEditingFinished();
	void onReturnPressed();
	void onSelectionChanged();
	void onTextChanged(const QString & text);
	void onTextEdited(const QString & text);
	void onCustomContextMenuRequested(const QPoint & pos);
};


#endif
