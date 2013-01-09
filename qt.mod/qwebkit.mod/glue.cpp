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

MaxQWebView::MaxQWebView(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QWebView(parent)
{
	qbind(this, handle);

	connect(this, SIGNAL(iconChanged()), SLOT(onIconChanged()));
	connect(this, SIGNAL(linkClicked(const QUrl &)), SLOT(onLinkClicked(const QUrl &)));
	connect(this, SIGNAL(loadFinished(bool)), SLOT(onLoadFinished(bool)));
	connect(this, SIGNAL(loadProgress(int)), SLOT(onLoadProgress(int)));
	connect(this, SIGNAL(loadStarted()), SLOT(onLoadStarted()));
	connect(this, SIGNAL(selectionChanged()), SLOT(onSelectionChanged()));
	connect(this, SIGNAL(statusBarMessage(const QString &)), SLOT(onStatusBarMessage(const QString &)));
	connect(this, SIGNAL(titleChanged(const QString &)), SLOT(onTitleChanged(const QString &)));
	connect(this, SIGNAL(urlChanged(const QUrl &)), SLOT(onUrlChanged(const QUrl &)));
}

MaxQWebView::~MaxQWebView()
{
	qunbind(this);
}

void MaxQWebView::onIconChanged() {
	_qt_qwebkit_QWebView__OnIconChanged(maxHandle);
}

void MaxQWebView::onLinkClicked( const QUrl & url ) {
	_qt_qwebkit_QWebView__OnLinkClicked(maxHandle, new MaxQUrl(url));
}

void MaxQWebView::onLoadFinished( bool ok ) {
	_qt_qwebkit_QWebView__OnLoadFinished(maxHandle, static_cast<int>(ok));
}

void MaxQWebView::onLoadProgress( int progress ) {
	_qt_qwebkit_QWebView__OnLoadProgress(maxHandle, progress);
}

void MaxQWebView::onLoadStarted() {
	_qt_qwebkit_QWebView__OnLoadStarted(maxHandle);
}

void MaxQWebView::onSelectionChanged() {
	_qt_qwebkit_QWebView__OnSelectionChanged(maxHandle);
}

void MaxQWebView::onStatusBarMessage( const QString & text ) {
	_qt_qwebkit_QWebView__OnStatusBarMessage(maxHandle, bbStringFromQString(text));
}

void MaxQWebView::onTitleChanged( const QString & title ) {
	_qt_qwebkit_QWebView__OnTitleChanged(maxHandle, bbStringFromQString(title));
}

void MaxQWebView::onUrlChanged( const QUrl & url ) {
	_qt_qwebkit_QWebView__OnUrlChanged(maxHandle, new MaxQUrl(url));
}


// ****************** DEFAULT HANDLERS ********************

// QWebView
// QWidget
void MaxQWebView::defaultactionEvent(QActionEvent * event){
	QWebView::actionEvent(event);
}

void MaxQWebView::defaultchangeEvent(QEvent * event){
	QWebView::changeEvent(event);
}

void MaxQWebView::defaultcloseEvent(QCloseEvent * event){
	QWebView::closeEvent(event);
}

void MaxQWebView::defaultcontextMenuEvent(QContextMenuEvent * event){
	QWebView::contextMenuEvent(event);
}

void MaxQWebView::defaultdragEnterEvent(QDragEnterEvent * event){
	QWebView::dragEnterEvent(event);
}

void MaxQWebView::defaultdragLeaveEvent(QDragLeaveEvent * event){
	QWebView::dragLeaveEvent(event);
}

void MaxQWebView::defaultdragMoveEvent(QDragMoveEvent * event){
	QWebView::dragMoveEvent(event);
}

void MaxQWebView::defaultdropEvent(QDropEvent * event){
	QWebView::dropEvent(event);
}

void MaxQWebView::defaultenterEvent(QEvent * event){
	QWebView::enterEvent(event);
}

void MaxQWebView::defaultfocusInEvent(QFocusEvent * event){
	QWebView::focusInEvent(event);
}

bool MaxQWebView::defaultfocusNextChild() {
	return QWebView::focusNextChild();
}

bool MaxQWebView::defaultfocusNextPrevChild(bool next){
	return QWebView::focusNextPrevChild(next);
}

void MaxQWebView::defaultfocusOutEvent(QFocusEvent * event){
	QWebView::focusOutEvent(event);
}

bool MaxQWebView::defaultfocusPreviousChild() {
	return QWebView::focusPreviousChild();
}

void MaxQWebView::defaulthideEvent(QHideEvent * event){
	QWebView::hideEvent(event);
}

void MaxQWebView::defaultinputMethodEvent(QInputMethodEvent * event){
	QWebView::inputMethodEvent(event);
}

void MaxQWebView::defaultkeyPressEvent(QKeyEvent * event){
	QWebView::keyPressEvent(event);
}

void MaxQWebView::defaultkeyReleaseEvent(QKeyEvent * event){
	QWebView::keyReleaseEvent(event);
}

void MaxQWebView::defaultleaveEvent(QEvent * event){
	QWebView::leaveEvent(event);
}

void MaxQWebView::defaultmouseDoubleClickEvent(QMouseEvent * event){
	QWebView::mouseDoubleClickEvent(event);
}

void MaxQWebView::defaultmouseMoveEvent(QMouseEvent * event){
	QWebView::mouseMoveEvent(event);
}

void MaxQWebView::defaultmousePressEvent(QMouseEvent * event){
	QWebView::mousePressEvent(event);
}

void MaxQWebView::defaultmouseReleaseEvent(QMouseEvent * event){
	QWebView::mouseReleaseEvent(event);
}

void MaxQWebView::defaultmoveEvent(QMoveEvent * event){
	QWebView::moveEvent(event);
}

void MaxQWebView::defaultpaintEvent(QPaintEvent * event){
	QWebView::paintEvent(event);
}

void MaxQWebView::defaultresizeEvent(QResizeEvent * event){
	QWebView::resizeEvent(event);
}

void MaxQWebView::defaultshowEvent(QShowEvent * event){
	QWebView::showEvent(event);
}

void MaxQWebView::defaulttabletEvent(QTabletEvent * event){
	QWebView::tabletEvent(event);
}

void MaxQWebView::defaultwheelEvent(QWheelEvent * event){
	QWebView::wheelEvent(event);
}

// QObject
bool MaxQWebView::defaultevent(QEvent * event){
	return QWebView::event(event);
}

void MaxQWebView::defaulttimerEvent(QTimerEvent * event){
	QWebView::timerEvent(event);
}


// ****************** HANDLERS - TO MAX ********************

// QWebView
// QWidget
void MaxQWebView::mouseMoveEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseMoveEvent(maxHandle, event);
}

