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

#ifndef MAX_QT_QTABBAR
#define MAX_QT_QTABBAR

#include "../core.mod/glue.h"
#include "../qicon.mod/glue.h"
#include "../qcolor.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QTabBar>

class MaxQTabBar;

extern "C" {

#include <blitz.h>

	void _qt_qtabbar_QTabBar__OnCurrentChanged(BBObject * handle, int index);
	void _qt_qtabbar_QTabBar__OnTabCloseRequested(BBObject * handle, int index);
	void _qt_qtabbar_QTabBar__OnTabMoved(BBObject * handle, int from, int to);

	QTabBar * bmx_qt_qtabbar_create(BBObject * handle, QWidget * parent);
	int bmx_qt_qtabbar_addtab(QTabBar * tb, BBString * text, MaxQIcon * icon);
	int bmx_qt_qtabbar_count(QTabBar * tb);
	int bmx_qt_qtabbar_currentindex(QTabBar * tb);
	int bmx_qt_qtabbar_documentmode(QTabBar * tb);
	int bmx_qt_qtabbar_drawbase(QTabBar * tb);
	int bmx_qt_qtabbar_elidemode(QTabBar * tb);
	int bmx_qt_qtabbar_expanding(QTabBar * tb);
	void bmx_qt_qtabbar_iconsize(QTabBar * tb, int * w, int * h);
	int bmx_qt_qtabbar_inserttab(QTabBar * tb, int index, BBString * text, MaxQIcon * icon);
	int bmx_qt_qtabbar_ismovable(QTabBar * tb);
	int bmx_qt_qtabbar_istabenabled(QTabBar * tb, int index);
	void bmx_qt_qtabbar_movetab(QTabBar * tb, int _from, int _to);
	void bmx_qt_qtabbar_removetab(QTabBar * tb, int index);
	int bmx_qt_qtabbar_selectionbehavioronremove(QTabBar * tb);
	void bmx_qt_qtabbar_setdocumentmode(QTabBar * tb, int set);
	void bmx_qt_qtabbar_setdrawbase(QTabBar * tb, int drawTheBase);
	void bmx_qt_qtabbar_setelidemode(QTabBar * tb, int _mode);
	void bmx_qt_qtabbar_setexpanding(QTabBar * tb, int enabled);
	void bmx_qt_qtabbar_seticonsize(QTabBar * tb, int w, int h);
	void bmx_qt_qtabbar_setmovable(QTabBar * tb, int movable);
	void bmx_qt_qtabbar_setselectionbehaviouronremove(QTabBar * tb, int behavior);
	void bmx_qt_qtabbar_setshape(QTabBar * tb, int shape);
	void bmx_qt_qtabbar_settabbutton(QTabBar * tb, int index, int position, QWidget * widget);
	void bmx_qt_qtabbar_settabdata(QTabBar * tb, int index, BBInt64 data);
	void bmx_qt_qtabbar_settabenabled(QTabBar * tb, int index, int enabled);
	void bmx_qt_qtabbar_settabicon(QTabBar * tb, int index, MaxQIcon * icon);
	void bmx_qt_qtabbar_settabtext(QTabBar * tb, int index, BBString * text);
	void bmx_qt_qtabbar_settabtextcolor(QTabBar * tb, int index, MaxQColor * color);
	void bmx_qt_qtabbar_settabtooltip(QTabBar * tb, int index, BBString * tip);
	void bmx_qt_qtabbar_settabwhatsthis(QTabBar * tb, int index, BBString * text);
	void bmx_qt_qtabbar_settabsclosable(QTabBar * tb, int closable);
	void bmx_qt_qtabbar_setusesscrollbuttons(QTabBar * tb, int useButtons);
	int bmx_qt_qtabbar_shape(QTabBar * tb);
	int bmx_qt_qtabbar_tabat(QTabBar * tb, int x, int y);
	QWidget * bmx_qt_qtabbar_tabbutton(QTabBar * tb, int index, int position);
	void bmx_qt_qtabbar_tabdata(QTabBar * tb, int index, BBInt64 * id);
	MaxQIcon * bmx_qt_qtabbar_tabicon(QTabBar * tb, int index);
	MaxQRect * bmx_qt_qtabbar_tabrect(QTabBar * tb, int index);
	BBString * bmx_qt_qtabbar_tabtext(QTabBar * tb, int index);
	MaxQColor * bmx_qt_qtabbar_tabtextcolor(QTabBar * tb, int index);
	BBString * bmx_qt_qtabbar_tabtooltip(QTabBar * tb, int index);
	BBString * bmx_qt_qtabbar_tabwhatsthis(QTabBar * tb, int index);
	int bmx_qt_qtabbar_tabsclosable(QTabBar * tb);
	int bmx_qt_qtabbar_usesscrollbuttons(QTabBar * tb);

	void bmx_qt_qtabbar_setcurrentindex(QTabBar * tb, int index);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQTabBar : public QTabBar
{
	Q_OBJECT
	
public:
	MaxQTabBar(BBObject * handle, QWidget * parent);
	~MaxQTabBar();

private:
	BBObject * maxHandle;

private slots:
	void onCurrentChanged(int index);
	void onTabCloseRequested(int index);
	void onTabMoved(int from, int to);
	void onCustomContextMenuRequested(const QPoint & pos);
};

#endif
