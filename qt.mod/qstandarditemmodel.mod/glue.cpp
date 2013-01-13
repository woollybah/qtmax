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

#include "glue.h"

// ---------------------------------------------------------------------------------------

MaxQStandardItemModel::MaxQStandardItemModel(BBObject * handle, QObject * parent)
	: maxHandle(handle), QAbstractItemModel(parent)
{
	qbind(this, handle);
	
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

int	MaxQStandardItemModel::columnCount(const QModelIndex & parent) const {
	return _qt_qstandarditemmodel_QStandardItemModel__columnCount(maxHandle, new MaxQModelIndex(parent));
}

QVariant MaxQStandardItemModel::data(const QModelIndex & index, int role) const {
//printf("MaxQStandardItemModel::data - %d\n", role);fflush(stdout);

	role = (role == Qt::EditRole) ? Qt::DisplayRole : role;

	switch(role) {
		case Qt::DisplayRole:
		case Qt::EditRole:
		case Qt::ToolTipRole:
		case Qt::StatusTipRole:
		case Qt::WhatsThisRole:
			{
				BBString * text = _qt_qstandarditemmodel_QStandardItemModel__getDataString(maxHandle, new MaxQModelIndex(index), role);
				if (text != &bbEmptyString) {
					return QVariant(qStringFromBBString(text));
				} else {
					return QVariant();
				} 
			}
		case Qt::TextAlignmentRole:
		case Qt::CheckStateRole:
		case Qt::InitialSortOrderRole:
			{
				int value = _qt_qstandarditemmodel_QStandardItemModel__getDataInt(maxHandle, new MaxQModelIndex(index), role);
				if (value >= 0) {
					return QVariant(value);
				} else {
					return QVariant();
				}
			}
		case Qt::UserRole:
			{
				BBObject * obj = _qt_qstandarditemmodel_QStandardItemModel__getDataObject(maxHandle, new MaxQModelIndex(index), role);
				if (obj != &bbNullObject) {
					QVariant v = QVariant::fromValue<void*>(obj);
					return v;
				} else {
					return QVariant();
				} 
			}
		case Qt::DecorationRole:
		case Qt::BackgroundRole:
		case Qt::ForegroundRole:
		case Qt::FontRole:
			{
				int type = 0;
				void * data = _qt_qstandarditemmodel_QStandardItemModel__getDataType(maxHandle, new MaxQModelIndex(index), role, &type);
				if (data) {
					switch (type) {
						case QVariant::Color:
							return QVariant(((MaxQColor*)data)->Color());
						case QVariant::Icon:
							return QVariant(((MaxQIcon*)data)->Icon());
						case QVariant::Pixmap:
							return QVariant(((MaxQPixmap*)data)->Pixmap());
						case QVariant::Brush:
							return QVariant(((MaxQBrush*)data)->Brush());
						case QVariant::Font:
							return QVariant(((MaxQFont*)data)->Font());
					}
				}
				return QVariant();
			}
	}
	
	return QVariant();
}

QModelIndex	MaxQStandardItemModel::parent(const QModelIndex & child) const {
//printf("MaxQStandardItemModel::parent\n");fflush(stdout);
	if (child.row() < 0 || child.column() < 0) {
		return QModelIndex();
	}
	
	MaxQStandardItem * parentItem = static_cast<MaxQStandardItem*>(child.internalPointer());
	MaxQModelIndex * index = _qt_qstandarditemmodel_QStandardItemModel__indexFromItem(maxHandle, parentItem->handle());
	if (index) {
		return index->Index();
	} else {
		return QModelIndex();
	}
}

int	MaxQStandardItemModel::rowCount(const QModelIndex & parent) const {
	return _qt_qstandarditemmodel_QStandardItemModel__rowCount(maxHandle, new MaxQModelIndex(parent));
}

QModelIndex MaxQStandardItemModel::index(int row, int column, const QModelIndex &parent) const {
//printf("MaxQStandardItemModel::index : %d, %d\n", row, column);fflush(stdout);
	MaxQStandardItem * item = _qt_qstandarditemmodel_QStandardItemModel__itemFromIndex(maxHandle, new MaxQModelIndex(parent));

	if ((item == 0) || (row < 0) || (column < 0) || (row >= item->rowCount()) || (column >= item->columnCount())) {
		return QModelIndex();
	} else {
		return createIndex(row, column, item);
	}
}

QModelIndex MaxQStandardItemModel::doCreateIndex(int row, int col, MaxQStandardItem * parent) {
	return createIndex(row, col, parent);
}

bool MaxQStandardItemModel::setData(const QModelIndex & index, const QVariant & value, int role) {
//printf("MaxQStandardItemModel::setData : %d\n", role);fflush(stdout);
	if (!index.isValid()) {
		return false;
	}
	
	role = (role == Qt::EditRole) ? Qt::DisplayRole : role;
	
	switch(role) {
		case Qt::DisplayRole:
		case Qt::EditRole:
		case Qt::ToolTipRole:
		case Qt::StatusTipRole:
		case Qt::WhatsThisRole:
			return static_cast<bool>(_qt_qstandarditemmodel_QStandardItemModel__setDataString(maxHandle, new MaxQModelIndex(index), role, bbStringFromQString(value.toString()))); 
		case Qt::TextAlignmentRole:
		case Qt::CheckStateRole:
		case Qt::InitialSortOrderRole:
			return static_cast<bool>(_qt_qstandarditemmodel_QStandardItemModel__setDataInt(maxHandle, new MaxQModelIndex(index), role, value.toInt()));
		case Qt::UserRole:
			{
				BBObject * obj = &bbNullObject;
				
				if (value.type() != QVariant::Invalid) {
					obj = reinterpret_cast<BBObject*>(value.value<void*>());
				}
	
				return static_cast<bool>(_qt_qstandarditemmodel_QStandardItemModel__setDataObject(maxHandle, new MaxQModelIndex(index), role, obj)); 
			}
		case Qt::DecorationRole:
			{
				int type = value.type();
				switch (type) {
					case QVariant::Color:
						return static_cast<bool>(_qt_qstandarditemmodel_QStandardItemModel__setDataColor(maxHandle, new MaxQModelIndex(index), role, new MaxQColor(value.value<QColor>()))); 
					case QVariant::Icon:
						return static_cast<bool>(_qt_qstandarditemmodel_QStandardItemModel__setDataIcon(maxHandle, new MaxQModelIndex(index), role, new MaxQIcon(value.value<QIcon>()))); 
					case QVariant::Pixmap:
						return static_cast<bool>(_qt_qstandarditemmodel_QStandardItemModel__setDataPixmap(maxHandle, new MaxQModelIndex(index), role, new MaxQPixmap(value.value<QPixmap>()))); 
				}
			}
		case Qt::BackgroundRole:
		case Qt::ForegroundRole:
			return static_cast<bool>(_qt_qstandarditemmodel_QStandardItemModel__setDataBrush(maxHandle, new MaxQModelIndex(index), role, new MaxQBrush(value.value<QBrush>()))); 
		case Qt::FontRole:
			return static_cast<bool>(_qt_qstandarditemmodel_QStandardItemModel__setDataFont(maxHandle, new MaxQModelIndex(index), role, new MaxQFont(value.value<QFont>()))); 
	}
	
	return false;
}

bool MaxQStandardItemModel::insertRows(int row, int count, const QModelIndex & parent) {
//printf("MaxQStandardItemModel::insertRows\n");fflush(stdout);
	return static_cast<bool>(_qt_qstandarditemmodel_QStandardItemModel__insertRows(maxHandle, row, count, new MaxQModelIndex(parent)));
}

bool MaxQStandardItemModel::removeRows(int row, int count, const QModelIndex & parent) {
//printf("MaxQStandardItemModel:: removeRows\n");fflush(stdout);
	return static_cast<bool>(_qt_qstandarditemmodel_QStandardItemModel__removeRows(maxHandle, row, count, new MaxQModelIndex(parent)));
}


void MaxQStandardItemModel::itemChanged(const QModelIndex & index1, const QModelIndex & index2) {
	emit dataChanged(index1, index2);
}

void MaxQStandardItemModel::doBeginInsertRows(const QModelIndex & index, int row, int count) {
	beginInsertRows(index, row, count);
}

void MaxQStandardItemModel::doEndInsertRows() {
	endInsertRows();
}

void MaxQStandardItemModel::doBeginRemoveRows(const QModelIndex & index, int row, int count) {
	beginRemoveRows(index, row, count);
}

void MaxQStandardItemModel::doEndRemoveRows() {
	endRemoveRows();
}

bool MaxQStandardItemModel::hasChildren(const QModelIndex & parent) const {
	return rowCount(parent) > 0;
}

// ********************  SLOTS ****************************

void MaxQStandardItemModel::onColumnsAboutToBeInserted(const QModelIndex & parent, int start, int end) {
	_qt_qstandarditemmodel_QStandardItemModel__OnColumnsAboutToBeInserted(maxHandle, new MaxQModelIndex(parent), start, end);
}

void MaxQStandardItemModel::onColumnsAboutToBeMoved(const QModelIndex & sourceParent, int sourceStart, int sourceEnd, const QModelIndex & destinationParent, int destinationColumn) {
	_qt_qstandarditemmodel_QStandardItemModel__OnColumnsAboutToBeMoved(maxHandle, new MaxQModelIndex(sourceParent), sourceStart, sourceEnd, new MaxQModelIndex(destinationParent), destinationColumn);
}

void MaxQStandardItemModel::onColumnsAboutToBeRemoved(const QModelIndex & parent, int start, int end) {
	_qt_qstandarditemmodel_QStandardItemModel__OnColumnsAboutToBeRemoved(maxHandle, new MaxQModelIndex(parent), start, end);
}

void MaxQStandardItemModel::onColumnsInserted(const QModelIndex & parent, int start, int end) {
	_qt_qstandarditemmodel_QStandardItemModel__OnColumnsInserted(maxHandle, new MaxQModelIndex(parent), start, end);
}

void MaxQStandardItemModel::onColumnsMoved(const QModelIndex & sourceParent, int sourceStart, int sourceEnd, const QModelIndex & destinationParent, int destinationColumn) {
	_qt_qstandarditemmodel_QStandardItemModel__OnColumnsMoved(maxHandle, new MaxQModelIndex(sourceParent), sourceStart, sourceEnd, new MaxQModelIndex(destinationParent), destinationColumn);
}

void MaxQStandardItemModel::onColumnsRemoved(const QModelIndex & parent, int start, int end) {
	_qt_qstandarditemmodel_QStandardItemModel__OnColumnsRemoved(maxHandle, new MaxQModelIndex(parent), start, end);
}

void MaxQStandardItemModel::onDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight) {
	_qt_qstandarditemmodel_QStandardItemModel__OnDataChanged(maxHandle, new MaxQModelIndex(topLeft), new MaxQModelIndex(bottomRight));
}