void MaxQWebView::mousePressEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mousePressEvent(maxHandle, event);
}

void MaxQWebView::mouseReleaseEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseReleaseEvent(maxHandle, event);
}


void MaxQWebView::actionEvent(QActionEvent * event) {
	_qt_qwidget_QWidget__actionEvent(maxHandle, event);
}

void MaxQWebView::changeEvent(QEvent * event) {
	_qt_qwidget_QWidget__changeEvent(maxHandle, event);
}

void MaxQWebView::closeEvent(QCloseEvent * event) {
	_qt_qwidget_QWidget__closeEvent(maxHandle, event);
}

void MaxQWebView::contextMenuEvent(QContextMenuEvent * event) {
	_qt_qwidget_QWidget__contextMenuEvent(maxHandle, event);
}

void MaxQWebView::dragEnterEvent(QDragEnterEvent * event) {
	_qt_qwidget_QWidget__dragEnterEvent(maxHandle, event);
}

void MaxQWebView::dragLeaveEvent(QDragLeaveEvent * event) {
	_qt_qwidget_QWidget__dragLeaveEvent(maxHandle, event);
}

void MaxQWebView::dragMoveEvent(QDragMoveEvent * event) {
	_qt_qwidget_QWidget__dragMoveEvent(maxHandle, event);
}

void MaxQWebView::dropEvent(QDropEvent * event) {
	_qt_qwidget_QWidget__dropEvent(maxHandle, event);
}

void MaxQWebView::enterEvent(QEvent * event) {
	_qt_qwidget_QWidget__enterEvent(maxHandle, event);
}

void MaxQWebView::focusInEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusInEvent(maxHandle, event);
}

bool MaxQWebView::focusNextChild () {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextChild(maxHandle));
}

bool MaxQWebView::focusNextPrevChild(bool next) {
	return static_cast<bool>(_qt_qwidget_QWidget__focusNextPrevChild(maxHandle, static_cast<int>(next)));
}

