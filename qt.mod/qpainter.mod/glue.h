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

#ifndef MAX_QT_QPAINTER
#define MAX_QT_QPAINTER

#include "../core.mod/glue.h"
#include "../qbrush.mod/glue.h"
#include "../qcolor.mod/glue.h"
#include "../qgradient.mod/glue.h"
#include "../qpainterpath.mod/glue.h"
#include "../qimage.mod/glue.h"
#include "../qfont.mod/glue.h"
#include <QtCore>
#include <QPainter>
#include <QWidget>

class MaxQPainter;

extern "C" {

#include <blitz.h>

	QPainter * bmx_qt_qpainter_create(QPaintDevice * device);
	QPainter * bmx_qt_qpainter_createwithwidget(QWidget * widget);
	void bmx_qt_qpainter_free(QPainter * painter);
	int bmx_qt_qpainter_begin(QPainter * painter, QPaintDevice * device);
	int bmx_qt_qpainter_end(QPainter * painter);
	void bmx_qt_qpainter_resetmatrix(QPainter * painter);
	void bmx_qt_qpainter_resettransform(QPainter * painter);
	void bmx_qt_qpainter_restore(QPainter * painter);
	void bmx_qt_qpainter_rotate(QPainter * painter, double angle);
	void bmx_qt_qpainter_save(QPainter * painter);
	void bmx_qt_qpainter_scale(QPainter * painter, double sx, double sy);
	void bmx_qt_qpainter_setbrush(QPainter * painter, MaxQBrush * brush);
	void bmx_qt_qpainter_setbrushcolor(QPainter * painter, MaxQColor * color);
	void bmx_qt_qpainter_drawconvexpolygon(QPainter * painter, BBArray * points);
	void bmx_qt_qpainter_drawconvexpolygond(QPainter * painter, BBArray * points);
	void bmx_qt_qpainter_drawellipse(QPainter * painter, int x, int y, int width, int height);
	void bmx_qt_qpainter_drawellipsecenter(QPainter * painter, int cx, int cy, int rx, int ry);
	void bmx_qt_qpainter_drawellipsecenterd(QPainter * painter, double cx, double cy, double rx, double ry);
	void bmx_qt_qpainter_drawline(QPainter * painter, int x1, int y1, int x2, int y2);
	void bmx_qt_qpainter_drawlined(QPainter * painter, double x1, double y1, double x2, double y2);

	void bmx_qt_qpainter_setpencolor(QPainter * painter, MaxQColor * color);
	void bmx_qt_qpainter_setpenstyle(QPainter * painter, int style);
	void bmx_qt_qpainter_translate(QPainter * painter, double dx, double dy);
	void bmx_qt_qpainter_setrenderhint(QPainter * painter, int hint, int on);
	void bmx_qt_qpainter_setbrushgradient(QPainter * painter, MaxQGradient * gradient);
	void bmx_qt_qpainter_fillrect(QPainter * painter, int x, int y, int width, int height, int style);
	void bmx_qt_qpainter_fillrectrect(QPainter * painter, MaxQRect * rectangle, int style);
	void bmx_qt_qpainter_fillrectbrush(QPainter * painter, int x, int y, int width, int height, MaxQBrush * brush);
	void bmx_qt_qpainter_fillrectrectbrush(QPainter * painter, MaxQRect * rectangle, MaxQBrush * brush);
	void bmx_qt_qpainter_fillpath(QPainter * painter, MaxQPainterPath * path, MaxQBrush * brush);
	void bmx_qt_qpainter_drawrectrect(QPainter * painter, MaxQRect * rectangle);
	void bmx_qt_qpainter_drawrect(QPainter * painter, int x, int y, int width, int height);
	void bmx_qt_qpainter_drawtext(QPainter * painter, int x, int y, BBString * text);
	void bmx_qt_qpainter_fillrectcolor(QPainter * painter, int x, int y, int width, int height, MaxQColor * color);
	void bmx_qt_qpainter_drawtiledpixmaprectf(QPainter * painter, MaxQRectF * rectangle, MaxQPixmap * pixmap, double posX, double posY);
	void bmx_qt_qpainter_drawtiledpixmaprect(QPainter * painter, MaxQRect * rectangle, MaxQPixmap * pixmap, int posX, int posY);
	void bmx_qt_qpainter_drawtiledpixmap(QPainter * painter, int x, int y, int width, int height, MaxQPixmap * pixmap, int sx, int sy);
	void bmx_qt_qpainter_drawimage(QPainter * painter, int x, int y, MaxQImage * image);
	void bmx_qt_qpainter_setcliprect(QPainter * painter, int x, int y, int width, int height, int operation);
	void bmx_qt_qpainter_setfont(QPainter * painter, MaxQFont * font);
	void bmx_qt_qpainter_setclipping(QPainter * painter, int enable);
	void bmx_qt_qpainter_setcompositionmode(QPainter * painter, int mode);
	void bmx_qt_qpainter_setopacity(QPainter * painter, double opacity);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQPainter
{
public:
	MaxQPainter(QPaintDevice * device);
	~MaxQPainter();

	QPainter * Painter();
	
private:
	QPainter painter;
};

#endif
