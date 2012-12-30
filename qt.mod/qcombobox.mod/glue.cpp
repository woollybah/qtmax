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

MaxQComboBox::MaxQComboBox(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QComboBox(parent)
{
	qbind(this, handle);

	connect(this, SIGNAL(activated(int)), SLOT(onActivated(int)));
	connect(this, SIGNAL(currentIndexChanged(int)), SLOT(onCurrentIndexChanged(int)));
	connect(this, SIGNAL(editTextChanged(QString)), SLOT(onEditTextChanged(QString)));
	connect(this, SIGNAL(highlighted(int)), SLOT(onHighlighted(int)));
	connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), SLOT(onCustomContextMenuRequested(const QPoint &)));
}

MaxQComboBox::~MaxQComboBox()
{
	qunbind(this);
}

void MaxQComboBox::onActivated(int index) {
	_qt_qcombobox_QComboBox__OnActivated(maxHandle, index);
}

void MaxQComboBox::onCurrentIndexChanged(int index) {
	_qt_qcombobox_QComboBox__OnCurrentIndexChanged(maxHandle, index);
}

void MaxQComboBox::onEditTextChanged(const QString & text) {
	_qt_qcombobox_QComboBox__OnEditTextChanged(maxHandle, bbStringFromQString(text));
}

void MaxQComboBox::onHighlighted(int index) {
	_qt_qcombobox_QComboBox__OnHighlighted(maxHandle, index);
}

void MaxQComboBox::onCustomContextMenuRequested(const QPoint & pos) {
	_qt_qwidget_QWidget__OnCustomContextMenuRequested(maxHandle, pos.x(), pos.y());
}


// ****************** DEFAULT HANDLERS ********************

// QComboBox

// QWidget
void MaxQComboBox::defaultactionEvent(QActionEvent * event){
	QComboBox::actionEvent(event);
}

void MaxQComboBox::defaultchangeEvent(QEvent * event){
	QComboBox::changeEvent(event);
}

void MaxQComboBox::defaultcloseEvent(QCloseEvent * event){
	QComboBox::closeEvent(event);
}

void MaxQComboBox::defaultcontextMenuEvent(QContextMenuEvent * event){
	QComboBox::contextMenuEvent(event);
}

void MaxQComboBox::defaultdragEnterEvent(QDragEnterEvent * event){
	QComboBox::dragEnterEvent(event);
}

void MaxQComboBox::defaultdragLeaveEvent(QDragLeaveEvent * event){
	QComboBox::dragLeaveEvent(event);
}

void MaxQComboBox::defaultdragMoveEvent(QDragMoveEvent * event){
	QComboBox::dragMoveEvent(event);
}

void MaxQComboBox::defaultdropEvent(QDropEvent * event){
	QComboBox::dropEvent(event);
}

void MaxQComboBox::defaultenterEvent(QEvent * event){
	QComboBox::enterEvent(event);
}

void MaxQComboBox::defaultfocusInEvent(QFocusEvent * event){
	QComboBox::focusInEvent(event);
}

bool MaxQComboBox::defaultfocusNextChild() {
	return QComboBox::focusNextChild();
}

bool MaxQComboBox::defaultfocusNextPrevChild(bool next){
	return QComboBox::focusNextPrevChild(next);
}

void MaxQComboBox::defaultfocusOutEvent(QFocusEvent * event){
	QComboBox::focusOutEvent(event);
}

bool MaxQComboBox::defaultfocusPreviousChild() {
	return QComboBox::focusPreviousChild();
}

void MaxQComboBox::defaulthideEvent(QHideEvent * event){
	QComboBox::hideEvent(event);
}

void MaxQComboBox::defaultinputMethodEvent(QInputMethodEvent * event){
	QComboBox::inputMethodEvent(event);
}

void MaxQComboBox::defaultkeyPressEvent(QKeyEvent * event){
	QComboBox::keyPressEvent(event);
}

void MaxQComboBox::defaultkeyReleaseEvent(QKeyEvent * event){
	QComboBox::keyReleaseEvent(event);
}

void MaxQComboBox::defaultleaveEvent(QEvent * event){
	QComboBox::leaveEvent(event);
}

void MaxQComboBox::defaultmouseDoubleClickEvent(QMouseEvent * event){
	QComboBox::mouseDoubleClickEvent(event);
}

void MaxQComboBox::defaultmouseMoveEvent(QMouseEvent * event){
	QComboBox::mouseMoveEvent(event);
}

void MaxQComboBox::defaultmousePressEvent(QMouseEvent * event){
	QComboBox::mousePressEvent(event);
}

void MaxQComboBox::defaultmouseReleaseEvent(QMouseEvent * event){
	QComboBox::mouseReleaseEvent(event);
}

void MaxQComboBox::defaultmoveEvent(QMoveEvent * event){
	QComboBox::moveEvent(event);
}

void MaxQComboBox::defaultpaintEvent(QPaintEvent * event){
	QComboBox::paintEvent(event);
}

void MaxQComboBox::defaultresizeEvent(QResizeEvent * event){
	QComboBox::resizeEvent(event);
}

void MaxQComboBox::defaultshowEvent(QShowEvent * event){
	QComboBox::showEvent(event);
}

void MaxQComboBox::defaulttabletEvent(QTabletEvent * event){
	QComboBox::tabletEvent(event);
}

void MaxQComboBox::defaultwheelEvent(QWheelEvent * event){
	QComboBox::wheelEvent(event);
}

// QObject
bool MaxQComboBox::defaultevent(QEvent * event){
	return QComboBox::event(event);
}

void MaxQComboBox::defaulttimerEvent(QTimerEvent * event){
	QComboBox::timerEvent(event);
}


// ****************** HANDLERS - TO MAX ********************

// QComboBox

// QWidget

void MaxQComboBox::actionEvent(QActionEvent * event) {
	_qt_qwidget_QWidget__actionEvent(maxHandle, event);
}

void MaxQComboBox::changeEvent(QEvent * event) {
	_qt_qwidget_QWidget__changeEvent(maxHandle, event);
}

void MaxQComboBox::closeEvent(QCloseEvent * event) {
	_qt_qwidget_QWidget__closeEvent(maxHandle, event);
}

void MaxQComboBox::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__contextMenuEvent(maxHandle, event);
}

void MaxQComboBox::dragEnterEvent(QDragEnterEvent * event) {
	_qt_qwidget_QWidget__dragEnterEvent(maxHandle, event);
}

void MaxQComboBox::dragLeaveEvent(QDragLeaveEvent * event) {
	_qt_qwidget_QWidget__dragLeaveEvent(maxHandle, event);
}

void MaxQComboBox::dragMoveEvent(QDragMoveEvent * event) {
	_qt_qwidget_QWidget__dragMoveEvent(maxHandle, event);
}

void MaxQComboBox::dropEvent(QDropEvent * event) {
	_qt_qwidget_QWidget__dropEvent(maxHandle, event);
}

void MaxQComboBox::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__enterEvent(maxHandle, event);
}

void MaxQComboBox::focusInEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusInEvent(maxHandle, event);
}

bool MaxQComboBox::focusNextChild () {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextChild(maxHandle));
}

bool MaxQComboBox::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQComboBox::focusOutEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusOutEvent(maxHandle, event);
}

bool MaxQComboBox::focusPreviousChild() {
	return static_cast<bool>(_qt_qwidget_QWidget__focusPreviousChild(maxHandle));
}

void MaxQComboBox::hideEvent(QHideEvent * event) {
	_qt_qwidget_QWidget__hideEvent(maxHandle, event);
}

void MaxQComboBox::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qwidget_QWidget__inputMethodEvent(maxHandle, event);
}

void MaxQComboBox::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__leaveEvent(maxHandle, event);
}

void MaxQComboBox::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyPressEvent(maxHandle, event);
}

void MaxQComboBox::keyReleaseEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyReleaseEvent(maxHandle, event);
}

void MaxQComboBox::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseDoubleClickEvent(maxHandle, event);
}

void MaxQComboBox::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseMoveEvent(maxHandle, event);
}

void MaxQComboBox::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mousePressEvent(maxHandle, event);
}

void MaxQComboBox::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseReleaseEvent(maxHandle, event);
}

void MaxQComboBox::moveEvent(QMoveEvent * event) {
	_qt_qwidget_QWidget__moveEvent(maxHandle, event);
}

void MaxQComboBox::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__paintEvent(maxHandle, event);
}

void MaxQComboBox::resizeEvent(QResizeEvent * event) {
	_qt_qwidget_QWidget__resizeEvent(maxHandle, event);
}

void MaxQComboBox::showEvent(QShowEvent * event) {
	_qt_qwidget_QWidget__showEvent(maxHandle, event);
}

void MaxQComboBox::tabletEvent(QTabletEvent * event) {
	_qt_qwidget_QWidget__tabletEvent(maxHandle, event);
}

void MaxQComboBox::wheelEvent(QWheelEvent * event) {
	_qt_qwidget_QWidget__wheelEvent(maxHandle, event);
}

// QObject
bool MaxQComboBox::event(QEvent * event) {
	return static_cast<bool>(_qt_qobject_QObject__event(maxHandle, event));
}

void MaxQComboBox::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

// QComboBox

// QWidget
void bmx_qt_qcombobox_default_actionevent(MaxQComboBox * combo, QActionEvent * event) {
	combo->defaultactionEvent(event);
}

void bmx_qt_qcombobox_default_changeevent(MaxQComboBox * combo, QEvent * event) {
	combo->defaultchangeEvent(event);
}

void bmx_qt_qcombobox_default_closeevent(MaxQComboBox * combo, QCloseEvent * event) {
	combo->defaultcloseEvent(event);
}

void bmx_qt_qcombobox_default_contextmenuevent(MaxQComboBox * combo, QContextMenuEvent * event) {
	combo->defaultcontextMenuEvent(event);
}

void bmx_qt_qcombobox_default_dragenterevent(MaxQComboBox * combo, QDragEnterEvent * event) {
	combo->defaultdragEnterEvent(event);
}

void bmx_qt_qcombobox_default_dragleaveevent(MaxQComboBox * combo, QDragLeaveEvent * event) {
	combo->defaultdragLeaveEvent(event);
}

void bmx_qt_qcombobox_default_dragmoveevent(MaxQComboBox * combo, QDragMoveEvent * event) {
	combo->defaultdragMoveEvent(event);
}

void bmx_qt_qcombobox_default_dropevent(MaxQComboBox * combo, QDropEvent * event) {
	combo->defaultdropEvent(event);
}

void bmx_qt_qcombobox_default_enterevent(MaxQComboBox * combo, QEvent * event) {
	combo->defaultenterEvent(event);
}

void bmx_qt_qcombobox_default_focusinevent(MaxQComboBox * combo, QFocusEvent * event) {
	combo->defaultfocusInEvent(event);
}

int bmx_qt_qcombobox_default_focusnextprevchild(MaxQComboBox * combo, int next) {
	return static_cast<int>(combo->defaultfocusNextPrevChild(static_cast<bool>(next)));
}

int bmx_qt_qcombobox_default_focusnextchild(MaxQComboBox * combo) {
	return static_cast<int>(combo->defaultfocusNextChild());
}

void bmx_qt_qcombobox_default_focusoutevent(MaxQComboBox * combo, QFocusEvent * event) {
	combo->defaultfocusOutEvent(event);
}

int bmx_qt_qcombobox_default_focuspreviouschild(MaxQComboBox * combo) {
	return static_cast<int>(combo->defaultfocusPreviousChild());
}

void bmx_qt_qcombobox_default_hideevent(MaxQComboBox * combo, QHideEvent * event) {
	combo->defaulthideEvent(event);
}

