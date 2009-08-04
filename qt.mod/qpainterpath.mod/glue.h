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

#ifndef MAX_QT_ template
#define MAX_QT_ template

#include "../core.mod/glue.h"
#include "../qfont.mod/glue.h"
#include "../qregion.mod/glue.h"
#include <QtCore>
#include <QPainterPath>
#include <QMatrix>
#include <QTransform>

class MaxQPainterPath;
class MaxPathElement;

extern "C" {

#include <blitz.h>

	void bmx_qt_qpainterpath_addellipse(MaxQPainterPath * path, double x, double y, double width, double height);
	void bmx_qt_qpainterpath_addellipsecenter(MaxQPainterPath * path, double cx, double cy, double rx, double ry);
	void bmx_qt_qpainterpath_addpath(MaxQPainterPath * path, MaxQPainterPath * p);
	void bmx_qt_qpainterpath_addrect(MaxQPainterPath * path, double x, double y, double width, double height);
	void bmx_qt_qpainterpath_addregion(MaxQPainterPath * path, MaxQRegion * region);
	void bmx_qt_qpainterpath_addroundedrect(MaxQPainterPath * path, double x, double y, double w, double h, double xRadius, double yRadius, int _mode);
	void bmx_qt_qpainterpath_addtext(MaxQPainterPath * path, double x, double y, MaxQFont * font, BBString * text);
	double bmx_qt_qpainterpath_angleatpercent(MaxQPainterPath * path, double t);
	void bmx_qt_qpainterpath_arcmoveto(MaxQPainterPath * path, double x, double y, double width, double height, double angle);
	void bmx_qt_qpainterpath_arcto(MaxQPainterPath * path, double x, double y, double width, double height, double startAngle, double sweepLength);
	MaxQRectF * bmx_qt_qpainterpath_boundingrect(MaxQPainterPath * path);
	void bmx_qt_qpainterpath_closesubpath(MaxQPainterPath * path);
	void bmx_qt_qpainterpath_connectpath(MaxQPainterPath * path, MaxQPainterPath * p);
	int bmx_qt_qpainterpath_contains(MaxQPainterPath * path, double x, double y);
	int bmx_qt_qpainterpath_containsrect(MaxQPainterPath * path, MaxQRectF * rectangle);
	int bmx_qt_qpainterpath_containspath(MaxQPainterPath * path, MaxQPainterPath * p);
	MaxQRectF * bmx_qt_qpainterpath_controlpointrect(MaxQPainterPath * path);
	void bmx_qt_qpainterpath_cubicto(MaxQPainterPath * path, double c1X, double c1Y, double c2X, double c2Y, double endPointX, double endPointY);
	void bmx_qt_qpainterpath_currentposition(MaxQPainterPath * path, double * x, double * y);
	MaxPathElement * bmx_qt_qpainterpath_elementat(MaxQPainterPath * path, int index);
	int bmx_qt_qpainterpath_elementcount(MaxQPainterPath * path);
	int bmx_qt_qpainterpath_fillrule(MaxQPainterPath * path);
	MaxQPainterPath * bmx_qt_qpainterpath_intersected(MaxQPainterPath * path, MaxQPainterPath * p);
	int bmx_qt_qpainterpath_intersects(MaxQPainterPath * path, MaxQPainterPath * p);
	int bmx_qt_qpainterpath_isempty(MaxQPainterPath * path);
	double bmx_qt_qpainterpath_length(MaxQPainterPath * path);
	void bmx_qt_qpainterpath_lineto(MaxQPainterPath * path, double x, double y);
	void bmx_qt_qpainterpath_moveto(MaxQPainterPath * path, double x, double y);
	double bmx_qt_qpainterpath_percentatlength(MaxQPainterPath * path, double length);
	void bmx_qt_qpainterpath_pointatpercent(MaxQPainterPath * path, double t, double * x, double * y);
	void bmx_qt_qpainterpath_quadto(MaxQPainterPath * path, double cx, double cy, double endPointX, double endPointY);
	void bmx_qt_qpainterpath_setelementpositionat(MaxQPainterPath * path, int index, double x, double y);
	void bmx_qt_qpainterpath_setfillrule(MaxQPainterPath * path, int fillRule);
	MaxQPainterPath * bmx_qt_qpainterpath_simplified(MaxQPainterPath * path);
	double bmx_qt_qpainterpath_slopeatpercent(MaxQPainterPath * path, double t);
	MaxQPainterPath * bmx_qt_qpainterpath_subtracted(MaxQPainterPath * path, MaxQPainterPath * p);
	MaxQPainterPath * bmx_qt_qpainterpath_toreversed(MaxQPainterPath * path);
	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQPainterPath
{
public:
	MaxQPainterPath(const QPainterPath & p);
	~MaxQPainterPath();
	QPainterPath & Path();

private:
	QPainterPath path;
};

class MaxPathElement
{
public:
	MaxPathElement(const QPainterPath::Element & e);
	~MaxPathElement();
	
	QPainterPath::Element & Element();

private:
	QPainterPath::Element element;
};

#endif
