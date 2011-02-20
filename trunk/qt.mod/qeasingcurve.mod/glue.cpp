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

MaxQEasingCurve::MaxQEasingCurve(const QEasingCurve & c)
	: curve(c)
{
}

MaxQEasingCurve::~MaxQEasingCurve()
{
}

QEasingCurve & MaxQEasingCurve::Curve() {
	return curve;
}

// *********************************************

void bmx_qt_qeasingcurve_free(MaxQEasingCurve * handle) {
	delete handle;
}

MaxQEasingCurve * bmx_qt_qeasingcurve_create(int type) {
	QEasingCurve::Type curveType;

	switch (type) {
		case 0:
			curveType = QEasingCurve::Linear;
			break;
		case 1:
			curveType = QEasingCurve::InQuad;
			break;
		case 2:
			curveType = QEasingCurve::OutQuad;
			break;
		case 3:
			curveType = QEasingCurve::InOutQuad;
			break;
		case 4:
			curveType = QEasingCurve::OutInQuad;
			break;
		case 5:
			curveType = QEasingCurve::InCubic;
			break;
		case 6:
			curveType = QEasingCurve::OutCubic;
			break;
		case 7:
			curveType = QEasingCurve::InOutCubic;
			break;
		case 8:
			curveType = QEasingCurve::OutInCubic;
			break;
		case 9:
			curveType = QEasingCurve::InQuart;
			break;
		case 10:
			curveType = QEasingCurve::OutQuart;
			break;
		case 11:
			curveType = QEasingCurve::InOutQuart;
			break;
		case 12:
			curveType = QEasingCurve::OutInQuart;
			break;
		case 13:
			curveType = QEasingCurve::InQuint;
			break;
		case 14:
			curveType = QEasingCurve::OutQuint;
			break;
		case 15:
			curveType = QEasingCurve::InOutQuint;
			break;
		case 16:
			curveType = QEasingCurve::OutInQuint;
			break;
		case 17:
			curveType = QEasingCurve::InSine;
			break;
		case 18:
			curveType = QEasingCurve::OutSine;
			break;
		case 19:
			curveType = QEasingCurve::InOutSine;
			break;
		case 20:
			curveType = QEasingCurve::OutInSine;
			break;
		case 21:
			curveType = QEasingCurve::InExpo;
			break;
		case 22:
			curveType = QEasingCurve::OutExpo;
			break;
		case 23:
			curveType = QEasingCurve::InOutExpo;
			break;
		case 24:
			curveType = QEasingCurve::OutInExpo;
			break;
		case 25:
			curveType = QEasingCurve::InCirc;
			break;
		case 26:
			curveType = QEasingCurve::OutCirc;
			break;
		case 27:
			curveType = QEasingCurve::InOutCirc;
			break;
		case 28:
			curveType = QEasingCurve::OutInCirc;
			break;
		case 29:
			curveType = QEasingCurve::InElastic;
			break;
		case 30:
			curveType = QEasingCurve::OutElastic;
			break;
		case 31:
			curveType = QEasingCurve::InOutElastic;
			break;
		case 32:
			curveType = QEasingCurve::OutInElastic;
			break;
		case 33:
			curveType = QEasingCurve::InBack;
			break;
		case 34:
			curveType = QEasingCurve::OutBack;
			break;
		case 35:
			curveType = QEasingCurve::InOutBack;
			break;
		case 36:
			curveType = QEasingCurve::OutInBack;
			break;
		case 37:
			curveType = QEasingCurve::InBounce;
			break;
		case 38:
			curveType = QEasingCurve::OutBounce;
			break;
		case 39:
			curveType = QEasingCurve::InOutBounce;
			break;
		case 40:
			curveType = QEasingCurve::OutInBounce;
			break;
	}
	
	return new MaxQEasingCurve(QEasingCurve(curveType));
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
