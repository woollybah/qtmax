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

MaxQGraphicsView::MaxQGraphicsView(BBObject * handle, QGraphicsScene * scene, QWidget * parent)
	: maxHandle(handle), QGraphicsView(scene, parent)
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

void MaxQGraphicsView::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
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

void MaxQGraphicsScene::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

void MaxQGraphicsScene::defaultContextMenuEvent(QGraphicsSceneContextMenuEvent * contextMenuEvent) {
	QGraphicsScene::contextMenuEvent(contextMenuEvent);
}

void MaxQGraphicsScene::defaultDragEnterEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsScene::dragEnterEvent(event);
}

void MaxQGraphicsScene::defaultDragLeaveEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsScene::dragLeaveEvent(event);
}

void MaxQGraphicsScene::defaultDragMoveEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsScene::dragMoveEvent(event);
}

void MaxQGraphicsScene::defaultDrawBackground(QPainter * painter, const QRectF & rect) {
	QGraphicsScene::drawBackground(painter, rect);
}

void MaxQGraphicsScene::defaultDrawForeground(QPainter * painter, const QRectF & rect) {
	QGraphicsScene::drawForeground(painter, rect);
}

void MaxQGraphicsScene::defaultDrawItems(QPainter * painter, int numItems, QGraphicsItem * items[], const QStyleOptionGraphicsItem options[], QWidget * widget) {
	QGraphicsScene::drawItems(painter, numItems, items, options, widget);
}

void MaxQGraphicsScene::defaultDropEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsScene::dropEvent(event);
}

void MaxQGraphicsScene::defaultFocusInEvent(QFocusEvent * focusEvent) {
	QGraphicsScene::focusInEvent(focusEvent);
}

void MaxQGraphicsScene::defaultFocusOutEvent(QFocusEvent * focusEvent) {
	QGraphicsScene::focusOutEvent(focusEvent);
}

void MaxQGraphicsScene::defaultHelpEvent(QGraphicsSceneHelpEvent * helpEvent) {
	QGraphicsScene::helpEvent(helpEvent);
}

void MaxQGraphicsScene::defaultInputMethodEvent(QInputMethodEvent * event) {
	QGraphicsScene::inputMethodEvent(event);
}

void MaxQGraphicsScene::defaultKeyPressEvent(QKeyEvent * keyEvent) {
	QGraphicsScene::keyPressEvent(keyEvent);
}

void MaxQGraphicsScene::defaultKeyReleaseEvent(QKeyEvent * keyEvent) {
	QGraphicsScene::keyReleaseEvent(keyEvent);
}

void MaxQGraphicsScene::defaultMouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsScene::mouseDoubleClickEvent(mouseEvent);
}

void MaxQGraphicsScene::defaultMouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void MaxQGraphicsScene::defaultMousePressEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsScene::mousePressEvent(mouseEvent);
}

void MaxQGraphicsScene::defaultMouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void MaxQGraphicsScene::defaultWheelEvent(QGraphicsSceneWheelEvent * wheelEvent) {
	QGraphicsScene::wheelEvent(wheelEvent);
}


void MaxQGraphicsScene::contextMenuEvent(QGraphicsSceneContextMenuEvent * contextMenuEvent) {
	_qt_qgraphicsview_QGraphicsScene__contextMenuEvent(maxHandle, contextMenuEvent);
}

void MaxQGraphicsScene::dragEnterEvent(QGraphicsSceneDragDropEvent * event) {
	_qt_qgraphicsview_QGraphicsScene__dragEnterEvent(maxHandle, event);
}

void MaxQGraphicsScene::dragLeaveEvent(QGraphicsSceneDragDropEvent * event) {
	_qt_qgraphicsview_QGraphicsScene__dragLeaveEvent(maxHandle, event);
}

void MaxQGraphicsScene::dragMoveEvent(QGraphicsSceneDragDropEvent * event) {
	_qt_qgraphicsview_QGraphicsScene__dragMoveEvent(maxHandle, event);
}

void MaxQGraphicsScene::drawBackground(QPainter * painter, const QRectF & rect) {
	_qt_qgraphicsview_QGraphicsScene__drawBackground(maxHandle, painter, new MaxQRectF(rect));
}

