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

MaxQWidget::MaxQWidget(BBObject * handle, QWidget * parent, Qt::WindowFlags flags)
	: maxHandle(handle), QWidget(parent, flags)
{
	qbind(this, handle);
}

MaxQWidget::~MaxQWidget()
{
	qunbind(this);
}

QSize MaxQWidget::sizeHint() const {
	int w, h;
	_qt_qwidget_QWidget__SizeHint(maxHandle, &w, &h);
	return QSize(w, h);
}

QSize MaxQWidget::minimumSizeHint() const {
	int w, h;
	_qt_qwidget_QWidget__MinimumSizeHint(maxHandle, &w, &h);
	return QSize(w, h);
}

void MaxQWidget::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__OnPaintEvent(maxHandle, event);
}

void MaxQWidget::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__OnMouseDoubleClickEvent(maxHandle, event);
}

void MaxQWidget::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__OnMouseMoveEvent(maxHandle, event);
}

void MaxQWidget::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__OnMousePressEvent(maxHandle, event);
}

void MaxQWidget::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__OnMouseReleaseEvent(maxHandle, event);
}

void MaxQWidget::actionEvent(QActionEvent * event){
	_qt_qwidget_QWidget__OnActionEvent(maxHandle, event);
}

void MaxQWidget::changeEvent(QEvent * event){
	_qt_qwidget_QWidget__OnChangeEvent(maxHandle, event);
}

void MaxQWidget::closeEvent(QCloseEvent * event){
	_qt_qwidget_QWidget__OnCloseEvent(maxHandle, event);
}

void MaxQWidget::contextMenuEvent(QContextMenuEvent * event){
	_qt_qwidget_QWidget__OnContextMenuEvent(maxHandle, event);
}

void MaxQWidget::dragEnterEvent(QDragEnterEvent * event){
	_qt_qwidget_QWidget__OnDragEnterEvent(maxHandle, event);
}

void MaxQWidget::dragLeaveEvent(QDragLeaveEvent * event){
	_qt_qwidget_QWidget__OnDragLeaveEvent(maxHandle, event);
}

void MaxQWidget::dragMoveEvent(QDragMoveEvent * event){
	_qt_qwidget_QWidget__OnDragMoveEvent(maxHandle, event);
}

void MaxQWidget::dropEvent(QDropEvent * event){
	_qt_qwidget_QWidget__OnDropEvent(maxHandle, event);
}

void MaxQWidget::enterEvent(QEvent * event){
	_qt_qwidget_QWidget__OnEnterEvent(maxHandle, event);
}

void MaxQWidget::focusInEvent(QFocusEvent * event){
	_qt_qwidget_QWidget__OnFocusInEvent(maxHandle, event);
}

void MaxQWidget::focusOutEvent(QFocusEvent * event){
	_qt_qwidget_QWidget__OnFocusOutEvent(maxHandle, event);
}

void MaxQWidget::hideEvent(QHideEvent * event){
	_qt_qwidget_QWidget__OnHideEvent(maxHandle, event);
}

void MaxQWidget::inputMethodEvent(QInputMethodEvent * event){
	_qt_qwidget_QWidget__OnInputMethodEvent(maxHandle, event);
}

void MaxQWidget::keyPressEvent(QKeyEvent * event){
	_qt_qwidget_QWidget__OnKeyPressEvent(maxHandle, event);
}

void MaxQWidget::keyReleaseEvent(QKeyEvent * event){
	_qt_qwidget_QWidget__OnKeyReleaseEvent(maxHandle, event);
}

void MaxQWidget::leaveEvent(QEvent * event){
	_qt_qwidget_QWidget__OnLeaveEvent(maxHandle, event);
}

void MaxQWidget::moveEvent(QMoveEvent * event){
	_qt_qwidget_QWidget__OnMoveEvent(maxHandle, event);
}

void MaxQWidget::resizeEvent(QResizeEvent * event){
	_qt_qwidget_QWidget__OnResizeEvent(maxHandle, event);
}

void MaxQWidget::showEvent(QShowEvent * event){
	_qt_qwidget_QWidget__OnShowEvent(maxHandle, event);
}

void MaxQWidget::tabletEvent(QTabletEvent * event){
	_qt_qwidget_QWidget__OnTabletEvent(maxHandle, event);
}

void MaxQWidget::wheelEvent(QWheelEvent * event){
	_qt_qwidget_QWidget__OnWheelEvent(maxHandle, event);
}

