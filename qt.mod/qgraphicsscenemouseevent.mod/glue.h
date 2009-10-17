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

#ifndef MAX_QT_QGRAPHICSSCENEMOUSEEVENT
#define MAX_QT_QGRAPHICSSCENEMOUSEEVENT

#include "../core.mod/glue.h"
#include <QtCore>
#include <QGraphicsSceneMouseEvent>

extern "C" {

#include <blitz.h>

	int bmx_qt_qgraphicsscenemouseevent_button(QGraphicsSceneMouseEvent * event);
	void bmx_qt_qgraphicsscenemouseevent_buttondownpos(QGraphicsSceneMouseEvent * event, int button, float * x, float * y);
	void bmx_qt_qgraphicsscenemouseevent_buttondownscenepos(QGraphicsSceneMouseEvent * event, int button, float * x, float * y);
	void bmx_qt_qgraphicsscenemouseevent_buttondownscreenpos(QGraphicsSceneMouseEvent * event, int button, int * x, int * y);
	int bmx_qt_qgraphicsscenemouseevent_buttons(QGraphicsSceneMouseEvent * event);
	void bmx_qt_qgraphicsscenemouseevent_lastpos(QGraphicsSceneMouseEvent * event, float * x, float * y);
	void bmx_qt_qgraphicsscenemouseevent_lastscenepos(QGraphicsSceneMouseEvent * event, float * x, float * y);
	void bmx_qt_qgraphicsscenemouseevent_lastscreenpos(QGraphicsSceneMouseEvent * event, int * x, int * y);
	int bmx_qt_qgraphicsscenemouseevent_modifiers(QGraphicsSceneMouseEvent * event);
	void bmx_qt_qgraphicsscenemouseevent_pos(QGraphicsSceneMouseEvent * event, float * x, float * y);
	void bmx_qt_qgraphicsscenemouseevent_scenepos(QGraphicsSceneMouseEvent * event, float * x, float * y);
	void bmx_qt_qgraphicsscenemouseevent_screenpos(QGraphicsSceneMouseEvent * event, int * x, int * y);

	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif
