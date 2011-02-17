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

MaxQTextDocument::MaxQTextDocument(BBObject * handle, QTextDocument * doc)
	: document(doc), MaxQObjectWrapper(handle, doc)
{
	doConnections();
}

MaxQTextDocument::MaxQTextDocument(QTextDocument * doc)
	: document(doc), MaxQObjectWrapper(doc)
{
	maxHandle = _qt_qtextdocument_QTextDocument__create(doc);
	qbind(doc, maxHandle);

	doConnections();
}

QTextDocument * MaxQTextDocument::Document() {
	return document;
}

void MaxQTextDocument::link(QTextDocument * doc) {
	BBObject * handle = qfind(doc);
	
	if (handle == &bbNullObject) {
		MaxQTextDocument * document = new MaxQTextDocument(doc);
	}
}

MaxQTextDocument::~MaxQTextDocument()
{
}

void MaxQTextDocument::doConnections() {
	connect(document, SIGNAL(blockCountChanged(int)), SLOT(onBlockCountChanged(int)));
	connect(document, SIGNAL(contentsChange(int, int, int)), SLOT(onContentsChange(int, int, int)));
	connect(document, SIGNAL(contentsChanged()), SLOT(onContentsChanged()));
	connect(document, SIGNAL(cursorPositionChanged(const QTextCursor &)), SLOT(onCursorPositionChanged(const QTextCursor &)));
	connect(document, SIGNAL(documentLayoutChanged()), SLOT(onDocumentLayoutChanged()));
	connect(document, SIGNAL(modificationChanged(bool)), SLOT(onModificationChanged(bool)));
	connect(document, SIGNAL(redoAvailable(bool)), SLOT(onRedoAvailable(bool)));
	connect(document, SIGNAL(undoAvailable(bool)), SLOT(onUndoAvailable(bool)));
	connect(document, SIGNAL(undoCommandAdded()), SLOT(onUndoCommandAdded()));
}

void MaxQTextDocument::onBlockCountChanged(int newBlockCount) {
	_qt_qtextdocument_QTextDocument__OnBlockCountChanged(maxHandle, newBlockCount);
}

void MaxQTextDocument::onContentsChange(int position, int charsRemoved, int charsAdded) {
	_qt_qtextdocument_QTextDocument__OnContentsChange(maxHandle, position, charsRemoved, charsAdded);
}

void MaxQTextDocument::onContentsChanged() {
	_qt_qtextdocument_QTextDocument__OnContentsChanged(maxHandle);
}

void MaxQTextDocument::onCursorPositionChanged(const QTextCursor & cursor) {
	_qt_qtextdocument_QTextDocument__OnCursorPositionChanged(maxHandle, new MaxQTextCursor(cursor));
}

void MaxQTextDocument::onDocumentLayoutChanged() {
	_qt_qtextdocument_QTextDocument__OnDocumentLayoutChanged(maxHandle);
}

void MaxQTextDocument::onModificationChanged(bool changed) {
	_qt_qtextdocument_QTextDocument__OnModificationChanged(maxHandle, static_cast<int>(changed));
}

void MaxQTextDocument::onRedoAvailable(bool available) {
	_qt_qtextdocument_QTextDocument__OnRedoAvailable(maxHandle, static_cast<int>(available));
}

void MaxQTextDocument::onUndoAvailable(bool available) {
	_qt_qtextdocument_QTextDocument__OnUndoAvailable(maxHandle, static_cast<int>(available));
}

void MaxQTextDocument::onUndoCommandAdded() {
	_qt_qtextdocument_QTextDocument__OnUndoCommandAdded(maxHandle);
}

// ---------------------------------------------------------------------------------------

MaxQTextCursor::MaxQTextCursor(const QTextCursor & c)
	: cursor(c)
{
}

MaxQTextCursor::~MaxQTextCursor()
{
}

QTextCursor & MaxQTextCursor::Cursor() {
	return cursor;
}

// ---------------------------------------------------------------------------------------
/*
MaxQTextFormat::MaxQTextFormat(const QTextFormat & f)
	: format(f)
{
}

MaxQTextFormat::~MaxQTextFormat()
{
}

QTextFormat & MaxQTextFormat::Format() {
	return format;
}
*/
// ---------------------------------------------------------------------------------------

MaxQTextOption::MaxQTextOption(const QTextOption & o)
	: option(o)
{
}

MaxQTextOption::~MaxQTextOption()
{
}

QTextOption & MaxQTextOption::Option() {
	return option;
}

// ---------------------------------------------------------------------------------------

MaxQTextBlock::MaxQTextBlock(const QTextBlock & b)
	: block(b)
{
}

MaxQTextBlock::~MaxQTextBlock()
{
}

QTextBlock & MaxQTextBlock::Block() {
	return block;
}


// *********************************************

double bmx_qt_qtextdocument_idealwidth(QTextDocument * doc) {
	return doc->idealWidth();
}

double bmx_qt_qtextdocument_indentewidth(QTextDocument * doc) {
	return doc->indentWidth();
}

int bmx_qt_qtextdocument_isempty(QTextDocument * doc) {
	return static_cast<int>(doc->isEmpty());
}

int bmx_qt_qtextdocument_ismodified(QTextDocument * doc) {
	return static_cast<int>(doc->isModified());
}

int bmx_qt_qtextdocument_isredoavailable(QTextDocument * doc) {
	return static_cast<int>(doc->isRedoAvailable());
}

