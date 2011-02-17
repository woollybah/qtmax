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

MaxQGraphicsPolygonItem::MaxQGraphicsPolygonItem(BBObject * handle, QGraphicsItem * parent)
	: maxHandle(handle), QGraphicsPolygonItem(parent)
{
	qgibind(this, handle);
}

MaxQGraphicsPolygonItem::MaxQGraphicsPolygonItem(BBObject * handle, MaxQPolygonF * polygon, QGraphicsItem * parent)
	: maxHandle(handle), QGraphicsPolygonItem(polygon->Polygon(), parent)
{
	qgibind(this, handle);
}

MaxQGraphicsPolygonItem::~MaxQGraphicsPolygonItem()
{
	qgiunbind(this);
}

// *********************************************


void MaxQGraphicsPolygonItem::defaultContextMenuEvent(QGraphicsSceneContextMenuEvent * contextMenuEvent) {
	QGraphicsPolygonItem::contextMenuEvent(contextMenuEvent);
}

void MaxQGraphicsPolygonItem::defaultDragEnterEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsPolygonItem::dragEnterEvent(event);
}

void MaxQGraphicsPolygonItem::defaultDragLeaveEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsPolygonItem::dragLeaveEvent(event);
}

void MaxQGraphicsPolygonItem::defaultDragMoveEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsPolygonItem::dragMoveEvent(event);
}

void MaxQGraphicsPolygonItem::defaultDropEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsPolygonItem::dropEvent(event);
}

void MaxQGraphicsPolygonItem::defaultFocusInEvent(QFocusEvent * focusEvent) {
	QGraphicsPolygonItem::focusInEvent(focusEvent);
}

void MaxQGraphicsPolygonItem::defaultFocusOutEvent(QFocusEvent * focusEvent) {
	QGraphicsPolygonItem::focusOutEvent(focusEvent);
}

void MaxQGraphicsPolygonItem::defaultHoverEnterEvent(QGraphicsSceneHoverEvent * hoverEvent) {
	QGraphicsPolygonItem::hoverEnterEvent(hoverEvent);
}

void MaxQGraphicsPolygonItem::defaultHoverLeaveEvent(QGraphicsSceneHoverEvent * hoverEvent) {
	QGraphicsPolygonItem::hoverLeaveEvent(hoverEvent);
}

void MaxQGraphicsPolygonItem::defaultHoverMoveEvent(QGraphicsSceneHoverEvent * hoverEvent) {
	QGraphicsPolygonItem::hoverMoveEvent(hoverEvent);
}

void MaxQGraphicsPolygonItem::defaultInputMethodEvent(QInputMethodEvent * event) {
	QGraphicsPolygonItem::inputMethodEvent(event);
}

void MaxQGraphicsPolygonItem::defaultKeyPressEvent(QKeyEvent * keyEvent) {
	QGraphicsPolygonItem::keyPressEvent(keyEvent);
}

void MaxQGraphicsPolygonItem::defaultKeyReleaseEvent(QKeyEvent * keyEvent) {
	QGraphicsPolygonItem::keyReleaseEvent(keyEvent);
}

void MaxQGraphicsPolygonItem::defaultMouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsPolygonItem::mouseDoubleClickEvent(mouseEvent);
}

void MaxQGraphicsPolygonItem::defaultMouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsPolygonItem::mouseMoveEvent(mouseEvent);
}

void MaxQGraphicsPolygonItem::defaultMousePressEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsPolygonItem::mousePressEvent(mouseEvent);
}

void MaxQGraphicsPolygonItem::defaultMouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsPolygonItem::mouseReleaseEvent(mouseEvent);
}

void MaxQGraphicsPolygonItem::defaultSceneEvent(QEvent * event) {
	QGraphicsPolygonItem::sceneEvent(event);
}

void MaxQGraphicsPolygonItem::defaultSceneEventFilter(QGraphicsItem * watched, QEvent * event) {
	QGraphicsPolygonItem::sceneEventFilter(watched, event);
}

void MaxQGraphicsPolygonItem::defaultWheelEvent(QGraphicsSceneWheelEvent * wheelEvent) {
	QGraphicsPolygonItem::wheelEvent(wheelEvent);
}

// *********************************************


QGraphicsPolygonItem * bmx_qt_qgraphicspolygonitem_create(BBObject * handle, QGraphicsItem * parent) {
	return new MaxQGraphicsPolygonItem(handle, parent);
}

QGraphicsPolygonItem * bmx_qt_qgraphicspolygonitem_createwithpoly(BBObject * handle, MaxQPolygonF * polygon, QGraphicsItem * parent) {
	return new MaxQGraphicsPolygonItem(handle, polygon, parent);
}

int bmx_qt_qgraphicspolygonitem_fillrule(QGraphicsPolygonItem * item) {
	return item->fillRule();
}

MaxQPolygonF * bmx_qt_qgraphicspolygonitem_polygon(QGraphicsPolygonItem * item) {
	return new MaxQPolygonF(item->polygon());
}

void bmx_qt_qgraphicspolygonitem_setfillrule(QGraphicsPolygonItem * item, int rule) {
	item->setFillRule((Qt::FillRule)rule);
}

void bmx_qt_qgraphicspolygonitem_setpolygon(QGraphicsPolygonItem * item, MaxQPolygonF * polygon) {
	item->setPolygon(polygon->Polygon());
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