void MaxQGraphicsScene::drawForeground(QPainter * painter, const QRectF & rect) {
	_qt_qgraphicsview_QGraphicsScene__drawForeground(maxHandle, painter, new MaxQRectF(rect));
}

void MaxQGraphicsScene::drawItems(QPainter * painter, int numItems, QGraphicsItem * items[], const QStyleOptionGraphicsItem options[], QWidget * widget) {
	// TODO - implement in max code.
	QGraphicsScene::drawItems(painter, numItems, items, options, widget);
}

void MaxQGraphicsScene::dropEvent(QGraphicsSceneDragDropEvent * event) {
	_qt_qgraphicsview_QGraphicsScene__dropEvent(maxHandle, event);
}

void MaxQGraphicsScene::focusInEvent(QFocusEvent * focusEvent) {
	_qt_qgraphicsview_QGraphicsScene__focusInEvent(maxHandle, focusEvent);
}

void MaxQGraphicsScene::focusOutEvent(QFocusEvent * focusEvent) {
	_qt_qgraphicsview_QGraphicsScene__focusOutEvent(maxHandle, focusEvent);
}

void MaxQGraphicsScene::helpEvent(QGraphicsSceneHelpEvent * helpEvent) {
	_qt_qgraphicsview_QGraphicsScene__helpEvent(maxHandle, helpEvent);
}

void MaxQGraphicsScene::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qgraphicsview_QGraphicsScene__inputMethodEvent(maxHandle, event);
}

void MaxQGraphicsScene::keyPressEvent(QKeyEvent * keyEvent) {
	_qt_qgraphicsview_QGraphicsScene__keyPressEvent(maxHandle, keyEvent);
}

void MaxQGraphicsScene::keyReleaseEvent(QKeyEvent * keyEvent) {
	_qt_qgraphicsview_QGraphicsScene__keyReleaseEvent(maxHandle, keyEvent);
}

void MaxQGraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	_qt_qgraphicsview_QGraphicsScene__mouseDoubleClickEvent(maxHandle, mouseEvent);
}

void MaxQGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	_qt_qgraphicsview_QGraphicsScene__mouseMoveEvent(maxHandle, mouseEvent);
}

void MaxQGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	_qt_qgraphicsview_QGraphicsScene__mousePressEvent(maxHandle, mouseEvent);
}

void MaxQGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	_qt_qgraphicsview_QGraphicsScene__mouseReleaseEvent(maxHandle, mouseEvent);
}

void MaxQGraphicsScene::wheelEvent(QGraphicsSceneWheelEvent * wheelEvent) {
	_qt_qgraphicsview_QGraphicsScene__wheelEvent(maxHandle, wheelEvent);
}


// ---------------------------------------------------------------------------------------

MaxQGraphicsPixmapItem::MaxQGraphicsPixmapItem(BBObject * handle, const QPixmap & pixmap, QGraphicsItem * parent)
	: maxHandle(handle), QGraphicsPixmapItem(pixmap, parent)
{
	qbind(this, handle);
}

MaxQGraphicsPixmapItem::~MaxQGraphicsPixmapItem()
{
	qunbind(this);
}

void MaxQGraphicsPixmapItem::defaultContextMenuEvent(QGraphicsSceneContextMenuEvent * contextMenuEvent) {
	QGraphicsPixmapItem::contextMenuEvent(contextMenuEvent);
}

void MaxQGraphicsPixmapItem::defaultDragEnterEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsPixmapItem::dragEnterEvent(event);
}

void MaxQGraphicsPixmapItem::defaultDragLeaveEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsPixmapItem::dragLeaveEvent(event);
}

void MaxQGraphicsPixmapItem::defaultDragMoveEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsPixmapItem::dragMoveEvent(event);
}

void MaxQGraphicsPixmapItem::defaultDropEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsPixmapItem::dropEvent(event);
}

void MaxQGraphicsPixmapItem::defaultFocusInEvent(QFocusEvent * focusEvent) {
	QGraphicsPixmapItem::focusInEvent(focusEvent);
}

void MaxQGraphicsPixmapItem::defaultFocusOutEvent(QFocusEvent * focusEvent) {
	QGraphicsPixmapItem::focusOutEvent(focusEvent);
}

