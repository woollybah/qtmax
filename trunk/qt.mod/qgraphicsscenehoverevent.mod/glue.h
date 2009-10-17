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

#ifndef MAX_QT_QGRAPHICSSCENEHOVEREVENT
#define MAX_QT_QGRAPHICSSCENEHOVEREVENT

#include "../core.mod/glue.h"
#include <QtCore>
#include <QGraphicsSceneHoverEvent>

extern "C" {

#include <blitz.h>

	void bmx_qt_qgraphicsscenehoverevent_lastpos(QGraphicsSceneHoverEvent * event, float * x, float * y);
	void bmx_qt_qgraphicsscenehoverevent_lastscenepos(QGraphicsSceneHoverEvent * event, float * x, float * y);
	void bmx_qt_qgraphicsscenehoverevent_lastscreenpos(QGraphicsSceneHoverEvent * event, int * x, int * y);
	int bmx_qt_qgraphicsscenehoverevent_modifiers(QGraphicsSceneHoverEvent * event);
	void bmx_qt_qgraphicsscenehoverevent_pos(QGraphicsSceneHoverEvent * event, float * x, float * y);
	void bmx_qt_qgraphicsscenehoverevent_scenepos(QGraphicsSceneHoverEvent * event, float * x, float * y);
	void bmx_qt_qgraphicsscenehoverevent_screenpos(QGraphicsSceneHoverEvent * event, int * x, int * y);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#endif
