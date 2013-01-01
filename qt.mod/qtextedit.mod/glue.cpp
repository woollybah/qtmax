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

MaxQTextEdit::MaxQTextEdit(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QTextEdit(parent)
{
	qbind(this, handle);
}

MaxQTextEdit::~MaxQTextEdit()
{
	qunbind(this);
}


void MaxQTextEdit::onCopyAvailable(bool yes) {
	_qt_qtextedit_QTextEdit__OnCopyAvailable(maxHandle, static_cast<int>(yes));
}

void MaxQTextEdit::onCurrentCharFormatChanged(const QTextCharFormat & f) {
	_qt_qtextedit_QTextEdit__OnCurrentCharFormatChanged(maxHandle, new MaxQTextCharFormat(f));
}

void MaxQTextEdit::onCursorPositionChanged() {
	_qt_qtextedit_QTextEdit__OnCursorPositionChanged(maxHandle);
}

void MaxQTextEdit::onRedoAvailable(bool available) {
	_qt_qtextedit_QTextEdit__OnRedoAvailable(maxHandle, static_cast<int>(available));
}

void MaxQTextEdit::onSelectionChanged() {
	_qt_qtextedit_QTextEdit__OnSelectionChanged(maxHandle);
}

void MaxQTextEdit::onTextChanged() {
	_qt_qtextedit_QTextEdit__OnTextChanged(maxHandle);
}

void MaxQTextEdit::onUndoAvailable(bool available) {
	_qt_qtextedit_QTextEdit__OnUndoAvailable(maxHandle, static_cast<int>(available));
}


// ****************** DEFAULT HANDLERS ********************

// QTextEdit
// QAbstractScrollArea
void MaxQTextEdit::defaultscrollContentsBy(int dx, int dy){
	QTextEdit::scrollContentsBy(dx, dy);
}

bool MaxQTextEdit::defaultviewportEvent(QEvent * event){
	return QTextEdit::viewportEvent(event);
}

// QFrame
// QWidget
void MaxQTextEdit::defaultactionEvent(QActionEvent * event){
	QTextEdit::actionEvent(event);
}

void MaxQTextEdit::defaultchangeEvent(QEvent * event){
	QTextEdit::changeEvent(event);
}

void MaxQTextEdit::defaultcloseEvent(QCloseEvent * event){
	QTextEdit::closeEvent(event);
}

void MaxQTextEdit::defaultcontextMenuEvent(QContextMenuEvent * event){
	QTextEdit::contextMenuEvent(event);
}

void MaxQTextEdit::defaultdragEnterEvent(QDragEnterEvent * event){
	QTextEdit::dragEnterEvent(event);
}

void MaxQTextEdit::defaultdragLeaveEvent(QDragLeaveEvent * event){
	QTextEdit::dragLeaveEvent(event);
}

void MaxQTextEdit::defaultdragMoveEvent(QDragMoveEvent * event){
	QTextEdit::dragMoveEvent(event);
}

void MaxQTextEdit::defaultdropEvent(QDropEvent * event){
	QTextEdit::dropEvent(event);
}

void MaxQTextEdit::defaultenterEvent(QEvent * event){
	QTextEdit::enterEvent(event);
}

void MaxQTextEdit::defaultfocusInEvent(QFocusEvent * event){
	QTextEdit::focusInEvent(event);
}

bool MaxQTextEdit::defaultfocusNextChild() {
	return QTextEdit::focusNextChild();
}

bool MaxQTextEdit::defaultfocusNextPrevChild(bool next){
	return QTextEdit::focusNextPrevChild(next);
}

void MaxQTextEdit::defaultfocusOutEvent(QFocusEvent * event){
	QTextEdit::focusOutEvent(event);
}

bool MaxQTextEdit::defaultfocusPreviousChild() {
	return QTextEdit::focusPreviousChild();
}

void MaxQTextEdit::defaulthideEvent(QHideEvent * event){
	QTextEdit::hideEvent(event);
}

void MaxQTextEdit::defaultinputMethodEvent(QInputMethodEvent * event){
	QTextEdit::inputMethodEvent(event);
}

void MaxQTextEdit::defaultkeyPressEvent(QKeyEvent * event){
	QTextEdit::keyPressEvent(event);
}

void MaxQTextEdit::defaultkeyReleaseEvent(QKeyEvent * event){
	QTextEdit::keyReleaseEvent(event);
}

void MaxQTextEdit::defaultleaveEvent(QEvent * event){
	QTextEdit::leaveEvent(event);
}

void MaxQTextEdit::defaultmouseDoubleClickEvent(QMouseEvent * event){
	QTextEdit::mouseDoubleClickEvent(event);
}

void MaxQTextEdit::defaultmouseMoveEvent(QMouseEvent * event){
	QTextEdit::mouseMoveEvent(event);
}

void MaxQTextEdit::defaultmousePressEvent(QMouseEvent * event){
	QTextEdit::mousePressEvent(event);
}

void MaxQTextEdit::defaultmouseReleaseEvent(QMouseEvent * event){
	QTextEdit::mouseReleaseEvent(event);
}

void MaxQTextEdit::defaultmoveEvent(QMoveEvent * event){
	QTextEdit::moveEvent(event);
}

void MaxQTextEdit::defaultpaintEvent(QPaintEvent * event){
	QTextEdit::paintEvent(event);
}

void MaxQTextEdit::defaultresizeEvent(QResizeEvent * event){
	QTextEdit::resizeEvent(event);
}

void MaxQTextEdit::defaultshowEvent(QShowEvent * event){
	QTextEdit::showEvent(event);
}

void MaxQTextEdit::defaulttabletEvent(QTabletEvent * event){
	QTextEdit::tabletEvent(event);
}

void MaxQTextEdit::defaultwheelEvent(QWheelEvent * event){
	QTextEdit::wheelEvent(event);
}

// QObject
bool MaxQTextEdit::defaultevent(QEvent * event){
	return QTextEdit::event(event);
}

void MaxQTextEdit::defaulttimerEvent(QTimerEvent * event){
	QTextEdit::timerEvent(event);
}


// ****************** HANDLERS - TO MAX ********************

// QTextEdit
// QAbstractScrollArea
void MaxQTextEdit::scrollContentsBy(int dx, int dy) {
	_qt_qabstractscrollarea_QAbstractScrollArea__scrollContentsBy(maxHandle, dx, dy);
}

bool MaxQTextEdit::viewportEvent(QEvent * event) {
	return static_cast<bool>(_qt_qabstractscrollarea_QAbstractScrollArea__viewportEvent(maxHandle, event));
}
// QFrame
// QWidget
void MaxQTextEdit::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseMoveEvent(maxHandle, event);
}

void MaxQTextEdit::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mousePressEvent(maxHandle, event);
}

void MaxQTextEdit::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseReleaseEvent(maxHandle, event);
}


void MaxQTextEdit::actionEvent(QActionEvent * event) {
	_qt_qwidget_QWidget__actionEvent(maxHandle, event);
}

void MaxQTextEdit::changeEvent(QEvent * event) {
	_qt_qwidget_QWidget__changeEvent(maxHandle, event);
}

void MaxQTextEdit::closeEvent(QCloseEvent * event) {
	_qt_qwidget_QWidget__closeEvent(maxHandle, event);
}

void MaxQTextEdit::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__contextMenuEvent(maxHandle, event);
}

void MaxQTextEdit::dragEnterEvent(QDragEnterEvent * event) {
	_qt_qwidget_QWidget__dragEnterEvent(maxHandle, event);
}

void MaxQTextEdit::dragLeaveEvent(QDragLeaveEvent * event) {
	_qt_qwidget_QWidget__dragLeaveEvent(maxHandle, event);
}

void MaxQTextEdit::dragMoveEvent(QDragMoveEvent * event) {
	_qt_qwidget_QWidget__dragMoveEvent(maxHandle, event);
}

void MaxQTextEdit::dropEvent(QDropEvent * event) {
	_qt_qwidget_QWidget__dropEvent(maxHandle, event);
}

void MaxQTextEdit::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__enterEvent(maxHandle, event);
}

void MaxQTextEdit::focusInEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusInEvent(maxHandle, event);
}

bool MaxQTextEdit::focusNextChild () {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextChild(maxHandle));
}

bool MaxQTextEdit::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQTextEdit::focusOutEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusOutEvent(maxHandle, event);
}

bool MaxQTextEdit::focusPreviousChild() {
	return static_cast<bool>(_qt_qwidget_QWidget__focusPreviousChild(maxHandle));
}

void MaxQTextEdit::hideEvent(QHideEvent * event) {
	_qt_qwidget_QWidget__hideEvent(maxHandle, event);
}

void MaxQTextEdit::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qwidget_QWidget__inputMethodEvent(maxHandle, event);
}

void MaxQTextEdit::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__leaveEvent(maxHandle, event);
}

void MaxQTextEdit::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyPressEvent(maxHandle, event);
}

void MaxQTextEdit::keyReleaseEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyReleaseEvent(maxHandle, event);
}

void MaxQTextEdit::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseDoubleClickEvent(maxHandle, event);
}

void MaxQTextEdit::moveEvent(QMoveEvent * event) {
	_qt_qwidget_QWidget__moveEvent(maxHandle, event);
}

void MaxQTextEdit::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__paintEvent(maxHandle, event);
}

void MaxQTextEdit::resizeEvent(QResizeEvent * event) {
	_qt_qwidget_QWidget__resizeEvent(maxHandle, event);
}

void MaxQTextEdit::showEvent(QShowEvent * event) {
	_qt_qwidget_QWidget__showEvent(maxHandle, event);
}

void MaxQTextEdit::tabletEvent(QTabletEvent * event) {
	_qt_qwidget_QWidget__tabletEvent(maxHandle, event);
}

void MaxQTextEdit::wheelEvent(QWheelEvent * event) {
	_qt_qwidget_QWidget__wheelEvent(maxHandle, event);
}

// QObject
bool MaxQTextEdit::event(QEvent * event) {
	return static_cast<bool>(_qt_qobject_QObject__event(maxHandle, event));
}

void MaxQTextEdit::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

// QTextEdit
// QAbstractScrollArea
void bmx_qt_qtextedit_default_scrollcontentsby(MaxQTextEdit * edit, int dx, int dy) {
	edit->defaultscrollContentsBy(dx, dy);
}

int bmx_qt_qtextedit_default_viewportevent(MaxQTextEdit * edit, QEvent * event) {
	static_cast<int>(edit->defaultviewportEvent(event));
}

// QFrame
// QWidget
void bmx_qt_qtextedit_default_actionevent(MaxQTextEdit * edit, QActionEvent * event) {
	edit->defaultactionEvent(event);
}

void bmx_qt_qtextedit_default_changeevent(MaxQTextEdit * edit, QEvent * event) {
	edit->defaultchangeEvent(event);
}

void bmx_qt_qtextedit_default_closeevent(MaxQTextEdit * edit, QCloseEvent * event) {
	edit->defaultcloseEvent(event);
}

void bmx_qt_qtextedit_default_contextmenuevent(MaxQTextEdit * edit, QContextMenuEvent * event) {
	edit->defaultcontextMenuEvent(event);
}

void bmx_qt_qtextedit_default_dragenterevent(MaxQTextEdit * edit, QDragEnterEvent * event) {
	edit->defaultdragEnterEvent(event);
}

void bmx_qt_qtextedit_default_dragleaveevent(MaxQTextEdit * edit, QDragLeaveEvent * event) {
	edit->defaultdragLeaveEvent(event);
}

void bmx_qt_qtextedit_default_dragmoveevent(MaxQTextEdit * edit, QDragMoveEvent * event) {
	edit->defaultdragMoveEvent(event);
}

void bmx_qt_qtextedit_default_dropevent(MaxQTextEdit * edit, QDropEvent * event) {
	edit->defaultdropEvent(event);
}

void bmx_qt_qtextedit_default_enterevent(MaxQTextEdit * edit, QEvent * event) {
	edit->defaultenterEvent(event);
}

void bmx_qt_qtextedit_default_focusinevent(MaxQTextEdit * edit, QFocusEvent * event) {
	edit->defaultfocusInEvent(event);
}

int bmx_qt_qtextedit_default_focusnextprevchild(MaxQTextEdit * edit, int next) {
	return static_cast<int>(edit->defaultfocusNextPrevChild(static_cast<bool>(next)));
}

int bmx_qt_qtextedit_default_focusnextchild(MaxQTextEdit * edit) {
	return static_cast<int>(edit->defaultfocusNextChild());
}

void bmx_qt_qtextedit_default_focusoutevent(MaxQTextEdit * edit, QFocusEvent * event) {
	edit->defaultfocusOutEvent(event);
}

int bmx_qt_qtextedit_default_focuspreviouschild(MaxQTextEdit * edit) {
	return static_cast<int>(edit->defaultfocusPreviousChild());
}

void bmx_qt_qtextedit_default_hideevent(MaxQTextEdit * edit, QHideEvent * event) {
	edit->defaulthideEvent(event);
}

void bmx_qt_qtextedit_default_inputmethodevent(MaxQTextEdit * edit, QInputMethodEvent * event) {
	edit->defaultinputMethodEvent(event);
}

void bmx_qt_qtextedit_default_keypressevent(MaxQTextEdit * edit, QKeyEvent * event) {
	edit->defaultkeyPressEvent(event);
}

void bmx_qt_qtextedit_default_keyreleaseevent(MaxQTextEdit * edit, QKeyEvent * event) {
	edit->defaultkeyReleaseEvent(event);
}

void bmx_qt_qtextedit_default_leaveevent(MaxQTextEdit * edit, QEvent * event) {
	edit->defaultleaveEvent(event);
}

void bmx_qt_qtextedit_default_mousedoubleclickevent(MaxQTextEdit * edit, QMouseEvent * event) {
	edit->defaultmouseDoubleClickEvent(event);
}

void bmx_qt_qtextedit_default_mousemoveevent(MaxQTextEdit * edit, QMouseEvent * event) {
	edit->defaultmouseMoveEvent(event);
}

void bmx_qt_qtextedit_default_mousepressevent(MaxQTextEdit * edit, QMouseEvent * event) {
	edit->defaultmousePressEvent(event);
}

void bmx_qt_qtextedit_default_mousereleaseevent(MaxQTextEdit * edit, QMouseEvent * event) {
	edit->defaultmouseReleaseEvent(event);
}

void bmx_qt_qtextedit_default_moveevent(MaxQTextEdit * edit, QMoveEvent * event) {
	edit->defaultmoveEvent(event);
}

void bmx_qt_qtextedit_default_paintevent(MaxQTextEdit * edit, QPaintEvent * event) {
	edit->defaultpaintEvent(event);
}

void bmx_qt_qtextedit_default_resizeevent(MaxQTextEdit * edit, QResizeEvent * event) {
	edit->defaultresizeEvent(event);
}

void bmx_qt_qtextedit_default_showevent(MaxQTextEdit * edit, QShowEvent * event) {
	edit->defaultshowEvent(event);
}

void bmx_qt_qtextedit_default_tabletevent(MaxQTextEdit * edit, QTabletEvent * event) {
	edit->defaulttabletEvent(event);
}

void bmx_qt_qtextedit_default_wheelevent(MaxQTextEdit * edit, QWheelEvent * event) {
	edit->defaultwheelEvent(event);
}