int bmx_qt_qtextdocument_isundoavailable(QTextDocument * doc) {
	return static_cast<int>(doc->isUndoAvailable());
}

int bmx_qt_qtextdocument_isundoredoenabled(QTextDocument * doc) {
	return static_cast<int>(doc->isUndoRedoEnabled());
}

MaxQTextBlock * bmx_qt_qtextdocument_lastblock(QTextDocument * doc) {
	return new MaxQTextBlock(doc->lastBlock());
}

int bmx_qt_qtextdocument_linecount(QTextDocument * doc) {
	return doc->lineCount();
}

void bmx_qt_qtextdocument_markcontentsdirty(QTextDocument * doc, int position, int length) {
	doc->markContentsDirty(position, length);
}

int bmx_qt_qtextdocument_maximumblockcount(QTextDocument * doc) {
	return doc->maximumBlockCount();
}

BBString * bmx_qt_qtextdocument_metainformation(QTextDocument * doc, int info) {
	return bbStringFromQString(doc->metaInformation((QTextDocument::MetaInformation)info));
}

QTextObject * bmx_qt_qtextdocument_object(QTextDocument * doc, int objectIndex) {
	return doc->object(objectIndex);
}

QTextObject * bmx_qt_qtextdocument_objectforformat(QTextDocument * doc, MaxQTextFormat * f) {
	return doc->objectForFormat(f->Format());
}

int bmx_qt_qtextdocument_pagecount(QTextDocument * doc) {
	return doc->pageCount();
}

void bmx_qt_qtextdocument_pagesize(QTextDocument * doc, double * w, double * h) {
	QSizeF s(doc->pageSize());
	*w = s.width();
	*h = s.height();
}

void bmx_qt_qtextdocument_print(QTextDocument * doc, QPrinter * printer) {
	doc->print(printer);
}

void bmx_qt_qtextdocument_redo(QTextDocument * doc, MaxQTextCursor * cursor) {
	if (cursor) {
		doc->redo(&cursor->Cursor());
	} else {
		doc->redo();
	}
}

int bmx_qt_qtextdocument_revision(QTextDocument * doc) {
	return doc->revision();
}

QTextFrame * bmx_qt_qtextdocument_rootframe(QTextDocument * doc) {
	return doc->rootFrame();
}

void bmx_qt_qtextdocument_setdefaultfont(QTextDocument * doc, MaxQFont * font) {
	doc->setDefaultFont(font->Font());
}

void bmx_qt_qtextdocument_setdefaultstylesheet(QTextDocument * doc, BBString* sheet) {
	doc->setDefaultStyleSheet(qStringFromBBString(sheet));
}

void bmx_qt_qtextdocument_setdefaulttextoption(QTextDocument * doc, MaxQTextOption * option) {
	doc->setDefaultTextOption(option->Option());
}

void bmx_qt_qtextdocument_setdocumentlayout(QTextDocument * doc, QAbstractTextDocumentLayout * layout) {
	doc->setDocumentLayout(layout);
}

void bmx_qt_qtextdocument_setdocumentmargin(QTextDocument * doc, double margin) {
	doc->setDocumentMargin(margin);
}

void bmx_qt_qtextdocument_sethtml(QTextDocument * doc, BBString * html) {
	doc->setHtml(qStringFromBBString(html));
}

void bmx_qt_qtextdocument_setindentwidth(QTextDocument * doc, double width) {
	doc->setIndentWidth(width);
}

void bmx_qt_qtextdocument_setmaximumblockcount(QTextDocument * doc, int maximum) {
	doc->setMaximumBlockCount(maximum);
}

void bmx_qt_qtextdocument_setmetainformation(QTextDocument * doc, int info, BBString * text) {
	doc->setMetaInformation((QTextDocument::MetaInformation)info, qStringFromBBString(text));
}

void bmx_qt_qtextdocument_setpagesize(QTextDocument * doc, double w, double h) {
	doc->setPageSize(QSizeF(w, h));
}

void bmx_qt_qtextdocument_setplaintext(QTextDocument * doc, BBString * text) {
	doc->setPlainText(qStringFromBBString(text));
}

void bmx_qt_qtextdocument_settextwidth(QTextDocument * doc, double width) {
	doc->setTextWidth(width);
}

void bmx_qt_qtextdocument_setundoredoenabled(QTextDocument * doc, int enable) {
	doc->setUndoRedoEnabled(static_cast<bool>(enable));
}

void bmx_qt_qtextdocument_setusedesignmetrics(QTextDocument * doc, int b) {
	doc->setUseDesignMetrics(static_cast<bool>(b));
}

void bmx_qt_qtextdocument_size(QTextDocument * doc, double * w, double * h) {
	QSizeF s(doc->size());
	*w = s.width();
	*h = s.height();
}

double  bmx_qt_qtextdocument_textwidth(QTextDocument * doc) {
	return doc->textWidth();
}

BBString * bmx_qt_qtextdocument_toplaintext(QTextDocument * doc) {
	return bbStringFromQString(doc->toPlainText());
}

void bmx_qt_qtextdocument_undo(QTextDocument * doc, MaxQTextCursor * cursor) {
	if (cursor) {
		doc->undo(&cursor->Cursor());
	} else {
		doc->undo();
	}
}

int bmx_qt_qtextdocument_usedesignmetrics(QTextDocument * doc) {
	return static_cast<int>(doc->useDesignMetrics());
}

void bmx_qt_qtextdocument_setmodified(QTextDocument * doc, int m) {
	doc->setModified(static_cast<bool>(m));
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
