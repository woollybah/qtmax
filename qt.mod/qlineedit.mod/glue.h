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

#ifndef MAX_QT_QLINEEDIT
#define MAX_QT_QLINEEDIT

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QLineEdit>

class MaxQLineEdit;

extern "C" {

#include <blitz.h>

	void _qt_qlineedit_QLineEdit__OnCursorPositionChanged(BBObject * handle, int oldPos, int newPos);
	void _qt_qlineedit_QLineEdit__OnEditingFinished(BBObject * handle);
	void _qt_qlineedit_QLineEdit__OnReturnPressed(BBObject * handle);
	void _qt_qlineedit_QLineEdit__OnSelectionChanged(BBObject * handle);
	void _qt_qlineedit_QLineEdit__OnTextChanged(BBObject * handle, BBString * text);
	void _qt_qlineedit_QLineEdit__OnTextEdited(BBObject * handle, BBString * text);

	QLineEdit * bmx_qt_qlineedit_create(BBObject * handle, QWidget * parent);
	void bmx_qt_qlineedit_setreadonly(QLineEdit * edit, int value);

	void bmx_qt_qlineedit_clear(QLineEdit * edit);
	void bmx_qt_qlineedit_copy(QLineEdit * edit);
	void bmx_qt_qlineedit_cut(QLineEdit * edit);
	void bmx_qt_qlineedit_paste(QLineEdit * edit);
	void bmx_qt_qlineedit_redo(QLineEdit * edit);
	void bmx_qt_qlineedit_selectall(QLineEdit * edit);
	void bmx_qt_qlineedit_settext(QLineEdit * edit, BBString * text);
	void bmx_qt_qlineedit_undo(QLineEdit * edit);

	BBString * bmx_qt_qlineedit_text(QLineEdit * edit);

	int bmx_qt_qlineedit_alignment(QLineEdit * edit);
	void bmx_qt_qlineedit_backspace(QLineEdit * edit);
	void bmx_qt_qlineedit_cursorbackward(QLineEdit * edit, int mark, int steps);
	void bmx_qt_qlineedit_cursorforward(QLineEdit * edit, int mark, int steps);
	int bmx_qt_qlineedit_cursorposition(QLineEdit * edit);
	int bmx_qt_qlineedit_cursorpositionat(QLineEdit * edit, int x, int y);
	void bmx_qt_qlineedit_cursorwordbackward(QLineEdit * edit, int mark);
	void bmx_qt_qlineedit_cursorwordforward(QLineEdit * edit, int mark);
	void bmx_qt_qlineedit_del(QLineEdit * edit);
	void bmx_qt_qlineedit_deselect(QLineEdit * edit);
	BBString *  bmx_qt_qlineedit_displaytext(QLineEdit * edit);
	int bmx_qt_qlineedit_dragenabled(QLineEdit * edit);
	int bmx_qt_qlineedit_echomode(QLineEdit * edit);
	void bmx_qt_qlineedit_toend(QLineEdit * edit, int mark);
	void bmx_qt_qlineedit_gettextmargins(QLineEdit * edit, int * _left, int * _top, int * _right, int * _bottom);
	int bmx_qt_qlineedit_hasacceptableinput(QLineEdit * edit);
	int bmx_qt_qlineedit_hasframe(QLineEdit * edit);
	int bmx_qt_qlineedit_hasselectedtext(QLineEdit * edit);
	void bmx_qt_qlineedit_home(QLineEdit * edit, int mark);
	BBString * bmx_qt_qlineedit_inputmask(QLineEdit * edit);
	void bmx_qt_qlineedit_insert(QLineEdit * edit, BBString * newText);
	int bmx_qt_qlineedit_ismodified(QLineEdit * edit);
	int bmx_qt_qlineedit_isreadonly(QLineEdit * edit);
	int bmx_qt_qlineedit_isredoavailable(QLineEdit * edit);
	int bmx_qt_qlineedit_isundoavailable(QLineEdit * edit);
	int bmx_qt_qlineedit_maxlength(QLineEdit * edit);
	void bmx_qt_qlineedit_minimumsizehint(QLineEdit * edit, int * w, int * h);
	BBString * bmx_qt_qlineedit_selectedtext(QLineEdit * edit);
	int bmx_qt_qlineedit_selectionstar(QLineEdit * edit);
	void bmx_qt_qlineedit_setalignment(QLineEdit * edit, int flag);
	void bmx_qt_qlineedit_setcursorposition(QLineEdit * edit, int pos);
	void bmx_qt_qlineedit_setdragenabled(QLineEdit * edit, int b);
	void bmx_qt_qlineedit_setechomode(QLineEdit * edit, int mode);
	void bmx_qt_qlineedit_setframe(QLineEdit * edit, int frame);
	void bmx_qt_qlineedit_setinputmask(QLineEdit * edit, BBString * inputMask);
	void bmx_qt_qlineedit_setmaxlength(QLineEdit * edit, int length);
	void bmx_qt_qlineedit_setmodified(QLineEdit * edit, int value);
	void bmx_qt_qlineedit_setselection(QLineEdit * edit, int start, int length);
	void bmx_qt_qlineedit_settextmargins(QLineEdit * edit, int _left, int _top, int _right, int _bottom);
	void bmx_qt_qlineedit_sizehint(QLineEdit * edit, int * w, int * h);
	
	void bmx_qt_qlineedit_setvalidator(QLineEdit * edit, QValidator * v);


	// QWidget
	void bmx_qt_qlineedit_default_actionevent(MaxQLineEdit * edit, QActionEvent * event);
	void bmx_qt_qlineedit_default_changeevent(MaxQLineEdit * edit, QEvent * event);
	void bmx_qt_qlineedit_default_closeevent(MaxQLineEdit * edit, QCloseEvent * event);
	void bmx_qt_qlineedit_default_contextmenuevent(MaxQLineEdit * edit, QContextMenuEvent * event);
	void bmx_qt_qlineedit_default_dragenterevent(MaxQLineEdit * edit, QDragEnterEvent * event);
	void bmx_qt_qlineedit_default_dragleaveevent(MaxQLineEdit * edit, QDragLeaveEvent * event);
	void bmx_qt_qlineedit_default_dragmoveevent(MaxQLineEdit * edit, QDragMoveEvent * event);
	void bmx_qt_qlineedit_default_dropevent(MaxQLineEdit * edit, QDropEvent * event);
	void bmx_qt_qlineedit_default_enterevent(MaxQLineEdit * edit, QEvent * event);
	void bmx_qt_qlineedit_default_focusinevent(MaxQLineEdit * edit, QFocusEvent * event);
	int bmx_qt_qlineedit_default_focusnextprevchild(MaxQLineEdit * edit, int next);
	int bmx_qt_qlineedit_default_focusnextchild(MaxQLineEdit * edit);
	void bmx_qt_qlineedit_default_focusoutevent(MaxQLineEdit * edit, QFocusEvent * event);
	int bmx_qt_qlineedit_default_focuspreviouschild(MaxQLineEdit * edit);
	void bmx_qt_qlineedit_default_hideevent(MaxQLineEdit * edit, QHideEvent * event);
	void bmx_qt_qlineedit_default_inputmethodevent(MaxQLineEdit * edit, QInputMethodEvent * event);
	void bmx_qt_qlineedit_default_keypressevent(MaxQLineEdit * edit, QKeyEvent * event);
	void bmx_qt_qlineedit_default_keyreleaseevent(MaxQLineEdit * edit, QKeyEvent * event);
	void bmx_qt_qlineedit_default_leaveevent(MaxQLineEdit * edit, QEvent * event);
	void bmx_qt_qlineedit_default_mousedoubleclickevent(MaxQLineEdit * edit, QMouseEvent * event);
	void bmx_qt_qlineedit_default_mousemoveevent(MaxQLineEdit * edit, QMouseEvent * event);
	void bmx_qt_qlineedit_default_mousepressevent(MaxQLineEdit * edit, QMouseEvent * event);
	void bmx_qt_qlineedit_default_mousereleaseevent(MaxQLineEdit * edit, QMouseEvent * event);
	void bmx_qt_qlineedit_default_moveevent(MaxQLineEdit * edit, QMoveEvent * event);
	void bmx_qt_qlineedit_default_paintevent(MaxQLineEdit * edit, QPaintEvent * event);
	void bmx_qt_qlineedit_default_resizeevent(MaxQLineEdit * edit, QResizeEvent * event);
	void bmx_qt_qlineedit_default_showevent(MaxQLineEdit * edit, QShowEvent * event);
	void bmx_qt_qlineedit_default_tabletevent(MaxQLineEdit * edit, QTabletEvent * event);
	void bmx_qt_qlineedit_default_wheelevent(MaxQLineEdit * edit, QWheelEvent * event);
	// QObject
	int bmx_qt_qlineedit_default_event(MaxQLineEdit * edit, QEvent * event);
	void bmx_qt_qlineedit_default_timerevent(MaxQLineEdit * edit, QTimerEvent * event);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQLineEdit : public QLineEdit
{
	Q_OBJECT

public:
	MaxQLineEdit(BBObject * handle, QWidget * parent);
	~MaxQLineEdit();

private:
	BBObject * maxHandle;

public:
	// QLineEdit
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

private slots:
	void onCursorPositionChanged(int oldPos, int newPos);
	void onEditingFinished();
	void onReturnPressed();
	void onSelectionChanged();
	void onTextChanged(const QString & text);
	void onTextEdited(const QString & text);
	void onCustomContextMenuRequested(const QPoint & pos);

protected:
	// QLineEdit
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
