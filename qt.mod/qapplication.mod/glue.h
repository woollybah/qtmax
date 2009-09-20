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

#ifndef MAX_QT_QAPPLICATION
#define MAX_QT_QAPPLICATION

#include "../core.mod/glue.h"
#include "../qcoreapplication.mod/glue.h"
#include "../qsessionmanager.mod/glue.h"
#include "../qcursor.mod/glue.h"
#include "../qlocale.mod/glue.h"
#include "../qpalette.mod/glue.h"
#include "../qfont.mod/glue.h"
#include "../qfontmetrics.mod/glue.h"
#include "../qobject.mod/glue.h"
#include <QtGui>

class MaxQApplication;

extern "C" {

#include <blitz.h>

	void _qt_qapplication_QApplication__OnCommitDataRequest(BBObject * handle, MaxQSessionManager * manager);
	void _qt_qapplication_QApplication__OnFocusChanged(BBObject * handle, QWidget* old, QWidget * now);
	void _qt_qapplication_QApplication__OnFontDatabaseChanged(BBObject * handle);
	void _qt_qapplication_QApplication__OnLastWindowClosed(BBObject * handle);
	void _qt_qapplication_QApplication__OnSaveStateRequest(BBObject * handle, MaxQSessionManager * manager);

	QApplication * bmx_qt_qapplication_create(BBObject * handle);
	int bmx_qt_qapplication_exec();
	void bmx_qt_qapplication_aboutqt(QApplication * app);
	void bmx_qt_qapplication_closeallwindows(QApplication * app);
	void bmx_qt_qapplication_setstylesheet(QApplication * app, BBString * sheet);

	QWidget * bmx_qt_qapplication_activemodalwidget();
	QWidget * bmx_qt_qapplication_activepopupwidget();
	QWidget * bmx_qt_qapplication_activewindow();
	void bmx_qt_qapplication_alert(QWidget * widget, int msec);
	void bmx_qt_qapplication_beep();
	void bmx_qt_qapplication_changeoverridecursor(MaxQCursor * cursor);
	QClipboard * bmx_qt_qapplication_clipboard();
	int bmx_qt_qapplication_colorspec();
	int bmx_qt_qapplication_cursorflashtime();
	QDesktopWidget * bmx_qt_qapplication_desktop();
	int bmx_qt_qapplication_desktopsettingsaware();
	int bmx_qt_qapplication_doubleclickinterval();
	QWidget * bmx_qt_qapplication_focuswidget();
	MaxQFont * bmx_qt_qapplication_font();
	MaxQFont * bmx_qt_qapplication_fontwidget(QWidget * widget);
	MaxQFont * bmx_qt_qapplication_fontname(BBString * className);
	MaxQFontMetrics * bmx_qt_qapplication_fontmetrics();
	void bmx_qt_qapplication_globalstrut(int * w, int * h);
	int bmx_qt_qapplication_iseffectenabled(int effect);
	int bmx_qt_qapplication_islefttoright();
	int bmx_qt_qapplication_isrighttoleft();
	int bmx_qt_qapplication_keyboardinputdirection();
	int bmx_qt_qapplication_keyboardinputinterval();
	MaxQLocale * bmx_qt_qapplication_keyboardinputlocale();
	int bmx_qt_qapplication_keyboardmodifiers();
	int bmx_qt_qapplication_layoutdirection();
	int bmx_qt_qapplication_mousebuttons();
	MaxQCursor * bmx_qt_qapplication_overridecursor();
	int bmx_qt_qapplication_quitonlastwindowclosed();
	void bmx_qt_qapplication_restoreoverridecursor();
	void bmx_qt_qapplication_setactivewindow(QWidget * widget);
	void bmx_qt_qapplication_setcolorspec(int spec);
	void bmx_qt_qapplication_setcursorflashtime(int time);
	void bmx_qt_qapplication_setdesktopsettingsaware(int on);
	void bmx_qt_qapplication_setdoubleclickinterval(int interval);
	void bmx_qt_qapplication_seteffectenabled(int effect, int enable);
	void bmx_qt_qapplication_setfont(MaxQFont * font, BBString * className);
	void bmx_qt_qapplication_setglobalstrut(int w, int h);
	void bmx_qt_qapplication_setgraphicssystem(BBString * system);
	void bmx_qt_qapplication_setkeyboardinputinterval(int interval);
	void bmx_qt_qapplication_setlayoutdirection(int direction);
	void bmx_qt_qapplication_setoverridecursor(MaxQCursor * cursor);
	void bmx_qt_qapplication_setpalette(MaxQPalette * palette, BBString * className);
	void bmx_qt_qapplication_setquitonlastwindowclosed(int quit);
	void bmx_qt_qapplication_setstartdragdistance(int l);
	void bmx_qt_qapplication_setstartdragtime(int ms);
	
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQApplication : public QApplication
{

	Q_OBJECT

public:
	MaxQApplication(BBObject * handle, int & argc, char ** argv);
	~MaxQApplication();

private:
	BBObject * maxHandle;

private slots:
	void onCommitDataRequest(QSessionManager & manager);
	void onFocusChanged(QWidget * old, QWidget * now);
	void onFontDatabaseChanged();
	void onLastWindowClosed();
	void onSaveStateRequest(QSessionManager & manager);
	void onAboutToQuit(); // from QCoreApplication

protected:
	void timerEvent(QTimerEvent * event);
};


#endif
