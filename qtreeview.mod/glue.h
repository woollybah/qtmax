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

#ifndef MAX_QT_QTREEVIEW
#define MAX_QT_QTREEVIEW

#include "../core.mod/glue.h"
#include "../qabstractitemmodel.mod/glue.h"
#include "../qobject.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include "../qabstractitemview.mod/glue.h"
#include <QtCore>
#include <QTreeView>

class MaxQTreeView;

extern "C" {

#include <blitz.h>

	void _qt_qtreeview_QTreeView__OnCollapsed(BBObject * handle, MaxQModelIndex * index);
	void _qt_qtreeview_QTreeView__OnExpanded(BBObject * handle, MaxQModelIndex * index);


	// QTreeView
	// QAbstractItemView
	// QAbstractScrollArea
	void bmx_qt_qtreeview_default_scrollcontentsby(MaxQTreeView * view, int dx, int dy);
	int bmx_qt_qtreeview_default_viewportevent(MaxQTreeView * view, QEvent * event);
	// QFrame
	// QWidget
	void bmx_qt_qtreeview_default_actionevent(MaxQTreeView * view, QActionEvent * event);
	void bmx_qt_qtreeview_default_changeevent(MaxQTreeView * view, QEvent * event);
	void bmx_qt_qtreeview_default_closeevent(MaxQTreeView * view, QCloseEvent * event);
	void bmx_qt_qtreeview_default_contextmenuevent(MaxQTreeView * view, QContextMenuEvent * event);
	void bmx_qt_qtreeview_default_dragenterevent(MaxQTreeView * view, QDragEnterEvent * event);
	void bmx_qt_qtreeview_default_dragleaveevent(MaxQTreeView * view, QDragLeaveEvent * event);
	void bmx_qt_qtreeview_default_dragmoveevent(MaxQTreeView * view, QDragMoveEvent * event);
	void bmx_qt_qtreeview_default_dropevent(MaxQTreeView * view, QDropEvent * event);
	void bmx_qt_qtreeview_default_enterevent(MaxQTreeView * view, QEvent * event);
	void bmx_qt_qtreeview_default_focusinevent(MaxQTreeView * view, QFocusEvent * event);
	int bmx_qt_qtreeview_default_focusnextprevchild(MaxQTreeView * view, int next);
	int bmx_qt_qtreeview_default_focusnextchild(MaxQTreeView * view);
	void bmx_qt_qtreeview_default_focusoutevent(MaxQTreeView * view, QFocusEvent * event);
	int bmx_qt_qtreeview_default_focuspreviouschild(MaxQTreeView * view);
	void bmx_qt_qtreeview_default_hideevent(MaxQTreeView * view, QHideEvent * event);
	void bmx_qt_qtreeview_default_inputmethodevent(MaxQTreeView * view, QInputMethodEvent * event);
	void bmx_qt_qtreeview_default_keypressevent(MaxQTreeView * view, QKeyEvent * event);
	void bmx_qt_qtreeview_default_keyreleaseevent(MaxQTreeView * view, QKeyEvent * event);
	void bmx_qt_qtreeview_default_leaveevent(MaxQTreeView * view, QEvent * event);
	void bmx_qt_qtreeview_default_mousedoubleclickevent(MaxQTreeView * view, QMouseEvent * event);
	void bmx_qt_qtreeview_default_mousemoveevent(MaxQTreeView * view, QMouseEvent * event);
	void bmx_qt_qtreeview_default_mousepressevent(MaxQTreeView * view, QMouseEvent * event);
	void bmx_qt_qtreeview_default_mousereleaseevent(MaxQTreeView * view, QMouseEvent * event);
	void bmx_qt_qtreeview_default_moveevent(MaxQTreeView * view, QMoveEvent * event);
	void bmx_qt_qtreeview_default_paintevent(MaxQTreeView * view, QPaintEvent * event);
	void bmx_qt_qtreeview_default_resizeevent(MaxQTreeView * view, QResizeEvent * event);
	void bmx_qt_qtreeview_default_showevent(MaxQTreeView * view, QShowEvent * event);
	void bmx_qt_qtreeview_default_tabletevent(MaxQTreeView * view, QTabletEvent * event);
	void bmx_qt_qtreeview_default_wheelevent(MaxQTreeView * view, QWheelEvent * event);
	// QObject
	int bmx_qt_qtreeview_default_event(MaxQTreeView * view, QEvent * event);
	void bmx_qt_qtreeview_default_timerevent(MaxQTreeView * view, QTimerEvent * event);



	QTreeView * bmx_qt_qtreeview_create(BBObject * handle, QWidget * parent);
	int bmx_qt_qtreeview_allcolumnsshowfocus(QTreeView * tv);
	int bmx_qt_qtreeview_autoexpanddelay(QTreeView * tv);
	int bmx_qt_qtreeview_columnat(QTreeView * tv, int x);
	int bmx_qt_qtreeview_columnviewportposition(QTreeView * tv, int column);
	int bmx_qt_qtreeview_columnwidth(QTreeView * tv, int column);
	int bmx_qt_qtreeview_expandsondoubleclick(QTreeView * tv);
	QHeaderView * bmx_qt_qtreeview_header(QTreeView * tv);
	int bmx_qt_qtreeview_indentation(QTreeView * tv);
	MaxQModelIndex * bmx_qt_qtreeview_indexabove(QTreeView * tv, MaxQModelIndex * index);
	MaxQModelIndex * bmx_qt_qtreeview_indexbelow(QTreeView * tv, MaxQModelIndex * index);
	int bmx_qt_qtreeview_isanimated(QTreeView * tv);
	int bmx_qt_qtreeview_iscolumnhidden(QTreeView * tv, int column);
	int bmx_qt_qtreeview_isexpanded(QTreeView * tv, MaxQModelIndex * index);
	int bmx_qt_qtreeview_isfirstcolumnspanned(QTreeView * tv, int row, MaxQModelIndex * parent);
	int bmx_qt_qtreeview_isheaderhidden(QTreeView * tv);
	int bmx_qt_qtreeview_isrowhidden(QTreeView * tv, int row, MaxQModelIndex * parent);
	int bmx_qt_qtreeview_issortingenabled(QTreeView * tv);
	int bmx_qt_qtreeview_itemsexpandable(QTreeView * tv);
	int bmx_qt_qtreeview_rootisdecorated(QTreeView * tv);
	void bmx_qt_qtreeview_setallcolumnsshowfocus(QTreeView * tv, int enable);
	void bmx_qt_qtreeview_setanimated(QTreeView * tv, int enable);
	void bmx_qt_qtreeview_setautoexpanddelay(QTreeView * tv, int _delay);
	void bmx_qt_qtreeview_setcolumnhidden(QTreeView * tv, int column, int hide);
	void bmx_qt_qtreeview_setcolumnwidth(QTreeView * tv, int column, int width);
	void bmx_qt_qtreeview_setexpanded(QTreeView * tv, MaxQModelIndex * index, int expanded);
	void bmx_qt_qtreeview_setexpandsondoubleclick(QTreeView * tv, int enable);
	void bmx_qt_qtreeview_setfirstcolumnspanned(QTreeView * tv, int row, MaxQModelIndex * parent, int span);
	void bmx_qt_qtreeview_setheader(QTreeView * tv, QHeaderView * header);
	void bmx_qt_qtreeview_setheaderhidden(QTreeView * tv, int hide);
	void bmx_qt_qtreeview_setindentation(QTreeView * tv, int i);
	void bmx_qt_qtreeview_setitemsexpandable(QTreeView * tv, int enable);
	void bmx_qt_qtreeview_setrootisdecorated(QTreeView * tv, int show);
	void bmx_qt_qtreeview_setrowhidden(QTreeView * tv, int row, MaxQModelIndex * parent, int hide);
	void bmx_qt_qtreeview_setsortingenabled(QTreeView * tv, int enable);
	void bmx_qt_qtreeview_setuniformrowheights(QTreeView * tv, int uniform);
	void bmx_qt_qtreeview_setwordwrap(QTreeView * tv, int on);
	void bmx_qt_qtreeview_sortbycolumn(QTreeView * tv, int column, int order);
	int bmx_qt_qtreeview_uniformrowheights(QTreeView * tv);
	int bmx_qt_qtreeview_wordwrap(QTreeView * tv);

	void bmx_qt_qtreeview_collapse(QTreeView * tv, MaxQModelIndex * index);
	void bmx_qt_qtreeview_collapseall(QTreeView * tv);
	void bmx_qt_qtreeview_expand(QTreeView * tv, MaxQModelIndex * index);
	void bmx_qt_qtreeview_expandall(QTreeView * tv);
	void bmx_qt_qtreeview_expandtodepth(QTreeView * tv, int depth);
	void bmx_qt_qtreeview_hidecolumn(QTreeView * tv, int column);
	void bmx_qt_qtreeview_resizecolumntocontents(QTreeView * tv, int column);
	void bmx_qt_qtreeview_showcolumn(QTreeView * tv, int column);
	MaxQModelIndex * bmx_qt_qtreeview_indexat(QTreeView * tv, int x, int y);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQTreeView : public QTreeView
{
	Q_OBJECT
	
public:
	MaxQTreeView(BBObject * handle, QWidget * parent);
	~MaxQTreeView();

	virtual QModelIndex indexAt(const QPoint & point) const;

private:
	BBObject * maxHandle;

private slots:
	void onCollapsed(const QModelIndex & index);
	void onExpanded(const QModelIndex & index);
	void onActivated(const QModelIndex & index);
	void onClicked(const QModelIndex & index);
	void onDoubleClicked(const QModelIndex & index);
	void onEntered(const QModelIndex & index);
	void onPressed(const QModelIndex & index);
	void onViewportEntered();
	void onCustomContextMenuRequested(const QPoint & pos);
	
public:
	// QTreeView
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
	// QTreeView
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
