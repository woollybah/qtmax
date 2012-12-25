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
#include "../qicon.mod/glue.h"
#include "../qregion.mod/glue.h"
#include "../qlocale.mod/glue.h"
#include "../qobject.mod/glue.h"
#include "../qpalette.mod/glue.h"
#include <QWidget>
#include <QPainter>
#include <QAction>
#include <QActionGroup>
#include <QLayout>

class MaxQWidget;
class MaxQAction;
class MaxQActionGroup;

extern "C" {

#include <blitz.h>
	
	void _qt_qwidget_QActionGroup__OnHovered(BBObject * handle, QAction * action);
	void _qt_qwidget_QActionGroup__OnTriggered(BBObject * handle, QAction * action);

	void _qt_qwidget_QWidget__OnCustomContextMenuRequested(BBObject * handle, int x, int y);
	void _qt_qwidget_QWidget__OnPaintEvent(BBObject * handle, QPaintEvent * event);
	void _qt_qwidget_QWidget__OnMouseDoubleClickEvent(BBObject * handle, QMouseEvent * event);
	void _qt_qwidget_QWidget__OnMouseMoveEvent(BBObject * handle, QMouseEvent * event);
	void _qt_qwidget_QWidget__OnMousePressEvent(BBObject * handle, QMouseEvent * event);
	void _qt_qwidget_QWidget__OnMouseReleaseEvent(BBObject * handle, QMouseEvent * event);
	void _qt_qwidget_QWidget__OnActionEvent(BBObject * handle, QActionEvent * event);
	void _qt_qwidget_QWidget__OnChangeEvent(BBObject * handle, QEvent * event);
	void _qt_qwidget_QWidget__OnCloseEvent(BBObject * handle, QCloseEvent * event);
	void _qt_qwidget_QWidget__OnContextMenuEvent(BBObject * handle, QContextMenuEvent * event);
	void _qt_qwidget_QWidget__OnDragEnterEvent(BBObject * handle, QDragEnterEvent * event);
	void _qt_qwidget_QWidget__OnDragLeaveEvent(BBObject * handle, QDragLeaveEvent * event);
	void _qt_qwidget_QWidget__OnDragMoveEvent(BBObject * handle, QDragMoveEvent * event);
	void _qt_qwidget_QWidget__OnDropEvent(BBObject * handle, QDropEvent * event);
	void _qt_qwidget_QWidget__OnEnterEvent(BBObject * handle, QEvent * event);
	void _qt_qwidget_QWidget__OnFocusInEvent(BBObject * handle, QFocusEvent * event);
	void _qt_qwidget_QWidget__OnFocusOutEvent(BBObject * handle, QFocusEvent * event);
	void _qt_qwidget_QWidget__OnHideEvent(BBObject * handle, QHideEvent * event);
	void _qt_qwidget_QWidget__OnInputMethodEvent(BBObject * handle, QInputMethodEvent * event);
	void _qt_qwidget_QWidget__OnKeyPressEvent(BBObject * handle, QKeyEvent * event);
	void _qt_qwidget_QWidget__OnKeyReleaseEvent(BBObject * handle, QKeyEvent * event);
	void _qt_qwidget_QWidget__OnLeaveEvent(BBObject * handle, QEvent * event);
	void _qt_qwidget_QWidget__OnMoveEvent(BBObject * handle, QMoveEvent * event);
	void _qt_qwidget_QWidget__OnResizeEvent(BBObject * handle, QResizeEvent * event);
	void _qt_qwidget_QWidget__OnShowEvent(BBObject * handle, QShowEvent * event);
	void _qt_qwidget_QWidget__OnTabletEvent(BBObject * handle, QTabletEvent * event);
	void _qt_qwidget_QWidget__OnWheelEvent(BBObject * handle, QWheelEvent * event);
	int _qt_qwidget_QWidget__OnFocusNextPrevChild(BBObject * handle, int next);

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
	void bmx_qt_qwidget_setattribute(QWidget * widget, int attribute, int on);
	void bmx_qt_qwidget_move(QWidget * widget, int x, int y);
	void bmx_qt_qwidget_settooltip(QWidget * widget, BBString * text);
	MaxQSizePolicy * bmx_qt_qwidget_sizepolicy(QWidget * widget);
	void bmx_qt_qwidget_setsizepolicyhv(QWidget * widget, int horizontalPolicy, int verticalPolicy);
	MaxQFont * bmx_qt_qwidget_font(QWidget * widget);
	MaxQFontMetrics * bmx_qt_qwidget_fontmetrics(QWidget * widget);
	void bmx_qt_qwidget_setfont(QWidget * widget, MaxQFont * font);
	QWidget * bmx_qt_qwidget_window(QWidget * widget);
	BBString * bmx_qt_qwidget_windowfilepath(QWidget * widget);
	int bmx_qt_qwidget_windowflags(QWidget * widget);
	MaxQIcon * bmx_qt_qwidget_windowicon(QWidget * widget);
	BBString * bmx_qt_qwidget_windowicontext(QWidget * widget);
	int bmx_qt_qwidget_windowmodality(QWidget * widget);
	double bmx_qt_qwidget_windowopacity(QWidget * widget);
	BBString * bmx_qt_qwidget_windowrole(QWidget * widget);
	int bmx_qt_qwidget_windowstate(QWidget * widget);
	BBString * bmx_qt_qwidget_windowtitle(QWidget * widget);
	int bmx_qt_qwidget_windowtype(QWidget * widget);
	int bmx_qt_qwidget_x(QWidget * widget);
	int bmx_qt_qwidget_y(QWidget * widget);
	MaxQLocale * bmx_qt_qwidget_locale(QWidget * widget);
	void bmx_qt_qwidget_setgeometry(QWidget * widget, int x, int y, int w, int h);
	MaxQPalette * bmx_qt_qwidget_palette(QWidget * widget);
	void bmx_qt_qwidget_setpalette(QWidget * widget, MaxQPalette * palette);

	void bmx_qt_qwidget_default_paintevent(MaxQWidget * widget, QPaintEvent * event);
	void bmx_qt_qwidget_default_mousedoubleclickevent(MaxQWidget * widget, QMouseEvent * event);
	void bmx_qt_qwidget_default_mousemoveevent(MaxQWidget * widget, QMouseEvent * event);
	void bmx_qt_qwidget_default_mousepressevent(MaxQWidget * widget, QMouseEvent * event);
	void bmx_qt_qwidget_default_mousereleaseevent(MaxQWidget * widget, QMouseEvent * event);
	void bmx_qt_qwidget_default_actionevent(MaxQWidget * widget, QActionEvent * event);
	void bmx_qt_qwidget_default_changeevent(MaxQWidget * widget, QEvent * event);
	void bmx_qt_qwidget_default_closeevent(MaxQWidget * widget, QCloseEvent * event);
	void bmx_qt_qwidget_default_contextmenuevent(MaxQWidget * widget, QContextMenuEvent * event);
	void bmx_qt_qwidget_default_dragenterevent(MaxQWidget * widget, QDragEnterEvent * event);
	void bmx_qt_qwidget_default_dragleaveevent(MaxQWidget * widget, QDragLeaveEvent * event);
	void bmx_qt_qwidget_default_dragmoveevent(MaxQWidget * widget, QDragMoveEvent * event);
	void bmx_qt_qwidget_default_dropevent(MaxQWidget * widget, QDropEvent * event);
	void bmx_qt_qwidget_default_enterevent(MaxQWidget * widget, QEvent * event);
	void bmx_qt_qwidget_default_focusinevent(MaxQWidget * widget, QFocusEvent * event);
	void bmx_qt_qwidget_default_focusoutevent(MaxQWidget * widget, QFocusEvent * event);
	void bmx_qt_qwidget_default_hideevent(MaxQWidget * widget, QHideEvent * event);
	void bmx_qt_qwidget_default_inputmethodevent(MaxQWidget * widget, QInputMethodEvent * event);
	void bmx_qt_qwidget_default_keypressevent(MaxQWidget * widget, QKeyEvent * event);
	void bmx_qt_qwidget_default_keyreleaseevent(MaxQWidget * widget, QKeyEvent * event);
	void bmx_qt_qwidget_default_leaveevent(MaxQWidget * widget, QEvent * event);
	void bmx_qt_qwidget_default_moveevent(MaxQWidget * widget, QMoveEvent * event);
	void bmx_qt_qwidget_default_resizeevent(MaxQWidget * widget, QResizeEvent * event);
	void bmx_qt_qwidget_default_showevent(MaxQWidget * widget, QShowEvent * event);
	void bmx_qt_qwidget_default_tabletevent(MaxQWidget * widget, QTabletEvent * event);
	void bmx_qt_qwidget_default_wheelevent(MaxQWidget * widget, QWheelEvent * event);
	int bmx_qt_qwidget_default_focusnextprevchild(MaxQWidget * widget, int next);

	void bmx_qt_qwidget_default_sizehint(MaxQWidget * widget, int * w, int * h);
	void bmx_qt_qwidget_default_minimumsizehint(MaxQWidget * widget, int * w, int * h);

	int bmx_qt_qwidget_height(QWidget * widget);
	int bmx_qt_qwidget_width(QWidget * widget);
	int bmx_qt_qwidget_acceptdrops(QWidget * widget);
	BBString * bmx_qt_qwidget_accessibledescription(QWidget * widget);
	BBString * bmx_qt_qwidget_accessiblename(QWidget * widget);
	void bmx_qt_qwidget_activatewindow(QWidget * widget);
	void bmx_qt_qwidget_adjustsize(QWidget * widget);
	int bmx_qt_qwidget_autofillbackground(QWidget * widget);
	int bmx_qt_qwidget_backgroundrole(QWidget * widget);
	void bmx_qt_qwidget_basesize(QWidget * widget, int * w, int * h);
	QWidget * bmx_qt_qwidget_childat(QWidget * widget, int x, int y);
	MaxQRect * bmx_qt_qwidget_childrenrect(QWidget * widget);
	MaxQRegion * bmx_qt_qwidget_childrenregion(QWidget * widget);
	void bmx_qt_qwidget_clearfocus(QWidget * widget);
	void bmx_qt_qwidget_clearmask(QWidget * widget);
	MaxQRect * bmx_qt_qwidget_contentsrect(QWidget * widget);
	QWidget * bmx_qt_qwidget_parentwidget(QWidget * widget);
	void bmx_qt_qwidget_pos(QWidget * widget, int * x, int * y);
	MaxQRect * bmx_qt_qwidget_rect(QWidget * widget);
	void bmx_qt_qwidget_size(QWidget * widget, int * w, int * h);
	void bmx_qt_qwidget_sizeincrement(QWidget * widget, int * w, int * h);
	int bmx_qt_qwidget_winid(QWidget * widget);
	void bmx_qt_qwidget_setparent(QWidget * widget, QWidget * parent);
	int bmx_qt_qwidget_hasfocus(QWidget * widget);
	int bmx_qt_qwidget_hasmousetracking(QWidget * widget);
	int bmx_qt_qwidget_isactivewindow(QWidget * widget);
	int bmx_qt_qwidget_isenabled(QWidget * widget);
	int bmx_qt_qwidget_isfullscreen(QWidget * widget);
	int bmx_qt_qwidget_ishidden(QWidget * widget);
	int bmx_qt_qwidget_ismaximized(QWidget * widget);
	int bmx_qt_qwidget_isminimized(QWidget * widget);
	int bmx_qt_qwidget_ismodal(QWidget * widget);
	int bmx_qt_qwidget_isvisible(QWidget * widget);
	int bmx_qt_qwidget_iswindow(QWidget * widget);
	int bmx_qt_qwidget_iswindowmodified(QWidget * widget);
	void bmx_qt_qwidget_setmaximumheight(QWidget * widget, int maxh);
	void bmx_qt_qwidget_setmaximumsize(QWidget * widget, int w, int h);
	void bmx_qt_qwidget_setmaximumwidth(QWidget * widget, int maxw);
	void bmx_qt_qwidget_setminimumheight(QWidget * widget, int minh);
	void bmx_qt_qwidget_setminimumsize(QWidget * widget, int w, int h);
	void bmx_qt_qwidget_setminimumwidth(QWidget * widget, int minw);
	void bmx_qt_qwidget_setmousetracking(QWidget * widget, int enable);
	void bmx_qt_qwidget_setshortcutautorepeat(QWidget * widget, int id, int enable);
	void bmx_qt_qwidget_setshortcutenabled(QWidget * widget, int id, int enable);
	void bmx_qt_qwidget_setsizeincrement(QWidget * widget, int w, int h);
	void bmx_qt_qwidget_setautofillbackground(QWidget * widget, int enabled);

	QAction * bmx_qt_qaction_create(BBObject * handle, BBString * text, QObject * parent);
	QAction * bmx_qt_qaction_createwithicon(BBObject * handle, MaxQIcon * icon, BBString * text, QObject * parent);
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
	void bmx_qt_qaction_setshortcuts(QAction * action, int key);
	void bmx_qt_qaction_hover(QAction * action);
	void bmx_qt_qaction_setchecked(QAction * action, int value);
	void bmx_qt_qaction_setdisabled(QAction * action, int value);
	void bmx_qt_qaction_setenabled(QAction * action, int value);
	void bmx_qt_qaction_setvisible(QAction * action, int value);
	void bmx_qt_qaction_toggle(QAction * action);
	void bmx_qt_qaction_trigger(QAction * action);


	QActionGroup * bmx_qt_qactiongroup_create(BBObject * handle, QObject * parent);
	QAction * bmx_qt_qactiongroup_addaction(QActionGroup * group, QAction * action);
	QAction * bmx_qt_qactiongroup_addactiontext(QActionGroup * group, BBString * text);
	QAction * bmx_qt_qactiongroup_checkedaction(QActionGroup * group);
	int bmx_qt_qactiongroup_isenabled(QActionGroup * group);
	int bmx_qt_qactiongroup_isexclusive(QActionGroup * group);
	int bmx_qt_qactiongroup_isvisible(QActionGroup * group);
	void bmx_qt_qactiongroup_removeaction(QActionGroup * group, QAction * action);
	void bmx_qt_qactiongroup_setdisabled(QActionGroup * group, int value);
	void bmx_qt_qactiongroup_setenabled(QActionGroup * group, int value);
	void bmx_qt_qactiongroup_setexclusive(QActionGroup * group, int value);
	void bmx_qt_qactiongroup_setvisible(QActionGroup * group, int value);

	Qt::WidgetAttribute bmx_qt_inttowidgetattribute(int a);
	
	void bmx_qt_qlayout_setsizeconstraint(QLayout * layout, int constraint);
	void bmx_qt_qlayout_setcontentsmargins(QLayout * layout, int left, int top, int right, int bottom);
	void bmx_qt_qlayout_setenabled(QLayout * layout, int enable);
	void bmx_qt_qlayout_setmenubar(QLayout * layout, QWidget * widget);

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
	
	void defaultSizeHint(int * w, int * h);
	void defaultMinimumSizeHint(int * w, int * h);

	void defaultActionEvent(QActionEvent * event);
	void defaultChangeEvent(QEvent * event);
	void defaultCloseEvent(QCloseEvent * event);
	void defaultContextMenuEvent(QContextMenuEvent * event);
	void defaultDragEnterEvent(QDragEnterEvent * event);
	void defaultDragLeaveEvent(QDragLeaveEvent * event);
	void defaultDragMoveEvent(QDragMoveEvent * event);
	void defaultDropEvent(QDropEvent * event);
	void defaultEnterEvent(QEvent * event);
	void defaultFocusInEvent(QFocusEvent * event);
	void defaultFocusOutEvent(QFocusEvent * event);
	void defaultHideEvent(QHideEvent * event);
	void defaultInputMethodEvent(QInputMethodEvent * event);
	void defaultKeyPressEvent(QKeyEvent * event);
	void defaultKeyReleaseEvent(QKeyEvent * event);
	void defaultLeaveEvent(QEvent * event);
	void defaultMoveEvent(QMoveEvent * event);
	void defaultPaintEvent(QPaintEvent * event);
	void defaultMouseDoubleClickEvent(QMouseEvent * event);
	void defaultMouseMoveEvent(QMouseEvent * event);
	void defaultMousePressEvent(QMouseEvent * event);
	void defaultMouseReleaseEvent(QMouseEvent * event);
	void defaultResizeEvent(QResizeEvent * event);
	void defaultShowEvent(QShowEvent * event);
	void defaultTabletEvent(QTabletEvent * event);
	void defaultWheelEvent(QWheelEvent * event);
	bool defaultFocusNextPrevChild(bool next);
	
protected:
	void actionEvent(QActionEvent * event);
	void changeEvent(QEvent * event);
	void closeEvent(QCloseEvent * event);
	void contextMenuEvent(QContextMenuEvent * event);
	void dragEnterEvent(QDragEnterEvent * event);
	void dragLeaveEvent(QDragLeaveEvent * event);
	void dragMoveEvent(QDragMoveEvent * event);
	void dropEvent(QDropEvent * event);
	void enterEvent(QEvent * event);
	void focusInEvent(QFocusEvent * event);
	void focusOutEvent(QFocusEvent * event);
	void hideEvent(QHideEvent * event);
	void inputMethodEvent(QInputMethodEvent * event);
	void keyPressEvent(QKeyEvent * event);
	void keyReleaseEvent(QKeyEvent * event);
	void leaveEvent(QEvent * event);
	void moveEvent(QMoveEvent * event);
	void paintEvent(QPaintEvent * event);
	void mouseDoubleClickEvent(QMouseEvent * event);
	void mouseMoveEvent(QMouseEvent * event);
	void mousePressEvent(QMouseEvent * event);
	void mouseReleaseEvent(QMouseEvent * event);
	void resizeEvent(QResizeEvent * event);
	void showEvent(QShowEvent * event);
	void tabletEvent(QTabletEvent * event);
	void wheelEvent(QWheelEvent * event);
	void timerEvent(QTimerEvent * event);
	bool focusNextPrevChild(bool next);

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

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQActionGroup : public QActionGroup
{
	Q_OBJECT
	
public:
	MaxQActionGroup(BBObject * handle, QObject * parent);
	~MaxQActionGroup();

private:
	BBObject * maxHandle;

private slots:
	void onHovered(QAction * action);
	void onTriggered(QAction * action);
};

#endif
