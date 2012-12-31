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

#ifndef MAX_QT_ template
#define MAX_QT_ template

#include "../core.mod/glue.h"
#include "../qobject.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QGLWidget>

class MaxQGLWidget;

extern "C" {

#include <blitz.h>

	void _qt_qglwidget_QGLWidget__glDraw(BBObject * handle);
	void _qt_qglwidget_QGLWidget__glInit(BBObject * handle);
	void _qt_qglwidget_QGLWidget__initializeGL(BBObject * handle);
	void _qt_qglwidget_QGLWidget__initializeOverlayGL(BBObject * handle);
	void _qt_qglwidget_QGLWidget__paintGL(BBObject * handle);
	void _qt_qglwidget_QGLWidget__paintOverlayGL(BBObject * handle);
	void _qt_qglwidget_QGLWidget__resizeGL(BBObject * handle, int width, int height);
	void _qt_qglwidget_QGLWidget__resizeOverlayGL(BBObject * handle, int width, int height);


	// QGLWidget
	void bmx_qt_qglwidget_default_glDraw(MaxQGLWidget * widget);
	void bmx_qt_qglwidget_default_glInit(MaxQGLWidget * widget);
	void bmx_qt_qglwidget_default_initializeGL(MaxQGLWidget * widget);
	void bmx_qt_qglwidget_default_initializeOverlayGL(MaxQGLWidget * widget);
	void bmx_qt_qglwidget_default_paintGL(MaxQGLWidget * widget);
	void bmx_qt_qglwidget_default_paintOverlayGL(MaxQGLWidget * widget);
	void bmx_qt_qglwidget_default_resizeGL(MaxQGLWidget * widget, int width, int height);
	void bmx_qt_qglwidget_default_resizeOverlayGL(MaxQGLWidget * widget, int width, int height);
	// QWidget
	void bmx_qt_qglwidget_default_actionevent(MaxQGLWidget * widget, QActionEvent * event);
	void bmx_qt_qglwidget_default_changeevent(MaxQGLWidget * widget, QEvent * event);
	void bmx_qt_qglwidget_default_closeevent(MaxQGLWidget * widget, QCloseEvent * event);
	void bmx_qt_qglwidget_default_contextmenuevent(MaxQGLWidget * widget, QContextMenuEvent * event);
	void bmx_qt_qglwidget_default_dragenterevent(MaxQGLWidget * widget, QDragEnterEvent * event);
	void bmx_qt_qglwidget_default_dragleaveevent(MaxQGLWidget * widget, QDragLeaveEvent * event);
	void bmx_qt_qglwidget_default_dragmoveevent(MaxQGLWidget * widget, QDragMoveEvent * event);
	void bmx_qt_qglwidget_default_dropevent(MaxQGLWidget * widget, QDropEvent * event);
	void bmx_qt_qglwidget_default_enterevent(MaxQGLWidget * widget, QEvent * event);
	void bmx_qt_qglwidget_default_focusinevent(MaxQGLWidget * widget, QFocusEvent * event);
	int bmx_qt_qglwidget_default_focusnextprevchild(MaxQGLWidget * widget, int next);
	int bmx_qt_qglwidget_default_focusnextchild(MaxQGLWidget * widget);
	void bmx_qt_qglwidget_default_focusoutevent(MaxQGLWidget * widget, QFocusEvent * event);
	int bmx_qt_qglwidget_default_focuspreviouschild(MaxQGLWidget * widget);
	void bmx_qt_qglwidget_default_hideevent(MaxQGLWidget * widget, QHideEvent * event);
	void bmx_qt_qglwidget_default_inputmethodevent(MaxQGLWidget * widget, QInputMethodEvent * event);
	void bmx_qt_qglwidget_default_keypressevent(MaxQGLWidget * widget, QKeyEvent * event);
	void bmx_qt_qglwidget_default_keyreleaseevent(MaxQGLWidget * widget, QKeyEvent * event);
	void bmx_qt_qglwidget_default_leaveevent(MaxQGLWidget * widget, QEvent * event);
	void bmx_qt_qglwidget_default_mousedoubleclickevent(MaxQGLWidget * widget, QMouseEvent * event);
	void bmx_qt_qglwidget_default_mousemoveevent(MaxQGLWidget * widget, QMouseEvent * event);
	void bmx_qt_qglwidget_default_mousepressevent(MaxQGLWidget * widget, QMouseEvent * event);
	void bmx_qt_qglwidget_default_mousereleaseevent(MaxQGLWidget * widget, QMouseEvent * event);
	void bmx_qt_qglwidget_default_moveevent(MaxQGLWidget * widget, QMoveEvent * event);
	void bmx_qt_qglwidget_default_paintevent(MaxQGLWidget * widget, QPaintEvent * event);
	void bmx_qt_qglwidget_default_resizeevent(MaxQGLWidget * widget, QResizeEvent * event);
	void bmx_qt_qglwidget_default_showevent(MaxQGLWidget * widget, QShowEvent * event);
	void bmx_qt_qglwidget_default_tabletevent(MaxQGLWidget * widget, QTabletEvent * event);
	void bmx_qt_qglwidget_default_wheelevent(MaxQGLWidget * widget, QWheelEvent * event);
	// QObject
	int bmx_qt_qglwidget_default_event(MaxQGLWidget * widget, QEvent * event);
	void bmx_qt_qglwidget_default_timerevent(MaxQGLWidget * widget, QTimerEvent * event);


}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQGLWidget : public QGLWidget
{
	Q_OBJECT

public:
	MaxQGLWidget(BBObject * handle, QGLContext * context, QWidget * parent, QGLWidget * shareWidget, Qt::WindowFlags flags);
	~MaxQGLWidget();

private:
	BBObject * maxHandle;

public:
	// QGLWidget
	void defaultglDraw();
	void defaultglInit();
	void defaultinitializeGL();
	void defaultinitializeOverlayGL();
	void defaultpaintGL();
	void defaultpaintOverlayGL();
	void defaultresizeGL(int width, int height);
	void defaultresizeOverlayGL(int width, int height);
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
	// QGLWidget
	virtual void glDraw();
	virtual void glInit();
	virtual void initializeGL();
	virtual void initializeOverlayGL();
	virtual void paintGL();
	virtual void paintOverlayGL();
	virtual void resizeGL(int width, int height);
	virtual void resizeOverlayGL(int width, int height);
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
