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

#ifndef MAX_QT_QDIAL
#define MAX_QT_QDIAL

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include "../qabstractslider.mod/glue.h"
#include <QtCore>
#include <QDial>

class MaxQDial;

extern "C" {

#include <blitz.h>


	QDial * bmx_qt_qdial_create(BBObject * handle, QWidget * parent);
	int bmx_qt_qdial_notchsize(QDial * dial);
	double bmx_qt_qdial_notchtarget(QDial * dial);
	int bmx_qt_qdial_notchesvisible(QDial * dial);
	void bmx_qt_qdial_setnotchtarget(QDial * dial, double target);
	int bmx_qt_qdial_wrapping(QDial * dial);
	void bmx_qt_qdial_setnotchesvisible(QDial * dial, int visible);
	void bmx_qt_qdial_setwrapping(QDial * dial, int on);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQDial : public QDial
{
	Q_OBJECT
	
public:
	MaxQDial(BBObject * handle, QWidget * parent);
	~MaxQDial();

private slots:
	void onActionTriggered(int action);
	void onRangeChanged(int min, int max);
	void onSliderMoved(int value);
	void onSliderPressed();
	void onSliderReleased();
	void onValueChanged(int value);
	void onCustomContextMenuRequested(const QPoint & pos);
	
private:
	BBObject * maxHandle;
};

#endif
