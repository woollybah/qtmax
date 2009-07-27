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


MaxQUrl::MaxQUrl(const QUrl& u)
	: url(u)
{
}

QUrl & MaxQUrl::Url() {
	return url;
}

void MaxQUrl::SetUrl(const QUrl & u) {
	url = u;
}

// ---------------------------------------------------------------------------------------

MaxQRect::MaxQRect(const QRect & r)
	: rect(r)
{
}

QRect & MaxQRect::Rect() {
	return rect;
}

void MaxQRect::SetRect(const QRect & r) {
	rect = r;
}

// *********************************************

typedef std::map<QObject*, BBObject*> PeerMap;

static PeerMap peerMap;

void qbind( QObject *obj, BBObject *peer ) {
	if( !obj || peer==&bbNullObject ) return;
	peerMap.insert( std::make_pair( obj,peer ) );
	BBRETAIN( peer );
}

BBObject *qfind( QObject *obj ){
	if( !obj ) return &bbNullObject;
	PeerMap::iterator it = peerMap.find( obj );
	if( it != peerMap.end() ) return it->second;
	return &bbNullObject;
}

void qunbind(QObject *obj) {
	BBObject * peer = qfind(obj);
	if (peer != &bbNullObject) {
		peerMap.erase(obj);
		_qt_qobject_QObject__Free(peer);
		BBRELEASE(peer);
	}
}

// *********************************************

// Converts a QString to a BBString
BBString *bbStringFromQString(const QString &s ) {
	return bbStringFromShorts((const BBChar*)s.utf16(), s.length());
}

// Converts a BBString to a QString
QString qStringFromBBString(BBString * s) {
	return QString::fromUtf16((const ushort*)s->buf, s->length);
}

// *********************************************

MaxQUrl * bmx_qt_qurl_create(BBString * url) {
	QUrl u(qStringFromBBString(url));
	return new MaxQUrl(u);
}

void bmx_qt_qurl_free(MaxQUrl * url) {
	delete url;
}

// *********************************************


MaxQRect * bmx_qt_qrect_create(int x, int y, int w, int h) {
	QRect r(x, y, w, h);
	return new MaxQRect(r);
}

void bmx_qt_qrect_free(MaxQRect * rect) {
	delete rect;
}

void bmx_qt_qrect_adjust(MaxQRect * rect, int dx1, int dy1, int dx2, int dy2) {
	rect->Rect().adjust(dx1, dy1, dx2, dy2);
}

MaxQRect * bmx_qt_qrect_adjusted(MaxQRect * rect, int dx1, int dy1, int dx2, int dy2) {
	return new MaxQRect(rect->Rect().adjusted(dx1, dy1, dx2, dy2));
}

int bmx_qt_qrect_bottom(MaxQRect * rect) {
	return rect->Rect().bottom();
}

void bmx_qt_qrect_bottomleft(MaxQRect * rect, int * x, int * y) {
	QPoint p(rect->Rect().bottomLeft());
	*x = p.x();
	*y = p.y();
}

void bmx_qt_qrect_bottomright(MaxQRect * rect, int * x, int * y) {
	QPoint p(rect->Rect().bottomRight());
	*x = p.x();
	*y = p.y();
}

void bmx_qt_qrect_center(MaxQRect * rect, int * x, int * y) {
	QPoint p(rect->Rect().center());
	*x = p.x();
	*y = p.y();
}

int bmx_qt_qrect_contains(MaxQRect * rect, int x, int y, int proper) {
	return static_cast<int>(rect->Rect().contains(x, y, static_cast<bool>(proper)));
}

int bmx_qt_qrect_containsrect(MaxQRect * rect, MaxQRect * rectangle, int proper) {
	return static_cast<int>(rect->Rect().contains(rectangle->Rect(), static_cast<bool>(proper)));
}

void bmx_qt_qrect_getcoords(MaxQRect * rect, int * x1, int * y1, int * x2, int * y2) {
	rect->Rect().getCoords(x1, y1, x2, y2);
}

void bmx_qt_qrect_getrect(MaxQRect * rect, int * x, int * y, int * width, int * height) {
	rect->Rect().getRect(x, y, width, height);
}

int bmx_qt_qrect_height(MaxQRect * rect) {
	return rect->Rect().height();
}

