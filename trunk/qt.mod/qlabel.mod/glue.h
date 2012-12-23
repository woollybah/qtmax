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

protected:
	void timerEvent(QTimerEvent * event);
	void contextMenuEvent(QContextMenuEvent * ev);
	void focusInEvent(QFocusEvent * ev);
	bool focusNextPrevChild(bool next);
	void focusOutEvent(QFocusEvent * ev);
	void keyPressEvent(QKeyEvent * ev);
	void mouseMoveEvent(QMouseEvent * ev);
	void mousePressEvent(QMouseEvent * ev);
	void mouseReleaseEvent(QMouseEvent * ev);
	void enterEvent(QEvent * event);
	void leaveEvent(QEvent * event);
};


#endif
