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

#ifndef MAX_QT_QTOOLBAR
#define MAX_QT_QTOOLBAR

#include "../core.mod/glue.h"
#include "../qwidget.mod/glue.h"
#include <QtCore>
#include <QToolBar>

class MaxQToolBar;

extern "C" {

#include <blitz.h>

	BBObject * _qt_qtoolbar_QToolBar___create(QToolBar * toolbar);
	void _qt_qtoolbar_QToolBar__OnActionTriggered(BBObject * handle, QAction * action);
	void _qt_qtoolbar_QToolBar__OnAllowedAreasChanged(BBObject * handle, int allowedAreas);
	void _qt_qtoolbar_QToolBar__OnIconSizeChanged(BBObject * handle,int width, int height);
	void _qt_qtoolbar_QToolBar__OnMovableChanged(BBObject * handle, int movable);
	void _qt_qtoolbar_QToolBar__OnOrientationChanged(BBObject * handle, int orientation);
	void _qt_qtoolbar_QToolBar__OnToolButtonStyleChanged(BBObject * handle, int toolButtonStyle);
	void _qt_qtoolbar_QToolBar__OnTopLevelChanged(BBObject * handle, int topLevel);
	void _qt_qtoolbar_QToolBar__OnVisibilityChanged(BBObject * handle, int visible);

	QToolBar * bmx_qt_qtoolbar_create(BBObject * handle, QWidget * parent);
	void bmx_qt_qtoolbar_addwidget(QToolBar * tb, QWidget * widget);
	int bmx_qt_qtoolbar_allowedareas(QToolBar * tb);
	void bmx_qt_qtoolbar_clear(QToolBar * tb);
	void bmx_qt_qtoolbar_iconsize(QToolBar * tb, int * w, int * h);
	int bmx_qt_qtoolbar_isareaallowed(QToolBar * tb, int area);
	int bmx_qt_qtoolbar_isfloatable(QToolBar * tb);
	int bmx_qt_qtoolbar_isfloating(QToolBar * tb);
	int bmx_qt_qtoolbar_ismovable(QToolBar * tb);
	int bmx_qt_qtoolbar_orientation(QToolBar * tb);
	void bmx_qt_qtoolbar_setallowedareas(QToolBar * tb, int areas);
	void bmx_qt_qtoolbar_setfloatable(QToolBar * tb, int floatable);
	void bmx_qt_qtoolbar_setmovable(QToolBar * tb, int movable);
	void bmx_qt_qtoolbar_setorientation(QToolBar * tb, int orientation);
	int bmx_qt_qtoolbar_toolbuttonstyle(QToolBar * tb);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQToolBar : public MaxQObjectWrapper
{
	Q_OBJECT

public:
	MaxQToolBar(BBObject * handle, QToolBar * tb);
	MaxQToolBar(QToolBar * tb);

	QToolBar * ToolBar();
	
	static void link(QToolBar * t);
	
	~MaxQToolBar();

private:
	void doConnections();
	QToolBar * toolBar;

private slots:
	void onActionTriggered(QAction * action);
	void onAllowedAreasChanged(Qt::ToolBarAreas allowedAreas);
	void onIconSizeChanged(const QSize & iconSize);
	void onMovableChanged(bool movable);
	void onOrientationChanged(Qt::Orientation orientation);
	void onToolButtonStyleChanged(Qt::ToolButtonStyle toolButtonStyle);
	void onTopLevelChanged(bool topLevel);
	void onVisibilityChanged(bool visible);
	void onCustomContextMenuRequested(const QPoint & pos);
	
};

#endif
