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

MaxQApplication::MaxQApplication(BBObject * handle, int & argc, char ** argv)
	: maxHandle(handle), QApplication(argc, argv)
{
	qbind(this, handle);
}

MaxQApplication::~MaxQApplication()
{
	qunbind(this);
}

void MaxQApplication::onCommitDataRequest(QSessionManager & manager) {
	_qt_qapplication_QApplication__OnCommitDataRequest(maxHandle, new MaxQSessionManager(manager));
}

void MaxQApplication::onFocusChanged(QWidget * old, QWidget * now) {
	_qt_qapplication_QApplication__OnFocusChanged(maxHandle, old, now);
}

void MaxQApplication::onFontDatabaseChanged() {
	_qt_qapplication_QApplication__OnFontDatabaseChanged(maxHandle);
}

void MaxQApplication::onLastWindowClosed() {
	_qt_qapplication_QApplication__OnLastWindowClosed(maxHandle);
}

void MaxQApplication::onSaveStateRequest(QSessionManager & manager) {
	_qt_qapplication_QApplication__OnSaveStateRequest(maxHandle, new MaxQSessionManager(manager));
}

void MaxQApplication::onAboutToQuit() {
	_qt_qcoreapplication_QCoreApplication__OnAboutToQuit(maxHandle);
}

void MaxQApplication::timerEvent(QTimerEvent * event) {
	_qt_qobject_QObject__timerEvent(maxHandle, event);
}


// *********************************************

QApplication * bmx_qt_qapplication_create(BBObject * handle) {

	static int i = 0;
	static const char *const empty = "";


	MaxQApplication * app = new MaxQApplication(handle, i, (char **)&empty);
	
	// accepts all strings from Max as utf-8
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
	
	return app;
}

int bmx_qt_qapplication_exec() {
	return QApplication::exec();
}

void bmx_qt_qapplication_aboutqt(QApplication * app) {
	app->aboutQt();
}

void bmx_qt_qapplication_closeallwindows(QApplication * app) {
	app->closeAllWindows();
}

void bmx_qt_qapplication_setstylesheet(QApplication * app, BBString * sheet) {
	app->setStyleSheet(qStringFromBBString(sheet));
}

QWidget * bmx_qt_qapplication_activemodalwidget() {
	return QApplication::activeModalWidget();
}

QWidget * bmx_qt_qapplication_activepopupwidget() {
	return QApplication::activePopupWidget();
}

QWidget * bmx_qt_qapplication_activewindow() {
	return QApplication::activeWindow();
}

void bmx_qt_qapplication_alert(QWidget * widget, int msec) {
	QApplication::alert(widget, msec);
}

void bmx_qt_qapplication_beep() {
	QApplication::beep();
}

void bmx_qt_qapplication_changeoverridecursor(MaxQCursor * cursor) {
	QApplication::changeOverrideCursor(cursor->Cursor());
}

QClipboard * bmx_qt_qapplication_clipboard() {
	QClipboard * clipboard = QApplication::clipboard();
	MaxQClipboard::link(clipboard);
	return clipboard;
}

int bmx_qt_qapplication_colorspec() {
	return QApplication::colorSpec();
}

int bmx_qt_qapplication_cursorflashtime() {
	return QApplication::cursorFlashTime();
}

QDesktopWidget * bmx_qt_qapplication_desktop() {
	QDesktopWidget * widget = QApplication::desktop();
	MaxQDesktopWidget::link(widget);
	return widget;
}

int bmx_qt_qapplication_desktopsettingsaware() {
	return static_cast<int>(QApplication::desktopSettingsAware());
}

int bmx_qt_qapplication_doubleclickinterval() {
	return QApplication::doubleClickInterval();
}

QWidget * bmx_qt_qapplication_focuswidget() {
	return QApplication::focusWidget();
}

MaxQFont * bmx_qt_qapplication_font() {
	return new MaxQFont(QApplication::font());
}

MaxQFont * bmx_qt_qapplication_fontwidget(QWidget * widget) {
	return new MaxQFont(QApplication::font(widget));
}

MaxQFont * bmx_qt_qapplication_fontname(BBString * className) {
	char * f = bbStringToCString(className);
	MaxQFont * font = new MaxQFont(QApplication::font(f));
	bbMemFree(f);
	return font;
}

MaxQFontMetrics * bmx_qt_qapplication_fontmetrics() {
	return new MaxQFontMetrics(QApplication::fontMetrics());
}

