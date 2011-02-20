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

#ifndef MAX_QT_QGRAPHICSVIEW
#define MAX_QT_QGRAPHICSVIEW

#include "../core.mod/glue.h"
#include "../qpainterpath.mod/glue.h"
#include "../qbrush.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include "../qpalette.mod/glue.h"
#include "../qcursor.mod/glue.h"
#include "../qpixmap.mod/glue.h"
#include <QtCore>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class MaxQGraphicsView;
class MaxQGraphicsScene;
class MaxQGraphicsItem;
class MaxQGraphicsEventItem;
class MaxQGraphicsItemList;
class MaxQGraphicsPixmapItem;

extern "C" {

#include <blitz.h>

	BBObject * _qt_qpainter_QPainter__create(QPainter * painter);

	void _qt_qgraphicsview_QGraphicsScene__contextMenuEvent(BBObject * handle, QGraphicsSceneContextMenuEvent * contextMenuEvent);
	void _qt_qgraphicsview_QGraphicsScene__dragEnterEvent(BBObject * handle, QGraphicsSceneDragDropEvent * event);
	void _qt_qgraphicsview_QGraphicsScene__dragLeaveEvent(BBObject * handle, QGraphicsSceneDragDropEvent * event);
	void _qt_qgraphicsview_QGraphicsScene__dragMoveEvent(BBObject * handle, QGraphicsSceneDragDropEvent * event);
	void _qt_qgraphicsview_QGraphicsScene__drawBackground(BBObject * handle, QPainter * painter, MaxQRectF * rect);
	void _qt_qgraphicsview_QGraphicsScene__drawForeground(BBObject * handle, QPainter * painter, MaxQRectF * rect);
	void _qt_qgraphicsview_QGraphicsScene__dropEvent(BBObject * handle, QGraphicsSceneDragDropEvent * event);
	void _qt_qgraphicsview_QGraphicsScene__focusInEvent(BBObject * handle, QFocusEvent * focusEvent);
	void _qt_qgraphicsview_QGraphicsScene__focusOutEvent(BBObject * handle, QFocusEvent * focusEvent);
	void _qt_qgraphicsview_QGraphicsScene__helpEvent(BBObject * handle, QGraphicsSceneHelpEvent * helpEvent);
	void _qt_qgraphicsview_QGraphicsScene__inputMethodEvent(BBObject * handle, QInputMethodEvent * event);
	void _qt_qgraphicsview_QGraphicsScene__keyPressEvent(BBObject * handle, QKeyEvent * keyEvent);
	void _qt_qgraphicsview_QGraphicsScene__keyReleaseEvent(BBObject * handle, QKeyEvent * keyEvent);
	void _qt_qgraphicsview_QGraphicsScene__mouseDoubleClickEvent(BBObject * handle, QGraphicsSceneMouseEvent * mouseEvent);
	void _qt_qgraphicsview_QGraphicsScene__mouseMoveEvent(BBObject * handle, QGraphicsSceneMouseEvent * mouseEvent);
	void _qt_qgraphicsview_QGraphicsScene__mousePressEvent(BBObject * handle, QGraphicsSceneMouseEvent * mouseEvent);
	void _qt_qgraphicsview_QGraphicsScene__mouseReleaseEvent(BBObject * handle, QGraphicsSceneMouseEvent * mouseEvent);
	void _qt_qgraphicsview_QGraphicsScene__wheelEvent(BBObject * handle, QGraphicsSceneWheelEvent * wheelEvent);

	BBArray * _qt_qgraphicsview_QGraphicsScene__newItems(int size);
	void _qt_qgraphicsview_QGraphicsScene__setItem(BBArray * arr, int index, QGraphicsItem * item);

	void _qt_qgraphicsview_QGraphicsItem__Free(BBObject * handle);
	MaxQRectF * _qt_qgraphicsview_QGraphicsItem__boundingRect(BBObject * handle);
	void _qt_qgraphicsview_QGraphicsItem__paint(BBObject * handle, QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

	
	QGraphicsView * bmx_qt_qgraphicsview_create(BBObject * handle, QWidget * parent);
	QGraphicsView * bmx_qt_qgraphicsview_createwithscene(BBObject * handle, QGraphicsScene * scene, QWidget * parent);
	void bmx_qt_qgraphicsview_setalignment(QGraphicsView * view, int alignment);
	void bmx_qt_qgraphicsview_setbackgroundbrush(QGraphicsView * view, MaxQBrush * brush);
	void bmx_qt_qgraphicsview_setcachemode(QGraphicsView * view, int _mode);
	void bmx_qt_qgraphicsview_setdragmode(QGraphicsView * view, int _mode);
	void bmx_qt_qgraphicsview_setforegroundbrush(QGraphicsView * view, MaxQBrush * brush);
	void bmx_qt_qgraphicsview_setinteractive(QGraphicsView * view, int allowed);
	void bmx_qt_qgraphicsview_setmatrix(QGraphicsView * view, MaxQMatrix * matrix, int combine);
	void bmx_qt_qgraphicsview_setoptimizationflag(QGraphicsView * view, int flag, int enabled);
	void bmx_qt_qgraphicsview_setoptimizationflags(QGraphicsView * view, int flags);
	void bmx_qt_qgraphicsview_setrenderhint(QGraphicsView * view, int hint, int enabled);
	void bmx_qt_qgraphicsview_setrenderhints(QGraphicsView * view, int hints);
	void bmx_qt_qgraphicsview_setresizeanchor(QGraphicsView * view, int anchor);
	void bmx_qt_qgraphicsview_setrubberbandselectionmode(QGraphicsView * view, int _mode);
	void bmx_qt_qgraphicsview_setscene(QGraphicsView * view, QGraphicsScene * scene);
	void bmx_qt_qgraphicsview_setscenerectrect(QGraphicsView * view, MaxQRectF * rect);
	void bmx_qt_qgraphicsview_setscenerect(QGraphicsView * view, double x, double y, double w, double h);
	void bmx_qt_qgraphicsview_settransform(QGraphicsView * view, MaxQTransform * matrix, int combine);
	void bmx_qt_qgraphicsview_settransformationanchor(QGraphicsView * view, int anchor);

	void bmx_qt_qgraphicsview_default_paintevent(MaxQGraphicsView * widget, QPaintEvent * event);
	void bmx_qt_qgraphicsview_default_mousedoubleclickevent(MaxQGraphicsView * widget, QMouseEvent * event);
	void bmx_qt_qgraphicsview_default_mousemoveevent(MaxQGraphicsView * widget, QMouseEvent * event);
	void bmx_qt_qgraphicsview_default_mousepressevent(MaxQGraphicsView * widget, QMouseEvent * event);
	void bmx_qt_qgraphicsview_default_mousereleaseevent(MaxQGraphicsView * widget, QMouseEvent * event);
	void bmx_qt_qgraphicsview_default_actionevent(MaxQGraphicsView * widget, QActionEvent * event);
	void bmx_qt_qgraphicsview_default_changeevent(MaxQGraphicsView * widget, QEvent * event);
	void bmx_qt_qgraphicsview_default_closeevent(MaxQGraphicsView * widget, QCloseEvent * event);
	void bmx_qt_qgraphicsview_default_contextmenuevent(MaxQGraphicsView * widget, QContextMenuEvent * event);
	void bmx_qt_qgraphicsview_default_dragenterevent(MaxQGraphicsView * widget, QDragEnterEvent * event);
	void bmx_qt_qgraphicsview_default_dragleaveevent(MaxQGraphicsView * widget, QDragLeaveEvent * event);
	void bmx_qt_qgraphicsview_default_dragmoveevent(MaxQGraphicsView * widget, QDragMoveEvent * event);
	void bmx_qt_qgraphicsview_default_dropevent(MaxQGraphicsView * widget, QDropEvent * event);
	void bmx_qt_qgraphicsview_default_enterevent(MaxQGraphicsView * widget, QEvent * event);
	void bmx_qt_qgraphicsview_default_focusinevent(MaxQGraphicsView * widget, QFocusEvent * event);
	void bmx_qt_qgraphicsview_default_focusoutevent(MaxQGraphicsView * widget, QFocusEvent * event);
	void bmx_qt_qgraphicsview_default_hideevent(MaxQGraphicsView * widget, QHideEvent * event);
	void bmx_qt_qgraphicsview_default_inputmethodevent(MaxQGraphicsView * widget, QInputMethodEvent * event);
	void bmx_qt_qgraphicsview_default_keypressevent(MaxQGraphicsView * widget, QKeyEvent * event);
	void bmx_qt_qgraphicsview_default_keyreleaseevent(MaxQGraphicsView * widget, QKeyEvent * event);
	void bmx_qt_qgraphicsview_default_leaveevent(MaxQGraphicsView * widget, QEvent * event);
	void bmx_qt_qgraphicsview_default_moveevent(MaxQGraphicsView * widget, QMoveEvent * event);
	void bmx_qt_qgraphicsview_default_resizeevent(MaxQGraphicsView * widget, QResizeEvent * event);
	void bmx_qt_qgraphicsview_default_showevent(MaxQGraphicsView * widget, QShowEvent * event);
	void bmx_qt_qgraphicsview_default_tabletevent(MaxQGraphicsView * widget, QTabletEvent * event);
	void bmx_qt_qgraphicsview_default_wheelevent(MaxQGraphicsView * widget, QWheelEvent * event);

	void bmx_qt_qgraphicsview_scale(QGraphicsView * view, double sx, double sy);
	QGraphicsScene * bmx_qt_qgraphicsview_scene(QGraphicsView * view);
	MaxQRectF * bmx_qt_qgraphicsview_scenerect(QGraphicsView * view);
	void bmx_qt_qgraphicsview_resetcachedcontent(QGraphicsView * view);
	void bmx_qt_qgraphicsview_resetmatrix(QGraphicsView * view);
	void bmx_qt_qgraphicsview_resettransform(QGraphicsView * view);
	int bmx_qt_qgraphicsview_alignment(QGraphicsView * view);
	MaxQBrush * bmx_qt_qgraphicsview_backgroundbrush(QGraphicsView * view);
	int bmx_qt_qgraphicsview_cachemode(QGraphicsView * view);
	void bmx_qt_qgraphicsview_sizehint(QGraphicsView * view, int * w, int * h);
	void bmx_qt_qgraphicsview_render(QGraphicsView * view, QPainter * painter, MaxQRectF * target, MaxQRect * source, int aspectRatioMode);

	QGraphicsScene * bmx_qt_qgraphicsscene_create(BBObject * handle, QObject * parent);
	void bmx_qt_qgraphicsscene_setscenerectrect(QGraphicsScene * scene, MaxQRectF * rect);
	void bmx_qt_qgraphicsscene_setscenerect(QGraphicsScene * scene, double x, double y, double w, double h);
	void bmx_qt_qgraphicsscene_advance(QGraphicsScene * scene);
	void bmx_qt_qgraphicsscene_clear(QGraphicsScene * scene);
	void bmx_qt_qgraphicsscene_clearselection(QGraphicsScene * scene);
	void bmx_qt_qgraphicsscene_additem(QGraphicsScene * scene, void * item);
	void bmx_qt_qgraphicsscene_setbackgroundbrush(QGraphicsScene * scene, MaxQBrush * brush);
	void bmx_qt_qgraphicsscene_setbsptreedepth(QGraphicsScene * scene, int depth);
	void bmx_qt_qgraphicsscene_setfocus(QGraphicsScene * scene, int focusReason);
	void bmx_qt_qgraphicsscene_setfocusitem(QGraphicsScene * scene, QGraphicsItem * item, int focusReason);
	void bmx_qt_qgraphicsscene_setfont(QGraphicsScene * scene, MaxQFont * font);
	void bmx_qt_qgraphicsscene_setforegroundbrush(QGraphicsScene * scene, MaxQBrush * brush);
	void bmx_qt_qgraphicsscene_setitemindexmethod(QGraphicsScene * scene, int _method);
	void bmx_qt_qgraphicsscene_setpalette(QGraphicsScene * scene, MaxQPalette * palette);
	void bmx_qt_qgraphicsscene_setselectionarea(QGraphicsScene * scene, MaxQPainterPath * path, int _mode);
	void bmx_qt_qgraphicsscene_setsortcacheenabled(QGraphicsScene * scene, int enabled);
	void bmx_qt_qgraphicsscene_setstickyfocus(QGraphicsScene * scene, int enabled);
	void bmx_qt_qgraphicsscene_setstyle(QGraphicsScene * scene, QStyle * style);
	MaxQRectF * bmx_qt_qgraphicsscene_scenerect(QGraphicsScene * scene);
	BBArray * bmx_qt_qgraphicsscene_selecteditems(QGraphicsScene * scene);
	MaxQPainterPath * bmx_qt_qgraphicsscene_selectionarea(QGraphicsScene * scene);
	void bmx_qt_qgraphicsscene_setactivewindow(QGraphicsScene * scene, QGraphicsWidget * widget);
	double bmx_qt_qgraphicsscene_width(QGraphicsScene * scene);
	double bmx_qt_qgraphicsscene_height(QGraphicsScene * scene);
	void bmx_qt_qgraphicsscene_udpate(QGraphicsScene * scene, MaxQRectF * rect);
	int bmx_qt_qgraphicsscene_hasfocus(QGraphicsScene * scene);
	QGraphicsItem * bmx_qt_qgraphicsscene_itemat(QGraphicsScene * scene, double x, double y);
	int bmx_qt_qgraphicsscene_itemindexmethod(QGraphicsScene * scene);
	MaxQRectF * bmx_qt_qgraphicsscene_itemsboundingrect(QGraphicsScene * scene);
	QGraphicsItem * bmx_qt_qgraphicsscene_mousegrabberitem(QGraphicsScene * scene);
	MaxQPalette * bmx_qt_qgraphicsscene_palette(QGraphicsScene * scene);
	void bmx_qt_qgraphicsscene_removeitem(QGraphicsScene * scene, QGraphicsItem * item);
	MaxQGraphicsItemList * bmx_qt_qgraphicsscene_items(QGraphicsScene * scene);
	QGraphicsPixmapItem * bmx_qt_qgraphicsscene_addpixmap(QGraphicsScene * scene, MaxQPixmap * pixmap);

	void bmx_qt_qgraphicsscene_defaultdrawbackground(MaxQGraphicsScene * scene, QPainter * painter, MaxQRectF * rect);
	void bmx_qt_qgraphicsscene_defaultdrawforeground(MaxQGraphicsScene * scene, QPainter * painter, MaxQRectF * rect);
	void bmx_qt_qgraphicsscene_defaultcontextmenuevent(MaxQGraphicsScene * scene, QGraphicsSceneContextMenuEvent * contextMenuEvent);
	void bmx_qt_qgraphicsscene_defaultdragenterevent(MaxQGraphicsScene * scene, QGraphicsSceneDragDropEvent * event);
	void bmx_qt_qgraphicsscene_defaultdragleaveevent(MaxQGraphicsScene * scene, QGraphicsSceneDragDropEvent * event);
	void bmx_qt_qgraphicsscene_defaultdragmoveevent(MaxQGraphicsScene * scene, QGraphicsSceneDragDropEvent * event);
	void bmx_qt_qgraphicsscene_defaultdropevent(MaxQGraphicsScene * scene, QGraphicsSceneDragDropEvent * event);
	void bmx_qt_qgraphicsscene_defaultfocusinevent(MaxQGraphicsScene * scene, QFocusEvent * focusEvent);
	void bmx_qt_qgraphicsscene_defaultfocusoutevent(MaxQGraphicsScene * scene, QFocusEvent * focusEvent);
	void bmx_qt_qgraphicsscene_defaulthelpevent(MaxQGraphicsScene * scene, QGraphicsSceneHelpEvent * helpEvent);
	void bmx_qt_qgraphicsscene_defaultinputmethodevent(MaxQGraphicsScene * scene, QInputMethodEvent * event);
	void bmx_qt_qgraphicsscene_defaultkeypressevent(MaxQGraphicsScene * scene, QKeyEvent * keyEvent);
	void bmx_qt_qgraphicsscene_defaultkeyreleaseevent(MaxQGraphicsScene * scene, QKeyEvent * keyEvent);
	void bmx_qt_qgraphicsscene_defaultmousedoubleclickevent(MaxQGraphicsScene * scene, QGraphicsSceneMouseEvent * mouseEvent);
	void bmx_qt_qgraphicsscene_defaultmousemoveevent(MaxQGraphicsScene * scene, QGraphicsSceneMouseEvent * mouseEvent);
	void bmx_qt_qgraphicsscene_defaultmousepressevent(MaxQGraphicsScene * scene, QGraphicsSceneMouseEvent * mouseEvent);
	void bmx_qt_qgraphicsscene_defaultmousereleaseevent(MaxQGraphicsScene * scene, QGraphicsSceneMouseEvent * mouseEvent);
	void bmx_qt_qgraphicsscene_defaultwheelevent(MaxQGraphicsScene * scene, QGraphicsSceneWheelEvent * wheelEvent);


	void qgibind( QGraphicsItem *obj, BBObject *peer );
	void qgiunbind(QGraphicsItem *obj);
	BBObject *qgifind( QGraphicsItem *obj );

	int bmx_qt_qgraphicsitem_isselected(QGraphicsItem * item);
	int bmx_qt_qgraphicsitem_isundermouse(QGraphicsItem * item);
	int bmx_qt_qgraphicsitem_isvisible(QGraphicsItem * item);
	int bmx_qt_qgraphicsitem_isvisibleto(QGraphicsItem * item, QGraphicsItem * parent);
	int bmx_qt_qgraphicsitem_iswidget(QGraphicsItem * item);
	int bmx_qt_qgraphicsitem_iswindow(QGraphicsItem * item);
	void bmx_qt_qgraphicsitem_setacceptdrops(QGraphicsItem * item, int on);
	void bmx_qt_qgraphicsitem_setaccepthoverevents(QGraphicsItem * item, int enabled);
	void bmx_qt_qgraphicsitem_setacceptedmousebuttons(QGraphicsItem * item, int buttons);
	void bmx_qt_qgraphicsitem_setboundingregiongranularity(QGraphicsItem * item, double granularity);
	void bmx_qt_qgraphicsitem_setcachemode(QGraphicsItem * item, int mode, int w, int h);
	void bmx_qt_qgraphicsitem_setcursor(QGraphicsItem * item, MaxQCursor * cursor);
	void bmx_qt_qgraphicsitem_setdata(QGraphicsItem * item, int key, BBObject * value);
	void bmx_qt_qgraphicsitem_setenabled(QGraphicsItem * item, int enabled);
	void bmx_qt_qgraphicsitem_setflag(QGraphicsItem * item, int flag, int enabled);
	void bmx_qt_qgraphicsitem_setflags(QGraphicsItem * item, int flags);
	void bmx_qt_qgraphicsitem_setfocus(QGraphicsItem * item, int focusReason);
	void bmx_qt_qgraphicsitem_setgroup(QGraphicsItem * item, QGraphicsItemGroup * group);
	void bmx_qt_qgraphicsitem_sethandleschildevents(QGraphicsItem * item, int enabled);
	void bmx_qt_qgraphicsitem_setopacity(QGraphicsItem * item, double opacity);
	void bmx_qt_qgraphicsitem_setparentitem(QGraphicsItem * item, QGraphicsItem * parent);
	void bmx_qt_qgraphicsitem_setpos(QGraphicsItem * item, double x, double y);
	void bmx_qt_qgraphicsitem_setselected(QGraphicsItem * item, int selected);
	void bmx_qt_qgraphicsitem_settooltip(QGraphicsItem * item, BBString * toolTip);
	void bmx_qt_qgraphicsitem_settransform(QGraphicsItem * item, MaxQTransform * matrix, int combine);
	void bmx_qt_qgraphicsitem_setvisible(QGraphicsItem * item, int visible);
	void bmx_qt_qgraphicsitem_setzvalue(QGraphicsItem * item, double z);
	MaxQRectF * bmx_qt_qgraphicsitem_boundingrect(QGraphicsItem * item);
	void bmx_qt_qgraphicsitem_addtoscene(QGraphicsItem * item, QGraphicsScene * scene);
	void bmx_qt_qgraphicsitem_pos(QGraphicsItem * item, double * x, double * y);
	void bmx_qt_qgraphicsitem_removesceneeventfilter(QGraphicsItem * item, QGraphicsItem * filterItem);
	void bmx_qt_qgraphicsitem_resettransform(QGraphicsItem * item);
	void bmx_qt_qgraphicsitem_rotate(QGraphicsItem * item, double angle);
	void bmx_qt_qgraphicsitem_scale(QGraphicsItem * item, double sx, double sy);
	QGraphicsScene * bmx_qt_qgraphicsitem_scene(QGraphicsItem * item);
	MaxQRectF * bmx_qt_qgraphicsitem_sceneboundingrect(QGraphicsItem * item);
	void bmx_qt_qgraphicsitem_scenepos(QGraphicsItem * item, double * x, double * y);
	MaxQTransform * bmx_qt_qgraphicsitem_scenetransform(QGraphicsItem * item);
	void bmx_qt_qgraphicsitem_scroll(QGraphicsItem * item, double dx, double dy, MaxQRectF * rect);
	void bmx_qt_qgraphicsitem_update(QGraphicsItem * item, MaxQRectF * rect);
	QGraphicsItem * bmx_qt_qgraphicsitem_create(BBObject * handle, QGraphicsItem * parent);
	void bmx_qt_qgraphicsitem_mapfromitem(QGraphicsItem * gi, QGraphicsItem * item, double x, double y, double * x1, double * y1);
	void bmx_qt_qgraphicsitem_preparegeometrychange(QGraphicsItem * item);
	QGraphicsEffect * bmx_qt_qgraphicsitem_graphicseffect(QGraphicsItem * item);
	void bmx_qt_qgraphicsitem_setgraphicseffect(QGraphicsItem * item, QGraphicsEffect * effect);

	void bmx_qt_qgraphicsitem_defaultcontextmenuevent(void * item, QGraphicsSceneContextMenuEvent * contextMenuEvent);
	void bmx_qt_qgraphicsitem_defaultdragenterevent(void * item, QGraphicsSceneDragDropEvent * event);
	void bmx_qt_qgraphicsitem_defaultdragleaveevent(void * item, QGraphicsSceneDragDropEvent * event);
	void bmx_qt_qgraphicsitem_defaultdragmoveevent(void * item, QGraphicsSceneDragDropEvent * event);
	void bmx_qt_qgraphicsitem_defaultdropevent(void * item, QGraphicsSceneDragDropEvent * event);
	void bmx_qt_qgraphicsitem_defaultfocusinevent(void * item, QFocusEvent * focusEvent);
	void bmx_qt_qgraphicsitem_defaultfocusoutevent(void * item, QFocusEvent * focusEvent);
	void bmx_qt_qgraphicsitem_defaulthoverenterevent(void * item, QGraphicsSceneHoverEvent * hoverEvent);
	void bmx_qt_qgraphicsitem_defaulthoverleaveevent(void * item, QGraphicsSceneHoverEvent * hoverEvent);
	void bmx_qt_qgraphicsitem_defaulthovermoveevent(void * item, QGraphicsSceneHoverEvent * hoverEvent);
	void bmx_qt_qgraphicsitem_defaultinputmethodevent(void * item, QInputMethodEvent * event);
	void bmx_qt_qgraphicsitem_defaultkeypressevent(void * item, QKeyEvent * keyEvent);
	void bmx_qt_qgraphicsitem_defaultkeyreleaseevent(void * item, QKeyEvent * keyEvent);
	void bmx_qt_qgraphicsitem_defaultmousedoubleclickevent(void * item, QGraphicsSceneMouseEvent * mouseEvent);
	void bmx_qt_qgraphicsitem_defaultmousemoveevent(void * item, QGraphicsSceneMouseEvent * mouseEvent);
	void bmx_qt_qgraphicsitem_defaultmousepressevent(void * item, QGraphicsSceneMouseEvent * mouseEvent);
	void bmx_qt_qgraphicsitem_defaultmousereleaseevent(void * item, QGraphicsSceneMouseEvent * mouseEvent);
	void bmx_qt_qgraphicsitem_defaultsceneevent(void * item, QEvent * event);
	void bmx_qt_qgraphicsitem_defaultsceneeventfilter(void * item, QGraphicsItem * watched, QEvent * event);
	void bmx_qt_qgraphicsitem_defaultwheelevent(void * item, QGraphicsSceneWheelEvent * wheelEvent);

	int bmx_qt_qgraphicsitemlist_size(MaxQGraphicsItemList * list);
	void bmx_qt_qgraphicsitemlist_free(MaxQGraphicsItemList * list);
	int bmx_qt_qgraphicsitemlist_hasnext(MaxQGraphicsItemList * list);
	QGraphicsItem * bmx_qt_qgraphicsitemlist_nextobject(MaxQGraphicsItemList * list);
	void bmx_qt_qgraphicsitemlist_reset(MaxQGraphicsItemList * list);

	MaxQGraphicsPixmapItem * bmx_qt_qgraphicspixmapitem_create(BBObject * handle, MaxQPixmap * pixmap, QGraphicsItem * parent);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQGraphicsView : public QGraphicsView
{
	Q_OBJECT

public:
	MaxQGraphicsView(BBObject * handle, QWidget * parent);
	MaxQGraphicsView(BBObject * handle, QGraphicsScene * scene, QWidget * parent);
	~MaxQGraphicsView();

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

private:
	BBObject * maxHandle;

protected:
	void timerEvent(QTimerEvent * event);
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQGraphicsScene : public QGraphicsScene
{
	Q_OBJECT

public:
	MaxQGraphicsScene(BBObject * handle, QObject * parent);
	~MaxQGraphicsScene();

	void defaultContextMenuEvent(QGraphicsSceneContextMenuEvent * contextMenuEvent);
	void defaultDragEnterEvent(QGraphicsSceneDragDropEvent * event);
	void defaultDragLeaveEvent(QGraphicsSceneDragDropEvent * event);
	void defaultDragMoveEvent(QGraphicsSceneDragDropEvent * event);
	void defaultDrawBackground(QPainter * painter, const QRectF & rect);
	void defaultDrawForeground(QPainter * painter, const QRectF & rect);
	void defaultDrawItems(QPainter * painter, int numItems, QGraphicsItem * items[], const QStyleOptionGraphicsItem options[], QWidget * widget);
	void defaultDropEvent(QGraphicsSceneDragDropEvent * event);
	void defaultFocusInEvent(QFocusEvent * focusEvent);
	void defaultFocusOutEvent(QFocusEvent * focusEvent);
	void defaultHelpEvent(QGraphicsSceneHelpEvent * helpEvent);
	void defaultInputMethodEvent(QInputMethodEvent * event);
	void defaultKeyPressEvent(QKeyEvent * keyEvent);
	void defaultKeyReleaseEvent(QKeyEvent * keyEvent);
	void defaultMouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent);
	void defaultMouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
	void defaultMousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
	void defaultMouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
	void defaultWheelEvent(QGraphicsSceneWheelEvent * wheelEvent);

	
private:
	BBObject * maxHandle;
	
private slots:
	void onChanged(const QList<QRectF> & region);
	void onSceneRectChanged(const QRectF & rect);
	void onSelectionChanged();

protected:
	void timerEvent(QTimerEvent * event);
	void contextMenuEvent(QGraphicsSceneContextMenuEvent * contextMenuEvent);
	void dragEnterEvent(QGraphicsSceneDragDropEvent * event);
	void dragLeaveEvent(QGraphicsSceneDragDropEvent * event);
	void dragMoveEvent(QGraphicsSceneDragDropEvent * event);
	void drawBackground(QPainter * painter, const QRectF & rect);
	void drawForeground(QPainter * painter, const QRectF & rect);
	void drawItems(QPainter * painter, int numItems, QGraphicsItem * items[], const QStyleOptionGraphicsItem options[], QWidget * widget = 0);
	void dropEvent(QGraphicsSceneDragDropEvent * event);
	void focusInEvent(QFocusEvent * focusEvent);
	void focusOutEvent(QFocusEvent * focusEvent);
	void helpEvent(QGraphicsSceneHelpEvent * helpEvent);
	void inputMethodEvent(QInputMethodEvent * event);
	void keyPressEvent(QKeyEvent * keyEvent);
	void keyReleaseEvent(QKeyEvent * keyEvent);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent);
	void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
	void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
	void wheelEvent(QGraphicsSceneWheelEvent * wheelEvent);
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQGraphicsEventItem
{
public:
	MaxQGraphicsEventItem() {};

	virtual void defaultContextMenuEvent(QGraphicsSceneContextMenuEvent * contextMenuEvent) {};
	virtual void defaultDragEnterEvent(QGraphicsSceneDragDropEvent * event) {};
	virtual void defaultDragLeaveEvent(QGraphicsSceneDragDropEvent * event) {};
	virtual void defaultDragMoveEvent(QGraphicsSceneDragDropEvent * event) {};
	virtual void defaultDropEvent(QGraphicsSceneDragDropEvent * event) {};
	virtual void defaultFocusInEvent(QFocusEvent * focusEvent) {};
	virtual void defaultFocusOutEvent(QFocusEvent * focusEvent) {};
	virtual void defaultHoverEnterEvent(QGraphicsSceneHoverEvent * hoverEvent) {};
	virtual void defaultHoverLeaveEvent(QGraphicsSceneHoverEvent * hoverEvent) {};
	virtual void defaultHoverMoveEvent(QGraphicsSceneHoverEvent * hoverEvent) {};
	virtual void defaultInputMethodEvent(QInputMethodEvent * event) {};
	virtual void defaultKeyPressEvent(QKeyEvent * keyEvent) {};
	virtual void defaultKeyReleaseEvent(QKeyEvent * keyEvent) {};
	virtual void defaultMouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent) {};
	virtual void defaultMouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent) {};
	virtual void defaultMousePressEvent(QGraphicsSceneMouseEvent * mouseEvent) {};
	virtual void defaultMouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent) {};
	virtual void defaultSceneEvent(QEvent * event) {};
	virtual void defaultSceneEventFilter(QGraphicsItem * watched, QEvent * event) {};
	virtual void defaultWheelEvent(QGraphicsSceneWheelEvent * wheelEvent) {};
	
};


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQGraphicsItem : public QGraphicsItem, MaxQGraphicsEventItem
{
public:

	MaxQGraphicsItem(BBObject * handle, QGraphicsItem * parent);
	~MaxQGraphicsItem();
	
	QRectF boundingRect () const;
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );

	virtual void defaultContextMenuEvent(QGraphicsSceneContextMenuEvent * contextMenuEvent);
	virtual void defaultDragEnterEvent(QGraphicsSceneDragDropEvent * event);
	virtual void defaultDragLeaveEvent(QGraphicsSceneDragDropEvent * event);
	virtual void defaultDragMoveEvent(QGraphicsSceneDragDropEvent * event);
	virtual void defaultDropEvent(QGraphicsSceneDragDropEvent * event);
	virtual void defaultFocusInEvent(QFocusEvent * focusEvent);
	virtual void defaultFocusOutEvent(QFocusEvent * focusEvent);
	virtual void defaultHoverEnterEvent(QGraphicsSceneHoverEvent * hoverEvent);
	virtual void defaultHoverLeaveEvent(QGraphicsSceneHoverEvent * hoverEvent);
	virtual void defaultHoverMoveEvent(QGraphicsSceneHoverEvent * hoverEvent);
	virtual void defaultInputMethodEvent(QInputMethodEvent * event);
	virtual void defaultKeyPressEvent(QKeyEvent * keyEvent);
	virtual void defaultKeyReleaseEvent(QKeyEvent * keyEvent);
	virtual void defaultMouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void defaultMouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void defaultMousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void defaultMouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void defaultSceneEvent(QEvent * event);
	virtual void defaultSceneEventFilter(QGraphicsItem * watched, QEvent * event);
	virtual void defaultWheelEvent(QGraphicsSceneWheelEvent * wheelEvent);

	void DoPrepareGeometryChange() {
		prepareGeometryChange();
	}
	
