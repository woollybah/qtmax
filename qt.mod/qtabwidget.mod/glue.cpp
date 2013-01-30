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

MaxQTabWidget::MaxQTabWidget(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QTabWidget(parent)
{
	qbind(this, handle);

	connect(this, SIGNAL(currentChanged(int)), SLOT(onCurrentChanged(int)));
	connect(this, SIGNAL(tabCloseRequested(int)), SLOT(onTabCloseRequested(int)));
	connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), SLOT(onCustomContextMenuRequested(const QPoint &)));
}

MaxQTabWidget::~MaxQTabWidget()
{
	qunbind(this);
}

void MaxQTabWidget::onCurrentChanged(int index) {
	_qt_qtabwidget_QTabWidget__OnCurrentChanged(maxHandle, index);
}

void MaxQTabWidget::onTabCloseRequested(int index) {
	_qt_qtabwidget_QTabWidget__OnTabCloseRequested(maxHandle, index);
}

void MaxQTabWidget::onCustomContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}

// ****************** DEFAULT HANDLERS ********************

// QTabWidget
void MaxQTabWidget::defaulttabInserted(int index) {
	QTabWidget::tabInserted(index);
}

void MaxQTabWidget::defaulttabRemoved(int index) {
	QTabWidget::tabRemoved(index);
}

// QWidget
void MaxQTabWidget::defaultactionEvent(QActionEvent * event){
	QTabWidget::actionEvent(event);
}

void MaxQTabWidget::defaultchangeEvent(QEvent * event){
	QTabWidget::changeEvent(event);
}

void MaxQTabWidget::defaultcloseEvent(QCloseEvent * event){
	QTabWidget::closeEvent(event);
}

void MaxQTabWidget::defaultcontextMenuEvent(QContextMenuEvent * event){
	QTabWidget::contextMenuEvent(event);
}

void MaxQTabWidget::defaultdragEnterEvent(QDragEnterEvent * event){
	QTabWidget::dragEnterEvent(event);
}

void MaxQTabWidget::defaultdragLeaveEvent(QDragLeaveEvent * event){
	QTabWidget::dragLeaveEvent(event);
}

void MaxQTabWidget::defaultdragMoveEvent(QDragMoveEvent * event){
	QTabWidget::dragMoveEvent(event);
}

void MaxQTabWidget::defaultdropEvent(QDropEvent * event){
	QTabWidget::dropEvent(event);
}

void MaxQTabWidget::defaultenterEvent(QEvent * event){
	QTabWidget::enterEvent(event);
}

void MaxQTabWidget::defaultfocusInEvent(QFocusEvent * event){
	QTabWidget::focusInEvent(event);
}

bool MaxQTabWidget::defaultfocusNextChild() {
	return QTabWidget::focusNextChild();
}

bool MaxQTabWidget::defaultfocusNextPrevChild(bool next){
	return QTabWidget::focusNextPrevChild(next);
}

void MaxQTabWidget::defaultfocusOutEvent(QFocusEvent * event){
	QTabWidget::focusOutEvent(event);
}

bool MaxQTabWidget::defaultfocusPreviousChild() {
	return QTabWidget::focusPreviousChild();
}

void MaxQTabWidget::defaulthideEvent(QHideEvent * event){
	QTabWidget::hideEvent(event);
}

void MaxQTabWidget::defaultinputMethodEvent(QInputMethodEvent * event){
	QTabWidget::inputMethodEvent(event);
}

void MaxQTabWidget::defaultkeyPressEvent(QKeyEvent * event){
	QTabWidget::keyPressEvent(event);
}

void MaxQTabWidget::defaultkeyReleaseEvent(QKeyEvent * event){
	QTabWidget::keyReleaseEvent(event);
}

void MaxQTabWidget::defaultleaveEvent(QEvent * event){
	QTabWidget::leaveEvent(event);
}

void MaxQTabWidget::defaultmouseDoubleClickEvent(QMouseEvent * event){
	QTabWidget::mouseDoubleClickEvent(event);
}

void MaxQTabWidget::defaultmouseMoveEvent(QMouseEvent * event){
	QTabWidget::mouseMoveEvent(event);
}

void MaxQTabWidget::defaultmousePressEvent(QMouseEvent * event){
	QTabWidget::mousePressEvent(event);
}

void MaxQTabWidget::defaultmouseReleaseEvent(QMouseEvent * event){
	QTabWidget::mouseReleaseEvent(event);
}

void MaxQTabWidget::defaultmoveEvent(QMoveEvent * event){
	QTabWidget::moveEvent(event);
}

void MaxQTabWidget::defaultpaintEvent(QPaintEvent * event){
	QTabWidget::paintEvent(event);
}

void MaxQTabWidget::defaultresizeEvent(QResizeEvent * event){
	QTabWidget::resizeEvent(event);
}

void MaxQTabWidget::defaultshowEvent(QShowEvent * event){
	QTabWidget::showEvent(event);
}

void MaxQTabWidget::defaulttabletEvent(QTabletEvent * event){
	QTabWidget::tabletEvent(event);
}

void MaxQTabWidget::defaultwheelEvent(QWheelEvent * event){
	QTabWidget::wheelEvent(event);
}

// QObject
bool MaxQTabWidget::defaultevent(QEvent * event){
	return QTabWidget::event(event);
}

void MaxQTabWidget::defaulttimerEvent(QTimerEvent * event){
	QTabWidget::timerEvent(event);
}


// ****************** HANDLERS - TO MAX ********************

// QTabWidget
void MaxQTabWidget::tabInserted(int index) {
	_qt_qtabwidget_QTabWidget__tabInserted(maxHandle, index);
}

void MaxQTabWidget::tabRemoved(int index) {
	_qt_qtabwidget_QTabWidget__tabRemoved(maxHandle, index);
}

// QWidget
void MaxQTabWidget::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseMoveEvent(maxHandle, event);
}

void MaxQTabWidget::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mousePressEvent(maxHandle, event);
}

void MaxQTabWidget::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseReleaseEvent(maxHandle, event);
}

void MaxQTabWidget::actionEvent(QActionEvent * event) {
	_qt_qwidget_QWidget__actionEvent(maxHandle, event);
}

void MaxQTabWidget::changeEvent(QEvent * event) {
	_qt_qwidget_QWidget__changeEvent(maxHandle, event);
}

void MaxQTabWidget::closeEvent(QCloseEvent * event) {
	_qt_qwidget_QWidget__closeEvent(maxHandle, event);
}

void MaxQTabWidget::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__contextMenuEvent(maxHandle, event);
}

void MaxQTabWidget::dragEnterEvent(QDragEnterEvent * event) {
	_qt_qwidget_QWidget__dragEnterEvent(maxHandle, event);
}

void MaxQTabWidget::dragLeaveEvent(QDragLeaveEvent * event) {
	_qt_qwidget_QWidget__dragLeaveEvent(maxHandle, event);
}

void MaxQTabWidget::dragMoveEvent(QDragMoveEvent * event) {
	_qt_qwidget_QWidget__dragMoveEvent(maxHandle, event);
}

void MaxQTabWidget::dropEvent(QDropEvent * event) {
	_qt_qwidget_QWidget__dropEvent(maxHandle, event);
}

void MaxQTabWidget::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__enterEvent(maxHandle, event);
}

void MaxQTabWidget::focusInEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusInEvent(maxHandle, event);
}

bool MaxQTabWidget::focusNextChild () {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextChild(maxHandle));
}

bool MaxQTabWidget::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQTabWidget::focusOutEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusOutEvent(maxHandle, event);
}

bool MaxQTabWidget::focusPreviousChild() {
	return static_cast<bool>(_qt_qwidget_QWidget__focusPreviousChild(maxHandle));
}

void MaxQTabWidget::hideEvent(QHideEvent * event) {
	_qt_qwidget_QWidget__hideEvent(maxHandle, event);
}

void MaxQTabWidget::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qwidget_QWidget__inputMethodEvent(maxHandle, event);
}

void MaxQTabWidget::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__leaveEvent(maxHandle, event);
}

void MaxQTabWidget::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyPressEvent(maxHandle, event);
}

void MaxQTabWidget::keyReleaseEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyReleaseEvent(maxHandle, event);
}

void MaxQTabWidget::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseDoubleClickEvent(maxHandle, event);
}

void MaxQTabWidget::moveEvent(QMoveEvent * event) {
	_qt_qwidget_QWidget__moveEvent(maxHandle, event);
}

void MaxQTabWidget::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__paintEvent(maxHandle, event);
}

void MaxQTabWidget::resizeEvent(QResizeEvent * event) {
	_qt_qwidget_QWidget__resizeEvent(maxHandle, event);
}

void MaxQTabWidget::showEvent(QShowEvent * event) {
	_qt_qwidget_QWidget__showEvent(maxHandle, event);
}

void MaxQTabWidget::tabletEvent(QTabletEvent * event) {
	_qt_qwidget_QWidget__tabletEvent(maxHandle, event);
}

void MaxQTabWidget::wheelEvent(QWheelEvent * event) {
	_qt_qwidget_QWidget__wheelEvent(maxHandle, event);
}

// QObject
bool MaxQTabWidget::event(QEvent * event) {
	return static_cast<bool>(_qt_qobject_QObject__event(maxHandle, event));
}

void MaxQTabWidget::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

// QTabWidget
void bmx_qt_qtabwidget_default_tabinserted(MaxQTabWidget * tab, int index) {
	tab->defaulttabInserted(index);
}

void bmx_qt_qtabwidget_default_tabremoved(MaxQTabWidget * tab, int index) {
	tab->defaulttabRemoved(index);
}

// QWidget
void bmx_qt_qtabwidget_default_actionevent(MaxQTabWidget * tab, QActionEvent * event) {
	tab->defaultactionEvent(event);
}

void bmx_qt_qtabwidget_default_changeevent(MaxQTabWidget * tab, QEvent * event) {
	tab->defaultchangeEvent(event);
}

void bmx_qt_qtabwidget_default_closeevent(MaxQTabWidget * tab, QCloseEvent * event) {
	tab->defaultcloseEvent(event);
}

void bmx_qt_qtabwidget_default_contextmenuevent(MaxQTabWidget * tab, QContextMenuEvent * event) {
	tab->defaultcontextMenuEvent(event);
}

void bmx_qt_qtabwidget_default_dragenterevent(MaxQTabWidget * tab, QDragEnterEvent * event) {
	tab->defaultdragEnterEvent(event);
}

void bmx_qt_qtabwidget_default_dragleaveevent(MaxQTabWidget * tab, QDragLeaveEvent * event) {
	tab->defaultdragLeaveEvent(event);
}

void bmx_qt_qtabwidget_default_dragmoveevent(MaxQTabWidget * tab, QDragMoveEvent * event) {
	tab->defaultdragMoveEvent(event);
}

void bmx_qt_qtabwidget_default_dropevent(MaxQTabWidget * tab, QDropEvent * event) {
	tab->defaultdropEvent(event);
}

void bmx_qt_qtabwidget_default_enterevent(MaxQTabWidget * tab, QEvent * event) {
	tab->defaultenterEvent(event);
}

void bmx_qt_qtabwidget_default_focusinevent(MaxQTabWidget * tab, QFocusEvent * event) {
	tab->defaultfocusInEvent(event);
}

int bmx_qt_qtabwidget_default_focusnextprevchild(MaxQTabWidget * tab, int next) {
	return static_cast<int>(tab->defaultfocusNextPrevChild(static_cast<bool>(next)));
}

int bmx_qt_qtabwidget_default_focusnextchild(MaxQTabWidget * tab) {
	return static_cast<int>(tab->defaultfocusNextChild());
}

void bmx_qt_qtabwidget_default_focusoutevent(MaxQTabWidget * tab, QFocusEvent * event) {
	tab->defaultfocusOutEvent(event);
}

int bmx_qt_qtabwidget_default_focuspreviouschild(MaxQTabWidget * tab) {
	return static_cast<int>(tab->defaultfocusPreviousChild());
}

void bmx_qt_qtabwidget_default_hideevent(MaxQTabWidget * tab, QHideEvent * event) {
	tab->defaulthideEvent(event);
}

void bmx_qt_qtabwidget_default_inputmethodevent(MaxQTabWidget * tab, QInputMethodEvent * event) {
	tab->defaultinputMethodEvent(event);
}

void bmx_qt_qtabwidget_default_keypressevent(MaxQTabWidget * tab, QKeyEvent * event) {
	tab->defaultkeyPressEvent(event);
}

void bmx_qt_qtabwidget_default_keyreleaseevent(MaxQTabWidget * tab, QKeyEvent * event) {
	tab->defaultkeyReleaseEvent(event);
}

void bmx_qt_qtabwidget_default_leaveevent(MaxQTabWidget * tab, QEvent * event) {
	tab->defaultleaveEvent(event);
}

void bmx_qt_qtabwidget_default_mousedoubleclickevent(MaxQTabWidget * tab, QMouseEvent * event) {
	tab->defaultmouseDoubleClickEvent(event);
}

void bmx_qt_qtabwidget_default_mousemoveevent(MaxQTabWidget * tab, QMouseEvent * event) {
	tab->defaultmouseMoveEvent(event);
}

void bmx_qt_qtabwidget_default_mousepressevent(MaxQTabWidget * tab, QMouseEvent * event) {
	tab->defaultmousePressEvent(event);
}

void bmx_qt_qtabwidget_default_mousereleaseevent(MaxQTabWidget * tab, QMouseEvent * event) {
	tab->defaultmouseReleaseEvent(event);
}

void bmx_qt_qtabwidget_default_moveevent(MaxQTabWidget * tab, QMoveEvent * event) {
	tab->defaultmoveEvent(event);
}

void bmx_qt_qtabwidget_default_paintevent(MaxQTabWidget * tab, QPaintEvent * event) {
	tab->defaultpaintEvent(event);
}

void bmx_qt_qtabwidget_default_resizeevent(MaxQTabWidget * tab, QResizeEvent * event) {
	tab->defaultresizeEvent(event);
}

void bmx_qt_qtabwidget_default_showevent(MaxQTabWidget * tab, QShowEvent * event) {
	tab->defaultshowEvent(event);
}

void bmx_qt_qtabwidget_default_tabletevent(MaxQTabWidget * tab, QTabletEvent * event) {
	tab->defaulttabletEvent(event);
}

void bmx_qt_qtabwidget_default_wheelevent(MaxQTabWidget * tab, QWheelEvent * event) {
	tab->defaultwheelEvent(event);
}

// QObject
int bmx_qt_qtabwidget_default_event(MaxQTabWidget * tab, QEvent * event) {
	return static_cast<int>(tab->defaultevent(event));
}

void bmx_qt_qtabwidget_default_timerevent(MaxQTabWidget * tab, QTimerEvent * event) {
	tab->defaulttimerEvent(event);
}


// *********************************************

QTabWidget::TabPosition bmx_qt_inttotabposition(int p) {
	switch(p) {
		case 0:
			return QTabWidget::North;
		case 1:
			return QTabWidget::South;
		case 2:
			return QTabWidget::West;
		case 3:
			return QTabWidget::East;
	}
	
	return QTabWidget::North;
}

QTabWidget::TabShape bmx_qt_inttotabshape(int s) {
	switch(s) {
		case 0:
			return QTabWidget::Rounded;
		case 1:
			return QTabWidget::Triangular;
	}
	
	return QTabWidget::Rounded;
}

QTabWidget * bmx_qt_qtabwidget_create(BBObject * handle, QWidget * parent) {
	return new MaxQTabWidget(handle, parent);
}

int bmx_qt_qtabwidget_addtab(QTabWidget * tab, QWidget * page, BBString * label, MaxQIcon * icon) {
	if (icon) {
		return tab->addTab(page, icon->Icon(), qStringFromBBString(label));
	} else {
		return tab->addTab(page, qStringFromBBString(label));
	}
}

void bmx_qt_qtabwidget_clear(QTabWidget * tab) {
	tab->clear();
}

int bmx_qt_qtabwidget_count(QTabWidget * tab) {
	return tab->count();
}

int bmx_qt_qtabwidget_currentindex(QTabWidget * tab) {
	return tab->currentIndex();
}

int bmx_qt_qtabwidget_documentmode(QTabWidget * tab) {
	return tab->documentMode();
}

int bmx_qt_qtabwidget_elidemode(QTabWidget * tab) {
	return tab->elideMode();
}

void bmx_qt_qtabwidget_iconsize(QTabWidget * tab, int * width, int * height) {
	QSize s = tab->iconSize();
	*width = s.width();
	*height = s.height();
}

int bmx_qt_qtabwidget_indexof(QTabWidget * tab, QWidget * w) {
	return tab->indexOf(w);
}

int bmx_qt_qtabwidget_inserttab(QTabWidget * tab, int index, QWidget * page, BBString * label, MaxQIcon * icon) {
	if (icon) {
		return tab->insertTab(index, page, icon->Icon(), qStringFromBBString(label));
	} else {
		return tab->insertTab(index, page, qStringFromBBString(label));
	}
}

int bmx_qt_qtabwidget_ismovable(QTabWidget * tab) {
	return static_cast<int>(tab->isMovable());
}

int bmx_qt_qtabwidget_istabenabled(QTabWidget * tab, int index) {
	return static_cast<int>(tab->isTabEnabled(index));
}

void bmx_qt_qtabwidget_removetab(QTabWidget * tab, int index) {
	tab->removeTab(index);
}

void bmx_qt_qtabwidget_setcornerwidget(QTabWidget * tab, QWidget * widget, int corner) {
	tab->setCornerWidget(widget, bmx_qt_inttocorner(corner));
}

void bmx_qt_qtabwidget_setdocumentmode(QTabWidget * tab, int set) {
	tab->setDocumentMode(set);
}

void bmx_qt_qtabwidget_setelidemode(QTabWidget * tab, int mode) {
	tab->setElideMode(bmx_qt_inttoelidemode(mode));
}

void bmx_qt_qtabwidget_seticonsize(QTabWidget * tab, int width, int height) {
	tab->setIconSize(QSize(width, height));
}

void bmx_qt_qtabwidget_setmovable(QTabWidget * tab, int movable) {
	tab->setMovable(static_cast<bool>(movable));
}

void bmx_qt_qtabwidget_settabenabled(QTabWidget * tab, int index, int enable) {
	tab->setTabEnabled(index, static_cast<bool>(enable));
}

void bmx_qt_qtabwidget_settabicon(QTabWidget * tab, int index, MaxQIcon * icon) {
	tab->setTabIcon(index, icon->Icon());
}

void bmx_qt_qtabwidget_settabposition(QTabWidget * tab, int pos) {
	tab->setTabPosition(bmx_qt_inttotabposition(pos));
}

void bmx_qt_qtabwidget_settabshape(QTabWidget * tab, int shape) {
	tab->setTabShape(bmx_qt_inttotabshape(shape));
}

void bmx_qt_qtabwidget_settabtext(QTabWidget * tab, int index, BBString * label) {
	tab->setTabText(index, qStringFromBBString(label));
}

void bmx_qt_qtabwidget_settabtooltip(QTabWidget * tab, int index, BBString * tip) {
	tab->setTabToolTip(index, qStringFromBBString(tip));
}

void bmx_qt_qtabwidget_settabwhatsthis(QTabWidget * tab, int index, BBString * text) {
	tab->setTabWhatsThis(index, qStringFromBBString(text));
}

void bmx_qt_qtabwidget_settabsclosable(QTabWidget * tab, int closeable) {
	tab->setTabsClosable(static_cast<bool>(closeable));
}

void bmx_qt_qtabwidget_setusesscrollbuttons(QTabWidget * tab, int useButtons) {
	tab->setUsesScrollButtons(static_cast<bool>(useButtons));
}

MaxQIcon * bmx_qt_qtabwidget_tabicon(QTabWidget * tab, int index) {
	return new MaxQIcon(tab->tabIcon(index));
}

int bmx_qt_qtabwidget_tabposition(QTabWidget * tab) {
	return tab->tabPosition();
}

int bmx_qt_qtabwidget_tabshape(QTabWidget * tab) {
	return tab->tabShape();
}

BBString * bmx_qt_qtabwidget_tabtext(QTabWidget * tab, int index) {
	return bbStringFromQString(tab->tabText(index));
}

BBString * bmx_qt_qtabwidget_tabtooltip(QTabWidget * tab, int index) {
	return bbStringFromQString(tab->tabToolTip(index));
}

BBString * bmx_qt_qtabwidget_tabwhatsthis(QTabWidget * tab, int index) {
	return bbStringFromQString(tab->tabWhatsThis(index));
}

int bmx_qt_qtabwidget_tabsclosable(QTabWidget * tab) {
	return static_cast<int>(tab->tabsClosable());
}

int bmx_qt_qtabwidget_usesscrollbuttons(QTabWidget * tab) {
	return static_cast<int>(tab->usesScrollButtons());
}

void bmx_qt_qtabwidget_setcurrentindex(QTabWidget * tab, int index) {
	tab->setCurrentIndex(index);
}

void bmx_qt_qtabwidget_setcurrentwidget(QTabWidget * tab, QWidget * widget) {
	tab->setCurrentWidget(widget);
}

QTabBar * bmx_qt_qtabwidget_tabbar(QTabWidget * tab) {
	QTabBar * tb = tab->tabBar();
	MaxQTabBar::link(tb);
	return tb;
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