void MaxQStandardItemModel::onHeaderDataChanged(Qt::Orientation orientation, int first, int last) {
	_qt_qstandarditemmodel_QStandardItemModel__OnHeaderDataChanged(maxHandle, static_cast<int>(orientation), first, last);
}

void MaxQStandardItemModel::onLayoutAboutToBeChanged() {
	_qt_qstandarditemmodel_QStandardItemModel__OnLayoutAboutToBeChanged(maxHandle);
}

void MaxQStandardItemModel::onLayoutChanged() {
	_qt_qstandarditemmodel_QStandardItemModel__OnLayoutChanged(maxHandle);
}

void MaxQStandardItemModel::onModelAboutToBeReset() {
	_qt_qstandarditemmodel_QStandardItemModel__OnModelAboutToBeReset(maxHandle);
}

void MaxQStandardItemModel::onModelReset() {
	_qt_qstandarditemmodel_QStandardItemModel__OnModelReset(maxHandle);
}

void MaxQStandardItemModel::onRowsAboutToBeInserted(const QModelIndex & parent, int start, int end) {
	_qt_qstandarditemmodel_QStandardItemModel__OnRowsAboutToBeInserted(maxHandle, new MaxQModelIndex(parent), start, end);
}

void MaxQStandardItemModel::onRowsAboutToBeMoved(const QModelIndex & sourceParent, int sourceStart, int sourceEnd, const QModelIndex & destinationParent, int destinationRow) {
	_qt_qstandarditemmodel_QStandardItemModel__OnRowsAboutToBeMoved(maxHandle, new MaxQModelIndex(sourceParent), sourceStart, sourceEnd, new MaxQModelIndex(destinationParent), destinationRow);
}