void MaxQWebView::focusOutEvent(QFocusEvent * event) {
	_qt_qwidget_QWidget__focusOutEvent(maxHandle, event);
}

bool MaxQWebView::focusPreviousChild() {
	return static_cast<bool>(_qt_qwidget_QWidget__focusPreviousChild(maxHandle));
}

void MaxQWebView::hideEvent(QHideEvent * event) {
	_qt_qwidget_QWidget__hideEvent(maxHandle, event);
}

void MaxQWebView::inputMethodEvent(QInputMethodEvent * event) {
	_qt_qwidget_QWidget__inputMethodEvent(maxHandle, event);
}

void MaxQWebView::leaveEvent(QEvent * event) {
	_qt_qwidget_QWidget__leaveEvent(maxHandle, event);
}

void MaxQWebView::keyPressEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyPressEvent(maxHandle, event);
}

void MaxQWebView::keyReleaseEvent(QKeyEvent * event) {
	_qt_qwidget_QWidget__keyReleaseEvent(maxHandle, event);
}

void MaxQWebView::mouseDoubleClickEvent(QMouseEvent * event) {
	_qt_qwidget_QWidget__mouseDoubleClickEvent(maxHandle, event);
}

void MaxQWebView::moveEvent(QMoveEvent * event) {
	_qt_qwidget_QWidget__moveEvent(maxHandle, event);
}

void MaxQWebView::paintEvent(QPaintEvent * event) {
	_qt_qwidget_QWidget__paintEvent(maxHandle, event);
}

void MaxQWebView::resizeEvent(QResizeEvent * event) {
	_qt_qwidget_QWidget__resizeEvent(maxHandle, event);
}

void MaxQWebView::showEvent(QShowEvent * event) {
	_qt_qwidget_QWidget__showEvent(maxHandle, event);
}

void MaxQWebView::tabletEvent(QTabletEvent * event) {
	_qt_qwidget_QWidget__tabletEvent(maxHandle, event);
}

void MaxQWebView::wheelEvent(QWheelEvent * event) {
	_qt_qwidget_QWidget__wheelEvent(maxHandle, event);
}

// QObject
bool MaxQWebView::event(QEvent * event) {
	return static_cast<bool>(_qt_qobject_QObject__event(maxHandle, event));
}

void MaxQWebView::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}

// *********************************************

// QWebView
// QWidget
void bmx_qt_qwebview_default_actionevent(MaxQWebView * view, QActionEvent * event) {
	view->defaultactionEvent(event);
}

void bmx_qt_qwebview_default_changeevent(MaxQWebView * view, QEvent * event) {
	view->defaultchangeEvent(event);
}

void bmx_qt_qwebview_default_closeevent(MaxQWebView * view, QCloseEvent * event) {
	view->defaultcloseEvent(event);
}

void bmx_qt_qwebview_default_contextmenuevent(MaxQWebView * view, QContextMenuEvent * event) {
	view->defaultcontextMenuEvent(event);
}

void bmx_qt_qwebview_default_dragenterevent(MaxQWebView * view, QDragEnterEvent * event) {
	view->defaultdragEnterEvent(event);
}

void bmx_qt_qwebview_default_dragleaveevent(MaxQWebView * view, QDragLeaveEvent * event) {
	view->defaultdragLeaveEvent(event);
}

void bmx_qt_qwebview_default_dragmoveevent(MaxQWebView * view, QDragMoveEvent * event) {
	view->defaultdragMoveEvent(event);
}

void bmx_qt_qwebview_default_dropevent(MaxQWebView * view, QDropEvent * event) {
	view->defaultdropEvent(event);
}

void bmx_qt_qwebview_default_enterevent(MaxQWebView * view, QEvent * event) {
	view->defaultenterEvent(event);
}

void bmx_qt_qwebview_default_focusinevent(MaxQWebView * view, QFocusEvent * event) {
	view->defaultfocusInEvent(event);
}

int bmx_qt_qwebview_default_focusnextprevchild(MaxQWebView * view, int next) {
	return static_cast<int>(view->defaultfocusNextPrevChild(static_cast<bool>(next)));
}

int bmx_qt_qwebview_default_focusnextchild(MaxQWebView * view) {
	return static_cast<int>(view->defaultfocusNextChild());
}

void bmx_qt_qwebview_default_focusoutevent(MaxQWebView * view, QFocusEvent * event) {
	view->defaultfocusOutEvent(event);
}

