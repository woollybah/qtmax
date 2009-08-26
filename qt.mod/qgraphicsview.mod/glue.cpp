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

void MaxQGraphicsView::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__OnPaintEvent(maxHandle, event);
}

void MaxQGraphicsView::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__OnMouseDoubleClickEvent(maxHandle, event);
}

void MaxQGraphicsView::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__OnMouseMoveEvent(maxHandle, event);
}

void MaxQGraphicsView::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__OnMousePressEvent(maxHandle, event);
}

void MaxQGraphicsView::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__OnMouseReleaseEvent(maxHandle, event);
}

void MaxQGraphicsView::actionEvent(QActionEvent * event){
	_qt_qwidget_QWidget__OnActionEvent(maxHandle, event);
}

void MaxQGraphicsView::changeEvent(QEvent * event){
	_qt_qwidget_QWidget__OnChangeEvent(maxHandle, event);
}

void MaxQGraphicsView::closeEvent(QCloseEvent * event){
	_qt_qwidget_QWidget__OnCloseEvent(maxHandle, event);
}

void MaxQGraphicsView::contextMenuEvent(QContextMenuEvent * event){
	_qt_qwidget_QWidget__OnContextMenuEvent(maxHandle, event);
}

void MaxQGraphicsView::dragEnterEvent(QDragEnterEvent * event){
	_qt_qwidget_QWidget__OnDragEnterEvent(maxHandle, event);
}

void MaxQGraphicsView::dragLeaveEvent(QDragLeaveEvent * event){
	_qt_qwidget_QWidget__OnDragLeaveEvent(maxHandle, event);
}

void MaxQGraphicsView::dragMoveEvent(QDragMoveEvent * event){
	_qt_qwidget_QWidget__OnDragMoveEvent(maxHandle, event);
}

void MaxQGraphicsView::dropEvent(QDropEvent * event){
	_qt_qwidget_QWidget__OnDropEvent(maxHandle, event);
}

void MaxQGraphicsView::enterEvent(QEvent * event){
	_qt_qwidget_QWidget__OnEnterEvent(maxHandle, event);
}

void MaxQGraphicsView::focusInEvent(QFocusEvent * event){
	_qt_qwidget_QWidget__OnFocusInEvent(maxHandle, event);
}

void MaxQGraphicsView::focusOutEvent(QFocusEvent * event){
	_qt_qwidget_QWidget__OnFocusOutEvent(maxHandle, event);
}

void MaxQGraphicsView::hideEvent(QHideEvent * event){
	_qt_qwidget_QWidget__OnHideEvent(maxHandle, event);
}

void MaxQGraphicsView::inputMethodEvent(QInputMethodEvent * event){
	_qt_qwidget_QWidget__OnInputMethodEvent(maxHandle, event);
}

void MaxQGraphicsView::keyPressEvent(QKeyEvent * event){
	_qt_qwidget_QWidget__OnKeyPressEvent(maxHandle, event);
}

void MaxQGraphicsView::keyReleaseEvent(QKeyEvent * event){
	_qt_qwidget_QWidget__OnKeyReleaseEvent(maxHandle, event);
}

void MaxQGraphicsView::leaveEvent(QEvent * event){
	_qt_qwidget_QWidget__OnLeaveEvent(maxHandle, event);
}

void MaxQGraphicsView::moveEvent(QMoveEvent * event){
	_qt_qwidget_QWidget__OnMoveEvent(maxHandle, event);
}

void MaxQGraphicsView::resizeEvent(QResizeEvent * event){
	_qt_qwidget_QWidget__OnResizeEvent(maxHandle, event);
}

void MaxQGraphicsView::showEvent(QShowEvent * event){
	_qt_qwidget_QWidget__OnShowEvent(maxHandle, event);
}

void MaxQGraphicsView::tabletEvent(QTabletEvent * event){
	_qt_qwidget_QWidget__OnTabletEvent(maxHandle, event);
}

void MaxQGraphicsView::wheelEvent(QWheelEvent * event){
	_qt_qwidget_QWidget__OnWheelEvent(maxHandle, event);
}

void MaxQGraphicsView::defaultActionEvent(QActionEvent * event) {
	QGraphicsView::actionEvent(event);
}

