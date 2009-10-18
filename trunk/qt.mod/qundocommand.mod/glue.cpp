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

MaxQUndoCommand::MaxQUndoCommand(BBObject * handle, QUndoCommand * parent)
	: maxHandle(handle), QUndoCommand(parent)
{
	BBRETAIN(maxHandle);
}

MaxQUndoCommand::~MaxQUndoCommand()
{
	BBRELEASE(maxHandle);
}

BBObject * MaxQUndoCommand::Handle() {
	return maxHandle;
}

void MaxQUndoCommand::redo() {
	_qt_qundocommand_QUndoCommand__redo(maxHandle);
}

void MaxQUndoCommand::undo() {
	_qt_qundocommand_QUndoCommand__undo(maxHandle);
}

bool MaxQUndoCommand::mergeWith(const QUndoCommand * command) {
	return static_cast<bool>(_qt_qundocommand_QUndoCommand__mergeWith(maxHandle, command));
}

int MaxQUndoCommand::id() const {
	return _qt_qundocommand_QUndoCommand__id(maxHandle);
}

bool MaxQUndoCommand::mergeWithDefault(const QUndoCommand * command) {
	return QUndoCommand::mergeWith(command);
}

int MaxQUndoCommand::idDefault() const {
	return QUndoCommand::id();
}

// *********************************************

QUndoCommand * bmx_qt_qundocommand_new(BBObject * handle, QUndoCommand * parent) {
	return new MaxQUndoCommand(handle, parent);
}

BBObject * bmx_qt_qundocommand_obj(QUndoCommand * handle) {
	MaxQUndoCommand * cmd = static_cast<MaxQUndoCommand*>(handle);
	if (cmd) {
		return cmd->Handle();
	} else {
		return &bbNullObject;
	}
}

const QUndoCommand * bmx_qt_qundocommand_child(QUndoCommand * uc, int index) {
	return uc->child(index);
}

int bmx_qt_qundocommand_childcount(QUndoCommand * uc) {
	return uc->childCount();
}

int bmx_qt_qundocommand_id_default(QUndoCommand * uc) {
	MaxQUndoCommand * cmd = static_cast<MaxQUndoCommand*>(uc);
	if (cmd) {
		return cmd->idDefault();
	} else {
		return uc->id();
	}
}

int bmx_qt_qundocommand_mergewith_default(QUndoCommand * uc, QUndoCommand * command) {
	MaxQUndoCommand * cmd = static_cast<MaxQUndoCommand*>(uc);
	if (cmd) {
		return cmd->mergeWithDefault(command);
	} else {
		return uc->mergeWith(command);
	}
}

void bmx_qt_qundocommand_settext(QUndoCommand * uc, BBString * text) {
	uc->setText(qStringFromBBString(text));
}

BBString * bmx_qt_qundocommand_text(QUndoCommand * uc) {
	return bbStringFromQString(uc->text());
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
