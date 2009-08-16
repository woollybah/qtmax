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

#ifndef MAX_QT_QGRAPHICSSVGITEM
#define MAX_QT_QGRAPHICSSVGITEM

#include "../core.mod/glue.h"
#include "../qcursor.mod/glue.h"
#include "../qpainterpath.mod/glue.h"
#include <QtCore>
#include <QGraphicsSvgItem>
#include <QGraphicsScene>

class MaxQGraphicsSvgItem;

extern "C" {

#include <blitz.h>

	QGraphicsSvgItem * bmx_qt_qgraphicssvgitem_create(BBObject * handle, BBString * filename, QGraphicsItem * parent);

	int bmx_qt_qgraphicssvgitem_isselected(QGraphicsSvgItem * item);
	int bmx_qt_qgraphicssvgitem_isundermouse(QGraphicsSvgItem * item);
	int bmx_qt_qgraphicssvgitem_isvisible(QGraphicsSvgItem * item);
	int bmx_qt_qgraphicssvgitem_isvisibleto(QGraphicsSvgItem * item, QGraphicsSvgItem * parent);
	int bmx_qt_qgraphicssvgitem_iswidget(QGraphicsSvgItem * item);
	int bmx_qt_qgraphicssvgitem_iswindow(QGraphicsSvgItem * item);
	void bmx_qt_qgraphicssvgitem_setacceptdrops(QGraphicsSvgItem * item, int on);
	void bmx_qt_qgraphicssvgitem_setaccepthoverevents(QGraphicsSvgItem * item, int enabled);
	void bmx_qt_qgraphicssvgitem_setacceptedmousebuttons(QGraphicsSvgItem * item, int buttons);
	void bmx_qt_qgraphicssvgitem_setboundingregiongranularity(QGraphicsSvgItem * item, double granularity);
	void bmx_qt_qgraphicssvgitem_setcachemode(QGraphicsSvgItem * item, int mode, int w, int h);
	void bmx_qt_qgraphicssvgitem_setcursor(QGraphicsSvgItem * item, MaxQCursor * cursor);
	void bmx_qt_qgraphicssvgitem_setdata(QGraphicsSvgItem * item, int key, BBObject * value);
	void bmx_qt_qgraphicssvgitem_setenabled(QGraphicsSvgItem * item, int enabled);
	void bmx_qt_qgraphicssvgitem_setflag(QGraphicsSvgItem * item, int flag, int enabled);
	void bmx_qt_qgraphicssvgitem_setflags(QGraphicsSvgItem * item, int flags);
	void bmx_qt_qgraphicssvgitem_setfocus(QGraphicsSvgItem * item, int focusReason);
	void bmx_qt_qgraphicssvgitem_setgroup(QGraphicsSvgItem * item, QGraphicsItemGroup * group);
	void bmx_qt_qgraphicssvgitem_sethandleschildevents(QGraphicsSvgItem * item, int enabled);
	void bmx_qt_qgraphicssvgitem_setopacity(QGraphicsSvgItem * item, double opacity);
	void bmx_qt_qgraphicssvgitem_setparentitem(QGraphicsSvgItem * item, QGraphicsSvgItem * parent);
	void bmx_qt_qgraphicssvgitem_setpos(QGraphicsSvgItem * item, double x, double y);
	void bmx_qt_qgraphicssvgitem_setselected(QGraphicsSvgItem * item, int selected);
	void bmx_qt_qgraphicssvgitem_settooltip(QGraphicsSvgItem * item, BBString * toolTip);
	void bmx_qt_qgraphicssvgitem_settransform(QGraphicsSvgItem * item, MaxQTransform * matrix, int combine);
	void bmx_qt_qgraphicssvgitem_setvisible(QGraphicsSvgItem * item, int visible);
	void bmx_qt_qgraphicssvgitem_setzvalue(QGraphicsSvgItem * item, double z);
	MaxQRectF * bmx_qt_qgraphicssvgitem_boundingrect(QGraphicsSvgItem * item);

	void bmx_qt_qgraphicssvgitem_addtoscene(QGraphicsSvgItem * item, QGraphicsScene * scene);
	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQGraphicsSvgItem : public QGraphicsSvgItem
{
public:
	MaxQGraphicsSvgItem(BBObject * handle, const QString & fileName, QGraphicsItem * parent);
	~MaxQGraphicsSvgItem();

private:
	BBObject * maxHandle;
};

#endif
