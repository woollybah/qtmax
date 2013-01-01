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

#ifndef MAX_QT_QTEXTDOCUMENT
#define MAX_QT_QTEXTDOCUMENT

#include "../core.mod/glue.h"
#include "../qfont.mod/glue.h"
#include "../qtextformat.mod/glue.h"
#include "../qtextframeformat.mod/glue.h"
#include "../qtextblockformat.mod/glue.h"
#include "../qtextcharformat.mod/glue.h"
#include "../qtextimageformat.mod/glue.h"
#include <QtCore>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextBlock>
#include <QTextOption>
#include <QTextDocumentFragment>

class MaxQTextDocument;
class MaxQTextCursor;
//class MaxQTextFormat;
class MaxQTextOption;
class MaxQTextBlock;
class MaxQTextDocumentFragment;

extern "C" {

#include <blitz.h>

	BBObject * _qt_qtextdocument_QTextDocument__create(QTextDocument * doc);
	
	void _qt_qtextdocument_QTextDocument__OnBlockCountChanged(BBObject * handle, int newBlockCount);
	void _qt_qtextdocument_QTextDocument__OnContentsChange(BBObject * handle, int position, int charsRemoved, int charsAdded);
	void _qt_qtextdocument_QTextDocument__OnContentsChanged(BBObject * handle);
	void _qt_qtextdocument_QTextDocument__OnCursorPositionChanged(BBObject * handle, MaxQTextCursor * cursor);
	void _qt_qtextdocument_QTextDocument__OnDocumentLayoutChanged(BBObject * handle);
	void _qt_qtextdocument_QTextDocument__OnModificationChanged(BBObject * handle, int changed);
	void _qt_qtextdocument_QTextDocument__OnRedoAvailable(BBObject * handle, int available);
	void _qt_qtextdocument_QTextDocument__OnUndoAvailable(BBObject * handle, int available);
	void _qt_qtextdocument_QTextDocument__OnUndoCommandAdded(BBObject * handle);

	double bmx_qt_qtextdocument_idealwidth(QTextDocument * doc);
	double bmx_qt_qtextdocument_indentewidth(QTextDocument * doc);
	int bmx_qt_qtextdocument_isempty(QTextDocument * doc);
	int bmx_qt_qtextdocument_ismodified(QTextDocument * doc);
	int bmx_qt_qtextdocument_isredoavailable(QTextDocument * doc);
	int bmx_qt_qtextdocument_isundoavailable(QTextDocument * doc);
	int bmx_qt_qtextdocument_isundoredoenabled(QTextDocument * doc);
	MaxQTextBlock * bmx_qt_qtextdocument_lastblock(QTextDocument * doc);
	int bmx_qt_qtextdocument_linecount(QTextDocument * doc);
	void bmx_qt_qtextdocument_markcontentsdirty(QTextDocument * doc, int position, int length);
	int bmx_qt_qtextdocument_maximumblockcount(QTextDocument * doc);
	BBString * bmx_qt_qtextdocument_metainformation(QTextDocument * doc, int info);
	QTextObject * bmx_qt_qtextdocument_object(QTextDocument * doc, int objectIndex);
	QTextObject * bmx_qt_qtextdocument_objectforformat(QTextDocument * doc, MaxQTextFormat * f);
	int bmx_qt_qtextdocument_pagecount(QTextDocument * doc);
	void bmx_qt_qtextdocument_pagesize(QTextDocument * doc, double * w, double * h);
	void bmx_qt_qtextdocument_print(QTextDocument * doc, QPrinter * printer);
	void bmx_qt_qtextdocument_redo(QTextDocument * doc, MaxQTextCursor * cursor);
	int bmx_qt_qtextdocument_revision(QTextDocument * doc);
	QTextFrame * bmx_qt_qtextdocument_rootframe(QTextDocument * doc);
	void bmx_qt_qtextdocument_setdefaultfont(QTextDocument * doc, MaxQFont * font);
	void bmx_qt_qtextdocument_setdefaultstylesheet(QTextDocument * doc, BBString* sheet);
	void bmx_qt_qtextdocument_setdefaulttextoption(QTextDocument * doc, MaxQTextOption * option);
	void bmx_qt_qtextdocument_setdocumentlayout(QTextDocument * doc, QAbstractTextDocumentLayout * layout);
	void bmx_qt_qtextdocument_setdocumentmargin(QTextDocument * doc, double margin);
	void bmx_qt_qtextdocument_sethtml(QTextDocument * doc, BBString * html);
	void bmx_qt_qtextdocument_setindentwidth(QTextDocument * doc, double width);
	void bmx_qt_qtextdocument_setmaximumblockcount(QTextDocument * doc, int maximum);
	void bmx_qt_qtextdocument_setmetainformation(QTextDocument * doc, int info, BBString * text);
	void bmx_qt_qtextdocument_setpagesize(QTextDocument * doc, double w, double h);
	void bmx_qt_qtextdocument_setplaintext(QTextDocument * doc, BBString * text);
	void bmx_qt_qtextdocument_settextwidth(QTextDocument * doc, double width);
	void bmx_qt_qtextdocument_setundoredoenabled(QTextDocument * doc, int enable);
	void bmx_qt_qtextdocument_setusedesignmetrics(QTextDocument * doc, int b);
	void bmx_qt_qtextdocument_size(QTextDocument * doc, double * w, double * h);
	double  bmx_qt_qtextdocument_textwidth(QTextDocument * doc);
	BBString * bmx_qt_qtextdocument_toplaintext(QTextDocument * doc);
	void bmx_qt_qtextdocument_undo(QTextDocument * doc, MaxQTextCursor * cursor);
	int bmx_qt_qtextdocument_usedesignmetrics(QTextDocument * doc);
	void bmx_qt_qtextdocument_setmodified(QTextDocument * doc, int m);

	QTextDocument::FindFlags bmx_qt_intToDocumentFindFlags(int f);
	
	
	
	int bmx_qt_qtextcursor_anchor(MaxQTextCursor * cursor);
	int bmx_qt_qtextcursor_atblockend(MaxQTextCursor * cursor);
	int bmx_qt_qtextcursor_atblockstart(MaxQTextCursor * cursor);
	int bmx_qt_qtextcursor_atend(MaxQTextCursor * cursor);
	int bmx_qt_qtextcursor_atstart(MaxQTextCursor * cursor);
	void bmx_qt_qtextcursor_begineditblock(MaxQTextCursor * cursor);
	MaxQTextBlock * bmx_qt_qtextcursor_block(MaxQTextCursor * cursor);
	MaxQTextCharFormat * bmx_qt_qtextcursor_blockcharformat(MaxQTextCursor * cursor);
	MaxQTextBlockFormat * bmx_qt_qtextcursor_blockformat(MaxQTextCursor * cursor);
	int bmx_qt_qtextcursor_blocknumber(MaxQTextCursor * cursor);
	MaxQTextCharFormat * bmx_qt_qtextcursor_charformat(MaxQTextCursor * cursor);
	void bmx_qt_qtextcursor_clearselection(MaxQTextCursor * cursor);
	int bmx_qt_qtextcursor_columnnumber(MaxQTextCursor * cursor);
	void bmx_qt_qtextcursor_deletechar(MaxQTextCursor * cursor);
	void bmx_qt_qtextcursor_deletepreviouschar(MaxQTextCursor * cursor);
	void bmx_qt_qtextcursor_endeditblock(MaxQTextCursor * cursor);
	int bmx_qt_qtextcursor_hascomplexselection(MaxQTextCursor * cursor);
	int bmx_qt_qtextcursor_hasselection(MaxQTextCursor * cursor);
	void bmx_qt_qtextcursor_insertblock(MaxQTextCursor * cursor);
	void bmx_qt_qtextcursor_insertblockformat(MaxQTextCursor * cursor, MaxQTextBlockFormat * format);
	void bmx_qt_qtextcursor_insertblockcharformat(MaxQTextCursor * cursor, MaxQTextBlockFormat * format, MaxQTextCharFormat * charFormat);
	void bmx_qt_qtextcursor_insertfragment(MaxQTextCursor * cursor, MaxQTextDocumentFragment * fragment);
	void bmx_qt_qtextcursor_inserthtml(MaxQTextCursor * cursor, BBString * html);
	void bmx_qt_qtextcursor_insertimage(MaxQTextCursor * cursor, MaxQTextImageFormat * format);
	void bmx_qt_qtextcursor_insertimagealign(MaxQTextCursor * cursor, MaxQTextImageFormat * format, int alignment);
	void bmx_qt_qtextcursor_insertimagename(MaxQTextCursor * cursor, BBString * name);
	void bmx_qt_qtextcursor_insertimageimage(MaxQTextCursor * cursor, MaxQImage * image, BBString * name);
	void bmx_qt_qtextcursor_inserttext(MaxQTextCursor * cursor, BBString * text);
	void bmx_qt_qtextcursor_inserttextformat(MaxQTextCursor * cursor, BBString * text, MaxQTextCharFormat * format);
	int bmx_qt_qtextcursor_iscopyof(MaxQTextCursor * cursor, MaxQTextCursor * other);
	int bmx_qt_qtextcursor_isnull(MaxQTextCursor * cursor);
	void bmx_qt_qtextcursor_joinpreviouseditblock(MaxQTextCursor * cursor);
	int bmx_qt_qtextcursor_keeppositiononinsert(MaxQTextCursor * cursor);
	void bmx_qt_qtextcursor_mergeblockcharformat(MaxQTextCursor * cursor, MaxQTextCharFormat * modifier);
	void bmx_qt_qtextcursor_mergeblockformat(MaxQTextCursor * cursor, MaxQTextBlockFormat * modifier);
	void bmx_qt_qtextcursor_mergecharformat(MaxQTextCursor * cursor, MaxQTextCharFormat * modifier);
	int bmx_qt_qtextcursor_moveposition(MaxQTextCursor * cursor, int operation, int mode, int n);
	int bmx_qt_qtextcursor_position(MaxQTextCursor * cursor);
	int bmx_qt_qtextcursor_positioninblock(MaxQTextCursor * cursor);
	void bmx_qt_qtextcursor_removeselectedtext(MaxQTextCursor * cursor);
	void bmx_qt_qtextcursor_selecttext(MaxQTextCursor * cursor, int selection);
	BBString * bmx_qt_qtextcursor_selectedtext(MaxQTextCursor * cursor);
	MaxQTextDocumentFragment * bmx_qt_qtextcursor_selection(MaxQTextCursor * cursor);
	int bmx_qt_qtextcursor_selectionend(MaxQTextCursor * cursor);
	int bmx_qt_qtextcursor_selectionstart(MaxQTextCursor * cursor);
	void bmx_qt_qtextcursor_setblockcharformat(MaxQTextCursor * cursor, MaxQTextCharFormat * format);
	void bmx_qt_qtextcursor_setblockformat(MaxQTextCursor * cursor, MaxQTextBlockFormat * format);
	void bmx_qt_qtextcursor_setcharformat(MaxQTextCursor * cursor, MaxQTextCharFormat * format);
	void bmx_qt_qtextcursor_setkeepoisitiononinsert(MaxQTextCursor * cursor, int value);
	void bmx_qt_qtextcursor_setposition(MaxQTextCursor * cursor, int pos, int mode);
	void bmx_qt_qtextcursor_setverticalmovementx(MaxQTextCursor * cursor, int x);
	void bmx_qt_qtextcursor_setvisualnavigation(MaxQTextCursor * cursor, int value);
	int bmx_qt_qtextcursor_verticalmovementx(MaxQTextCursor * cursor);
	int bmx_qt_qtextcursor_visualnavigation(MaxQTextCursor * cursor);


	QTextCursor::SelectionType bmx_qt_intToCursorSelectionType(int t);
	QTextOption::WrapMode bmx_qt_intToTextOptionWrapMode(int m);
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQTextDocument : public MaxQObjectWrapper
{
	Q_OBJECT

public:
	MaxQTextDocument(BBObject * handle, QTextDocument * doc);
	MaxQTextDocument(QTextDocument * doc);
	
	QTextDocument * Document();
	
	static void link(QTextDocument * doc);
	
	~MaxQTextDocument();

private:
	void doConnections();
	QTextDocument * document;

private slots:
	void onBlockCountChanged(int newBlockCount);
	void onContentsChange(int position, int charsRemoved, int charsAdded);
	void onContentsChanged();
	void onCursorPositionChanged(const QTextCursor & cursor);
	void onDocumentLayoutChanged();
	void onModificationChanged(bool changed);
	void onRedoAvailable(bool available);
	void onUndoAvailable(bool available);
	void onUndoCommandAdded();
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQTextCursor
{
public:
	MaxQTextCursor(const QTextCursor & c);
	~MaxQTextCursor();
	
	QTextCursor & Cursor();

private:
	QTextCursor cursor;
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/*class MaxQTextFormat
{
public:
	MaxQTextFormat(const QTextFormat & f);
	~MaxQTextFormat();
	
	QTextFormat & Format();

private:
	QTextFormat format;
};*/

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQTextOption
{
public:
	MaxQTextOption(const QTextOption & o);
	~MaxQTextOption();
	
	QTextOption & Option();

private:
	QTextOption option;
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQTextBlock
{
public:
	MaxQTextBlock(const QTextBlock & b);
	~MaxQTextBlock();
	
	QTextBlock & Block();

private:
	QTextBlock block;
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQTextDocumentFragment
{
public:
	MaxQTextDocumentFragment(const QTextDocumentFragment & f);
	~MaxQTextDocumentFragment();
	
	QTextDocumentFragment & Fragment();

private:
	QTextDocumentFragment fragment;
};

#endif

