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

#ifndef MAX_QT_QWEBKIT
#define MAX_QT_QWEBKIT

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include "../qwebhistory.mod/glue.h"
#include <QtCore>
#include <QWebView>
#include <QWebFrame>
#include <QWebPage>
#include <QWebHitTestResult>

class MaxQWebView;
class MaxQWebHitTestResult;

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


	// QWebView
	// QWidget
	void bmx_qt_qwebview_default_actionevent(MaxQWebView * view, QActionEvent * event);
	void bmx_qt_qwebview_default_changeevent(MaxQWebView * view, QEvent * event);
	void bmx_qt_qwebview_default_closeevent(MaxQWebView * view, QCloseEvent * event);
	void bmx_qt_qwebview_default_contextmenuevent(MaxQWebView * view, QContextMenuEvent * event);
	void bmx_qt_qwebview_default_dragenterevent(MaxQWebView * view, QDragEnterEvent * event);
	void bmx_qt_qwebview_default_dragleaveevent(MaxQWebView * view, QDragLeaveEvent * event);
	void bmx_qt_qwebview_default_dragmoveevent(MaxQWebView * view, QDragMoveEvent * event);
	void bmx_qt_qwebview_default_dropevent(MaxQWebView * view, QDropEvent * event);
	void bmx_qt_qwebview_default_enterevent(MaxQWebView * view, QEvent * event);
	void bmx_qt_qwebview_default_focusinevent(MaxQWebView * view, QFocusEvent * event);
	int bmx_qt_qwebview_default_focusnextprevchild(MaxQWebView * view, int next);
	int bmx_qt_qwebview_default_focusnextchild(MaxQWebView * view);
	void bmx_qt_qwebview_default_focusoutevent(MaxQWebView * view, QFocusEvent * event);
	int bmx_qt_qwebview_default_focuspreviouschild(MaxQWebView * view);
	void bmx_qt_qwebview_default_hideevent(MaxQWebView * view, QHideEvent * event);
	void bmx_qt_qwebview_default_inputmethodevent(MaxQWebView * view, QInputMethodEvent * event);
	void bmx_qt_qwebview_default_keypressevent(MaxQWebView * view, QKeyEvent * event);
	void bmx_qt_qwebview_default_keyreleaseevent(MaxQWebView * view, QKeyEvent * event);
	void bmx_qt_qwebview_default_leaveevent(MaxQWebView * view, QEvent * event);
	void bmx_qt_qwebview_default_mousedoubleclickevent(MaxQWebView * view, QMouseEvent * event);
	void bmx_qt_qwebview_default_mousemoveevent(MaxQWebView * view, QMouseEvent * event);
	void bmx_qt_qwebview_default_mousepressevent(MaxQWebView * view, QMouseEvent * event);
	void bmx_qt_qwebview_default_mousereleaseevent(MaxQWebView * view, QMouseEvent * event);
	void bmx_qt_qwebview_default_moveevent(MaxQWebView * view, QMoveEvent * event);
	void bmx_qt_qwebview_default_paintevent(MaxQWebView * view, QPaintEvent * event);
	void bmx_qt_qwebview_default_resizeevent(MaxQWebView * view, QResizeEvent * event);
	void bmx_qt_qwebview_default_showevent(MaxQWebView * view, QShowEvent * event);
	void bmx_qt_qwebview_default_tabletevent(MaxQWebView * view, QTabletEvent * event);
	void bmx_qt_qwebview_default_wheelevent(MaxQWebView * view, QWheelEvent * event);
	// QObject
	int bmx_qt_qwebview_default_event(MaxQWebView * view, QEvent * event);
	void bmx_qt_qwebview_default_timerevent(MaxQWebView * view, QTimerEvent * event);



	QWebView * bmx_qt_qwebview_create(BBObject * handle, QWidget * parent, int flags);
	void bmx_qt_qwebview_load(QWebView * view, MaxQUrl * url);
	QAction * bmx_qt_qwebview_pageaction(QWebView * view, int action);
	BBString * bmx_qt_qwebview_title(QWebView * view);
	MaxQUrl * bmx_qt_qwebview_url(QWebView * view);
	QWebSettings * bmx_qt_qwebview_settings(QWebView * view);
	QWebPage * bmx_qt_qwebview_page(QWebView * view);
	int bmx_qt_qwebview_findtext(QWebView * view, BBString * subString, int options);
	MaxQIcon * bmx_qt_qwebview_icon(QWebView * view);
	int bmx_qt_qwebview_ismodified(QWebView * view);
	BBString * bmx_qt_qwebview_selectedtext(QWebView * view);
	void bmx_qt_qwebview_sethtml(QWebView * view, BBString * html, MaxQUrl * baseUrl);
	void bmx_qt_qwebview_setpage(QWebView * view, QWebPage * page);
	void bmx_qt_qwebview_settextsizemultiplier(QWebView * view, double factor);
	void bmx_qt_qwebview_seturl(QWebView * view, MaxQUrl * url);
	void bmx_qt_qwebview_setzoomfactor(QWebView * view, double factor);
	void bmx_qt_qwebview_back(QWebView * view);
	void bmx_qt_qwebview_forward(QWebView * view);
	void bmx_qt_qwebview_reload(QWebView * view);
	void bmx_qt_qwebview_stop(QWebView * view);

	void bmx_qt_qwebsettings_setattribute(QWebSettings * settings, int attribute, int on);
	BBString * bmx_qt_qwebsettings_fontfamily(QWebSettings * settings, int which);
	int bmx_qt_qwebsettings_fontsize(QWebSettings * settings, int sizeType);
	void bmx_qt_qwebsettings_resetattribute(QWebSettings * settings, int attribute);
	void bmx_qt_qwebsettings_resetfontfamily(QWebSettings * settings, int which);
	void bmx_qt_qwebsettings_resetfontsize(QWebSettings * settings, int sizeType);
	void bmx_qt_qwebsettings_setfontfamily(QWebSettings * settings, int which, BBString * family);
	void bmx_qt_qwebsettings_setfontsize(QWebSettings * settings, int sizeType, int size);
	void bmx_qt_qwebsettings_setuserstylesheeturl(QWebSettings * settings, MaxQUrl * location);
	int bmx_qt_qwebsettings_testattribute(QWebSettings * settings, int attribute);
	MaxQUrl * bmx_qt_qwebsettings_userstylesheeturl(QWebSettings * settings);
	void bmx_qt_qwebsettings_clearicondatabase();
	QWebSettings * bmx_qt_qwebsettings_globalsettings();
	BBString * bmx_qt_qwebsettings_icondatabasepath();
	MaxQIcon * bmx_qt_qwebsettings_iconforurl(MaxQUrl * url);
	int bmx_qt_qwebsettings_maximumpagesincache();
	void bmx_qt_qwebsettings_offlinestoragedefaultquota(BBInt64 * value);
	BBString * bmx_qt_qwebsettings_offlinestoragepath();
	void bmx_qt_qwebsettings_seticondatabasepath(BBString * path);
	void bmx_qt_qwebsettings_setmaximumpagesincache(int pages);
	void bmx_qt_qwebsettings_setobjectcachecapacities(int cacheMinDeadCapacity, int cacheMaxDead, int totalCapacity);
	void bmx_qt_qwebsettings_setofflinestoragedefaultquota(BBInt64 maximumSize);
	void bmx_qt_qwebsettings_setofflinestoragepath(BBString * path);
	void bmx_qt_qwebsettings_setwebgraphic(int graphicType, MaxQPixmap * graphic);
	MaxQPixmap * bmx_qt_qwebsettings_webgraphic(int graphicType);

	QWebFrame * bmx_qt_qwebpage_mainframe(QWebPage * page);

	BBString * bmx_qt_qwebframe_evaluatejavascript(QWebFrame * frame, BBString * scriptSource);
	MaxQWebHitTestResult * bmx_qt_qwebframe_hittestcontent(QWebFrame * frame, int x, int y);

	BBString * bmx_qt_qwebhittestresult_alternatetext(MaxQWebHitTestResult * res);
	MaxQRect * bmx_qt_qwebhittestresult_boundingrect(MaxQWebHitTestResult * res);
	QWebFrame * bmx_qt_qwebhittestresult_frame(MaxQWebHitTestResult * res);
	MaxQUrl * bmx_qt_qwebhittestresult_imageurl(MaxQWebHitTestResult * res);
	int bmx_qt_qwebhittestresult_iscontenteditable(MaxQWebHitTestResult * res);
	int bmx_qt_qwebhittestresult_iscontentselected(MaxQWebHitTestResult * res);
	int bmx_qt_qwebhittestresult_isnull(MaxQWebHitTestResult * res);
	QWebFrame * bmx_qt_qwebhittestresult_linktargetframe(MaxQWebHitTestResult * res);
	BBString * bmx_qt_qwebhittestresult_linktext(MaxQWebHitTestResult * res);
	MaxQUrl * bmx_qt_qwebhittestresult_linktitle(MaxQWebHitTestResult * res);
	MaxQUrl * bmx_qt_qwebhittestresult_linkurl(MaxQWebHitTestResult * res);
	MaxQPixmap * bmx_qt_qwebhittestresult_pixmap(MaxQWebHitTestResult * res);
	void bmx_qt_qwebhittestresult_pos(MaxQWebHitTestResult * res, int * x, int * y);
	BBString * bmx_qt_qwebhittestresult_title(MaxQWebHitTestResult * res);
	void bmx_qt_qwebhittestresult_free(MaxQWebHitTestResult * res);

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