void MaxQGraphicsPixmapItem::defaultHoverEnterEvent(QGraphicsSceneHoverEvent * hoverEvent) {
	QGraphicsPixmapItem::hoverEnterEvent(hoverEvent);
}

void MaxQGraphicsPixmapItem::defaultHoverLeaveEvent(QGraphicsSceneHoverEvent * hoverEvent) {
	QGraphicsPixmapItem::hoverLeaveEvent(hoverEvent);
}

void MaxQGraphicsPixmapItem::defaultHoverMoveEvent(QGraphicsSceneHoverEvent * hoverEvent) {
	QGraphicsPixmapItem::hoverMoveEvent(hoverEvent);
}

void MaxQGraphicsPixmapItem::defaultInputMethodEvent(QInputMethodEvent * event) {
	QGraphicsPixmapItem::inputMethodEvent(event);
}

void MaxQGraphicsPixmapItem::defaultKeyPressEvent(QKeyEvent * keyEvent) {
	QGraphicsPixmapItem::keyPressEvent(keyEvent);
}

void MaxQGraphicsPixmapItem::defaultKeyReleaseEvent(QKeyEvent * keyEvent) {
	QGraphicsPixmapItem::keyReleaseEvent(keyEvent);
}

void MaxQGraphicsPixmapItem::defaultMouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsPixmapItem::mouseDoubleClickEvent(mouseEvent);
}

void MaxQGraphicsPixmapItem::defaultMouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsPixmapItem::mouseMoveEvent(mouseEvent);
}

void MaxQGraphicsPixmapItem::defaultMousePressEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsPixmapItem::mousePressEvent(mouseEvent);
}

void MaxQGraphicsPixmapItem::defaultMouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsPixmapItem::mouseReleaseEvent(mouseEvent);
}

void MaxQGraphicsPixmapItem::defaultSceneEvent(QEvent * event) {
	QGraphicsPixmapItem::sceneEvent(event);
}

void MaxQGraphicsPixmapItem::defaultSceneEventFilter(QGraphicsItem * watched, QEvent * event) {
	QGraphicsPixmapItem::sceneEventFilter(watched, event);
}

void MaxQGraphicsPixmapItem::defaultWheelEvent(QGraphicsSceneWheelEvent * wheelEvent) {
	QGraphicsPixmapItem::wheelEvent(wheelEvent);
}

// *********************************************

MaxQGraphicsItem::MaxQGraphicsItem(BBObject * handle, QGraphicsItem * parent)
	: maxHandle(handle), QGraphicsItem(parent)
{
	qgibind(this, handle);
}

MaxQGraphicsItem::~MaxQGraphicsItem()
{
	qgiunbind(this);
}

QRectF MaxQGraphicsItem::boundingRect () const {
	MaxQRectF * rect = _qt_qgraphicsview_QGraphicsItem__boundingRect(maxHandle);
	if (rect) {
		return rect->Rect();
	}
	
	return QRectF();
}

void MaxQGraphicsItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget) {
	_qt_qgraphicsview_QGraphicsItem__paint(maxHandle, painter, option, widget);
}

void MaxQGraphicsItem::defaultContextMenuEvent(QGraphicsSceneContextMenuEvent * contextMenuEvent) {
	QGraphicsItem::contextMenuEvent(contextMenuEvent);
}

void MaxQGraphicsItem::defaultDragEnterEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsItem::dragEnterEvent(event);
}

void MaxQGraphicsItem::defaultDragLeaveEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsItem::dragLeaveEvent(event);
}

void MaxQGraphicsItem::defaultDragMoveEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsItem::dragMoveEvent(event);
}

void MaxQGraphicsItem::defaultDropEvent(QGraphicsSceneDragDropEvent * event) {
	QGraphicsItem::dropEvent(event);
}

void MaxQGraphicsItem::defaultFocusInEvent(QFocusEvent * focusEvent) {
	QGraphicsItem::focusInEvent(focusEvent);
}

void MaxQGraphicsItem::defaultFocusOutEvent(QFocusEvent * focusEvent) {
	QGraphicsItem::focusOutEvent(focusEvent);
}

void MaxQGraphicsItem::defaultHoverEnterEvent(QGraphicsSceneHoverEvent * hoverEvent) {
	QGraphicsItem::hoverEnterEvent(hoverEvent);
}

void MaxQGraphicsItem::defaultHoverLeaveEvent(QGraphicsSceneHoverEvent * hoverEvent) {
	QGraphicsItem::hoverLeaveEvent(hoverEvent);
}

void MaxQGraphicsItem::defaultHoverMoveEvent(QGraphicsSceneHoverEvent * hoverEvent) {
	QGraphicsItem::hoverMoveEvent(hoverEvent);
}

void MaxQGraphicsItem::defaultInputMethodEvent(QInputMethodEvent * event) {
	QGraphicsItem::inputMethodEvent(event);
}

void MaxQGraphicsItem::defaultKeyPressEvent(QKeyEvent * keyEvent) {
	QGraphicsItem::keyPressEvent(keyEvent);
}

void MaxQGraphicsItem::defaultKeyReleaseEvent(QKeyEvent * keyEvent) {
	QGraphicsItem::keyReleaseEvent(keyEvent);
}

void MaxQGraphicsItem::defaultMouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsItem::mouseDoubleClickEvent(mouseEvent);
}

void MaxQGraphicsItem::defaultMouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsItem::mouseMoveEvent(mouseEvent);
}

void MaxQGraphicsItem::defaultMousePressEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsItem::mousePressEvent(mouseEvent);
}

void MaxQGraphicsItem::defaultMouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent) {
	QGraphicsItem::mouseReleaseEvent(mouseEvent);
}

void MaxQGraphicsItem::defaultSceneEvent(QEvent * event) {
	QGraphicsItem::sceneEvent(event);
}

void MaxQGraphicsItem::defaultSceneEventFilter(QGraphicsItem * watched, QEvent * event) {
	QGraphicsItem::sceneEventFilter(watched, event);
}

void MaxQGraphicsItem::defaultWheelEvent(QGraphicsSceneWheelEvent * wheelEvent) {
	QGraphicsItem::wheelEvent(wheelEvent);
}


// *********************************************

QGraphicsView * bmx_qt_qgraphicsview_create(BBObject * handle, QWidget * parent) {
	return new MaxQGraphicsView(handle, parent);
}

QGraphicsView * bmx_qt_qgraphicsview_createwithscene(BBObject * handle, QGraphicsScene * scene, QWidget * parent) {
	return new MaxQGraphicsView(handle, scene, parent);
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

void bmx_qt_qgraphicsscene_setscenerectrect(QGraphicsScene * scene, MaxQRectF * rect) {
	scene->setSceneRect(rect->Rect());
}

void bmx_qt_qgraphicsscene_setscenerect(QGraphicsScene * scene, double x, double y, double w, double h) {
	scene->setSceneRect(x, y, w, h);
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

void bmx_qt_qgraphicsscene_setbackgroundbrush(QGraphicsScene * scene, MaxQBrush * brush) {
	scene->setBackgroundBrush(brush->Brush());
}

void bmx_qt_qgraphicsscene_setbsptreedepth(QGraphicsScene * scene, int depth) {
	scene->setBspTreeDepth(depth);
}

void bmx_qt_qgraphicsscene_setfocus(QGraphicsScene * scene, int focusReason) {
	scene->setFocus((Qt::FocusReason)focusReason);
}

void bmx_qt_qgraphicsscene_setfocusitem(QGraphicsScene * scene, QGraphicsItem * item, int focusReason) {
	scene->setFocusItem(item, (Qt::FocusReason)focusReason);
}

void bmx_qt_qgraphicsscene_setfont(QGraphicsScene * scene, MaxQFont * font) {
	scene->setFont(font->Font());
}

void bmx_qt_qgraphicsscene_setforegroundbrush(QGraphicsScene * scene, MaxQBrush * brush) {
	scene->setForegroundBrush(brush->Brush());
}

void bmx_qt_qgraphicsscene_setitemindexmethod(QGraphicsScene * scene, int _method) {
	scene->setItemIndexMethod((QGraphicsScene::ItemIndexMethod)_method);
}

void bmx_qt_qgraphicsscene_setpalette(QGraphicsScene * scene, MaxQPalette * palette) {
	scene->setPalette(palette->Palette());
}

void bmx_qt_qgraphicsscene_setselectionarea(QGraphicsScene * scene, MaxQPainterPath * path, int _mode) {
	scene->setSelectionArea(path->Path(), (Qt::ItemSelectionMode)_mode);
}

void bmx_qt_qgraphicsscene_setsortcacheenabled(QGraphicsScene * scene, int enabled) {
	scene->setSortCacheEnabled(static_cast<bool>(enabled));
}

void bmx_qt_qgraphicsscene_setstickyfocus(QGraphicsScene * scene, int enabled) {
	scene->setStickyFocus(static_cast<bool>(enabled));
}

void bmx_qt_qgraphicsscene_setstyle(QGraphicsScene * scene, QStyle * style) {
	scene->setStyle(style);
}

MaxQRectF * bmx_qt_qgraphicsscene_scenerect(QGraphicsScene * scene) {
	return new MaxQRectF(scene->sceneRect());
}

BBArray * bmx_qt_qgraphicsscene_selecteditems(QGraphicsScene * scene) {
	QList<QGraphicsItem *> list = scene->selectedItems();
	int n = list.size();
	
	BBArray * arr = _qt_qgraphicsview_QGraphicsScene__newItems(n);
	
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			_qt_qgraphicsview_QGraphicsScene__setItem(arr, i, list[i]);
		}
	}
	
	return arr;
}