int bmx_qt_qwebview_default_focuspreviouschild(MaxQWebView * view) {
	return static_cast<int>(view->defaultfocusPreviousChild());
}

void bmx_qt_qwebview_default_hideevent(MaxQWebView * view, QHideEvent * event) {
	view->defaulthideEvent(event);
}

void bmx_qt_qwebview_default_inputmethodevent(MaxQWebView * view, QInputMethodEvent * event) {
	view->defaultinputMethodEvent(event);
}

void bmx_qt_qwebview_default_keypressevent(MaxQWebView * view, QKeyEvent * event) {
	view->defaultkeyPressEvent(event);
}

void bmx_qt_qwebview_default_keyreleaseevent(MaxQWebView * view, QKeyEvent * event) {
	view->defaultkeyReleaseEvent(event);
}

void bmx_qt_qwebview_default_leaveevent(MaxQWebView * view, QEvent * event) {
	view->defaultleaveEvent(event);
}

void bmx_qt_qwebview_default_mousedoubleclickevent(MaxQWebView * view, QMouseEvent * event) {
	view->defaultmouseDoubleClickEvent(event);
}

void bmx_qt_qwebview_default_mousemoveevent(MaxQWebView * view, QMouseEvent * event) {
	view->defaultmouseMoveEvent(event);
}

void bmx_qt_qwebview_default_mousepressevent(MaxQWebView * view, QMouseEvent * event) {
	view->defaultmousePressEvent(event);
}

void bmx_qt_qwebview_default_mousereleaseevent(MaxQWebView * view, QMouseEvent * event) {
	view->defaultmouseReleaseEvent(event);
}

void bmx_qt_qwebview_default_moveevent(MaxQWebView * view, QMoveEvent * event) {
	view->defaultmoveEvent(event);
}

void bmx_qt_qwebview_default_paintevent(MaxQWebView * view, QPaintEvent * event) {
	view->defaultpaintEvent(event);
}

void bmx_qt_qwebview_default_resizeevent(MaxQWebView * view, QResizeEvent * event) {
	view->defaultresizeEvent(event);
}

void bmx_qt_qwebview_default_showevent(MaxQWebView * view, QShowEvent * event) {
	view->defaultshowEvent(event);
}

void bmx_qt_qwebview_default_tabletevent(MaxQWebView * view, QTabletEvent * event) {
	view->defaulttabletEvent(event);
}

void bmx_qt_qwebview_default_wheelevent(MaxQWebView * view, QWheelEvent * event) {
	view->defaultwheelEvent(event);
}

// QObject
int bmx_qt_qwebview_default_event(MaxQWebView * view, QEvent * event) {
	return static_cast<int>(view->defaultevent(event));
}

void bmx_qt_qwebview_default_timerevent(MaxQWebView * view, QTimerEvent * event) {
	view->defaulttimerEvent(event);
}


// ---------------------------------------------------------------------------------------

MaxQWebHitTestResult::MaxQWebHitTestResult(const QWebHitTestResult & r)
	: result(r)
{
}

MaxQWebHitTestResult::~MaxQWebHitTestResult()
{
}

QWebHitTestResult & MaxQWebHitTestResult::Result() {
	return result;
}

// *********************************************

QWebView * bmx_qt_qwebview_create(BBObject * handle, QWidget * parent, int flags) {
	return new MaxQWebView(handle, parent);
}

void bmx_qt_qwebview_load(QWebView * view, MaxQUrl * url) {
	view->load(url->Url());
}

QAction * bmx_qt_qwebview_pageaction(QWebView * view, int a) {
	QAction * action = view->pageAction((QWebPage::WebAction)a);
	MaxQAction::link(action);
	return action;
}

BBString * bmx_qt_qwebview_title(QWebView * view) {
	return bbStringFromQString(view->title());
}

MaxQUrl * bmx_qt_qwebview_url(QWebView * view) {
	return new MaxQUrl(view->url());
}

QWebSettings * bmx_qt_qwebview_settings(QWebView * view) {
	return view->settings();
}

QWebPage * bmx_qt_qwebview_page(QWebView * view) {
	return view->page();
}

int bmx_qt_qwebview_findtext(QWebView * view, BBString * subString, int options) {
	return view->findText(qStringFromBBString(subString), (QWebPage::FindFlags)options);
}