private:
	BBObject * maxHandle;
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQGraphicsItemList
{
public:
	MaxQGraphicsItemList(const QList<QGraphicsItem *> & l);
	~MaxQGraphicsItemList();
	void Reset();
	int HasNext();
	QGraphicsItem * NextObject();
	int Size();

private:
	QList<QGraphicsItem *> list;
	QList<QGraphicsItem *>::iterator iter;
};


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQGraphicsPixmapItem : public QGraphicsPixmapItem, MaxQGraphicsEventItem, QObject
{
public:
	MaxQGraphicsPixmapItem(BBObject * handle, const QPixmap & pixmap, QGraphicsItem * parent);
	~MaxQGraphicsPixmapItem();

	virtual void defaultContextMenuEvent(QGraphicsSceneContextMenuEvent * contextMenuEvent);
	virtual void defaultDragEnterEvent(QGraphicsSceneDragDropEvent * event);
	virtual void defaultDragLeaveEvent(QGraphicsSceneDragDropEvent * event);
	virtual void defaultDragMoveEvent(QGraphicsSceneDragDropEvent * event);
	virtual void defaultDropEvent(QGraphicsSceneDragDropEvent * event);
	virtual void defaultFocusInEvent(QFocusEvent * focusEvent);
	virtual void defaultFocusOutEvent(QFocusEvent * focusEvent);
	virtual void defaultHoverEnterEvent(QGraphicsSceneHoverEvent * hoverEvent);
	virtual void defaultHoverLeaveEvent(QGraphicsSceneHoverEvent * hoverEvent);
	virtual void defaultHoverMoveEvent(QGraphicsSceneHoverEvent * hoverEvent);
	virtual void defaultInputMethodEvent(QInputMethodEvent * event);
	virtual void defaultKeyPressEvent(QKeyEvent * keyEvent);
	virtual void defaultKeyReleaseEvent(QKeyEvent * keyEvent);
	virtual void defaultMouseDoubleClickEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void defaultMouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void defaultMousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void defaultMouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
	virtual void defaultSceneEvent(QEvent * event);
	virtual void defaultSceneEventFilter(QGraphicsItem * watched, QEvent * event);
	virtual void defaultWheelEvent(QGraphicsSceneWheelEvent * wheelEvent);

private:
	BBObject * maxHandle;
};

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#endif