MaxQPainterPath * bmx_qt_qgraphicsscene_selectionarea(QGraphicsScene * scene) {
	return new MaxQPainterPath(scene->selectionArea());
}

void bmx_qt_qgraphicsscene_setactivewindow(QGraphicsScene * scene, QGraphicsWidget * widget) {
	scene->setActiveWindow(widget);
}

double bmx_qt_qgraphicsscene_width(QGraphicsScene * scene) {
	return scene->width();
}

double bmx_qt_qgraphicsscene_height(QGraphicsScene * scene) {
	return scene->height();
}

void bmx_qt_qgraphicsscene_udpate(QGraphicsScene * scene, MaxQRectF * rect) {
	if (rect) {
		scene->update(rect->Rect());
	} else {
		scene->update();
	}
}

int bmx_qt_qgraphicsscene_hasfocus(QGraphicsScene * scene) {
	return static_cast<int>(scene->hasFocus());
}

QGraphicsItem * bmx_qt_qgraphicsscene_itemat(QGraphicsScene * scene, double x, double y) {
	return scene->itemAt(x, y);
}

int bmx_qt_qgraphicsscene_itemindexmethod(QGraphicsScene * scene) {
	return scene->itemIndexMethod();
}

MaxQRectF * bmx_qt_qgraphicsscene_itemsboundingrect(QGraphicsScene * scene) {
	return new MaxQRectF(scene->itemsBoundingRect());
}

QGraphicsItem * bmx_qt_qgraphicsscene_mousegrabberitem(QGraphicsScene * scene) {
	return scene->mouseGrabberItem();
}

MaxQPalette * bmx_qt_qgraphicsscene_palette(QGraphicsScene * scene) {
	return new MaxQPalette(scene->palette());
}

void bmx_qt_qgraphicsscene_removeitem(QGraphicsScene * scene, QGraphicsItem * item) {
	scene->removeItem(item);
}

MaxQGraphicsItemList * bmx_qt_qgraphicsscene_items(QGraphicsScene * scene) {
	return new MaxQGraphicsItemList(scene->items());
}

QGraphicsPixmapItem * bmx_qt_qgraphicsscene_addpixmap(QGraphicsScene * scene, MaxQPixmap * pixmap) {
	return scene->addPixmap(pixmap->Pixmap());
}

// *********************************************

void bmx_qt_qgraphicsscene_defaultdrawbackground(MaxQGraphicsScene * scene, QPainter * painter, MaxQRectF * rect) {
	scene->defaultDrawBackground(painter, rect->Rect());
}

void bmx_qt_qgraphicsscene_defaultdrawforeground(MaxQGraphicsScene * scene, QPainter * painter, MaxQRectF * rect) {
	scene->defaultDrawForeground(painter, rect->Rect());
}

// *********************************************


typedef std::map<QGraphicsItem*, BBObject*> QGraphicsItemPeerMap;

static QGraphicsItemPeerMap qGraphicsItemPeerMap;

