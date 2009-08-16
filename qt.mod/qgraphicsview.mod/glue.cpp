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

MaxQGraphicsView::MaxQGraphicsView(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QGraphicsView(parent)
{
	qbind(this, handle);
}

MaxQGraphicsView::~MaxQGraphicsView()
{
	qunbind(this);
}

// ---------------------------------------------------------------------------------------

MaxQGraphicsScene::MaxQGraphicsScene(BBObject * handle, QObject * parent)
	: maxHandle(handle), QGraphicsScene(parent)
{
	qbind(this, handle);
}

MaxQGraphicsScene::~MaxQGraphicsScene()
{
	qunbind(this);
}

void MaxQGraphicsScene::onChanged(const QList<QRectF> & region) {

}

void MaxQGraphicsScene::onSceneRectChanged(const QRectF & rect) {

}

void MaxQGraphicsScene::onSelectionChanged() {

}

// *********************************************

QGraphicsView * bmx_qt_qgraphicsview_create(BBObject * handle, QWidget * parent) {
	return new MaxQGraphicsView(handle, parent);
}

void bmx_qt_qgraphicsview_setalignment(QGraphicsView * view, int alignment) {
	view->setAlignment((Qt::Alignment)alignment);
}

void bmx_qt_qgraphicsview_setbackgroundbrush(QGraphicsView * view, MaxQBrush * brush) {
	view->setBackgroundBrush(brush->Brush());
}

void bmx_qt_qgraphicsview_setcachemode(QGraphicsView * view, int _mode) {
	view->setCacheMode((QGraphicsView::CacheMode)_mode);
}

void bmx_qt_qgraphicsview_setdragmode(QGraphicsView * view, int _mode) {
	view->setDragMode((QGraphicsView::DragMode)_mode);
}

void bmx_qt_qgraphicsview_setforegroundbrush(QGraphicsView * view, MaxQBrush * brush) {
	view->setForegroundBrush(brush->Brush());
}

void bmx_qt_qgraphicsview_setinteractive(QGraphicsView * view, int allowed) {
	view->setInteractive(static_cast<bool>(allowed));
}

void bmx_qt_qgraphicsview_setmatrix(QGraphicsView * view, MaxQMatrix * matrix, int combine) {
	view->setMatrix(matrix->Matrix(), static_cast<bool>(combine));
}

void bmx_qt_qgraphicsview_setoptimizationflag(QGraphicsView * view, int flag, int enabled) {
	view->setOptimizationFlag((QGraphicsView::OptimizationFlag)flag, static_cast<bool>(enabled));
}

void bmx_qt_qgraphicsview_setoptimizationflags(QGraphicsView * view, int flags) {
	view->setOptimizationFlags((QGraphicsView::OptimizationFlags)flags);
}

void bmx_qt_qgraphicsview_setrenderhint(QGraphicsView * view, int hint, int enabled) {
	view->setRenderHint((QPainter::RenderHint)hint, static_cast<bool>(enabled));
}

void bmx_qt_qgraphicsview_setrenderhints(QGraphicsView * view, int hints) {
	view->setRenderHints((QPainter::RenderHints)hints);
}

void bmx_qt_qgraphicsview_setresizeanchor(QGraphicsView * view, int anchor) {
	view->setResizeAnchor((QGraphicsView::ViewportAnchor)anchor);
}

void bmx_qt_qgraphicsview_setrubberbandselectionmode(QGraphicsView * view, int _mode) {
	view->setRubberBandSelectionMode((Qt::ItemSelectionMode)_mode);
}

void bmx_qt_qgraphicsview_setscene(QGraphicsView * view, QGraphicsScene * scene) {
	view->setScene(scene);
}

void bmx_qt_qgraphicsview_setscenerectrect(QGraphicsView * view, MaxQRectF * rect) {
	view->setSceneRect(rect->Rect());
}

void bmx_qt_qgraphicsview_setscenerect(QGraphicsView * view, double x, double y, double w, double h) {
	view->setSceneRect(x, y, w, h);
}

void bmx_qt_qgraphicsview_settransform(QGraphicsView * view, MaxQTransform * matrix, int combine) {
	view->setTransform(matrix->Transform(), static_cast<bool>(combine));
}

void bmx_qt_qgraphicsview_settransformationanchor(QGraphicsView * view, int anchor) {
	view->setTransformationAnchor((QGraphicsView::ViewportAnchor)anchor);
}


void bmx_qt_qgraphicsview_scale(QGraphicsView * view, double sx, double sy) {
	view->scale(sx, sy);
}

QGraphicsScene * bmx_qt_qgraphicsview_scene(QGraphicsView * view) {
	return view->scene();
}

MaxQRectF * bmx_qt_qgraphicsview_scenerect(QGraphicsView * view) {
	return new MaxQRectF(view->sceneRect());
}

void bmx_qt_qgraphicsview_resetcachedcontent(QGraphicsView * view) {
	view->resetCachedContent();
}

void bmx_qt_qgraphicsview_resetmatrix(QGraphicsView * view) {
	view->resetMatrix();
}

void bmx_qt_qgraphicsview_resettransform(QGraphicsView * view) {
	view->resetTransform();
}

int bmx_qt_qgraphicsview_alignment(QGraphicsView * view) {
	return view->alignment();
}

MaxQBrush * bmx_qt_qgraphicsview_backgroundbrush(QGraphicsView * view) {
	return new MaxQBrush(view->backgroundBrush());
}

int bmx_qt_qgraphicsview_cachemode(QGraphicsView * view) {
	return view->cacheMode();
}

void bmx_qt_qgraphicsview_sizehint(QGraphicsView * view, int * w, int * h) {
	QSize s(view->sizeHint());
	*w = s.width();
	*h = s.height();
}

// *********************************************

QGraphicsScene * bmx_qt_qgraphicsscene_create(BBObject * handle, QObject * parent) {
	return new MaxQGraphicsScene(handle, parent);
}

void bmx_qt_qgraphicsscene_setscenerect(QGraphicsScene * scene, MaxQRectF * rect) {
	scene->setSceneRect(rect->Rect());
}

void bmx_qt_qgraphicsscene_advance(QGraphicsScene * scene) {
	scene->advance();
}

void bmx_qt_qgraphicsscene_clear(QGraphicsScene * scene) {
	scene->clear();
}

void bmx_qt_qgraphicsscene_clearselection(QGraphicsScene * scene) {
	scene->clearSelection();
}

void bmx_qt_qgraphicsscene_additem(QGraphicsScene * scene, void * item) {
	scene->addItem((QGraphicsItem*)item);
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
