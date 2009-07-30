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

#ifndef MAX_QT_QMENU
#define MAX_QT_QMENU

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QMenu>

class MaxQMenu;

extern "C" {

#include <blitz.h>

	BBObject * _qt_qmenu_QMenu___create(QMenu * menu);

	QMenu * bmx_qt_qmenu_create(BBObject * handle, QWidget * parent);

	QAction * bmx_qt_qmenu_actionat(QMenu * m, int x, int y);
	MaxQRect * bmx_qt_qmenu_actiongeometry(QMenu * m, QAction * act);
	QAction * bmx_qt_qmenu_activeaction(QMenu * m);
	void bmx_qt_qmenu_addaction(QMenu * m, QAction * action);
	QAction * bmx_qt_qmenu_addactiontxt(QMenu * m, BBString * action);
	QAction * bmx_qt_qmenu_addmenuaction(QMenu * m, QMenu * menu);
	QMenu * bmx_qt_qmenu_addmenu(QMenu * m, BBString * title);
	QAction * bmx_qt_qmenu_addseparator(QMenu * m);
	void bmx_qt_qmenu_clear(QMenu * m);
	QAction * bmx_qt_qmenu_defaultaction(QMenu * m);
	QAction * bmx_qt_qmenu_exec(QMenu * m);
	QAction * bmx_qt_qmenu_execaction(QMenu * m, int x, int y, QAction * action);
	void bmx_qt_qmenu_hidetearoffmenu(QMenu * m);
	QAction * bmx_qt_qmenu_insertmenu(QMenu * m, QAction * before, QMenu * menu);
	QAction * bmx_qt_qmenu_insertseparator(QMenu * m, QAction * before);
	int bmx_qt_qmenu_isempty(QMenu * m);
	int bmx_qt_qmenu_istearoffenabled(QMenu * m);
	int bmx_qt_qmenu_istearoffmenuvisible(QMenu * m);
	QAction * bmx_qt_qmenu_menuaction(QMenu * m);
	void bmx_qt_qmenu_popup(QMenu * m, int x, int y, QAction * atAction);
	int bmx_qt_qmenu_separatorscollapsible(QMenu * m);
	void bmx_qt_qmenu_setactiveaction(QMenu * m, QAction * act);
	void bmx_qt_qmenu_setdefaultaction(QMenu * m, QAction * act);
	//void bmx_qt_qmenu_seticon(QMenu * m, MaxQIcon * icon);
	void bmx_qt_qmenu_setseparatorscollapsible(QMenu * m, int collapse);
	void bmx_qt_qmenu_settearoffenabled(QMenu * m, int value);
	void bmx_qt_qmenu_settitle(QMenu * m, BBString * title);
	BBString * bmx_qt_qmenu_title(QMenu * m);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQMenu : public QMenu
{
	Q_OBJECT

public:
	MaxQMenu(BBObject * handle, QWidget * parent);
	MaxQMenu(BBObject * handle, const QString & text, QWidget * parent);
	MaxQMenu(const QString & text, QWidget * parent);
	~MaxQMenu();

private:
	BBObject * maxHandle;
	
private slots:
	void onAboutToHide();
	void onAboutToShow();
	void onHovered(QAction * action);
	void onTriggered(QAction * action);
	void customContextMenuRequested(const QPoint & pos);
};

#endif