bool MaxQWidget::focusNextPrevChild(bool next){
	return static_cast<bool>(_qt_qwidget_QWidget__OnFocusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQWidget::defaultActionEvent(QActionEvent * event) {
	QWidget::actionEvent(event);
}

void MaxQWidget::defaultChangeEvent(QEvent * event) {
	QWidget::changeEvent(event);
}

void MaxQWidget::defaultCloseEvent(QCloseEvent * event) {
	QWidget::closeEvent(event);
}

void MaxQWidget::defaultContextMenuEvent(QContextMenuEvent * event) {
	QWidget::contextMenuEvent(event);
}

void MaxQWidget::defaultDragEnterEvent(QDragEnterEvent * event) {
	QWidget::dragEnterEvent(event);
}

void MaxQWidget::defaultDragLeaveEvent(QDragLeaveEvent * event) {
	QWidget::dragLeaveEvent(event);
}

void MaxQWidget::defaultDragMoveEvent(QDragMoveEvent * event) {
	QWidget::dragMoveEvent(event);
}

void MaxQWidget::defaultDropEvent(QDropEvent * event) {
	QWidget::dropEvent(event);
}

void MaxQWidget::defaultEnterEvent(QEvent * event) {
	QWidget::enterEvent(event);
}

void MaxQWidget::defaultFocusInEvent(QFocusEvent * event) {
	QWidget::focusInEvent(event);
}

void MaxQWidget::defaultFocusOutEvent(QFocusEvent * event) {
	QWidget::focusOutEvent(event);
}

void MaxQWidget::defaultHideEvent(QHideEvent * event) {
	QWidget::hideEvent(event);
}

void MaxQWidget::defaultInputMethodEvent(QInputMethodEvent * event) {
	QWidget::inputMethodEvent(event);
}

void MaxQWidget::defaultKeyPressEvent(QKeyEvent * event) {
	QWidget::keyPressEvent(event);
}

void MaxQWidget::defaultKeyReleaseEvent(QKeyEvent * event) {
	QWidget::keyReleaseEvent(event);
}

void MaxQWidget::defaultLeaveEvent(QEvent * event) {
	QWidget::leaveEvent(event);
}

void MaxQWidget::defaultMoveEvent(QMoveEvent * event) {
	QWidget::moveEvent(event);
}

void MaxQWidget::defaultPaintEvent(QPaintEvent * event) {
	QWidget::paintEvent(event);
}

void MaxQWidget::defaultMouseDoubleClickEvent(QMouseEvent * event) {
	QWidget::mouseDoubleClickEvent(event);
}

void MaxQWidget::defaultMouseMoveEvent(QMouseEvent * event) {
	QWidget::mouseMoveEvent(event);
}

void MaxQWidget::defaultMousePressEvent(QMouseEvent * event) {
	QWidget::mousePressEvent(event);
}

void MaxQWidget::defaultMouseReleaseEvent(QMouseEvent * event) {
	QWidget::mouseReleaseEvent(event);
}

void MaxQWidget::defaultResizeEvent(QResizeEvent * event) {
	QWidget::resizeEvent(event);
}

void MaxQWidget::defaultShowEvent(QShowEvent * event) {
	QWidget::showEvent(event);
}

void MaxQWidget::defaultTabletEvent(QTabletEvent * event) {
	QWidget::tabletEvent(event);
}

void MaxQWidget::defaultWheelEvent(QWheelEvent * event) {
	QWidget::wheelEvent(event);
}

void MaxQWidget::defaultSizeHint(int * w, int * h) {
	QSize s(QWidget::sizeHint());
	*w = s.width();
	*h = s.height();
}

void MaxQWidget::defaultMinimumSizeHint(int * w, int * h) {
	QSize s(QWidget::minimumSizeHint());
	*w = s.width();
	*h = s.height();
}

void MaxQWidget::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

bool MaxQWidget::defaultFocusNextPrevChild(bool next) {
	return QWidget::focusNextPrevChild(next);
}

// ---------------------------------------------------------------------------------------

MaxQAction::MaxQAction(BBObject * handle, QAction * action)
	: action(action), MaxQObjectWrapper(handle, action)
{
	doConnections();
}

MaxQAction::~MaxQAction()
{
}

MaxQAction::MaxQAction(QAction * a)
	: action(a), MaxQObjectWrapper(a)
{
	maxHandle = _qt_qwidget_QAction__create(action);
	qbind(action, maxHandle);

	doConnections();
}

void MaxQAction::doConnections() {
	connect(action, SIGNAL(changed()), SLOT(onChanged()));
	connect(action, SIGNAL(hovered()), SLOT(onHovered()));
	connect(action, SIGNAL(toggled(bool)), SLOT(onToggled(bool)));
	connect(action, SIGNAL(triggered(bool)), SLOT(onTriggered(bool)));
}

QAction * MaxQAction::Action() {
	return action;
}

void MaxQAction::link(QAction * a) {
	BBObject * handle = qfind(a);
	
	if (handle == &bbNullObject) {
		MaxQAction * action = new MaxQAction(a);
	}
}

void MaxQAction::onChanged() {
	_qt_qwidget_QAction__OnChanged(maxHandle);
}

void MaxQAction::onHovered() {
	_qt_qwidget_QAction__OnHovered(maxHandle);
}

void MaxQAction::onToggled(bool checked) {
	_qt_qwidget_QAction__OnToggled(maxHandle, static_cast<int>(checked));
}

void MaxQAction::onTriggered(bool checked) {
	_qt_qwidget_QAction__OnTriggered(maxHandle, static_cast<int>(checked));
}

// ---------------------------------------------------------------------------------------

MaxQActionGroup::MaxQActionGroup(BBObject * handle, QObject * parent)
	: maxHandle(handle), QActionGroup(parent)
{
	qbind(this, handle);
	connect(this, SIGNAL(hovered(QAction *)), SLOT(onHovered(QAction *)));
	connect(this, SIGNAL(triggered(QAction *)), SLOT(onTriggered(QAction *)));
}

MaxQActionGroup::~MaxQActionGroup()
{
	qunbind(this);
}

void MaxQActionGroup::onHovered(QAction * action) {
	MaxQAction::link(action);
	_qt_qwidget_QActionGroup__OnHovered(maxHandle, action);
}

void MaxQActionGroup::onTriggered(QAction * action) {
	MaxQAction::link(action);
	_qt_qwidget_QActionGroup__OnTriggered(maxHandle, action);
}

// *********************************************


QWidget * bmx_qt_qwidget_create(BBObject * handle, QWidget * parent, int f) {
	return new MaxQWidget(handle, parent, bmx_qt_getwindowflags(f));
}

void bmx_qt_qwidget_hide(QWidget * widget) {
	widget->hide();
}

void bmx_qt_qwidget_show(QWidget * widget) {
	widget->show();
}

void bmx_qt_qwidget_setlayout(QWidget * widget, QLayout * layout) {
	widget->setLayout(layout);
}

void bmx_qt_qwidget_setwindowtitle(QWidget * widget, BBString * title) {
	widget->setWindowTitle(qStringFromBBString(title));
}

void bmx_qt_qwidget_showfullscreen(QWidget * widget) {
	widget->showFullScreen();
}

void bmx_qt_qwidget_showmaximized(QWidget * widget) {
	widget->showMaximized();
}

void bmx_qt_qwidget_showminimized(QWidget * widget) {
	widget->showMinimized();
}

void bmx_qt_qwidget_shownormal(QWidget * widget) {
	widget->showNormal();
}

void bmx_qt_qwidget_stackunder(QWidget * widget, QWidget * w) {
	widget->stackUnder(w);
}

void bmx_qt_qwidget_setfixedsize(QWidget * widget, int w, int h) {
	widget->setFixedSize(w, h);
}

void bmx_qt_qwidget_setfixedwidth(QWidget * widget, int w) {
	widget->setFixedWidth(w);
}

void bmx_qt_qwidget_setfocus(QWidget * widget, int reason) {
	widget->setFocus(bmx_qt_getfocusreason(reason));
}

void bmx_qt_qwidget_close(QWidget * widget) {
	widget->close();
}


void bmx_qt_qwidget_update(QWidget * widget) {
	widget->update();
}


void bmx_qt_qwidget_raise(QWidget * widget) {
	widget->raise();
}


void bmx_qt_qwidget_repaint(QWidget * widget) {
	widget->repaint();
}


void bmx_qt_qwidget_setdisabled(QWidget * widget, int disable) {
	widget->setDisabled(static_cast<bool>(disable));
}


void bmx_qt_qwidget_setenabled(QWidget * widget, int value) {
	widget->setEnabled(static_cast<bool>(value));
}


void bmx_qt_qwidget_sethidden(QWidget * widget, int hidden) {
	widget->setHidden(static_cast<bool>(hidden));
}


void bmx_qt_qwidget_setstylesheet(QWidget * widget, BBString * styleSheet) {
	widget->setStyleSheet(qStringFromBBString(styleSheet));
}


void bmx_qt_qwidget_setvisible(QWidget * widget, int visible) {
	widget->setVisible(static_cast<bool>(visible));
}


void bmx_qt_qwidget_setwindowmodified(QWidget * widget, int value) {
	widget->setWindowModified(static_cast<bool>(value));
}

void bmx_qt_qwidget_resize(QWidget * widget, int w, int h) {
	widget->resize(w, h);
}

int bmx_qt_qwidget_height(QWidget * widget) {
	return widget->height();
}

int bmx_qt_qwidget_width(QWidget * widget) {
	return widget->width();
}

void bmx_qt_qwidget_addaction(QWidget * widget, QAction * action) {
	widget->addAction(action);
}

void bmx_qt_qwidget_setcontextmenupolicy(QWidget * widget, int p) {
	Qt::ContextMenuPolicy policy;
	
	switch(p) {
		case 0:
			policy = Qt::NoContextMenu;
			break;
		case 1:
			policy = Qt::DefaultContextMenu;
			break;
		case 2:
			policy = Qt::ActionsContextMenu;
			break;
		case 3:
			policy = Qt::CustomContextMenu;
			break;
		case 4:
			policy = Qt::PreventContextMenu;
			break;
	}
	
	widget->setContextMenuPolicy(policy);
}

MaxQRect * bmx_qt_qwidget_framegeometry(QWidget * widget) {
	return new MaxQRect(widget->frameGeometry());
}

void bmx_qt_qwidget_framesize(QWidget * widget, int * w, int * h) {
	QSize s(widget->frameSize());
	*w = s.width();
	*h = s.height();
}

MaxQRect * bmx_qt_qwidget_geometry(QWidget * widget) {
	return new MaxQRect(widget->geometry());
}

void bmx_qt_qwidget_setattribute(QWidget * widget, int attribute, int on) {
	widget->setAttribute(bmx_qt_inttowidgetattribute(attribute), static_cast<bool>(on));
}

void bmx_qt_qwidget_move(QWidget * widget, int x, int y) {
	widget->move(x, y);
}

void bmx_qt_qwidget_settooltip(QWidget * widget, BBString * text) {
	widget->setToolTip(qStringFromBBString(text));
}

MaxQSizePolicy * bmx_qt_qwidget_sizepolicy(QWidget * widget) {
	return new MaxQSizePolicy(widget->sizePolicy());
}

void bmx_qt_qwidget_setsizepolicyhv(QWidget * widget, int horizontalPolicy, int verticalPolicy) {
	widget->setSizePolicy((QSizePolicy::Policy)horizontalPolicy, (QSizePolicy::Policy)verticalPolicy);
}

MaxQFont * bmx_qt_qwidget_font(QWidget * widget) {
	return new MaxQFont(widget->font());
}

MaxQFontMetrics * bmx_qt_qwidget_fontmetrics(QWidget * widget) {
	return new MaxQFontMetrics(widget->fontMetrics());
}

void bmx_qt_qwidget_setfont(QWidget * widget, MaxQFont * font) {
	widget->setFont(font->Font());
}

QWidget * bmx_qt_qwidget_window(QWidget * widget) {
	return widget->window();
}

BBString * bmx_qt_qwidget_windowfilepath(QWidget * widget) {
	return bbStringFromQString(widget->windowFilePath());
}

int bmx_qt_qwidget_windowflags(QWidget * widget) {
	return widget->windowFlags();
}

MaxQIcon * bmx_qt_qwidget_windowicon(QWidget * widget) {
	return new MaxQIcon(widget->windowIcon());
}

BBString * bmx_qt_qwidget_windowicontext(QWidget * widget) {
	return bbStringFromQString(widget->windowIconText());
}

int bmx_qt_qwidget_windowmodality(QWidget * widget) {
	return widget->windowModality();
}

double bmx_qt_qwidget_windowopacity(QWidget * widget) {
	return widget->windowOpacity();
}

BBString * bmx_qt_qwidget_windowrole(QWidget * widget) {
	return bbStringFromQString(widget->windowRole());
}

int bmx_qt_qwidget_windowstate(QWidget * widget) {
	return widget->windowState();
}

BBString * bmx_qt_qwidget_windowtitle(QWidget * widget) {
	return bbStringFromQString(widget->windowTitle());
}

int bmx_qt_qwidget_windowtype(QWidget * widget) {
	return widget->windowType();
}

int bmx_qt_qwidget_x(QWidget * widget) {
	return widget->x();
}

int bmx_qt_qwidget_y(QWidget * widget) {
	return widget->y();
}

int bmx_qt_qwidget_acceptdrops(QWidget * widget) {
	return widget->acceptDrops();
}

BBString * bmx_qt_qwidget_accessibledescription(QWidget * widget) {
	return bbStringFromQString(widget->accessibleDescription());
}

BBString * bmx_qt_qwidget_accessiblename(QWidget * widget) {
	return bbStringFromQString(widget->accessibleName());
}

void bmx_qt_qwidget_activatewindow(QWidget * widget) {
	widget->activateWindow();
}

void bmx_qt_qwidget_adjustsize(QWidget * widget) {
	widget->adjustSize();
}

int bmx_qt_qwidget_autofillbackground(QWidget * widget) {
	return static_cast<int>(widget->autoFillBackground());
}

int bmx_qt_qwidget_backgroundrole(QWidget * widget) {
	return widget->backgroundRole();
}

void bmx_qt_qwidget_basesize(QWidget * widget, int * w, int * h) {
	QSize s(widget->baseSize());
	*w = s.width();
	*h = s.height();
}

QWidget * bmx_qt_qwidget_childat(QWidget * widget, int x, int y) {
	return widget->childAt(x, y);
}

MaxQRect * bmx_qt_qwidget_childrenrect(QWidget * widget) {
	return new MaxQRect(widget->childrenRect());
}

MaxQRegion * bmx_qt_qwidget_childrenregion(QWidget * widget) {
	return new MaxQRegion(widget->childrenRegion());
}

void bmx_qt_qwidget_clearfocus(QWidget * widget) {
	widget->clearFocus();
}

void bmx_qt_qwidget_clearmask(QWidget * widget) {
	widget->clearMask();
}

MaxQRect * bmx_qt_qwidget_contentsrect(QWidget * widget) {
	return new MaxQRect(widget->contentsRect());
}

QWidget * bmx_qt_qwidget_parentwidget(QWidget * widget) {
	return widget->parentWidget();
}

void bmx_qt_qwidget_pos(QWidget * widget, int * x, int * y) {
	QPoint p(widget->pos());
	*x = p.x();
	*y = p.y();
}

MaxQRect * bmx_qt_qwidget_rect(QWidget * widget) {
	return new MaxQRect(widget->rect());
}

void bmx_qt_qwidget_size(QWidget * widget, int * w, int * h) {
	QSize s(widget->size());
	*w = s.width();
	*h = s.height();
}

void bmx_qt_qwidget_sizeincrement(QWidget * widget, int * w, int * h) {
	QSize s(widget->sizeIncrement());
	*w = s.width();
	*h = s.height();
}

MaxQLocale * bmx_qt_qwidget_locale(QWidget * widget) {
	return new MaxQLocale(widget->locale());
}

void bmx_qt_qwidget_setparent(QWidget * widget, QWidget * parent) {
	widget->setParent(parent);
}

int bmx_qt_qwidget_hasfocus(QWidget * widget) {
	return static_cast<int>(widget->hasFocus());
}

int bmx_qt_qwidget_hasmousetracking(QWidget * widget) {
	return static_cast<int>(widget->hasMouseTracking());
}

int bmx_qt_qwidget_isactivewindow(QWidget * widget) {
	return static_cast<int>(widget->isActiveWindow());
}

int bmx_qt_qwidget_isenabled(QWidget * widget) {
	return static_cast<int>(widget->isEnabled());
}

int bmx_qt_qwidget_isfullscreen(QWidget * widget) {
	return static_cast<int>(widget->isFullScreen());
}

int bmx_qt_qwidget_ishidden(QWidget * widget) {
	return static_cast<int>(widget->isHidden());
}

int bmx_qt_qwidget_ismaximized(QWidget * widget) {
	return static_cast<int>(widget->isMaximized());
}

int bmx_qt_qwidget_isminimized(QWidget * widget) {
	return static_cast<int>(widget->isMinimized());
}

int bmx_qt_qwidget_ismodal(QWidget * widget) {
	return static_cast<int>(widget->isModal());
}

int bmx_qt_qwidget_isvisible(QWidget * widget) {
	return static_cast<int>(widget->isVisible());
}

int bmx_qt_qwidget_iswindow(QWidget * widget) {
	return static_cast<int>(widget->isWindow());
}

int bmx_qt_qwidget_iswindowmodified(QWidget * widget) {
	return static_cast<int>(widget->isWindowModified());
}

void bmx_qt_qwidget_setmaximumheight(QWidget * widget, int maxh) {
	widget->setMaximumHeight(maxh);
}

void bmx_qt_qwidget_setmaximumsize(QWidget * widget, int w, int h) {
	widget->setMaximumSize(w, h);
}

void bmx_qt_qwidget_setmaximumwidth(QWidget * widget, int maxw) {
	widget->setMaximumWidth(maxw);
}

void bmx_qt_qwidget_setminimumheight(QWidget * widget, int minh) {
	widget->setMinimumHeight(minh);
}

void bmx_qt_qwidget_setminimumsize(QWidget * widget, int w, int h) {
	widget->setMinimumSize(w, h);
}

void bmx_qt_qwidget_setminimumwidth(QWidget * widget, int minw) {
	widget->setMinimumWidth(minw);
}

void bmx_qt_qwidget_setmousetracking(QWidget * widget, int enable) {
	widget->setMouseTracking(static_cast<bool>(enable));
}

void bmx_qt_qwidget_setshortcutautorepeat(QWidget * widget, int id, int enable) {
	widget->setShortcutAutoRepeat(id, static_cast<bool>(enable));
}

void bmx_qt_qwidget_setshortcutenabled(QWidget * widget, int id, int enable) {
	widget->setShortcutEnabled(id, static_cast<bool>(enable));
}

void bmx_qt_qwidget_setsizeincrement(QWidget * widget, int w, int h) {
	widget->setSizeIncrement(w, h);
}

void bmx_qt_qwidget_setgeometry(QWidget * widget, int x, int y, int w, int h) {
	widget->setGeometry(x, y, w, h);
}

MaxQPalette * bmx_qt_qwidget_palette(QWidget * widget) {
	QPalette p(widget->palette());
	return new MaxQPalette(p);
}

void bmx_qt_qwidget_setpalette(QWidget * widget, MaxQPalette * palette) {
	widget->setPalette(palette->Palette());
}

void bmx_qt_qwidget_setautofillbackground(QWidget * widget, int enabled) {
	widget->setAutoFillBackground(static_cast<bool>(enabled));
}

void bmx_qt_qwidget_setbasesize(QWidget * widget, int basew, int baseh) {
	widget->setBaseSize(basew, baseh);
}

void bmx_qt_qwidget_setcontentsmargins(QWidget * widget, int left, int top, int right, int bottom) {
	widget->setContentsMargins(left, top, right, bottom);
}

// *********************************************

void bmx_qt_qwidget_default_mousedoubleclickevent(MaxQWidget * widget, QMouseEvent * event) {
	widget->defaultMouseDoubleClickEvent(event);
}

void bmx_qt_qwidget_default_mousemoveevent(MaxQWidget * widget, QMouseEvent * event) {
	widget->defaultMouseMoveEvent(event);
}

void bmx_qt_qwidget_default_mousepressevent(MaxQWidget * widget, QMouseEvent * event) {
	widget->defaultMousePressEvent(event);
}

void bmx_qt_qwidget_default_mousereleaseevent(MaxQWidget * widget, QMouseEvent * event) {
	widget->defaultMouseReleaseEvent(event);
}

void bmx_qt_qwidget_default_actionevent(MaxQWidget * widget, QActionEvent * event) {
	widget->defaultActionEvent(event);
}

void bmx_qt_qwidget_default_changeevent(MaxQWidget * widget, QEvent * event) {
	widget->defaultChangeEvent(event);
}

void bmx_qt_qwidget_default_closeevent(MaxQWidget * widget, QCloseEvent * event) {
	widget->defaultCloseEvent(event);
}

void bmx_qt_qwidget_default_contextmenuevent(MaxQWidget * widget, QContextMenuEvent * event) {
	widget->defaultContextMenuEvent(event);
}

void bmx_qt_qwidget_default_dragenterevent(MaxQWidget * widget, QDragEnterEvent * event) {
	widget->defaultDragEnterEvent(event);
}

void bmx_qt_qwidget_default_dragleaveevent(MaxQWidget * widget, QDragLeaveEvent * event) {
	widget->defaultDragLeaveEvent(event);
}

void bmx_qt_qwidget_default_dragmoveevent(MaxQWidget * widget, QDragMoveEvent * event) {
	widget->defaultDragMoveEvent(event);
}

void bmx_qt_qwidget_default_dropevent(MaxQWidget * widget, QDropEvent * event) {
	widget->defaultDropEvent(event);
}

void bmx_qt_qwidget_default_enterevent(MaxQWidget * widget, QEvent * event) {
	widget->defaultEnterEvent(event);
}

void bmx_qt_qwidget_default_focusinevent(MaxQWidget * widget, QFocusEvent * event) {
	widget->defaultFocusInEvent(event);
}

void bmx_qt_qwidget_default_focusoutevent(MaxQWidget * widget, QFocusEvent * event) {
	widget->defaultFocusOutEvent(event);
}

void bmx_qt_qwidget_default_hideevent(MaxQWidget * widget, QHideEvent * event) {
	widget->defaultHideEvent(event);
}

void bmx_qt_qwidget_default_inputmethodevent(MaxQWidget * widget, QInputMethodEvent * event) {
	widget->defaultInputMethodEvent(event);
}

void bmx_qt_qwidget_default_keypressevent(MaxQWidget * widget, QKeyEvent * event) {
	widget->defaultKeyPressEvent(event);
}

void bmx_qt_qwidget_default_keyreleaseevent(MaxQWidget * widget, QKeyEvent * event) {
	widget->defaultKeyReleaseEvent(event);
}

void bmx_qt_qwidget_default_leaveevent(MaxQWidget * widget, QEvent * event) {
	widget->defaultLeaveEvent(event);
}

void bmx_qt_qwidget_default_moveevent(MaxQWidget * widget, QMoveEvent * event) {
	widget->defaultMoveEvent(event);
}

void bmx_qt_qwidget_default_resizeevent(MaxQWidget * widget, QResizeEvent * event) {
	widget->defaultResizeEvent(event);
}

void bmx_qt_qwidget_default_showevent(MaxQWidget * widget, QShowEvent * event) {
	widget->defaultShowEvent(event);
}

void bmx_qt_qwidget_default_tabletevent(MaxQWidget * widget, QTabletEvent * event) {
	widget->defaultTabletEvent(event);
}

void bmx_qt_qwidget_default_wheelevent(MaxQWidget * widget, QWheelEvent * event) {
	widget->defaultWheelEvent(event);
}

void bmx_qt_qwidget_default_paintevent(MaxQWidget * widget, QPaintEvent * event) {
	widget->defaultPaintEvent(event);
}

int bmx_qt_qwidget_winid(QWidget * widget) {
	return (int)widget->winId();
}

void bmx_qt_qwidget_default_sizehint(MaxQWidget * widget, int * w, int * h) {
	widget->defaultSizeHint(w, h);
}

void bmx_qt_qwidget_default_minimumsizehint(MaxQWidget * widget, int * w, int * h) {
	widget->defaultMinimumSizeHint(w, h);
}

int bmx_qt_qwidget_default_focusnextprevchild(MaxQWidget * widget, int next) {
	return static_cast<int>(widget->defaultFocusNextPrevChild(static_cast<bool>(next)));
}

// *********************************************

QAction * bmx_qt_qaction_create(BBObject * handle, BBString * text, QObject * parent) {
	MaxQAction * action = new MaxQAction(handle, new QAction(qStringFromBBString(text), parent));
	return action->Action();
}

QAction * bmx_qt_qaction_createwithicon(BBObject * handle, MaxQIcon * icon, BBString * text, QObject * parent) {
	MaxQAction * action = new MaxQAction(handle, new QAction(icon->Icon(), qStringFromBBString(text), parent));
	return action->Action();
}

void bmx_qt_qaction_setshortcut(QAction * action, BBString * sequence) {
	action->setShortcut(qStringFromBBString(sequence));
}

QActionGroup * bmx_qt_qaction_actiongroup(QAction * action) {
	return action->actionGroup();
}

void bmx_qt_qaction_activate(QAction * action, int event) {
	action->activate((QAction::ActionEvent)event);
}

int bmx_qt_qaction_autorepeat(QAction * action) {
	return static_cast<int>(action->autoRepeat());
}

BBObject * bmx_qt_qaction_data(QAction * action) {
	return &bbNullObject;
	// TODO
	//return action->
}

MaxQFont * bmx_qt_qaction_font(QAction * action) {
	return new MaxQFont(action->font());
}

BBString * bmx_qt_qaction_icontext(QAction * action) {
	return bbStringFromQString(action->iconText());
}

int bmx_qt_qaction_ischeckable(QAction * action) {
	return static_cast<int>(action->isCheckable());
}

int bmx_qt_qaction_ischecked(QAction * action) {
	return static_cast<int>(action->isChecked());
}

int bmx_qt_qaction_isenabled(QAction * action) {
	return static_cast<int>(action->isEnabled());
}

int bmx_qt_qaction_isiconvisibleinmenu(QAction * action) {
	return static_cast<int>(action->isIconVisibleInMenu());
}

int bmx_qt_qaction_isseparator(QAction * action) {
	return static_cast<int>(action->isSeparator());
}

int bmx_qt_qaction_isvisible(QAction * action) {
	return static_cast<int>(action->isVisible());
}

QMenu * bmx_qt_qaction_menu(QAction * action) {
	return action->menu();
}

int bmx_qt_qaction_menurole(QAction * action) {
	return action->menuRole();
}

QWidget * bmx_qt_qaction_parentwidget(QAction * action) {
	return action->parentWidget();
}

void bmx_qt_qaction_setactiongroup(QAction * action, QActionGroup * group) {
	action->setActionGroup(group);
}

void bmx_qt_qaction_setautorepeat(QAction * action, int value) {
	action->setAutoRepeat(static_cast<bool>(value));
}

void bmx_qt_qaction_setcheckable(QAction * action, int value) {
	action->setCheckable(static_cast<bool>(value));
}

void bmx_qt_qaction_setdata(QAction * action, BBObject * userData) {
	// TODO
	//action->
}

void bmx_qt_qaction_setfont(QAction * action, MaxQFont * font) {
	action->setFont(font->Font());
}

void bmx_qt_qaction_seticontext(QAction * action, BBString * text) {
	action->setIconText(qStringFromBBString(text));
}

void bmx_qt_qaction_seticonvisibleinmenu(QAction * action, int visible) {
	action->setIconVisibleInMenu(static_cast<bool>(visible));
}

void bmx_qt_qaction_setmenu(QAction * action, QMenu * menu) {
	action->setMenu(menu);
}

void bmx_qt_qaction_setmenurole(QAction * action, int menuRole) {
	action->setMenuRole((QAction::MenuRole)menuRole);
}

void bmx_qt_qaction_setseparator(QAction * action, int value) {
	action->setSeparator(static_cast<bool>(value));
}

void bmx_qt_qaction_setshortcutcontext(QAction * action, int context) {
	action->setShortcutContext((Qt::ShortcutContext)context);
}

void bmx_qt_qaction_setstatustip(QAction * action, BBString * statusTip) {
	action->setStatusTip(qStringFromBBString(statusTip));
}

void bmx_qt_qaction_settext(QAction * action, BBString * text) {
	action->setText(qStringFromBBString(text));
}

void bmx_qt_qaction_settooltip(QAction * action, BBString * tip) {
	action->setToolTip(qStringFromBBString(tip));
}

void bmx_qt_qaction_setwhatsthis(QAction * action, BBString * what) {
	action->setWhatsThis(qStringFromBBString(what));
}

BBString * bmx_qt_qaction_shortcut(QAction * action) {
	return bbStringFromQString(action->shortcut().toString());
}

int bmx_qt_qaction_shortcutcontext(QAction * action) {
	return action->shortcutContext();
}

int bmx_qt_qaction_showstatustext(QAction * action, QWidget * widget) {
	return static_cast<int>(action->showStatusText());
}

BBString * bmx_qt_qaction_statustip(QAction * action) {
	return bbStringFromQString(action->statusTip());
}

BBString * bmx_qt_qaction_text(QAction * action) {
	return bbStringFromQString(action->text());
}

BBString * bmx_qt_qaction_tooltip(QAction * action) {
	return bbStringFromQString(action->toolTip());
}

BBString * bmx_qt_qaction_whatsthis(QAction * action) {
	return bbStringFromQString(action->whatsThis());
}

void bmx_qt_qaction_setshortcuts(QAction * action, int key) {
	action->setShortcuts((QKeySequence::StandardKey)key);
}

void bmx_qt_qaction_hover(QAction * action) {
	action->hover();
}

void bmx_qt_qaction_setchecked(QAction * action, int value) {
	action->setChecked(static_cast<bool>(value));
}

void bmx_qt_qaction_setdisabled(QAction * action, int value) {
	action->setDisabled(static_cast<bool>(value));
}

void bmx_qt_qaction_setenabled(QAction * action, int value) {
	action->setEnabled(static_cast<bool>(value));
}

void bmx_qt_qaction_setvisible(QAction * action, int value) {
	action->setVisible(static_cast<bool>(value));
}

void bmx_qt_qaction_toggle(QAction * action) {
	action->toggle();
}

void bmx_qt_qaction_trigger(QAction * action) {
	action->trigger();
}



// *********************************************

QActionGroup * bmx_qt_qactiongroup_create(BBObject * handle, QObject * parent) {
	return new MaxQActionGroup(handle, parent);
}

QAction * bmx_qt_qactiongroup_addaction(QActionGroup * group, QAction * a) {
	QAction * action = group->addAction(a);
	MaxQAction::link(action);
	return action;
}

QAction * bmx_qt_qactiongroup_addactiontext(QActionGroup * group, BBString * text) {
	QAction * action = group->addAction(qStringFromBBString(text));
	MaxQAction::link(action);
	return action;
}

QAction * bmx_qt_qactiongroup_checkedaction(QActionGroup * group) {
	QAction * action = group->checkedAction();
	MaxQAction::link(action);
	return action;
}

int bmx_qt_qactiongroup_isenabled(QActionGroup * group) {
	return static_cast<int>(group->isEnabled());
}

int bmx_qt_qactiongroup_isexclusive(QActionGroup * group) {
	return static_cast<int>(group->isExclusive());
}

int bmx_qt_qactiongroup_isvisible(QActionGroup * group) {
	return static_cast<int>(group->isVisible());
}

void bmx_qt_qactiongroup_removeaction(QActionGroup * group, QAction * action) {
	group->removeAction(action);
}

void bmx_qt_qactiongroup_setdisabled(QActionGroup * group, int value) {
	group->setDisabled(static_cast<bool>(value));
}

void bmx_qt_qactiongroup_setenabled(QActionGroup * group, int value) {
	group->setEnabled(static_cast<bool>(value));
}

void bmx_qt_qactiongroup_setexclusive(QActionGroup * group, int value) {
	group->setExclusive(static_cast<bool>(value));
}

void bmx_qt_qactiongroup_setvisible(QActionGroup * group, int value) {
	group->setVisible(static_cast<bool>(value));
}

// *********************************************

void bmx_qt_qlayout_setsizeconstraint(QLayout * layout, int constraint) {
	layout->setSizeConstraint((QLayout::SizeConstraint)constraint);
}

void bmx_qt_qlayout_setcontentsmargins(QLayout * layout, int left, int top, int right, int bottom) {
	layout->setContentsMargins(left, top, right, bottom);
}

void bmx_qt_qlayout_setenabled(QLayout * layout, int enable) {
	layout->setEnabled(static_cast<bool>(enable));
}

void bmx_qt_qlayout_setmenubar(QLayout * layout, QWidget * widget) {
	layout->setMenuBar(widget);
}

// *********************************************

Qt::WidgetAttribute bmx_qt_inttowidgetattribute(int a) {
	switch(a) {
		case 0:
			return Qt::WA_Disabled;
		case 1:
			return Qt::WA_UnderMouse;
		case 2:
			return Qt::WA_MouseTracking;
		case 4:
			return Qt::WA_OpaquePaintEvent;
		case 5:
			return Qt::WA_StaticContents;
		case 7:
			return Qt::WA_LaidOut;
		case 8:
			return Qt::WA_PaintOnScreen;
		case 9:
			return Qt::WA_NoSystemBackground;
		case 10:
			return Qt::WA_UpdatesDisabled;
		case 11:
			return Qt::WA_Mapped;
		case 12:
			return Qt::WA_MacNoClickThrough;
		case 13:
			return Qt::WA_PaintOutsidePaintEvent;
		case 14:
			return Qt::WA_InputMethodEnabled;
		case 15:
			return Qt::WA_WState_Visible;
		case 16:
			return Qt::WA_WState_Hidden;
		case 32:
			return Qt::WA_ForceDisabled;
		case 33:
			return Qt::WA_KeyCompression;
		case 34:
			return Qt::WA_PendingMoveEvent;
		case 35:
			return Qt::WA_PendingResizeEvent;
		case 36:
			return Qt::WA_SetPalette;
		case 37:
			return Qt::WA_SetFont;
		case 38:
			return Qt::WA_SetCursor;
		case 39:
			return Qt::WA_NoChildEventsFromChildren;
		case 41:
			return Qt::WA_WindowModified;
		case 42:
			return Qt::WA_Resized;
		case 43:
			return Qt::WA_Moved;
		case 44:
			return Qt::WA_PendingUpdate;
		case 45:
			return Qt::WA_InvalidSize;
		case 46:
			return Qt::WA_MacBrushedMetal;
		case 47:
			return Qt::WA_CustomWhatsThis;
		case 48:
			return Qt::WA_LayoutOnEntireRect;
		case 49:
			return Qt::WA_OutsideWSRange;
		case 50:
			return Qt::WA_GrabbedShortcut;
		case 51:
			return Qt::WA_TransparentForMouseEvents;
		case 52:
			return Qt::WA_PaintUnclipped;
		case 53:
			return Qt::WA_SetWindowIcon;
		case 54:
			return Qt::WA_NoMouseReplay;
		case 55:
			return Qt::WA_DeleteOnClose;
		case 56:
			return Qt::WA_RightToLeft;
		case 57:
			return Qt::WA_SetLayoutDirection;
		case 58:
			return Qt::WA_NoChildEventsForParent;
		case 59:
			return Qt::WA_ForceUpdatesDisabled;
		case 60:
			return Qt::WA_WState_Created;
		case 61:
			return Qt::WA_WState_CompressKeys;
		case 62:
			return Qt::WA_WState_InPaintEvent;
		case 63:
			return Qt::WA_WState_Reparented;
		case 64:
			return Qt::WA_WState_ConfigPending;
		case 66:
			return Qt::WA_WState_Polished;
		case 68:
			return Qt::WA_WState_OwnSizePolicy;
		case 69:
			return Qt::WA_WState_ExplicitShowHide;
		case 71:
			return Qt::WA_MouseNoMask;
		case 73:
			return Qt::WA_NoMousePropagation;
		case 74:
			return Qt::WA_Hover;
		case 75:
			return Qt::WA_InputMethodTransparent;
		case 76:
			return Qt::WA_QuitOnClose;
		case 77:
			return Qt::WA_KeyboardFocusChange;
		case 78:
			return Qt::WA_AcceptDrops;
		case 80:
			return Qt::WA_WindowPropagation;
		case 81:
			return Qt::WA_NoX11EventCompression;
		case 82:
			return Qt::WA_TintedBackground;
		case 83:
			return Qt::WA_X11OpenGLOverlay;
		case 84:
			return Qt::WA_AlwaysShowToolTips;
		case 85:
			return Qt::WA_MacOpaqueSizeGrip;
		case 86:
			return Qt::WA_SetStyle;
		case 87:
			return Qt::WA_SetLocale;
		case 88:
			return Qt::WA_MacShowFocusRect;
		case 89:
			return Qt::WA_MacNormalSize;
		case 90:
			return Qt::WA_MacSmallSize;
		case 91:
			return Qt::WA_MacMiniSize;
		case 92:
			return Qt::WA_LayoutUsesWidgetRect;
		case 93:
			return Qt::WA_StyledBackground;
		case 94:
			return Qt::WA_MSWindowsUseDirect3D;
		case 95:
			return Qt::WA_CanHostQMdiSubWindowTitleBar;
		case 96:
			return Qt::WA_MacAlwaysShowToolWindow;
		case 97:
			return Qt::WA_StyleSheet;
		case 98:
			return Qt::WA_ShowWithoutActivating;
		case 99:
			return Qt::WA_X11BypassTransientForHint;
		case 100:
			return Qt::WA_NativeWindow;
		case 101:
			return Qt::WA_DontCreateNativeAncestors;
		case 102:
			return Qt::WA_MacVariableSize;
		case 103:
			return Qt::WA_DontShowOnScreen;
		case 104:
			return Qt::WA_X11NetWmWindowTypeDesktop;
		case 105:
			return Qt::WA_X11NetWmWindowTypeDock;
		case 106:
			return Qt::WA_X11NetWmWindowTypeToolBar;
		case 107:
			return Qt::WA_X11NetWmWindowTypeMenu;
		case 108:
			return Qt::WA_X11NetWmWindowTypeUtility;
		case 109:
			return Qt::WA_X11NetWmWindowTypeSplash;
		case 110:
			return Qt::WA_X11NetWmWindowTypeDialog;
		case 111:
			return Qt::WA_X11NetWmWindowTypeDropDownMenu;
		case 112:
			return Qt::WA_X11NetWmWindowTypePopupMenu;
		case 113:
			return Qt::WA_X11NetWmWindowTypeToolTip;
		case 114:
			return Qt::WA_X11NetWmWindowTypeNotification;
		case 115:
			return Qt::WA_X11NetWmWindowTypeCombo;
		case 116:
			return Qt::WA_X11NetWmWindowTypeDND;
		case 117:
			return Qt::WA_MacFrameworkScaled;
		case 118:
			return Qt::WA_SetWindowModality;
		case 119:
			return Qt::WA_WState_WindowOpacitySet;
		case 120:
			return Qt::WA_TranslucentBackground;
	}
	
	return Qt::WA_Disabled;
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
