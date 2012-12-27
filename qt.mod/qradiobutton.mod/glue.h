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

#ifndef MAX_QT_QRADIOBUTTON
#define MAX_QT_QRADIOBUTTON

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include "../qabstractbutton.mod/glue.h"
#include <QtCore>
#include <QRadioButton>

class MaxQRadioButton;

extern "C" {

#include <blitz.h>

	void _qt_qradiobutton_QRadioButton__OnClicked(BBObject * handle, int checked);
	void _qt_qradiobutton_QRadioButton__OnPressed(BBObject * handle);
	void _qt_qradiobutton_QRadioButton__OnReleased(BBObject * handle);
	void _qt_qradiobutton_QRadioButton__OnToggled(BBObject * handle, int checked);

	QRadioButton * bmx_qt_qradiobutton_create(BBObject * handle, BBString * text, QWidget * parent);

	// QRadioButton
	// QAbstractButton
	void bmx_qt_qradiobutton_default_checkstateset(MaxQRadioButton * button);
	int bmx_qt_qradiobutton_default_hitbutton(MaxQRadioButton * button, int x, int y);
	void bmx_qt_qradiobutton_default_nextcheckstate(MaxQRadioButton * button);
	// QWidget
	void bmx_qt_qradiobutton_default_actionevent(MaxQRadioButton * button, QActionEvent * event);
	void bmx_qt_qradiobutton_default_changeevent(MaxQRadioButton * button, QEvent * event);
	void bmx_qt_qradiobutton_default_closeevent(MaxQRadioButton * button, QCloseEvent * event);
	void bmx_qt_qradiobutton_default_contextmenuevent(MaxQRadioButton * button, QContextMenuEvent * event);
	void bmx_qt_qradiobutton_default_dragenterevent(MaxQRadioButton * button, QDragEnterEvent * event);
	void bmx_qt_qradiobutton_default_dragleaveevent(MaxQRadioButton * button, QDragLeaveEvent * event);
	void bmx_qt_qradiobutton_default_dragmoveevent(MaxQRadioButton * button, QDragMoveEvent * event);
	void bmx_qt_qradiobutton_default_dropevent(MaxQRadioButton * button, QDropEvent * event);
	void bmx_qt_qradiobutton_default_enterevent(MaxQRadioButton * button, QEvent * event);
	void bmx_qt_qradiobutton_default_focusinevent(MaxQRadioButton * button, QFocusEvent * event);
	int bmx_qt_qradiobutton_default_focusnextprevchild(MaxQRadioButton * button, int next);
	int bmx_qt_qradiobutton_default_focusnextchild(MaxQRadioButton * button);
	void bmx_qt_qradiobutton_default_focusoutevent(MaxQRadioButton * button, QFocusEvent * event);
	int bmx_qt_qradiobutton_default_focuspreviouschild(MaxQRadioButton * button);
	void bmx_qt_qradiobutton_default_hideevent(MaxQRadioButton * button, QHideEvent * event);
	void bmx_qt_qradiobutton_default_inputmethodevent(MaxQRadioButton * button, QInputMethodEvent * event);
	void bmx_qt_qradiobutton_default_keypressevent(MaxQRadioButton * button, QKeyEvent * event);
	void bmx_qt_qradiobutton_default_keyreleaseevent(MaxQRadioButton * button, QKeyEvent * event);
	void bmx_qt_qradiobutton_default_leaveevent(MaxQRadioButton * button, QEvent * event);
	void bmx_qt_qradiobutton_default_mousedoubleclickevent(MaxQRadioButton * button, QMouseEvent * event);
	void bmx_qt_qradiobutton_default_mousemoveevent(MaxQRadioButton * button, QMouseEvent * event);
	void bmx_qt_qradiobutton_default_mousepressevent(MaxQRadioButton * button, QMouseEvent * event);
	void bmx_qt_qradiobutton_default_mousereleaseevent(MaxQRadioButton * button, QMouseEvent * event);
	void bmx_qt_qradiobutton_default_moveevent(MaxQRadioButton * button, QMoveEvent * event);
	void bmx_qt_qradiobutton_default_paintevent(MaxQRadioButton * button, QPaintEvent * event);
	void bmx_qt_qradiobutton_default_resizeevent(MaxQRadioButton * button, QResizeEvent * event);
	void bmx_qt_qradiobutton_default_showevent(MaxQRadioButton * button, QShowEvent * event);
	void bmx_qt_qradiobutton_default_tabletevent(MaxQRadioButton * button, QTabletEvent * event);
	void bmx_qt_qradiobutton_default_wheelevent(MaxQRadioButton * button, QWheelEvent * event);
	// QObject
	int bmx_qt_qradiobutton_default_event(MaxQRadioButton * button, QEvent * event);
	void bmx_qt_qradiobutton_default_timerevent(MaxQRadioButton * button, QTimerEvent * event);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQRadioButton : public QRadioButton
{

	Q_OBJECT

public:
	MaxQRadioButton(BBObject * handle, const QString & text, QWidget * parent);
	~MaxQRadioButton();

private:
	BBObject * maxHandle;

private slots:
	void onClicked(bool checked);
	void onPressed();
	void onReleased();
	void onToggled(bool checked);

public:
	// QRadioButton
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
	// QRadioButton
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
