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

MaxQTreeView::MaxQTreeView(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QTreeView(parent)
{
	qbind(this, handle);
	
	
	connect(this, SIGNAL(collapsed(const QModelIndex &)), SLOT(onCollapsed(const QModelIndex &)));
	connect(this, SIGNAL(expanded(const QModelIndex &)), SLOT(onExpanded(const QModelIndex &)));
	connect(this, SIGNAL(activated(const QModelIndex &)), SLOT(onActivated(const QModelIndex &)));
	connect(this, SIGNAL(clicked(const QModelIndex &)), SLOT(onClicked(const QModelIndex &)));
	connect(this, SIGNAL(doubleClicked(const QModelIndex &)), SLOT(onDoubleClicked(const QModelIndex &)));
	connect(this, SIGNAL(entered(const QModelIndex &)), SLOT(onEntered(const QModelIndex &)));
	connect(this, SIGNAL(pressed(const QModelIndex &)), SLOT(onPressed(const QModelIndex &)));
	connect(this, SIGNAL(viewportEntered()), SLOT(onViewportEntered()));
	connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), SLOT(onCustomContextMenuRequested(const QPoint &)));
}

MaxQTreeView::~MaxQTreeView()
{
	qunbind(this);
}

void MaxQTreeView::onCollapsed(const QModelIndex & index) {
	_qt_qtreeview_QTreeView__OnCollapsed(maxHandle, new MaxQModelIndex(index));
}

void MaxQTreeView::onExpanded(const QModelIndex & index) {
	_qt_qtreeview_QTreeView__OnExpanded(maxHandle, new MaxQModelIndex(index));
}

void MaxQTreeView::onActivated(const QModelIndex & index) {
	_qt_qabstractitemview_QAbstractItemView__OnActivated(maxHandle, new MaxQModelIndex(index));
}

void MaxQTreeView::onClicked(const QModelIndex & index) {
	_qt_qabstractitemview_QAbstractItemView__OnClicked(maxHandle, new MaxQModelIndex(index));
}

void MaxQTreeView::onDoubleClicked(const QModelIndex & index) {
	_qt_qabstractitemview_QAbstractItemView__OnDoubleClicked(maxHandle, new MaxQModelIndex(index));
}

void MaxQTreeView::onEntered(const QModelIndex & index) {
	_qt_qabstractitemview_QAbstractItemView__OnEntered(maxHandle, new MaxQModelIndex(index));
}

void MaxQTreeView::onPressed(const QModelIndex & index) {
	_qt_qabstractitemview_QAbstractItemView__OnPressed(maxHandle, new MaxQModelIndex(index));
}

void MaxQTreeView::onViewportEntered() {
	_qt_qabstractitemview_QAbstractItemView__OnViewportEntered(maxHandle);
}

void MaxQTreeView::onCustomContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}

QModelIndex MaxQTreeView::indexAt(const QPoint & point) const {
	return QTreeView::indexAt(point);
}

// ****************** DEFAULT HANDLERS ********************

// QTreeView
// QAbstractItemView
// QAbstractScrollArea
void MaxQTreeView::defaultscrollContentsBy(int dx, int dy){
	QTreeView::scrollContentsBy(dx, dy);
}

bool MaxQTreeView::defaultviewportEvent(QEvent * event){
	return QTreeView::viewportEvent(event);
}

// QFrame
// QWidget
void MaxQTreeView::defaultactionEvent(QActionEvent * event){
	QTreeView::actionEvent(event);
}

void MaxQTreeView::defaultchangeEvent(QEvent * event){
	QTreeView::changeEvent(event);
}

void MaxQTreeView::defaultcloseEvent(QCloseEvent * event){
	QTreeView::closeEvent(event);
}

void MaxQTreeView::defaultcontextMenuEvent(QContextMenuEvent * event){
	QTreeView::contextMenuEvent(event);
}

void MaxQTreeView::defaultdragEnterEvent(QDragEnterEvent * event){
	QTreeView::dragEnterEvent(event);
}

void MaxQTreeView::defaultdragLeaveEvent(QDragLeaveEvent * event){
	QTreeView::dragLeaveEvent(event);
}

