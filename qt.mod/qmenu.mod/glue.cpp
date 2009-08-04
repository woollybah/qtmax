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

MaxQMenu::MaxQMenu(BBObject * handle, const QString & text, QWidget * parent)
	: maxHandle(handle), QMenu(text, parent)
{
	qbind(this, handle);
}

MaxQMenu::MaxQMenu(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QMenu(parent)
{
	qbind(this, handle);
}

MaxQMenu::MaxQMenu(const QString & text, QWidget * parent)
	: QMenu(text, parent)
{
	maxHandle = _qt_qmenu_QMenu___create(this);
	qbind(this, maxHandle);
}

MaxQMenu::~MaxQMenu()
{
	qunbind(this);
}

void MaxQMenu::onAboutToHide() {

}

void MaxQMenu::onAboutToShow() {

}

void MaxQMenu::onHovered(QAction * action) {

}

void MaxQMenu::onTriggered(QAction * action) {

}

void MaxQMenu::customContextMenuRequested(const QPoint & pos) {

}


// *********************************************

QMenu * bmx_qt_qmenu_create(BBObject * handle, QWidget * parent) {
	return new MaxQMenu(handle, parent);
}

QAction * bmx_qt_qmenu_actionat(QMenu * m, int x, int y) {
	QAction * action = m->actionAt(QPoint(x, y));
	MaxQAction::link(action);
	return action;
}

MaxQRect * bmx_qt_qmenu_actiongeometry(QMenu * m, QAction * act) {
	return new MaxQRect(m->actionGeometry(act));
}

QAction * bmx_qt_qmenu_activeaction(QMenu * m) {
	QAction * action = m->activeAction();
	MaxQAction::link(action);
	return action;
}

void bmx_qt_qmenu_addaction(QMenu * m, QAction * action) {
	m->addAction(action);
}

QAction * bmx_qt_qmenu_addactiontxt(QMenu * m, BBString * text) {
	QAction * action = m->addAction(qStringFromBBString(text));
	MaxQAction::link(action);
	return action;
}

QAction * bmx_qt_qmenu_addmenuaction(QMenu * m, QMenu * menu) {
	QAction * action = m->addMenu(menu);
	MaxQAction::link(action);
	return action;
}

QMenu * bmx_qt_qmenu_addmenu(QMenu * m, BBString * title) {
	MaxQMenu * menu = new MaxQMenu(qStringFromBBString(title), m);
	m->addMenu(menu);
	return menu;
}

QAction * bmx_qt_qmenu_addseparator(QMenu * m) {
	QAction * action = m->addSeparator();
	MaxQAction::link(action);
	return action;
}

void bmx_qt_qmenu_clear(QMenu * m) {
	m->clear();
}

QAction * bmx_qt_qmenu_defaultaction(QMenu * m) {
	QAction * action = m->defaultAction();
	MaxQAction::link(action);
	return action;
}

QAction * bmx_qt_qmenu_exec(QMenu * m) {
	QAction * action = m->exec();
	MaxQAction::link(action);
	return action;
}

QAction * bmx_qt_qmenu_execaction(QMenu * m, int x, int y, QAction * a) {
	QAction * action = m->exec(QPoint(x, y),a);
	MaxQAction::link(action);
	return action;
}

void bmx_qt_qmenu_hidetearoffmenu(QMenu * m) {
	m->hideTearOffMenu();
}

QAction * bmx_qt_qmenu_insertmenu(QMenu * m, QAction * before, QMenu * menu) {
	QAction * action = m->insertMenu(before, menu);
	MaxQAction::link(action);
	return action;
}

QAction * bmx_qt_qmenu_insertseparator(QMenu * m, QAction * before) {
	QAction * action = m->insertSeparator(before);
	MaxQAction::link(action);
	return action;
}

int bmx_qt_qmenu_isempty(QMenu * m) {
	return static_cast<int>(m->isEmpty());
}

int bmx_qt_qmenu_istearoffenabled(QMenu * m) {
	return static_cast<int>(m->isTearOffEnabled());
}

int bmx_qt_qmenu_istearoffmenuvisible(QMenu * m) {
	return static_cast<int>(m->isTearOffMenuVisible());
}

QAction * bmx_qt_qmenu_menuaction(QMenu * m) {
	QAction * action = m->menuAction();
	MaxQAction::link(action);
	return action;
}

void bmx_qt_qmenu_popup(QMenu * m, int x, int y, QAction * atAction) {
	m->popup(QPoint(x, y), atAction);
}

int bmx_qt_qmenu_separatorscollapsible(QMenu * m) {
	return static_cast<int>(m->separatorsCollapsible());
}

void bmx_qt_qmenu_setactiveaction(QMenu * m, QAction * act) {
	m->setActiveAction(act);
}

void bmx_qt_qmenu_setdefaultaction(QMenu * m, QAction * act) {
	m->setDefaultAction(act);
}

//void bmx_qt_qmenu_seticon(QMenu * m, MaxQIcon * icon) {
//	m->
//}

void bmx_qt_qmenu_setseparatorscollapsible(QMenu * m, int collapse) {
	m->setSeparatorsCollapsible(static_cast<bool>(collapse));
}

void bmx_qt_qmenu_settearoffenabled(QMenu * m, int value) {
	m->setTearOffEnabled(static_cast<bool>(value));
}

void bmx_qt_qmenu_settitle(QMenu * m, BBString * title) {
	m->setTitle(qStringFromBBString(title));
}

BBString * bmx_qt_qmenu_title(QMenu * m) {
	return bbStringFromQString(m->title());
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
