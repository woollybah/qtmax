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

MaxQPainter::MaxQPainter(QPaintDevice * device)
	: painter(device)
{
}

MaxQPainter::~MaxQPainter()
{
}

QPainter & MaxQPainter::Painter() {
	return painter;
}


// *********************************************

QPainter * bmx_qt_qpainter_create(QPaintDevice * device) {
	return new QPainter(device);
}

void bmx_qt_qpainter_free(QPainter * painter) {
	delete painter;
}

int bmx_qt_qpainter_begin(QPainter * painter, QPaintDevice * device) {
	return static_cast<int>(painter->begin(device));
}

int bmx_qt_qpainter_end(QPainter * painter) {
	return static_cast<int>(painter->end());
}

void bmx_qt_qpainter_resetmatrix(QPainter * painter) {
	painter->resetMatrix();
}

void bmx_qt_qpainter_resettransform(QPainter * painter) {
	painter->resetTransform();
}

void bmx_qt_qpainter_restore(QPainter * painter) {
	painter->restore();
}

void bmx_qt_qpainter_rotate(QPainter * painter, double angle) {
	painter->rotate(angle);
}

void bmx_qt_qpainter_save(QPainter * painter) {
	painter->save();
}

void bmx_qt_qpainter_scale(QPainter * painter, double sx, double sy) {
	painter->scale(sx, sy);
}

void bmx_qt_qpainter_setbrush(QPainter * painter, MaxQBrush * brush) {
	painter->setBrush(brush->Brush());
}

void bmx_qt_qpainter_setbrushcolor(QPainter * painter, MaxQColor * color) {
	painter->setBrush(color->Color());
}

void bmx_qt_qpainter_drawconvexpolygon(QPainter * painter, BBArray * points) {
	QPolygon p;
	p.setPoints(points->scales[0] / 2, (int*)BBARRAYDATA(points, points->dims));
	painter->drawConvexPolygon(p);
}

void bmx_qt_qpainter_drawconvexpolygond(QPainter * painter, BBArray * points) {
	QPolygonF p;
	int n = points->scales[0] / 2;
	double *s=(double*)BBARRAYDATA( points, points->dims );
	for (int i = 0; i < n; i++) {
		p << QPointF(s[i * 2], s[i * 2 + 1]);
	}
	painter->drawConvexPolygon(p);
}

void bmx_qt_qpainter_drawellipse(QPainter * painter, int x, int y, int width, int height) {
	painter->drawEllipse(x, y, width, height);
}

void bmx_qt_qpainter_drawellipsecenter(QPainter * painter, int cx, int cy, int rx, int ry) {
	painter->drawEllipse(QPoint(cx, cy), rx, ry);
}

void bmx_qt_qpainter_drawellipsecenterd(QPainter * painter, double cx, double cy, double rx, double ry) {
	painter->drawEllipse(QPointF(cx, cy), rx, ry);
}

void bmx_qt_qpainter_drawline(QPainter * painter, int x1, int y1, int x2, int y2) {
	painter->drawLine(x1, y1, x2, y2);
}

void bmx_qt_qpainter_drawlined(QPainter * painter, double x1, double y1, double x2, double y2) {
	painter->drawLine(QPointF(x1, y1), QPointF(x2, y2));
}
	
void bmx_qt_qpainter_setpencolor(QPainter * painter, MaxQColor * color) {
	painter->setPen(color->Color());
}

void bmx_qt_qpainter_setpenstyle(QPainter * painter, int style) {
	painter->setPen((Qt::PenStyle)style); // if we don't cast here, it assumes we are setting the pen color...
}

void bmx_qt_qpainter_translate(QPainter * painter, double dx, double dy) {
	painter->translate(dx, dy);
}

void bmx_qt_qpainter_setrenderhint(QPainter * painter, int h, int on) {
	QPainter::RenderHint hint;
	switch(h) {
		case 0x01:
			hint = QPainter::Antialiasing;
			break;
		case 0x02:
			hint = QPainter::TextAntialiasing;
			break;
		case 0x04:
			hint = QPainter::SmoothPixmapTransform;
			break;
		case 0x08:
			hint = QPainter::HighQualityAntialiasing;
			break;
		case 0x10:
			hint = QPainter::NonCosmeticDefaultPen;
			break;
	}
	
	painter->setRenderHint(hint, static_cast<bool>(on));
}

void bmx_qt_qpainter_setbrushgradient(QPainter * painter, MaxQGradient * gradient) {
	painter->setBrush(gradient->Gradient());
}

void bmx_qt_qpainter_fillrect(QPainter * painter, int x, int y, int width, int height, int style) {
	painter->fillRect(x, y, width, height, (Qt::BrushStyle)style);
}

void bmx_qt_qpainter_fillrectrect(QPainter * painter, MaxQRect * rectangle, int style) {
	painter->fillRect(rectangle->Rect(), (Qt::BrushStyle)style);
}

void bmx_qt_qpainter_fillrectbrush(QPainter * painter, int x, int y, int width, int height, MaxQBrush * brush) {
	painter->fillRect(x, y, width, height, brush->Brush());
}

void bmx_qt_qpainter_fillrectrectbrush(QPainter * painter, MaxQRect * rectangle, MaxQBrush * brush) {
	painter->fillRect(rectangle->Rect(), brush->Brush());
}

void bmx_qt_qpainter_fillpath(QPainter * painter, MaxQPainterPath * path, MaxQBrush * brush) {
	painter->fillPath(path->Path(), brush->Brush());
}

void bmx_qt_qpainter_drawrectrect(QPainter * painter, MaxQRect * rectangle) {
	painter->drawRect(rectangle->Rect());
}

void bmx_qt_qpainter_drawrect(QPainter * painter, int x, int y, int width, int height) {
	painter->drawRect(x, y, width, height);
}

void bmx_qt_qpainter_drawtext(QPainter * painter, int x, int y, BBString * text) {
	painter->drawText(x, y, qStringFromBBString(text));
}

void bmx_qt_qpainter_fillrectcolor(QPainter * painter, int x, int y, int width, int height, MaxQColor * color) {
	painter->fillRect(x, y, width, height, color->Color());
}

void bmx_qt_qpainter_drawtiledpixmaprectf(QPainter * painter, MaxQRectF * rectangle, MaxQPixmap * pixmap, double posX, double posY) {
	if (posX == 0 && posY == 0) {
		painter->drawTiledPixmap(rectangle->Rect(), pixmap->Pixmap());
	} else {
		painter->drawTiledPixmap(rectangle->Rect(), pixmap->Pixmap(), QPointF(posX, posY));
	}
}

void bmx_qt_qpainter_drawtiledpixmaprect(QPainter * painter, MaxQRect * rectangle, MaxQPixmap * pixmap, int posX, int posY) {
	if (posX == 0 && posY == 0) {
		painter->drawTiledPixmap(rectangle->Rect(), pixmap->Pixmap());
	} else {
		painter->drawTiledPixmap(rectangle->Rect(), pixmap->Pixmap(), QPoint(posX, posY));
	}
}

void bmx_qt_qpainter_drawtiledpixmap(QPainter * painter, int x, int y, int width, int height, MaxQPixmap * pixmap, int sx, int sy) {
	painter->drawTiledPixmap(x, y, width, height, pixmap->Pixmap(), sx, sy);
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
