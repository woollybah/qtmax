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

#include <QtCore>
#include <QUrl>

#include <map>

#ifndef BMX_QT_CORE
#define BMX_QT_CORE

class MaxQUrl;


extern "C" {

#include <blitz.h>

	void _qt_qobject_QObject__Free(BBObject * handle);

	void qbind( QObject *obj, BBObject *peer );
	void qunbind(QObject *obj);
	BBObject *qfind( QObject *obj );
	
	BBString *bbStringFromQString(const QString &s );
	QString qStringFromBBString(BBString * s);


	MaxQUrl * bmx_qt_qurl_create(BBString * url);
	void bmx_qt_qurl_free(MaxQUrl * url);


	Qt::WindowFlags bmx_qt_getwindowflags(int f);
	Qt::Alignment bmx_qt_getalignment(int a);
	Qt::FocusReason bmx_qt_getfocusreason(int r);
	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQUrl
{
public:

public:
	MaxQUrl(const QUrl & u);
	QUrl & Url();
	void SetUrl(const QUrl & u);

private:
	QUrl url;
};


#endif
