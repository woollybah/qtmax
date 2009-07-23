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

#ifndef MAX_QT_QTEXTEDIT
#define MAX_QT_QTEXTEDIT

#include "../core.mod/glue.h"
#include "../qcolor.mod/glue.h"
#include "../qfont.mod/glue.h"
#include <QtCore>
#include <QTextEdit>

class MaxQTextEdit;

extern "C" {

#include <blitz.h>

	QTextEdit * bmx_qt_qtextedit_create(BBObject * handle, QWidget * parent);
	void bmx_qt_qtextedit_setreadonly(QTextEdit * edit, int value);

	void bmx_qt_qtextedit_append(QTextEdit * edit, BBString * text);
	void bmx_qt_qtextedit_clear(QTextEdit * edit);
	void bmx_qt_qtextedit_copy(QTextEdit * edit);
	void bmx_qt_qtextedit_cut(QTextEdit * edit);
	void bmx_qt_qtextedit_inserthtml(QTextEdit * edit, BBString * text);
	void bmx_qt_qtextedit_insertplaintext(QTextEdit * edit, BBString * text);
	void bmx_qt_qtextedit_paste(QTextEdit * edit);
	void bmx_qt_qtextedit_redo(QTextEdit * edit);
	void bmx_qt_qtextedit_scrolltoanchor(QTextEdit * edit, BBString * name);
	void bmx_qt_qtextedit_selectall(QTextEdit * edit);
	void bmx_qt_qtextedit_setalignment(QTextEdit * edit, int a);
	void bmx_qt_qtextedit_setcurrentfont(QTextEdit * edit, MaxQFont * f);
	void bmx_qt_qtextedit_setfontfamily(QTextEdit * edit, BBString * fontFamily);
	void bmx_qt_qtextedit_setfontitalic(QTextEdit * edit, int italic);
	void bmx_qt_qtextedit_setfontpointsize(QTextEdit * edit, double s);
	void bmx_qt_qtextedit_setfontunderline(QTextEdit * edit, int underline);
	void bmx_qt_qtextedit_setfontweight(QTextEdit * edit, int weight);
	void bmx_qt_qtextedit_sethtml(QTextEdit * edit, BBString * text);
	void bmx_qt_qtextedit_setplaintext(QTextEdit * edit, BBString * text);
	void bmx_qt_qtextedit_settext(QTextEdit * edit, BBString * text);
	void bmx_qt_qtextedit_settextbackgroundcolor(QTextEdit * edit, MaxQColor * c);
	void bmx_qt_qtextedit_settextcolor(QTextEdit * edit, MaxQColor * c);
	void bmx_qt_qtextedit_undo(QTextEdit * edit);
	void bmx_qt_qtextedit_zoomin(QTextEdit * edit, int _range);
	void bmx_qt_qtextedit_zoomout(QTextEdit * edit, int _range);

	BBString * bmx_qt_qtextedit_tohtml(QTextEdit * edit);
	BBString * bmx_qt_qtextedit_toplaintext(QTextEdit * edit);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQTextEdit : public QTextEdit
{
public:
	MaxQTextEdit(BBObject * handle, QWidget * parent);
	~MaxQTextEdit();

private:
	BBObject * maxHandle;
};

#endif

