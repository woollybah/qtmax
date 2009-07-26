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

#ifndef MAX_QT_QDOUBLEVALIDATOR
#define MAX_QT_QDOUBLEVALIDATOR

#include "../core.mod/glue.h"
#include <QtCore>
#include <QDoubleValidator>

class MaxQDoubleValidator;

extern "C" {

#include <blitz.h>

	QDoubleValidator * bmx_qt_qdoublevalidator_create(BBObject * handle, QObject * parent);
	QDoubleValidator * bmx_qt_qdoublevalidator_createwithrange(BBObject * handle, double bottom, double top, int decimals, QObject * parent);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQDoubleValidator : public QDoubleValidator
{
public:
	MaxQDoubleValidator(BBObject * handle, QObject * parent);
	MaxQDoubleValidator(BBObject * handle, double bottom, double top, int decimals, QObject * parent);
	~MaxQDoubleValidator();

private:
	BBObject * maxHandle;
};


#endif
