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



void MaxQTextEdit::defaultChangeEvent(QEvent * e) {
	QTextEdit::changeEvent(e);
}

void MaxQTextEdit::defaultContextMenuEvent(QContextMenuEvent * event) {
	QTextEdit::contextMenuEvent(event);
}

void MaxQTextEdit::defaultDragEnterEvent(QDragEnterEvent * e) {
	QTextEdit::dragEnterEvent(e);
}

void MaxQTextEdit::defaultDragLeaveEvent(QDragLeaveEvent * e) {
	QTextEdit::dragLeaveEvent(e);
}

void MaxQTextEdit::defaultDragMoveEvent(QDragMoveEvent * e) {
	QTextEdit::dragMoveEvent(e);
}

void MaxQTextEdit::defaultDropEvent(QDropEvent * e) {
	QTextEdit::dropEvent(e);
}

void MaxQTextEdit::defaultFocusInEvent(QFocusEvent * e) {
	QTextEdit::focusInEvent(e);
}

bool MaxQTextEdit::defaultFocusNextPrevChild(bool next) {
	return QTextEdit::focusNextPrevChild(next);
}

void MaxQTextEdit::defaultFocusOutEvent(QFocusEvent * e) {
	QTextEdit::focusOutEvent(e);
}

void MaxQTextEdit::defaultInputMethodEvent(QInputMethodEvent * e) {
	QTextEdit::inputMethodEvent(e);
}

void MaxQTextEdit::defaultKeyPressEvent(QKeyEvent * e) {
	QTextEdit::keyPressEvent(e);
}

void MaxQTextEdit::defaultKeyReleaseEvent(QKeyEvent * e) {
	QTextEdit::keyReleaseEvent(e);
}

void MaxQTextEdit::defaultMouseDoubleClickEvent(QMouseEvent * e) {
	QTextEdit::mouseDoubleClickEvent(e);
}

void MaxQTextEdit::defaultMouseMoveEvent(QMouseEvent * e) {
	QTextEdit::mouseMoveEvent(e);
}

void MaxQTextEdit::defaultMousePressEvent(QMouseEvent * e) {
	QTextEdit::mousePressEvent(e);
}

void MaxQTextEdit::defaultMouseReleaseEvent(QMouseEvent * e) {
	QTextEdit::mouseReleaseEvent(e);
}

void MaxQTextEdit::defaultPaintEvent(QPaintEvent * event) {
	QTextEdit::paintEvent(event);
}

void MaxQTextEdit::defaultResizeEvent(QResizeEvent * e) {
	QTextEdit::resizeEvent(e);
}

void MaxQTextEdit::defaultScrollContentsBy(int dx, int dy) {
	QTextEdit::scrollContentsBy(dx, dy);
}

void MaxQTextEdit::defaultShowEvent(QShowEvent * e) {
	QTextEdit::showEvent(e);
}

void MaxQTextEdit::defaultWheelEvent(QWheelEvent * e) {
	QTextEdit::wheelEvent(e);
}


void MaxQTextEdit::changeEvent(QEvent * e) {
	_qt_qwidget_QWidget__OnChangeEvent(maxHandle, e);
}

void MaxQTextEdit::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__OnContextMenuEvent(maxHandle, event);
}

void MaxQTextEdit::dragEnterEvent(QDragEnterEvent * e) {
	_qt_qwidget_QWidget__OnDragEnterEvent(maxHandle, e);
}

void MaxQTextEdit::dragLeaveEvent(QDragLeaveEvent * e) {
	_qt_qwidget_QWidget__OnDragLeaveEvent(maxHandle, e);
}

void MaxQTextEdit::dragMoveEvent(QDragMoveEvent * e) {
	_qt_qwidget_QWidget__OnDragMoveEvent(maxHandle, e);
}

void MaxQTextEdit::dropEvent(QDropEvent * e) {
	_qt_qwidget_QWidget__OnDropEvent(maxHandle, e);
}

void MaxQTextEdit::focusInEvent(QFocusEvent * e) {
	_qt_qwidget_QWidget__OnFocusInEvent(maxHandle, e);
}

bool MaxQTextEdit::focusNextPrevChild(bool next) {
	return _qt_qwidget_QWidget__OnFocusNextPrevChild(maxHandle, next);
}

void MaxQTextEdit::focusOutEvent(QFocusEvent * e) {
	_qt_qwidget_QWidget__OnFocusOutEvent(maxHandle, e);
}

void MaxQTextEdit::inputMethodEvent(QInputMethodEvent * e) {
	_qt_qwidget_QWidget__OnInputMethodEvent(maxHandle, e);
}

void MaxQTextEdit::keyPressEvent(QKeyEvent * e) {
	_qt_qwidget_QWidget__OnKeyPressEvent(maxHandle, e);
}

void MaxQTextEdit::keyReleaseEvent(QKeyEvent * e) {
	_qt_qwidget_QWidget__OnKeyReleaseEvent(maxHandle, e);
}