void qgibind( QGraphicsItem *obj, BBObject *peer ) {
	if( !obj || peer==&bbNullObject ) return;
	qGraphicsItemPeerMap.insert( std::make_pair( obj,peer ) );
	BBRETAIN( peer );
}

BBObject *qgifind( QGraphicsItem *obj ){
	if( !obj ) return &bbNullObject;
	QGraphicsItemPeerMap::iterator it = qGraphicsItemPeerMap.find( obj );
	if( it != qGraphicsItemPeerMap.end() ) return it->second;
	return &bbNullObject;
}

void qgiunbind(QGraphicsItem *obj) {
	BBObject * peer = qgifind(obj);
	if (peer != &bbNullObject) {
		qGraphicsItemPeerMap.erase(obj);
		_qt_qgraphicsview_QGraphicsItem__Free(peer);
		BBRELEASE(peer);
	}
}

// *********************************************

QGraphicsItem * bmx_qt_qgraphicsitem_create(BBObject * handle, QGraphicsItem * parent) {
	return new MaxQGraphicsItem(handle, parent);
}

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

void bmx_qt_qgraphicsitem_pos(QGraphicsItem * item, double * x, double * y) {
	QPointF p(item->pos());
	*x = p.x();
	*y = p.y();
}

void bmx_qt_qgraphicsitem_removesceneeventfilter(QGraphicsItem * item, QGraphicsItem * filterItem) {
	item->removeSceneEventFilter(filterItem);
}

void bmx_qt_qgraphicsitem_resettransform(QGraphicsItem * item) {
	item->resetTransform();
}

void bmx_qt_qgraphicsitem_rotate(QGraphicsItem * item, double angle) {
	item->rotate(angle);
}

void bmx_qt_qgraphicsitem_scale(QGraphicsItem * item, double sx, double sy) {
	item->scale(sx, sy);
}

QGraphicsScene * bmx_qt_qgraphicsitem_scene(QGraphicsItem * item) {
	return item->scene();
}

MaxQRectF * bmx_qt_qgraphicsitem_sceneboundingrect(QGraphicsItem * item) {
	return new MaxQRectF(item->sceneBoundingRect());
}

void bmx_qt_qgraphicsitem_scenepos(QGraphicsItem * item, double * x, double * y) {
	QPointF p(item->scenePos());
	*x = p.x();
	*y = p.y();
}

MaxQTransform * bmx_qt_qgraphicsitem_scenetransform(QGraphicsItem * item) {
	return new MaxQTransform(item->sceneTransform());
}

void bmx_qt_qgraphicsitem_scroll(QGraphicsItem * item, double dx, double dy, MaxQRectF * rect) {
	if (rect) {
		item->scroll(dx, dy, rect->Rect());
	} else {
		item->scroll(dx, dy);
	}
}

void bmx_qt_qgraphicsitem_update(QGraphicsItem * item, MaxQRectF * rect) {
	if (rect) {
		item->update(rect->Rect());
	} else {
		item->update();
	}
}

void bmx_qt_qgraphicsitem_mapfromitem(QGraphicsItem * gi, QGraphicsItem * item, double x, double y, double * x1, double * y1) {
	QPointF p(gi->mapFromItem(item, x, y));
	*x1 = p.x();
	*y1 = p.y();
}

void bmx_qt_qgraphicsitem_preparegeometrychange(QGraphicsItem * item) {
	MaxQGraphicsItem * i = dynamic_cast<MaxQGraphicsItem*>(item);
	if (i) {
		i->DoPrepareGeometryChange();
	}
}

QGraphicsEffect * bmx_qt_qgraphicsitem_graphicseffect(QGraphicsItem * item) {
	return item->graphicsEffect();
}

void bmx_qt_qgraphicsitem_setgraphicseffect(QGraphicsItem * item, QGraphicsEffect * effect) {
	item->setGraphicsEffect(effect);
}

// *********************************************


void bmx_qt_qgraphicsscene_defaultcontextmenuevent(MaxQGraphicsScene * scene, QGraphicsSceneContextMenuEvent * contextMenuEvent) {
	scene->defaultContextMenuEvent(contextMenuEvent);
}

void bmx_qt_qgraphicsscene_defaultdragenterevent(MaxQGraphicsScene * scene, QGraphicsSceneDragDropEvent * event) {
	scene->defaultDragEnterEvent(event);
}

