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

#ifndef MAX_QT_QABSTRACTSCROLLAREA
#define MAX_QT_QABSTRACTSCROLLAREA

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QAbstractScrollArea>

class MaxQAbstractScrollArea;

extern "C" {

#include <blitz.h>

	void _qt_qabstractscrollarea_QAbstractScrollArea__scrollContentsBy(BBObject * handle, int dx, int dy);
	int _qt_qabstractscrollarea_QAbstractScrollArea__viewportEvent(BBObject * handle, QEvent * event);

	void bmx_qt_qabstractscrollarea_addscrollbarwidget(QAbstractScrollArea * sa, QWidget * widget, int alignment);
	QWidget * bmx_qt_qabstractscrollarea_cornerwidget(QAbstractScrollArea * sa);
	QScrollBar * bmx_qt_qabstractscrollarea_horizontalscrollbar(QAbstractScrollArea * sa);
	int bmx_qt_qabstractscrollarea_horizontalscrollbarpolicy(QAbstractScrollArea * sa);
	void bmx_qt_qabstractscrollarea_maximumviewportsize(QAbstractScrollArea * sa, int * w, int * h);
	void bmx_qt_qabstractscrollarea_setcornerwidget(QAbstractScrollArea * sa, QWidget * widget);
	void bmx_qt_qabstractscrollarea_sethorizontalscrollbar(QAbstractScrollArea * sa, QScrollBar * scrollBar);
	void bmx_qt_qabstractscrollarea_sethorizontalscrollbarpolicy(QAbstractScrollArea * sa, int policy);
	void bmx_qt_qabstractscrollarea_setverticalscrollbar(QAbstractScrollArea * sa, QScrollBar * scrollBar);
	void bmx_qt_qabstractscrollarea_setverticalscrollbarpolicy(QAbstractScrollArea * sa, int policy);
	void bmx_qt_qabstractscrollarea_setviewport(QAbstractScrollArea * sa, QWidget * widget);
	QScrollBar * bmx_qt_qabstractscrollarea_verticalscrollbar(QAbstractScrollArea * sa);
	int bmx_qt_qabstractscrollarea_verticalscrollbarpolicy(QAbstractScrollArea * sa);
	QWidget * bmx_qt_qabstractscrollarea_viewport(QAbstractScrollArea * sa);

	// QAbstractScrollArea
	void bmx_qt_qabstractscrollarea_default_scrollcontentsby(MaxQAbstractScrollArea * area, int dx, int dy);
	int bmx_qt_qabstractscrollarea_default_viewportevent(MaxQAbstractScrollArea * area, QEvent * event);
	// QFrame
	// QWidget
	void bmx_qt_qabstractscrollarea_default_actionevent(MaxQAbstractScrollArea * area, QActionEvent * event);
	void bmx_qt_qabstractscrollarea_default_changeevent(MaxQAbstractScrollArea * area, QEvent * event);
	void bmx_qt_qabstractscrollarea_default_closeevent(MaxQAbstractScrollArea * area, QCloseEvent * event);
	void bmx_qt_qabstractscrollarea_default_contextmenuevent(MaxQAbstractScrollArea * area, QContextMenuEvent * event);
	void bmx_qt_qabstractscrollarea_default_dragenterevent(MaxQAbstractScrollArea * area, QDragEnterEvent * event);
	void bmx_qt_qabstractscrollarea_default_dragleaveevent(MaxQAbstractScrollArea * area, QDragLeaveEvent * event);
	void bmx_qt_qabstractscrollarea_default_dragmoveevent(MaxQAbstractScrollArea * area, QDragMoveEvent * event);
	void bmx_qt_qabstractscrollarea_default_dropevent(MaxQAbstractScrollArea * area, QDropEvent * event);
	void bmx_qt_qabstractscrollarea_default_enterevent(MaxQAbstractScrollArea * area, QEvent * event);
	void bmx_qt_qabstractscrollarea_default_focusinevent(MaxQAbstractScrollArea * area, QFocusEvent * event);
	int bmx_qt_qabstractscrollarea_default_focusnextprevchild(MaxQAbstractScrollArea * area, int next);
	int bmx_qt_qabstractscrollarea_default_focusnextchild(MaxQAbstractScrollArea * area);
	void bmx_qt_qabstractscrollarea_default_focusoutevent(MaxQAbstractScrollArea * area, QFocusEvent * event);
	int bmx_qt_qabstractscrollarea_default_focuspreviouschild(MaxQAbstractScrollArea * area);
	void bmx_qt_qabstractscrollarea_default_hideevent(MaxQAbstractScrollArea * area, QHideEvent * event);
	void bmx_qt_qabstractscrollarea_default_inputmethodevent(MaxQAbstractScrollArea * area, QInputMethodEvent * event);
	void bmx_qt_qabstractscrollarea_default_keypressevent(MaxQAbstractScrollArea * area, QKeyEvent * event);
	void bmx_qt_qabstractscrollarea_default_keyreleaseevent(MaxQAbstractScrollArea * area, QKeyEvent * event);
	void bmx_qt_qabstractscrollarea_default_leaveevent(MaxQAbstractScrollArea * area, QEvent * event);
	void bmx_qt_qabstractscrollarea_default_mousedoubleclickevent(MaxQAbstractScrollArea * area, QMouseEvent * event);
	void bmx_qt_qabstractscrollarea_default_mousemoveevent(MaxQAbstractScrollArea * area, QMouseEvent * event);
	void bmx_qt_qabstractscrollarea_default_mousepressevent(MaxQAbstractScrollArea * area, QMouseEvent * event);
	void bmx_qt_qabstractscrollarea_default_mousereleaseevent(MaxQAbstractScrollArea * area, QMouseEvent * event);
	void bmx_qt_qabstractscrollarea_default_moveevent(MaxQAbstractScrollArea * area, QMoveEvent * event);
	void bmx_qt_qabstractscrollarea_default_paintevent(MaxQAbstractScrollArea * area, QPaintEvent * event);
	void bmx_qt_qabstractscrollarea_default_resizeevent(MaxQAbstractScrollArea * area, QResizeEvent * event);
	void bmx_qt_qabstractscrollarea_default_showevent(MaxQAbstractScrollArea * area, QShowEvent * event);
	void bmx_qt_qabstractscrollarea_default_tabletevent(MaxQAbstractScrollArea * area, QTabletEvent * event);
	void bmx_qt_qabstractscrollarea_default_wheelevent(MaxQAbstractScrollArea * area, QWheelEvent * event);
	// QObject
	int bmx_qt_qabstractscrollarea_default_event(MaxQAbstractScrollArea * area, QEvent * event);
	void bmx_qt_qabstractscrollarea_default_timerevent(MaxQAbstractScrollArea * area, QTimerEvent * event);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQAbstractScrollArea : public QAbstractScrollArea
{
	Q_OBJECT

public:
	MaxQAbstractScrollArea(BBObject * handle, QWidget * parent);
	~MaxQAbstractScrollArea();

private:
	BBObject * maxHandle;

public:
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