// QObject
int bmx_qt_qtextedit_default_event(MaxQTextEdit * edit, QEvent * event) {
	return static_cast<int>(edit->defaultevent(event));
}

void bmx_qt_qtextedit_default_timerevent(MaxQTextEdit * edit, QTimerEvent * event) {
	edit->defaulttimerEvent(event);
}


// *********************************************

QTextEdit::AutoFormatting bmx_qt_qtexteditautoformattingfromint(int f) {
	QTextEdit::AutoFormatting formatting;

	if (f & 0x00000001) formatting |= QTextEdit::AutoBulletList;
	if (f & 0xffffffff) formatting |= QTextEdit::AutoAll;

	return formatting;
}

QTextEdit::LineWrapMode bmx_qt_qtexteditlinewrapmodefromint(int m) {
	switch(m) {
		case 0:
			return QTextEdit::NoWrap;
		case 1:
			return QTextEdit::WidgetWidth;
		case 2:
			return QTextEdit::FixedPixelWidth;
		case 3:
			return QTextEdit::FixedColumnWidth;
	}
	
	return QTextEdit::NoWrap;
}

// *********************************************

QTextEdit * bmx_qt_qtextedit_create(BBObject * handle, QWidget * parent) {
	return new MaxQTextEdit(handle, parent);
}

void bmx_qt_qtextedit_setreadonly(QTextEdit * edit, int value) {
	edit->setReadOnly(static_cast<bool>(value));
}


void bmx_qt_qtextedit_append(QTextEdit * edit, BBString * text) {
	edit->append(qStringFromBBString(text));
}


void bmx_qt_qtextedit_clear(QTextEdit * edit) {
	edit->clear();
}


void bmx_qt_qtextedit_copy(QTextEdit * edit) {
	edit->copy();
}


void bmx_qt_qtextedit_cut(QTextEdit * edit) {
	edit->cut();
}


void bmx_qt_qtextedit_inserthtml(QTextEdit * edit, BBString * text) {
	edit->insertHtml(qStringFromBBString(text));
}


void bmx_qt_qtextedit_insertplaintext(QTextEdit * edit, BBString * text) {
	edit->insertPlainText(qStringFromBBString(text));
}


void bmx_qt_qtextedit_paste(QTextEdit * edit) {
	edit->paste();
}


void bmx_qt_qtextedit_redo(QTextEdit * edit) {
	edit->redo();
}


void bmx_qt_qtextedit_scrolltoanchor(QTextEdit * edit, BBString * name) {
	edit->scrollToAnchor(qStringFromBBString(name));
}


void bmx_qt_qtextedit_selectall(QTextEdit * edit) {
	edit->selectAll();
}


void bmx_qt_qtextedit_setalignment(QTextEdit * edit, int a) {
	edit->setAlignment(bmx_qt_getalignment(a));
}


void bmx_qt_qtextedit_setcurrentfont(QTextEdit * edit, MaxQFont * f) {
	edit->setCurrentFont(f->Font());
}


void bmx_qt_qtextedit_setfontfamily(QTextEdit * edit, BBString * fontFamily) {
	edit->setFontFamily(qStringFromBBString(fontFamily));
}


void bmx_qt_qtextedit_setfontitalic(QTextEdit * edit, int italic) {
	edit->setFontItalic(static_cast<bool>(italic));
}


void bmx_qt_qtextedit_setfontpointsize(QTextEdit * edit, double s) {
	edit->setFontPointSize(s);
}


void bmx_qt_qtextedit_setfontunderline(QTextEdit * edit, int underline) {
	edit->setFontUnderline(static_cast<bool>(underline));
}


void bmx_qt_qtextedit_setfontweight(QTextEdit * edit, int weight) {
	edit->setFontWeight(weight);
}


void bmx_qt_qtextedit_sethtml(QTextEdit * edit, BBString * text) {
	edit->setHtml(qStringFromBBString(text));
}


