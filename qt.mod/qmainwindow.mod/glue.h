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

#ifndef MAX_QT_QMAINWINDOW
#define MAX_QT_QMAINWINDOW

#include "../core.mod/glue.h"
#include "../qtoolbar.mod/glue.h"
#include <QtCore>
#include <QMainWindow>

class MaxQMainWindow;

extern "C" {

#include <blitz.h>

	QMainWindow * bmx_qt_qmainwindow_create(BBObject * handle, QWidget * parent, int flags);

	void bmx_qt_qmainwindow_adddockwidget(QMainWindow * window, int area, QDockWidget * dockwidget, int orientation);
	void bmx_qt_qmainwindow_addtoolbararea(QMainWindow * window, int area, QToolBar * toolbar);
	QToolBar * bmx_qt_qmainwindow_addtoolbar(QMainWindow * window, QToolBar * toolbar);
	QToolBar * bmx_qt_qmainwindow_addtoolbartxt(QMainWindow * window, BBString * toolbar);
	void bmx_qt_qmainwindow_addtoolbarbreak(QMainWindow * window, int area);
	QWidget * bmx_qt_qmainwindow_centralwidget(QMainWindow * window);
	int bmx_qt_qmainwindow_corner(QMainWindow * window, int c);
	QMenu * bmx_qt_qmainwindow_createpopupmenu(QMainWindow * window);
	int bmx_qt_qmainwindow_dockoptions(QMainWindow * window);
	int bmx_qt_qmainwindow_dockwidgetarea(QMainWindow * window, QDockWidget * dockwidget);
	int bmx_qt_qmainwindow_documentmode(QMainWindow * window);
	void bmx_qt_qmainwindow_iconsize(QMainWindow * window, int * w, int * h);
	void bmx_qt_qmainwindow_inserttoolbar(QMainWindow * window, QToolBar * before, QToolBar * toolbar);
	void bmx_qt_qmainwindow_inserttoolbarbreak(QMainWindow * window, QToolBar * before);
	int bmx_qt_qmainwindow_isanimated(QMainWindow * window);
	int bmx_qt_qmainwindow_isdocknestingenabled(QMainWindow * window);
	QMenuBar * bmx_qt_qmainwindow_menubar(QMainWindow * window);
	QWidget * bmx_qt_qmainwindow_menuwidget(QMainWindow * window);
	void bmx_qt_qmainwindow_removedockwidget(QMainWindow * window, QDockWidget * dockwidget);
	void bmx_qt_qmainwindow_removetoolbar(QMainWindow * window, QToolBar * toolbar);
	void bmx_qt_qmainwindow_removetoolbarbreak(QMainWindow * window, QToolBar * before);
	void bmx_qt_qmainwindow_restoredockwidget(QMainWindow * window, QDockWidget * dockwidget);
	void bmx_qt_qmainwindow_setcentralwidget(QMainWindow * window, QWidget * widget);
	void bmx_qt_qmainwindow_setcorner(QMainWindow * window, int corner, int area);
	void bmx_qt_qmainwindow_setdockoptions(QMainWindow * window, int options);
	void bmx_qt_qmainwindow_setdocumentmode(QMainWindow * window, int enabled);
	void bmx_qt_qmainwindow_seticonsize(QMainWindow * window, int w, int h);
	void bmx_qt_qmainwindow_setmenubar(QMainWindow * window, QMenuBar * menuBar);
	void bmx_qt_qmainwindow_setmenuwidget(QMainWindow * window, QWidget * widget);
	void bmx_qt_qmainwindow_setstatusbar(QMainWindow * window, QStatusBar * statusbar);
	void bmx_qt_qmainwindow_settabposition(QMainWindow * window, int areas, int tabPosition);
	void bmx_qt_qmainwindow_settabshape(QMainWindow * window, int tabShape);
	void bmx_qt_qmainwindow_settoolbuttonstyle(QMainWindow * window, int toolButtonStyle);
	void bmx_qt_qmainwindow_setunifiedtitleandtoolbaronmac(QMainWindow * window, int set);
	void bmx_qt_qmainwindow_splitdockwidget(QMainWindow * window, QDockWidget * _first, QDockWidget * _second, int orientation);
	QStatusBar * bmx_qt_qmainwindow_statusBar(QMainWindow * window);
	int bmx_qt_qmainwindow_tabposition(QMainWindow * window, int area);
	int bmx_qt_qmainwindow_tabshape(QMainWindow * window);
	void bmx_qt_qmainwindow_tabifydockwidget(QMainWindow * window, QDockWidget * _first, QDockWidget * _second);
	int bmx_qt_qmainwindow_toolbararea(QMainWindow * window, QToolBar * toolbar);
	int bmx_qt_qmainwindow_toolbarbreak(QMainWindow * window, QToolBar * toolbar);
	int bmx_qt_qmainwindow_toolbuttonstyle(QMainWindow * window);
	int bmx_qt_qmainwindow_unifiedtitleandtoolbaronmac(QMainWindow * window);
	void bmx_qt_qmainwindow_setanimated(QMainWindow * window, int enabled);
	void bmx_qt_qmainwindow_setdocknestingenabled(QMainWindow * window, int enabled);

	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQMainWindow : public QMainWindow
{
public:
	MaxQMainWindow(BBObject * handle, QWidget * parent, Qt::WindowFlags flags);
	~MaxQMainWindow();

private:
	BBObject * maxHandle;
};

#endif

