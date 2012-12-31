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

#ifndef MAX_QT_QFONTDATABASE
#define MAX_QT_QFONTDATABASE

#include "../core.mod/glue.h"
#include "../qfont.mod/glue.h"
#include "../qfontinfo.mod/glue.h"
#include <QtCore>
#include <QFontDatabase>

class MaxQFontDatabase;

extern "C" {

#include <blitz.h>

	MaxQFontDatabase * bmx_qt_qfontdatabase_create();
	int bmx_qt_qfontdatabase_bold(MaxQFontDatabase * db, BBString * family, BBString * style);
	BBArray * bmx_qt_qfontdatabase_families(MaxQFontDatabase * db, int writingSystem);
	MaxQFont * bmx_qt_qfontdatabase_font(MaxQFontDatabase * db, BBString * family, BBString * style, int pointSize);
	int bmx_qt_qfontdatabase_isbitmapscalable(MaxQFontDatabase * db, BBString * family, BBString * style);
	int bmx_qt_qfontdatabase_isfixedpitch(MaxQFontDatabase * db, BBString * family, BBString * style);
	int bmx_qt_qfontdatabase_isscalable(MaxQFontDatabase * db, BBString * family, BBString * style);
	int bmx_qt_qfontdatabase_issmoothlyscalable(MaxQFontDatabase * db, BBString * family, BBString * style);
	int bmx_qt_qfontdatabase_italic(MaxQFontDatabase * db, BBString * family, BBString * style);
	BBArray * bmx_qt_qfontdatabase_pointsizes(MaxQFontDatabase * db, BBString * family, BBString * style);
	BBArray * bmx_qt_qfontdatabase_smoothsizes(MaxQFontDatabase * db, BBString * family, BBString * style);
	BBString * bmx_qt_qfontdatabase_stylestring(MaxQFontDatabase * db, MaxQFont * font);
	BBString * bmx_qt_qfontdatabase_stylestringinfo(MaxQFontDatabase * db, MaxQFontInfo * fontInfo);
	BBArray * bmx_qt_qfontdatabase_styles(MaxQFontDatabase * db, BBString * family);
	int bmx_qt_qfontdatabase_weight(MaxQFontDatabase * db, BBString * family, BBString * style);
	BBArray * bmx_qt_qfontdatabase_writingsystems(MaxQFontDatabase * db, BBString * family);
	int bmx_qt_qfontdatabase_addapplicationfont(BBString * fileName);
	BBArray * bmx_qt_qfontdatabase_applicationfontfamilies(int id);
	int bmx_qt_qfontdatabase_removeallapplicationfonts();
	int bmx_qt_qfontdatabase_removeapplicationfont(int id);
	BBArray * bmx_qt_qfontdatabase_standardsizes();
	int bmx_qt_qfontdatabase_supportsthreadedfontrendering();
	BBString * bmx_qt_qfontdatabase_writingsystemname(int writingSystem);
	BBString * bmx_qt_qfontdatabase_writingsystemsample(int writingSystem);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQFontDatabase
{
public:
	MaxQFontDatabase(const QFontDatabase & d);
	~MaxQFontDatabase();
	
	QFontDatabase & Database();

private:
	QFontDatabase database;
};

#endif
