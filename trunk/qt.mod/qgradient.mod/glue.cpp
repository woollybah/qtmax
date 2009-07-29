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

#include "glue.h"

// ---------------------------------------------------------------------------------------


MaxQRadialGradient::MaxQRadialGradient(double cx, double cy, double radius, double fx, double fy)
	: gradient(QPointF(cx, cy), radius, QPointF(fx, fy))
{
}

MaxQRadialGradient::~MaxQRadialGradient()
{
}

QGradient & MaxQRadialGradient::Gradient() {
	return gradient;
}

QRadialGradient & MaxQRadialGradient::RadialGradient() {
	return gradient;
}

// *********************************************

void bmx_qt_qgradient_setcolorat(MaxQGradient * gradient, double position, MaxQColor * color) {
	gradient->Gradient().setColorAt(position, color->Color());
}

// *********************************************

MaxQRadialGradient * bmx_qt_qradialgradient_create(double cx, double cy, double radius, double fx, double fy) {
	return new MaxQRadialGradient(cx, cy, radius, fx, fy);
}

void bmx_qt_qradialgradient_center(MaxQRadialGradient * gradient, double * x, double * y) {
	QPointF p(gradient->RadialGradient().center());
	*x = p.x();
	*y = p.y();
}

void bmx_qt_qradialgradient_focalpoint(MaxQRadialGradient * gradient, double * x, double * y) {
	QPointF p(gradient->RadialGradient().focalPoint());
	*x = p.x();
	*y = p.y();
}

double bmx_qt_qradialgradient_radius(MaxQRadialGradient * gradient) {
	return gradient->RadialGradient().radius();
}

void bmx_qt_qradialgradient_setcenter(MaxQRadialGradient * gradient, double x, double y) {
	gradient->RadialGradient().setCenter(QPointF(x, y));
}

void bmx_qt_qradialgradient_setfocalpoint(MaxQRadialGradient * gradient, double x, double y) {
	gradient->RadialGradient().setFocalPoint(QPointF(x, y));
}

void bmx_qt_qradialgradient_setradius(MaxQRadialGradient * gradient, double radius) {
	gradient->RadialGradient().setRadius(radius);
}

void bmx_qt_qradialgradient_free(MaxQRadialGradient * gradient) {
	delete gradient;
}



// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
