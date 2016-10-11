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

#ifndef MAX_QT_QMAINWINDOW
#define MAX_QT_QMAINWINDOW

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include "../qtoolbar.mod/glue.h"
#include <QtCore>
#include <QMainWindow>

class MaxQMainWindow;

extern "C" {

#include <blitz.h>

	void _qt_qmainwindow_QMainWindow__OnIconSizeChanged(BBObject * handle, int width, int height);
	void _qt_qmainwindow_QMainWindow__OnToolButtonStyleChanged(BBObject * handle, int style);

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


	// QMainWindow
	// QWidget
	void bmx_qt_qmainwindow_default_actionevent(MaxQMainWindow * window, QActionEvent * event);
	void bmx_qt_qmainwindow_default_changeevent(MaxQMainWindow * window, QEvent * event);
	void bmx_qt_qmainwindow_default_closeevent(MaxQMainWindow * window, QCloseEvent * event);
	void bmx_qt_qmainwindow_default_contextmenuevent(MaxQMainWindow * window, QContextMenuEvent * event);
	void bmx_qt_qmainwindow_default_dragenterevent(MaxQMainWindow * window, QDragEnterEvent * event);
	void bmx_qt_qmainwindow_default_dragleaveevent(MaxQMainWindow * window, QDragLeaveEvent * event);
	void bmx_qt_qmainwindow_default_dragmoveevent(MaxQMainWindow * window, QDragMoveEvent * event);
	void bmx_qt_qmainwindow_default_dropevent(MaxQMainWindow * window, QDropEvent * event);
	void bmx_qt_qmainwindow_default_enterevent(MaxQMainWindow * window, QEvent * event);
	void bmx_qt_qmainwindow_default_focusinevent(MaxQMainWindow * window, QFocusEvent * event);
	int bmx_qt_qmainwindow_default_focusnextprevchild(MaxQMainWindow * window, int next);
	int bmx_qt_qmainwindow_default_focusnextchild(MaxQMainWindow * window);
	void bmx_qt_qmainwindow_default_focusoutevent(MaxQMainWindow * window, QFocusEvent * event);
	int bmx_qt_qmainwindow_default_focuspreviouschild(MaxQMainWindow * window);
	void bmx_qt_qmainwindow_default_hideevent(MaxQMainWindow * window, QHideEvent * event);
	void bmx_qt_qmainwindow_default_inputmethodevent(MaxQMainWindow * window, QInputMethodEvent * event);
	void bmx_qt_qmainwindow_default_keypressevent(MaxQMainWindow * window, QKeyEvent * event);
	void bmx_qt_qmainwindow_default_keyreleaseevent(MaxQMainWindow * window, QKeyEvent * event);
	void bmx_qt_qmainwindow_default_leaveevent(MaxQMainWindow * window, QEvent * event);
	void bmx_qt_qmainwindow_default_mousedoubleclickevent(MaxQMainWindow * window, QMouseEvent * event);
	void bmx_qt_qmainwindow_default_mousemoveevent(MaxQMainWindow * window, QMouseEvent * event);
	void bmx_qt_qmainwindow_default_mousepressevent(MaxQMainWindow * window, QMouseEvent * event);
	void bmx_qt_qmainwindow_default_mousereleaseevent(MaxQMainWindow * window, QMouseEvent * event);
	void bmx_qt_qmainwindow_default_moveevent(MaxQMainWindow * window, QMoveEvent * event);
	void bmx_qt_qmainwindow_default_paintevent(MaxQMainWindow * window, QPaintEvent * event);
	void bmx_qt_qmainwindow_default_resizeevent(MaxQMainWindow * window, QResizeEvent * event);
	void bmx_qt_qmainwindow_default_showevent(MaxQMainWindow * window, QShowEvent * event);
	void bmx_qt_qmainwindow_default_tabletevent(MaxQMainWindow * window, QTabletEvent * event);
	void bmx_qt_qmainwindow_default_wheelevent(MaxQMainWindow * window, QWheelEvent * event);
	// QObject
	int bmx_qt_qmainwindow_default_event(MaxQMainWindow * window, QEvent * event);
	void bmx_qt_qmainwindow_default_timerevent(MaxQMainWindow * window, QTimerEvent * event);
	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQMainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	MaxQMainWindow(BBObject * handle, QWidget * parent, Qt::WindowFlags flags);
	~MaxQMainWindow();

private:
	BBObject * maxHandle;
	
private slots:
	void onIconSizeChanged(const QSize & iconSize);
	void onToolButtonStyleChanged(Qt::ToolButtonStyle toolButtonStyle);
	void onCustomContextMenuRequested(const QPoint & pos);

public:
	// QMainWindow
	// QWidget
	void defaultactionEvent(QActionEvent * event);
	void defaultchangeEvent(QEvent * event);
	void defaultcloseEvent(QCloseEvent * event);
	void defaultcontextMenuEvent(QContextMenuEvent * event);
	void defaultdragEnterEvent(QDragEnterEvent * event);
	void defaultdragLeaveEvent(QDragLeaveEvent * event);
	void defaultdragMoveEvent(QDragMoveEvent * event);
	void defaultdropEvent(QDropEvent * event);
	void defaultenterEvent(QEvent * event);
	void defaultfocusInEvent(QFocusEvent * event);
	bool defaultfocusNextChild ();
	bool defaultfocusNextPrevChild(bool next);
	void defaultfocusOutEvent(QFocusEvent * event);
	bool defaultfocusPreviousChild();
	void defaulthideEvent(QHideEvent * event);
	void defaultinputMethodEvent(QInputMethodEvent * event);
	void defaultkeyPressEvent(QKeyEvent * event);
	void defaultkeyReleaseEvent(QKeyEvent * event);
	void defaultleaveEvent(QEvent * event);
	void defaultmouseDoubleClickEvent(QMouseEvent * event);
	void defaultmouseMoveEvent(QMouseEvent * event);
	void defaultmousePressEvent(QMouseEvent * event);
	void defaultmouseReleaseEvent(QMouseEvent * event);
	void defaultmoveEvent(QMoveEvent * event);
	void defaultpaintEvent(QPaintEvent * event);
	void defaultresizeEvent(QResizeEvent * event);
	void defaultshowEvent(QShowEvent * event);
	void defaulttabletEvent(QTabletEvent * event);
	void defaultwheelEvent(QWheelEvent * event);
	// QObject
	bool defaultevent(QEvent * event);
	void defaulttimerEvent(QTimerEvent * event);

protected:
	// QMainWindow
	// QWidget
	virtual void actionEvent(QActionEvent * event);
	virtual void changeEvent(QEvent * event);
	virtual void closeEvent(QCloseEvent * event);
	virtual void contextMenuEvent(QContextMenuEvent * event);
	virtual void dragEnterEvent(QDragEnterEvent * event);
	virtual void dragLeaveEvent(QDragLeaveEvent * event);
	virtual void dragMoveEvent(QDragMoveEvent * event);
	virtual void dropEvent(QDropEvent * event);
	virtual void enterEvent(QEvent * event);
	virtual void focusInEvent(QFocusEvent * event);
	bool focusNextChild();
	virtual bool focusNextPrevChild(bool next);
	virtual void focusOutEvent(QFocusEvent * event);
	bool focusPreviousChild();
	virtual void hideEvent(QHideEvent * event);
	virtual void inputMethodEvent(QInputMethodEvent * event);
	virtual void leaveEvent(QEvent * event);
	virtual void keyPressEvent(QKeyEvent * event);
	virtual void keyReleaseEvent(QKeyEvent * event);
	virtual void mouseDoubleClickEvent(QMouseEvent * event);
	virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void mousePressEvent(QMouseEvent * event);
	virtual void mouseReleaseEvent(QMouseEvent * event);
	virtual void moveEvent(QMoveEvent * event);
	virtual void paintEvent(QPaintEvent * event);
	virtual void resizeEvent(QResizeEvent * event);
	virtual void showEvent(QShowEvent * event);
	virtual void tabletEvent(QTabletEvent * event);
	virtual void wheelEvent(QWheelEvent * event);
	// QObject
	virtual bool event(QEvent * event);
	virtual void timerEvent(QTimerEvent * event);
};

#endif

