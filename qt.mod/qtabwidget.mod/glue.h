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

#ifndef MAX_QT_QTABWIDGET
#define MAX_QT_QTABWIDGET

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QTabWidget>

class MaxQTabWidget;

extern "C" {

#include <blitz.h>

	void _qt_qtabwidget_QTabWidget__OnCurrentChanged(BBObject * maxHandle, int index);
	void _qt_qtabwidget_QTabWidget__OnTabCloseRequested(BBObject * maxHandle, int index);
	
	void _qt_qtabwidget_QTabWidget__tabInserted(BBObject * maxHandle, int index);
	void _qt_qtabwidget_QTabWidget__tabRemoved(BBObject * maxHandle, int index);

	
	// QTabWidget
	void bmx_qt_qtabwidget_default_tabinserted(MaxQTabWidget * tab, int index);
	void bmx_qt_qtabwidget_default_tabremoved(MaxQTabWidget * tab, int index);
	// QWidget
	void bmx_qt_qtabwidget_default_actionevent(MaxQTabWidget * tab, QActionEvent * event);
	void bmx_qt_qtabwidget_default_changeevent(MaxQTabWidget * tab, QEvent * event);
	void bmx_qt_qtabwidget_default_closeevent(MaxQTabWidget * tab, QCloseEvent * event);
	void bmx_qt_qtabwidget_default_contextmenuevent(MaxQTabWidget * tab, QContextMenuEvent * event);
	void bmx_qt_qtabwidget_default_dragenterevent(MaxQTabWidget * tab, QDragEnterEvent * event);
	void bmx_qt_qtabwidget_default_dragleaveevent(MaxQTabWidget * tab, QDragLeaveEvent * event);
	void bmx_qt_qtabwidget_default_dragmoveevent(MaxQTabWidget * tab, QDragMoveEvent * event);
	void bmx_qt_qtabwidget_default_dropevent(MaxQTabWidget * tab, QDropEvent * event);
	void bmx_qt_qtabwidget_default_enterevent(MaxQTabWidget * tab, QEvent * event);
	void bmx_qt_qtabwidget_default_focusinevent(MaxQTabWidget * tab, QFocusEvent * event);
	int bmx_qt_qtabwidget_default_focusnextprevchild(MaxQTabWidget * tab, int next);
	int bmx_qt_qtabwidget_default_focusnextchild(MaxQTabWidget * tab);
	void bmx_qt_qtabwidget_default_focusoutevent(MaxQTabWidget * tab, QFocusEvent * event);
	int bmx_qt_qtabwidget_default_focuspreviouschild(MaxQTabWidget * tab);
	void bmx_qt_qtabwidget_default_hideevent(MaxQTabWidget * tab, QHideEvent * event);
	void bmx_qt_qtabwidget_default_inputmethodevent(MaxQTabWidget * tab, QInputMethodEvent * event);
	void bmx_qt_qtabwidget_default_keypressevent(MaxQTabWidget * tab, QKeyEvent * event);
	void bmx_qt_qtabwidget_default_keyreleaseevent(MaxQTabWidget * tab, QKeyEvent * event);
	void bmx_qt_qtabwidget_default_leaveevent(MaxQTabWidget * tab, QEvent * event);
	void bmx_qt_qtabwidget_default_mousedoubleclickevent(MaxQTabWidget * tab, QMouseEvent * event);
	void bmx_qt_qtabwidget_default_mousemoveevent(MaxQTabWidget * tab, QMouseEvent * event);
	void bmx_qt_qtabwidget_default_mousepressevent(MaxQTabWidget * tab, QMouseEvent * event);
	void bmx_qt_qtabwidget_default_mousereleaseevent(MaxQTabWidget * tab, QMouseEvent * event);
	void bmx_qt_qtabwidget_default_moveevent(MaxQTabWidget * tab, QMoveEvent * event);
	void bmx_qt_qtabwidget_default_paintevent(MaxQTabWidget * tab, QPaintEvent * event);
	void bmx_qt_qtabwidget_default_resizeevent(MaxQTabWidget * tab, QResizeEvent * event);
	void bmx_qt_qtabwidget_default_showevent(MaxQTabWidget * tab, QShowEvent * event);
	void bmx_qt_qtabwidget_default_tabletevent(MaxQTabWidget * tab, QTabletEvent * event);
	void bmx_qt_qtabwidget_default_wheelevent(MaxQTabWidget * tab, QWheelEvent * event);
	// QObject
	int bmx_qt_qtabwidget_default_event(MaxQTabWidget * tab, QEvent * event);
	void bmx_qt_qtabwidget_default_timerevent(MaxQTabWidget * tab, QTimerEvent * event);


	QTabWidget * bmx_qt_qtabwidget_create(BBObject * handle, QWidget * parent);
	int bmx_qt_qtabwidget_addtab(QTabWidget * tab, QWidget * page, BBString * label, MaxQIcon * icon);
	void bmx_qt_qtabwidget_clear(QTabWidget * tab);
	int bmx_qt_qtabwidget_count(QTabWidget * tab);
	int bmx_qt_qtabwidget_currentindex(QTabWidget * tab);
	int bmx_qt_qtabwidget_documentmode(QTabWidget * tab);
	int bmx_qt_qtabwidget_elidemode(QTabWidget * tab);
	void bmx_qt_qtabwidget_iconsize(QTabWidget * tab, int * width, int * height);
	int bmx_qt_qtabwidget_indexof(QTabWidget * tab, QWidget * w);
	int bmx_qt_qtabwidget_inserttab(QTabWidget * tab, int index, QWidget * page, BBString * label, MaxQIcon * icon);
	int bmx_qt_qtabwidget_ismovable(QTabWidget * tab);
	int bmx_qt_qtabwidget_istabenabled(QTabWidget * tab, int index);
	void bmx_qt_qtabwidget_removetab(QTabWidget * tab, int index);
	void bmx_qt_qtabwidget_setcornerwidget(QTabWidget * tab, QWidget * widget, int corner);
	void bmx_qt_qtabwidget_setdocumentmode(QTabWidget * tab, int set);
	void bmx_qt_qtabwidget_setelidemode(QTabWidget * tab, int mode);
	void bmx_qt_qtabwidget_seticonsize(QTabWidget * tab, int width, int height);
	void bmx_qt_qtabwidget_setmovable(QTabWidget * tab, int movable);
	void bmx_qt_qtabwidget_settabenabled(QTabWidget * tab, int index, int enable);
	void bmx_qt_qtabwidget_settabicon(QTabWidget * tab, int index, MaxQIcon * icon);
	void bmx_qt_qtabwidget_settabposition(QTabWidget * tab, int pos);
	void bmx_qt_qtabwidget_settabshape(QTabWidget * tab, int shape);
	void bmx_qt_qtabwidget_settabtext(QTabWidget * tab, int index, BBString * label);
	void bmx_qt_qtabwidget_settabtooltip(QTabWidget * tab, int index, BBString * tip);
	void bmx_qt_qtabwidget_settabwhatsthis(QTabWidget * tab, int index, BBString * text);
	void bmx_qt_qtabwidget_settabsclosable(QTabWidget * tab, int closeable);
	void bmx_qt_qtabwidget_setusesscrollbuttons(QTabWidget * tab, int useButtons);
	MaxQIcon * bmx_qt_qtabwidget_tabicon(QTabWidget * tab, int index);
	int bmx_qt_qtabwidget_tabposition(QTabWidget * tab);
	int bmx_qt_qtabwidget_tabshape(QTabWidget * tab);
	BBString * bmx_qt_qtabwidget_tabtext(QTabWidget * tab, int index);
	BBString * bmx_qt_qtabwidget_tabtooltip(QTabWidget * tab, int index);
	BBString * bmx_qt_qtabwidget_tabwhatsthis(QTabWidget * tab, int index);
	int bmx_qt_qtabwidget_tabsclosable(QTabWidget * tab);
	int bmx_qt_qtabwidget_usesscrollbuttons(QTabWidget * tab);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQTabWidget : public QTabWidget
{
	Q_OBJECT
	
public:
	MaxQTabWidget(BBObject * handle, QWidget * parent);
	~MaxQTabWidget();

private:
	BBObject * maxHandle;

private slots:
	void onCurrentChanged(int index);
	void onTabCloseRequested(int index);
	void onCustomContextMenuRequested(const QPoint & pos);
	
public:
	// QTabWidget
	void defaulttabInserted(int index);
	void defaulttabRemoved(int index);
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
	// QTabWidget
	virtual void tabInserted(int index);
	virtual void tabRemoved(int index);
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
