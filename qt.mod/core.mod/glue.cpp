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

// ---------------------------------------------------------------------------------------

MaxQTime::MaxQTime(const QTime & t)
	: time(t)
{
}

QTime & MaxQTime::Time() {
	return time;
}

// ---------------------------------------------------------------------------------------

MaxQRectF::MaxQRectF(const QRectF & r)
	: rect(r)
{
}

QRectF & MaxQRectF::Rect() {
	return rect;
}

void MaxQRectF::SetRect(const QRectF & r) {
	rect = r;
}

// ---------------------------------------------------------------------------------------

MaxQObjectWrapper::MaxQObjectWrapper(BBObject * handle, QObject * o)
	: maxHandle(handle), obj(o)
{
	qbind(obj, handle);
	connect(obj, SIGNAL(destroyed(QObject *)), SLOT(onDestroy(QObject *)));
}

MaxQObjectWrapper::MaxQObjectWrapper(QObject * o)
	: obj(o)
{
	// we assume that this object will be qbind() elsewhere...
	
	connect(obj, SIGNAL(destroyed(QObject *)), SLOT(onDestroy(QObject *)));
}

MaxQObjectWrapper::~MaxQObjectWrapper()
{
}

void MaxQObjectWrapper::onDestroy(QObject * obj) {
	qunbind(obj);
	delete this;
}

// ---------------------------------------------------------------------------------------

MaxQDate::MaxQDate(const QDate & d)
	: date(d)
{
}

QDate & MaxQDate::Date() {
	return date;
}

// ---------------------------------------------------------------------------------------

MaxQDateTime::MaxQDateTime(const QDateTime & d)
	: datetime(d)
{
}

QDateTime & MaxQDateTime::DateTime() {
	return datetime;
}

// ---------------------------------------------------------------------------------------

MaxQLineF::MaxQLineF(const QLineF & l)
	: line(l)
{
}

QLineF & MaxQLineF::Line() {
	return line;
}

// ---------------------------------------------------------------------------------------

MaxQVariant::MaxQVariant(const QVariant & v)
	: variant(v)
{
}

QVariant & MaxQVariant::Variant() {
	return variant;
}

// *********************************************

typedef std::map<QObject*, BBObject*> QObjectPeerMap;

static QObjectPeerMap qObjectPeerMap;

void qbind( QObject *obj, BBObject *peer ) {
	if( !obj || peer==&bbNullObject ) return;
	qObjectPeerMap.insert( std::make_pair( obj,peer ) );
	BBRETAIN( peer );
}

BBObject *qfind( QObject *obj ){
	if( !obj ) return &bbNullObject;
	QObjectPeerMap::iterator it = qObjectPeerMap.find( obj );
	if( it != qObjectPeerMap.end() ) return it->second;
	return &bbNullObject;
}