void MaxQGraphicsView::defaultChangeEvent(QEvent * event) {
	QGraphicsView::changeEvent(event);
}

void MaxQGraphicsView::defaultCloseEvent(QCloseEvent * event) {
	QGraphicsView::closeEvent(event);
}

void MaxQGraphicsView::defaultContextMenuEvent(QContextMenuEvent * event) {
	QGraphicsView::contextMenuEvent(event);
}

void MaxQGraphicsView::defaultDragEnterEvent(QDragEnterEvent * event) {
	QGraphicsView::dragEnterEvent(event);
}

void MaxQGraphicsView::defaultDragLeaveEvent(QDragLeaveEvent * event) {
	QGraphicsView::dragLeaveEvent(event);
}

void MaxQGraphicsView::defaultDragMoveEvent(QDragMoveEvent * event) {
	QGraphicsView::dragMoveEvent(event);
}

void MaxQGraphicsView::defaultDropEvent(QDropEvent * event) {
	QGraphicsView::dropEvent(event);
}

void MaxQGraphicsView::defaultEnterEvent(QEvent * event) {
	QGraphicsView::enterEvent(event);
}

void MaxQGraphicsView::defaultFocusInEvent(QFocusEvent * event) {
	QGraphicsView::focusInEvent(event);
}

void MaxQGraphicsView::defaultFocusOutEvent(QFocusEvent * event) {
	QGraphicsView::focusOutEvent(event);
}

void MaxQGraphicsView::defaultHideEvent(QHideEvent * event) {
	QGraphicsView::hideEvent(event);
}

void MaxQGraphicsView::defaultInputMethodEvent(QInputMethodEvent * event) {
	QGraphicsView::inputMethodEvent(event);
}

void MaxQGraphicsView::defaultKeyPressEvent(QKeyEvent * event) {
	QGraphicsView::keyPressEvent(event);
}

void MaxQGraphicsView::defaultKeyReleaseEvent(QKeyEvent * event) {
	QGraphicsView::keyReleaseEvent(event);
}

void MaxQGraphicsView::defaultLeaveEvent(QEvent * event) {
	QGraphicsView::leaveEvent(event);
}

void MaxQGraphicsView::defaultMoveEvent(QMoveEvent * event) {
	QGraphicsView::moveEvent(event);
}

void MaxQGraphicsView::defaultPaintEvent(QPaintEvent * event) {
	QGraphicsView::paintEvent(event);
}

void MaxQGraphicsView::defaultMouseDoubleClickEvent(QMouseEvent * event) {
	QGraphicsView::mouseDoubleClickEvent(event);
}

void MaxQGraphicsView::defaultMouseMoveEvent(QMouseEvent * event) {
	QGraphicsView::mouseMoveEvent(event);
}

void MaxQGraphicsView::defaultMousePressEvent(QMouseEvent * event) {
	QGraphicsView::mousePressEvent(event);
}

void MaxQGraphicsView::defaultMouseReleaseEvent(QMouseEvent * event) {
	QGraphicsView::mouseReleaseEvent(event);
}

void MaxQGraphicsView::defaultResizeEvent(QResizeEvent * event) {
	QGraphicsView::resizeEvent(event);
}

void MaxQGraphicsView::defaultShowEvent(QShowEvent * event) {
	QGraphicsView::showEvent(event);
}

void MaxQGraphicsView::defaultTabletEvent(QTabletEvent * event) {
	QGraphicsView::tabletEvent(event);
}

