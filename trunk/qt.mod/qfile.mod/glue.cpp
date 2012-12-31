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

MaxQFile::MaxQFile(BBObject * handle, QFile * f)
	: file(f), MaxQObjectWrapper(handle, f)
{
	doConnections();
}

MaxQFile::MaxQFile(QFile * f)
	: file(f), MaxQObjectWrapper(f)
{
	maxHandle = _qt_qfile_QFile__create(file);
	qbind(file, maxHandle);

	doConnections();
}

QFile * MaxQFile::File() {
	return file;
}

void MaxQFile::link(QFile * f) {
	BBObject * handle = qfind(f);
	
	if (handle == &bbNullObject) {
		MaxQFile * file = new MaxQFile(f);
	}
}

MaxQFile::~MaxQFile()
{
}

void MaxQFile::doConnections() {
	connect(file, SIGNAL(aboutToClose()), SLOT(onAboutToClose()));
	connect(file, SIGNAL(bytesWritten(qint64)), SLOT(onBytesWritten(qint64)));
	connect(file, SIGNAL(readChannelFinished()), SLOT(onReadChannelFinished()));
	connect(file, SIGNAL(readyRead()), SLOT(onReadyRead()));
}

void MaxQFile::onAboutToClose() {
	_qt_qiodevice_QIODevice__OnAboutToClose(maxHandle);
}

void MaxQFile::onBytesWritten(qint64 bytes) {
	_qt_qiodevice_QIODevice__OnBytesWritten(maxHandle, bytes);
}

void MaxQFile::onReadChannelFinished() {
	_qt_qiodevice_QIODevice__OnReadChannelFinished(maxHandle);
}

void MaxQFile::onReadyRead() {
	_qt_qiodevice_QIODevice__OnReadyRead(maxHandle);
}


// *********************************************

QFile * bmx_qt_qfile_create(BBObject * handle, BBString * name) {
	MaxQFile * file = new MaxQFile(handle, new QFile(qStringFromBBString(name)));
	return file->File();
}

void bmx_qt_qfile_free(QFile * file) {
	delete file;
}

int bmx_qt_qfile_atend(QFile * file) {
	return static_cast<int>(file->atEnd());
}

void bmx_qt_qfile_close(QFile * file) {
	file->close();
}

int bmx_qt_qfile_copy(QFile * file, BBString * newName) {
	return static_cast<int>(file->copy(qStringFromBBString(newName)));
}

int bmx_qt_qfile_error(QFile * file) {
	return file->error();
}

int bmx_qt_qfile_exists(QFile * file) {
	return static_cast<int>(file->exists());
}

BBString * bmx_qt_qfile_filename(QFile * file) {
	return bbStringFromQString(file->fileName());
}

int bmx_qt_qfile_flush(QFile * file) {
	return static_cast<int>(file->flush());
}

int bmx_qt_qfile_handle(QFile * file) {
	return file->handle();
}

int bmx_qt_qfile_issequential(QFile * file) {
	return static_cast<int>(file->isSequential());
}

int bmx_qt_qfile_link(QFile * file, BBString * linkName) {
	return static_cast<int>(file->link(qStringFromBBString(linkName)));
}

uchar * bmx_qt_qfile_map(QFile * file, BBInt64 offset, BBInt64 size, int flags) {
	return file->map(offset, size, (QFile::MemoryMapFlags)flags);
}

int bmx_qt_qfile_open(QFile * file, int mode) {
	return static_cast<int>(file->open((QIODevice::OpenMode)mode));
}

int bmx_qt_qfile_openhandle(QFile * file, int h, int mode) {
	return static_cast<int>(file->open(h, (QIODevice::OpenMode)mode));
}

int bmx_qt_qfile_permissions(QFile * file) {
	return file->permissions();
}

int bmx_qt_qfile_remove(QFile * file) {
	return static_cast<int>(file->remove());
}

int bmx_qt_qfile_rename(QFile * file, BBString * newName) {
	return static_cast<int>(file->rename(qStringFromBBString(newName)));
}

int bmx_qt_qfile_resize(QFile * file, BBInt64 sz) {
	return static_cast<int>(file->resize(sz));
}

void bmx_qt_qfile_setfilename(QFile * file, BBString * name) {
	file->setFileName(qStringFromBBString(name));
}

int bmx_qt_qfile_setpermissions(QFile * file, int permissions) {
	return static_cast<int>(file->setPermissions((QFile::Permissions)permissions));
}

void bmx_qt_qfile_size(QFile * file, BBInt64 * s) {
	qint64 size = file->size();
	*s = size;
}

BBString * bmx_qt_qfile_symlinktarget(QFile * file) {
	return bbStringFromQString(file->symLinkTarget());
}

int bmx_qt_qfile_unmap(QFile * file, uchar * address) {
	return static_cast<int>(file->unmap(address));
}

void bmx_qt_qfile_unseterror(QFile * file) {
	file->unsetError();
}



// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