void qunbind(QObject *obj) {
	BBObject * peer = qfind(obj);
	if (peer != &bbNullObject) {
		qObjectPeerMap.erase(obj);
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

QVector<qreal> qRealVectorFromBBDoubleArray(BBArray * p) {
	int n=p->scales[0];
	QVector<qreal> vec(n);

	double *s=(double*)BBARRAYDATA( p,p->dims );
	
	for( int i=0;i<n;++i ){
		vec[i] = s[i];
	}
	
	return vec;
}

BBArray * bbDoubleArrayFromQRealVector(QVector<qreal> vec) {
	int n = vec.count();
	BBArray *p=bbArrayNew1D( "d",n );
	double *s=(double*)BBARRAYDATA( p,p->dims );
	for( int i=0;i<n;++i ){
		s[i] = vec[i];
	}
	return p;
}

BBArray * bbStringArrayFromQStringList(QStringList list) {
	int n = list.count();
	BBArray *p=bbArrayNew1D( "$",n );
	BBString **s=(BBString**)BBARRAYDATA( p,p->dims );
	for( int i=0;i<n;++i ){
		s[i]=bbStringFromQString( list[i] );
		BBRETAIN( s[i] );
	}
	return p;	
}

BBArray * bbIntArrayFromQIntList(QList<int> list) {
	int n = list.count();
	BBArray *p=bbArrayNew1D( "i",n );
	int *s=(int*)BBARRAYDATA( p,p->dims );
	for( int i=0;i<n;++i ){
		s[i] = list[i];
	}
	return p;
}

// *********************************************

MaxQUrl * bmx_qt_qurl_create(BBString * url) {
	QUrl u(qStringFromBBString(url));
	return new MaxQUrl(u);
}

void bmx_qt_qurl_free(MaxQUrl * url) {
	delete url;
}

BBString * bmx_qt_qurl_tostring(MaxQUrl * url) {
	return bbStringFromQString(url->Url().toString());
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
	if (f & 0x00000100) flags |= Qt::MSWindowsFixedSizeDialogHint;
	if (f & 0x00000200) flags |= Qt::MSWindowsOwnDC;
	if (f & 0x00000400) flags |= Qt::X11BypassWindowManagerHint;
	if (f & 0x00000800) flags |= Qt::FramelessWindowHint;
	if (f & 0x02000000) flags |= Qt::CustomizeWindowHint;
	if (f & 0x00001000) flags |= Qt::WindowTitleHint;
	if (f & 0x00002000) flags |= Qt::WindowSystemMenuHint;
	if (f & 0x00004000) flags |= Qt::WindowMinimizeButtonHint;
	if (f & 0x00008000) flags |= Qt::WindowMaximizeButtonHint;
	if (f & (0x00004000 | 0x00008000)) flags |= Qt::WindowMinMaxButtonsHint;
	if (f & 0x08000000) flags |= Qt::WindowCloseButtonHint;
	if (f & 0x00010000) flags |= Qt::WindowContextHelpButtonHint;
	if (f & 0x10000000) flags |= Qt::MacWindowToolBarButtonHint;
	if (f & 0x20000000) flags |= Qt::BypassGraphicsProxyWidget;
	if (f & 0x00020000) flags |= Qt::WindowShadeButtonHint;
	if (f & 0x00040000) flags |= Qt::WindowStaysOnTopHint;
	if (f & 0x04000000) flags |= Qt::WindowStaysOnBottomHint;
	if (f & 0x00080000) flags |= Qt::WindowOkButtonHint;
	if (f & 0x00100000) flags |= Qt::WindowCancelButtonHint;
	if (f & 0x000000ff) flags |= Qt::WindowType_Mask;
	
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

Qt::TextInteractionFlags bmx_qt_inttotextinteractionflags(int f) {
	Qt::TextInteractionFlags flags;
	
	if (f & 0x0001) flags |= Qt::TextSelectableByMouse;
	if (f & 0x0002) flags |= Qt::TextSelectableByKeyboard;
	if (f & 0x0004) flags |= Qt::LinksAccessibleByMouse;
	if (f & 0x0008) flags |= Qt::LinksAccessibleByKeyboard;
	if (f & 0x0010) flags |= Qt::TextEditable;
	if (f & (0x0001 | 0x0002 | 0x0010)) flags |= Qt::TextEditorInteraction;
	if (f & (0x0001 | 0x0004 | 0x0008)) flags |= Qt::TextBrowserInteraction;
	
	return flags;
}

Qt::TextFormat bmx_qt_inttotextformat(int f) {
	switch(f) {
		case 0:
			return Qt::PlainText;
		case 1:
			return Qt::RichText;
		case 2:
			return Qt::AutoText;
		case 3:
			return Qt::LogText;
	}
	
	return Qt::PlainText;
}

Qt::Orientation bmx_qt_getorientation(int o) {

	switch(o) {
		case 1:
			return Qt::Horizontal;
		case 2:
			return Qt::Vertical;
	}
	
	return Qt::Horizontal;
}

// *********************************************

void bmx_qt_qevent_accept(QEvent * event) {
	event->accept();
}

void bmx_qt_qevent_ignore(QEvent * event) {
	event->ignore();
}

int bmx_qt_qevent_isaccepted(QEvent * event) {
	return static_cast<int>(event->isAccepted());
}

void bmx_qt_qevent_setaccepted(QEvent * event, int accepted) {
	event->setAccepted(accepted);
}

int bmx_qt_qevent_spontaneous(QEvent * event) {
	return static_cast<int>(event->spontaneous());
}

int bmx_qt_qevent_gettype(QEvent * event) {
	return event->type();
}


// *********************************************

int bmx_qt_qtime_elapsed(MaxQTime * time) {
	return time->Time().elapsed();
}

int bmx_qt_qtime_hour(MaxQTime * time) {
	return time->Time().hour();
}

int bmx_qt_qtime_isnull(MaxQTime * time) {
	return static_cast<int>(time->Time().isNull());
}

int bmx_qt_qtime_isvalid(MaxQTime * time) {
	return static_cast<int>(time->Time().isValid());
}

int bmx_qt_qtime_minute(MaxQTime * time) {
	return time->Time().minute();
}

int bmx_qt_qtime_msec(MaxQTime * time) {
	return time->Time().msec();
}

int bmx_qt_qtime_msecsto(MaxQTime * time, MaxQTime * t) {
	return time->Time().msecsTo(t->Time());
}

void bmx_qt_qtime_restart(MaxQTime * time) {
	time->Time().restart();
}

int bmx_qt_qtime_second(MaxQTime * time) {
	return time->Time().second();
}

int bmx_qt_qtime_secsto(MaxQTime * time, MaxQTime * t) {
	return time->Time().secsTo(t->Time());
}

int bmx_qt_qtime_sethms(MaxQTime * time, int h, int m, int s, int ms) {
	return static_cast<int>(time->Time().setHMS(h, m, s, ms));
}

void bmx_qt_qtime_start(MaxQTime * time) {
	time->Time().start();
}

MaxQTime * bmx_qt_qtime_currenttime() {
	return new MaxQTime(QTime::currentTime());
}

void bmx_qt_qtime_free(MaxQTime * time) {
	delete time;
}


// *********************************************

MaxQRectF * bmx_qt_qrectf_create(double x, double y, double w, double h) {
	QRectF r(x, y, w, h);
	return new MaxQRectF(r);
}

void bmx_qt_qrectf_free(MaxQRectF * rect) {
	delete rect;
}

void bmx_qt_qrectf_adjust(MaxQRectF * rect, double dx1, double dy1, double dx2, double dy2) {
	rect->Rect().adjust(dx1, dy1, dx2, dy2);
}

MaxQRectF * bmx_qt_qrectf_adjusted(MaxQRectF * rect, double dx1, double dy1, double dx2, double dy2) {
	return new MaxQRectF(rect->Rect().adjusted(dx1, dy1, dx2, dy2));
}

double bmx_qt_qrectf_bottom(MaxQRectF * rect) {
	return rect->Rect().bottom();
}

void bmx_qt_qrectf_bottomleft(MaxQRectF * rect, double * x, double * y) {
	QPointF p(rect->Rect().bottomLeft());
	*x = p.x();
	*y = p.y();
}

void bmx_qt_qrectf_bottomright(MaxQRectF * rect, double * x, double * y) {
	QPointF p(rect->Rect().bottomRight());
	*x = p.x();
	*y = p.y();
}

void bmx_qt_qrectf_center(MaxQRectF * rect, double * x, double * y) {
	QPointF p(rect->Rect().center());
	*x = p.x();
	*y = p.y();
}

int bmx_qt_qrectf_contains(MaxQRectF * rect, double x, double y) {
	return static_cast<int>(rect->Rect().contains(x, y));
}

int bmx_qt_qrectf_containsrect(MaxQRectF * rect, MaxQRectF * rectangle) {
	return static_cast<int>(rect->Rect().contains(rectangle->Rect()));
}

void bmx_qt_qrectf_getcoords(MaxQRectF * rect, double * x1, double * y1, double * x2, double * y2) {
	rect->Rect().getCoords(x1, y1, x2, y2);
}

void bmx_qt_qrectf_getrect(MaxQRectF * rect, double * x, double * y, double * width, double * height) {
	rect->Rect().getRect(x, y, width, height);
}

double bmx_qt_qrectf_height(MaxQRectF * rect) {
	return rect->Rect().height();
}

MaxQRectF * bmx_qt_qrectf_intersected(MaxQRectF * rect, MaxQRectF * rectangle) {
	return new MaxQRectF(rect->Rect().intersected(rectangle->Rect()));
}

int bmx_qt_qrectf_intersects(MaxQRectF * rect, MaxQRectF * rectangle) {
	return static_cast<int>(rect->Rect().intersects(rectangle->Rect()));
}

int bmx_qt_qrectf_isempty(MaxQRectF * rect) {
	return static_cast<int>(rect->Rect().isEmpty());
}

int bmx_qt_qrectf_isnull(MaxQRectF * rect) {
	return static_cast<int>(rect->Rect().isNull());
}

int bmx_qt_qrectf_isvalid(MaxQRectF * rect) {
	return static_cast<int>(rect->Rect().isValid());
}

double bmx_qt_qrectf_left(MaxQRectF * rect) {
	return rect->Rect().left();
}

void bmx_qt_qrectf_movebottom(MaxQRectF * rect, double y) {
	rect->Rect().moveBottom(y);
}

void bmx_qt_qrectf_movebottomleft(MaxQRectF * rect, double x, double y) {
	rect->Rect().moveBottomLeft(QPointF(x, y));
}

void bmx_qt_qrectf_movebottomright(MaxQRectF * rect, double x, double y) {
	rect->Rect().moveBottomRight(QPointF(x, y));
}

void bmx_qt_qrectf_movecenter(MaxQRectF * rect, double x, double y) {
	rect->Rect().moveCenter(QPointF(x, y));
}

void bmx_qt_qrectf_moveleft(MaxQRectF * rect, double x) {
	rect->Rect().moveLeft(x);
}

void bmx_qt_qrectf_moveright(MaxQRectF * rect, double x) {
	rect->Rect().moveRight(x);
}

void bmx_qt_qrectf_moveto(MaxQRectF * rect, double x, double y) {
	rect->Rect().moveTo(x, y);
}

void bmx_qt_qrectf_movetop(MaxQRectF * rect, double y) {
	rect->Rect().moveTop(y);
}

void bmx_qt_qrectf_movetopleft(MaxQRectF * rect, double x, double y) {
	rect->Rect().moveTopLeft(QPointF(x, y));
}

void bmx_qt_qrectf_movetopright(MaxQRectF * rect, double x, double y) {
	rect->Rect().moveTopRight(QPointF(x, y));
}

MaxQRectF * bmx_qt_qrectf_normalized(MaxQRectF * rect) {
	return new MaxQRectF(rect->Rect().normalized());
}

double bmx_qt_qrectf_right(MaxQRectF * rect) {
	return rect->Rect().right();
}

void bmx_qt_qrectf_setbottom(MaxQRectF * rect, double y) {
	rect->Rect().setBottom(y);
}

void bmx_qt_qrectf_setbottomleft(MaxQRectF * rect, double x, double y) {
	rect->Rect().setBottomLeft(QPointF(x, y));
}

void bmx_qt_qrectf_setbottomright(MaxQRectF * rect, double x, double y) {
	rect->Rect().setBottomRight(QPointF(x, y));
}

void bmx_qt_qrectf_setcoords(MaxQRectF * rect, double x1, double y1, double x2, double y2) {
	rect->Rect().setCoords(x1, y1, x2, y2);
}

void bmx_qt_qrectf_setheight(MaxQRectF * rect, double height) {
	rect->Rect().setHeight(height);
}

void bmx_qt_qrectf_setleft(MaxQRectF * rect, double x) {
	rect->Rect().setLeft(x);
}

void bmx_qt_qrectf_setrect(MaxQRectF * rect, double x, double y, double width, double height) {
	rect->Rect().setRect(x, y, width, height);
}

void bmx_qt_qrectf_setright(MaxQRectF * rect, double x) {
	rect->Rect().setRight(x);
}

void bmx_qt_qrectf_setsize(MaxQRectF * rect, double w, double h) {
	rect->Rect().setSize(QSize(w, h));
}

void bmx_qt_qrectf_settop(MaxQRectF * rect, double y) {
	rect->Rect().setTop(y);
}

void bmx_qt_qrectf_settopleft(MaxQRectF * rect, double x, double y) {
	rect->Rect().setTopLeft(QPointF(x, y));
}

void bmx_qt_qrectf_settopright(MaxQRectF * rect, double x, double y) {
	rect->Rect().setTopRight(QPointF(x, y));
}

void bmx_qt_qrectf_setwidth(MaxQRectF * rect, double width) {
	rect->Rect().setWidth(width);
}

void bmx_qt_qrectf_setx(MaxQRectF * rect, double x) {
	rect->Rect().setX(x);
}

void bmx_qt_qrectf_sety(MaxQRectF * rect, double y) {
	rect->Rect().setY(y);
}

void bmx_qt_qrectf_size(MaxQRectF * rect, double * w, double * h) {
	QSizeF s(rect->Rect().size());
	*w = s.width();
	*h = s.height();
}

double bmx_qt_qrectf_top(MaxQRectF * rect) {
	return rect->Rect().top();
}

void bmx_qt_qrectf_topleft(MaxQRectF * rect, double * x, double * y) {
	QPointF p(rect->Rect().topLeft());
	*x = p.x();
	*y = p.y();
}

void bmx_qt_qrectf_topright(MaxQRectF * rect, double * x, double * y) {
	QPointF p(rect->Rect().topRight());
	*x = p.x();
	*y = p.y();
}

void bmx_qt_qrectf_translate(MaxQRectF * rect, double dx, double dy) {
	rect->Rect().translate(dx, dy);
}

MaxQRectF * bmx_qt_qrectf_translated(MaxQRectF * rect, double dx, double dy) {
	return new MaxQRectF(rect->Rect().translated(dx, dy));
}

MaxQRectF * bmx_qt_qrectf_united(MaxQRectF * rect, MaxQRectF * rectangle) {
	return new MaxQRectF(rect->Rect().united(rectangle->Rect()));
}

double bmx_qt_qrectf_width(MaxQRectF * rect) {
	return rect->Rect().width();
}

double bmx_qt_qrectf_x(MaxQRectF * rect) {
	return rect->Rect().x();
}

double bmx_qt_qrectf_y(MaxQRectF * rect) {
	return rect->Rect().y();
}

// *********************************************

void bmx_qt_qsize_scale(int * w, int * h, int scaleW, int scaleH, int _mode) {
	QSize s(*w, *h);
	s.scale(scaleW, scaleH, (Qt::AspectRatioMode)_mode);
	*w = s.width();
	*h = s.height();
}

// *********************************************

MaxQDate * bmx_qt_qdate_create(int y, int m, int d) {
	QDate date(y, m , d);
	return new MaxQDate(date);
}

void bmx_qt_qdate_free(MaxQDate * date) {
	delete date;
}

MaxQDate * bmx_qt_qdate_adddays(MaxQDate * date, int ndays) {
	return new MaxQDate(date->Date().addDays(ndays));
}

MaxQDate * bmx_qt_qdate_addmonths(MaxQDate * date, int nmonths) {
	return new MaxQDate(date->Date().addMonths(nmonths));
}

MaxQDate * bmx_qt_qdate_addYears(MaxQDate * date, int nyears) {
	return new MaxQDate(date->Date().addYears(nyears));
}

int bmx_qt_qdate_day(MaxQDate * date) {
	return date->Date().day();
}

int bmx_qt_qdate_dayofweek(MaxQDate * date) {
	return date->Date().dayOfWeek();
}

int bmx_qt_qdate_dayofyear(MaxQDate * date) {
	return date->Date().dayOfYear();
}

int bmx_qt_qdate_daysinmonth(MaxQDate * date) {
	return date->Date().daysInMonth();
}

int bmx_qt_qdate_daysinyear(MaxQDate * date) {
	return date->Date().daysInYear();
}

int bmx_qt_qdate_daysto(MaxQDate * date, MaxQDate * d) {
	return date->Date().daysTo(d->Date());
}

void bmx_qt_qdate_getdate(MaxQDate * date, int * year, int * _month, int * day) {
	date->Date().getDate(year, _month, day);
}

int bmx_qt_qdate_isnull(MaxQDate * date) {
	return static_cast<int>(date->Date().isNull());
}

int bmx_qt_qdate_isvalid(MaxQDate * date) {
	return static_cast<int>(date->Date().isValid());
}

int bmx_qt_qdate_month(MaxQDate * date) {
	return date->Date().month();
}

int bmx_qt_qdate_setdate(MaxQDate * date, int year, int _month, int day) {
	return date->Date().setDate(year, _month, day);
}

int bmx_qt_qdate_tojulianday(MaxQDate * date) {
	return date->Date().toJulianDay();
}

BBString * bmx_qt_qdate_toformatedstring(MaxQDate * date, BBString * format) {
	return bbStringFromQString(date->Date().toString(qStringFromBBString(format)));
}

BBString * bmx_qt_qdate_tostring(MaxQDate * date) {
	return bbStringFromQString(date->Date().toString());
}

int bmx_qt_qdate_weeknumber(MaxQDate * date, int * yearNumber) {
	return date->Date().weekNumber(yearNumber);
}

int bmx_qt_qdate_year(MaxQDate * date) {
	return date->Date().year();
}

// *********************************************

MaxQLineF * bmx_qt_qlinef_create(double x1, double y1, double x2, double y2) {
	return new MaxQLineF(QLineF(x1, y1, x2, y2));
}

void bmx_qt_qlinef_p1(MaxQLineF * line, double * x, double * y) {
	QPointF f = line->Line().p1();
	*x = f.x();
	*y = f.y();
}

void bmx_qt_qlinef_p2(MaxQLineF * line, double * x, double * y) {
	QPointF f = line->Line().p2();
	*x = f.x();
	*y = f.y();
}

double bmx_qt_qlinef_x1(MaxQLineF * line) {
	return line->Line().x1();
}

double bmx_qt_qlinef_y1(MaxQLineF * line) {
	return line->Line().y1();
}

double bmx_qt_qlinef_x2(MaxQLineF * line) {
	return line->Line().x2();
}

double bmx_qt_qlinef_y2(MaxQLineF * line) {
	return line->Line().y2();
}

double bmx_qt_qlinef_angle(MaxQLineF * line) {
	return line->Line().angle();
}

double bmx_qt_qlinef_angleTo(MaxQLineF * line, MaxQLineF * other) {
	return line->Line().angleTo(other->Line());
}

double bmx_qt_qlinef_dx(MaxQLineF * line) {
	return line->Line().dx();
}

double bmx_qt_qlinef_dy(MaxQLineF * line) {
	return line->Line().dy();
}

int bmx_qt_qlinef_intersect(MaxQLineF * line, MaxQLineF * other, double * x, double * y) {
	QPointF p;
	QLineF::IntersectType t = line->Line().intersect(other->Line(), &p);
	*x = p.x();
	*y = p.y();
	return t;
}

int bmx_qt_qlinef_isnull(MaxQLineF * line) {
	return static_cast<int>(line->Line().isNull());
}

double bmx_qt_qlinef_length(MaxQLineF * line) {
	return line->Line().length();
}

MaxQLineF * bmx_qt_qlinef_normalvector(MaxQLineF * line) {
	return new MaxQLineF(line->Line().normalVector());
}

void bmx_qt_qlinef_pointat(MaxQLineF * line, double t, double * x, double * y) {
	QPointF p(line->Line().pointAt(t));
	*x = p.x();
	*y = p.y();
}

void bmx_qt_qlinef_setp1(MaxQLineF * line, double x, double y) {
	line->Line().setP1(QPointF(x, y));
}

void bmx_qt_qlinef_setp2(MaxQLineF * line, double x, double y) {
	line->Line().setP2(QPointF(x, y));
}

void bmx_qt_qlinef_setangle(MaxQLineF * line, double angle) {
	line->Line().setAngle(angle);
}

void bmx_qt_qlinef_setlength(MaxQLineF * line, double length) {
	line->Line().setLength(length);
}

void bmx_qt_qlinef_setline(MaxQLineF * line, double x1, double y1, double x2, double y2) {
	line->Line().setLine(x1, y1, x2, y2);
}

void bmx_qt_qlinef_translate(MaxQLineF * line, double dx, double dy) {
	line->Line().translate(dx, dy);
}

MaxQLineF * bmx_qt_qlinef_translated(MaxQLineF * line, double dx, double dy) {
	return new MaxQLineF(line->Line().translated(dx, dy));
}

MaxQLineF * bmx_qt_qlinef_unitvector(MaxQLineF * line) {
	return new MaxQLineF(line->Line().unitVector());
}



// *********************************************

int bmx_qt_qchar_category(int c) {
	return QChar(c).category();
}

// *********************************************

void bmx_qt_variant_free(MaxQVariant * variant) {
	delete variant;
}

MaxQVariant * bmx_qt_qintvariant_create(int value) {
	return new MaxQVariant(QVariant(value));
}

int bmx_qt_qintvariant_value(MaxQVariant * variant) {
	return variant->Variant().toInt();
}

MaxQVariant * bmx_qt_qdoublevariant_create(double value) {
	return new MaxQVariant(QVariant(value));
}

double bmx_qt_qdoublevariant_value(MaxQVariant * variant) {
	return variant->Variant().toDouble();
}

MaxQVariant * bmx_qt_qfloatvariant_create(float value) {
	return new MaxQVariant(QVariant(value));
}

float bmx_qt_qfloatvariant_value(MaxQVariant * variant) {
	return variant->Variant().toFloat();
}

// *********************************************

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"