public:
	// QWebView
	// QWidget
	void defaultactionEvent(QActionEvent * event);
	void defaultchangeEvent(QEvent * event);
	void defaultcloseEvent(QCloseEvent * event);
	void defaultcontextMenuEvent(QContextMenuEvent * event);
	void defaultdragEnterEvent(QDragEnterEvent * event);
	void defaultdragLeaveEvent(QDragLeaveEvent * event);
	void defaultdragMoveEvent(QDragMoveEvent * event);
	void defaultdropEvent(QDropEvent * event);
	void defaultenterEvent(QEvent * event);
	void defaultfocusInEvent(QFocusEvent * event);
	bool defaultfocusNextChild ();
	bool defaultfocusNextPrevChild(bool next);
	void defaultfocusOutEvent(QFocusEvent * event);
	bool defaultfocusPreviousChild();
	void defaulthideEvent(QHideEvent * event);
	void defaultinputMethodEvent(QInputMethodEvent * event);
	void defaultkeyPressEvent(QKeyEvent * event);
	void defaultkeyReleaseEvent(QKeyEvent * event);
	void defaultleaveEvent(QEvent * event);
	void defaultmouseDoubleClickEvent(QMouseEvent * event);
	void defaultmouseMoveEvent(QMouseEvent * event);
	void defaultmousePressEvent(QMouseEvent * event);
	void defaultmouseReleaseEvent(QMouseEvent * event);
	void defaultmoveEvent(QMoveEvent * event);
	void defaultpaintEvent(QPaintEvent * event);
	void defaultresizeEvent(QResizeEvent * event);
	void defaultshowEvent(QShowEvent * event);
	void defaulttabletEvent(QTabletEvent * event);
	void defaultwheelEvent(QWheelEvent * event);
	// QObject
	bool defaultevent(QEvent * event);
	void defaulttimerEvent(QTimerEvent * event);
	
