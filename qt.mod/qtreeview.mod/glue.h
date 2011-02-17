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

#ifndef MAX_QT_QTREEVIEW
#define MAX_QT_QTREEVIEW

#include "../core.mod/glue.h"
#include "../qabstractitemmodel.mod/glue.h"
#include <QtCore>
#include <QTreeView>

class MaxQTreeView;

extern "C" {

#include <blitz.h>

	QTreeView * bmx_qt_qtreeview_create(BBObject * handle, QWidget * parent);
	int bmx_qt_qtreeview_allcolumnsshowfocus(QTreeView * tv);
	int bmx_qt_qtreeview_autoexpanddelay(QTreeView * tv);
	int bmx_qt_qtreeview_columnat(QTreeView * tv, int x);
	int bmx_qt_qtreeview_columnviewportposition(QTreeView * tv, int column);
	int bmx_qt_qtreeview_columnwidth(QTreeView * tv, int column);
	int bmx_qt_qtreeview_expandsondoubleclick(QTreeView * tv);
	QHeaderView * bmx_qt_qtreeview_header(QTreeView * tv);
	int bmx_qt_qtreeview_indentation(QTreeView * tv);
	MaxQModelIndex * bmx_qt_qtreeview_indexabove(QTreeView * tv, MaxQModelIndex * index);
	MaxQModelIndex * bmx_qt_qtreeview_indexbelow(QTreeView * tv, MaxQModelIndex * index);
	int bmx_qt_qtreeview_isanimated(QTreeView * tv);
	int bmx_qt_qtreeview_iscolumnhidden(QTreeView * tv, int column);
	int bmx_qt_qtreeview_isexpanded(QTreeView * tv, MaxQModelIndex * index);
	int bmx_qt_qtreeview_isfirstcolumnspanned(QTreeView * tv, int row, MaxQModelIndex * parent);
	int bmx_qt_qtreeview_isheaderhidden(QTreeView * tv);
	int bmx_qt_qtreeview_isrowhidden(QTreeView * tv, int row, MaxQModelIndex * parent);
	int bmx_qt_qtreeview_issortingenabled(QTreeView * tv);
	int bmx_qt_qtreeview_itemsexpandable(QTreeView * tv);
	int bmx_qt_qtreeview_rootisdecorated(QTreeView * tv);
	void bmx_qt_qtreeview_setallcolumnsshowfocus(QTreeView * tv, int enable);
	void bmx_qt_qtreeview_setanimated(QTreeView * tv, int enable);
	void bmx_qt_qtreeview_setautoexpanddelay(QTreeView * tv, int _delay);
	void bmx_qt_qtreeview_setcolumnhidden(QTreeView * tv, int column, int hide);
	void bmx_qt_qtreeview_setcolumnwidth(QTreeView * tv, int column, int width);
	void bmx_qt_qtreeview_setexpanded(QTreeView * tv, MaxQModelIndex * index, int expanded);
	void bmx_qt_qtreeview_setexpandsondoubleclick(QTreeView * tv, int enable);
	void bmx_qt_qtreeview_setfirstcolumnspanned(QTreeView * tv, int row, MaxQModelIndex * parent, int span);
	void bmx_qt_qtreeview_setheader(QTreeView * tv, QHeaderView * header);
	void bmx_qt_qtreeview_setheaderhidden(QTreeView * tv, int hide);
	void bmx_qt_qtreeview_setindentation(QTreeView * tv, int i);
	void bmx_qt_qtreeview_setitemsexpandable(QTreeView * tv, int enable);
	void bmx_qt_qtreeview_setrootisdecorated(QTreeView * tv, int show);
	void bmx_qt_qtreeview_setrowhidden(QTreeView * tv, int row, MaxQModelIndex * parent, int hide);
	void bmx_qt_qtreeview_setsortingenabled(QTreeView * tv, int enable);
	void bmx_qt_qtreeview_setuniformrowheights(QTreeView * tv, int uniform);
	void bmx_qt_qtreeview_setwordwrap(QTreeView * tv, int on);
	void bmx_qt_qtreeview_sortbycolumn(QTreeView * tv, int column, int order);
	int bmx_qt_qtreeview_uniformrowheights(QTreeView * tv);
	int bmx_qt_qtreeview_wordwrap(QTreeView * tv);

	void bmx_qt_qtreeview_collapse(QTreeView * tv, MaxQModelIndex * index);
	void bmx_qt_qtreeview_collapseall(QTreeView * tv);
	void bmx_qt_qtreeview_expand(QTreeView * tv, MaxQModelIndex * index);
	void bmx_qt_qtreeview_expandall(QTreeView * tv);
	void bmx_qt_qtreeview_expandtodepth(QTreeView * tv, int depth);
	void bmx_qt_qtreeview_hidecolumn(QTreeView * tv, int column);
	void bmx_qt_qtreeview_resizecolumntocontents(QTreeView * tv, int column);
	void bmx_qt_qtreeview_showcolumn(QTreeView * tv, int column);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQTreeView : public QTreeView
{
	Q_OBJECT
	
public:
	MaxQTreeView(BBObject * handle, QWidget * parent);
	~MaxQTreeView();

private:
	BBObject * maxHandle;

private slots:
	void onCcollapsed(const QModelIndex & index);
	void onExpanded(const QModelIndex & index);
	void onActivated(const QModelIndex & index);
	void onClicked(const QModelIndex & index);
	void onDoubleClicked(const QModelIndex & index);
	void onEntered(const QModelIndex & index);
	void onPressed(const QModelIndex & index);
	void onViewportEntered();
	void onCustomContextMenuRequested(const QPoint & pos);
};

#endif
