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

#ifndef BMX_QT_QWIDGET
#define BMX_QT_QWIDGET

#include "../core.mod/glue.h"
#include "../qsizepolicy.mod/glue.h"
#include "../qfont.mod/glue.h"
#include "../qfontmetrics.mod/glue.h"
#include <QWidget>
#include <QPainter>
#include <QAction>

class MaxQWidget;
class MaxQAction;

extern "C" {

#include <blitz.h>

	void _qt_qwidget_QWidget__OnCustomContextMenuRequested(BBObject * handle, int x, int y);
	void _qt_qwidget_QWidget__OnPaintEvent(BBObject * handle, QPaintEvent * event, BBObject * painter);
	void _qt_qwidget_QWidget__OnMouseDoubleClickEvent(BBObject * handle, QMouseEvent * event);
	void _qt_qwidget_QWidget__OnMouseMoveEvent(BBObject * handle, QMouseEvent * event);
	void _qt_qwidget_QWidget__OnMousePressEvent(BBObject * handle, QMouseEvent * event);
	void _qt_qwidget_QWidget__OnMouseReleseEvent(BBObject * handle, QMouseEvent * event);

	void _qt_qwidget_QWidget__SizeHint(BBObject * handle, int * w, int * h);
	void _qt_qwidget_QWidget__MinimumSizeHint(BBObject * handle, int * w, int * h);

	void _qt_qwidget_QAction__OnChanged(BBObject * handle);
	void _qt_qwidget_QAction__OnHovered(BBObject * handle);
	void _qt_qwidget_QAction__OnToggled(BBObject * handle, int checked);
	void _qt_qwidget_QAction__OnTriggered(BBObject * handle, int checked);
	
	// used for on-the-fly QAction creation - linking to a BlitzMax object.
	BBObject * _qt_qwidget_QAction__create(QAction * action);

	BBObject * _qt_qpainter_QPainter__create(QPainter * painter);

	QWidget * bmx_qt_qwidget_create(BBObject * handle, QWidget * parent, int f);
	void bmx_qt_qwidget_hide(QWidget * widget);
	void bmx_qt_qwidget_show(QWidget * widget);
	void bmx_qt_qwidget_setlayout(QWidget * widget, QLayout * layout);
	void bmx_qt_qwidget_setwindowtitle(QWidget * widget, BBString * title);

	void bmx_qt_qwidget_showfullscreen(QWidget * widget);
	void bmx_qt_qwidget_showmaximized(QWidget * widget);
	void bmx_qt_qwidget_showminimized(QWidget * widget);
	void bmx_qt_qwidget_shownormal(QWidget * widget);
	void bmx_qt_qwidget_stackunder(QWidget * widget, QWidget * w);
	void bmx_qt_qwidget_setfixedsize(QWidget * widget, int w, int h);
	void bmx_qt_qwidget_setfixedwidth(QWidget * widget, int w);
	void bmx_qt_qwidget_setfocus(QWidget * widget, int reason);
	void bmx_qt_qwidget_close(QWidget * widget);
	void bmx_qt_qwidget_update(QWidget * widget);
	void bmx_qt_qwidget_raise(QWidget * widget);
	void bmx_qt_qwidget_repaint(QWidget * widget);
	void bmx_qt_qwidget_setdisabled(QWidget * widget, int disable);
	void bmx_qt_qwidget_setenabled(QWidget * widget, int value);
	void bmx_qt_qwidget_sethidden(QWidget * widget, int hidden);
	void bmx_qt_qwidget_setstylesheet(QWidget * widget, BBString * styleSheet);
	void bmx_qt_qwidget_setvisible(QWidget * widget, int visible);
	void bmx_qt_qwidget_setwindowmodified(QWidget * widget, int value);
	void bmx_qt_qwidget_resize(QWidget * widget, int w, int h);
	void bmx_qt_qwidget_addaction(QWidget * widget, QAction * action);
	void bmx_qt_qwidget_setcontextmenupolicy(QWidget * widget, int policy);
	MaxQRect * bmx_qt_qwidget_framegeometry(QWidget * widget);
	void bmx_qt_qwidget_framesize(QWidget * widget, int * w, int * h);
	MaxQRect * bmx_qt_qwidget_geometry(QWidget * widget);
	void bmx_qt_qwidget_setattribute(QWidget * widget, int attribute);
	void bmx_qt_qwidget_move(QWidget * widget, int x, int y);
	void bmx_qt_qwidget_settooltip(QWidget * widget, BBString * text);
	MaxQSizePolicy * bmx_qt_qwidget_sizepolicy(QWidget * widget);
	void bmx_qt_qwidget_setsizepolicyhv(QWidget * widget, int horizontalPolicy, int verticalPolicy);
	MaxQFont * bmx_qt_qwidget_font(QWidget * widget);
	MaxQFontMetrics * bmx_qt_qwidget_fontmetrics(QWidget * widget);
	void bmx_qt_qwidget_setfont(QWidget * widget, MaxQFont * font);

	int bmx_qt_qwidget_height(QWidget * widget);
	int bmx_qt_qwidget_width(QWidget * widget);

	QAction * bmx_qt_qaction_create(BBObject * handle, BBString * text, QObject * parent);
	void bmx_qt_qaction_setshortcut(QAction * handle, BBString * sequence);
	QActionGroup * bmx_qt_qaction_actiongroup(QAction * action);
	void bmx_qt_qaction_activate(QAction * action, int event);
	int bmx_qt_qaction_autorepeat(QAction * action);
	BBObject * bmx_qt_qaction_data(QAction * action);
	MaxQFont * bmx_qt_qaction_font(QAction * action);
	BBString * bmx_qt_qaction_icontext(QAction * action);
	int bmx_qt_qaction_ischeckable(QAction * action);
	int bmx_qt_qaction_ischecked(QAction * action);
	int bmx_qt_qaction_isenabled(QAction * action);
	int bmx_qt_qaction_isiconvisibleinmenu(QAction * action);
	int bmx_qt_qaction_isseparator(QAction * action);
	int bmx_qt_qaction_isvisible(QAction * action);
	QMenu * bmx_qt_qaction_menu(QAction * action);
	int bmx_qt_qaction_menurole(QAction * action);
	QWidget * bmx_qt_qaction_parentwidget(QAction * action);
	void bmx_qt_qaction_setactiongroup(QAction * action, QActionGroup * group);
	void bmx_qt_qaction_setautorepeat(QAction * action, int value);
	void bmx_qt_qaction_setcheckable(QAction * action, int value);
	void bmx_qt_qaction_setdata(QAction * action, BBObject * userData);
	void bmx_qt_qaction_setfont(QAction * action, MaxQFont * font);
	void bmx_qt_qaction_seticontext(QAction * action, BBString * text);
	void bmx_qt_qaction_seticonvisibleinmenu(QAction * action, int visible);
	void bmx_qt_qaction_setmenu(QAction * action, QMenu * menu);
	void bmx_qt_qaction_setmenurole(QAction * action, int menuRole);
	void bmx_qt_qaction_setseparator(QAction * action, int value);
	void bmx_qt_qaction_setshortcutcontext(QAction * action, int context);
	void bmx_qt_qaction_setstatustip(QAction * action, BBString * statusTip);
	void bmx_qt_qaction_settext(QAction * action, BBString * text);
	void bmx_qt_qaction_settooltip(QAction * action, BBString * tip);
	void bmx_qt_qaction_setwhatsthis(QAction * action, BBString * what);
	BBString * bmx_qt_qaction_shortcut(QAction * action);
	int bmx_qt_qaction_shortcutcontext(QAction * action);
	int bmx_qt_qaction_showstatustext(QAction * action, QWidget * widget);
	BBString * bmx_qt_qaction_statustip(QAction * action);
	BBString * bmx_qt_qaction_text(QAction * action);
	BBString * bmx_qt_qaction_tooltip(QAction * action);
	BBString * bmx_qt_qaction_whatsthis(QAction * action);
	
	Qt::WidgetAttribute bmx_qt_inttowidgetattribute(int a);
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQWidget : public QWidget
{
	Q_OBJECT

public:
	MaxQWidget(BBObject * handle, QWidget * parent, Qt::WindowFlags flags);
	~MaxQWidget();

	QSize sizeHint() const;
	QSize minimumSizeHint() const;
	
protected:
	void paintEvent(QPaintEvent * event);
	void mouseDoubleClickEvent(QMouseEvent * event);
	void mouseMoveEvent(QMouseEvent * event);
	void mousePressEvent(QMouseEvent * event);
	void mouseReleaseEvent(QMouseEvent * event);

private:
	BBObject * maxHandle;
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQAction : public MaxQObjectWrapper
{
	Q_OBJECT

public:
	MaxQAction(BBObject * handle, QAction * action);
	MaxQAction(QAction * action);
	
	QAction * Action();
	
	static void link(QAction * a);
	
	~MaxQAction();

private:
	void doConnections();
	QAction * action;
	
private slots:
	void onChanged();
	void onHovered();
	void onToggled(bool checked);
	void onTriggered(bool checked);

};

#endif