void bmx_qt_qapplication_globalstrut(int * w, int * h) {
	QSize s(QApplication::globalStrut());
	*w = s.width();
	*h = s.height();
}

int bmx_qt_qapplication_iseffectenabled(int effect) {
	return static_cast<int>(QApplication::isEffectEnabled((Qt::UIEffect)effect));
}

int bmx_qt_qapplication_islefttoright() {
	return static_cast<int>(QApplication::isLeftToRight());
}

int bmx_qt_qapplication_isrighttoleft() {
	return static_cast<int>(QApplication::isRightToLeft());
}

int bmx_qt_qapplication_keyboardinputdirection() {
	return QApplication::keyboardInputDirection();
}

int bmx_qt_qapplication_keyboardinputinterval() {
	return QApplication::keyboardInputInterval();
}

MaxQLocale * bmx_qt_qapplication_keyboardinputlocale() {
	return new MaxQLocale(QApplication::keyboardInputLocale());
}

int bmx_qt_qapplication_keyboardmodifiers() {
	return QApplication::keyboardModifiers();
}

int bmx_qt_qapplication_layoutdirection() {
	return QApplication::layoutDirection();
}

int bmx_qt_qapplication_mousebuttons() {
	return QApplication::mouseButtons();
}

MaxQCursor * bmx_qt_qapplication_overridecursor() {
	QCursor * c = QApplication::overrideCursor();
	if (c) {
		return new MaxQCursor(*c);
	} else {
		return 0;
	}
}

int bmx_qt_qapplication_quitonlastwindowclosed() {
	return static_cast<int>(QApplication::quitOnLastWindowClosed());
}

void bmx_qt_qapplication_restoreoverridecursor() {
	QApplication::restoreOverrideCursor();
}

void bmx_qt_qapplication_setactivewindow(QWidget * widget) {
	QApplication::setActiveWindow(widget);
}

void bmx_qt_qapplication_setcolorspec(int spec) {
	QApplication::setColorSpec(spec);
}

void bmx_qt_qapplication_setcursorflashtime(int time) {
	QApplication::setCursorFlashTime(time);
}

void bmx_qt_qapplication_setdesktopsettingsaware(int on) {
	QApplication::setDesktopSettingsAware(static_cast<bool>(on));
}

void bmx_qt_qapplication_setdoubleclickinterval(int interval) {
	QApplication::setDoubleClickInterval(interval);
}

void bmx_qt_qapplication_seteffectenabled(int effect, int enable) {
	QApplication::setEffectEnabled((Qt::UIEffect)effect, static_cast<bool>(enable));
}

void bmx_qt_qapplication_setfont(MaxQFont * font, BBString * className) {
	char * name = 0;
	if (className != &bbEmptyString) {
		name = bbStringToCString(className);
	}
	QApplication::setFont(font->Font(), name);
	if (name) bbMemFree(name);
}

void bmx_qt_qapplication_setglobalstrut(int w, int h) {
	QApplication::setGlobalStrut(QSize(w, h));
}

void bmx_qt_qapplication_setgraphicssystem(BBString * system) {
	QApplication::setGraphicsSystem(qStringFromBBString(system));
}

void bmx_qt_qapplication_setkeyboardinputinterval(int interval) {
	QApplication::setKeyboardInputInterval(interval);
}

void bmx_qt_qapplication_setlayoutdirection(int direction) {
	QApplication::setLayoutDirection((Qt::LayoutDirection)direction);
}

void bmx_qt_qapplication_setoverridecursor(MaxQCursor * cursor) {
	QApplication::setOverrideCursor(cursor->Cursor());
}

void bmx_qt_qapplication_setpalette(MaxQPalette * palette, BBString * className) {
	char * n = 0;
	if (className != &bbEmptyString) {
		n = bbStringToCString(className);
	}
	QApplication::setPalette(palette->Palette(), n);
	if (n) bbMemFree(n);
}

void bmx_qt_qapplication_setquitonlastwindowclosed(int quit) {
	QApplication::setQuitOnLastWindowClosed(static_cast<bool>(quit));
}

void bmx_qt_qapplication_setstartdragdistance(int l) {
	QApplication::setStartDragDistance(l);
}

void bmx_qt_qapplication_setstartdragtime(int ms) {
	QApplication::setStartDragTime(ms);
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
