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

#ifndef MAX_QT_QSLIDER
#define MAX_QT_QSLIDER

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include "../qabstractslider.mod/glue.h"
#include <QtCore>
#include <QSlider>

class MaxQSlider;

extern "C" {

#include <blitz.h>

	QSlider * bmx_qt_qslider_create(BBObject * handle, int orientation, QWidget * parent);
	void bmx_qt_qslider_settickinterval(QSlider * slider, int interval);
	void bmx_qt_qslider_settickposition(QSlider * slider, int position);
	int bmx_qt_qslider_tickinterval(QSlider * slider);
	int bmx_qt_qslider_tickposition(QSlider * slider);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQSlider : public QSlider
{
	Q_OBJECT
	
public:
	MaxQSlider(BBObject * handle, Qt::Orientation orientation, QWidget * parent);
	~MaxQSlider();

private:
	BBObject * maxHandle;

private slots:
	void onActionTriggered(int action);
	void onRangeChanged(int min, int max);
	void onSliderMoved(int value);
	void onSliderPressed();
	void onSliderReleased();
	void onValueChanged(int value);
	void onCustomContextMenuRequested(const QPoint & pos);
};

#endif
