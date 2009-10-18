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

#ifndef MAX_QT_QUNDOSTACK
#define MAX_QT_QUNDOSTACK

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QUndoStack>

class MaxQUndoStack;

extern "C" {

#include <blitz.h>

	QUndoStack * bmx_qt_qundostack_create(BBObject * handle, QObject * parent);
	void bmx_qt_qundostack_beginmacro(QUndoStack * us, BBString * text);
	int bmx_qt_qundostack_canredo(QUndoStack * us);
	int bmx_qt_qundostack_canundo(QUndoStack * us);
	int bmx_qt_qundostack_cleanindex(QUndoStack * us);
	void bmx_qt_qundostack_clear(QUndoStack * us);
	const QUndoCommand * bmx_qt_qundostack_command(QUndoStack * us, int index);
	int bmx_qt_qundostack_count(QUndoStack * us);
	QAction * bmx_qt_qundostack_createredoaction(QUndoStack * us, QObject * parent, BBString * prefix);
	QAction * bmx_qt_qundostack_createundoaction(QUndoStack * us, QObject * parent, BBString * prefix);
	void bmx_qt_qundostack_endmacro(QUndoStack * us);
	int bmx_qt_qundostack_index(QUndoStack * us);
	int bmx_qt_qundostack_isactive(QUndoStack * us);
	int bmx_qt_qundostack_isclean(QUndoStack * us);
	void bmx_qt_qundostack_push(QUndoStack * us, QUndoCommand * cmd);
	BBString * bmx_qt_qundostack_redotext(QUndoStack * us);
	void bmx_qt_qundostack_setundolimit(QUndoStack * us, int limit);
	BBString * bmx_qt_qundostack_text(QUndoStack * us, int idx);
	int bmx_qt_qundostack_undolimit(QUndoStack * us);
	BBString * bmx_qt_qundostack_undotext(QUndoStack * us);
	void bmx_qt_qundostack_redo(QUndoStack * us);
	void bmx_qt_qundostack_setactive(QUndoStack * us, int active);
	void bmx_qt_qundostack_setclean(QUndoStack * us);
	void bmx_qt_qundostack_setindex(QUndoStack * us, int idx);
	void bmx_qt_qundostack_undo(QUndoStack * us);

	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQUndoStack : public QUndoStack
{
public:
	MaxQUndoStack(BBObject * handle, QObject * parent);
	~MaxQUndoStack();

private:
	BBObject * maxHandle;

private slots:
	void onCanRedoChanged(bool canRedo);
	void onCanUndoChanged(bool canUndo);
	void onCleanChanged(bool clean);
	void onIndexChanged(int idx);
	void onRedoTextChanged(const QString & redoText);
	void onUndoTextChanged(const QString & undoText);
};

#endif
