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

#ifndef MAX_QT_QFONTCOMBOBOX
#define MAX_QT_QFONTCOMBOBOX

#include "../core.mod/glue.h"
#include "../qcombobox.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QFontComboBox>

class MaxQFontComboBox;

extern "C" {

#include <blitz.h>

	void _qt_qfontcombobox_QFontComboBox__OnCurrentFontChanged(BBObject * handle, MaxQFont * font);

	QFontComboBox * bmx_qt_qfontcombobox_create(BBObject * handle, QWidget * parent);
	MaxQFont * bmx_qt_qfontcombobox_currentfont(QFontComboBox * cb);
	int bmx_qt_qfontcombobox_fontfilters(QFontComboBox * cb);
	void bmx_qt_qfontcombobox_setfontfilters(QFontComboBox * cb, int filters);
	void bmx_qt_qfontcombobox_setwritingsystem(QFontComboBox * cb, int script);
	int bmx_qt_qfontcombobox_writingsystem(QFontComboBox * cb);
	void bmx_qt_qfontcombobox_setcurrentfont(QFontComboBox * cb, MaxQFont * font);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQFontComboBox : public QFontComboBox
{
	Q_OBJECT
	
public:
	MaxQFontComboBox(BBObject * handle, QWidget * parent);
	~MaxQFontComboBox();

private:
	BBObject * maxHandle;

private slots:
	void onCurrentFontChanged(const QFont & font);
	void onActivated(int index);
	void onCurrentIndexChanged(int index);
	void onEditTextChanged(const QString & text);
	void onHighlighted(int index);
	void onCustomContextMenuRequested(const QPoint & pos);

protected:
	void timerEvent(QTimerEvent * event);
};

#endif
