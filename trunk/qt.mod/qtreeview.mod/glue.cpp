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

MaxQTreeView::MaxQTreeView(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QTreeView(parent)
{
	qbind(this, handle);
}

MaxQTreeView::~MaxQTreeView()
{
	qunbind(this);
}

void MaxQTreeView::onCcollapsed(const QModelIndex & index) {

}

void MaxQTreeView::onExpanded(const QModelIndex & index) {

}

void MaxQTreeView::onActivated(const QModelIndex & index) {

}

void MaxQTreeView::onClicked(const QModelIndex & index) {

}

void MaxQTreeView::onDoubleClicked(const QModelIndex & index) {

}

void MaxQTreeView::onEntered(const QModelIndex & index) {

}

void MaxQTreeView::onPressed(const QModelIndex & index) {

}

void MaxQTreeView::onViewportEntered() {

}

void MaxQTreeView::onCustomContextMenuRequested(const QPoint & pos) {

}


// *********************************************

QTreeView * bmx_qt_qtreeview_create(BBObject * handle, QWidget * parent) {
	return new MaxQTreeView(handle, parent);
}

int bmx_qt_qtreeview_allcolumnsshowfocus(QTreeView * tv) {
	return static_cast<int>(tv->allColumnsShowFocus());
}

int bmx_qt_qtreeview_autoexpanddelay(QTreeView * tv) {
	return tv->autoExpandDelay();
}

int bmx_qt_qtreeview_columnat(QTreeView * tv, int x) {
	return tv->columnAt(x);
}

int bmx_qt_qtreeview_columnviewportposition(QTreeView * tv, int column) {
	return tv->columnViewportPosition(column);
}

int bmx_qt_qtreeview_columnwidth(QTreeView * tv, int column) {
	return tv->columnWidth(column);
}

int bmx_qt_qtreeview_expandsondoubleclick(QTreeView * tv) {
	return static_cast<int>(tv->expandsOnDoubleClick());
}

QHeaderView * bmx_qt_qtreeview_header(QTreeView * tv) {
	return tv->header();
}

int bmx_qt_qtreeview_indentation(QTreeView * tv) {
	return tv->indentation();
}

MaxQModelIndex * bmx_qt_qtreeview_indexabove(QTreeView * tv, MaxQModelIndex * index) {
	return new MaxQModelIndex(tv->indexAbove(index->Index()));
}

MaxQModelIndex * bmx_qt_qtreeview_indexbelow(QTreeView * tv, MaxQModelIndex * index) {
	return new MaxQModelIndex(tv->indexBelow(index->Index()));
}

int bmx_qt_qtreeview_isanimated(QTreeView * tv) {
	return static_cast<int>(tv->isAnimated());
}

int bmx_qt_qtreeview_iscolumnhidden(QTreeView * tv, int column) {
	return static_cast<int>(tv->isColumnHidden(column));
}

int bmx_qt_qtreeview_isexpanded(QTreeView * tv, MaxQModelIndex * index) {
	return static_cast<int>(tv->isExpanded(index->Index()));
}

int bmx_qt_qtreeview_isfirstcolumnspanned(QTreeView * tv, int row, MaxQModelIndex * parent) {
	return static_cast<int>(tv->isFirstColumnSpanned(row, parent->Index()));
}

int bmx_qt_qtreeview_isheaderhidden(QTreeView * tv) {
	return static_cast<int>(tv->isHeaderHidden());
}

int bmx_qt_qtreeview_isrowhidden(QTreeView * tv, int row, MaxQModelIndex * parent) {
	return static_cast<int>(tv->isRowHidden(row, parent->Index()));
}

int bmx_qt_qtreeview_issortingenabled(QTreeView * tv) {
	return static_cast<int>(tv->isSortingEnabled());
}

int bmx_qt_qtreeview_itemsexpandable(QTreeView * tv) {
	return static_cast<int>(tv->itemsExpandable());
}

int bmx_qt_qtreeview_rootisdecorated(QTreeView * tv) {
	return static_cast<int>(tv->rootIsDecorated());
}

void bmx_qt_qtreeview_setallcolumnsshowfocus(QTreeView * tv, int enable) {
	tv->setAllColumnsShowFocus(static_cast<bool>(enable));
}

void bmx_qt_qtreeview_setanimated(QTreeView * tv, int enable) {
	tv->setAnimated(static_cast<bool>(enable));
}

void bmx_qt_qtreeview_setautoexpanddelay(QTreeView * tv, int _delay) {
	tv->setAutoExpandDelay(_delay);
}

void bmx_qt_qtreeview_setcolumnhidden(QTreeView * tv, int column, int hide) {
	tv->setColumnHidden(column, static_cast<bool>(hide));
}

void bmx_qt_qtreeview_setcolumnwidth(QTreeView * tv, int column, int width) {
	tv->setColumnWidth(column, width);
}

void bmx_qt_qtreeview_setexpanded(QTreeView * tv, MaxQModelIndex * index, int expanded) {
	tv->setExpanded(index->Index(), static_cast<bool>(expanded));
}

void bmx_qt_qtreeview_setexpandsondoubleclick(QTreeView * tv, int enable) {
	tv->setExpandsOnDoubleClick(static_cast<bool>(enable));
}

void bmx_qt_qtreeview_setfirstcolumnspanned(QTreeView * tv, int row, MaxQModelIndex * parent, int span) {
	tv->setFirstColumnSpanned(row, parent->Index(), static_cast<bool>(span));
}

void bmx_qt_qtreeview_setheader(QTreeView * tv, QHeaderView * header) {
	tv->setHeader(header);
}

void bmx_qt_qtreeview_setheaderhidden(QTreeView * tv, int hide) {
	tv->setHeaderHidden(static_cast<bool>(hide));
}

void bmx_qt_qtreeview_setindentation(QTreeView * tv, int i) {
	tv->setIndentation(i);
}

void bmx_qt_qtreeview_setitemsexpandable(QTreeView * tv, int enable) {
	tv->setItemsExpandable(static_cast<bool>(enable));
}

void bmx_qt_qtreeview_setrootisdecorated(QTreeView * tv, int show) {
	tv->setRootIsDecorated(static_cast<bool>(show));
}

void bmx_qt_qtreeview_setrowhidden(QTreeView * tv, int row, MaxQModelIndex * parent, int hide) {
	tv->setRowHidden(row, parent->Index(), static_cast<bool>(hide));
}

void bmx_qt_qtreeview_setsortingenabled(QTreeView * tv, int enable) {
	tv->setSortingEnabled(static_cast<bool>(enable));
}

void bmx_qt_qtreeview_setuniformrowheights(QTreeView * tv, int uniform) {
	tv->setUniformRowHeights(static_cast<bool>(uniform));
}

void bmx_qt_qtreeview_setwordwrap(QTreeView * tv, int on) {
	tv->setWordWrap(static_cast<bool>(on));
}

void bmx_qt_qtreeview_sortbycolumn(QTreeView * tv, int column, int order) {
	tv->sortByColumn(column, (Qt::SortOrder)order);
}

int bmx_qt_qtreeview_uniformrowheights(QTreeView * tv) {
	return static_cast<int>(tv->uniformRowHeights());
}

int bmx_qt_qtreeview_wordwrap(QTreeView * tv) {
	return static_cast<int>(tv->wordWrap());
}


void bmx_qt_qtreeview_collapse(QTreeView * tv, MaxQModelIndex * index) {
	tv->collapse(index->Index());
}

void bmx_qt_qtreeview_collapseall(QTreeView * tv) {
	tv->collapseAll();
}

void bmx_qt_qtreeview_expand(QTreeView * tv, MaxQModelIndex * index) {
	tv->expand(index->Index());
}

void bmx_qt_qtreeview_expandall(QTreeView * tv) {
	tv->expandAll();
}

void bmx_qt_qtreeview_expandtodepth(QTreeView * tv, int depth) {
	tv->expandToDepth(depth);
}

void bmx_qt_qtreeview_hidecolumn(QTreeView * tv, int column) {
	tv->hideColumn(column);
}

void bmx_qt_qtreeview_resizecolumntocontents(QTreeView * tv, int column) {
	tv->resizeColumnToContents(column);
}

void bmx_qt_qtreeview_showcolumn(QTreeView * tv, int column) {
	tv->showColumn(column);
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
