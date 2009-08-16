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



// *********************************************

int bmx_qt_qgraphicsitem_isselected(QGraphicsItem * item) {
	return static_cast<int>(item->isSelected());
}

int bmx_qt_qgraphicsitem_isundermouse(QGraphicsItem * item) {
	return static_cast<int>(item->isUnderMouse());
}

int bmx_qt_qgraphicsitem_isvisible(QGraphicsItem * item) {
	return static_cast<int>(item->isVisible());
}

int bmx_qt_qgraphicsitem_isvisibleto(QGraphicsItem * item, QGraphicsItem * parent) {
	return static_cast<int>(item->isVisibleTo(parent));
}

int bmx_qt_qgraphicsitem_iswidget(QGraphicsItem * item) {
	return static_cast<int>(item->isWidget());
}

int bmx_qt_qgraphicsitem_iswindow(QGraphicsItem * item) {
	return static_cast<int>(item->isWindow());
}

void bmx_qt_qgraphicsitem_setacceptdrops(QGraphicsItem * item, int on) {
	item->setAcceptDrops(static_cast<bool>(on));
}

void bmx_qt_qgraphicsitem_setaccepthoverevents(QGraphicsItem * item, int enabled) {
	item->setAcceptHoverEvents(static_cast<bool>(enabled));
}

void bmx_qt_qgraphicsitem_setacceptedmousebuttons(QGraphicsItem * item, int buttons) {
	item->setAcceptedMouseButtons((Qt::MouseButtons)buttons);
}

void bmx_qt_qgraphicsitem_setboundingregiongranularity(QGraphicsItem * item, double granularity) {
	item->setBoundingRegionGranularity(granularity);
}

void bmx_qt_qgraphicsitem_setcachemode(QGraphicsItem * item, int mode, int w, int h) {
	if (w!=0 && h!=0) {
		item->setCacheMode((QGraphicsItem::CacheMode)mode, QSize(w, h)); 
	} else {
		item->setCacheMode((QGraphicsItem::CacheMode)mode); 
	}
}

void bmx_qt_qgraphicsitem_setcursor(QGraphicsItem * item, MaxQCursor * cursor) {
	item->setCursor(cursor->Cursor());
}

void bmx_qt_qgraphicsitem_setdata(QGraphicsItem * item, int key, BBObject * value) {
	// TODO
//	item->setData
}

void bmx_qt_qgraphicsitem_setenabled(QGraphicsItem * item, int enabled) {
	item->setEnabled(static_cast<bool>(enabled));
}

void bmx_qt_qgraphicsitem_setflag(QGraphicsItem * item, int flag, int enabled) {
	item->setFlag((QGraphicsItem::GraphicsItemFlag)flag, static_cast<bool>(enabled));
}

void bmx_qt_qgraphicsitem_setflags(QGraphicsItem * item, int flags) {
	item->setFlags((QGraphicsItem::GraphicsItemFlags)flags);
}

void bmx_qt_qgraphicsitem_setfocus(QGraphicsItem * item, int focusReason) {
	item->setFocus((Qt::FocusReason)focusReason);
}

void bmx_qt_qgraphicsitem_setgroup(QGraphicsItem * item, QGraphicsItemGroup * group) {
	item->setGroup(group);
}

void bmx_qt_qgraphicsitem_sethandleschildevents(QGraphicsItem * item, int enabled) {
	item->setHandlesChildEvents(static_cast<bool>(enabled));
}

void bmx_qt_qgraphicsitem_setopacity(QGraphicsItem * item, double opacity) {
	item->setOpacity(opacity);
}

void bmx_qt_qgraphicsitem_setparentitem(QGraphicsItem * item, QGraphicsItem * parent) {
	item->setParentItem(parent);
}

void bmx_qt_qgraphicsitem_setpos(QGraphicsItem * item, double x, double y) {
	item->setPos(x, y);
}

void bmx_qt_qgraphicsitem_setselected(QGraphicsItem * item, int selected) {
	item->setSelected(static_cast<bool>(selected));
}

void bmx_qt_qgraphicsitem_settooltip(QGraphicsItem * item, BBString * toolTip) {
	item->setToolTip(qStringFromBBString(toolTip));
}

void bmx_qt_qgraphicsitem_settransform(QGraphicsItem * item, MaxQTransform * matrix, int combine) {
	item->setTransform(matrix->Transform(), static_cast<bool>(combine));
}

void bmx_qt_qgraphicsitem_setvisible(QGraphicsItem * item, int visible) {
	item->setVisible(static_cast<bool>(visible));
}

void bmx_qt_qgraphicsitem_setzvalue(QGraphicsItem * item, double z) {
	item->setZValue(z);
}

MaxQRectF * bmx_qt_qgraphicsitem_boundingrect(QGraphicsItem * item) {
	return new MaxQRectF(item->boundingRect());
}

void bmx_qt_qgraphicsitem_addtoscene(QGraphicsItem * item, QGraphicsScene * scene) {
	scene->addItem(item);
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