MaxQIcon * bmx_qt_qwebview_icon(QWebView * view) {
	return new MaxQIcon(view->icon());
}

int bmx_qt_qwebview_ismodified(QWebView * view) {
	return static_cast<int>(view->isModified());
}

BBString * bmx_qt_qwebview_selectedtext(QWebView * view) {
	return bbStringFromQString(view->selectedText());
}

void bmx_qt_qwebview_sethtml(QWebView * view, BBString * html, MaxQUrl * baseUrl) {
	if (baseUrl) {
		view->setHtml(qStringFromBBString(html), baseUrl->Url());
	} else {
		view->setHtml(qStringFromBBString(html));
	}
}

void bmx_qt_qwebview_setpage(QWebView * view, QWebPage * page) {
	view->setPage(page);
}

void bmx_qt_qwebview_settextsizemultiplier(QWebView * view, double factor) {
	view->setTextSizeMultiplier(factor);
}

void bmx_qt_qwebview_seturl(QWebView * view, MaxQUrl * url) {
	view->setUrl(url->Url());
}

void bmx_qt_qwebview_setzoomfactor(QWebView * view, double factor) {
	view->setZoomFactor(factor);
}


// *********************************************

void bmx_qt_qwebsettings_setattribute(QWebSettings * settings, int attribute, int on) {
	settings->setAttribute((QWebSettings::WebAttribute)attribute, static_cast<bool>(on));
}

BBString * bmx_qt_qwebsettings_fontfamily(QWebSettings * settings, int which) {
	return bbStringFromQString(settings->fontFamily((QWebSettings::FontFamily)which));
}

int bmx_qt_qwebsettings_fontsize(QWebSettings * settings, int sizeType) {
	return settings->fontSize((QWebSettings::FontSize)sizeType);
}

void bmx_qt_qwebsettings_resetattribute(QWebSettings * settings, int attribute) {
	settings->resetAttribute((QWebSettings::WebAttribute)attribute);
}

void bmx_qt_qwebsettings_resetfontfamily(QWebSettings * settings, int which) {
	settings->resetFontFamily((QWebSettings::FontFamily)which);
}

void bmx_qt_qwebsettings_resetfontsize(QWebSettings * settings, int sizeType) {
	settings->resetFontSize((QWebSettings::FontSize)sizeType);
}

void bmx_qt_qwebsettings_setfontfamily(QWebSettings * settings, int which, BBString * family) {
	settings->setFontFamily((QWebSettings::FontFamily)which, qStringFromBBString(family));
}

void bmx_qt_qwebsettings_setfontsize(QWebSettings * settings, int sizeType, int size) {
	settings->setFontSize((QWebSettings::FontSize)sizeType, size);
}

void bmx_qt_qwebsettings_setuserstylesheeturl(QWebSettings * settings, MaxQUrl * location) {
	settings->setUserStyleSheetUrl(location->Url());
}

int bmx_qt_qwebsettings_testattribute(QWebSettings * settings, int attribute) {
	return static_cast<int>(settings->testAttribute((QWebSettings::WebAttribute)attribute));
}

MaxQUrl * bmx_qt_qwebsettings_userstylesheeturl(QWebSettings * settings) {
	return new MaxQUrl(settings->userStyleSheetUrl());
}

void bmx_qt_qwebsettings_clearicondatabase() {
	QWebSettings::clearIconDatabase();
}

QWebSettings * bmx_qt_qwebsettings_globalsettings() {
	return QWebSettings::globalSettings();
}

BBString * bmx_qt_qwebsettings_icondatabasepath() {
	return bbStringFromQString(QWebSettings::iconDatabasePath());
}

MaxQIcon * bmx_qt_qwebsettings_iconforurl(MaxQUrl * url) {
	return new MaxQIcon(QWebSettings::iconForUrl(url->Url()));
}

int bmx_qt_qwebsettings_maximumpagesincache() {
	return QWebSettings::maximumPagesInCache();
}

void bmx_qt_qwebsettings_offlinestoragedefaultquota(BBInt64 * value) {
	*value = QWebSettings::offlineStorageDefaultQuota();
}

BBString * bmx_qt_qwebsettings_offlinestoragepath() {
	return bbStringFromQString(QWebSettings::offlineStoragePath());
}

void bmx_qt_qwebsettings_seticondatabasepath(BBString * path) {
	QWebSettings::setIconDatabasePath(qStringFromBBString(path));
}

