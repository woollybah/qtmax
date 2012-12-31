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

#ifndef MAX_QT_QWEBDATABASE
#define MAX_QT_QWEBDATABASE

#include "../core.mod/glue.h"
#include <QtCore>
#include <QWebSecurityOrigin>
#include <QWebDatabase>

class MaxQWebDatabase;
class MaxQWebSecurityOrigin;

extern "C" {

#include <blitz.h>

	BBString * bmx_qt_qwebdatabase_displayname(MaxQWebDatabase * db);
	void bmx_qt_qwebdatabase_expectedsize(MaxQWebDatabase * db, BBInt64 * value);
	BBString * bmx_qt_qwebdatabase_filename(MaxQWebDatabase * db);
	BBString * bmx_qt_qwebdatabase_name(MaxQWebDatabase * db);
	MaxQWebSecurityOrigin * bmx_qt_qwebdatabase_origin(MaxQWebDatabase * db);
	void bmx_qt_qwebdatabase_size(MaxQWebDatabase * db, BBInt64 * value);
	void bmx_qt_qwebdatabase_free(MaxQWebDatabase * db);

	void bmx_qt_qwebsecurityorigin_databasequota(MaxQWebSecurityOrigin * origin, BBInt64 * value);
	void bmx_qt_qwebsecurityorigin_databaseusage(MaxQWebSecurityOrigin * origin, BBInt64 * value);
	BBString * bmx_qt_qwebsecurityorigin_host(MaxQWebSecurityOrigin * origin);
	int bmx_qt_qwebsecurityorigin_port(MaxQWebSecurityOrigin * origin);
	BBString * bmx_qt_qwebsecurityorigin_scheme(MaxQWebSecurityOrigin * origin);
	void bmx_qt_qwebsecurityorigin_setdatabasequota(MaxQWebSecurityOrigin * origin, BBInt64 quota);
	void bmx_qt_qwebsecurityorigin_free(MaxQWebSecurityOrigin * origin);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQWebDatabase
{
public:
	MaxQWebDatabase(QWebDatabase & d);
	~MaxQWebDatabase();
	
	QWebDatabase & Database();

private:
	QWebDatabase database;
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQWebSecurityOrigin
{
public:
	MaxQWebSecurityOrigin(const QWebSecurityOrigin & o);
	~MaxQWebSecurityOrigin();
	
	QWebSecurityOrigin & Origin();

private:
	QWebSecurityOrigin origin;
};

#endif
