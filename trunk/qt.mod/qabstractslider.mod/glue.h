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

#ifndef MAX_QT_QABSTRACTSLIDER
#define MAX_QT_QABSTRACTSLIDER

#include "../core.mod/glue.h"
#include <QtCore>
#include <QAbstractSlider>

extern "C" {

#include <blitz.h>

	void _qt_qabstractslider_QAbstractSlider__OnActionTriggered(BBObject * handle, int action);
	void _qt_qabstractslider_QAbstractSlider__OnRangeChanged(BBObject * handle, int min, int max);
	void _qt_qabstractslider_QAbstractSlider__OnSliderMoved(BBObject * handle, int value);
	void _qt_qabstractslider_QAbstractSlider__OnSliderPressed(BBObject * handle);
	void _qt_qabstractslider_QAbstractSlider__OnSliderReleased(BBObject * handle);
	void _qt_qabstractslider_QAbstractSlider__OnValueChanged(BBObject * handle, int value);

	int bmx_qt_qabstractslider_hastracking(QAbstractSlider * slider);
	int bmx_qt_qabstractslider_invertedappearance(QAbstractSlider * slider);
	int bmx_qt_qabstractslider_invertedcontrols(QAbstractSlider * slider);
	int bmx_qt_qabstractslider_issliderdown(QAbstractSlider * slider);
	int bmx_qt_qabstractslider_maximum(QAbstractSlider * slider);
	int bmx_qt_qabstractslider_minimum(QAbstractSlider * slider);
	int bmx_qt_qabstractslider_orientation(QAbstractSlider * slider);
	int bmx_qt_qabstractslider_pagestep(QAbstractSlider * slider);
	void bmx_qt_qabstractslider_setinvertedappearance(QAbstractSlider * slider, int value);
	void bmx_qt_qabstractslider_setinvertedcontrols(QAbstractSlider * slider, int value);
	void bmx_qt_qabstractslider_setmaximum(QAbstractSlider * slider, int value);
	void bmx_qt_qabstractslider_setminimum(QAbstractSlider * slider, int value);
	void bmx_qt_qabstractslider_setpagestep(QAbstractSlider * slider, int value);
	void bmx_qt_qabstractslider_setrange(QAbstractSlider * slider, int minimum, int maximum);
	void bmx_qt_qabstractslider_setsinglestep(QAbstractSlider * slider, int value);
	void bmx_qt_qabstractslider_setsliderdown(QAbstractSlider * slider, int value);
	void bmx_qt_qabstractslider_setsliderposition(QAbstractSlider * slider, int value);
	void bmx_qt_qabstractslider_settracking(QAbstractSlider * slider, int enable);
	int bmx_qt_qabstractslider_singlestep(QAbstractSlider * slider);
	int bmx_qt_qabstractslider_sliderposition(QAbstractSlider * slider);
	void bmx_qt_qabstractslider_triggeraction(QAbstractSlider * slider, int sliderAction);
	int bmx_qt_qabstractslider_value(QAbstractSlider * slider);
	void bmx_qt_qabstractslider_setorientation(QAbstractSlider * slider, int orientation);
	void bmx_qt_qabstractslider_setvalue(QAbstractSlider * slider, int value);
	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif
