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

#ifndef MAX_QT_QPOLYGONF
#define MAX_QT_QPOLYGONF

#include "../core.mod/glue.h"
#include <QtCore>
#include <QPolygonF>

class MaxQPolygonF;

extern "C" {

#include <blitz.h>

	MaxQPolygonF * bmx_qt_qpolygonf_create();
	int bmx_qt_qpolygonf_containspoint(MaxQPolygonF * poly, float x, float y, int fillRule);
	MaxQPolygonF * bmx_qt_qpolygonf_intersected(MaxQPolygonF * poly, MaxQPolygonF * r);
	int bmx_qt_qpolygonf_isclosed(MaxQPolygonF * poly);
	int bmx_qt_qpolygonf_isempty(MaxQPolygonF * poly);
	int bmx_qt_qpolygonf_size(MaxQPolygonF * poly);
	MaxQPolygonF * bmx_qt_qpolygonf_subtracted(MaxQPolygonF * poly, MaxQPolygonF *r);
	void bmx_qt_qpolygonf_translate(MaxQPolygonF * poly, float dx, float dy);
	MaxQPolygonF * bmx_qt_qpolygonf_united(MaxQPolygonF * poly, MaxQPolygonF * r);
	void bmx_qt_qpolygonf_free(MaxQPolygonF * poly);
	void bmx_qt_qpolygonf_at(MaxQPolygonF * poly, int index, float * x, float * y);
	void bmx_qt_qpolygonf_clear(MaxQPolygonF * poly);
	void bmx_qt_qpolygonf_append(MaxQPolygonF * poly, float x, float y);
	void bmx_qt_qpolygonf_prepend(MaxQPolygonF * poly, float x, float y);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQPolygonF
{
public:
	MaxQPolygonF();
	MaxQPolygonF(const QPolygonF & p);
	~MaxQPolygonF();
	
	QPolygonF & Polygon();

private:
	QPolygonF polygon;
};

#endif
