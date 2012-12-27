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

#ifndef MAX_QT_QTEXTEDIT
#define MAX_QT_QTEXTEDIT

#include "../core.mod/glue.h"
#include "../qcolor.mod/glue.h"
#include "../qfont.mod/glue.h"
#include "../qtextdocument.mod/glue.h"
#include "../qtextcharformat.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include "../qabstractscrollarea.mod/glue.h"
#include <QtCore>
#include <QTextEdit>

class MaxQTextEdit;

extern "C" {

#include <blitz.h>

	void _qt_qtextedit_QTextEdit__OnCopyAvailable(BBObject * handle, int yes);
	void _qt_qtextedit_QTextEdit__OnCurrentCharFormatChanged(BBObject * handle, MaxQTextCharFormat * f);
	void _qt_qtextedit_QTextEdit__OnCursorPositionChanged(BBObject * handle);
	void _qt_qtextedit_QTextEdit__OnRedoAvailable(BBObject * handle, int available);
	void _qt_qtextedit_QTextEdit__OnSelectionChanged(BBObject * handle);
	void _qt_qtextedit_QTextEdit__OnTextChanged(BBObject * handle);
	void _qt_qtextedit_QTextEdit__OnUndoAvailable(BBObject * handle, int available);


	QTextEdit * bmx_qt_qtextedit_create(BBObject * handle, QWidget * parent);
	void bmx_qt_qtextedit_setreadonly(QTextEdit * edit, int value);

	void bmx_qt_qtextedit_append(QTextEdit * edit, BBString * text);
	void bmx_qt_qtextedit_clear(QTextEdit * edit);
	void bmx_qt_qtextedit_copy(QTextEdit * edit);
	void bmx_qt_qtextedit_cut(QTextEdit * edit);
	void bmx_qt_qtextedit_inserthtml(QTextEdit * edit, BBString * text);
	void bmx_qt_qtextedit_insertplaintext(QTextEdit * edit, BBString * text);
	void bmx_qt_qtextedit_paste(QTextEdit * edit);
	void bmx_qt_qtextedit_redo(QTextEdit * edit);
	void bmx_qt_qtextedit_scrolltoanchor(QTextEdit * edit, BBString * name);
	void bmx_qt_qtextedit_selectall(QTextEdit * edit);
	void bmx_qt_qtextedit_setalignment(QTextEdit * edit, int a);
	void bmx_qt_qtextedit_setcurrentfont(QTextEdit * edit, MaxQFont * f);
	void bmx_qt_qtextedit_setfontfamily(QTextEdit * edit, BBString * fontFamily);
	void bmx_qt_qtextedit_setfontitalic(QTextEdit * edit, int italic);
	void bmx_qt_qtextedit_setfontpointsize(QTextEdit * edit, double s);
	void bmx_qt_qtextedit_setfontunderline(QTextEdit * edit, int underline);
	void bmx_qt_qtextedit_setfontweight(QTextEdit * edit, int weight);
	void bmx_qt_qtextedit_sethtml(QTextEdit * edit, BBString * text);
	void bmx_qt_qtextedit_setplaintext(QTextEdit * edit, BBString * text);
	void bmx_qt_qtextedit_settext(QTextEdit * edit, BBString * text);
	void bmx_qt_qtextedit_settextbackgroundcolor(QTextEdit * edit, MaxQColor * c);
	void bmx_qt_qtextedit_settextcolor(QTextEdit * edit, MaxQColor * c);
	void bmx_qt_qtextedit_undo(QTextEdit * edit);
	void bmx_qt_qtextedit_zoomin(QTextEdit * edit, int _range);
	void bmx_qt_qtextedit_zoomout(QTextEdit * edit, int _range);
	void bmx_qt_qtextedit_setacceptrichtext(QTextEdit * edit, int accept);
	void bmx_qt_qtextedit_setautoformatting(QTextEdit * edit, int features);
	void bmx_qt_qtextedit_setcursorwidth(QTextEdit * edit, int width);
	void bmx_qt_qtextedit_setdocumenttitle(QTextEdit * edit, BBString * title);
	void bmx_qt_qtextedit_setlinewrapcolumnorwidth(QTextEdit * edit, int w);
	void bmx_qt_qtextedit_setlinewrapmode(QTextEdit * edit, int mode);

	BBString * bmx_qt_qtextedit_tohtml(QTextEdit * edit);
	BBString * bmx_qt_qtextedit_toplaintext(QTextEdit * edit);
	QTextDocument * bmx_qt_qtextedit_document(QTextEdit * edit);

	// QTextEdit
	// QAbstractScrollArea
	void bmx_qt_qtextedit_default_scrollcontentsby(MaxQTextEdit * edit, int dx, int dy);
	int bmx_qt_qtextedit_default_viewportevent(MaxQTextEdit * edit, QEvent * event);
	// QFrame
	// QWidget
	void bmx_qt_qtextedit_default_actionevent(MaxQTextEdit * edit, QActionEvent * event);
	void bmx_qt_qtextedit_default_changeevent(MaxQTextEdit * edit, QEvent * event);
	void bmx_qt_qtextedit_default_closeevent(MaxQTextEdit * edit, QCloseEvent * event);
	void bmx_qt_qtextedit_default_contextmenuevent(MaxQTextEdit * edit, QContextMenuEvent * event);
	void bmx_qt_qtextedit_default_dragenterevent(MaxQTextEdit * edit, QDragEnterEvent * event);
	void bmx_qt_qtextedit_default_dragleaveevent(MaxQTextEdit * edit, QDragLeaveEvent * event);
	void bmx_qt_qtextedit_default_dragmoveevent(MaxQTextEdit * edit, QDragMoveEvent * event);
	void bmx_qt_qtextedit_default_dropevent(MaxQTextEdit * edit, QDropEvent * event);
	void bmx_qt_qtextedit_default_enterevent(MaxQTextEdit * edit, QEvent * event);
	void bmx_qt_qtextedit_default_focusinevent(MaxQTextEdit * edit, QFocusEvent * event);
	int bmx_qt_qtextedit_default_focusnextprevchild(MaxQTextEdit * edit, int next);
	int bmx_qt_qtextedit_default_focusnextchild(MaxQTextEdit * edit);
	void bmx_qt_qtextedit_default_focusoutevent(MaxQTextEdit * edit, QFocusEvent * event);
	int bmx_qt_qtextedit_default_focuspreviouschild(MaxQTextEdit * edit);
	void bmx_qt_qtextedit_default_hideevent(MaxQTextEdit * edit, QHideEvent * event);
	void bmx_qt_qtextedit_default_inputmethodevent(MaxQTextEdit * edit, QInputMethodEvent * event);
	void bmx_qt_qtextedit_default_keypressevent(MaxQTextEdit * edit, QKeyEvent * event);
	void bmx_qt_qtextedit_default_keyreleaseevent(MaxQTextEdit * edit, QKeyEvent * event);
	void bmx_qt_qtextedit_default_leaveevent(MaxQTextEdit * edit, QEvent * event);
	void bmx_qt_qtextedit_default_mousedoubleclickevent(MaxQTextEdit * edit, QMouseEvent * event);
	void bmx_qt_qtextedit_default_mousemoveevent(MaxQTextEdit * edit, QMouseEvent * event);
	void bmx_qt_qtextedit_default_mousepressevent(MaxQTextEdit * edit, QMouseEvent * event);
	void bmx_qt_qtextedit_default_mousereleaseevent(MaxQTextEdit * edit, QMouseEvent * event);
	void bmx_qt_qtextedit_default_moveevent(MaxQTextEdit * edit, QMoveEvent * event);
	void bmx_qt_qtextedit_default_paintevent(MaxQTextEdit * edit, QPaintEvent * event);
	void bmx_qt_qtextedit_default_resizeevent(MaxQTextEdit * edit, QResizeEvent * event);
	void bmx_qt_qtextedit_default_showevent(MaxQTextEdit * edit, QShowEvent * event);
	void bmx_qt_qtextedit_default_tabletevent(MaxQTextEdit * edit, QTabletEvent * event);
	void bmx_qt_qtextedit_default_wheelevent(MaxQTextEdit * edit, QWheelEvent * event);
	// QObject
	int bmx_qt_qtextedit_default_event(MaxQTextEdit * edit, QEvent * event);
	void bmx_qt_qtextedit_default_timerevent(MaxQTextEdit * edit, QTimerEvent * event);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQTextEdit : public QTextEdit
{
	Q_OBJECT

public:
	MaxQTextEdit(BBObject * handle, QWidget * parent);
	~MaxQTextEdit();

private:
	BBObject * maxHandle;

private slots:
	void onCopyAvailable(bool yes);
	void onCurrentCharFormatChanged(const QTextCharFormat & f);
	void onCursorPositionChanged();
	void onRedoAvailable(bool available);
	void onSelectionChanged();
	void onTextChanged();
	void onUndoAvailable(bool available);

public:
	// QTextEdit
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
	// QTextEdit
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