MaxQRect * bmx_qt_qrect_intersected(MaxQRect * rect, MaxQRect * rectangle) {
	return new MaxQRect(rect->Rect().intersected(rectangle->Rect()));
}

int bmx_qt_qrect_intersects(MaxQRect * rect, MaxQRect * rectangle) {
	return static_cast<int>(rect->Rect().intersects(rectangle->Rect()));
}

int bmx_qt_qrect_isempty(MaxQRect * rect) {
	return static_cast<int>(rect->Rect().isEmpty());
}

int bmx_qt_qrect_isnull(MaxQRect * rect) {
	return static_cast<int>(rect->Rect().isNull());
}

int bmx_qt_qrect_isvalid(MaxQRect * rect) {
	return static_cast<int>(rect->Rect().isValid());
}

int bmx_qt_qrect_left(MaxQRect * rect) {
	return rect->Rect().left();
}

void bmx_qt_qrect_movebottom(MaxQRect * rect, int y) {
	rect->Rect().moveBottom(y);
}

void bmx_qt_qrect_movebottomleft(MaxQRect * rect, int x, int y) {
	rect->Rect().moveBottomLeft(QPoint(x, y));
}

void bmx_qt_qrect_movebottomright(MaxQRect * rect, int x, int y) {
	rect->Rect().moveBottomRight(QPoint(x, y));
}

void bmx_qt_qrect_movecenter(MaxQRect * rect, int x, int y) {
	rect->Rect().moveCenter(QPoint(x, y));
}

void bmx_qt_qrect_moveleft(MaxQRect * rect, int x) {
	rect->Rect().moveLeft(x);
}

void bmx_qt_qrect_moveright(MaxQRect * rect, int x) {
	rect->Rect().moveRight(x);
}

void bmx_qt_qrect_moveto(MaxQRect * rect, int x, int y) {
	rect->Rect().moveTo(x, y);
}

void bmx_qt_qrect_movetop(MaxQRect * rect, int y) {
	rect->Rect().moveTop(y);
}

void bmx_qt_qrect_movetopleft(MaxQRect * rect, int x, int y) {
	rect->Rect().moveTopLeft(QPoint(x, y));
}

void bmx_qt_qrect_movetopright(MaxQRect * rect, int x, int y) {
	rect->Rect().moveTopRight(QPoint(x, y));
}

MaxQRect * bmx_qt_qrect_normalized(MaxQRect * rect) {
	return new MaxQRect(rect->Rect().normalized());
}

int bmx_qt_qrect_right(MaxQRect * rect) {
	return rect->Rect().right();
}

void bmx_qt_qrect_setbottom(MaxQRect * rect, int y) {
	rect->Rect().setBottom(y);
}

void bmx_qt_qrect_setbottomleft(MaxQRect * rect, int x, int y) {
	rect->Rect().setBottomLeft(QPoint(x, y));
}

void bmx_qt_qrect_setbottomright(MaxQRect * rect, int x, int y) {
	rect->Rect().setBottomRight(QPoint(x, y));
}

void bmx_qt_qrect_setcoords(MaxQRect * rect, int x1, int y1, int x2, int y2) {
	rect->Rect().setCoords(x1, y1, x2, y2);
}

void bmx_qt_qrect_setheight(MaxQRect * rect, int height) {
	rect->Rect().setHeight(height);
}

void bmx_qt_qrect_setleft(MaxQRect * rect, int x) {
	rect->Rect().setLeft(x);
}

void bmx_qt_qrect_setrect(MaxQRect * rect, int x, int y, int width, int height) {
	rect->Rect().setRect(x, y, width, height);
}

void bmx_qt_qrect_setright(MaxQRect * rect, int x) {
	rect->Rect().setRight(x);
}

void bmx_qt_qrect_setsize(MaxQRect * rect, int w, int h) {
	rect->Rect().setSize(QSize(w, h));
}

void bmx_qt_qrect_settop(MaxQRect * rect, int y) {
	rect->Rect().setTop(y);
}

void bmx_qt_qrect_settopleft(MaxQRect * rect, int x, int y) {
	rect->Rect().setTopLeft(QPoint(x, y));
}

void bmx_qt_qrect_settopright(MaxQRect * rect, int x, int y) {
	rect->Rect().setTopRight(QPoint(x, y));
}

