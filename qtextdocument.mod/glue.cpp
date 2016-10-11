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

// ---------------------------------------------------------------------------------------

MaxQTextDocumentFragment::MaxQTextDocumentFragment(const QTextDocumentFragment & f)
	: fragment(f)
{
}

MaxQTextDocumentFragment::~MaxQTextDocumentFragment()
{
}

QTextDocumentFragment & MaxQTextDocumentFragment::Fragment() {
	return fragment;
}


// *********************************************

QTextDocument::FindFlags bmx_qt_intToDocumentFindFlags(int f) {
	QTextDocument::FindFlags flags;
	
	if (f & 0x0001) flags |= QTextDocument::FindBackward;
	if (f & 0x0002) flags |= QTextDocument::FindCaseSensitively;
	if (f & 0x0004) flags |= QTextDocument::FindWholeWords;
	
	return flags;
}

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


// *********************************************

QTextCursor::SelectionType bmx_qt_intToCursorSelectionType(int t) {
	switch(t) {
		case 0:
			return QTextCursor::WordUnderCursor;
		case 1:
			return QTextCursor::LineUnderCursor;
		case 2:
			return QTextCursor::BlockUnderCursor;
		case 3:
			return QTextCursor::Document;
	}
	return QTextCursor::WordUnderCursor;
}

QTextCursor::MoveOperation bmx_qt_intToCursorMoveOperation(int o) {
	switch(o) {
		case 0:
			return QTextCursor::NoMove;
		case 1:
			return QTextCursor::Start;
		case 2:
			return QTextCursor::Up;
		case 3:
			return QTextCursor::StartOfLine;
		case 4:
			return QTextCursor::StartOfBlock;
		case 5:
			return QTextCursor::StartOfWord;
		case 6:
			return QTextCursor::PreviousBlock;
		case 7:
			return QTextCursor::PreviousCharacter;
		case 8:
			return QTextCursor::PreviousWord;
		case 9:
			return QTextCursor::Left;
		case 10:
			return QTextCursor::WordLeft;
		case 11:
			return QTextCursor::End;
		case 12:
			return QTextCursor::Down;
		case 13:
			return QTextCursor::EndOfLine;
		case 14:
			return QTextCursor::EndOfWord;
		case 15:
			return QTextCursor::EndOfBlock;
		case 16:
			return QTextCursor::NextBlock;
		case 17:
			return QTextCursor::NextCharacter;
		case 18:
			return QTextCursor::NextWord;
		case 19:
			return QTextCursor::Right;
		case 20:
			return QTextCursor::WordRight;
		case 21:
			return QTextCursor::NextCell;
		case 22:
			return QTextCursor::PreviousCell;
		case 23:
			return QTextCursor::NextRow;
		case 24:
			return QTextCursor::PreviousRow;		
	}
	
	return QTextCursor::NoMove;
}

QTextCursor::MoveMode bmx_qt_intToCursorMoveMode(int m) {
	switch(m) {
		case 0:
			return QTextCursor::MoveAnchor;
		case 1:
			return QTextCursor::KeepAnchor;
	}
	return QTextCursor::MoveAnchor;
}

int bmx_qt_qtextcursor_anchor(MaxQTextCursor * cursor) {
	return cursor->Cursor().anchor();
}

int bmx_qt_qtextcursor_atblockend(MaxQTextCursor * cursor) {
	return static_cast<int>(cursor->Cursor().atBlockEnd());
}

int bmx_qt_qtextcursor_atblockstart(MaxQTextCursor * cursor) {
	return static_cast<int>(cursor->Cursor().atBlockStart());
}

int bmx_qt_qtextcursor_atend(MaxQTextCursor * cursor) {
	return static_cast<int>(cursor->Cursor().atEnd());
}

int bmx_qt_qtextcursor_atstart(MaxQTextCursor * cursor) {
	return static_cast<int>(cursor->Cursor().atStart());
}

void bmx_qt_qtextcursor_begineditblock(MaxQTextCursor * cursor) {
	cursor->Cursor().beginEditBlock();
}

MaxQTextBlock * bmx_qt_qtextcursor_block(MaxQTextCursor * cursor) {
	return new MaxQTextBlock(cursor->Cursor().block());
}

MaxQTextCharFormat * bmx_qt_qtextcursor_blockcharformat(MaxQTextCursor * cursor) {
	return new MaxQTextCharFormat(cursor->Cursor().blockCharFormat());
}

