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

#ifndef MAX_QT_QGRAPHICSPOLYGONITEM
#define MAX_QT_QGRAPHICSPOLYGONITEM

#include "../core.mod/glue.h"
#include "../qgraphicsview.mod/glue.h"
#include "../qpolygonf.mod/glue.h"
#include <QtCore>
#include <QGraphicsPolygonItem>

class MaxQGraphicsPolygonItem;

extern "C" {

#include <blitz.h>

	QGraphicsPolygonItem * bmx_qt_qgraphicspolygonitem_create(BBObject * handle, QGraphicsItem * parent);
	QGraphicsPolygonItem * bmx_qt_qgraphicspolygonitem_createwithpoly(BBObject * handle, MaxQPolygonF * polygon, QGraphicsItem * parent);
	int bmx_qt_qgraphicspolygonitem_fillrule(QGraphicsPolygonItem * item);
	MaxQPolygonF * bmx_qt_qgraphicspolygonitem_polygon(QGraphicsPolygonItem * item);
	void bmx_qt_qgraphicspolygonitem_setfillrule(QGraphicsPolygonItem * item, int rule);
	void bmx_qt_qgraphicspolygonitem_setpolygon(QGraphicsPolygonItem * item, MaxQPolygonF * polygon);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQGraphicsPolygonItem : public QGraphicsPolygonItem, MaxQGraphicsEventItem
{
public:
	MaxQGraphicsPolygonItem(BBObject * handle, QGraphicsItem * parent);
	MaxQGraphicsPolygonItem(BBObject * handle, MaxQPolygonF * polygon, QGraphicsItem * parent);
	~MaxQGraphicsPolygonItem();

	virtual void defaultContextMenuEvent(QGraphicsSceneContextMenuEvent * contextMenuEvent);
	virtual void defaultDragEnterEvent(QGraphicsSceneDragDropEvent * event);
	virtual void defaultDragLeaveEvent(QGraphicsSceneDragDropEvent * event);
	virtual void defaultDragMoveEvent(QGraphicsSceneDragDropEvent * event);
	virtual void defaultDropEvent(QGraphicsSceneDragDropEvent * event);
	virtual void defaultFocusInEvent(QFocusEvent * focusEvent);
	virtual void defaultFocusOutEvent(QFocusEvent * focusEvent);
	virtual void defaultHoverEnterEvent(QGraphicsSceneHoverEvent * hoverEvent);
	virtual void defaultHoverLeaveEvent(QGraphicsSceneHoverEvent * hoverEvent);
	virtual void defaultHoverMoveEvent(QGraphicsSceneHoverEvent * hoverEvent);
	virtual void defaultInputMethodEvent(QInputMethodEvent * event);
	virtual void defaultKeyPressEvent(QKeyEvent * keyEvent);
	virtual void defaultKeyReleaseEvent(QKeyEvent * keyEvent);
	virtual void defaultMouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void defaultMouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void defaultMousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void defaultMouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void defaultSceneEvent(QEvent * event);
	virtual void defaultSceneEventFilter(QGraphicsItem * watched, QEvent * event);
	virtual void defaultWheelEvent(QGraphicsSceneWheelEvent * wheelEvent);

private:
	BBObject * maxHandle;
};

#endif