void MaxQTreeView::defaultdragMoveEvent(QDragMoveEvent * event){
	QTreeView::dragMoveEvent(event);
}

void MaxQTreeView::defaultdropEvent(QDropEvent * event){
	QTreeView::dropEvent(event);
}

void MaxQTreeView::defaultenterEvent(QEvent * event){
	QTreeView::enterEvent(event);
}

void MaxQTreeView::defaultfocusInEvent(QFocusEvent * event){
	QTreeView::focusInEvent(event);
}

bool MaxQTreeView::defaultfocusNextChild() {
	return QTreeView::focusNextChild();
}

bool MaxQTreeView::defaultfocusNextPrevChild(bool next){
	return QTreeView::focusNextPrevChild(next);
}

void MaxQTreeView::defaultfocusOutEvent(QFocusEvent * event){
	QTreeView::focusOutEvent(event);
}

bool MaxQTreeView::defaultfocusPreviousChild() {
	return QTreeView::focusPreviousChild();
}

void MaxQTreeView::defaulthideEvent(QHideEvent * event){
	QTreeView::hideEvent(event);
}

void MaxQTreeView::defaultinputMethodEvent(QInputMethodEvent * event){
	QTreeView::inputMethodEvent(event);
}

void MaxQTreeView::defaultkeyPressEvent(QKeyEvent * event){
	QTreeView::keyPressEvent(event);
}

void MaxQTreeView::defaultkeyReleaseEvent(QKeyEvent * event){
	QTreeView::keyReleaseEvent(event);
}

void MaxQTreeView::defaultleaveEvent(QEvent * event){
	QTreeView::leaveEvent(event);
}

void MaxQTreeView::defaultmouseDoubleClickEvent(QMouseEvent * event){
	QTreeView::mouseDoubleClickEvent(event);
}

void MaxQTreeView::defaultmouseMoveEvent(QMouseEvent * event){
	QTreeView::mouseMoveEvent(event);
}

void MaxQTreeView::defaultmousePressEvent(QMouseEvent * event){
	QTreeView::mousePressEvent(event);
}

void MaxQTreeView::defaultmouseReleaseEvent(QMouseEvent * event){
	QTreeView::mouseReleaseEvent(event);
}

void MaxQTreeView::defaultmoveEvent(QMoveEvent * event){
	QTreeView::moveEvent(event);
}

void MaxQTreeView::defaultpaintEvent(QPaintEvent * event){
	QTreeView::paintEvent(event);
}

void MaxQTreeView::defaultresizeEvent(QResizeEvent * event){
	QTreeView::resizeEvent(event);
}

void MaxQTreeView::defaultshowEvent(QShowEvent * event){
	QTreeView::showEvent(event);
}

void MaxQTreeView::defaulttabletEvent(QTabletEvent * event){
	QTreeView::tabletEvent(event);
}

void MaxQTreeView::defaultwheelEvent(QWheelEvent * event){
	QTreeView::wheelEvent(event);
}

// QObject
bool MaxQTreeView::defaultevent(QEvent * event){
	return QTreeView::event(event);
}

void MaxQTreeView::defaulttimerEvent(QTimerEvent * event){
	QTreeView::timerEvent(event);
}


// ****************** HANDLERS - TO MAX ********************

// QTreeView
// QAbstractItemView
// QAbstractScrollArea
void MaxQTreeView::scrollContentsBy(int dx, int dy) {
	_qt_qabstractscrollarea_QAbstractScrollArea__scrollContentsBy(maxHandle, dx, dy);
}

bool MaxQTreeView::viewportEvent(QEvent * event) {
	return static_cast<bool>(_qt_qabstractscrollarea_QAbstractScrollArea__viewportEvent(maxHandle, event));
}
// QFrame
// QWidget
void MaxQTreeView::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseMoveEvent(maxHandle, event);
}

void MaxQTreeView::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mousePressEvent(maxHandle, event);
}

void MaxQTreeView::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseReleaseEvent(maxHandle, event);
}


void MaxQTreeView::actionEvent(QActionEvent * event) {
	_qt_qwidget_QWidget__actionEvent(maxHandle, event);
}

void MaxQTreeView::changeEvent(QEvent * event) {
	_qt_qwidget_QWidget__changeEvent(maxHandle, event);
}

void MaxQTreeView::closeEvent(QCloseEvent * event) {
	_qt_qwidget_QWidget__closeEvent(maxHandle, event);
}

void MaxQTreeView::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__contextMenuEvent(maxHandle, event);
}

void MaxQTreeView::dragEnterEvent(QDragEnterEvent * event) {
	_qt_qwidget_QWidget__dragEnterEvent(maxHandle, event);
}

void MaxQTreeView::dragLeaveEvent(QDragLeaveEvent * event) {
	_qt_qwidget_QWidget__dragLeaveEvent(maxHandle, event);
}

void MaxQTreeView::dragMoveEvent(QDragMoveEvent * event) {
	_qt_qwidget_QWidget__dragMoveEvent(maxHandle, event);
}

void MaxQTreeView::dropEvent(QDropEvent * event) {
	_qt_qwidget_QWidget__dropEvent(maxHandle, event);
}

void MaxQTreeView::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__enterEvent(maxHandle, event);
}

void MaxQTreeView::focusInEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusInEvent(maxHandle, event);
}

bool MaxQTreeView::focusNextChild () {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextChild(maxHandle));
}

bool MaxQTreeView::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQTreeView::focusOutEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusOutEvent(maxHandle, event);
}

bool MaxQTreeView::focusPreviousChild() {
	return static_cast<bool>(_qt_qwidget_QWidget__focusPreviousChild(maxHandle));
}

void MaxQTreeView::hideEvent(QHideEvent * event) {
	_qt_qwidget_QWidget__hideEvent(maxHandle, event);
}

void MaxQTreeView::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qwidget_QWidget__inputMethodEvent(maxHandle, event);
}

void MaxQTreeView::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__leaveEvent(maxHandle, event);
}

void MaxQTreeView::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyPressEvent(maxHandle, event);
}

void MaxQTreeView::keyReleaseEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyReleaseEvent(maxHandle, event);
}

void MaxQTreeView::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseDoubleClickEvent(maxHandle, event);
}

void MaxQTreeView::moveEvent(QMoveEvent * event) {
	_qt_qwidget_QWidget__moveEvent(maxHandle, event);
}

void MaxQTreeView::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__paintEvent(maxHandle, event);
}

void MaxQTreeView::resizeEvent(QResizeEvent * event) {
	_qt_qwidget_QWidget__resizeEvent(maxHandle, event);
}

void MaxQTreeView::showEvent(QShowEvent * event) {
	_qt_qwidget_QWidget__showEvent(maxHandle, event);
}

void MaxQTreeView::tabletEvent(QTabletEvent * event) {
	_qt_qwidget_QWidget__tabletEvent(maxHandle, event);
}

void MaxQTreeView::wheelEvent(QWheelEvent * event) {
	_qt_qwidget_QWidget__wheelEvent(maxHandle, event);
}

// QObject
bool MaxQTreeView::event(QEvent * event) {
	return static_cast<bool>(_qt_qobject_QObject__event(maxHandle, event));
}

void MaxQTreeView::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

// QTreeView
// QAbstractItemView
// QAbstractScrollArea
void bmx_qt_qtreeview_default_scrollcontentsby(MaxQTreeView * view, int dx, int dy) {
	view->defaultscrollContentsBy(dx, dy);
}

int bmx_qt_qtreeview_default_viewportevent(MaxQTreeView * view, QEvent * event) {
	static_cast<int>(view->defaultviewportEvent(event));
}

// QFrame
// QWidget
void bmx_qt_qtreeview_default_actionevent(MaxQTreeView * view, QActionEvent * event) {
	view->defaultactionEvent(event);
}

void bmx_qt_qtreeview_default_changeevent(MaxQTreeView * view, QEvent * event) {
	view->defaultchangeEvent(event);
}

void bmx_qt_qtreeview_default_closeevent(MaxQTreeView * view, QCloseEvent * event) {
	view->defaultcloseEvent(event);
}