MaxQTextBlockFormat * bmx_qt_qtextcursor_blockformat(MaxQTextCursor * cursor) {
	return new MaxQTextBlockFormat(cursor->Cursor().blockFormat());
}

int bmx_qt_qtextcursor_blocknumber(MaxQTextCursor * cursor) {
	return cursor->Cursor().blockNumber();
}

MaxQTextCharFormat * bmx_qt_qtextcursor_charformat(MaxQTextCursor * cursor) {
	return new MaxQTextCharFormat(cursor->Cursor().charFormat());
}

void bmx_qt_qtextcursor_clearselection(MaxQTextCursor * cursor) {
	cursor->Cursor().clearSelection();
}

int bmx_qt_qtextcursor_columnnumber(MaxQTextCursor * cursor) {
	return cursor->Cursor().columnNumber();
}

void bmx_qt_qtextcursor_deletechar(MaxQTextCursor * cursor) {
	cursor->Cursor().deleteChar();
}

void bmx_qt_qtextcursor_deletepreviouschar(MaxQTextCursor * cursor) {
	cursor->Cursor().deletePreviousChar();
}

void bmx_qt_qtextcursor_endeditblock(MaxQTextCursor * cursor) {
	cursor->Cursor().endEditBlock();
}

int bmx_qt_qtextcursor_hascomplexselection(MaxQTextCursor * cursor) {
	return static_cast<int>(cursor->Cursor().hasComplexSelection());
}

int bmx_qt_qtextcursor_hasselection(MaxQTextCursor * cursor) {
	return static_cast<int>(cursor->Cursor().hasSelection());
}

void bmx_qt_qtextcursor_insertblock(MaxQTextCursor * cursor) {
	cursor->Cursor().insertBlock();
}

void bmx_qt_qtextcursor_insertblockformat(MaxQTextCursor * cursor, MaxQTextBlockFormat * format) {
	cursor->Cursor().insertBlock(format->Format());
}

void bmx_qt_qtextcursor_insertblockcharformat(MaxQTextCursor * cursor, MaxQTextBlockFormat * format, MaxQTextCharFormat * charFormat) {
	cursor->Cursor().insertBlock(format->Format(), charFormat->Format());
}

void bmx_qt_qtextcursor_insertfragment(MaxQTextCursor * cursor, MaxQTextDocumentFragment * fragment) {
	cursor->Cursor().insertFragment(fragment->Fragment());
}

void bmx_qt_qtextcursor_inserthtml(MaxQTextCursor * cursor, BBString * html) {
	cursor->Cursor().insertHtml(qStringFromBBString(html));
}

void bmx_qt_qtextcursor_insertimage(MaxQTextCursor * cursor, MaxQTextImageFormat * format) {
	cursor->Cursor().insertImage(format->Format());
}

void bmx_qt_qtextcursor_insertimagealign(MaxQTextCursor * cursor, MaxQTextImageFormat * format, int alignment) {
	cursor->Cursor().insertImage(format->Format(), bmx_qt_intToFrameFormatPosition(alignment));
}

void bmx_qt_qtextcursor_insertimagename(MaxQTextCursor * cursor, BBString * name) {
	cursor->Cursor().insertImage(qStringFromBBString(name));
}

void bmx_qt_qtextcursor_insertimageimage(MaxQTextCursor * cursor, MaxQImage * image, BBString * name) {
	cursor->Cursor().insertImage(image->Image(), qStringFromBBString(name));
}

void bmx_qt_qtextcursor_inserttext(MaxQTextCursor * cursor, BBString * text) {
	cursor->Cursor().insertText(qStringFromBBString(text));
}

void bmx_qt_qtextcursor_inserttextformat(MaxQTextCursor * cursor, BBString * text, MaxQTextCharFormat * format) {
	cursor->Cursor().insertText(qStringFromBBString(text), format->Format());
}

int bmx_qt_qtextcursor_iscopyof(MaxQTextCursor * cursor, MaxQTextCursor * other) {
	return static_cast<int>(cursor->Cursor().isCopyOf(other->Cursor()));
}

int bmx_qt_qtextcursor_isnull(MaxQTextCursor * cursor) {
	return static_cast<int>(cursor->Cursor().isNull());
}

void bmx_qt_qtextcursor_joinpreviouseditblock(MaxQTextCursor * cursor) {
	cursor->Cursor().joinPreviousEditBlock();
}

int bmx_qt_qtextcursor_keeppositiononinsert(MaxQTextCursor * cursor) {
	return static_cast<int>(cursor->Cursor().keepPositionOnInsert());
}

