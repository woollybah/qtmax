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

#ifndef MAX_QT_QFILE
#define MAX_QT_QFILE

#include "../core.mod/glue.h"
#include "../qiodevice.mod/glue.h"
#include <QtCore>
#include <QFile>

class MaxQFile;

extern "C" {

#include <blitz.h>

	BBObject * _qt_qfile_QFile__create(QFile * file);

	QFile * bmx_qt_qfile_create(BBObject * handle, BBString * name);
	void bmx_qt_qfile_free(QFile * file);

	int bmx_qt_qfile_atend(QFile * file);
	void bmx_qt_qfile_close(QFile * file);
	int bmx_qt_qfile_copy(QFile * file, BBString * newName);
	int bmx_qt_qfile_error(QFile * file);
	int bmx_qt_qfile_exists(QFile * file);
	BBString * bmx_qt_qfile_filename(QFile * file);
	int bmx_qt_qfile_flush(QFile * file);
	int bmx_qt_qfile_handle(QFile * file);
	int bmx_qt_qfile_issequential(QFile * file);
	int bmx_qt_qfile_link(QFile * file, BBString * linkName);
	uchar * bmx_qt_qfile_map(QFile * file, BBInt64 offset, BBInt64 size, int flags);
	int bmx_qt_qfile_open(QFile * file, int mode);
	int bmx_qt_qfile_openhandle(QFile * file, int h, int mode);
	int bmx_qt_qfile_permissions(QFile * file);
	int bmx_qt_qfile_remove(QFile * file);
	int bmx_qt_qfile_rename(QFile * file, BBString * newName);
	int bmx_qt_qfile_resize(QFile * file, BBInt64 sz);
	void bmx_qt_qfile_setfilename(QFile * file, BBString * name);
	int bmx_qt_qfile_setpermissions(QFile * file, int permissions);
	void bmx_qt_qfile_size(QFile * file, BBInt64 * s);
	BBString * bmx_qt_qfile_symlinktarget(QFile * file);
	int bmx_qt_qfile_unmap(QFile * file, uchar * address);
	void bmx_qt_qfile_unseterror(QFile * file);
	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQFile : public MaxQObjectWrapper
{
	Q_OBJECT

public:
	MaxQFile(BBObject * handle, QFile * f);
	MaxQFile(QFile * f);

	QFile * File();
	
	static void link(QFile * f);

	~MaxQFile();

private:
	void doConnections();
	QFile * file;

private slots:
	void onAboutToClose();
	void onBytesWritten(qint64 bytes);
	void onReadChannelFinished();
	void onReadyRead();
};

#endif
