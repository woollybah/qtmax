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

MaxQGridLayout::MaxQGridLayout(BBObject * handle)
	: maxHandle(handle)
{
	qbind(this, handle);
}

MaxQGridLayout::MaxQGridLayout(BBObject * handle, QWidget * parent)
	: maxHandle(handle), QGridLayout(parent)
{
	qbind(this, handle);
}

MaxQGridLayout::~MaxQGridLayout()
{
	qunbind(this);
}


// *********************************************

QGridLayout * bmx_qt_qgridlayout_create(BBObject * handle, QWidget * parent) {
	if (parent) {
		return new MaxQGridLayout(handle, parent);
	} else {
		return new MaxQGridLayout(handle);
	}
}

void bmx_qt_qgridlayout_addlayout(QGridLayout * grid, QLayout * layout, int row, int column, int alignment) {
	grid->addLayout(layout, row, column, bmx_qt_getalignment(alignment));
}

void bmx_qt_qgridlayout_addwidget(QGridLayout * grid, QWidget * widget, int row, int column, int alignment) {
	grid->addWidget(widget, row, column, bmx_qt_getalignment(alignment));
}

void bmx_qt_qgridlayout_addwidgetspan(QGridLayout * grid, QWidget * widget, int fromRow, int fromColumn,  int rowSpan, int columnSpan, int alignment) {
	grid->addWidget(widget, fromRow, fromColumn, rowSpan, columnSpan, bmx_qt_getalignment(alignment));
}

MaxQRect * bmx_qt_qgridlayout_cellrect(QGridLayout * layout, int row, int column) {
	return new MaxQRect(layout->cellRect(row, column));
}

int bmx_qt_qgridlayout_columncount(QGridLayout * layout) {
	return layout->columnCount();
}

int bmx_qt_qgridlayout_columnminimumwidth(QGridLayout * layout, int column) {
	return layout->columnMinimumWidth(column);
}

int bmx_qt_qgridlayout_columnstretch(QGridLayout * layout, int column) {
	return layout->columnStretch(column);
}

void bmx_qt_qgridlayout_getitemposition(QGridLayout * layout, int index, int * row, int * column, int * rowSpan, int * columnSpan) {
	layout->getItemPosition(index, row, column, rowSpan, columnSpan);
}

int bmx_qt_qgridlayout_horizontalspacing(QGridLayout * layout) {
	return layout->horizontalSpacing();
}

QLayoutItem * bmx_qt_qgridlayout_itematposition(QGridLayout * layout, int row, int column) {
	return layout->itemAtPosition(row, column);
}

int bmx_qt_qgridlayout_origincorner(QGridLayout * layout) {
	return layout->originCorner();
}

int bmx_qt_qgridlayout_rowcount(QGridLayout * layout) {
	return layout->rowCount();
}

int bmx_qt_qgridlayout_rowminimumheight(QGridLayout * layout, int row) {
	return layout->rowMinimumHeight(row);
}

int bmx_qt_qgridlayout_rowstretch(QGridLayout * layout, int row) {
	return layout->rowStretch(row);
}

void bmx_qt_qgridlayout_setcolumnminimumwidth(QGridLayout * layout, int column, int minSize) {
	layout->setColumnMinimumWidth(column, minSize);
}

void bmx_qt_qgridlayout_setcolumnstretch(QGridLayout * layout, int column, int stretch) {
	layout->setColumnStretch(column, stretch);
}

void bmx_qt_qgridlayout_sethorizontalspacing(QGridLayout * layout, int spacing) {
	layout->setHorizontalSpacing(spacing);
}

void bmx_qt_qgridlayout_setorigincorner(QGridLayout * layout, int corner) {
	layout->setOriginCorner((Qt::Corner)corner);
}

void bmx_qt_qgridlayout_setrowminimumheight(QGridLayout * layout, int row, int minSize) {
	layout->setRowMinimumHeight(row, minSize);
}

void bmx_qt_qgridlayout_setrowstretch(QGridLayout * layout, int row, int stretch) {
	layout->setRowStretch(row, stretch);
}

void bmx_qt_qgridlayout_setspacing(QGridLayout * layout, int spacing) {
	layout->setSpacing(spacing);
}

void bmx_qt_qgridlayout_setverticalspacing(QGridLayout * layout, int spacing) {
	layout->setVerticalSpacing(spacing);
}

int bmx_qt_qgridlayout_spacing(QGridLayout * layout) {
	return layout->spacing();
}

int bmx_qt_qgridlayout_verticalspacing(QGridLayout * layout) {
	return layout->verticalSpacing();
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
