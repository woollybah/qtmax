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

#ifndef MAX_QT_QWEBKIT
#define MAX_QT_QWEBKIT

#include "../core.mod/glue.h"
#include <QtCore>
#include <QWebView>
#include <QWebFrame>
#include <QWebPage>

class MaxQWebView;

extern "C" {

#include <blitz.h>

	void _qt_qwebkit_QWebView__OnIconChanged(BBObject * handle);
	void _qt_qwebkit_QWebView__OnLinkClicked(BBObject * handle, MaxQUrl * url);
	void _qt_qwebkit_QWebView__OnLoadFinished(BBObject * handle, int ok);
	void _qt_qwebkit_QWebView__OnLoadProgress(BBObject * handle, int progress);
	void _qt_qwebkit_QWebView__OnLoadStarted(BBObject * handle);
	void _qt_qwebkit_QWebView__OnSelectionChanged(BBObject * handle);
	void _qt_qwebkit_QWebView__OnStatusBarMessage(BBObject * handle, BBString * text);
	void _qt_qwebkit_QWebView__OnTitleChanged(BBObject * handle, BBString * title);
	void _qt_qwebkit_QWebView__OnUrlChanged(BBObject * handle, MaxQUrl * url);

	QWebView * bmx_qt_qwebview_create(BBObject * handle, QWidget * parent, int flags);
	void bmx_qt_qwebview_load(QWebView * view, MaxQUrl * url);
	QAction * bmx_qt_qwebview_pageaction(QWebView * view, int action);
	BBString * bmx_qt_qwebview_title(QWebView * view);
	MaxQUrl * bmx_qt_qwebview_url(QWebView * view);
	QWebSettings * bmx_qt_qwebview_settings(QWebView * view);
	QWebPage * bmx_qt_qwebview_page(QWebView * view);

	void bmx_qt_qwebsettings_setattribute(QWebSettings * settings, int attribute, int on);

	QWebFrame * bmx_qt_qwebpage_mainframe(QWebPage * page);

	BBString * bmx_qt_qwebframe_evaluatejavascript(QWebFrame * frame, BBString * scriptSource);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQWebView: public QWebView
{
	Q_OBJECT

public:
	MaxQWebView(BBObject * handle, QWidget * parent);
	~MaxQWebView();

private:
	BBObject * maxHandle;
	
private slots:
	void onIconChanged();
	void onLinkClicked( const QUrl & url );
	void onLoadFinished( bool ok );
	void onLoadProgress( int progress );
	void onLoadStarted();
	void onSelectionChanged();
	void onStatusBarMessage( const QString & text );
	void onTitleChanged( const QString & title );
	void onUrlChanged( const QUrl & url );
};

#endif