protected:
	// QWebView
	// QWidget
	virtual void actionEvent(QActionEvent * event);
	virtual void changeEvent(QEvent * event);
	virtual void closeEvent(QCloseEvent * event);
	virtual void contextMenuEvent(QContextMenuEvent * event);
	virtual void dragEnterEvent(QDragEnterEvent * event);
	virtual void dragLeaveEvent(QDragLeaveEvent * event);
	virtual void dragMoveEvent(QDragMoveEvent * event);
	virtual void dropEvent(QDropEvent * event);
	virtual void enterEvent(QEvent * event);
	virtual void focusInEvent(QFocusEvent * event);
	bool focusNextChild();
	virtual bool focusNextPrevChild(bool next);
	virtual void focusOutEvent(QFocusEvent * event);
	bool focusPreviousChild();
	virtual void hideEvent(QHideEvent * event);
	virtual void inputMethodEvent(QInputMethodEvent * event);
	virtual void leaveEvent(QEvent * event);
	virtual void keyPressEvent(QKeyEvent * event);
	virtual void keyReleaseEvent(QKeyEvent * event);
	virtual void mouseDoubleClickEvent(QMouseEvent * event);
	virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void mousePressEvent(QMouseEvent * event);
	virtual void mouseReleaseEvent(QMouseEvent * event);
	virtual void moveEvent(QMoveEvent * event);
	//virtual void paintEvent(QPaintEvent * event); // BaH - crashes on Win32!?
	virtual void resizeEvent(QResizeEvent * event);
	virtual void showEvent(QShowEvent * event);
	virtual void tabletEvent(QTabletEvent * event);
	virtual void wheelEvent(QWheelEvent * event);
	// QObject
	virtual bool event(QEvent * event);
	virtual void timerEvent(QTimerEvent * event);

};

class MaxQWebHitTestResult
{
public:
	MaxQWebHitTestResult(const QWebHitTestResult & r);
	~MaxQWebHitTestResult();
	
	QWebHitTestResult & Result();

private:
	QWebHitTestResult result;
};

#endif
