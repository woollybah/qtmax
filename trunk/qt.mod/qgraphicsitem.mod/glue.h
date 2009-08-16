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

#ifndef MAX_QT_QGRAPHICSITEM
#define MAX_QT_QGRAPHICSITEM

#include "../core.mod/glue.h"
#include "../qcursor.mod/glue.h"
#include "../qpainterpath.mod/glue.h"
#include <QtCore>
#include <QGraphicsItem>
#include <QGraphicsScene>

extern "C" {

#include <blitz.h>

	int bmx_qt_qgraphicsitem_isselected(QGraphicsItem * item);
	int bmx_qt_qgraphicsitem_isundermouse(QGraphicsItem * item);
	int bmx_qt_qgraphicsitem_isvisible(QGraphicsItem * item);
	int bmx_qt_qgraphicsitem_isvisibleto(QGraphicsItem * item, QGraphicsItem * parent);
	int bmx_qt_qgraphicsitem_iswidget(QGraphicsItem * item);
	int bmx_qt_qgraphicsitem_iswindow(QGraphicsItem * item);
	void bmx_qt_qgraphicsitem_setacceptdrops(QGraphicsItem * item, int on);
	void bmx_qt_qgraphicsitem_setaccepthoverevents(QGraphicsItem * item, int enabled);
	void bmx_qt_qgraphicsitem_setacceptedmousebuttons(QGraphicsItem * item, int buttons);
	void bmx_qt_qgraphicsitem_setboundingregiongranularity(QGraphicsItem * item, double granularity);
	void bmx_qt_qgraphicsitem_setcachemode(QGraphicsItem * item, int mode, int w, int h);
	void bmx_qt_qgraphicsitem_setcursor(QGraphicsItem * item, MaxQCursor * cursor);
	void bmx_qt_qgraphicsitem_setdata(QGraphicsItem * item, int key, BBObject * value);
	void bmx_qt_qgraphicsitem_setenabled(QGraphicsItem * item, int enabled);
	void bmx_qt_qgraphicsitem_setflag(QGraphicsItem * item, int flag, int enabled);
	void bmx_qt_qgraphicsitem_setflags(QGraphicsItem * item, int flags);
	void bmx_qt_qgraphicsitem_setfocus(QGraphicsItem * item, int focusReason);
	void bmx_qt_qgraphicsitem_setgroup(QGraphicsItem * item, QGraphicsItemGroup * group);
	void bmx_qt_qgraphicsitem_sethandleschildevents(QGraphicsItem * item, int enabled);
	void bmx_qt_qgraphicsitem_setopacity(QGraphicsItem * item, double opacity);
	void bmx_qt_qgraphicsitem_setparentitem(QGraphicsItem * item, QGraphicsItem * parent);
	void bmx_qt_qgraphicsitem_setpos(QGraphicsItem * item, double x, double y);
	void bmx_qt_qgraphicsitem_setselected(QGraphicsItem * item, int selected);
	void bmx_qt_qgraphicsitem_settooltip(QGraphicsItem * item, BBString * toolTip);
	void bmx_qt_qgraphicsitem_settransform(QGraphicsItem * item, MaxQTransform * matrix, int combine);
	void bmx_qt_qgraphicsitem_setvisible(QGraphicsItem * item, int visible);
	void bmx_qt_qgraphicsitem_setzvalue(QGraphicsItem * item, double z);
	MaxQRectF * bmx_qt_qgraphicsitem_boundingrect(QGraphicsItem * item);
	void bmx_qt_qgraphicsitem_addtoscene(QGraphicsItem * item, QGraphicsScene * scene);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif
