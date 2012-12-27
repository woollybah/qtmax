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

#ifndef MAX_QT_QCHECKBOX
#define MAX_QT_QCHECKBOX

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include "../qabstractbutton.mod/glue.h"
#include <QtCore>
#include <QCheckBox>

class MaxQCheckBox;

extern "C" {

#include <blitz.h>

	void _qt_qcheckbox_QCheckBox__OnClicked(BBObject * handle, int checked);
	void _qt_qcheckbox_QCheckBox__OnPressed(BBObject * handle);
	void _qt_qcheckbox_QCheckBox__OnReleased(BBObject * handle);
	void _qt_qcheckbox_QCheckBox__OnToggled(BBObject * handle, int checked);
	void _qt_qcheckbox_QCheckBox__OnStateChanged(BBObject * handle, int state);

	QCheckBox * bmx_qt_qcheckbox_create(BBObject * handle, BBString * text, QWidget * parent);
	int bmx_qt_qcheckbox_checkstate(QCheckBox * cb);
	int bmx_qt_qcheckbox_istristate(QCheckBox * cb);
	void bmx_qt_qcheckbox_setcheckstate(QCheckBox * cb, int state);
	void bmx_qt_qcheckbox_settristate(QCheckBox * cb, int value);



	// QCheckBox
	// QAbstractButton
	void bmx_qt_qcheckbox_default_checkstateset(MaxQCheckBox * check);
	int bmx_qt_qcheckbox_default_hitbutton(MaxQCheckBox * check, int x, int y);
	void bmx_qt_qcheckbox_default_nextcheckstate(MaxQCheckBox * check);
	// QWidget
	void bmx_qt_qcheckbox_default_actionevent(MaxQCheckBox * check, QActionEvent * event);
	void bmx_qt_qcheckbox_default_changeevent(MaxQCheckBox * check, QEvent * event);
	void bmx_qt_qcheckbox_default_closeevent(MaxQCheckBox * check, QCloseEvent * event);
	void bmx_qt_qcheckbox_default_contextmenuevent(MaxQCheckBox * check, QContextMenuEvent * event);
	void bmx_qt_qcheckbox_default_dragenterevent(MaxQCheckBox * check, QDragEnterEvent * event);
	void bmx_qt_qcheckbox_default_dragleaveevent(MaxQCheckBox * check, QDragLeaveEvent * event);
	void bmx_qt_qcheckbox_default_dragmoveevent(MaxQCheckBox * check, QDragMoveEvent * event);
	void bmx_qt_qcheckbox_default_dropevent(MaxQCheckBox * check, QDropEvent * event);
	void bmx_qt_qcheckbox_default_enterevent(MaxQCheckBox * check, QEvent * event);
	void bmx_qt_qcheckbox_default_focusinevent(MaxQCheckBox * check, QFocusEvent * event);
	int bmx_qt_qcheckbox_default_focusnextprevchild(MaxQCheckBox * check, int next);
	int bmx_qt_qcheckbox_default_focusnextchild(MaxQCheckBox * check);
	void bmx_qt_qcheckbox_default_focusoutevent(MaxQCheckBox * check, QFocusEvent * event);
	int bmx_qt_qcheckbox_default_focuspreviouschild(MaxQCheckBox * check);
	void bmx_qt_qcheckbox_default_hideevent(MaxQCheckBox * check, QHideEvent * event);
	void bmx_qt_qcheckbox_default_inputmethodevent(MaxQCheckBox * check, QInputMethodEvent * event);
	void bmx_qt_qcheckbox_default_keypressevent(MaxQCheckBox * check, QKeyEvent * event);
	void bmx_qt_qcheckbox_default_keyreleaseevent(MaxQCheckBox * check, QKeyEvent * event);
	void bmx_qt_qcheckbox_default_leaveevent(MaxQCheckBox * check, QEvent * event);
	void bmx_qt_qcheckbox_default_mousedoubleclickevent(MaxQCheckBox * check, QMouseEvent * event);
	void bmx_qt_qcheckbox_default_mousemoveevent(MaxQCheckBox * check, QMouseEvent * event);
	void bmx_qt_qcheckbox_default_mousepressevent(MaxQCheckBox * check, QMouseEvent * event);
	void bmx_qt_qcheckbox_default_mousereleaseevent(MaxQCheckBox * check, QMouseEvent * event);
	void bmx_qt_qcheckbox_default_moveevent(MaxQCheckBox * check, QMoveEvent * event);
	void bmx_qt_qcheckbox_default_paintevent(MaxQCheckBox * check, QPaintEvent * event);
	void bmx_qt_qcheckbox_default_resizeevent(MaxQCheckBox * check, QResizeEvent * event);
	void bmx_qt_qcheckbox_default_showevent(MaxQCheckBox * check, QShowEvent * event);
	void bmx_qt_qcheckbox_default_tabletevent(MaxQCheckBox * check, QTabletEvent * event);
	void bmx_qt_qcheckbox_default_wheelevent(MaxQCheckBox * check, QWheelEvent * event);
	// QObject
	int bmx_qt_qcheckbox_default_event(MaxQCheckBox * check, QEvent * event);
	void bmx_qt_qcheckbox_default_timerevent(MaxQCheckBox * check, QTimerEvent * event);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQCheckBox : public QCheckBox
{

	Q_OBJECT

public:
	MaxQCheckBox(BBObject * handle, const QString & text, QWidget * parent);
	~MaxQCheckBox();

private:
	BBObject * maxHandle;

private slots:
	void onClicked(bool checked);
	void onPressed();
	void onReleased();
	void onToggled(bool checked);
	void onStateChanged(int state);
	void onCustomContextMenuRequested(const QPoint & pos);

public:
	// QCheckBox
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
	// QCheckBox
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
