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

#include "glue.h"

// ---------------------------------------------------------------------------------------



// *********************************************

void bmx_qt_qgraphicsscenedragdropevent_acceptproposedaction(QGraphicsSceneDragDropEvent * event) {
	event->acceptProposedAction();
}

int bmx_qt_qgraphicsscenedragdropevent_buttons(QGraphicsSceneDragDropEvent * event) {
	return event->buttons();
}

int bmx_qt_qgraphicsscenedragdropevent_dropaction(QGraphicsSceneDragDropEvent * event) {
	return event->dropAction();
}

const QMimeData * bmx_qt_qgraphicsscenedragdropevent_mimedata(QGraphicsSceneDragDropEvent * event) {
	return event->mimeData();
}

int bmx_qt_qgraphicsscenedragdropevent_modifiers(QGraphicsSceneDragDropEvent * event) {
	return event->modifiers();
}

void bmx_qt_qgraphicsscenedragdropevent_pos(QGraphicsSceneDragDropEvent * event, float * x, float * y) {
	QPointF p(event->pos());
	*x = p.x();
	*y = p.y();
}

int bmx_qt_qgraphicsscenedragdropevent_possibleactions(QGraphicsSceneDragDropEvent * event) {
	return event->possibleActions();
}

int bmx_qt_qgraphicsscenedragdropevent_proposedaction(QGraphicsSceneDragDropEvent * event) {
	return event->proposedAction();
}

void bmx_qt_qgraphicsscenedragdropevent_scenepos(QGraphicsSceneDragDropEvent * event, float * x, float * y) {
	QPointF p(event->scenePos());
	*x = p.x();
	*y = p.y();
}

void bmx_qt_qgraphicsscenedragdropevent_screenpos(QGraphicsSceneDragDropEvent * event, int * x, int * y) {
	QPoint p(event->screenPos());
	*x = p.x();
	*y = p.y();
}

void bmx_qt_qgraphicsscenedragdropevent_setdropaction(QGraphicsSceneDragDropEvent * event, int action) {
	event->setDropAction((Qt::DropAction)action);
}

QWidget * bmx_qt_qgraphicsscenedragdropevent_source(QGraphicsSceneDragDropEvent * event) {
	return event->source();
}



// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