void bmx_qt_qcombobox_default_inputmethodevent(MaxQComboBox * combo, QInputMethodEvent * event) {
	combo->defaultinputMethodEvent(event);
}

void bmx_qt_qcombobox_default_keypressevent(MaxQComboBox * combo, QKeyEvent * event) {
	combo->defaultkeyPressEvent(event);
}

void bmx_qt_qcombobox_default_keyreleaseevent(MaxQComboBox * combo, QKeyEvent * event) {
	combo->defaultkeyReleaseEvent(event);
}

void bmx_qt_qcombobox_default_leaveevent(MaxQComboBox * combo, QEvent * event) {
	combo->defaultleaveEvent(event);
}

void bmx_qt_qcombobox_default_mousedoubleclickevent(MaxQComboBox * combo, QMouseEvent * event) {
	combo->defaultmouseDoubleClickEvent(event);
}

void bmx_qt_qcombobox_default_mousemoveevent(MaxQComboBox * combo, QMouseEvent * event) {
	combo->defaultmouseMoveEvent(event);
}

void bmx_qt_qcombobox_default_mousepressevent(MaxQComboBox * combo, QMouseEvent * event) {
	combo->defaultmousePressEvent(event);
}

void bmx_qt_qcombobox_default_mousereleaseevent(MaxQComboBox * combo, QMouseEvent * event) {
	combo->defaultmouseReleaseEvent(event);
}

void bmx_qt_qcombobox_default_moveevent(MaxQComboBox * combo, QMoveEvent * event) {
	combo->defaultmoveEvent(event);
}

void bmx_qt_qcombobox_default_paintevent(MaxQComboBox * combo, QPaintEvent * event) {
	combo->defaultpaintEvent(event);
}

void bmx_qt_qcombobox_default_resizeevent(MaxQComboBox * combo, QResizeEvent * event) {
	combo->defaultresizeEvent(event);
}

void bmx_qt_qcombobox_default_showevent(MaxQComboBox * combo, QShowEvent * event) {
	combo->defaultshowEvent(event);
}

void bmx_qt_qcombobox_default_tabletevent(MaxQComboBox * combo, QTabletEvent * event) {
	combo->defaulttabletEvent(event);
}

void bmx_qt_qcombobox_default_wheelevent(MaxQComboBox * combo, QWheelEvent * event) {
	combo->defaultwheelEvent(event);
}

// QObject
int bmx_qt_qcombobox_default_event(MaxQComboBox * combo, QEvent * event) {
	return static_cast<int>(combo->defaultevent(event));
}

void bmx_qt_qcombobox_default_timerevent(MaxQComboBox * combo, QTimerEvent * event) {
	combo->defaulttimerEvent(event);
}


// *********************************************

QComboBox::InsertPolicy bmx_qt_comboboxIntToInsertPolicy(int p) {
	switch(p) {
		case 0:
			return QComboBox::NoInsert;
		case 1:
			return QComboBox::InsertAtTop;
		case 2:
			return QComboBox::InsertAtCurrent;
		case 3:
			return QComboBox::InsertAtBottom;
		case 4:
			return QComboBox::InsertAfterCurrent;
		case 5:
			return QComboBox::InsertBeforeCurrent;
		case 6:
			return QComboBox::InsertAlphabetically;
	}
	return QComboBox::NoInsert;
}



QComboBox * bmx_qt_qcombobox_create(BBObject * handle, QWidget * parent) {
	return new MaxQComboBox(handle, parent);
}

void bmx_qt_qcombobox_addItem(QComboBox * cb, BBString * text, BBObject * data) {
	QVariant v = QVariant::fromValue<void*>(data);

	cb->addItem(qStringFromBBString(text), v);
}

void bmx_qt_qcombobox_addItems(QComboBox * cb, BBArray * texts) {
	// TODO
}

int bmx_qt_qcombobox_count(QComboBox * cb) {
	return cb->count();
}

int bmx_qt_qcombobox_currentindex(QComboBox * cb) {
	return cb->currentIndex();
}

