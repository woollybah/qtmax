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

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
