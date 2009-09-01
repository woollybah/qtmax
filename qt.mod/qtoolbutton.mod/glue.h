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

#ifndef MAX_QT_QTOOLBUTTON
#define MAX_QT_QTOOLBUTTON

#include "../core.mod/glue.h"
#include "../qmenu.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QToolButton>

class MaxQToolButton;

extern "C" {

#include <blitz.h>

	QToolButton * bmx_qt_qtoolbutton_create(BBObject * handle, QWidget * parent);
	int bmx_qt_qtoolbutton_arrowtype(QToolButton * button);
	int bmx_qt_qtoolbutton_autoraise(QToolButton * button);
	QAction * bmx_qt_qtoolbutton_defaultaction(QToolButton * button);
	QMenu * bmx_qt_qtoolbutton_menu(QToolButton * button);
	int bmx_qt_qtoolbutton_popupmode(QToolButton * button);
	void bmx_qt_qtoolbutton_setarrowtype(QToolButton * button, int arrow);
	void bmx_qt_qtoolbutton_setautoraise(QToolButton * button, int enable);
	void bmx_qt_qtoolbutton_setmenu(QToolButton * button, QMenu * menu);
	void bmx_qt_qtoolbutton_setpopupmode(QToolButton * button, int mode);
	int bmx_qt_qtoolbutton_toolbuttonstyle(QToolButton * button);
	void bmx_qt_qtoolbutton_setdefaultaction(QToolButton * button, QAction * action);
	void bmx_qt_qtoolbutton_settoolbuttonstyle(QToolButton * button, int style);
	void bmx_qt_qtoolbutton_showmenu(QToolButton * button);


}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQToolButton : public QToolButton
{
public:
	MaxQToolButton(BBObject * handle, QWidget * parent);
	~MaxQToolButton();

private:
	BBObject * maxHandle;

private slots:
	void onTriggered(QAction * action);
	void onClicked(bool checked);
	void onPressed();
	void onReleased();
	void onToggled(bool checked);
	void onCustomContextMenuRequested(const QPoint & pos);

};

#endif
