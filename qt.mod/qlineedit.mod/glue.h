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


	void bmx_qt_qlineedit_default_mousedoubleclickevent(MaxQLineEdit * edit, QMouseEvent * event);
	void bmx_qt_qlineedit_default_mousemoveevent(MaxQLineEdit * edit, QMouseEvent * event);
	void bmx_qt_qlineedit_default_mousepressevent(MaxQLineEdit * edit, QMouseEvent * event);
	void bmx_qt_qlineedit_default_mousereleaseevent(MaxQLineEdit * edit, QMouseEvent * event);
	void bmx_qt_qlineedit_default_changeevent(MaxQLineEdit * edit, QEvent * event);
	void bmx_qt_qlineedit_default_contextmenuevent(MaxQLineEdit * edit, QContextMenuEvent * event);
	void bmx_qt_qlineedit_default_dragenterevent(MaxQLineEdit * edit, QDragEnterEvent * event);
	void bmx_qt_qlineedit_default_dragleaveevent(MaxQLineEdit * edit, QDragLeaveEvent * event);
	void bmx_qt_qlineedit_default_dragmoveevent(MaxQLineEdit * edit, QDragMoveEvent * event);
	void bmx_qt_qlineedit_default_dropevent(MaxQLineEdit * edit, QDropEvent * event);
	void bmx_qt_qlineedit_default_focusinevent(MaxQLineEdit * edit, QFocusEvent * event);
	void bmx_qt_qlineedit_default_focusoutevent(MaxQLineEdit * edit, QFocusEvent * event);
	void bmx_qt_qlineedit_default_inputmethodevent(MaxQLineEdit * edit, QInputMethodEvent * event);
	void bmx_qt_qlineedit_default_keypressevent(MaxQLineEdit * edit, QKeyEvent * event);
	void bmx_qt_qlineedit_default_paintevent(MaxQLineEdit * edit, QPaintEvent * event);

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
	void defaultChangeEvent(QEvent * event);
	void defaultContextMenuEvent(QContextMenuEvent * event);
	void defaultDragEnterEvent(QDragEnterEvent * event);
	void defaultDragLeaveEvent(QDragLeaveEvent * event);
	void defaultDragMoveEvent(QDragMoveEvent * event);
	void defaultDropEvent(QDropEvent * event);
	void defaultFocusInEvent(QFocusEvent * event);
	void defaultFocusOutEvent(QFocusEvent * event);
	void defaultInputMethodEvent(QInputMethodEvent * event);
	void defaultKeyPressEvent(QKeyEvent * event);
	void defaultKeyReleaseEvent(QKeyEvent * event);
	void defaultLeaveEvent(QEvent * event);
	void defaultPaintEvent(QPaintEvent * event);
	void defaultMouseDoubleClickEvent(QMouseEvent * event);
	void defaultMouseMoveEvent(QMouseEvent * event);
	void defaultMousePressEvent(QMouseEvent * event);
	void defaultMouseReleaseEvent(QMouseEvent * event);

private slots:
	void onCursorPositionChanged(int oldPos, int newPos);
	void onEditingFinished();
	void onReturnPressed();
	void onSelectionChanged();
	void onTextChanged(const QString & text);
	void onTextEdited(const QString & text);
	void onCustomContextMenuRequested(const QPoint & pos);

protected:
	void changeEvent(QEvent * ev);
	void contextMenuEvent(QContextMenuEvent * event);
	void dragEnterEvent(QDragEnterEvent * e);
	void dragLeaveEvent(QDragLeaveEvent * e);
	void dragMoveEvent(QDragMoveEvent * e);
	void dropEvent(QDropEvent * e);
	void focusInEvent(QFocusEvent * e);
	void focusOutEvent(QFocusEvent * e);
	void inputMethodEvent(QInputMethodEvent * e);
	void keyPressEvent(QKeyEvent * event);
	void mouseDoubleClickEvent(QMouseEvent * e);
	void mouseMoveEvent(QMouseEvent * e);
	void mousePressEvent(QMouseEvent * e);
	void mouseReleaseEvent(QMouseEvent * e);
	void paintEvent(QPaintEvent *);
	void timerEvent(QTimerEvent * event);
};


#endif