void bmx_qt_qwebsettings_setmaximumpagesincache(int pages) {
	QWebSettings::setMaximumPagesInCache(pages);
}

void bmx_qt_qwebsettings_setobjectcachecapacities(int cacheMinDeadCapacity, int cacheMaxDead, int totalCapacity) {
	QWebSettings::setObjectCacheCapacities(cacheMinDeadCapacity, cacheMaxDead, totalCapacity);
}

void bmx_qt_qwebsettings_setofflinestoragedefaultquota(BBInt64 maximumSize) {
	QWebSettings::setOfflineStorageDefaultQuota(maximumSize);
}

void bmx_qt_qwebsettings_setofflinestoragepath(BBString * path) {
	QWebSettings::setOfflineStoragePath(qStringFromBBString(path));
}

void bmx_qt_qwebsettings_setwebgraphic(int graphicType, MaxQPixmap * graphic) {
	QWebSettings::setWebGraphic((QWebSettings::WebGraphic)graphicType, graphic->Pixmap());
}

MaxQPixmap * bmx_qt_qwebsettings_webgraphic(int graphicType) {
	return new MaxQPixmap(QWebSettings::webGraphic((QWebSettings::WebGraphic)graphicType));
}

// *********************************************

QWebFrame * bmx_qt_qwebpage_mainframe(QWebPage * page) {
	return page->mainFrame();
}

// *********************************************

BBString * bmx_qt_qwebframe_evaluatejavascript(QWebFrame * frame, BBString * scriptSource) {
	return bbStringFromQString(frame->evaluateJavaScript(qStringFromBBString(scriptSource)).toString());
}

MaxQWebHitTestResult * bmx_qt_qwebframe_hittestcontent(QWebFrame * frame, int x, int y) {
	return new MaxQWebHitTestResult(frame->hitTestContent(QPoint(x, y)));
}

// *********************************************

BBString * bmx_qt_qwebhittestresult_alternatetext(MaxQWebHitTestResult * res) {
	return bbStringFromQString(res->Result().alternateText());
}

MaxQRect * bmx_qt_qwebhittestresult_boundingrect(MaxQWebHitTestResult * res) {
	return new MaxQRect(res->Result().boundingRect());
}

QWebFrame * bmx_qt_qwebhittestresult_frame(MaxQWebHitTestResult * res) {
	return res->Result().frame();
}

MaxQUrl * bmx_qt_qwebhittestresult_imageurl(MaxQWebHitTestResult * res) {
	return new MaxQUrl(res->Result().imageUrl());
}

int bmx_qt_qwebhittestresult_iscontenteditable(MaxQWebHitTestResult * res) {
	return static_cast<int>(res->Result().isContentEditable());
}

int bmx_qt_qwebhittestresult_iscontentselected(MaxQWebHitTestResult * res) {
	return static_cast<int>(res->Result().isContentSelected());
}

int bmx_qt_qwebhittestresult_isnull(MaxQWebHitTestResult * res) {
	return static_cast<int>(res->Result().isNull());
}

QWebFrame * bmx_qt_qwebhittestresult_linktargetframe(MaxQWebHitTestResult * res) {
	return res->Result().linkTargetFrame();
}

BBString * bmx_qt_qwebhittestresult_linktext(MaxQWebHitTestResult * res) {
	return bbStringFromQString(res->Result().linkText());
}

MaxQUrl * bmx_qt_qwebhittestresult_linktitle(MaxQWebHitTestResult * res) {
	return new MaxQUrl(res->Result().linkTitle());
}

MaxQUrl * bmx_qt_qwebhittestresult_linkurl(MaxQWebHitTestResult * res) {
	return new MaxQUrl(res->Result().linkUrl());
}

MaxQPixmap * bmx_qt_qwebhittestresult_pixmap(MaxQWebHitTestResult * res) {
	return new MaxQPixmap(res->Result().pixmap());
}

void bmx_qt_qwebhittestresult_pos(MaxQWebHitTestResult * res, int * x, int * y) {
	QPoint p(res->Result().pos());
	*x = p.x();
	*y = p.y();
}

BBString * bmx_qt_qwebhittestresult_title(MaxQWebHitTestResult * res) {
	return bbStringFromQString(res->Result().title());
}

void bmx_qt_qwebhittestresult_free(MaxQWebHitTestResult * res) {
	delete res;
}



// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"

