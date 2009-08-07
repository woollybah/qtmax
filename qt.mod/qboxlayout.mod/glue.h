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
	void bmx_qt_qboxlayout_addlayout(QBoxLayout * layout, QLayout * lt, int stretch);
	void bmx_qt_qboxlayout_addspaceritem(QBoxLayout * layout, QSpacerItem * spacerItem);
	void bmx_qt_qboxlayout_addspacing(QBoxLayout * layout, int size);
	void bmx_qt_qboxlayout_addstrut(QBoxLayout * layout, int size);
	int bmx_qt_qboxlayout_direction(QBoxLayout * layout);
	void bmx_qt_qboxlayout_insertlayout(QBoxLayout * layout, int index, QLayout * lt, int stretch);
	void bmx_qt_qboxlayout_insertspaceritem(QBoxLayout * layout, int index, QSpacerItem * spacerItem);
	void bmx_qt_qboxlayout_insertspacing(QBoxLayout * layout, int index, int size);
	void bmx_qt_qboxlayout_insertstretch(QBoxLayout * layout, int index, int stretch);
	void bmx_qt_qboxlayout_insertwidget(QBoxLayout * layout, int index, QWidget * widget, int stretch, int alignment);
	void bmx_qt_qboxlayout_setdirection(QBoxLayout * layout, int direction);
	void bmx_qt_qboxlayout_setspacing(QBoxLayout * layout, int spacing);
	void bmx_qt_qboxlayout_setstretch(QBoxLayout * layout, int index, int stretch);
	int bmx_qt_qboxlayout_setstretchfactor(QBoxLayout * layout, QLayout * widget, int stretch);
	int bmx_qt_qboxlayout_setstretchfactorwidget(QBoxLayout * layout, QWidget * widget, int stretch);
	int bmx_qt_qboxlayout_spacing(QBoxLayout * layout);
	int bmx_qt_qboxlayout_stretch(QBoxLayout * layout, int index);

	
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
