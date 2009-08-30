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

#ifndef MAX_QT_QLOCALE
#define MAX_QT_QLOCALE

#include "../core.mod/glue.h"
#include <QtCore>
#include <QLocale>

class MaxQLocale;

extern "C" {

#include <blitz.h>

	MaxQLocale * bmx_qt_qlocale_create(int language, int country);
	void bmx_qt_qlocale_free(MaxQLocale * locale);
	BBArray * bmx_qt_qlocale_countriesforlanguage(int language);
	BBString * bmx_qt_qlocale_countrytostring(int country);
	BBString * bmx_qt_qlocale_languagetostring(int language);
	BBString * bmx_qt_qlocale_amtext(MaxQLocale * locale);
	int bmx_qt_qlocale_country(MaxQLocale * locale);
	int bmx_qt_qlocale_language(MaxQLocale * locale);
	BBString * bmx_qt_qlocale_name(MaxQLocale * locale);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQLocale
{
public:
	MaxQLocale(const QLocale & l);
	~MaxQLocale();
	
	QLocale & Locale();

private:
	QLocale locale;
};

#endif
