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

MaxQPainterPath::MaxQPainterPath(const QPainterPath & p)
	: path(p)
{
}

MaxQPainterPath::~MaxQPainterPath()
{
}

QPainterPath & MaxQPainterPath::Path() {
	return path;
}

// ---------------------------------------------------------------------------------------

MaxPathElement::MaxPathElement(const QPainterPath::Element & e)
	: element(e)
{
}

MaxPathElement::~MaxPathElement()
{
}

QPainterPath::Element & MaxPathElement::Element() {
	return element;
}

// ---------------------------------------------------------------------------------------

MaxQTransform::MaxQTransform(const QTransform & t)
	: transform(t)
{
}

MaxQTransform::~MaxQTransform()
{
}

QTransform & MaxQTransform::Transform() {
	return transform;
}

// ---------------------------------------------------------------------------------------

MaxQMatrix::MaxQMatrix(const QMatrix & m)
	: matrix(m)
{
}

MaxQMatrix::~MaxQMatrix()
{
}
	
QMatrix & MaxQMatrix::Matrix() {
	return matrix;
}

// *********************************************

MaxQPainterPath * bmx_qt_qpainterpath_create() {
	return new MaxQPainterPath(QPainterPath());
}

void bmx_qt_qpainterpath_free(MaxQPainterPath * path) {
	delete path;
}

void bmx_qt_qpainterpath_addellipse(MaxQPainterPath * path, double x, double y, double width, double height) {
	path->Path().addEllipse(x, y, width, height);
}

void bmx_qt_qpainterpath_addellipsecenter(MaxQPainterPath * path, double cx, double cy, double rx, double ry) {
	path->Path().addEllipse(QPointF(cx, cy), rx, ry);
}

void bmx_qt_qpainterpath_addpath(MaxQPainterPath * path, MaxQPainterPath * p) {
	path->Path().addPath(p->Path());
}

void bmx_qt_qpainterpath_addrect(MaxQPainterPath * path, double x, double y, double width, double height) {
	path->Path().addRect(x, y, width, height);
}

void bmx_qt_qpainterpath_addregion(MaxQPainterPath * path, MaxQRegion * region) {
	path->Path().addRegion(region->Region());
}

void bmx_qt_qpainterpath_addroundedrect(MaxQPainterPath * path, double x, double y, double w, double h, double xRadius, double yRadius, int _mode) {
	path->Path().addRoundedRect(x, y, w, h, xRadius, yRadius, (Qt::SizeMode)_mode);
}

void bmx_qt_qpainterpath_addtext(MaxQPainterPath * path, double x, double y, MaxQFont * font, BBString * text) {
	path->Path().addText(x, y, font->Font(), qStringFromBBString(text));
}

double bmx_qt_qpainterpath_angleatpercent(MaxQPainterPath * path, double t) {
	return path->Path().angleAtPercent(t);
}

void bmx_qt_qpainterpath_arcmoveto(MaxQPainterPath * path, double x, double y, double width, double height, double angle) {
	path->Path().arcMoveTo(x, y, width, height, angle);
}

void bmx_qt_qpainterpath_arcto(MaxQPainterPath * path, double x, double y, double width, double height, double startAngle, double sweepLength) {
	path->Path().arcTo(x, y, width, height, startAngle, sweepLength);
}

MaxQRectF * bmx_qt_qpainterpath_boundingrect(MaxQPainterPath * path) {
	return new MaxQRectF(path->Path().boundingRect());
}

void bmx_qt_qpainterpath_closesubpath(MaxQPainterPath * path) {
	path->Path().closeSubpath();
}

void bmx_qt_qpainterpath_connectpath(MaxQPainterPath * path, MaxQPainterPath * p) {
	path->Path().connectPath(p->Path());
}

int bmx_qt_qpainterpath_contains(MaxQPainterPath * path, double x, double y) {
	return static_cast<int>(path->Path().contains(QPointF(x, y)));
}