void MaxQStandardItemModel::onRowsAboutToBeRemoved(const QModelIndex & parent, int start, int end) {
	_qt_qstandarditemmodel_QStandardItemModel__OnRowsAboutToBeRemoved(maxHandle, new MaxQModelIndex(parent), start, end);
}

void MaxQStandardItemModel::onRowsInserted(const QModelIndex & parent, int start, int end) {
	_qt_qstandarditemmodel_QStandardItemModel__OnRowsInserted(maxHandle, new MaxQModelIndex(parent), start, end);
}

void MaxQStandardItemModel::onRowsMoved(const QModelIndex & sourceParent, int sourceStart, int sourceEnd, const QModelIndex & destinationParent, int destinationRow) {
	_qt_qstandarditemmodel_QStandardItemModel__OnRowsMoved(maxHandle, new MaxQModelIndex(sourceParent), sourceStart, sourceEnd, new MaxQModelIndex(destinationParent), destinationRow);
}

void MaxQStandardItemModel::onRowsRemoved(const QModelIndex & parent, int start, int end) {
	_qt_qstandarditemmodel_QStandardItemModel__OnRowsRemoved(maxHandle, new MaxQModelIndex(parent), start, end);
}


// *********************************************

MaxQStandardItemModel * bmx_qt_qstandarditemmodel_create(BBObject * handle, QObject * parent) {
	return new MaxQStandardItemModel(handle, parent);
}