void bmx_qt_qgraphicsscene_defaultdragleaveevent(MaxQGraphicsScene * scene, QGraphicsSceneDragDropEvent * event) {
	scene->defaultDragLeaveEvent(event);
}

void bmx_qt_qgraphicsscene_defaultdragmoveevent(MaxQGraphicsScene * scene, QGraphicsSceneDragDropEvent * event) {
	scene->defaultDragMoveEvent(event);
}

void bmx_qt_qgraphicsscene_defaultdropevent(MaxQGraphicsScene * scene, QGraphicsSceneDragDropEvent * event) {
	scene->defaultDropEvent(event);
}

void bmx_qt_qgraphicsscene_defaultfocusinevent(MaxQGraphicsScene * scene, QFocusEvent * focusEvent) {
	scene->defaultFocusInEvent(focusEvent);
}

void bmx_qt_qgraphicsscene_defaultfocusoutevent(MaxQGraphicsScene * scene, QFocusEvent * focusEvent) {
	scene->defaultFocusOutEvent(focusEvent);
}

void bmx_qt_qgraphicsscene_defaulthelpevent(MaxQGraphicsScene * scene, QGraphicsSceneHelpEvent * helpEvent) {
	scene->defaultHelpEvent(helpEvent);
}

void bmx_qt_qgraphicsscene_defaultinputmethodevent(MaxQGraphicsScene * scene, QInputMethodEvent * event) {
	scene->defaultInputMethodEvent(event);
}

void bmx_qt_qgraphicsscene_defaultkeypressevent(MaxQGraphicsScene * scene, QKeyEvent * keyEvent) {
	scene->defaultKeyPressEvent(keyEvent);
}

void bmx_qt_qgraphicsscene_defaultkeyreleaseevent(MaxQGraphicsScene * scene, QKeyEvent * keyEvent) {
	scene->defaultKeyReleaseEvent(keyEvent);
}

void bmx_qt_qgraphicsscene_defaultmousedoubleclickevent(MaxQGraphicsScene * scene, QGraphicsSceneMouseEvent * mouseEvent) {
	scene->defaultMouseDoubleClickEvent(mouseEvent);
}

void bmx_qt_qgraphicsscene_defaultmousemoveevent(MaxQGraphicsScene * scene, QGraphicsSceneMouseEvent * mouseEvent) {
	scene->defaultMouseMoveEvent(mouseEvent);
}

void bmx_qt_qgraphicsscene_defaultmousepressevent(MaxQGraphicsScene * scene, QGraphicsSceneMouseEvent * mouseEvent) {
	scene->defaultMousePressEvent(mouseEvent);
}

void bmx_qt_qgraphicsscene_defaultmousereleaseevent(MaxQGraphicsScene * scene, QGraphicsSceneMouseEvent * mouseEvent) {
	scene->defaultMouseReleaseEvent(mouseEvent);
}

void bmx_qt_qgraphicsscene_defaultwheelevent(MaxQGraphicsScene * scene, QGraphicsSceneWheelEvent * wheelEvent) {
	scene->defaultWheelEvent(wheelEvent);
}

// *********************************************

void bmx_qt_qgraphicsitem_defaultcontextmenuevent(void * item, QGraphicsSceneContextMenuEvent * contextMenuEvent) {
	static_cast<MaxQGraphicsEventItem *>(item)->defaultContextMenuEvent(contextMenuEvent);
}


void bmx_qt_qgraphicsitem_defaultdragenterevent(void * item, QGraphicsSceneDragDropEvent * event){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultDragEnterEvent(event);
}

void bmx_qt_qgraphicsitem_defaultdragleaveevent(void * item, QGraphicsSceneDragDropEvent * event){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultDragLeaveEvent(event);
}

void bmx_qt_qgraphicsitem_defaultdragmoveevent(void * item, QGraphicsSceneDragDropEvent * event){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultDragMoveEvent(event);
}

void bmx_qt_qgraphicsitem_defaultdropevent(void * item, QGraphicsSceneDragDropEvent * event){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultDropEvent(event);
}

void bmx_qt_qgraphicsitem_defaultfocusinevent(void * item, QFocusEvent * focusEvent){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultFocusInEvent(focusEvent);
}