void bmx_qt_qtreeview_default_contextmenuevent(MaxQTreeView * view, QContextMenuEvent * event) {
	view->defaultcontextMenuEvent(event);
}

void bmx_qt_qtreeview_default_dragenterevent(MaxQTreeView * view, QDragEnterEvent * event) {
	view->defaultdragEnterEvent(event);
}

void bmx_qt_qtreeview_default_dragleaveevent(MaxQTreeView * view, QDragLeaveEvent * event) {
	view->defaultdragLeaveEvent(event);
}

void bmx_qt_qtreeview_default_dragmoveevent(MaxQTreeView * view, QDragMoveEvent * event) {
	view->defaultdragMoveEvent(event);
}

void bmx_qt_qtreeview_default_dropevent(MaxQTreeView * view, QDropEvent * event) {
	view->defaultdropEvent(event);
}

void bmx_qt_qtreeview_default_enterevent(MaxQTreeView * view, QEvent * event) {
	view->defaultenterEvent(event);
}

void bmx_qt_qtreeview_default_focusinevent(MaxQTreeView * view, QFocusEvent * event) {
	view->defaultfocusInEvent(event);
}

int bmx_qt_qtreeview_default_focusnextprevchild(MaxQTreeView * view, int next) {
	return static_cast<int>(view->defaultfocusNextPrevChild(static_cast<bool>(next)));
}

int bmx_qt_qtreeview_default_focusnextchild(MaxQTreeView * view) {
	return static_cast<int>(view->defaultfocusNextChild());
}

void bmx_qt_qtreeview_default_focusoutevent(MaxQTreeView * view, QFocusEvent * event) {
	view->defaultfocusOutEvent(event);
}

int bmx_qt_qtreeview_default_focuspreviouschild(MaxQTreeView * view) {
	return static_cast<int>(view->defaultfocusPreviousChild());
}

void bmx_qt_qtreeview_default_hideevent(MaxQTreeView * view, QHideEvent * event) {
	view->defaulthideEvent(event);
}

void bmx_qt_qtreeview_default_inputmethodevent(MaxQTreeView * view, QInputMethodEvent * event) {
	view->defaultinputMethodEvent(event);
}

void bmx_qt_qtreeview_default_keypressevent(MaxQTreeView * view, QKeyEvent * event) {
	view->defaultkeyPressEvent(event);
}

void bmx_qt_qtreeview_default_keyreleaseevent(MaxQTreeView * view, QKeyEvent * event) {
	view->defaultkeyReleaseEvent(event);
}

void bmx_qt_qtreeview_default_leaveevent(MaxQTreeView * view, QEvent * event) {
	view->defaultleaveEvent(event);
}

void bmx_qt_qtreeview_default_mousedoubleclickevent(MaxQTreeView * view, QMouseEvent * event) {
	view->defaultmouseDoubleClickEvent(event);
}

void bmx_qt_qtreeview_default_mousemoveevent(MaxQTreeView * view, QMouseEvent * event) {
	view->defaultmouseMoveEvent(event);
}

void bmx_qt_qtreeview_default_mousepressevent(MaxQTreeView * view, QMouseEvent * event) {
	view->defaultmousePressEvent(event);
}

void bmx_qt_qtreeview_default_mousereleaseevent(MaxQTreeView * view, QMouseEvent * event) {
	view->defaultmouseReleaseEvent(event);
}

void bmx_qt_qtreeview_default_moveevent(MaxQTreeView * view, QMoveEvent * event) {
	view->defaultmoveEvent(event);
}

void bmx_qt_qtreeview_default_paintevent(MaxQTreeView * view, QPaintEvent * event) {
	view->defaultpaintEvent(event);
}

void bmx_qt_qtreeview_default_resizeevent(MaxQTreeView * view, QResizeEvent * event) {
	view->defaultresizeEvent(event);
}

void bmx_qt_qtreeview_default_showevent(MaxQTreeView * view, QShowEvent * event) {
	view->defaultshowEvent(event);
}

void bmx_qt_qtreeview_default_tabletevent(MaxQTreeView * view, QTabletEvent * event) {
	view->defaulttabletEvent(event);
}

void bmx_qt_qtreeview_default_wheelevent(MaxQTreeView * view, QWheelEvent * event) {
	view->defaultwheelEvent(event);
}

// QObject
int bmx_qt_qtreeview_default_event(MaxQTreeView * view, QEvent * event) {
	return static_cast<int>(view->defaultevent(event));
}

void bmx_qt_qtreeview_default_timerevent(MaxQTreeView * view, QTimerEvent * event) {
	view->defaulttimerEvent(event);
}

// *********************************************

QTreeView * bmx_qt_qtreeview_create(BBObject * handle, QWidget * parent) {
	return new MaxQTreeView(handle, parent);
}

int bmx_qt_qtreeview_allcolumnsshowfocus(QTreeView * tv) {
	return static_cast<int>(tv->allColumnsShowFocus());
}

int bmx_qt_qtreeview_autoexpanddelay(QTreeView * tv) {
	return tv->autoExpandDelay();
}

int bmx_qt_qtreeview_columnat(QTreeView * tv, int x) {
	return tv->columnAt(x);
}

int bmx_qt_qtreeview_columnviewportposition(QTreeView * tv, int column) {
	return tv->columnViewportPosition(column);
}

int bmx_qt_qtreeview_columnwidth(QTreeView * tv, int column) {
	return tv->columnWidth(column);
}

int bmx_qt_qtreeview_expandsondoubleclick(QTreeView * tv) {
	return static_cast<int>(tv->expandsOnDoubleClick());
}

QHeaderView * bmx_qt_qtreeview_header(QTreeView * tv) {
	return tv->header();
}

int bmx_qt_qtreeview_indentation(QTreeView * tv) {
	return tv->indentation();
}

MaxQModelIndex * bmx_qt_qtreeview_indexabove(QTreeView * tv, MaxQModelIndex * index) {
	return new MaxQModelIndex(tv->indexAbove(index->Index()));
}

MaxQModelIndex * bmx_qt_qtreeview_indexbelow(QTreeView * tv, MaxQModelIndex * index) {
	return new MaxQModelIndex(tv->indexBelow(index->Index()));
}

int bmx_qt_qtreeview_isanimated(QTreeView * tv) {
	return static_cast<int>(tv->isAnimated());
}

int bmx_qt_qtreeview_iscolumnhidden(QTreeView * tv, int column) {
	return static_cast<int>(tv->isColumnHidden(column));
}

int bmx_qt_qtreeview_isexpanded(QTreeView * tv, MaxQModelIndex * index) {
	return static_cast<int>(tv->isExpanded(index->Index()));
}

int bmx_qt_qtreeview_isfirstcolumnspanned(QTreeView * tv, int row, MaxQModelIndex * parent) {
	return static_cast<int>(tv->isFirstColumnSpanned(row, parent->Index()));
}

int bmx_qt_qtreeview_isheaderhidden(QTreeView * tv) {
	return static_cast<int>(tv->isHeaderHidden());
}

int bmx_qt_qtreeview_isrowhidden(QTreeView * tv, int row, MaxQModelIndex * parent) {
	return static_cast<int>(tv->isRowHidden(row, parent->Index()));
}

int bmx_qt_qtreeview_issortingenabled(QTreeView * tv) {
	return static_cast<int>(tv->isSortingEnabled());
}

int bmx_qt_qtreeview_itemsexpandable(QTreeView * tv) {
	return static_cast<int>(tv->itemsExpandable());
}

int bmx_qt_qtreeview_rootisdecorated(QTreeView * tv) {
	return static_cast<int>(tv->rootIsDecorated());
}

void bmx_qt_qtreeview_setallcolumnsshowfocus(QTreeView * tv, int enable) {
	tv->setAllColumnsShowFocus(static_cast<bool>(enable));
}

void bmx_qt_qtreeview_setanimated(QTreeView * tv, int enable) {
	tv->setAnimated(static_cast<bool>(enable));
}

void bmx_qt_qtreeview_setautoexpanddelay(QTreeView * tv, int _delay) {
	tv->setAutoExpandDelay(_delay);
}

void bmx_qt_qtreeview_setcolumnhidden(QTreeView * tv, int column, int hide) {
	tv->setColumnHidden(column, static_cast<bool>(hide));
}

void bmx_qt_qtreeview_setcolumnwidth(QTreeView * tv, int column, int width) {
	tv->setColumnWidth(column, width);
}

void bmx_qt_qtreeview_setexpanded(QTreeView * tv, MaxQModelIndex * index, int expanded) {
	tv->setExpanded(index->Index(), static_cast<bool>(expanded));
}

void bmx_qt_qtreeview_setexpandsondoubleclick(QTreeView * tv, int enable) {
	tv->setExpandsOnDoubleClick(static_cast<bool>(enable));
}

void bmx_qt_qtreeview_setfirstcolumnspanned(QTreeView * tv, int row, MaxQModelIndex * parent, int span) {
	tv->setFirstColumnSpanned(row, parent->Index(), static_cast<bool>(span));
}

void bmx_qt_qtreeview_setheader(QTreeView * tv, QHeaderView * header) {
	tv->setHeader(header);
}

void bmx_qt_qtreeview_setheaderhidden(QTreeView * tv, int hide) {
	tv->setHeaderHidden(static_cast<bool>(hide));
}

void bmx_qt_qtreeview_setindentation(QTreeView * tv, int i) {
	tv->setIndentation(i);
}

void bmx_qt_qtreeview_setitemsexpandable(QTreeView * tv, int enable) {
	tv->setItemsExpandable(static_cast<bool>(enable));
}

void bmx_qt_qtreeview_setrootisdecorated(QTreeView * tv, int show) {
	tv->setRootIsDecorated(static_cast<bool>(show));
}

void bmx_qt_qtreeview_setrowhidden(QTreeView * tv, int row, MaxQModelIndex * parent, int hide) {
	tv->setRowHidden(row, parent->Index(), static_cast<bool>(hide));
}

void bmx_qt_qtreeview_setsortingenabled(QTreeView * tv, int enable) {
	tv->setSortingEnabled(static_cast<bool>(enable));
}

void bmx_qt_qtreeview_setuniformrowheights(QTreeView * tv, int uniform) {
	tv->setUniformRowHeights(static_cast<bool>(uniform));
}

void bmx_qt_qtreeview_setwordwrap(QTreeView * tv, int on) {
	tv->setWordWrap(static_cast<bool>(on));
}

void bmx_qt_qtreeview_sortbycolumn(QTreeView * tv, int column, int order) {
	tv->sortByColumn(column, (Qt::SortOrder)order);
}

int bmx_qt_qtreeview_uniformrowheights(QTreeView * tv) {
	return static_cast<int>(tv->uniformRowHeights());
}

int bmx_qt_qtreeview_wordwrap(QTreeView * tv) {
	return static_cast<int>(tv->wordWrap());
}


void bmx_qt_qtreeview_collapse(QTreeView * tv, MaxQModelIndex * index) {
	tv->collapse(index->Index());
}

void bmx_qt_qtreeview_collapseall(QTreeView * tv) {
	tv->collapseAll();
}

void bmx_qt_qtreeview_expand(QTreeView * tv, MaxQModelIndex * index) {
	tv->expand(index->Index());
}

void bmx_qt_qtreeview_expandall(QTreeView * tv) {
	tv->expandAll();
}

void bmx_qt_qtreeview_expandtodepth(QTreeView * tv, int depth) {
	tv->expandToDepth(depth);
}

void bmx_qt_qtreeview_hidecolumn(QTreeView * tv, int column) {
	tv->hideColumn(column);
}

void bmx_qt_qtreeview_resizecolumntocontents(QTreeView * tv, int column) {
	tv->resizeColumnToContents(column);
}

void bmx_qt_qtreeview_showcolumn(QTreeView * tv, int column) {
	tv->showColumn(column);
}

MaxQModelIndex * bmx_qt_qtreeview_indexat(QTreeView * tv, int x, int y) {
	return new MaxQModelIndex(tv->indexAt(QPoint(x, y)));
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