MaxQModelIndex * bmx_qt_qstandarditemmodel_createindex(MaxQStandardItemModel * model, int row, int col, MaxQStandardItem * parent) {
	return new MaxQModelIndex(model->doCreateIndex(row, col, parent));
}

void bmx_qt_qstandarditemmodel_dataChanged(MaxQStandardItemModel * model, MaxQModelIndex * index1, MaxQModelIndex * index2) {
	model->itemChanged(index1->Index(), index2->Index());
}

void bmx_qt_qstandarditemmodel_dobegininsertrows(MaxQStandardItemModel * model, MaxQModelIndex * index, int row, int count) {
	model->doBeginInsertRows((index) ? index->Index() : QModelIndex(), row, count);
}

void bmx_qt_qstandarditemmodel_doendinsertrows(MaxQStandardItemModel * model) {
	model->doEndInsertRows();
}

void bmx_qt_qstandarditemmodel_dobeginremoverows(MaxQStandardItemModel * model, MaxQModelIndex * index, int row, int count) {
	model->doBeginRemoveRows((index) ? index->Index() : QModelIndex(), row, count);
}

void bmx_qt_qstandarditemmodel_doendremoverows(MaxQStandardItemModel * model) {
	model->doEndRemoveRows();
}

MaxQModelIndex * bmx_qt_qstandarditemmodel_index(MaxQStandardItemModel * model, int row, int column, MaxQModelIndex * parent) {
	return new MaxQModelIndex(model->index(row, column, (parent) ? parent->Index() : QModelIndex()));
}

// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