void MaxQTextEdit::mouseDoubleClickEvent(QMouseEvent * e) {
	_qt_qwidget_QWidget__OnMouseDoubleClickEvent(maxHandle, e);
}

void MaxQTextEdit::mouseMoveEvent(QMouseEvent * e) {
	_qt_qwidget_QWidget__OnMouseMoveEvent(maxHandle, e);
}

void MaxQTextEdit::mousePressEvent(QMouseEvent * e) {
	_qt_qwidget_QWidget__OnMousePressEvent(maxHandle, e);
}

void MaxQTextEdit::mouseReleaseEvent(QMouseEvent * e) {
	_qt_qwidget_QWidget__OnMouseReleaseEvent(maxHandle, e);
}

void MaxQTextEdit::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__OnPaintEvent(maxHandle, event);
}

void MaxQTextEdit::resizeEvent(QResizeEvent * e) {
	_qt_qwidget_QWidget__OnResizeEvent(maxHandle, e);
}

void MaxQTextEdit::scrollContentsBy(int dx, int dy) {
	_qt_qabstractscrollarea_QAbstractScrollArea__OnScrollContentsBy(maxHandle, dx, dy);
}

void MaxQTextEdit::showEvent(QShowEvent * e) {
	_qt_qwidget_QWidget__OnShowEvent(maxHandle, e);
}

void MaxQTextEdit::wheelEvent(QWheelEvent * e) {
	_qt_qwidget_QWidget__OnWheelEvent(maxHandle, e);
}

void MaxQTextEdit::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
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

// *********************************************

void bmx_qt_qtextedit_default_changeevent(MaxQTextEdit * edit, QEvent * event) {
	edit->defaultChangeEvent(event);
}

void bmx_qt_qtextedit_default_contextmenuevent(MaxQTextEdit * edit, QContextMenuEvent * event) {
	edit->defaultContextMenuEvent(event);
}

void bmx_qt_qtextedit_default_dragenterevent(MaxQTextEdit * edit, QDragEnterEvent * event) {
	edit->defaultDragEnterEvent(event);
}

void bmx_qt_qtextedit_default_dragleaveevent(MaxQTextEdit * edit, QDragLeaveEvent * event) {
	edit->defaultDragLeaveEvent(event);
}

void bmx_qt_qtextedit_default_dragmoveevent(MaxQTextEdit * edit, QDragMoveEvent * event) {
	edit->defaultDragMoveEvent(event);
}

void bmx_qt_qtextedit_default_dropevent(MaxQTextEdit * edit, QDropEvent * event) {
	edit->defaultDropEvent(event);
}

void bmx_qt_qtextedit_default_focusinevent(MaxQTextEdit * edit, QFocusEvent * event) {
	edit->defaultFocusInEvent(event);
}

int bmx_qt_qtextedit_default_focusnextprevchild(MaxQTextEdit * edit, int next) {
	return static_cast<int>(edit->defaultFocusNextPrevChild(static_cast<bool>(next)));
}

void bmx_qt_qtextedit_default_focusoutevent(MaxQTextEdit * edit, QFocusEvent * event) {
	edit->defaultFocusOutEvent(event);
}

void bmx_qt_qtextedit_default_inputmethodevent(MaxQTextEdit * edit, QInputMethodEvent * event) {
	edit->defaultInputMethodEvent(event);
}

void bmx_qt_qtextedit_default_keypressevent(MaxQTextEdit * edit, QKeyEvent * event) {
	edit->defaultKeyPressEvent(event);
}

void bmx_qt_qtextedit_default_keyreleaseevent(MaxQTextEdit * edit, QKeyEvent * event) {
	edit->defaultKeyReleaseEvent(event);
}

void bmx_qt_qtextedit_default_mousedoubleclickevent(MaxQTextEdit * edit, QMouseEvent * event) {
	edit->defaultMouseDoubleClickEvent(event);
}

void bmx_qt_qtextedit_default_mousemoveevent(MaxQTextEdit * edit, QMouseEvent * event) {
	edit->defaultMouseMoveEvent(event);
}

void bmx_qt_qtextedit_default_mousepressevent(MaxQTextEdit * edit, QMouseEvent * event) {
	edit->defaultMousePressEvent(event);
}

void bmx_qt_qtextedit_default_mousereleaseevent(MaxQTextEdit * edit, QMouseEvent * event) {
	edit->defaultMouseReleaseEvent(event);
}

void bmx_qt_qtextedit_default_paintevent(MaxQTextEdit * edit, QPaintEvent * event) {
	edit->defaultPaintEvent(event);
}

void bmx_qt_qtextedit_default_resizeevent(MaxQTextEdit * edit, QResizeEvent * event) {
	edit->defaultResizeEvent(event);
}

void bmx_qt_qtextedit_default_scrollcontentsby(MaxQTextEdit * edit, int dx, int dy) {
	edit->defaultScrollContentsBy(dx, dy);
}

void bmx_qt_qtextedit_default_wheelevent(MaxQTextEdit * edit, QWheelEvent * event) {
	edit->defaultWheelEvent(event);
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