void bmx_qt_qtextedit_setplaintext(QTextEdit * edit, BBString * text) {
	edit->setPlainText(qStringFromBBString(text));
}


void bmx_qt_qtextedit_settext(QTextEdit * edit, BBString * text) {
	edit->setText(qStringFromBBString(text));
}


void bmx_qt_qtextedit_settextbackgroundcolor(QTextEdit * edit, MaxQColor * c) {
	edit->setTextBackgroundColor(c->Color());
}


void bmx_qt_qtextedit_settextcolor(QTextEdit * edit, MaxQColor * c) {
	edit->setTextColor(c->Color());
}


void bmx_qt_qtextedit_undo(QTextEdit * edit) {
	edit->undo();
}


void bmx_qt_qtextedit_zoomin(QTextEdit * edit, int _range) {
	edit->zoomIn(_range);
}


void bmx_qt_qtextedit_zoomout(QTextEdit * edit, int _range) {
	edit->zoomOut(_range);
}

BBString * bmx_qt_qtextedit_tohtml(QTextEdit * edit) {
	return bbStringFromQString(edit->toHtml());
}

BBString * bmx_qt_qtextedit_toplaintext(QTextEdit * edit) {
	return bbStringFromQString(edit->toPlainText());
}

QTextDocument * bmx_qt_qtextedit_document(QTextEdit * edit) {
	QTextDocument * doc = edit->document();
	MaxQTextDocument::link(doc);
	return doc;
}

void bmx_qt_qtextedit_setacceptrichtext(QTextEdit * edit, int accept) {
	edit->setAcceptRichText(static_cast<bool>(accept));
}

void bmx_qt_qtextedit_setautoformatting(QTextEdit * edit, int features) {
	edit->setAutoFormatting(bmx_qt_qtexteditautoformattingfromint(features));
}

void bmx_qt_qtextedit_setcursorwidth(QTextEdit * edit, int width) {
	edit->setCursorWidth(width);
}

void bmx_qt_qtextedit_setdocumenttitle(QTextEdit * edit, BBString * title) {
	edit->setDocumentTitle(qStringFromBBString(title));
}

void bmx_qt_qtextedit_setlinewrapcolumnorwidth(QTextEdit * edit, int w) {
	edit->setLineWrapColumnOrWidth(w);
}

void bmx_qt_qtextedit_setlinewrapmode(QTextEdit * edit, int mode) {
	edit->setLineWrapMode(bmx_qt_qtexteditlinewrapmodefromint(mode));
}

int bmx_qt_qtextedit_acceptrichtext(QTextEdit * edit) {
	return static_cast<int>(edit->acceptRichText());
}

int bmx_qt_qtextedit_alignment(QTextEdit * edit) {
	return static_cast<int>(edit->alignment());
}

BBString * bmx_qt_qtextedit_anchorat(QTextEdit * edit, int x, int y) {
	return bbStringFromQString(edit->anchorAt(QPoint(x, y)));
}

int bmx_qt_qtextedit_autoformatting(QTextEdit * edit) {
	return static_cast<int>(edit->autoFormatting());
}

int bmx_qt_qtextedit_canpaste(QTextEdit * edit) {
	return static_cast<int>(edit->canPaste());
}

MaxQTextCharFormat * bmx_qt_qtextedit_currentcharformat(QTextEdit * edit) {
	return new MaxQTextCharFormat(edit->currentCharFormat());
}

MaxQFont * bmx_qt_qtextedit_currentfont(QTextEdit * edit) {
	return new MaxQFont(edit->currentFont());
}

MaxQTextCursor * bmx_qt_qtextedit_cursorforposition(QTextEdit * edit, int x, int y) {
	return new MaxQTextCursor(edit->cursorForPosition(QPoint(x, y)));
}

int bmx_qt_qtextedit_cursorwidth(QTextEdit * edit) {
	return edit->cursorWidth();
}

