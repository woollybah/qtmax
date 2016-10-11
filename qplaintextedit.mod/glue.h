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

#ifndef MAX_QT_QPLAINTEXTEDIT
#define MAX_QT_QPLAINTEXTEDIT

#include "../core.mod/glue.h"
#include "../qobject.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include "../qabstractscrollarea.mod/glue.h"
#include "../qtextcharformat.mod/glue.h"
#include "../qtextdocument.mod/glue.h"
#include <QtCore>
#include <QPlainTextEdit>

class MaxQPlainTextEdit;

extern "C" {

#include <blitz.h>

	void _qt_qplaintextedit_QPlainTextEdit__OnBlockCountChanged(BBObject * handle, int newBlockCount);
	void _qt_qplaintextedit_QPlainTextEdit__OnCopyAvailable(BBObject * handle, int yes);
	void _qt_qplaintextedit_QPlainTextEdit__OnCursorPositionChanged(BBObject * handle);
	void _qt_qplaintextedit_QPlainTextEdit__OnModificationChanged(BBObject * handle, int changed);
	void _qt_qplaintextedit_QPlainTextEdit__OnRedoAvailable(BBObject * handle, int available);
	void _qt_qplaintextedit_QPlainTextEdit__OnSelectionChanged(BBObject * handle);
	void _qt_qplaintextedit_QPlainTextEdit__OnTextChanged(BBObject * handle);
	void _qt_qplaintextedit_QPlainTextEdit__OnUndoAvailable(BBObject * handle, int available);
	void _qt_qplaintextedit_QPlainTextEdit__OnUpdateRequest(BBObject * handle, int x, int y, int width, int height, int dy);


	// QPlainTextEdit
	// QAbstractScrollArea
	void bmx_qt_qplaintextedit_default_scrollcontentsby(MaxQPlainTextEdit * edit, int dx, int dy);
	int bmx_qt_qplaintextedit_default_viewportevent(MaxQPlainTextEdit * edit, QEvent * event);
	// QFrame
	// QWidget
	void bmx_qt_qplaintextedit_default_actionevent(MaxQPlainTextEdit * edit, QActionEvent * event);
	void bmx_qt_qplaintextedit_default_changeevent(MaxQPlainTextEdit * edit, QEvent * event);
	void bmx_qt_qplaintextedit_default_closeevent(MaxQPlainTextEdit * edit, QCloseEvent * event);
	void bmx_qt_qplaintextedit_default_contextmenuevent(MaxQPlainTextEdit * edit, QContextMenuEvent * event);
	void bmx_qt_qplaintextedit_default_dragenterevent(MaxQPlainTextEdit * edit, QDragEnterEvent * event);
	void bmx_qt_qplaintextedit_default_dragleaveevent(MaxQPlainTextEdit * edit, QDragLeaveEvent * event);
	void bmx_qt_qplaintextedit_default_dragmoveevent(MaxQPlainTextEdit * edit, QDragMoveEvent * event);
	void bmx_qt_qplaintextedit_default_dropevent(MaxQPlainTextEdit * edit, QDropEvent * event);
	void bmx_qt_qplaintextedit_default_enterevent(MaxQPlainTextEdit * edit, QEvent * event);
	void bmx_qt_qplaintextedit_default_focusinevent(MaxQPlainTextEdit * edit, QFocusEvent * event);
	int bmx_qt_qplaintextedit_default_focusnextprevchild(MaxQPlainTextEdit * edit, int next);
	int bmx_qt_qplaintextedit_default_focusnextchild(MaxQPlainTextEdit * edit);
	void bmx_qt_qplaintextedit_default_focusoutevent(MaxQPlainTextEdit * edit, QFocusEvent * event);
	int bmx_qt_qplaintextedit_default_focuspreviouschild(MaxQPlainTextEdit * edit);
	void bmx_qt_qplaintextedit_default_hideevent(MaxQPlainTextEdit * edit, QHideEvent * event);
	void bmx_qt_qplaintextedit_default_inputmethodevent(MaxQPlainTextEdit * edit, QInputMethodEvent * event);
	void bmx_qt_qplaintextedit_default_keypressevent(MaxQPlainTextEdit * edit, QKeyEvent * event);
	void bmx_qt_qplaintextedit_default_keyreleaseevent(MaxQPlainTextEdit * edit, QKeyEvent * event);
	void bmx_qt_qplaintextedit_default_leaveevent(MaxQPlainTextEdit * edit, QEvent * event);
	void bmx_qt_qplaintextedit_default_mousedoubleclickevent(MaxQPlainTextEdit * edit, QMouseEvent * event);
	void bmx_qt_qplaintextedit_default_mousemoveevent(MaxQPlainTextEdit * edit, QMouseEvent * event);
	void bmx_qt_qplaintextedit_default_mousepressevent(MaxQPlainTextEdit * edit, QMouseEvent * event);
	void bmx_qt_qplaintextedit_default_mousereleaseevent(MaxQPlainTextEdit * edit, QMouseEvent * event);
	void bmx_qt_qplaintextedit_default_moveevent(MaxQPlainTextEdit * edit, QMoveEvent * event);
	void bmx_qt_qplaintextedit_default_paintevent(MaxQPlainTextEdit * edit, QPaintEvent * event);
	void bmx_qt_qplaintextedit_default_resizeevent(MaxQPlainTextEdit * edit, QResizeEvent * event);
	void bmx_qt_qplaintextedit_default_showevent(MaxQPlainTextEdit * edit, QShowEvent * event);
	void bmx_qt_qplaintextedit_default_tabletevent(MaxQPlainTextEdit * edit, QTabletEvent * event);
	void bmx_qt_qplaintextedit_default_wheelevent(MaxQPlainTextEdit * edit, QWheelEvent * event);
	// QObject
	int bmx_qt_qplaintextedit_default_event(MaxQPlainTextEdit * edit, QEvent * event);
	void bmx_qt_qplaintextedit_default_timerevent(MaxQPlainTextEdit * edit, QTimerEvent * event);



	QPlainTextEdit * bmx_qt_qplaintextedit_create(BBObject * handle, QWidget * parent);
	BBString * bmx_qt_qplaintextedit_anchorat(QPlainTextEdit * edit, int x, int y);
	int bmx_qt_qplaintextedit_backgroundvisible(QPlainTextEdit * edit);
	int bmx_qt_qplaintextedit_blockcount(QPlainTextEdit * edit);
	int bmx_qt_qplaintextedit_canpaste(QPlainTextEdit * edit);
	int bmx_qt_qplaintextedit_centeronscroll(QPlainTextEdit * edit);
	MaxQTextCharFormat * bmx_qt_qplaintextedit_currentcharformat(QPlainTextEdit * edit);
	MaxQTextCursor * bmx_qt_qplaintextedit_cursorforposition(QPlainTextEdit * edit, int x, int y);
	void bmx_qt_qplaintextedit_cursorrectcursor(QPlainTextEdit * edit, MaxQTextCursor * cursor, int * x, int * y, int * width, int * height);
	void bmx_qt_qplaintextedit_cursorrect(QPlainTextEdit * edit, int * x, int * y, int * width, int * height);
	int bmx_qt_qplaintextedit_cursorwidth(QPlainTextEdit * edit);
	BBString * bmx_qt_qplaintextedit_documenttitle(QPlainTextEdit * edit);
	void bmx_qt_qplaintextedit_ensurecursorvisible(QPlainTextEdit * edit);
	int bmx_qt_qplaintextedit_find(QPlainTextEdit * edit, BBString * expr, int options);
	int bmx_qt_qplaintextedit_isreadonly(QPlainTextEdit * edit);
	int bmx_qt_qplaintextedit_isundoredoenabled(QPlainTextEdit * edit);
	int bmx_qt_qplaintextedit_linewrapmode(QPlainTextEdit * edit);
	int bmx_qt_qplaintextedit_maximumblockcount(QPlainTextEdit * edit);
	void bmx_qt_qplaintextedit_mergecurrentcharformat(QPlainTextEdit * edit, MaxQTextCharFormat * modifier);
	void bmx_qt_qplaintextedit_movecursor(QPlainTextEdit * edit, int operation, int Mode);
	int bmx_qt_qplaintextedit_overwritemode(QPlainTextEdit * edit);
	void bmx_qt_qplaintextedit_setbackgroundvisible(QPlainTextEdit * edit, int visible);
	void bmx_qt_qplaintextedit_setcenteronscrol(QPlainTextEdit * edit, int enabled);
	void bmx_qt_qplaintextedit_setcurrentcharformat(QPlainTextEdit * edit, MaxQTextCharFormat * format);
	void bmx_qt_qplaintextedit_setcursorwidth(QPlainTextEdit * edit, int width);
	void bmx_qt_qplaintextedit_setdocument(QPlainTextEdit * edit, QTextDocument * document);
	void bmx_qt_qplaintextedit_setdocumenttitle(QPlainTextEdit * edit, BBString * title);
	void bmx_qt_qplaintextedit_setlinewrapmode(QPlainTextEdit * edit, int Mode);
	void bmx_qt_qplaintextedit_setmaximumblockcount(QPlainTextEdit * edit, int maximum);
	void bmx_qt_qplaintextedit_setoverwritemode(QPlainTextEdit * edit, int overwrite);
	void bmx_qt_qplaintextedit_setreadonly(QPlainTextEdit * edit, int ro);
	void bmx_qt_qplaintextedit_settabchangesfocus(QPlainTextEdit * edit, int value);
	void bmx_qt_qplaintextedit_settabstopwidth(QPlainTextEdit * edit, int width);
	void bmx_qt_qplaintextedit_settextcursor(QPlainTextEdit * edit, MaxQTextCursor * cursor);
	void bmx_qt_qplaintextedit_settextinteractionflags(QPlainTextEdit * edit, int flags);
	void bmx_qt_qplaintextedit_setundoredoenabled(QPlainTextEdit * edit, int enable);
	void bmx_qt_qplaintextedit_setwordwrapmode(QPlainTextEdit * edit, int policy);
	int bmx_qt_qplaintextedit_tabchangesfocus(QPlainTextEdit * edit);
	int bmx_qt_qplaintextedit_tabstopwidth(QPlainTextEdit * edit);
	MaxQTextCursor * bmx_qt_qplaintextedit_textcursor(QPlainTextEdit * edit);
	int bmx_qt_qplaintextedit_textinteractionflags(QPlainTextEdit * edit);
	BBString * bmx_qt_qplaintextedit_toplaintext(QPlainTextEdit * edit);
	int bmx_qt_qplaintextedit_wordwrapmode(QPlainTextEdit * edit);
	void bmx_qt_qplaintextedit_appendhtml(QPlainTextEdit * edit, BBString * html);
	void bmx_qt_qplaintextedit_appendplaintext(QPlainTextEdit * edit, BBString * text);
	void bmx_qt_qplaintextedit_centercursor(QPlainTextEdit * edit);
	void bmx_qt_qplaintextedit_clear(QPlainTextEdit * edit);
	void bmx_qt_qplaintextedit_copy(QPlainTextEdit * edit);
	void bmx_qt_qplaintextedit_cut(QPlainTextEdit * edit);
	void bmx_qt_qplaintextedit_insertplaintext(QPlainTextEdit * edit, BBString * text);
	void bmx_qt_qplaintextedit_paste(QPlainTextEdit * edit);
	void bmx_qt_qplaintextedit_redo(QPlainTextEdit * edit);
	void bmx_qt_qplaintextedit_selectall(QPlainTextEdit * edit);
	void bmx_qt_qplaintextedit_setplaintext(QPlainTextEdit * edit, BBString * text);
	void bmx_qt_qplaintextedit_undo(QPlainTextEdit * edit);
	void bmx_qt_qplaintextedit_setviewportmargins(MaxQPlainTextEdit * edit, int left, int top, int right, int bottom);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQPlainTextEdit : public QPlainTextEdit
{
	Q_OBJECT

public:
	MaxQPlainTextEdit(BBObject * handle, QWidget * parent);
	~MaxQPlainTextEdit();

	void setViewportMargins(int left, int top, int right, int bottom);

private:
	BBObject * maxHandle;

private slots:
	void onBlockCountChanged(int newBlockCount);
	void onCopyAvailable(bool yes);
	void onCursorPositionChanged();
	void onModificationChanged(bool changed);
	void onRedoAvailable(bool available);
	void onSelectionChanged();
	void onTextChanged();
	void onUndoAvailable(bool available);
	void onUpdateRequest(const QRect & rect, int dy);
	void onCustomContextMenuRequested(const QPoint & pos);

public:
	// QPlainTextEdit
	// QAbstractScrollArea
	void defaultscrollContentsBy(int dx, int dy);
	bool defaultviewportEvent(QEvent * event);
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
	// QPlainTextEdit
	// QAbstractScrollArea
	virtual void scrollContentsBy(int dx, int dy);
	virtual bool viewportEvent(QEvent * event);
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
