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

// *********************************************

QWebView * bmx_qt_qwebview_create(BBObject * handle, QWidget * parent, int flags) {
	return new MaxQWebView(handle, parent);
}

void bmx_qt_qwebview_load(QWebView * view, MaxQUrl * url) {
	view->load(url->Url());
}

QAction * bmx_qt_qwebview_pageaction(QWebView * view, int action) {
	return view->pageAction((QWebPage::WebAction)action);
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

// *********************************************

void bmx_qt_qwebsettings_setattribute(QWebSettings * settings, int attribute, int on) {
	settings->setAttribute((QWebSettings::WebAttribute)attribute, static_cast<bool>(on));
}

// *********************************************

QWebFrame * bmx_qt_qwebpage_mainframe(QWebPage * page) {
	return page->mainFrame();
}

// *********************************************

BBString * bmx_qt_qwebframe_evaluatejavascript(QWebFrame * frame, BBString * scriptSource) {
	return bbStringFromQString(frame->evaluateJavaScript(qStringFromBBString(scriptSource)).toString());
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"

