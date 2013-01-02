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

#include "glue.h"

// ---------------------------------------------------------------------------------------

MaxQPlainTextEdit::MaxQPlainTextEdit(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QPlainTextEdit(parent)
{
	qbind(this, handle);
}

MaxQPlainTextEdit::~MaxQPlainTextEdit()
{
	qunbind(this);
}

void MaxQPlainTextEdit::onBlockCountChanged(int newBlockCount) {
	_qt_qplaintextedit_QPlainTextEdit__OnBlockCountChanged(maxHandle, newBlockCount);
}

void MaxQPlainTextEdit::onCopyAvailable(bool yes) {
	_qt_qplaintextedit_QPlainTextEdit__OnCopyAvailable(maxHandle, static_cast<int>(yes));
}

void MaxQPlainTextEdit::onCursorPositionChanged() {
	_qt_qplaintextedit_QPlainTextEdit__OnCursorPositionChanged(maxHandle);
}

void MaxQPlainTextEdit::onModificationChanged(bool changed) {
	_qt_qplaintextedit_QPlainTextEdit__OnModificationChanged(maxHandle, static_cast<int>(changed));
}

void MaxQPlainTextEdit::onRedoAvailable(bool available) {
	_qt_qplaintextedit_QPlainTextEdit__OnRedoAvailable(maxHandle, static_cast<int>(available));
}

void MaxQPlainTextEdit::onSelectionChanged() {
	_qt_qplaintextedit_QPlainTextEdit__OnSelectionChanged(maxHandle);
}

void MaxQPlainTextEdit::onTextChanged() {
	_qt_qplaintextedit_QPlainTextEdit__OnTextChanged(maxHandle);
}

void MaxQPlainTextEdit::onUndoAvailable(bool available) {
	_qt_qplaintextedit_QPlainTextEdit__OnUndoAvailable(maxHandle, static_cast<int>(available));
}

void MaxQPlainTextEdit::onUpdateRequest(const QRect & rect, int dy) {
	_qt_qplaintextedit_QPlainTextEdit__OnUpdateRequest(maxHandle, rect.x(), rect.y(), rect.width(), rect.height(), dy);
}

void MaxQPlainTextEdit::onCustomContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}


// ****************** DEFAULT HANDLERS ********************

// QPlainTextEdit
// QAbstractScrollArea
void MaxQPlainTextEdit::defaultscrollContentsBy(int dx, int dy){
	QPlainTextEdit::scrollContentsBy(dx, dy);
}

bool MaxQPlainTextEdit::defaultviewportEvent(QEvent * event){
	return QPlainTextEdit::viewportEvent(event);
}

// QFrame
// QWidget
void MaxQPlainTextEdit::defaultactionEvent(QActionEvent * event){
	QPlainTextEdit::actionEvent(event);
}

void MaxQPlainTextEdit::defaultchangeEvent(QEvent * event){
	QPlainTextEdit::changeEvent(event);
}

void MaxQPlainTextEdit::defaultcloseEvent(QCloseEvent * event){
	QPlainTextEdit::closeEvent(event);
}

void MaxQPlainTextEdit::defaultcontextMenuEvent(QContextMenuEvent * event){
	QPlainTextEdit::contextMenuEvent(event);
}

void MaxQPlainTextEdit::defaultdragEnterEvent(QDragEnterEvent * event){
	QPlainTextEdit::dragEnterEvent(event);
}

void MaxQPlainTextEdit::defaultdragLeaveEvent(QDragLeaveEvent * event){
	QPlainTextEdit::dragLeaveEvent(event);
}

void MaxQPlainTextEdit::defaultdragMoveEvent(QDragMoveEvent * event){
	QPlainTextEdit::dragMoveEvent(event);
}

void MaxQPlainTextEdit::defaultdropEvent(QDropEvent * event){
	QPlainTextEdit::dropEvent(event);
}

void MaxQPlainTextEdit::defaultenterEvent(QEvent * event){
	QPlainTextEdit::enterEvent(event);
}

void MaxQPlainTextEdit::defaultfocusInEvent(QFocusEvent * event){
	QPlainTextEdit::focusInEvent(event);
}

bool MaxQPlainTextEdit::defaultfocusNextChild() {
	return QPlainTextEdit::focusNextChild();
}

bool MaxQPlainTextEdit::defaultfocusNextPrevChild(bool next){
	return QPlainTextEdit::focusNextPrevChild(next);
}

void MaxQPlainTextEdit::defaultfocusOutEvent(QFocusEvent * event){
	QPlainTextEdit::focusOutEvent(event);
}

bool MaxQPlainTextEdit::defaultfocusPreviousChild() {
	return QPlainTextEdit::focusPreviousChild();
}

void MaxQPlainTextEdit::defaulthideEvent(QHideEvent * event){
	QPlainTextEdit::hideEvent(event);
}

void MaxQPlainTextEdit::defaultinputMethodEvent(QInputMethodEvent * event){
	QPlainTextEdit::inputMethodEvent(event);
}

void MaxQPlainTextEdit::defaultkeyPressEvent(QKeyEvent * event){
	QPlainTextEdit::keyPressEvent(event);
}

void MaxQPlainTextEdit::defaultkeyReleaseEvent(QKeyEvent * event){
	QPlainTextEdit::keyReleaseEvent(event);
}

void MaxQPlainTextEdit::defaultleaveEvent(QEvent * event){
	QPlainTextEdit::leaveEvent(event);
}

void MaxQPlainTextEdit::defaultmouseDoubleClickEvent(QMouseEvent * event){
	QPlainTextEdit::mouseDoubleClickEvent(event);
}

void MaxQPlainTextEdit::defaultmouseMoveEvent(QMouseEvent * event){
	QPlainTextEdit::mouseMoveEvent(event);
}

void MaxQPlainTextEdit::defaultmousePressEvent(QMouseEvent * event){
	QPlainTextEdit::mousePressEvent(event);
}

void MaxQPlainTextEdit::defaultmouseReleaseEvent(QMouseEvent * event){
	QPlainTextEdit::mouseReleaseEvent(event);
}

void MaxQPlainTextEdit::defaultmoveEvent(QMoveEvent * event){
	QPlainTextEdit::moveEvent(event);
}

void MaxQPlainTextEdit::defaultpaintEvent(QPaintEvent * event){
	QPlainTextEdit::paintEvent(event);
}

void MaxQPlainTextEdit::defaultresizeEvent(QResizeEvent * event){
	QPlainTextEdit::resizeEvent(event);
}

void MaxQPlainTextEdit::defaultshowEvent(QShowEvent * event){
	QPlainTextEdit::showEvent(event);
}

void MaxQPlainTextEdit::defaulttabletEvent(QTabletEvent * event){
	QPlainTextEdit::tabletEvent(event);
}

void MaxQPlainTextEdit::defaultwheelEvent(QWheelEvent * event){
	QPlainTextEdit::wheelEvent(event);
}

// QObject
bool MaxQPlainTextEdit::defaultevent(QEvent * event){
	return QPlainTextEdit::event(event);
}

void MaxQPlainTextEdit::defaulttimerEvent(QTimerEvent * event){
	QPlainTextEdit::timerEvent(event);
}


// ****************** HANDLERS - TO MAX ********************

// QPlainTextEdit
// QAbstractScrollArea
void MaxQPlainTextEdit::scrollContentsBy(int dx, int dy) {
	_qt_qabstractscrollarea_QAbstractScrollArea__scrollContentsBy(maxHandle, dx, dy);
}

bool MaxQPlainTextEdit::viewportEvent(QEvent * event) {
	return static_cast<bool>(_qt_qabstractscrollarea_QAbstractScrollArea__viewportEvent(maxHandle, event));
}
// QFrame
// QWidget
void MaxQPlainTextEdit::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseMoveEvent(maxHandle, event);
}

void MaxQPlainTextEdit::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mousePressEvent(maxHandle, event);
}

void MaxQPlainTextEdit::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseReleaseEvent(maxHandle, event);
}


void MaxQPlainTextEdit::actionEvent(QActionEvent * event) {
	_qt_qwidget_QWidget__actionEvent(maxHandle, event);
}

void MaxQPlainTextEdit::changeEvent(QEvent * event) {
	_qt_qwidget_QWidget__changeEvent(maxHandle, event);
}

void MaxQPlainTextEdit::closeEvent(QCloseEvent * event) {
	_qt_qwidget_QWidget__closeEvent(maxHandle, event);
}

void MaxQPlainTextEdit::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__contextMenuEvent(maxHandle, event);
}

void MaxQPlainTextEdit::dragEnterEvent(QDragEnterEvent * event) {
	_qt_qwidget_QWidget__dragEnterEvent(maxHandle, event);
}

void MaxQPlainTextEdit::dragLeaveEvent(QDragLeaveEvent * event) {
	_qt_qwidget_QWidget__dragLeaveEvent(maxHandle, event);
}

void MaxQPlainTextEdit::dragMoveEvent(QDragMoveEvent * event) {
	_qt_qwidget_QWidget__dragMoveEvent(maxHandle, event);
}

void MaxQPlainTextEdit::dropEvent(QDropEvent * event) {
	_qt_qwidget_QWidget__dropEvent(maxHandle, event);
}

void MaxQPlainTextEdit::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__enterEvent(maxHandle, event);
}

void MaxQPlainTextEdit::focusInEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusInEvent(maxHandle, event);
}

bool MaxQPlainTextEdit::focusNextChild () {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextChild(maxHandle));
}

bool MaxQPlainTextEdit::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQPlainTextEdit::focusOutEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusOutEvent(maxHandle, event);
}

bool MaxQPlainTextEdit::focusPreviousChild() {
	return static_cast<bool>(_qt_qwidget_QWidget__focusPreviousChild(maxHandle));
}

void MaxQPlainTextEdit::hideEvent(QHideEvent * event) {
	_qt_qwidget_QWidget__hideEvent(maxHandle, event);
}

void MaxQPlainTextEdit::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qwidget_QWidget__inputMethodEvent(maxHandle, event);
}

void MaxQPlainTextEdit::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__leaveEvent(maxHandle, event);
}

void MaxQPlainTextEdit::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyPressEvent(maxHandle, event);
}

void MaxQPlainTextEdit::keyReleaseEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyReleaseEvent(maxHandle, event);
}

void MaxQPlainTextEdit::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseDoubleClickEvent(maxHandle, event);
}

void MaxQPlainTextEdit::moveEvent(QMoveEvent * event) {
	_qt_qwidget_QWidget__moveEvent(maxHandle, event);
}

void MaxQPlainTextEdit::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__paintEvent(maxHandle, event);
}

void MaxQPlainTextEdit::resizeEvent(QResizeEvent * event) {
	_qt_qwidget_QWidget__resizeEvent(maxHandle, event);
}

void MaxQPlainTextEdit::showEvent(QShowEvent * event) {
	_qt_qwidget_QWidget__showEvent(maxHandle, event);
}

void MaxQPlainTextEdit::tabletEvent(QTabletEvent * event) {
	_qt_qwidget_QWidget__tabletEvent(maxHandle, event);
}

void MaxQPlainTextEdit::wheelEvent(QWheelEvent * event) {
	_qt_qwidget_QWidget__wheelEvent(maxHandle, event);
}

// QObject
bool MaxQPlainTextEdit::event(QEvent * event) {
	return static_cast<bool>(_qt_qobject_QObject__event(maxHandle, event));
}

void MaxQPlainTextEdit::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