void bmx_qt_qrect_setwidth(MaxQRect * rect, int width) {
	rect->Rect().setWidth(width);
}

void bmx_qt_qrect_setx(MaxQRect * rect, int x) {
	rect->Rect().setX(x);
}

void bmx_qt_qrect_sety(MaxQRect * rect, int y) {
	rect->Rect().setY(y);
}

void bmx_qt_qrect_size(MaxQRect * rect, int * w, int * h) {
	QSize s(rect->Rect().size());
	*w = s.width();
	*h = s.height();
}

int bmx_qt_qrect_top(MaxQRect * rect) {
	return rect->Rect().top();
}

void bmx_qt_qrect_topleft(MaxQRect * rect, int * x, int * y) {
	QPoint p(rect->Rect().topLeft());
	*x = p.x();
	*y = p.y();
}

void bmx_qt_qrect_topright(MaxQRect * rect, int * x, int * y) {
	QPoint p(rect->Rect().topRight());
	*x = p.x();
	*y = p.y();
}

void bmx_qt_qrect_translate(MaxQRect * rect, int dx, int dy) {
	rect->Rect().translate(dx, dy);
}

MaxQRect * bmx_qt_qrect_translated(MaxQRect * rect, int dx, int dy) {
	return new MaxQRect(rect->Rect().translated(dx, dy));
}

MaxQRect * bmx_qt_qrect_united(MaxQRect * rect, MaxQRect * rectangle) {
	return new MaxQRect(rect->Rect().united(rectangle->Rect()));
}

int bmx_qt_qrect_width(MaxQRect * rect) {
	return rect->Rect().width();
}

int bmx_qt_qrect_x(MaxQRect * rect) {
	return rect->Rect().x();
}

int bmx_qt_qrect_y(MaxQRect * rect) {
	return rect->Rect().y();
}

// *********************************************

Qt::WindowFlags bmx_qt_getwindowflags(int f) {
	Qt::WindowFlags flags;


	if (f & 0x00000001) flags |= Qt::Window;
	if (f & (0x00000002 | 0x00000001)) flags |= Qt::Dialog;
	if (f & (0x00000004 | 0x00000001)) flags |= Qt::Sheet;
	if (f & (0x00000006 | 0x00000001)) flags |= Qt::Drawer;
	if (f & (0x00000008 | 0x00000001)) flags |= Qt::Popup;
	if (f & (0x0000000a | 0x00000001)) flags |= Qt::Tool;
	if (f & (0x0000000c | 0x00000001)) flags |= Qt::ToolTip;
	if (f & (0x0000000e | 0x00000001)) flags |= Qt::SplashScreen;
	if (f & (0x00000010 | 0x00000001)) flags |= Qt::Desktop;
	if (f & 0x00000012) flags |= Qt::SubWindow;


	return flags;
}

Qt::Alignment bmx_qt_getalignment(int a) {
	Qt::Alignment align;

	if (a & 0x0001) align |= Qt::AlignLeft;
	if (a & 0x0002) align |= Qt::AlignRight;
	if (a & 0x0004) align |= Qt::AlignHCenter;
	if (a & 0x0008) align |= Qt::AlignJustify;
	if (a & 0x0020) align |= Qt::AlignTop;
	if (a & 0x0040) align |= Qt::AlignBottom;
	if (a & 0x0080) align |= Qt::AlignVCenter;
	if (a & (0x0004 | 0x0080)) align |= Qt::AlignCenter;
	if (a & 0x0010) align |= Qt::AlignAbsolute;
	
	return align;
}

Qt::FocusReason bmx_qt_getfocusreason(int r) {
	switch(r) {
		case 0:
			return Qt::MouseFocusReason;
		case 1:
			return Qt::TabFocusReason;
		case 2:
			return Qt::BacktabFocusReason;
		case 3:
			return Qt::ActiveWindowFocusReason;
		case 4:
			return Qt::PopupFocusReason;
		case 5:
			return Qt::ShortcutFocusReason;
		case 6:
			return Qt::MenuBarFocusReason;
		case 7:
			return Qt::OtherFocusReason;
	}
	
	return Qt::OtherFocusReason;
}

// *********************************************


// *********************************************

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"