void bmx_qt_qtextcursor_mergeblockcharformat(MaxQTextCursor * cursor, MaxQTextCharFormat * modifier) {
	cursor->Cursor().mergeBlockCharFormat(modifier->Format());
}

void bmx_qt_qtextcursor_mergeblockformat(MaxQTextCursor * cursor, MaxQTextBlockFormat * modifier) {
	cursor->Cursor().mergeBlockFormat(modifier->Format());
}

void bmx_qt_qtextcursor_mergecharformat(MaxQTextCursor * cursor, MaxQTextCharFormat * modifier) {
	cursor->Cursor().mergeCharFormat(modifier->Format());
}

int bmx_qt_qtextcursor_moveposition(MaxQTextCursor * cursor, int operation, int mode, int n) {
	return static_cast<int>(cursor->Cursor().movePosition(bmx_qt_intToCursorMoveOperation(operation), bmx_qt_intToCursorMoveMode(mode), n));
}

int bmx_qt_qtextcursor_position(MaxQTextCursor * cursor) {
	return cursor->Cursor().position();
}

int bmx_qt_qtextcursor_positioninblock(MaxQTextCursor * cursor) {
	return cursor->Cursor().positionInBlock();
}

void bmx_qt_qtextcursor_removeselectedtext(MaxQTextCursor * cursor) {
	cursor->Cursor().removeSelectedText();
}

void bmx_qt_qtextcursor_selecttext(MaxQTextCursor * cursor, int selection) {
	cursor->Cursor().select(bmx_qt_intToCursorSelectionType(selection));
}

BBString * bmx_qt_qtextcursor_selectedtext(MaxQTextCursor * cursor) {
	return bbStringFromQString(cursor->Cursor().selectedText());
}

MaxQTextDocumentFragment * bmx_qt_qtextcursor_selection(MaxQTextCursor * cursor) {
	return new MaxQTextDocumentFragment(cursor->Cursor().selection());
}

int bmx_qt_qtextcursor_selectionend(MaxQTextCursor * cursor) {
	return cursor->Cursor().selectionEnd();
}

int bmx_qt_qtextcursor_selectionstart(MaxQTextCursor * cursor) {
	return cursor->Cursor().selectionStart();
}

void bmx_qt_qtextcursor_setblockcharformat(MaxQTextCursor * cursor, MaxQTextCharFormat * format) {
	cursor->Cursor().setBlockCharFormat(format->Format());
}

void bmx_qt_qtextcursor_setblockformat(MaxQTextCursor * cursor, MaxQTextBlockFormat * format) {
	cursor->Cursor().setBlockFormat(format->Format());
}

void bmx_qt_qtextcursor_setcharformat(MaxQTextCursor * cursor, MaxQTextCharFormat * format) {
	cursor->Cursor().setCharFormat(format->Format());
}

void bmx_qt_qtextcursor_setkeepoisitiononinsert(MaxQTextCursor * cursor, int value) {
	cursor->Cursor().setKeepPositionOnInsert(static_cast<bool>(value));
}

void bmx_qt_qtextcursor_setposition(MaxQTextCursor * cursor, int pos, int mode) {
	cursor->Cursor().setPosition(pos, bmx_qt_intToCursorMoveMode(mode));
}

void bmx_qt_qtextcursor_setverticalmovementx(MaxQTextCursor * cursor, int x) {
	cursor->Cursor().setVerticalMovementX(x);
}

void bmx_qt_qtextcursor_setvisualnavigation(MaxQTextCursor * cursor, int value) {
	cursor->Cursor().setVisualNavigation(static_cast<bool>(value));
}

int bmx_qt_qtextcursor_verticalmovementx(MaxQTextCursor * cursor) {
	return cursor->Cursor().verticalMovementX();
}

int bmx_qt_qtextcursor_visualnavigation(MaxQTextCursor * cursor) {
	return static_cast<int>(cursor->Cursor().visualNavigation());
}

// *********************************************

QTextOption::WrapMode bmx_qt_intToTextOptionWrapMode(int m) {
	switch(m) {
		case 0:
			return QTextOption::NoWrap;
		case 1:
			return QTextOption::WordWrap;
		case 2:
			return QTextOption::ManualWrap;
		case 3:
			return QTextOption::WrapAnywhere;
		case 4:
			return QTextOption::WrapAtWordBoundaryOrAnywhere;
	}
	
	return QTextOption::NoWrap;
}



// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
