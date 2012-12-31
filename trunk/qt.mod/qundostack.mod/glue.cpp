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

MaxQUndoStack::MaxQUndoStack(BBObject * handle, QObject * parent)
	: maxHandle(handle), QUndoStack(parent)
{
	qbind(this, handle);
}

MaxQUndoStack::~MaxQUndoStack()
{
	qunbind(this);
}

void MaxQUndoStack::onCanRedoChanged(bool canRedo) {

}

void MaxQUndoStack::onCanUndoChanged(bool canUndo) {

}

void MaxQUndoStack::onCleanChanged(bool clean) {

}

void MaxQUndoStack::onIndexChanged(int idx) {

}

void MaxQUndoStack::onRedoTextChanged(const QString & redoText) {

}

void MaxQUndoStack::onUndoTextChanged(const QString & undoText) {

}


// *********************************************

QUndoStack * bmx_qt_qundostack_create(BBObject * handle, QObject * parent) {
	return new MaxQUndoStack(handle, parent);
}

void bmx_qt_qundostack_beginmacro(QUndoStack * us, BBString * text) {
	us->beginMacro(qStringFromBBString(text));
}

int bmx_qt_qundostack_canredo(QUndoStack * us) {
	return static_cast<int>(us->canRedo());
}

int bmx_qt_qundostack_canundo(QUndoStack * us) {
	return static_cast<int>(us->canUndo());
}

int bmx_qt_qundostack_cleanindex(QUndoStack * us) {
	return us->cleanIndex();
}

void bmx_qt_qundostack_clear(QUndoStack * us) {
	us->clear();
}

const QUndoCommand * bmx_qt_qundostack_command(QUndoStack * us, int index) {
	return us->command(index);
}

int bmx_qt_qundostack_count(QUndoStack * us) {
	return us->count();
}

QAction * bmx_qt_qundostack_createredoaction(QUndoStack * us, QObject * parent, BBString * prefix) {
	QAction * action = us->createRedoAction(parent, qStringFromBBString(prefix));
	MaxQAction::link(action);
	return action;
}

QAction * bmx_qt_qundostack_createundoaction(QUndoStack * us, QObject * parent, BBString * prefix) {
	QAction * action = us->createUndoAction(parent, qStringFromBBString(prefix));
	MaxQAction::link(action);
	return action;
}

void bmx_qt_qundostack_endmacro(QUndoStack * us) {
	us->endMacro();
}

int bmx_qt_qundostack_index(QUndoStack * us) {
	return us->index();
}

int bmx_qt_qundostack_isactive(QUndoStack * us) {
	return static_cast<int>(us->isActive());
}

int bmx_qt_qundostack_isclean(QUndoStack * us) {
	return static_cast<int>(us->isClean());
}

void bmx_qt_qundostack_push(QUndoStack * us, QUndoCommand * cmd) {
	us->push(cmd);
}

BBString * bmx_qt_qundostack_redotext(QUndoStack * us) {
	return bbStringFromQString(us->redoText());
}

void bmx_qt_qundostack_setundolimit(QUndoStack * us, int limit) {
	us->setUndoLimit(limit);
}

BBString * bmx_qt_qundostack_text(QUndoStack * us, int idx) {
	return bbStringFromQString(us->text(idx));
}

int bmx_qt_qundostack_undolimit(QUndoStack * us) {
	return us->undoLimit();
}

BBString * bmx_qt_qundostack_undotext(QUndoStack * us) {
	return bbStringFromQString(us->undoText());
}

void bmx_qt_qundostack_redo(QUndoStack * us) {
	us->redo();
}

void bmx_qt_qundostack_setactive(QUndoStack * us, int active) {
	us->setActive(static_cast<bool>(active));
}

void bmx_qt_qundostack_setclean(QUndoStack * us) {
	us->setClean();
}

void bmx_qt_qundostack_setindex(QUndoStack * us, int idx) {
	us->setIndex(idx);
}

void bmx_qt_qundostack_undo(QUndoStack * us) {
	us->undo();
}



// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
