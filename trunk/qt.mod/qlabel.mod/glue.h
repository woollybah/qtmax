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

#ifndef BMX_QT_QLABEL
#define BMX_QT_QLABEL

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include "../qpixmap.mod/glue.h"
#include <QtCore>
#include <QLabel>

class MaxQLabel;


extern "C" {

#include <blitz.h>

	void _qt_qlabel_QLabel__OnLinkActivated(BBObject * handle, BBString * link);
	void _qt_qlabel_QLabel__OnLinkHovered(BBObject * handle, BBString * link);

	QLabel * bmx_qt_qlabel_create(BBObject * handle, BBString * text, QWidget * parent, int f);
	int bmx_qt_qlabel_alignment(QLabel * label);
	QWidget * bmx_qt_qlabel_buddy(QLabel * label);
	int bmx_qt_qlabel_hasscaledcontents(QLabel * label);
	int bmx_qt_qlabel_indent(QLabel * label);
	int bmx_qt_qlabel_margin(QLabel * label);
	int bmx_qt_qlabel_openexternallinks(QLabel * label);
	void bmx_qt_qlabel_setalignment(QLabel * label, int alignment);
	void bmx_qt_qlabel_setbuddy(QLabel * label, QWidget * buddy);
	void bmx_qt_qlabel_setindent(QLabel * label, int indent);
	void bmx_qt_qlabel_setmargin(QLabel * label, int margin);
	void bmx_qt_qlabel_setopenexternallinks(QLabel * label, int open);
	void bmx_qt_qlabel_setscaledcontents(QLabel * label, int scaled);
	void bmx_qt_qlabel_settextformat(QLabel * label, int format);
	void bmx_qt_qlabel_settextinteractionflags(QLabel * label, int flags);
	void bmx_qt_qlabel_setwordwrap(QLabel * label, int value);
	BBString * bmx_qt_qlabel_text(QLabel * label);
	int bmx_qt_qlabel_textformat(QLabel * label);
	int bmx_qt_qlabel_textinteractionflags(QLabel * label);
	int bmx_qt_qlabel_wordwrap(QLabel * label);
	void bmx_qt_qlabel_clear(QLabel * label);
	void bmx_qt_qlabel_setnum(QLabel * label, int num);
	void bmx_qt_qlabel_setnumdouble(QLabel * label, double num);
	void bmx_qt_qlabel_settext(QLabel * label, BBString * text);
	MaxQPixmap * bmx_qt_qlabel_pixmap(QLabel * label);
	void bmx_qt_qlabel_setpixmap(QLabel * label, MaxQPixmap * pixmap);


	// QLabel
	// QFrame
	// QWidget
	void bmx_qt_qlabel_default_actionevent(MaxQLabel * label, QActionEvent * event);
	void bmx_qt_qlabel_default_changeevent(MaxQLabel * label, QEvent * event);
	void bmx_qt_qlabel_default_closeevent(MaxQLabel * label, QCloseEvent * event);
	void bmx_qt_qlabel_default_contextmenuevent(MaxQLabel * label, QContextMenuEvent * event);
	void bmx_qt_qlabel_default_dragenterevent(MaxQLabel * label, QDragEnterEvent * event);
	void bmx_qt_qlabel_default_dragleaveevent(MaxQLabel * label, QDragLeaveEvent * event);
	void bmx_qt_qlabel_default_dragmoveevent(MaxQLabel * label, QDragMoveEvent * event);
	void bmx_qt_qlabel_default_dropevent(MaxQLabel * label, QDropEvent * event);
	void bmx_qt_qlabel_default_enterevent(MaxQLabel * label, QEvent * event);
	void bmx_qt_qlabel_default_focusinevent(MaxQLabel * label, QFocusEvent * event);
	int bmx_qt_qlabel_default_focusnextprevchild(MaxQLabel * label, int next);
	int bmx_qt_qlabel_default_focusnextchild(MaxQLabel * label);
	void bmx_qt_qlabel_default_focusoutevent(MaxQLabel * label, QFocusEvent * event);
	int bmx_qt_qlabel_default_focuspreviouschild(MaxQLabel * label);
	void bmx_qt_qlabel_default_hideevent(MaxQLabel * label, QHideEvent * event);
	void bmx_qt_qlabel_default_inputmethodevent(MaxQLabel * label, QInputMethodEvent * event);
	void bmx_qt_qlabel_default_keypressevent(MaxQLabel * label, QKeyEvent * event);
	void bmx_qt_qlabel_default_keyreleaseevent(MaxQLabel * label, QKeyEvent * event);
	void bmx_qt_qlabel_default_leaveevent(MaxQLabel * label, QEvent * event);
	void bmx_qt_qlabel_default_mousedoubleclickevent(MaxQLabel * label, QMouseEvent * event);
	void bmx_qt_qlabel_default_mousemoveevent(MaxQLabel * label, QMouseEvent * event);
	void bmx_qt_qlabel_default_mousepressevent(MaxQLabel * label, QMouseEvent * event);
	void bmx_qt_qlabel_default_mousereleaseevent(MaxQLabel * label, QMouseEvent * event);
	void bmx_qt_qlabel_default_moveevent(MaxQLabel * label, QMoveEvent * event);
	void bmx_qt_qlabel_default_paintevent(MaxQLabel * label, QPaintEvent * event);
	void bmx_qt_qlabel_default_resizeevent(MaxQLabel * label, QResizeEvent * event);
	void bmx_qt_qlabel_default_showevent(MaxQLabel * label, QShowEvent * event);
	void bmx_qt_qlabel_default_tabletevent(MaxQLabel * label, QTabletEvent * event);
	void bmx_qt_qlabel_default_wheelevent(MaxQLabel * label, QWheelEvent * event);
	// QObject
	int bmx_qt_qlabel_default_event(MaxQLabel * label, QEvent * event);
	void bmx_qt_qlabel_default_timerevent(MaxQLabel * label, QTimerEvent * event);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQLabel : public QLabel
{
	Q_OBJECT

public:
	MaxQLabel(BBObject * handle, const QString & text, QWidget * parent, Qt::WindowFlags flags);
	~MaxQLabel();

private:
	BBObject * maxHandle;
	
private slots:
	void onLinkActivated(const QString & link);
	void onLinkHovered(const QString & link);
	void onCustomContextMenuRequested(const QPoint & pos);

public:
	// QLabel
	// QFrame
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
	// QLabel
	// QFrame
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
	virtual void paintEvent(QPaintEvent * event);
	virtual void resizeEvent(QResizeEvent * event);
	virtual void showEvent(QShowEvent * event);
	virtual void tabletEvent(QTabletEvent * event);
	virtual void wheelEvent(QWheelEvent * event);
	// QObject
	virtual bool event(QEvent * event);
	virtual void timerEvent(QTimerEvent * event);
};


#endif
