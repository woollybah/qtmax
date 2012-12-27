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

#ifndef MAX_QT_QFRAME
#define MAX_QT_QFRAME

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QFrame>

class MaxQFrame;

extern "C" {

#include <blitz.h>

	QFrame * bmx_qt_qframe_create(BBObject * handle, QWidget * parent, int flags);
	void bmx_qt_qframe_framerect(QFrame * frame, int * x, int * y, int * w, int * h);
	int bmx_qt_qframe_frameshadow(QFrame * frame);
	int bmx_qt_qframe_frameshape(QFrame * frame);
	int bmx_qt_qframe_framestyle(QFrame * frame);
	int bmx_qt_qframe_framewidth(QFrame * frame);
	int bmx_qt_qframe_linewidth(QFrame * frame);
	int bmx_qt_qframe_midlinewidth(QFrame * frame);
	void bmx_qt_qframe_setframerect(QFrame * frame, int x, int y, int w, int h);
	void bmx_qt_qframe_setframeshadow(QFrame * frame, int shadow);
	void bmx_qt_qframe_setframeshape(QFrame * frame, int shape);
	void bmx_qt_qframe_setframestyle(QFrame * frame, int style);
	void bmx_qt_qframe_setlinewidth(QFrame * frame, int width);
	void bmx_qt_qframe_setmidlinewidth(QFrame * frame, int width);

	// QFrame
	// QWidget
	void bmx_qt_qframe_default_actionevent(MaxQFrame * frame, QActionEvent * event);
	void bmx_qt_qframe_default_changeevent(MaxQFrame * frame, QEvent * event);
	void bmx_qt_qframe_default_closeevent(MaxQFrame * frame, QCloseEvent * event);
	void bmx_qt_qframe_default_contextmenuevent(MaxQFrame * frame, QContextMenuEvent * event);
	void bmx_qt_qframe_default_dragenterevent(MaxQFrame * frame, QDragEnterEvent * event);
	void bmx_qt_qframe_default_dragleaveevent(MaxQFrame * frame, QDragLeaveEvent * event);
	void bmx_qt_qframe_default_dragmoveevent(MaxQFrame * frame, QDragMoveEvent * event);
	void bmx_qt_qframe_default_dropevent(MaxQFrame * frame, QDropEvent * event);
	void bmx_qt_qframe_default_enterevent(MaxQFrame * frame, QEvent * event);
	void bmx_qt_qframe_default_focusinevent(MaxQFrame * frame, QFocusEvent * event);
	int bmx_qt_qframe_default_focusnextprevchild(MaxQFrame * frame, int next);
	int bmx_qt_qframe_default_focusnextchild(MaxQFrame * frame);
	void bmx_qt_qframe_default_focusoutevent(MaxQFrame * frame, QFocusEvent * event);
	int bmx_qt_qframe_default_focuspreviouschild(MaxQFrame * frame);
	void bmx_qt_qframe_default_hideevent(MaxQFrame * frame, QHideEvent * event);
	void bmx_qt_qframe_default_inputmethodevent(MaxQFrame * frame, QInputMethodEvent * event);
	void bmx_qt_qframe_default_keypressevent(MaxQFrame * frame, QKeyEvent * event);
	void bmx_qt_qframe_default_keyreleaseevent(MaxQFrame * frame, QKeyEvent * event);
	void bmx_qt_qframe_default_leaveevent(MaxQFrame * frame, QEvent * event);
	void bmx_qt_qframe_default_mousedoubleclickevent(MaxQFrame * frame, QMouseEvent * event);
	void bmx_qt_qframe_default_mousemoveevent(MaxQFrame * frame, QMouseEvent * event);
	void bmx_qt_qframe_default_mousepressevent(MaxQFrame * frame, QMouseEvent * event);
	void bmx_qt_qframe_default_mousereleaseevent(MaxQFrame * frame, QMouseEvent * event);
	void bmx_qt_qframe_default_moveevent(MaxQFrame * frame, QMoveEvent * event);
	void bmx_qt_qframe_default_paintevent(MaxQFrame * frame, QPaintEvent * event);
	void bmx_qt_qframe_default_resizeevent(MaxQFrame * frame, QResizeEvent * event);
	void bmx_qt_qframe_default_showevent(MaxQFrame * frame, QShowEvent * event);
	void bmx_qt_qframe_default_tabletevent(MaxQFrame * frame, QTabletEvent * event);
	void bmx_qt_qframe_default_wheelevent(MaxQFrame * frame, QWheelEvent * event);
	// QObject
	int bmx_qt_qframe_default_event(MaxQFrame * frame, QEvent * event);
	void bmx_qt_qframe_default_timerevent(MaxQFrame * frame, QTimerEvent * event);

	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQFrame : public QFrame
{
	Q_OBJECT

public:
	MaxQFrame(BBObject * handle, QWidget * parent, Qt::WindowFlags flags);
	~MaxQFrame();

private:
	BBObject * maxHandle;

public:
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

