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

#ifndef MAX_QT_QUNDOCOMMAND
#define MAX_QT_QUNDOCOMMAND

#include "../core.mod/glue.h"
#include <QtCore>
#include <QUndoCommand>

class MaxQUndoCommand;


extern "C" {

#include <blitz.h>

	void _qt_qundocommand_QUndoCommand__redo(BBObject * handle);
	void _qt_qundocommand_QUndoCommand__undo(BBObject * handle);
	int _qt_qundocommand_QUndoCommand__mergeWith(BBObject * handle, const QUndoCommand *command);
	int _qt_qundocommand_QUndoCommand__id(BBObject * handle);

	QUndoCommand * bmx_qt_qundocommand_new(BBObject * handle, QUndoCommand * parent);
	BBObject * bmx_qt_qundocommand_obj(QUndoCommand * handle);
	const QUndoCommand * bmx_qt_qundocommand_child(QUndoCommand * uc, int index);
	int bmx_qt_qundocommand_childcount(QUndoCommand * uc);
	int bmx_qt_qundocommand_id_default(QUndoCommand * uc);
	int bmx_qt_qundocommand_mergewith_default(QUndoCommand * uc, QUndoCommand * command);
	void bmx_qt_qundocommand_settext(QUndoCommand * uc, BBString * text);
	BBString * bmx_qt_qundocommand_text(QUndoCommand * uc);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQUndoCommand : public QUndoCommand
{
public:
	MaxQUndoCommand(BBObject * handle, QUndoCommand * parent);
	~MaxQUndoCommand();	

	BBObject * Handle();

	virtual void redo();
	virtual void undo();
	virtual bool mergeWith(const QUndoCommand * command);
	virtual int id() const;

	bool mergeWithDefault(const QUndoCommand * command);
	int idDefault() const;

private:
	BBObject * maxHandle;
};

#endif