void MaxQGraphicsView::defaultWheelEvent(QWheelEvent * event) {
	QGraphicsView::wheelEvent(event);
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

void bmx_qt_qgraphicsview_render(QGraphicsView * view, QPainter * painter, MaxQRectF * target, MaxQRect * source, int aspectRatioMode) {
	view->render(painter, (target) ? target->Rect() : QRectF(), (target) ? source->Rect() : QRect(), (Qt::AspectRatioMode)aspectRatioMode);
}

// *********************************************

void bmx_qt_qgraphicsview_default_paintevent(MaxQGraphicsView * widget, QPaintEvent * event) {
	widget->defaultPaintEvent(event);
}

void bmx_qt_qgraphicsview_default_mousedoubleclickevent(MaxQGraphicsView * widget, QMouseEvent * event) {
	widget->defaultMouseDoubleClickEvent(event);
}

void bmx_qt_qgraphicsview_default_mousemoveevent(MaxQGraphicsView * widget, QMouseEvent * event) {
	widget->defaultMouseMoveEvent(event);
}

void bmx_qt_qgraphicsview_default_mousepressevent(MaxQGraphicsView * widget, QMouseEvent * event) {
	widget->defaultMousePressEvent(event);
}

void bmx_qt_qgraphicsview_default_mousereleaseevent(MaxQGraphicsView * widget, QMouseEvent * event) {
	widget->defaultMouseReleaseEvent(event);
}

void bmx_qt_qgraphicsview_default_actionevent(MaxQGraphicsView * widget, QActionEvent * event) {
	widget->defaultActionEvent(event);
}

void bmx_qt_qgraphicsview_default_changeevent(MaxQGraphicsView * widget, QEvent * event) {
	widget->defaultChangeEvent(event);
}

void bmx_qt_qgraphicsview_default_closeevent(MaxQGraphicsView * widget, QCloseEvent * event) {
	widget->defaultCloseEvent(event);
}

void bmx_qt_qgraphicsview_default_contextmenuevent(MaxQGraphicsView * widget, QContextMenuEvent * event) {
	widget->defaultContextMenuEvent(event);
}

void bmx_qt_qgraphicsview_default_dragenterevent(MaxQGraphicsView * widget, QDragEnterEvent * event) {
	widget->defaultDragEnterEvent(event);
}

void bmx_qt_qgraphicsview_default_dragleaveevent(MaxQGraphicsView * widget, QDragLeaveEvent * event) {
	widget->defaultDragLeaveEvent(event);
}

void bmx_qt_qgraphicsview_default_dragmoveevent(MaxQGraphicsView * widget, QDragMoveEvent * event) {
	widget->defaultDragMoveEvent(event);
}

void bmx_qt_qgraphicsview_default_dropevent(MaxQGraphicsView * widget, QDropEvent * event) {
	widget->defaultDropEvent(event);
}

void bmx_qt_qgraphicsview_default_enterevent(MaxQGraphicsView * widget, QEvent * event) {
	widget->defaultEnterEvent(event);
}

void bmx_qt_qgraphicsview_default_focusinevent(MaxQGraphicsView * widget, QFocusEvent * event) {
	widget->defaultFocusInEvent(event);
}

void bmx_qt_qgraphicsview_default_focusoutevent(MaxQGraphicsView * widget, QFocusEvent * event) {
	widget->defaultFocusOutEvent(event);
}

void bmx_qt_qgraphicsview_default_hideevent(MaxQGraphicsView * widget, QHideEvent * event) {
	widget->defaultHideEvent(event);
}

void bmx_qt_qgraphicsview_default_inputmethodevent(MaxQGraphicsView * widget, QInputMethodEvent * event) {
	widget->defaultInputMethodEvent(event);
}

void bmx_qt_qgraphicsview_default_keypressevent(MaxQGraphicsView * widget, QKeyEvent * event) {
	widget->defaultKeyPressEvent(event);
}

void bmx_qt_qgraphicsview_default_keyreleaseevent(MaxQGraphicsView * widget, QKeyEvent * event) {
	widget->defaultKeyReleaseEvent(event);
}

void bmx_qt_qgraphicsview_default_leaveevent(MaxQGraphicsView * widget, QEvent * event) {
	widget->defaultLeaveEvent(event);
}

void bmx_qt_qgraphicsview_default_moveevent(MaxQGraphicsView * widget, QMoveEvent * event) {
	widget->defaultMoveEvent(event);
}

void bmx_qt_qgraphicsview_default_resizeevent(MaxQGraphicsView * widget, QResizeEvent * event) {
	widget->defaultResizeEvent(event);
}

void bmx_qt_qgraphicsview_default_showevent(MaxQGraphicsView * widget, QShowEvent * event) {
	widget->defaultShowEvent(event);
}

void bmx_qt_qgraphicsview_default_tabletevent(MaxQGraphicsView * widget, QTabletEvent * event) {
	widget->defaultTabletEvent(event);
}

void bmx_qt_qgraphicsview_default_wheelevent(MaxQGraphicsView * widget, QWheelEvent * event) {
	widget->defaultWheelEvent(event);
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
