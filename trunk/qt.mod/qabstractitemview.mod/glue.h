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

#ifndef MAX_QT_QABSTRACTITEMVIEW
#define MAX_QT_QABSTRACTITEMVIEW

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include "../qabstractscrollarea.mod/glue.h"
#include "../qabstractitemmodel.mod/glue.h"
#include <QtCore>
#include <QAbstractItemView>


class MaxQAbstractItemView;

extern "C" {

#include <blitz.h>

	void _qt_qabstractitemview_QAbstractItemView__OnActivated(BBObject * handle, MaxQModelIndex * index);
	void _qt_qabstractitemview_QAbstractItemView__OnClicked(BBObject * handle, MaxQModelIndex * index);
	void _qt_qabstractitemview_QAbstractItemView__OnDoubleClicked(BBObject * handle, MaxQModelIndex * index);
	void _qt_qabstractitemview_QAbstractItemView__OnEntered(BBObject * handle, MaxQModelIndex * index);
	void _qt_qabstractitemview_QAbstractItemView__OnPressed(BBObject * handle, MaxQModelIndex * index);
	void _qt_qabstractitemview_QAbstractItemView__OnViewportEntered(BBObject * handle);


	// QAbstractItemView
	// QAbstractScrollArea
	void bmx_qt_qabstractitemview_default_scrollcontentsby(MaxQAbstractItemView * view, int dx, int dy);
	int bmx_qt_qabstractitemview_default_viewportevent(MaxQAbstractItemView * view, QEvent * event);
	// QFrame
	// QWidget
	void bmx_qt_qabstractitemview_default_actionevent(MaxQAbstractItemView * view, QActionEvent * event);
	void bmx_qt_qabstractitemview_default_changeevent(MaxQAbstractItemView * view, QEvent * event);
	void bmx_qt_qabstractitemview_default_closeevent(MaxQAbstractItemView * view, QCloseEvent * event);
	void bmx_qt_qabstractitemview_default_contextmenuevent(MaxQAbstractItemView * view, QContextMenuEvent * event);
	void bmx_qt_qabstractitemview_default_dragenterevent(MaxQAbstractItemView * view, QDragEnterEvent * event);
	void bmx_qt_qabstractitemview_default_dragleaveevent(MaxQAbstractItemView * view, QDragLeaveEvent * event);
	void bmx_qt_qabstractitemview_default_dragmoveevent(MaxQAbstractItemView * view, QDragMoveEvent * event);
	void bmx_qt_qabstractitemview_default_dropevent(MaxQAbstractItemView * view, QDropEvent * event);
	void bmx_qt_qabstractitemview_default_enterevent(MaxQAbstractItemView * view, QEvent * event);
	void bmx_qt_qabstractitemview_default_focusinevent(MaxQAbstractItemView * view, QFocusEvent * event);
	int bmx_qt_qabstractitemview_default_focusnextprevchild(MaxQAbstractItemView * view, int next);
	int bmx_qt_qabstractitemview_default_focusnextchild(MaxQAbstractItemView * view);
	void bmx_qt_qabstractitemview_default_focusoutevent(MaxQAbstractItemView * view, QFocusEvent * event);
	int bmx_qt_qabstractitemview_default_focuspreviouschild(MaxQAbstractItemView * view);
	void bmx_qt_qabstractitemview_default_hideevent(MaxQAbstractItemView * view, QHideEvent * event);
	void bmx_qt_qabstractitemview_default_inputmethodevent(MaxQAbstractItemView * view, QInputMethodEvent * event);
	void bmx_qt_qabstractitemview_default_keypressevent(MaxQAbstractItemView * view, QKeyEvent * event);
	void bmx_qt_qabstractitemview_default_keyreleaseevent(MaxQAbstractItemView * view, QKeyEvent * event);
	void bmx_qt_qabstractitemview_default_leaveevent(MaxQAbstractItemView * view, QEvent * event);
	void bmx_qt_qabstractitemview_default_mousedoubleclickevent(MaxQAbstractItemView * view, QMouseEvent * event);
	void bmx_qt_qabstractitemview_default_mousemoveevent(MaxQAbstractItemView * view, QMouseEvent * event);
	void bmx_qt_qabstractitemview_default_mousepressevent(MaxQAbstractItemView * view, QMouseEvent * event);
	void bmx_qt_qabstractitemview_default_mousereleaseevent(MaxQAbstractItemView * view, QMouseEvent * event);
	void bmx_qt_qabstractitemview_default_moveevent(MaxQAbstractItemView * view, QMoveEvent * event);
	void bmx_qt_qabstractitemview_default_paintevent(MaxQAbstractItemView * view, QPaintEvent * event);
	void bmx_qt_qabstractitemview_default_resizeevent(MaxQAbstractItemView * view, QResizeEvent * event);
	void bmx_qt_qabstractitemview_default_showevent(MaxQAbstractItemView * view, QShowEvent * event);
	void bmx_qt_qabstractitemview_default_tabletevent(MaxQAbstractItemView * view, QTabletEvent * event);
	void bmx_qt_qabstractitemview_default_wheelevent(MaxQAbstractItemView * view, QWheelEvent * event);
	// QObject
	int bmx_qt_qabstractitemview_default_event(MaxQAbstractItemView * view, QEvent * event);
	void bmx_qt_qabstractitemview_default_timerevent(MaxQAbstractItemView * view, QTimerEvent * event);



	void bmx_qt_qabstractitemview_setmodel(QAbstractItemView * view, QAbstractItemModel * model);
	void bmx_qt_qabstractitemview_clearselection(QAbstractItemView * view);
	void bmx_qt_qabstractitemview_scrollto(QAbstractItemView * view, MaxQModelIndex * index, int hint);
	void bmx_qt_qabstractitemview_scrolltobottom(QAbstractItemView * view);
	void bmx_qt_qabstractitemview_scrolltotop(QAbstractItemView * view);
	void bmx_qt_qabstractitemview_selectall(QAbstractItemView * view);
	void bmx_qt_qabstractitemview_setcurrentindex(QAbstractItemView * view, MaxQModelIndex * index);
	void bmx_qt_qabstractitemview_update(QAbstractItemView * view, MaxQModelIndex * index);
	void bmx_qt_qabstractitemview_setselectionmodel(QAbstractItemView * view, QItemSelectionModel * model);
	void bmx_qt_qabstractitemview_setselectionmode(QAbstractItemView * view, int mode);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQAbstractItemView : public QAbstractItemView
{
	Q_OBJECT

public:
	MaxQAbstractItemView(BBObject * handle, QWidget * parent);
	~MaxQAbstractItemView();

private:
	BBObject * maxHandle;
	
private slots:
	void onActivated(const QModelIndex & index);
	void onClicked(const QModelIndex & index);
	void onDoubleClicked(const QModelIndex & index);
	void onEntered(const QModelIndex & index);
	void onPressed(const QModelIndex & index);
	void onViewportEntered();
	void onCustomContextMenuRequested(const QPoint & pos);

public:
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