// QPlainTextEdit
// QAbstractScrollArea
void bmx_qt_qplaintextedit_default_scrollcontentsby(MaxQPlainTextEdit * edit, int dx, int dy) {
	edit->defaultscrollContentsBy(dx, dy);
}

int bmx_qt_qplaintextedit_default_viewportevent(MaxQPlainTextEdit * edit, QEvent * event) {
	static_cast<int>(edit->defaultviewportEvent(event));
}

// QFrame
// QWidget
void bmx_qt_qplaintextedit_default_actionevent(MaxQPlainTextEdit * edit, QActionEvent * event) {
	edit->defaultactionEvent(event);
}

void bmx_qt_qplaintextedit_default_changeevent(MaxQPlainTextEdit * edit, QEvent * event) {
	edit->defaultchangeEvent(event);
}

void bmx_qt_qplaintextedit_default_closeevent(MaxQPlainTextEdit * edit, QCloseEvent * event) {
	edit->defaultcloseEvent(event);
}

void bmx_qt_qplaintextedit_default_contextmenuevent(MaxQPlainTextEdit * edit, QContextMenuEvent * event) {
	edit->defaultcontextMenuEvent(event);
}

void bmx_qt_qplaintextedit_default_dragenterevent(MaxQPlainTextEdit * edit, QDragEnterEvent * event) {
	edit->defaultdragEnterEvent(event);
}

void bmx_qt_qplaintextedit_default_dragleaveevent(MaxQPlainTextEdit * edit, QDragLeaveEvent * event) {
	edit->defaultdragLeaveEvent(event);
}

void bmx_qt_qplaintextedit_default_dragmoveevent(MaxQPlainTextEdit * edit, QDragMoveEvent * event) {
	edit->defaultdragMoveEvent(event);
}

void bmx_qt_qplaintextedit_default_dropevent(MaxQPlainTextEdit * edit, QDropEvent * event) {
	edit->defaultdropEvent(event);
}

void bmx_qt_qplaintextedit_default_enterevent(MaxQPlainTextEdit * edit, QEvent * event) {
	edit->defaultenterEvent(event);
}

void bmx_qt_qplaintextedit_default_focusinevent(MaxQPlainTextEdit * edit, QFocusEvent * event) {
	edit->defaultfocusInEvent(event);
}

int bmx_qt_qplaintextedit_default_focusnextprevchild(MaxQPlainTextEdit * edit, int next) {
	return static_cast<int>(edit->defaultfocusNextPrevChild(static_cast<bool>(next)));
}

int bmx_qt_qplaintextedit_default_focusnextchild(MaxQPlainTextEdit * edit) {
	return static_cast<int>(edit->defaultfocusNextChild());
}

void bmx_qt_qplaintextedit_default_focusoutevent(MaxQPlainTextEdit * edit, QFocusEvent * event) {
	edit->defaultfocusOutEvent(event);
}

int bmx_qt_qplaintextedit_default_focuspreviouschild(MaxQPlainTextEdit * edit) {
	return static_cast<int>(edit->defaultfocusPreviousChild());
}

void bmx_qt_qplaintextedit_default_hideevent(MaxQPlainTextEdit * edit, QHideEvent * event) {
	edit->defaulthideEvent(event);
}

void bmx_qt_qplaintextedit_default_inputmethodevent(MaxQPlainTextEdit * edit, QInputMethodEvent * event) {
	edit->defaultinputMethodEvent(event);
}

void bmx_qt_qplaintextedit_default_keypressevent(MaxQPlainTextEdit * edit, QKeyEvent * event) {
	edit->defaultkeyPressEvent(event);
}

void bmx_qt_qplaintextedit_default_keyreleaseevent(MaxQPlainTextEdit * edit, QKeyEvent * event) {
	edit->defaultkeyReleaseEvent(event);
}

void bmx_qt_qplaintextedit_default_leaveevent(MaxQPlainTextEdit * edit, QEvent * event) {
	edit->defaultleaveEvent(event);
}