void bmx_qt_qgraphicsitem_defaultfocusoutevent(void * item, QFocusEvent * focusEvent){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultFocusOutEvent(focusEvent);
}

void bmx_qt_qgraphicsitem_defaulthoverenterevent(void * item, QGraphicsSceneHoverEvent * hoverEvent){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultHoverEnterEvent(hoverEvent);
}

void bmx_qt_qgraphicsitem_defaulthoverleaveevent(void * item, QGraphicsSceneHoverEvent * hoverEvent){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultHoverLeaveEvent(hoverEvent);
}

void bmx_qt_qgraphicsitem_defaulthovermoveevent(void * item, QGraphicsSceneHoverEvent * hoverEvent){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultHoverMoveEvent(hoverEvent);
}

void bmx_qt_qgraphicsitem_defaultinputmethodevent(void * item, QInputMethodEvent * event){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultInputMethodEvent(event);
}

void bmx_qt_qgraphicsitem_defaultkeypressevent(void * item, QKeyEvent * keyEvent){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultKeyPressEvent(keyEvent);
}

void bmx_qt_qgraphicsitem_defaultkeyreleaseevent(void * item, QKeyEvent * keyEvent){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultKeyReleaseEvent(keyEvent);
}

void bmx_qt_qgraphicsitem_defaultmousedoubleclickevent(void * item, QGraphicsSceneMouseEvent * mouseEvent){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultMouseDoubleClickEvent(mouseEvent);
}

void bmx_qt_qgraphicsitem_defaultmousemoveevent(void * item, QGraphicsSceneMouseEvent * mouseEvent){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultMouseMoveEvent(mouseEvent);
}

void bmx_qt_qgraphicsitem_defaultmousepressevent(void * item, QGraphicsSceneMouseEvent * mouseEvent){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultMousePressEvent(mouseEvent);
}

void bmx_qt_qgraphicsitem_defaultmousereleaseevent(void * item, QGraphicsSceneMouseEvent * mouseEvent){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultMouseReleaseEvent(mouseEvent);
}

void bmx_qt_qgraphicsitem_defaultsceneevent(void * item, QEvent * event){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultSceneEvent(event);
}

void bmx_qt_qgraphicsitem_defaultsceneeventfilter(void * item, QGraphicsItem * watched, QEvent * event){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultSceneEventFilter(watched, event);
}

void bmx_qt_qgraphicsitem_defaultwheelevent(void * item, QGraphicsSceneWheelEvent * wheelEvent){
	static_cast<MaxQGraphicsEventItem *>(item)->defaultWheelEvent(wheelEvent);
}

// *********************************************

MaxQGraphicsItemList::MaxQGraphicsItemList(const QList<QGraphicsItem *> & l)
	: list(l), iter(list.begin())
{
}

MaxQGraphicsItemList::~MaxQGraphicsItemList()
{
}

void MaxQGraphicsItemList::Reset() {
	iter = list.begin();
}

int MaxQGraphicsItemList::HasNext() {
	return static_cast<int>(iter != list.end());
}

QGraphicsItem * MaxQGraphicsItemList::NextObject() {
	return *iter++;
}

int MaxQGraphicsItemList::Size() {
	return list.size();
}

int bmx_qt_qgraphicsitemlist_size(MaxQGraphicsItemList * list) {
	return list->Size();
}

void bmx_qt_qgraphicsitemlist_free(MaxQGraphicsItemList * list) {
	delete list;
}

int bmx_qt_qgraphicsitemlist_hasnext(MaxQGraphicsItemList * list) {
	return list->HasNext();
}

QGraphicsItem * bmx_qt_qgraphicsitemlist_nextobject(MaxQGraphicsItemList * list) {
	return list->NextObject();
}

void bmx_qt_qgraphicsitemlist_reset(MaxQGraphicsItemList * list) {
	list->Reset();
}

// *********************************************

MaxQGraphicsPixmapItem * bmx_qt_qgraphicspixmapitem_create(BBObject * handle, MaxQPixmap * pixmap, QGraphicsItem * parent) {
	if (parent) {
		return new MaxQGraphicsPixmapItem(handle, pixmap->Pixmap(), parent);
	} else {
		return new MaxQGraphicsPixmapItem(handle, pixmap->Pixmap(), 0);
	}
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
