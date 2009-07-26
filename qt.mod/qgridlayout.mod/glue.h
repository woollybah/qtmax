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

#ifndef BMX_QT_QGRIDLAYOUT
#define BMX_QT_QGRIDLAYOUT

#include "../core.mod/glue.h"
#include <QtCore>
#include <QGridLayout>

class MaxQGridLayout;

extern "C" {

#include <blitz.h>

	QGridLayout * bmx_qt_qgridlayout_create(BBObject * handle, QWidget * parent);
	void bmx_qt_qgridlayout_addlayout(QGridLayout * grid, QLayout * layout, int row, int column, int alignment);
	void bmx_qt_qgridlayout_addwidget(QGridLayout * grid, QWidget * widget, int row, int column, int alignment);
	void bmx_qt_qgridlayout_addwidgetspan(QGridLayout * grid, QWidget * widget, int fromRow, int fromColumn,  int rowSpan, int columnSpan, int alignment);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQGridLayout : public QGridLayout
{
public:
	MaxQGridLayout(BBObject * handle);
	MaxQGridLayout(BBObject * handle, QWidget * parent);
	~MaxQGridLayout();

private:
	BBObject * maxHandle;
};

#endif
