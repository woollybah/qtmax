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

#ifndef MAX_QT_ template
#define MAX_QT_ template

#include "../core.mod/glue.h"
#include <QtCore>
#include <QFileInfo>

class MaxQFileInfo;

extern "C" {

#include <blitz.h>

	MaxQFileInfo * bmx_qt_qfileinfo_create(BBString * file);
	MaxQFileInfo * bmx_qt_qfileinfo_createfile(QFile * file);
	void bmx_qt_qfileinfo_free(MaxQFileInfo * info);
	BBString * bmx_qt_qfileinfo_absolutefilepath(MaxQFileInfo * info);
	BBString * bmx_qt_qfileinfo_absolutepath(MaxQFileInfo * info);
	BBString * bmx_qt_qfileinfo_basename(MaxQFileInfo * info);
	BBString * bmx_qt_qfileinfo_bundlename(MaxQFileInfo * info);
	int bmx_qt_qfileinfo_caching(MaxQFileInfo * info);
	BBString * bmx_qt_qfileinfo_canonicalfilepath(MaxQFileInfo * info);
	BBString * bmx_qt_qfileinfo_canonicalpath(MaxQFileInfo * info);
	BBString * bmx_qt_qfileinfo_completebasename(MaxQFileInfo * info);
	BBString * bmx_qt_qfileinfo_completesuffix(MaxQFileInfo * info);
	int bmx_qt_qfileinfo_exists(MaxQFileInfo * info);
	BBString * bmx_qt_qfileinfo_filename(MaxQFileInfo * info);
	BBString * bmx_qt_qfileinfo_filepath(MaxQFileInfo * info);
	BBString * bmx_qt_qfileinfo_group(MaxQFileInfo * info);
	uint bmx_qt_qfileinfo_groupid(MaxQFileInfo * info);
	int bmx_qt_qfileinfo_isabsolute(MaxQFileInfo * info);
	int bmx_qt_qfileinfo_isbundle(MaxQFileInfo * info);
	int bmx_qt_qfileinfo_isdir(MaxQFileInfo * info);
	int bmx_qt_qfileinfo_isexecutable(MaxQFileInfo * info);
	int bmx_qt_qfileinfo_isfile(MaxQFileInfo * info);
	int bmx_qt_qfileinfo_ishidden(MaxQFileInfo * info);
	int bmx_qt_qfileinfo_isreadable(MaxQFileInfo * info);
	int bmx_qt_qfileinfo_isrelative(MaxQFileInfo * info);
	int bmx_qt_qfileinfo_isroot(MaxQFileInfo * info);
	int bmx_qt_qfileinfo_issymlink(MaxQFileInfo * info);
	int bmx_qt_qfileinfo_iswritable(MaxQFileInfo * info);


}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQFileInfo
{
public:
	MaxQFileInfo(const QFileInfo & i);
	~MaxQFileInfo();
	
	QFileInfo & Info();

private:
	QFileInfo info;
};

#endif
