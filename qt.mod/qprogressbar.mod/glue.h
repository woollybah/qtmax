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

#ifndef MAX_QT_QPROGRESSBAR
#define MAX_QT_QPROGRESSBAR

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QProgressBar>

class MaxQProgressBar;

extern "C" {

#include <blitz.h>

	void _qt_qprogressbar_QProgressBar__OnValueChanged(BBObject * , int value);
	
	QProgressBar * bmx_qt_qprogressbar_create(BBObject * handle, QWidget * parent);
	int bmx_qt_qprogressbar_alignment(QProgressBar * bar);
	BBString * bmx_qt_qprogressbar_format(QProgressBar * bar);
	int bmx_qt_qprogressbar_invertedappearance(QProgressBar * bar);
	int bmx_qt_qprogressbar_istextvisible(QProgressBar * bar);
	int bmx_qt_qprogressbar_maximum(QProgressBar * bar);
	int bmx_qt_qprogressbar_minimum(QProgressBar * bar);
	int bmx_qt_qprogressbar_orientation(QProgressBar * handle);
	void bmx_qt_qprogressbar_setalignment(QProgressBar * handle, int alignment);
	void bmx_qt_qprogressbar_setformat(QProgressBar * handle, BBString * format);
	void bmx_qt_qprogressbar_setinvertedappearance(QProgressBar * handle, int invert);
	void bmx_qt_qprogressbar_settextdirection(QProgressBar * handle, int textDirection);
	void bmx_qt_qprogressbar_settextvisible(QProgressBar * handle, int visible);
	BBString * bmx_qt_qprogressbar_text(QProgressBar * handle);
	int bmx_qt_qprogressbar_textdirection(QProgressBar * handle);
	int bmx_qt_qprogressbar_value(QProgressBar * handle);
	void bmx_qt_qprogressbar_reset(QProgressBar * handle);
	void bmx_qt_qprogressbar_setmaximum(QProgressBar * handle, int maximum);
	void bmx_qt_qprogressbar_setminimum(QProgressBar * handle, int minimum);
	void bmx_qt_qprogressbar_setorientation(QProgressBar * handle, int orientation);
	void bmx_qt_qprogressbar_setrange(QProgressBar * handle, int minimum, int maximum);
	void bmx_qt_qprogressbar_setvalue(QProgressBar * handle, int value);

	QProgressBar::Direction bmx_qt_getprogressbardirection(int dir);

	// QProgressBar
	// QWidget
	void bmx_qt_qprogressbar_default_actionevent(MaxQProgressBar * bar, QActionEvent * event);
	void bmx_qt_qprogressbar_default_changeevent(MaxQProgressBar * bar, QEvent * event);
	void bmx_qt_qprogressbar_default_closeevent(MaxQProgressBar * bar, QCloseEvent * event);
	void bmx_qt_qprogressbar_default_contextmenuevent(MaxQProgressBar * bar, QContextMenuEvent * event);
	void bmx_qt_qprogressbar_default_dragenterevent(MaxQProgressBar * bar, QDragEnterEvent * event);
	void bmx_qt_qprogressbar_default_dragleaveevent(MaxQProgressBar * bar, QDragLeaveEvent * event);
	void bmx_qt_qprogressbar_default_dragmoveevent(MaxQProgressBar * bar, QDragMoveEvent * event);
	void bmx_qt_qprogressbar_default_dropevent(MaxQProgressBar * bar, QDropEvent * event);
	void bmx_qt_qprogressbar_default_enterevent(MaxQProgressBar * bar, QEvent * event);
	void bmx_qt_qprogressbar_default_focusinevent(MaxQProgressBar * bar, QFocusEvent * event);
	int bmx_qt_qprogressbar_default_focusnextprevchild(MaxQProgressBar * bar, int next);
	int bmx_qt_qprogressbar_default_focusnextchild(MaxQProgressBar * bar);
	void bmx_qt_qprogressbar_default_focusoutevent(MaxQProgressBar * bar, QFocusEvent * event);
	int bmx_qt_qprogressbar_default_focuspreviouschild(MaxQProgressBar * bar);
	void bmx_qt_qprogressbar_default_hideevent(MaxQProgressBar * bar, QHideEvent * event);
	void bmx_qt_qprogressbar_default_inputmethodevent(MaxQProgressBar * bar, QInputMethodEvent * event);
	void bmx_qt_qprogressbar_default_keypressevent(MaxQProgressBar * bar, QKeyEvent * event);
	void bmx_qt_qprogressbar_default_keyreleaseevent(MaxQProgressBar * bar, QKeyEvent * event);
	void bmx_qt_qprogressbar_default_leaveevent(MaxQProgressBar * bar, QEvent * event);
	void bmx_qt_qprogressbar_default_mousedoubleclickevent(MaxQProgressBar * bar, QMouseEvent * event);
	void bmx_qt_qprogressbar_default_mousemoveevent(MaxQProgressBar * bar, QMouseEvent * event);
	void bmx_qt_qprogressbar_default_mousepressevent(MaxQProgressBar * bar, QMouseEvent * event);
	void bmx_qt_qprogressbar_default_mousereleaseevent(MaxQProgressBar * bar, QMouseEvent * event);
	void bmx_qt_qprogressbar_default_moveevent(MaxQProgressBar * bar, QMoveEvent * event);
	void bmx_qt_qprogressbar_default_paintevent(MaxQProgressBar * bar, QPaintEvent * event);
	void bmx_qt_qprogressbar_default_resizeevent(MaxQProgressBar * bar, QResizeEvent * event);
	void bmx_qt_qprogressbar_default_showevent(MaxQProgressBar * bar, QShowEvent * event);
	void bmx_qt_qprogressbar_default_tabletevent(MaxQProgressBar * bar, QTabletEvent * event);
	void bmx_qt_qprogressbar_default_wheelevent(MaxQProgressBar * bar, QWheelEvent * event);
	// QObject
	int bmx_qt_qprogressbar_default_event(MaxQProgressBar * bar, QEvent * event);
	void bmx_qt_qprogressbar_default_timerevent(MaxQProgressBar * bar, QTimerEvent * event);
	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQProgressBar : public QProgressBar
{

	Q_OBJECT

public:
	MaxQProgressBar(BBObject * handle, QWidget * parent);
	~MaxQProgressBar();

private:
	BBObject * maxHandle;

private slots:
	void onValueChanged(int value);
	void onCustomContextMenuRequested(const QPoint & pos);

public:
	// QProgressBar
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
	bool defaultfocusNextChild();
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
	// QProgressBar
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