int bmx_qt_qpainterpath_containsrect(MaxQPainterPath * path, MaxQRectF * rectangle) {
	return static_cast<int>(path->Path().contains(rectangle->Rect()));
}

int bmx_qt_qpainterpath_containspath(MaxQPainterPath * path, MaxQPainterPath * p) {
	return static_cast<int>(path->Path().contains(p->Path()));
}

MaxQRectF * bmx_qt_qpainterpath_controlpointrect(MaxQPainterPath * path) {
	return new MaxQRectF(path->Path().controlPointRect());
}

void bmx_qt_qpainterpath_cubicto(MaxQPainterPath * path, double c1X, double c1Y, double c2X, double c2Y, double endPointX, double endPointY) {
	path->Path().cubicTo(c1X, c1Y, c2X, c2Y, endPointX, endPointY);
}

void bmx_qt_qpainterpath_currentposition(MaxQPainterPath * path, double * x, double * y) {
	QPointF p(path->Path().currentPosition());
	*x = p.x();
	*y = p.y();
}

MaxPathElement * bmx_qt_qpainterpath_elementat(MaxQPainterPath * path, int index) {
	return new MaxPathElement(path->Path().elementAt(index));
}

int bmx_qt_qpainterpath_elementcount(MaxQPainterPath * path) {
	return path->Path().elementCount();
}

int bmx_qt_qpainterpath_fillrule(MaxQPainterPath * path) {
	return path->Path().fillRule();
}

MaxQPainterPath * bmx_qt_qpainterpath_intersected(MaxQPainterPath * path, MaxQPainterPath * p) {
	return new MaxQPainterPath(path->Path().intersected(p->Path()));
}

int bmx_qt_qpainterpath_intersects(MaxQPainterPath * path, MaxQPainterPath * p) {
	return static_cast<int>(path->Path().intersects(p->Path()));
}

int bmx_qt_qpainterpath_isempty(MaxQPainterPath * path) {
	return static_cast<int>(path->Path().isEmpty());
}

double bmx_qt_qpainterpath_length(MaxQPainterPath * path) {
	return path->Path().length();
}

void bmx_qt_qpainterpath_lineto(MaxQPainterPath * path, double x, double y) {
	path->Path().lineTo(x, y);
}

void bmx_qt_qpainterpath_moveto(MaxQPainterPath * path, double x, double y) {
	path->Path().moveTo(x, y);
}

double bmx_qt_qpainterpath_percentatlength(MaxQPainterPath * path, double length) {
	return path->Path().percentAtLength(length);
}

void bmx_qt_qpainterpath_pointatpercent(MaxQPainterPath * path, double t, double * x, double * y) {
	QPointF p(path->Path().pointAtPercent(t));
	*x = p.x();
	*y = p.y();
}

void bmx_qt_qpainterpath_quadto(MaxQPainterPath * path, double cx, double cy, double endPointX, double endPointY) {
	path->Path().quadTo(cx, cy, endPointX, endPointY);
}

void bmx_qt_qpainterpath_setelementpositionat(MaxQPainterPath * path, int index, double x, double y) {
	path->Path().setElementPositionAt(index, x, y);
}

void bmx_qt_qpainterpath_setfillrule(MaxQPainterPath * path, int fillRule) {
	path->Path().setFillRule((Qt::FillRule)fillRule);
}

MaxQPainterPath * bmx_qt_qpainterpath_simplified(MaxQPainterPath * path) {
	return new MaxQPainterPath(path->Path().simplified());
}

double bmx_qt_qpainterpath_slopeatpercent(MaxQPainterPath * path, double t) {
	return path->Path().slopeAtPercent(t);
}

MaxQPainterPath * bmx_qt_qpainterpath_subtracted(MaxQPainterPath * path, MaxQPainterPath * p) {
	return new MaxQPainterPath(path->Path().subtracted(p->Path()));
}

MaxQPainterPath * bmx_qt_qpainterpath_toreversed(MaxQPainterPath * path) {
	return new MaxQPainterPath(path->Path().toReversed());
}



// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