BBString * bmx_qt_qtextedit_documenttitle(QTextEdit * edit) {
	return bbStringFromQString(edit->documentTitle());
}

void bmx_qt_qtextedit_ensurecursorvisible(QTextEdit * edit) {
	edit->ensureCursorVisible();
}

int bmx_qt_qtextedit_find(QTextEdit * edit, BBString * expr, int options) {
	return static_cast<int>(edit->find(qStringFromBBString(expr), bmx_qt_intToDocumentFindFlags(options)));
}

BBString * bmx_qt_qtextedit_fontfamily(QTextEdit * edit) {
	return bbStringFromQString(edit->fontFamily());
}

int bmx_qt_qtextedit_fontitalic(QTextEdit * edit) {
	return static_cast<int>(edit->fontItalic());
}

double bmx_qt_qtextedit_fontpointsize(QTextEdit * edit) {
	return edit->fontPointSize();
}

int bmx_qt_qtextedit_fontunderline(QTextEdit * edit) {
	return static_cast<int>(edit->fontUnderline());
}

int bmx_qt_qtextedit_fontweight(QTextEdit * edit) {
	return edit->fontWeight();
}

int bmx_qt_qtextedit_isreadonly(QTextEdit * edit) {
	return static_cast<int>(edit->isReadOnly());
}

int bmx_qt_qtextedit_isundoredoenabled(QTextEdit * edit) {
	return static_cast<int>(edit->isUndoRedoEnabled());
}

int bmx_qt_qtextedit_linewrapcolumnorwidth(QTextEdit * edit) {
	return edit->lineWrapColumnOrWidth();
}

int bmx_qt_qtextedit_linewrapmode(QTextEdit * edit) {
	return static_cast<int>(edit->lineWrapMode());
}

void bmx_qt_qtextedit_mergecurrentcharformat(QTextEdit * edit, MaxQTextCharFormat * modifier) {
	return edit->mergeCurrentCharFormat(modifier->Format());
}

int bmx_qt_qtextedit_overwritemode(QTextEdit * edit) {
	return static_cast<int>(edit->overwriteMode());
}

int bmx_qt_qtextedit_tabstopwidth(QTextEdit * edit) {
	return edit->tabStopWidth();
}

MaxQColor * bmx_qt_qtextedit_textbackgroundcolor(QTextEdit * edit) {
	return new MaxQColor(edit->textBackgroundColor());
}

MaxQColor * bmx_qt_qtextedit_textcolor(QTextEdit * edit) {
	return new MaxQColor(edit->textColor());
}

MaxQTextCursor * bmx_qt_qtextedit_textcursor(QTextEdit * edit) {
	return new MaxQTextCursor(edit->textCursor());
}

void bmx_qt_qtextedit_settabchangesfocus(QTextEdit * edit, int value) {
	edit->setTabChangesFocus(static_cast<bool>(value));
}

void bmx_qt_qtextedit_settabstopwidth(QTextEdit * edit, int width) {
	edit->setTabStopWidth(width);
}

void bmx_qt_qtextedit_settextcursor(QTextEdit * edit, MaxQTextCursor * cursor) {
	edit->setTextCursor(cursor->Cursor());
}

void bmx_qt_qtextedit_settextinteractionflags(QTextEdit * edit, int flags) {
	edit->setTextInteractionFlags(bmx_qt_inttotextinteractionflags(flags));
}

void bmx_qt_qtextedit_setundoredoenabled(QTextEdit * edit, int enable) {
	edit->setUndoRedoEnabled(static_cast<bool>(enable));
}

void bmx_qt_qtextedit_setwordwrapmode(QTextEdit * edit, int policy) {
	edit->setWordWrapMode(bmx_qt_intToTextOptionWrapMode(policy));
}

int bmx_qt_qtextedit_tabchangesfocus(QTextEdit * edit) {
	return static_cast<int>(edit->tabChangesFocus());	
}



// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
