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

MaxQTabBar::MaxQTabBar(BBObject * handle, QTabBar * tb)
	: tabBar(tb), MaxQObjectWrapper(handle, tb)
{
	doConnections();
}

MaxQTabBar::MaxQTabBar(QTabBar * tb)
	: tabBar(tb), MaxQObjectWrapper(tb)
{
	maxHandle = _qt_qtabbar_QTabBar___create(tb);
	qbind(tb, maxHandle);

	doConnections();
}

MaxQTabBar::~MaxQTabBar()
{
}

QTabBar * MaxQTabBar::TabBar() {
	return tabBar;
}

void MaxQTabBar::link(QTabBar * tb) {
	BBObject * handle = qfind(tb);
	
	if (handle == &bbNullObject) {
		MaxQTabBar * action = new MaxQTabBar(tb);
	}
}

void MaxQTabBar::doConnections() {
	connect(tabBar, SIGNAL(currentChanged(int)), SLOT(onCurrentChanged(int)));
	connect(tabBar, SIGNAL(tabCloseRequested(int)), SLOT(onTabCloseRequested(int)));
	connect(tabBar, SIGNAL(tabMoved(int, int)), SLOT(onTabMoved(int, int)));
	connect(tabBar, SIGNAL(customContextMenuRequested(const QPoint &)), SLOT(onCustomContextMenuRequested(const QPoint &)));
}

void MaxQTabBar::onCurrentChanged(int index) {
	_qt_qtabbar_QTabBar__OnCurrentChanged(maxHandle, index);
}

void MaxQTabBar::onTabCloseRequested(int index) {
	_qt_qtabbar_QTabBar__OnTabCloseRequested(maxHandle, index);
}

void MaxQTabBar::onTabMoved(int from, int to) {
	_qt_qtabbar_QTabBar__OnTabMoved(maxHandle, from, to);
}

void MaxQTabBar::onCustomContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}

// *********************************************

QTabBar * bmx_qt_qtabbar_create(BBObject * handle, QWidget * parent) {
	MaxQTabBar * tb = new MaxQTabBar(handle, new QTabBar(parent));
	return tb->TabBar();
}

int bmx_qt_qtabbar_addtab(QTabBar * tb, BBString * text, MaxQIcon * icon) {
	if (icon) {
		return tb->addTab(icon->Icon(), qStringFromBBString(text));
	} else {
		return tb->addTab(qStringFromBBString(text));
	}
}

int bmx_qt_qtabbar_count(QTabBar * tb) {
	return tb->count();
}

int bmx_qt_qtabbar_currentindex(QTabBar * tb) {
	return tb->currentIndex();
}

int bmx_qt_qtabbar_documentmode(QTabBar * tb) {
	return static_cast<int>(tb->documentMode());
}

int bmx_qt_qtabbar_drawbase(QTabBar * tb) {
	return static_cast<int>(tb->drawBase());
}

int bmx_qt_qtabbar_elidemode(QTabBar * tb) {
	return tb->elideMode();
}

int bmx_qt_qtabbar_expanding(QTabBar * tb) {
	return static_cast<int>(tb->expanding());
}

void bmx_qt_qtabbar_iconsize(QTabBar * tb, int * w, int * h) {
	QSize s(tb->iconSize());
	*w = s.width();
	*h = s.height();
}

int bmx_qt_qtabbar_inserttab(QTabBar * tb, int index, BBString * text, MaxQIcon * icon) {
	if (icon) {
		return tb->insertTab(index, icon->Icon(), qStringFromBBString(text));
	} else {
		return tb->insertTab(index, qStringFromBBString(text));
	}
}

int bmx_qt_qtabbar_ismovable(QTabBar * tb) {
	return static_cast<int>(tb->isMovable());
}

int bmx_qt_qtabbar_istabenabled(QTabBar * tb, int index) {
	return static_cast<int>(tb->isTabEnabled(index));
}

void bmx_qt_qtabbar_movetab(QTabBar * tb, int _from, int _to) {
	tb->moveTab(_from, _to);
}

void bmx_qt_qtabbar_removetab(QTabBar * tb, int index) {
	tb->removeTab(index);
}

int bmx_qt_qtabbar_selectionbehavioronremove(QTabBar * tb) {
	return tb->selectionBehaviorOnRemove();
}

void bmx_qt_qtabbar_setdocumentmode(QTabBar * tb, int set) {
	tb->setDocumentMode(static_cast<bool>(set));
}

void bmx_qt_qtabbar_setdrawbase(QTabBar * tb, int drawTheBase) {
	tb->setDrawBase(static_cast<bool>(drawTheBase));
}

void bmx_qt_qtabbar_setelidemode(QTabBar * tb, int _mode) {
	tb->setElideMode((Qt::TextElideMode)_mode);
}

void bmx_qt_qtabbar_setexpanding(QTabBar * tb, int enabled) {
	tb->setExpanding(static_cast<bool>(enabled));
}

void bmx_qt_qtabbar_seticonsize(QTabBar * tb, int w, int h) {
	tb->setIconSize(QSize(w, h));
}

void bmx_qt_qtabbar_setmovable(QTabBar * tb, int movable) {
	tb->setMovable(static_cast<bool>(movable));
}

void bmx_qt_qtabbar_setselectionbehaviouronremove(QTabBar * tb, int behavior) {
	tb->setSelectionBehaviorOnRemove((QTabBar::SelectionBehavior)behavior);
}

void bmx_qt_qtabbar_setshape(QTabBar * tb, int shape) {
	tb->setShape((QTabBar::Shape)shape);
}

void bmx_qt_qtabbar_settabbutton(QTabBar * tb, int index, int position, QWidget * widget) {
	tb->setTabButton(index, (QTabBar::ButtonPosition)position, widget);
}

void bmx_qt_qtabbar_settabdata(QTabBar * tb, int index, BBInt64 id) {
	tb->setTabData(index, QVariant(id));
}

void bmx_qt_qtabbar_settabenabled(QTabBar * tb, int index, int enabled) {
	tb->setTabEnabled(index, static_cast<bool>(enabled));
}

void bmx_qt_qtabbar_settabicon(QTabBar * tb, int index, MaxQIcon * icon) {
	tb->setTabIcon(index, icon->Icon());
}

void bmx_qt_qtabbar_settabtext(QTabBar * tb, int index, BBString * text) {
	tb->setTabText(index, qStringFromBBString(text));
}

void bmx_qt_qtabbar_settabtextcolor(QTabBar * tb, int index, MaxQColor * color) {
	tb->setTabTextColor(index, color->Color());
}

void bmx_qt_qtabbar_settabtooltip(QTabBar * tb, int index, BBString * tip) {
	tb->setTabToolTip(index, qStringFromBBString(tip));
}

void bmx_qt_qtabbar_settabwhatsthis(QTabBar * tb, int index, BBString * text) {
	tb->setTabWhatsThis(index, qStringFromBBString(text));
}

void bmx_qt_qtabbar_settabsclosable(QTabBar * tb, int closable) {
	tb->setTabsClosable(static_cast<bool>(closable));
}

void bmx_qt_qtabbar_setusesscrollbuttons(QTabBar * tb, int useButtons) {
	tb->setUsesScrollButtons(static_cast<bool>(useButtons));
}

int bmx_qt_qtabbar_shape(QTabBar * tb) {
	return tb->shape();
}

int bmx_qt_qtabbar_tabat(QTabBar * tb, int x, int y) {
	return tb->tabAt(QPoint(x, y));
}

QWidget * bmx_qt_qtabbar_tabbutton(QTabBar * tb, int index, int position) {
	return tb->tabButton(index, (QTabBar::ButtonPosition)position);
}

void bmx_qt_qtabbar_tabdata(QTabBar * tb, int index, BBInt64 * id) {
	QVariant v = tb->tabData(index);
	if (v.type() != QVariant::Invalid) {
		*id = v.toLongLong();
	}
}

MaxQIcon * bmx_qt_qtabbar_tabicon(QTabBar * tb, int index) {
	return new MaxQIcon(tb->tabIcon(index));
}

MaxQRect * bmx_qt_qtabbar_tabrect(QTabBar * tb, int index) {
	return new MaxQRect(tb->tabRect(index));
}

BBString * bmx_qt_qtabbar_tabtext(QTabBar * tb, int index) {
	return bbStringFromQString(tb->tabText(index));
}

MaxQColor * bmx_qt_qtabbar_tabtextcolor(QTabBar * tb, int index) {
	return new MaxQColor(tb->tabTextColor(index));
}

BBString * bmx_qt_qtabbar_tabtooltip(QTabBar * tb, int index) {
	return bbStringFromQString(tb->tabToolTip(index));
}

BBString * bmx_qt_qtabbar_tabwhatsthis(QTabBar * tb, int index) {
	return bbStringFromQString(tb->tabWhatsThis(index));
}

int bmx_qt_qtabbar_tabsclosable(QTabBar * tb) {
	return static_cast<int>(tb->tabsClosable());
}

int bmx_qt_qtabbar_usesscrollbuttons(QTabBar * tb) {
	return static_cast<int>(tb->usesScrollButtons());
}

void bmx_qt_qtabbar_setcurrentindex(QTabBar * tb, int index) {
	tb->setCurrentIndex(index);
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
