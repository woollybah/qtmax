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

MaxQGraphicsSvgItem::MaxQGraphicsSvgItem(BBObject * handle, const QString & fileName, QGraphicsItem * parent)
	: maxHandle(handle), QGraphicsSvgItem(fileName, parent)
{
	qbind(this, handle);
}

MaxQGraphicsSvgItem::~MaxQGraphicsSvgItem()
{
	qunbind(this);
}

// *********************************************


void MaxQGraphicsSvgItem::defaultContextMenuEvent(QGraphicsSceneContextMenuEvent * contextMenuEvent) {
	QGraphicsSvgItem::contextMenuEvent(contextMenuEvent);
}

void MaxQGraphicsSvgItem::defaultDragEnterEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsSvgItem::dragEnterEvent(event);
}

void MaxQGraphicsSvgItem::defaultDragLeaveEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsSvgItem::dragLeaveEvent(event);
}

void MaxQGraphicsSvgItem::defaultDragMoveEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsSvgItem::dragMoveEvent(event);
}

void MaxQGraphicsSvgItem::defaultDropEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsSvgItem::dropEvent(event);
}

void MaxQGraphicsSvgItem::defaultFocusInEvent(QFocusEvent * focusEvent) {
	QGraphicsSvgItem::focusInEvent(focusEvent);
}

void MaxQGraphicsSvgItem::defaultFocusOutEvent(QFocusEvent * focusEvent) {
	QGraphicsSvgItem::focusOutEvent(focusEvent);
}

void MaxQGraphicsSvgItem::defaultHoverEnterEvent(QGraphicsSceneHoverEvent * hoverEvent) {
	QGraphicsSvgItem::hoverEnterEvent(hoverEvent);
}

void MaxQGraphicsSvgItem::defaultHoverLeaveEvent(QGraphicsSceneHoverEvent * hoverEvent) {
	QGraphicsSvgItem::hoverLeaveEvent(hoverEvent);
}

void MaxQGraphicsSvgItem::defaultHoverMoveEvent(QGraphicsSceneHoverEvent * hoverEvent) {
	QGraphicsSvgItem::hoverMoveEvent(hoverEvent);
}

void MaxQGraphicsSvgItem::defaultInputMethodEvent(QInputMethodEvent * event) {
	QGraphicsSvgItem::inputMethodEvent(event);
}

void MaxQGraphicsSvgItem::defaultKeyPressEvent(QKeyEvent * keyEvent) {
	QGraphicsSvgItem::keyPressEvent(keyEvent);
}

void MaxQGraphicsSvgItem::defaultKeyReleaseEvent(QKeyEvent * keyEvent) {
	QGraphicsSvgItem::keyReleaseEvent(keyEvent);
}

void MaxQGraphicsSvgItem::defaultMouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsSvgItem::mouseDoubleClickEvent(mouseEvent);
}

void MaxQGraphicsSvgItem::defaultMouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsSvgItem::mouseMoveEvent(mouseEvent);
}

void MaxQGraphicsSvgItem::defaultMousePressEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsSvgItem::mousePressEvent(mouseEvent);
}

void MaxQGraphicsSvgItem::defaultMouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsSvgItem::mouseReleaseEvent(mouseEvent);
}

void MaxQGraphicsSvgItem::defaultSceneEvent(QEvent * event) {
	QGraphicsSvgItem::sceneEvent(event);
}

void MaxQGraphicsSvgItem::defaultSceneEventFilter(QGraphicsItem * watched, QEvent * event) {
	QGraphicsSvgItem::sceneEventFilter(watched, event);
}

void MaxQGraphicsSvgItem::defaultWheelEvent(QGraphicsSceneWheelEvent * wheelEvent) {
	QGraphicsSvgItem::wheelEvent(wheelEvent);
}

// *********************************************

QGraphicsSvgItem * bmx_qt_qgraphicssvgitem_create(BBObject * handle, BBString * filename, QGraphicsItem * parent) {
	return new QGraphicsSvgItem(qStringFromBBString(filename), parent);
}

int bmx_qt_qgraphicssvgitem_isselected(QGraphicsSvgItem * item) {
	return static_cast<int>(item->isSelected());
}

int bmx_qt_qgraphicssvgitem_isundermouse(QGraphicsSvgItem * item) {
	return static_cast<int>(item->isUnderMouse());
}

int bmx_qt_qgraphicssvgitem_isvisible(QGraphicsSvgItem * item) {
	return static_cast<int>(item->isVisible());
}

int bmx_qt_qgraphicssvgitem_isvisibleto(QGraphicsSvgItem * item, QGraphicsSvgItem * parent) {
	return static_cast<int>(item->isVisibleTo(parent));
}

