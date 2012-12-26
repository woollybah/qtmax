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

	void bmx_qt_qtextedit_default_actionevent(MaxQTextEdit * edit, QActionEvent * event);
	void bmx_qt_qtextedit_default_changeevent(MaxQTextEdit * edit, QEvent * event);
	void bmx_qt_qtextedit_default_contextmenuevent(MaxQTextEdit * edit, QContextMenuEvent * event);
	void bmx_qt_qtextedit_default_dragenterevent(MaxQTextEdit * edit, QDragEnterEvent * event);
	void bmx_qt_qtextedit_default_dragleaveevent(MaxQTextEdit * edit, QDragLeaveEvent * event);
	void bmx_qt_qtextedit_default_dragmoveevent(MaxQTextEdit * edit, QDragMoveEvent * event);
	void bmx_qt_qtextedit_default_dropevent(MaxQTextEdit * edit, QDropEvent * event);
	void bmx_qt_qtextedit_default_focusinevent(MaxQTextEdit * edit, QFocusEvent * event);
	int bmx_qt_qtextedit_default_focusnextprevchild(MaxQTextEdit * edit, int next);
	void bmx_qt_qtextedit_default_focusoutevent(MaxQTextEdit * edit, QFocusEvent * event);
	void bmx_qt_qtextedit_default_inputmethodevent(MaxQTextEdit * edit, QInputMethodEvent * event);
	void bmx_qt_qtextedit_default_keypressevent(MaxQTextEdit * edit, QKeyEvent * event);
	void bmx_qt_qtextedit_default_keyreleaseevent(MaxQTextEdit * edit, QKeyEvent * event);
	void bmx_qt_qtextedit_default_mousedoubleclickevent(MaxQTextEdit * edit, QMouseEvent * event);
	void bmx_qt_qtextedit_default_mousemoveevent(MaxQTextEdit * edit, QMouseEvent * event);
	void bmx_qt_qtextedit_default_mousepressevent(MaxQTextEdit * edit, QMouseEvent * event);
	void bmx_qt_qtextedit_default_mousereleaseevent(MaxQTextEdit * edit, QMouseEvent * event);
	void bmx_qt_qtextedit_default_paintevent(MaxQTextEdit * edit, QPaintEvent * event);
	void bmx_qt_qtextedit_default_resizeevent(MaxQTextEdit * edit, QResizeEvent * event);
	void bmx_qt_qtextedit_default_scrollcontentsby(MaxQTextEdit * edit, int dx, int dy);
	void bmx_qt_qtextedit_default_wheelevent(MaxQTextEdit * edit, QWheelEvent * event);

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

public: 
	void defaultChangeEvent(QEvent * e);
	void defaultContextMenuEvent(QContextMenuEvent * event);
	void defaultDragEnterEvent(QDragEnterEvent * e);
	void defaultDragLeaveEvent(QDragLeaveEvent * e);
	void defaultDragMoveEvent(QDragMoveEvent * e);
	void defaultDropEvent(QDropEvent * e);
	void defaultFocusInEvent(QFocusEvent * e);
	bool defaultFocusNextPrevChild(bool next);
	void defaultFocusOutEvent(QFocusEvent * e);
	void defaultInputMethodEvent(QInputMethodEvent * e);
	void defaultKeyPressEvent(QKeyEvent * e);
	void defaultKeyReleaseEvent(QKeyEvent * e);
	void defaultMouseDoubleClickEvent(QMouseEvent * e);
	void defaultMouseMoveEvent(QMouseEvent * e);
	void defaultMousePressEvent(QMouseEvent * e);
	void defaultMouseReleaseEvent(QMouseEvent * e);
	void defaultPaintEvent(QPaintEvent * event);
	void defaultResizeEvent(QResizeEvent * e);
	void defaultScrollContentsBy(int dx, int dy);
	void defaultShowEvent(QShowEvent *);
	void defaultWheelEvent(QWheelEvent * e);

private slots:
	void onCopyAvailable(bool yes);
	void onCurrentCharFormatChanged(const QTextCharFormat & f);
	void onCursorPositionChanged();
	void onRedoAvailable(bool available);
	void onSelectionChanged();
	void onTextChanged();
	void onUndoAvailable(bool available);
	
protected:
	void changeEvent(QEvent * e);
	void contextMenuEvent(QContextMenuEvent * event);
	void dragEnterEvent(QDragEnterEvent * e);
	void dragLeaveEvent(QDragLeaveEvent * e);
	void dragMoveEvent(QDragMoveEvent * e);
	void dropEvent(QDropEvent * e);
	void focusInEvent(QFocusEvent * e);
	bool focusNextPrevChild(bool next);
	void focusOutEvent(QFocusEvent * e);
	void inputMethodEvent(QInputMethodEvent * e);
	void keyPressEvent(QKeyEvent * e);
	void keyReleaseEvent(QKeyEvent * e);
	void mouseDoubleClickEvent(QMouseEvent * e);
	void mouseMoveEvent(QMouseEvent * e);
	void mousePressEvent(QMouseEvent * e);
	void mouseReleaseEvent(QMouseEvent * e);
	void paintEvent(QPaintEvent * event);
	void resizeEvent(QResizeEvent * e);
	void scrollContentsBy(int dx, int dy);
	void showEvent(QShowEvent *);
	void wheelEvent(QWheelEvent * e);
	void timerEvent(QTimerEvent * event);

};

#endif

