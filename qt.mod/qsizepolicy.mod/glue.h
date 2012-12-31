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

#ifndef MAX_QT_QSIZEPOLICY
#define MAX_QT_QSIZEPOLICY

#include "../core.mod/glue.h"
#include <QtCore>
#include <QSizePolicy>

class MaxQSizePolicy;

extern "C" {

#include <blitz.h>

	int bmx_qt_qsizepolicy_controltype(MaxQSizePolicy * sp);
	int bmx_qt_qsizepolicy_expandingdirections(MaxQSizePolicy * sp);
	int bmx_qt_qsizepolicy_hasheightforwidth(MaxQSizePolicy * sp);
	int bmx_qt_qsizepolicy_horizontalpolicy(MaxQSizePolicy * sp);
	int bmx_qt_qsizepolicy_horizontalstretch(MaxQSizePolicy * sp);
	void bmx_qt_qsizepolicy_setcontroltype(MaxQSizePolicy * sp, int controlType);
	void bmx_qt_qsizepolicy_setheightforwidth(MaxQSizePolicy * sp, int dependent);
	void bmx_qt_qsizepolicy_sethorizontalpolicy(MaxQSizePolicy * sp, int policy);
	void bmx_qt_qsizepolicy_sethorizontalstretch(MaxQSizePolicy * sp, int stretchFactor);
	void bmx_qt_qsizepolicy_setverticalpolicy(MaxQSizePolicy * sp, int policy);
	void bmx_qt_qsizepolicy_setverticalstretch(MaxQSizePolicy * sp, int stretchFactor);
	void bmx_qt_qsizepolicy_transpose(MaxQSizePolicy * sp);
	int bmx_qt_qsizepolicy_verticalpolicy(MaxQSizePolicy * sp);
	int bmx_qt_qsizepolicy_verticalstretch(MaxQSizePolicy * sp);
	void bmx_qt_qsizepolicy_free(MaxQSizePolicy * sp);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQSizePolicy
{
public:
	MaxQSizePolicy(const QSizePolicy & p);
	~MaxQSizePolicy();

	QSizePolicy & Policy();

private:
	QSizePolicy policy;
};

#endif
