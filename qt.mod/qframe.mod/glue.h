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

	void _qt_qframe_QFrame__OnPaintEvent(BBObject * handle, QPaintEvent * event);
	void _qt_qframe_QFrame__OnChangeEvent(BBObject * handle, QEvent * event);
	int _qt_qframe_QFrame__OnEvent(BBObject * handle, QEvent * event);

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

	void bmx_qt_qframe_default_changeevent(MaxQFrame * frame, QEvent * event);
	int bmx_qt_qframe_default_event(MaxQFrame * frame, QEvent * event);
	void bmx_qt_qframe_default_paintevent(MaxQFrame * frame, QPaintEvent * event);
	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQFrame : public QFrame
{

public:
	MaxQFrame(BBObject * handle, QWidget * parent, Qt::WindowFlags flags);
	~MaxQFrame();

private:
	BBObject * maxHandle;

public:
	void defaultChangeEvent(QEvent * event);
	bool defaultEvent(QEvent * event);
	void defaultPaintEvent(QPaintEvent * event);

protected:
	void actionEvent(QActionEvent * event);
	void changeEvent(QEvent * event);
	void closeEvent(QCloseEvent * event);
	void contextMenuEvent(QContextMenuEvent * event);
	void dragEnterEvent(QDragEnterEvent * event);
	void dragLeaveEvent(QDragLeaveEvent * event);
	void dragMoveEvent(QDragMoveEvent * event);
	void dropEvent(QDropEvent * event);
	void enterEvent(QEvent * event);
	void focusInEvent(QFocusEvent * event);
	void focusOutEvent(QFocusEvent * event);
	void hideEvent(QHideEvent * event);
	void inputMethodEvent(QInputMethodEvent * event);
	void keyPressEvent(QKeyEvent * event);
	void keyReleaseEvent(QKeyEvent * event);
	void leaveEvent(QEvent * event);
	void moveEvent(QMoveEvent * event);
	void paintEvent(QPaintEvent * event);
	void mouseDoubleClickEvent(QMouseEvent * event);
	void mouseMoveEvent(QMouseEvent * event);
	void mousePressEvent(QMouseEvent * event);
	void mouseReleaseEvent(QMouseEvent * event);
	void resizeEvent(QResizeEvent * event);
	void showEvent(QShowEvent * event);
	void tabletEvent(QTabletEvent * event);
	void wheelEvent(QWheelEvent * event);
	bool event(QEvent * event);
	void timerEvent(QTimerEvent * event);
};

#endif

