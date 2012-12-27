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

MaxQStandardItemModel::MaxQStandardItemModel(BBObject * handle, QObject * parent)
	: maxHandle(handle), QStandardItemModel(parent)
{
	qbind(this, handle);
	
	connect(this, SIGNAL(itemChanged(QStandardItem *)), SLOT(onItemChanged(QStandardItem *)));

	connect(this, SIGNAL(columnsAboutToBeInserted(const QModelIndex &, int, int)), SLOT(onColumnsAboutToBeInserted(const QModelIndex &, int, int)));
	connect(this, SIGNAL(columnsAboutToBeMoved(const QModelIndex &, int, int, const QModelIndex &, int)), SLOT(onColumnsAboutToBeMoved(const QModelIndex &, int, int, const QModelIndex &, int)));
	connect(this, SIGNAL(columnsAboutToBeRemoved(const QModelIndex &, int, int)), SLOT(onColumnsAboutToBeRemoved(const QModelIndex &, int, int)));
	connect(this, SIGNAL(columnsInserted(const QModelIndex &, int, int)), SLOT(onColumnsInserted(const QModelIndex &, int, int)));
	connect(this, SIGNAL(columnsMoved(const QModelIndex &, int, int, const QModelIndex &, int)), SLOT(onColumnsMoved(const QModelIndex &, int, int, const QModelIndex &, int)));
	connect(this, SIGNAL(columnsRemoved(const QModelIndex &, int, int)), SLOT(onColumnsRemoved(const QModelIndex &, int, int)));
	connect(this, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), SLOT(onDataChanged(const QModelIndex &, const QModelIndex &)));
	connect(this, SIGNAL(headerDataChanged(Qt::Orientation, int, int)), SLOT(onHeaderDataChanged(Qt::Orientation, int, int)));
	connect(this, SIGNAL(layoutAboutToBeChanged()), SLOT(onLayoutAboutToBeChanged()));
	connect(this, SIGNAL(layoutChanged()), SLOT(onLayoutChanged()));
	connect(this, SIGNAL(modelAboutToBeReset()), SLOT(onModelAboutToBeReset()));
	connect(this, SIGNAL(modelReset()), SLOT(onModelReset()));
	connect(this, SIGNAL(rowsAboutToBeInserted(const QModelIndex &, int, int)), SLOT(onRowsAboutToBeInserted(const QModelIndex &, int, int)));
	connect(this, SIGNAL(rowsAboutToBeMoved(const QModelIndex &, int, int, const QModelIndex &, int)), SLOT(onRowsAboutToBeMoved(const QModelIndex &, int, int, const QModelIndex &, int)));
	connect(this, SIGNAL(rowsAboutToBeRemoved(const QModelIndex &, int, int)), SLOT(onRowsAboutToBeRemoved(const QModelIndex &, int, int)));
	connect(this, SIGNAL(rowsInserted(const QModelIndex &, int, int)), SLOT(onRowsInserted(const QModelIndex &, int, int)));
	connect(this, SIGNAL(rowsMoved(const QModelIndex &, int, int, const QModelIndex &, int)), SLOT(onRowsMoved(const QModelIndex &, int, int, const QModelIndex &, int)));
	connect(this, SIGNAL(rowsRemoved(const QModelIndex &, int, int)), SLOT(onRowsRemoved(const QModelIndex &, int, int)));

}

MaxQStandardItemModel::~MaxQStandardItemModel()
{
	qunbind(this);
}

// ********************  SLOTS ****************************

void MaxQStandardItemModel::onItemChanged(QStandardItem * item) {
	
}

void MaxQStandardItemModel::onColumnsAboutToBeInserted(const QModelIndex & parent, int start, int end) {
	
}

void MaxQStandardItemModel::onColumnsAboutToBeMoved(const QModelIndex & sourceParent, int sourceStart, int sourceEnd, const QModelIndex & destinationParent, int destinationColumn) {
	
}

void MaxQStandardItemModel::onColumnsAboutToBeRemoved(const QModelIndex & parent, int start, int end) {
	
}

void MaxQStandardItemModel::onColumnsInserted(const QModelIndex & parent, int start, int end) {
	
}

void MaxQStandardItemModel::onColumnsMoved(const QModelIndex & sourceParent, int sourceStart, int sourceEnd, const QModelIndex & destinationParent, int destinationColumn) {
	
}

void MaxQStandardItemModel::onColumnsRemoved(const QModelIndex & parent, int start, int end) {
	
}

void MaxQStandardItemModel::onDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight) {
	
}

void MaxQStandardItemModel::onHeaderDataChanged(Qt::Orientation orientation, int first, int last) {
	
}

void MaxQStandardItemModel::onLayoutAboutToBeChanged() {
	
}

void MaxQStandardItemModel::onLayoutChanged() {
	
}

void MaxQStandardItemModel::onModelAboutToBeReset() {
	
}

void MaxQStandardItemModel::oModelReset() {
	
}

void MaxQStandardItemModel::onRowsAboutToBeInserted(const QModelIndex & parent, int start, int end) {
	
}

void MaxQStandardItemModel::onRowsAboutToBeMoved(const QModelIndex & sourceParent, int sourceStart, int sourceEnd, const QModelIndex & destinationParent, int destinationRow) {
	
}

void MaxQStandardItemModel::onRowsAboutToBeRemoved(const QModelIndex & parent, int start, int end) {
	
}

void MaxQStandardItemModel::onRowsInserted(const QModelIndex & parent, int start, int end) {
	
}

void MaxQStandardItemModel::onRowsMoved(const QModelIndex & sourceParent, int sourceStart, int sourceEnd, const QModelIndex & destinationParent, int destinationRow) {
	
}

void MaxQStandardItemModel::onRowsRemoved(const QModelIndex & parent, int start, int end) {
	
}


// *********************************************



// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
