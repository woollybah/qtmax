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

#ifndef MAX_QT_QTEXTDOCUMENT
#define MAX_QT_QTEXTDOCUMENT

#include "../core.mod/glue.h"
#include <QtCore>
#include <QTextDocument>
#include <QTextCursor>

class MaxQTextDocument;
class MaxQTextCursor;

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

class MaxQTextCursor
{
public:
	MaxQTextCursor(const QTextCursor & c);
	~MaxQTextCursor();
	
	QTextCursor & Cursor();

private:
	QTextCursor cursor;
};

#endif
