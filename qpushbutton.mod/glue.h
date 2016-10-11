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

#ifndef MAX_QT_QPUSHBUTTON
#define MAX_QT_QPUSHBUTTON

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include "../qabstractbutton.mod/glue.h"
#include <QtCore>
#include <QPushButton>

class MaxQPushButton;

extern "C" {

#include <blitz.h>

	void _qt_qpushbutton_QPushButton__OnClicked(BBObject * handle, int checked);
	void _qt_qpushbutton_QPushButton__OnPressed(BBObject * handle);
	void _qt_qpushbutton_QPushButton__OnReleased(BBObject * handle);
	void _qt_qpushbutton_QPushButton__OnToggled(BBObject * handle, int checked);


	QPushButton * bmx_qt_qpushbutton_create(BBObject * handle, BBString * text, QWidget * parent);
	int bmx_qt_qpushbutton_autodefault(QPushButton * button);
	int bmx_qt_qpushbutton_isdefault(QPushButton * button);
	int bmx_qt_qpushbutton_isflat(QPushButton * button);
	QMenu * bmx_qt_qpushbutton_menu(QPushButton * button);
	void bmx_qt_qpushbutton_setautodefault(QPushButton * button, int value);
	void bmx_qt_qpushbutton_setdefault(QPushButton * button, int value);
	void bmx_qt_qpushbutton_setflat(QPushButton * button, int value);
	void bmx_qt_qpushbutton_setmenu(QPushButton * button, QMenu * menu);
	void bmx_qt_qpushbutton_showmenu(QPushButton * button);


	// QPushButton
	// QAbstractButton
	void bmx_qt_qpushbutton_default_checkstateset(MaxQPushButton * button);
	int bmx_qt_qpushbutton_default_hitbutton(MaxQPushButton * button, int x, int y);
	void bmx_qt_qpushbutton_default_nextcheckstate(MaxQPushButton * button);
	// QWidget
	void bmx_qt_qpushbutton_default_actionevent(MaxQPushButton * button, QActionEvent * event);
	void bmx_qt_qpushbutton_default_changeevent(MaxQPushButton * button, QEvent * event);
	void bmx_qt_qpushbutton_default_closeevent(MaxQPushButton * button, QCloseEvent * event);
	void bmx_qt_qpushbutton_default_contextmenuevent(MaxQPushButton * button, QContextMenuEvent * event);
	void bmx_qt_qpushbutton_default_dragenterevent(MaxQPushButton * button, QDragEnterEvent * event);
	void bmx_qt_qpushbutton_default_dragleaveevent(MaxQPushButton * button, QDragLeaveEvent * event);
	void bmx_qt_qpushbutton_default_dragmoveevent(MaxQPushButton * button, QDragMoveEvent * event);
	void bmx_qt_qpushbutton_default_dropevent(MaxQPushButton * button, QDropEvent * event);
	void bmx_qt_qpushbutton_default_enterevent(MaxQPushButton * button, QEvent * event);
	void bmx_qt_qpushbutton_default_focusinevent(MaxQPushButton * button, QFocusEvent * event);
	int bmx_qt_qpushbutton_default_focusnextprevchild(MaxQPushButton * button, int next);
	int bmx_qt_qpushbutton_default_focusnextchild(MaxQPushButton * button);
	void bmx_qt_qpushbutton_default_focusoutevent(MaxQPushButton * button, QFocusEvent * event);
	int bmx_qt_qpushbutton_default_focuspreviouschild(MaxQPushButton * button);
	void bmx_qt_qpushbutton_default_hideevent(MaxQPushButton * button, QHideEvent * event);
	void bmx_qt_qpushbutton_default_inputmethodevent(MaxQPushButton * button, QInputMethodEvent * event);
	void bmx_qt_qpushbutton_default_keypressevent(MaxQPushButton * button, QKeyEvent * event);
	void bmx_qt_qpushbutton_default_keyreleaseevent(MaxQPushButton * button, QKeyEvent * event);
	void bmx_qt_qpushbutton_default_leaveevent(MaxQPushButton * button, QEvent * event);
	void bmx_qt_qpushbutton_default_mousedoubleclickevent(MaxQPushButton * button, QMouseEvent * event);
	void bmx_qt_qpushbutton_default_mousemoveevent(MaxQPushButton * button, QMouseEvent * event);
	void bmx_qt_qpushbutton_default_mousepressevent(MaxQPushButton * button, QMouseEvent * event);
	void bmx_qt_qpushbutton_default_mousereleaseevent(MaxQPushButton * button, QMouseEvent * event);
	void bmx_qt_qpushbutton_default_moveevent(MaxQPushButton * button, QMoveEvent * event);
	void bmx_qt_qpushbutton_default_paintevent(MaxQPushButton * button, QPaintEvent * event);
	void bmx_qt_qpushbutton_default_resizeevent(MaxQPushButton * button, QResizeEvent * event);
	void bmx_qt_qpushbutton_default_showevent(MaxQPushButton * button, QShowEvent * event);
	void bmx_qt_qpushbutton_default_tabletevent(MaxQPushButton * button, QTabletEvent * event);
	void bmx_qt_qpushbutton_default_wheelevent(MaxQPushButton * button, QWheelEvent * event);
	// QObject
	int bmx_qt_qpushbutton_default_event(MaxQPushButton * button, QEvent * event);
	void bmx_qt_qpushbutton_default_timerevent(MaxQPushButton * button, QTimerEvent * event);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQPushButton : public QPushButton
{

	Q_OBJECT

public:
	MaxQPushButton(BBObject * handle, const QString & text, QWidget * parent);
	~MaxQPushButton();

private:
	BBObject * maxHandle;

private slots:
	void onClicked(bool checked);
	void onPressed();
	void onReleased();
	void onToggled(bool checked);

public:
	// QPushButton
	// QAbstractButton
	void defaultcheckStateSet();
	bool defaulthitButton(const QPoint & pos) const;
	void defaultnextCheckState();
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
	// QPushButton
	// QAbstractButton
	virtual void checkStateSet();
	virtual bool hitButton(const QPoint & pos) const;
	virtual void nextCheckState();
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
