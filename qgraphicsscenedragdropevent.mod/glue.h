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

#ifndef MAX_QT_QGRAPHICSSCENEDRAGDROPEVENT
#define MAX_QT_QGRAPHICSSCENEDRAGDROPEVENT

#include "../core.mod/glue.h"
#include <QtCore>
#include <QGraphicsSceneDragDropEvent>

extern "C" {

#include <blitz.h>

	void bmx_qt_qgraphicsscenedragdropevent_acceptproposedaction(QGraphicsSceneDragDropEvent * event);
	int bmx_qt_qgraphicsscenedragdropevent_buttons(QGraphicsSceneDragDropEvent * event);
	int bmx_qt_qgraphicsscenedragdropevent_dropaction(QGraphicsSceneDragDropEvent * event);
	const QMimeData * bmx_qt_qgraphicsscenedragdropevent_mimedata(QGraphicsSceneDragDropEvent * event);
	int bmx_qt_qgraphicsscenedragdropevent_modifiers(QGraphicsSceneDragDropEvent * event);
	void bmx_qt_qgraphicsscenedragdropevent_pos(QGraphicsSceneDragDropEvent * event, float * x, float * y);
	int bmx_qt_qgraphicsscenedragdropevent_possibleactions(QGraphicsSceneDragDropEvent * event);
	int bmx_qt_qgraphicsscenedragdropevent_proposedaction(QGraphicsSceneDragDropEvent * event);
	void bmx_qt_qgraphicsscenedragdropevent_scenepos(QGraphicsSceneDragDropEvent * event, float * x, float * y);
	void bmx_qt_qgraphicsscenedragdropevent_screenpos(QGraphicsSceneDragDropEvent * event, int * x, int * y);
	void bmx_qt_qgraphicsscenedragdropevent_setdropaction(QGraphicsSceneDragDropEvent * event, int action);
	QWidget * bmx_qt_qgraphicsscenedragdropevent_source(QGraphicsSceneDragDropEvent * event);

	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif
