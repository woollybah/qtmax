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

#ifndef MAX_QT_QBOXLAYOUT
#define MAX_QT_QBOXLAYOUT

#include "../core.mod/glue.h"
#include <QtCore>
#include <QBoxLayout>

class MaxQBoxLayout;

extern "C" {

#include <blitz.h>

	QBoxLayout * bmx_qt_qboxlayout_create(BBObject * handle, QWidget * parent);
	QBoxLayout * bmx_qt_qboxlayout_createlayout(BBObject * handle, int dir, QWidget * parent);
	void bmx_qt_qboxlayout_addwidget(QBoxLayout * layout, QWidget * widget, int stretch, int alignment);
	void bmx_qt_qboxlayout_addstretch(QBoxLayout * layout, int stretch);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQBoxLayout : public QBoxLayout
{
public:
	MaxQBoxLayout(BBObject * handle, QBoxLayout::Direction dir, QWidget * parent);
	MaxQBoxLayout(BBObject * handle, QWidget * parent);
	~MaxQBoxLayout();

private:
	BBObject * maxHandle;
};

#endif