void bmx_qt_qplaintextedit_default_mousedoubleclickevent(MaxQPlainTextEdit * edit, QMouseEvent * event) {
	edit->defaultmouseDoubleClickEvent(event);
}

void bmx_qt_qplaintextedit_default_mousemoveevent(MaxQPlainTextEdit * edit, QMouseEvent * event) {
	edit->defaultmouseMoveEvent(event);
}

void bmx_qt_qplaintextedit_default_mousepressevent(MaxQPlainTextEdit * edit, QMouseEvent * event) {
	edit->defaultmousePressEvent(event);
}

void bmx_qt_qplaintextedit_default_mousereleaseevent(MaxQPlainTextEdit * edit, QMouseEvent * event) {
	edit->defaultmouseReleaseEvent(event);
}

void bmx_qt_qplaintextedit_default_moveevent(MaxQPlainTextEdit * edit, QMoveEvent * event) {
	edit->defaultmoveEvent(event);
}

void bmx_qt_qplaintextedit_default_paintevent(MaxQPlainTextEdit * edit, QPaintEvent * event) {
	edit->defaultpaintEvent(event);
}

void bmx_qt_qplaintextedit_default_resizeevent(MaxQPlainTextEdit * edit, QResizeEvent * event) {
	edit->defaultresizeEvent(event);
}

void bmx_qt_qplaintextedit_default_showevent(MaxQPlainTextEdit * edit, QShowEvent * event) {
	edit->defaultshowEvent(event);
}

void bmx_qt_qplaintextedit_default_tabletevent(MaxQPlainTextEdit * edit, QTabletEvent * event) {
	edit->defaulttabletEvent(event);
}

void bmx_qt_qplaintextedit_default_wheelevent(MaxQPlainTextEdit * edit, QWheelEvent * event) {
	edit->defaultwheelEvent(event);
}

// QObject
int bmx_qt_qplaintextedit_default_event(MaxQPlainTextEdit * edit, QEvent * event) {
	return static_cast<int>(edit->defaultevent(event));
}

void bmx_qt_qplaintextedit_default_timerevent(MaxQPlainTextEdit * edit, QTimerEvent * event) {
	edit->defaulttimerEvent(event);
}

// *********************************************

QPlainTextEdit::LineWrapMode bmx_qt_qplaintexteditlinewrapmodefromint(int m) {
	switch(m) {
		case 0:
			return QPlainTextEdit::NoWrap;
		case 1:
			return QPlainTextEdit::WidgetWidth;
	}
	
	return QPlainTextEdit::NoWrap;
}

QPlainTextEdit * bmx_qt_qplaintextedit_create(BBObject * handle, QWidget * parent) {
	return new MaxQPlainTextEdit(handle, parent);
}

BBString * bmx_qt_qplaintextedit_anchorat(QPlainTextEdit * edit, int x, int y) {
	return bbStringFromQString(edit->anchorAt(QPoint(x, y)));
}

int bmx_qt_qplaintextedit_backgroundvisible(QPlainTextEdit * edit) {
	return static_cast<int>(edit->backgroundVisible());
}

int bmx_qt_qplaintextedit_blockcount(QPlainTextEdit * edit) {
	return edit->blockCount();
}

int bmx_qt_qplaintextedit_canpaste(QPlainTextEdit * edit) {
	return static_cast<int>(edit->canPaste());
}

int bmx_qt_qplaintextedit_centeronscroll(QPlainTextEdit * edit) {
	return static_cast<int>(edit->centerOnScroll());
}

MaxQTextCharFormat * bmx_qt_qplaintextedit_currentcharformat(QPlainTextEdit * edit) {
	return new MaxQTextCharFormat(edit->currentCharFormat());
}

MaxQTextCursor * bmx_qt_qplaintextedit_cursorforposition(QPlainTextEdit * edit, int x, int y) {
	return new MaxQTextCursor(edit->cursorForPosition(QPoint(x, y)));
}

