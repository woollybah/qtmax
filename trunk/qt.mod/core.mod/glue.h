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

#include <QtCore>
#include <QUrl>
#include <QRect>
#include <QTime>

#include <map>

#ifndef BMX_QT_CORE
#define BMX_QT_CORE

class MaxQUrl;
class MaxQRect;
class MaxQTime;

extern "C" {

#include <blitz.h>

	void _qt_qobject_QObject__Free(BBObject * handle);

	void qbind( QObject *obj, BBObject *peer );
	void qunbind(QObject *obj);
	BBObject *qfind( QObject *obj );
	
	BBString *bbStringFromQString(const QString &s );
	QString qStringFromBBString(BBString * s);


	MaxQUrl * bmx_qt_qurl_create(BBString * url);
	void bmx_qt_qurl_free(MaxQUrl * url);

	MaxQRect * bmx_qt_qrect_create(int x, int y, int w, int h);
	void bmx_qt_qrect_free(MaxQRect * rect);
	void bmx_qt_qrect_adjust(MaxQRect * rect, int dx1, int dy1, int dx2, int dy2);
	MaxQRect * bmx_qt_qrect_adjusted(MaxQRect * rect, int dx1, int dy1, int dx2, int dy2);
	int bmx_qt_qrect_bottom(MaxQRect * rect);
	void bmx_qt_qrect_bottomleft(MaxQRect * rect, int * x, int * y);
	void bmx_qt_qrect_bottomright(MaxQRect * rect, int * x, int * y);
	void bmx_qt_qrect_center(MaxQRect * rect, int * x, int * y);
	int bmx_qt_qrect_contains(MaxQRect * rect, int x, int y, int proper);
	int bmx_qt_qrect_containsrect(MaxQRect * rect, MaxQRect * rectangle, int proper);
	void bmx_qt_qrect_getcoords(MaxQRect * rect, int * x1, int * y1, int * x2, int * y2);
	void bmx_qt_qrect_getrect(MaxQRect * rect, int * x, int * y, int * width, int * height);
	int bmx_qt_qrect_height(MaxQRect * rect);
	MaxQRect * bmx_qt_qrect_intersected(MaxQRect * rect, MaxQRect * rectangle);
	int bmx_qt_qrect_intersects(MaxQRect * rect, MaxQRect * rectangle);
	int bmx_qt_qrect_isempty(MaxQRect * rect);
	int bmx_qt_qrect_isnull(MaxQRect * rect);
	int bmx_qt_qrect_isvalid(MaxQRect * rect);
	int bmx_qt_qrect_left(MaxQRect * rect);
	void bmx_qt_qrect_movebottom(MaxQRect * rect, int y);
	void bmx_qt_qrect_movebottomleft(MaxQRect * rect, int x, int y);
	void bmx_qt_qrect_movebottomright(MaxQRect * rect, int x, int y);
	void bmx_qt_qrect_movecenter(MaxQRect * rect, int x, int y);
	void bmx_qt_qrect_moveleft(MaxQRect * rect, int x);
	void bmx_qt_qrect_moveright(MaxQRect * rect, int x);
	void bmx_qt_qrect_moveto(MaxQRect * rect, int x, int y);
	void bmx_qt_qrect_movetop(MaxQRect * rect, int y);
	void bmx_qt_qrect_movetopleft(MaxQRect * rect, int x, int y);
	void bmx_qt_qrect_movetopright(MaxQRect * rect, int x, int y);
	MaxQRect * bmx_qt_qrect_normalized(MaxQRect * rect);
	int bmx_qt_qrect_right(MaxQRect * rect);
	void bmx_qt_qrect_setbottom(MaxQRect * rect, int y);
	void bmx_qt_qrect_setbottomleft(MaxQRect * rect, int x, int y);
	void bmx_qt_qrect_setbottomright(MaxQRect * rect, int x, int y);
	void bmx_qt_qrect_setcoords(MaxQRect * rect, int x1, int y1, int x2, int y2);
	void bmx_qt_qrect_setheight(MaxQRect * rect, int height);
	void bmx_qt_qrect_setleft(MaxQRect * rect, int x);
	void bmx_qt_qrect_setrect(MaxQRect * rect, int x, int y, int width, int height);
	void bmx_qt_qrect_setright(MaxQRect * rect, int x);
	void bmx_qt_qrect_setsize(MaxQRect * rect, int w, int h);
	void bmx_qt_qrect_settop(MaxQRect * rect, int y);
	void bmx_qt_qrect_settopleft(MaxQRect * rect, int x, int y);
	void bmx_qt_qrect_settopright(MaxQRect * rect, int x, int y);
	void bmx_qt_qrect_setwidth(MaxQRect * rect, int width);
	void bmx_qt_qrect_setx(MaxQRect * rect, int x);
	void bmx_qt_qrect_sety(MaxQRect * rect, int y);
	void bmx_qt_qrect_size(MaxQRect * rect, int * w, int * h);
	int bmx_qt_qrect_top(MaxQRect * rect);
	void bmx_qt_qrect_topleft(MaxQRect * rect, int * x, int * y);
	void bmx_qt_qrect_topright(MaxQRect * rect, int * x, int * y);
	void bmx_qt_qrect_translate(MaxQRect * rect, int dx, int dy);
	MaxQRect * bmx_qt_qrect_translated(MaxQRect * rect, int dx, int dy);
	MaxQRect * bmx_qt_qrect_united(MaxQRect * rect, MaxQRect * rectangle);
	int bmx_qt_qrect_width(MaxQRect * rect);
	int bmx_qt_qrect_x(MaxQRect * rect);
	int bmx_qt_qrect_y(MaxQRect * rect);
	
	void bmx_qt_qevent_accept(QEvent * event);
	void bmx_qt_qevent_ignore(QEvent * event);
	int bmx_qt_qevent_isaccepted(QEvent * event);
	void bmx_qt_qevent_setaccepted(QEvent * event, int accepted);
	int bmx_qt_qevent_spontaneous(QEvent * event);
	int bmx_qt_qevent_gettype(QEvent * event);

	Qt::WindowFlags bmx_qt_getwindowflags(int f);
	Qt::Alignment bmx_qt_getalignment(int a);
	Qt::FocusReason bmx_qt_getfocusreason(int r);
	Qt::TextInteractionFlags bmx_qt_inttotextinteractionflags(int f);
	Qt::TextFormat bmx_qt_inttotextformat(int f);

	int bmx_qt_qtime_elapsed(MaxQTime * time);
	int bmx_qt_qtime_hour(MaxQTime * time);
	int bmx_qt_qtime_isnull(MaxQTime * time);
	int bmx_qt_qtime_isvalid(MaxQTime * time);
	int bmx_qt_qtime_minute(MaxQTime * time);
	int bmx_qt_qtime_msec(MaxQTime * time);
	int bmx_qt_qtime_msecsto(MaxQTime * time, MaxQTime * t);
	void bmx_qt_qtime_restart(MaxQTime * time);
	int bmx_qt_qtime_second(MaxQTime * time);
	int bmx_qt_qtime_secsto(MaxQTime * time, MaxQTime * t);
	int bmx_qt_qtime_sethms(MaxQTime * time, int h, int m, int s, int ms);
	void bmx_qt_qtime_start(MaxQTime * time);
	MaxQTime * bmx_qt_qtime_currenttime();
	void bmx_qt_qtime_free(MaxQTime * time);

	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQUrl
{
public:
	MaxQUrl(const QUrl & u);
	QUrl & Url();
	void SetUrl(const QUrl & u);

private:
	QUrl url;
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQRect
{
public:
	MaxQRect(const QRect & r);
	QRect & Rect();
	void SetRect(const QRect & r);

private:
	QRect rect;
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQTime
{
public:
	MaxQTime(const QTime & t);
	QTime & Time();

private:
	QTime time;
};


#endif
