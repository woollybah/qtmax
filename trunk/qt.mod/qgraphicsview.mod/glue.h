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

#ifndef MAX_QT_QGRAPHICSVIEW
#define MAX_QT_QGRAPHICSVIEW

#include "../core.mod/glue.h"
#include "../qpainterpath.mod/glue.h"
#include "../qbrush.mod/glue.h"
#include <QtCore>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

class MaxQGraphicsView;
class MaxQGraphicsScene;

extern "C" {

#include <blitz.h>

	QGraphicsView * bmx_qt_qgraphicsview_create(BBObject * handle, QWidget * parent);
	void bmx_qt_qgraphicsview_setalignment(QGraphicsView * view, int alignment);
	void bmx_qt_qgraphicsview_setbackgroundbrush(QGraphicsView * view, MaxQBrush * brush);
	void bmx_qt_qgraphicsview_setcachemode(QGraphicsView * view, int _mode);
	void bmx_qt_qgraphicsview_setdragmode(QGraphicsView * view, int _mode);
	void bmx_qt_qgraphicsview_setforegroundbrush(QGraphicsView * view, MaxQBrush * brush);
	void bmx_qt_qgraphicsview_setinteractive(QGraphicsView * view, int allowed);
	void bmx_qt_qgraphicsview_setmatrix(QGraphicsView * view, MaxQMatrix * matrix, int combine);
	void bmx_qt_qgraphicsview_setoptimizationflag(QGraphicsView * view, int flag, int enabled);
	void bmx_qt_qgraphicsview_setoptimizationflags(QGraphicsView * view, int flags);
	void bmx_qt_qgraphicsview_setrenderhint(QGraphicsView * view, int hint, int enabled);
	void bmx_qt_qgraphicsview_setrenderhints(QGraphicsView * view, int hints);
	void bmx_qt_qgraphicsview_setresizeanchor(QGraphicsView * view, int anchor);
	void bmx_qt_qgraphicsview_setrubberbandselectionmode(QGraphicsView * view, int _mode);
	void bmx_qt_qgraphicsview_setscene(QGraphicsView * view, QGraphicsScene * scene);
	void bmx_qt_qgraphicsview_setscenerectrect(QGraphicsView * view, MaxQRectF * rect);
	void bmx_qt_qgraphicsview_setscenerect(QGraphicsView * view, double x, double y, double w, double h);
	void bmx_qt_qgraphicsview_settransform(QGraphicsView * view, MaxQTransform * matrix, int combine);
	void bmx_qt_qgraphicsview_settransformationanchor(QGraphicsView * view, int anchor);

	void bmx_qt_qgraphicsview_scale(QGraphicsView * view, double sx, double sy);
	QGraphicsScene * bmx_qt_qgraphicsview_scene(QGraphicsView * view);
	MaxQRectF * bmx_qt_qgraphicsview_scenerect(QGraphicsView * view);
	void bmx_qt_qgraphicsview_resetcachedcontent(QGraphicsView * view);
	void bmx_qt_qgraphicsview_resetmatrix(QGraphicsView * view);
	void bmx_qt_qgraphicsview_resettransform(QGraphicsView * view);
	int bmx_qt_qgraphicsview_alignment(QGraphicsView * view);
	MaxQBrush * bmx_qt_qgraphicsview_backgroundbrush(QGraphicsView * view);
	int bmx_qt_qgraphicsview_cachemode(QGraphicsView * view);
	void bmx_qt_qgraphicsview_sizehint(QGraphicsView * view, int * w, int * h);

	QGraphicsScene * bmx_qt_qgraphicsscene_create(BBObject * handle, QObject * parent);
	void bmx_qt_qgraphicsscene_setscenerect(QGraphicsScene * scene, MaxQRectF * rect);
	void bmx_qt_qgraphicsscene_advance(QGraphicsScene * scene);
	void bmx_qt_qgraphicsscene_clear(QGraphicsScene * scene);
	void bmx_qt_qgraphicsscene_clearselection(QGraphicsScene * scene);
	void bmx_qt_qgraphicsscene_additem(QGraphicsScene * scene, void * item);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQGraphicsView : public QGraphicsView
{
	Q_OBJECT

public:
	MaxQGraphicsView(BBObject * handle, QWidget * parent);
	~MaxQGraphicsView();

private:
	BBObject * maxHandle;
};

class MaxQGraphicsScene : public QGraphicsScene
{
	Q_OBJECT

public:
	MaxQGraphicsScene(BBObject * handle, QObject * parent);
	~MaxQGraphicsScene();

private:
	BBObject * maxHandle;
	
private slots:
	void onChanged(const QList<QRectF> & region);
	void onSceneRectChanged(const QRectF & rect);
	void onSelectionChanged();
};

#endif