void bmx_qt_qcombobox_insertitem(QComboBox * cb, int index, BBString * text, BBObject * data) {
	QVariant v = QVariant::fromValue<void*>(data);

	cb->insertItem(index, qStringFromBBString(text), v);
}

BBObject * bmx_qt_qcombobox_itemdata(QComboBox * cb, int index) {
	QVariant v = cb->itemData(index);
	if (v.type() != QVariant::Invalid) {
		return reinterpret_cast<BBObject*>(v.value<void*>());
	}
	
	return &bbNullObject;
}

void bmx_qt_qcombobox_removeitem(QComboBox * cb, int index) {
	cb->removeItem(index);
}

void bmx_qt_qcombobox_setitemdata(QComboBox * cb, int index, BBObject * data) {
	QVariant v = QVariant::fromValue<void*>(data);
	cb->setItemData(index, v);
}

BBString * bmx_qt_qcombobox_currenttext(QComboBox * cb) {
	return bbStringFromQString(cb->currentText());
}

int bmx_qt_qcombobox_findtext(QComboBox * cb, BBString * text, int flags) {
	return cb->findText(qStringFromBBString(text), (Qt::MatchFlags)flags);
}

void bmx_qt_qcombobox_setcurrentindex(QComboBox * cb, int index) {
	cb->setCurrentIndex(index);
}

int bmx_qt_qcombobox_duplicatesenabled(QComboBox * cb) {
	return cb->duplicatesEnabled();
}

int bmx_qt_qcombobox_hasframe(QComboBox * cb) {
	return cb->hasFrame();
}

void bmx_qt_qcombobox_hidepopup(QComboBox * cb) {
	cb->hidePopup();
}

void bmx_qt_qcombobox_setmodel(QComboBox * cb, QAbstractItemModel * model) {
	cb->setModel(model);
}

BBString * bmx_qt_qcombobox_itemtext(QComboBox * cb, int index) {
	return bbStringFromQString(cb->itemText(index));
}

int bmx_qt_qcombobox_maxcount(QComboBox * cb) {
	return cb->maxCount();
}

int bmx_qt_qcombobox_maxvisibleitems(QComboBox * cb) {
	return cb->maxVisibleItems();
}

int bmx_qt_qcombobox_minimumcontentslength(QComboBox * cb) {
	return cb->minimumContentsLength();
}

int bmx_qt_qcombobox_modelcolumn(QComboBox * cb) {
	return cb->modelColumn();
}

void bmx_qt_qcombobox_setduplicatesenabled(QComboBox * cb, int enable) {
	cb->setDuplicatesEnabled(static_cast<bool>(enable));
}

void bmx_qt_qcombobox_seteditable(QComboBox * cb, int editable) {
	cb->setEditable(static_cast<bool>(editable));
}

void bmx_qt_qcombobox_setframe(QComboBox * cb, int value) {
	cb->setFrame(static_cast<bool>(value));
}

void bmx_qt_qcombobox_seticonsize(QComboBox * cb, int w, int h) {
	cb->setIconSize(QSize(w, h));
}

void bmx_qt_qcombobox_setinsertpolicy(QComboBox * cb, int policy) {
	cb->setInsertPolicy(bmx_qt_comboboxIntToInsertPolicy(policy));
}

void bmx_qt_qcombobox_setitemicon(QComboBox * cb, int index, MaxQIcon * icon) {
	if (icon) {
		cb->setItemIcon(index, icon->Icon());
	}
}

void bmx_qt_qcombobox_setitemtext(QComboBox * cb, int index, BBString * text) {
	cb->setItemText(index, qStringFromBBString(text));
}

void bmx_qt_qcombobox_setmaxcount(QComboBox * cb, int value) {
	cb->setMaxCount(value);
}

void bmx_qt_qcombobox_setmaxvisibleitems(QComboBox * cb, int maxItems) {
	cb->setMaxVisibleItems(maxItems);
}

void bmx_qt_qcombobox_setminimumcontentslength(QComboBox * cb, int characters) {
	cb->setMinimumContentsLength(characters);
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
