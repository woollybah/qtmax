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

#ifndef MAX_QT_QLISTVIEW
#define MAX_QT_QLISTVIEW

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include "../qabstractscrollarea.mod/glue.h"
#include "../qabstractitemview.mod/glue.h"
#include <QtCore>
#include <QListView>

class MaxQListView;

extern "C" {

#include <blitz.h>


	// QListView
	// QAbstractItemView
	// QAbstractScrollArea
	void bmx_qt_qlistview_default_scrollcontentsby(MaxQListView * view, int dx, int dy);
	int bmx_qt_qlistview_default_viewportevent(MaxQListView * view, QEvent * event);
	// QFrame
	// QWidget
	void bmx_qt_qlistview_default_actionevent(MaxQListView * view, QActionEvent * event);
	void bmx_qt_qlistview_default_changeevent(MaxQListView * view, QEvent * event);
	void bmx_qt_qlistview_default_closeevent(MaxQListView * view, QCloseEvent * event);
	void bmx_qt_qlistview_default_contextmenuevent(MaxQListView * view, QContextMenuEvent * event);
	void bmx_qt_qlistview_default_dragenterevent(MaxQListView * view, QDragEnterEvent * event);
	void bmx_qt_qlistview_default_dragleaveevent(MaxQListView * view, QDragLeaveEvent * event);
	void bmx_qt_qlistview_default_dragmoveevent(MaxQListView * view, QDragMoveEvent * event);
	void bmx_qt_qlistview_default_dropevent(MaxQListView * view, QDropEvent * event);
	void bmx_qt_qlistview_default_enterevent(MaxQListView * view, QEvent * event);
	void bmx_qt_qlistview_default_focusinevent(MaxQListView * view, QFocusEvent * event);
	int bmx_qt_qlistview_default_focusnextprevchild(MaxQListView * view, int next);
	int bmx_qt_qlistview_default_focusnextchild(MaxQListView * view);
	void bmx_qt_qlistview_default_focusoutevent(MaxQListView * view, QFocusEvent * event);
	int bmx_qt_qlistview_default_focuspreviouschild(MaxQListView * view);
	void bmx_qt_qlistview_default_hideevent(MaxQListView * view, QHideEvent * event);
	void bmx_qt_qlistview_default_inputmethodevent(MaxQListView * view, QInputMethodEvent * event);
	void bmx_qt_qlistview_default_keypressevent(MaxQListView * view, QKeyEvent * event);
	void bmx_qt_qlistview_default_keyreleaseevent(MaxQListView * view, QKeyEvent * event);
	void bmx_qt_qlistview_default_leaveevent(MaxQListView * view, QEvent * event);
	void bmx_qt_qlistview_default_mousedoubleclickevent(MaxQListView * view, QMouseEvent * event);
	void bmx_qt_qlistview_default_mousemoveevent(MaxQListView * view, QMouseEvent * event);
	void bmx_qt_qlistview_default_mousepressevent(MaxQListView * view, QMouseEvent * event);
	void bmx_qt_qlistview_default_mousereleaseevent(MaxQListView * view, QMouseEvent * event);
	void bmx_qt_qlistview_default_moveevent(MaxQListView * view, QMoveEvent * event);
	void bmx_qt_qlistview_default_paintevent(MaxQListView * view, QPaintEvent * event);
	void bmx_qt_qlistview_default_resizeevent(MaxQListView * view, QResizeEvent * event);
	void bmx_qt_qlistview_default_showevent(MaxQListView * view, QShowEvent * event);
	void bmx_qt_qlistview_default_tabletevent(MaxQListView * view, QTabletEvent * event);
	void bmx_qt_qlistview_default_wheelevent(MaxQListView * view, QWheelEvent * event);
	// QObject
	int bmx_qt_qlistview_default_event(MaxQListView * view, QEvent * event);
	void bmx_qt_qlistview_default_timerevent(MaxQListView * view, QTimerEvent * event);



	QListView * bmx_qt_qlistview_create(BBObject * handle, QWidget * parent);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQListView : public QListView
{
	Q_OBJECT

public:
	MaxQListView(BBObject * handle, QWidget * parent);
	~MaxQListView();

private:
	BBObject * maxHandle;

private slots:
	void onIndexesMoved(const QModelIndexList & indexes);
	void onActivated(const QModelIndex & index);
	void onClicked(const QModelIndex & index);
	void onDoubleClicked(const QModelIndex & index);
	void onEntered(const QModelIndex & index);
	void onPressed(const QModelIndex & index);
	void onViewportEntered();
	void onCustomContextMenuRequested(const QPoint & pos);

public:
	// QListView
	// QAbstractItemView
	// QAbstractScrollArea
	void defaultscrollContentsBy(int dx, int dy);
	bool defaultviewportEvent(QEvent * event);
	// QFrame
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
	// QListView
	// QAbstractItemView
	// QAbstractScrollArea
	virtual void scrollContentsBy(int dx, int dy);
	virtual bool viewportEvent(QEvent * event);
	// QFrame
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