int bmx_qt_qgraphicssvgitem_iswidget(QGraphicsSvgItem * item) {
	return static_cast<int>(item->isWidget());
}

int bmx_qt_qgraphicssvgitem_iswindow(QGraphicsSvgItem * item) {
	return static_cast<int>(item->isWindow());
}

void bmx_qt_qgraphicssvgitem_setacceptdrops(QGraphicsSvgItem * item, int on) {
	item->setAcceptDrops(static_cast<bool>(on));
}

void bmx_qt_qgraphicssvgitem_setaccepthoverevents(QGraphicsSvgItem * item, int enabled) {
	item->setAcceptHoverEvents(static_cast<bool>(enabled));
}

void bmx_qt_qgraphicssvgitem_setacceptedmousebuttons(QGraphicsSvgItem * item, int buttons) {
	item->setAcceptedMouseButtons((Qt::MouseButtons)buttons);
}

void bmx_qt_qgraphicssvgitem_setboundingregiongranularity(QGraphicsSvgItem * item, double granularity) {
	item->setBoundingRegionGranularity(granularity);
}

void bmx_qt_qgraphicssvgitem_setcachemode(QGraphicsSvgItem * item, int mode, int w, int h) {
	if (w!=0 && h!=0) {
		item->setCacheMode((QGraphicsItem::CacheMode)mode, QSize(w, h)); 
	} else {
		item->setCacheMode((QGraphicsItem::CacheMode)mode); 
	}
}

void bmx_qt_qgraphicssvgitem_setcursor(QGraphicsSvgItem * item, MaxQCursor * cursor) {
	item->setCursor(cursor->Cursor());
}

void bmx_qt_qgraphicssvgitem_setdata(QGraphicsSvgItem * item, int key, BBObject * value) {
	// TODO
//	item->setData
}

void bmx_qt_qgraphicssvgitem_setenabled(QGraphicsSvgItem * item, int enabled) {
	item->setEnabled(static_cast<bool>(enabled));
}

void bmx_qt_qgraphicssvgitem_setflag(QGraphicsSvgItem * item, int flag, int enabled) {
	item->setFlag((QGraphicsItem::GraphicsItemFlag)flag, static_cast<bool>(enabled));
}

void bmx_qt_qgraphicssvgitem_setflags(QGraphicsSvgItem * item, int flags) {
	item->setFlags((QGraphicsItem::GraphicsItemFlags)flags);
}

void bmx_qt_qgraphicssvgitem_setfocus(QGraphicsSvgItem * item, int focusReason) {
	item->setFocus((Qt::FocusReason)focusReason);
}

void bmx_qt_qgraphicssvgitem_setgroup(QGraphicsSvgItem * item, QGraphicsItemGroup * group) {
	item->setGroup(group);
}

void bmx_qt_qgraphicssvgitem_sethandleschildevents(QGraphicsSvgItem * item, int enabled) {
	item->setHandlesChildEvents(static_cast<bool>(enabled));
}

void bmx_qt_qgraphicssvgitem_setopacity(QGraphicsSvgItem * item, double opacity) {
	item->setOpacity(opacity);
}

void bmx_qt_qgraphicssvgitem_setparentitem(QGraphicsSvgItem * item, QGraphicsSvgItem * parent) {
	item->setParentItem(parent);
}

void bmx_qt_qgraphicssvgitem_setpos(QGraphicsSvgItem * item, double x, double y) {
	item->setPos(x, y);
}

void bmx_qt_qgraphicssvgitem_setselected(QGraphicsSvgItem * item, int selected) {
	item->setSelected(static_cast<bool>(selected));
}

void bmx_qt_qgraphicssvgitem_settooltip(QGraphicsSvgItem * item, BBString * toolTip) {
	item->setToolTip(qStringFromBBString(toolTip));
}

void bmx_qt_qgraphicssvgitem_settransform(QGraphicsSvgItem * item, MaxQTransform * matrix, int combine) {
	item->setTransform(matrix->Transform(), static_cast<bool>(combine));
}

void bmx_qt_qgraphicssvgitem_setvisible(QGraphicsSvgItem * item, int visible) {
	item->setVisible(static_cast<bool>(visible));
}

void bmx_qt_qgraphicssvgitem_setzvalue(QGraphicsSvgItem * item, double z) {
	item->setZValue(z);
}

MaxQRectF * bmx_qt_qgraphicssvgitem_boundingrect(QGraphicsSvgItem * item) {
	return new MaxQRectF(item->boundingRect());
}

void bmx_qt_qgraphicssvgitem_addtoscene(QGraphicsSvgItem * item, QGraphicsScene * scene) {
	scene->addItem(item);
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
