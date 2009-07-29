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

#ifndef MAX_QT_QGRADIENT
#define MAX_QT_QGRADIENT

#include "../core.mod/glue.h"
#include "../qcolor.mod/glue.h"
#include <QtCore>
#include <QGradient>
#include <QConicalGradient>
#include <QLinearGradient>
#include <QRadialGradient>

class MaxQGradient;
class MaxQRadialGradient;

extern "C" {

#include <blitz.h>

	void bmx_qt_qgradient_setcolorat(MaxQGradient * gradient, double position, MaxQColor * color);

	MaxQRadialGradient * bmx_qt_qradialgradient_create(double cx, double cy, double radius, double fx, double fy);
	void bmx_qt_qradialgradient_center(MaxQRadialGradient * gradient, double * x, double * y);
	void bmx_qt_qradialgradient_focalpoint(MaxQRadialGradient * gradient, double * x, double * y);
	double bmx_qt_qradialgradient_radius(MaxQRadialGradient * gradient);
	void bmx_qt_qradialgradient_setcenter(MaxQRadialGradient * gradient, double x, double y);
	void bmx_qt_qradialgradient_setfocalpoint(MaxQRadialGradient * gradient, double x, double y);
	void bmx_qt_qradialgradient_setradius(MaxQRadialGradient * gradient, double radius);
	void bmx_qt_qradialgradient_free(MaxQRadialGradient * gradient);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQGradient
{
public:
	MaxQGradient() {};
	
	virtual QGradient & Gradient() {};
};

class MaxQRadialGradient : public MaxQGradient
{
public:
	MaxQRadialGradient(double cx, double cy, double radius, double fx, double fy);
	~MaxQRadialGradient();

	QGradient & Gradient();
	QRadialGradient & RadialGradient();
	
private:
	QRadialGradient gradient;
};

#endif