void bmx_qt_qplaintextedit_cursorrectcursor(QPlainTextEdit * edit, MaxQTextCursor * cursor, int * x, int * y, int * width, int * height) {
	QRect r(edit->cursorRect(cursor->Cursor()));
	*x = r.x();
	*y = r.y();
	*width = r.width();
	*height = r.height();
}

void bmx_qt_qplaintextedit_cursorrect(QPlainTextEdit * edit, int * x, int * y, int * width, int * height) {
	QRect r(edit->cursorRect());
	*x = r.x();
	*y = r.y();
	*width = r.width();
	*height = r.height();
}

int bmx_qt_qplaintextedit_cursorwidth(QPlainTextEdit * edit) {
	return edit->cursorWidth();
}

BBString * bmx_qt_qplaintextedit_documenttitle(QPlainTextEdit * edit) {
	return bbStringFromQString(edit->documentTitle());
}

void bmx_qt_qplaintextedit_ensurecursorvisible(QPlainTextEdit * edit) {
	edit->ensureCursorVisible();
}

int bmx_qt_qplaintextedit_find(QPlainTextEdit * edit, BBString * expr, int options) {
	return edit->find(qStringFromBBString(expr), bmx_qt_intToDocumentFindFlags(options));
}

int bmx_qt_qplaintextedit_isreadonly(QPlainTextEdit * edit) {
	return static_cast<int>(edit->isReadOnly());
}

int bmx_qt_qplaintextedit_isundoredoenabled(QPlainTextEdit * edit) {
	return static_cast<int>(edit->isUndoRedoEnabled());
}

int bmx_qt_qplaintextedit_linewrapmode(QPlainTextEdit * edit) {
	return edit->lineWrapMode();
}

int bmx_qt_qplaintextedit_maximumblockcount(QPlainTextEdit * edit) {
	return edit->maximumBlockCount();
}

void bmx_qt_qplaintextedit_mergecurrentcharformat(QPlainTextEdit * edit, MaxQTextCharFormat * modifier) {
	edit->mergeCurrentCharFormat(modifier->Format());
}

void bmx_qt_qplaintextedit_movecursor(QPlainTextEdit * edit, int operation, int mode) {
	edit->moveCursor(bmx_qt_intToCursorMoveOperation(operation), bmx_qt_intToCursorMoveMode(mode));
}

int bmx_qt_qplaintextedit_overwritemode(QPlainTextEdit * edit) {
	return edit->overwriteMode();
}

void bmx_qt_qplaintextedit_setbackgroundvisible(QPlainTextEdit * edit, int visible) {
	edit->setBackgroundVisible(static_cast<bool>(visible));
}

void bmx_qt_qplaintextedit_setcenteronscrol(QPlainTextEdit * edit, int enabled) {
	edit->setCenterOnScroll(static_cast<bool>(enabled));
}

void bmx_qt_qplaintextedit_setcurrentcharformat(QPlainTextEdit * edit, MaxQTextCharFormat * format) {
	edit->setCurrentCharFormat(format->Format());
}

void bmx_qt_qplaintextedit_setcursorwidth(QPlainTextEdit * edit, int width) {
	edit->setCursorWidth(width);
}

void bmx_qt_qplaintextedit_setdocument(QPlainTextEdit * edit, QTextDocument * document) {
	edit->setDocument(document);
}

void bmx_qt_qplaintextedit_setdocumenttitle(QPlainTextEdit * edit, BBString * title) {
	edit->setDocumentTitle(qStringFromBBString(title));
}

void bmx_qt_qplaintextedit_setlinewrapmode(QPlainTextEdit * edit, int mode) {
	edit->setLineWrapMode(bmx_qt_qplaintexteditlinewrapmodefromint(mode));
}

void bmx_qt_qplaintextedit_setmaximumblockcount(QPlainTextEdit * edit, int maximum) {
	edit->setMaximumBlockCount(maximum);
}

void bmx_qt_qplaintextedit_setoverwritemode(QPlainTextEdit * edit, int overwrite) {
	edit->setOverwriteMode(static_cast<bool>(overwrite));
}

void bmx_qt_qplaintextedit_setreadonly(QPlainTextEdit * edit, int ro) {
	edit->setReadOnly(static_cast<bool>(ro));
}

void bmx_qt_qplaintextedit_settabchangesfocus(QPlainTextEdit * edit, int value) {
	edit->setTabChangesFocus(static_cast<bool>(value));
}

void bmx_qt_qplaintextedit_settabstopwidth(QPlainTextEdit * edit, int width) {
	edit->setTabStopWidth(width);
}

void bmx_qt_qplaintextedit_settextcursor(QPlainTextEdit * edit, MaxQTextCursor * cursor) {
	edit->setTextCursor(cursor->Cursor());
}

void bmx_qt_qplaintextedit_settextinteractionflags(QPlainTextEdit * edit, int flags) {
	edit->setTextInteractionFlags(bmx_qt_inttotextinteractionflags(flags));
}

void bmx_qt_qplaintextedit_setundoredoenabled(QPlainTextEdit * edit, int enable) {
	edit->setUndoRedoEnabled(static_cast<bool>(enable));
}

void bmx_qt_qplaintextedit_setwordwrapmode(QPlainTextEdit * edit, int policy) {
	edit->setWordWrapMode(bmx_qt_intToTextOptionWrapMode(policy));
}

int bmx_qt_qplaintextedit_tabchangesfocus(QPlainTextEdit * edit) {
	return static_cast<int>(edit->tabChangesFocus());
}

int bmx_qt_qplaintextedit_tabstopwidth(QPlainTextEdit * edit) {
	return edit->tabStopWidth();
}

MaxQTextCursor * bmx_qt_qplaintextedit_textcursor(QPlainTextEdit * edit) {
	return new MaxQTextCursor(edit->textCursor());
}

int bmx_qt_qplaintextedit_textinteractionflags(QPlainTextEdit * edit) {
	return edit->textInteractionFlags();
}

BBString * bmx_qt_qplaintextedit_toplaintext(QPlainTextEdit * edit) {
	return bbStringFromQString(edit->toPlainText());
}

int bmx_qt_qplaintextedit_wordwrapmode(QPlainTextEdit * edit) {
	return edit->wordWrapMode();
}

void bmx_qt_qplaintextedit_appendhtml(QPlainTextEdit * edit, BBString * html) {
	edit->appendHtml(qStringFromBBString(html));
}

void bmx_qt_qplaintextedit_appendplaintext(QPlainTextEdit * edit, BBString * text) {
	edit->appendPlainText(qStringFromBBString(text));
}

void bmx_qt_qplaintextedit_centercursor(QPlainTextEdit * edit) {
	edit->centerCursor();
}

void bmx_qt_qplaintextedit_clear(QPlainTextEdit * edit) {
	edit->clear();
}

void bmx_qt_qplaintextedit_copy(QPlainTextEdit * edit) {
	edit->copy();
}

void bmx_qt_qplaintextedit_cut(QPlainTextEdit * edit) {
	edit->cut();
}

void bmx_qt_qplaintextedit_insertplaintext(QPlainTextEdit * edit, BBString * text) {
	edit->insertPlainText(qStringFromBBString(text));
}

void bmx_qt_qplaintextedit_paste(QPlainTextEdit * edit) {
	edit->paste();
}

void bmx_qt_qplaintextedit_redo(QPlainTextEdit * edit) {
	edit->redo();
}

void bmx_qt_qplaintextedit_selectall(QPlainTextEdit * edit) {
	edit->selectAll();
}

void bmx_qt_qplaintextedit_setplaintext(QPlainTextEdit * edit, BBString * text) {
	edit->setPlainText(qStringFromBBString(text));
}

void bmx_qt_qplaintextedit_undo(QPlainTextEdit * edit) {
	edit->undo();
}



// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
