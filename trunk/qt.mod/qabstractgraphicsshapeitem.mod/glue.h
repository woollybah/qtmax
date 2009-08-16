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

#ifndef MAX_QT_QABSTRACTGRAPHICSSHAPEITEM
#define MAX_QT_QABSTRACTGRAPHICSSHAPEITEM

#include "../core.mod/glue.h"
#include "../qpen.mod/glue.h"
#include "../qbrush.mod/glue.h"
#include "../qcolor.mod/glue.h"
#include <QtCore>
#include <QAbstractGraphicsShapeItem>

extern "C" {

#include <blitz.h>

	MaxQBrush * bmx_qt_qabstractgraphicsshapeitem_brush(QAbstractGraphicsShapeItem * item);
	MaxQPen * bmx_qt_qabstractgraphicsshapeitem_pen(QAbstractGraphicsShapeItem * item);
	void bmx_qt_qabstractgraphicsshapeitem_setbrush(QAbstractGraphicsShapeItem * item, MaxQBrush * brush);
	void bmx_qt_qabstractgraphicsshapeitem_setbrushcolor(QAbstractGraphicsShapeItem * item, MaxQColor * brush);
	void bmx_qt_qabstractgraphicsshapeitem_setpenstyle(QAbstractGraphicsShapeItem * item, int style);
	void bmx_qt_qabstractgraphicsshapeitem_setpen(QAbstractGraphicsShapeItem * item, MaxQPen * pen);
	void bmx_qt_qabstractgraphicsshapeitem_setpencolor(QAbstractGraphicsShapeItem * item, MaxQColor * pen);
	void bmx_qt_qabstractgraphicsshapeitem_setbrushstyle(QAbstractGraphicsShapeItem * item, int style);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif
