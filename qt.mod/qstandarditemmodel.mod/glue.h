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

#ifndef MAX_QT_QSTANDARDITEMMODEL
#define MAX_QT_QSTANDARDITEMMODEL

#include "../core.mod/glue.h"
#include "../qabstractitemmodel.mod/glue.h"
#include "../qstandarditem.mod/glue.h"
#include "../qcolor.mod/glue.h"
#include "../qicon.mod/glue.h"
#include "../qbrush.mod/glue.h"
#include "../qfont.mod/glue.h"
#include <QtCore>
#include <QAbstractItemModel>

class MaxQStandardItemModel;


extern "C" {

#include <blitz.h>

	MaxQModelIndex * bmx_qt_qstandarditemmodel_createindex(MaxQStandardItemModel * model, int row, int col, MaxQStandardItem * parent);
	MaxQStandardItem * _qt_qstandarditemmodel_QStandardItemModel__itemFromIndex(BBObject * handle, MaxQModelIndex * parent);
	MaxQModelIndex * _qt_qstandarditemmodel_QStandardItemModel__indexFromItem(BBObject * handle, BBObject * item);
	int _qt_qstandarditemmodel_QStandardItemModel__columnCount(BBObject * handle, MaxQModelIndex * parent);
	int _qt_qstandarditemmodel_QStandardItemModel__rowCount(BBObject * handle, MaxQModelIndex * parent);
	int _qt_qstandarditemmodel_QStandardItemModel__setDataInt(BBObject * handle, MaxQModelIndex * index, int role, int value);
	int _qt_qstandarditemmodel_QStandardItemModel__setDataString(BBObject * handle, MaxQModelIndex * index, int role, BBString * value);
	int _qt_qstandarditemmodel_QStandardItemModel__setDataObject(BBObject * handle, MaxQModelIndex * index, int role, BBObject * value);
	int _qt_qstandarditemmodel_QStandardItemModel__setDataColor(BBObject * handle, MaxQModelIndex * index, int role, MaxQColor * value);
	int _qt_qstandarditemmodel_QStandardItemModel__setDataIcon(BBObject * handle, MaxQModelIndex * index, int role, MaxQIcon * value);
	int _qt_qstandarditemmodel_QStandardItemModel__setDataPixmap(BBObject * handle, MaxQModelIndex * index, int role, MaxQPixmap * value);
	int _qt_qstandarditemmodel_QStandardItemModel__setDataBrush(BBObject * handle, MaxQModelIndex * index, int role, MaxQBrush * value);
	int _qt_qstandarditemmodel_QStandardItemModel__setDataFont(BBObject * handle, MaxQModelIndex * index, int role, MaxQFont * value);
	int _qt_qstandarditemmodel_QStandardItemModel__getDataInt(BBObject * handle, MaxQModelIndex * index, int role);
	BBString * _qt_qstandarditemmodel_QStandardItemModel__getDataString(BBObject * handle, MaxQModelIndex * index, int role);
	BBObject * _qt_qstandarditemmodel_QStandardItemModel__getDataObject(BBObject * handle, MaxQModelIndex * index, int role);
	void * _qt_qstandarditemmodel_QStandardItemModel__getDataType(BBObject * handle, MaxQModelIndex * index, int role, int * type);
	int _qt_qstandarditemmodel_QStandardItemModel__insertRows(BBObject * handle, int row, int count, MaxQModelIndex * parent);
	int _qt_qstandarditemmodel_QStandardItemModel__removeRows(BBObject * handle, int row, int count, MaxQModelIndex * parent);

	void _qt_qstandarditemmodel_QStandardItemModel__OnColumnsAboutToBeInserted(BBObject * handle , MaxQModelIndex * index, int start, int end);
	void _qt_qstandarditemmodel_QStandardItemModel__OnColumnsAboutToBeMoved(BBObject * handle, MaxQModelIndex * sourceParent, int sourceStart, int sourceEnd, MaxQModelIndex * destinationParent, int destinationColumn);
	void _qt_qstandarditemmodel_QStandardItemModel__OnColumnsAboutToBeRemoved(BBObject * handle, MaxQModelIndex * parent, int start, int end);
	void _qt_qstandarditemmodel_QStandardItemModel__OnColumnsInserted(BBObject * handle, MaxQModelIndex * parent, int start, int end);
	void _qt_qstandarditemmodel_QStandardItemModel__OnColumnsMoved(BBObject * handle, MaxQModelIndex * sourceParent, int sourceStart, int sourceEnd, MaxQModelIndex * destinationParent, int destinationColumn);
	void _qt_qstandarditemmodel_QStandardItemModel__OnColumnsRemoved(BBObject * handle, MaxQModelIndex * parent, int start, int end);
	void _qt_qstandarditemmodel_QStandardItemModel__OnDataChanged(BBObject * handle, MaxQModelIndex * topLeft, MaxQModelIndex * bottomRight);
	void _qt_qstandarditemmodel_QStandardItemModel__OnHeaderDataChanged(BBObject * handle, int orientation, int first, int last);
	void _qt_qstandarditemmodel_QStandardItemModel__OnLayoutAboutToBeChanged(BBObject * handle);
	void _qt_qstandarditemmodel_QStandardItemModel__OnLayoutChanged(BBObject * handle);
	void _qt_qstandarditemmodel_QStandardItemModel__OnModelAboutToBeReset(BBObject * handle);
	void _qt_qstandarditemmodel_QStandardItemModel__OnModelReset(BBObject * handle);
	void _qt_qstandarditemmodel_QStandardItemModel__OnRowsAboutToBeInserted(BBObject * handle, MaxQModelIndex * parent, int start, int end);
	void _qt_qstandarditemmodel_QStandardItemModel__OnRowsAboutToBeMoved(BBObject * handle, MaxQModelIndex * sourceParent, int sourceStart, int sourceEnd, MaxQModelIndex * destinationParent, int destinationRow);
	void _qt_qstandarditemmodel_QStandardItemModel__OnRowsAboutToBeRemoved(BBObject * handle, MaxQModelIndex * parent, int start, int end);
	void _qt_qstandarditemmodel_QStandardItemModel__OnRowsInserted(BBObject * handle, MaxQModelIndex * parent, int start, int end);
	void _qt_qstandarditemmodel_QStandardItemModel__OnRowsMoved(BBObject * handle, MaxQModelIndex * sourceParent, int sourceStart, int sourceEnd, MaxQModelIndex * destinationParent, int destinationRow);
	void _qt_qstandarditemmodel_QStandardItemModel__OnRowsRemoved(BBObject * handle, MaxQModelIndex * parent, int start, int end);


	MaxQStandardItemModel * bmx_qt_qstandarditemmodel_create(BBObject * handle, QObject * parent);
	void bmx_qt_qstandarditemmodel_dataChanged(MaxQStandardItemModel * model, MaxQModelIndex * index1, MaxQModelIndex * index2);
	void bmx_qt_qstandarditemmodel_dobegininsertrows(MaxQStandardItemModel * model, MaxQModelIndex * index, int row, int count);
	void bmx_qt_qstandarditemmodel_doendinsertrows(MaxQStandardItemModel * model);
	void bmx_qt_qstandarditemmodel_dobeginremoverows(MaxQStandardItemModel * model, MaxQModelIndex * index, int row, int count);
	void bmx_qt_qstandarditemmodel_doendremoverows(MaxQStandardItemModel * model);
	MaxQModelIndex * bmx_qt_qstandarditemmodel_index(MaxQStandardItemModel * model, int row, int column, MaxQModelIndex * parent);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


class MaxQStandardItemModel : public QAbstractItemModel
{
	Q_OBJECT

public:
	MaxQStandardItemModel(BBObject * handle, QObject * parent);
	~MaxQStandardItemModel();

	virtual int	columnCount(const QModelIndex & parent = QModelIndex()) const;
	virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	virtual QModelIndex	parent(const QModelIndex & child) const;
	virtual int	rowCount(const QModelIndex & parent = QModelIndex()) const;
	QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
	virtual bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
	virtual bool insertRows(int row, int count, const QModelIndex & parent = QModelIndex());
	virtual bool removeRows(int row, int count, const QModelIndex & parent = QModelIndex());

	QModelIndex doCreateIndex(int row, int col, MaxQStandardItem * parent);
	void itemChanged(const QModelIndex & index1, const QModelIndex & index2);
	void doBeginInsertRows(const QModelIndex & index, int row, int count);
	void doEndInsertRows();
	void doBeginRemoveRows(const QModelIndex & index, int row, int count);
	void doEndRemoveRows();

private:
	BBObject * maxHandle;

private slots:
	void onColumnsAboutToBeInserted(const QModelIndex & parent, int start, int end);
	void onColumnsAboutToBeMoved(const QModelIndex & sourceParent, int sourceStart, int sourceEnd, const QModelIndex & destinationParent, int destinationColumn);
	void onColumnsAboutToBeRemoved(const QModelIndex & parent, int start, int end);
	void onColumnsInserted(const QModelIndex & parent, int start, int end);
	void onColumnsMoved(const QModelIndex & sourceParent, int sourceStart, int sourceEnd, const QModelIndex & destinationParent, int destinationColumn);
	void onColumnsRemoved(const QModelIndex & parent, int start, int end);
	void onDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
	void onHeaderDataChanged(Qt::Orientation orientation, int first, int last);
	void onLayoutAboutToBeChanged();
	void onLayoutChanged();
	void onModelAboutToBeReset();
	void onModelReset();
	void onRowsAboutToBeInserted(const QModelIndex & parent, int start, int end);
	void onRowsAboutToBeMoved(const QModelIndex & sourceParent, int sourceStart, int sourceEnd, const QModelIndex & destinationParent, int destinationRow);
	void onRowsAboutToBeRemoved(const QModelIndex & parent, int start, int end);
	void onRowsInserted(const QModelIndex & parent, int start, int end);
	void onRowsMoved(const QModelIndex & sourceParent, int sourceStart, int sourceEnd, const QModelIndex & destinationParent, int destinationRow);
	void onRowsRemoved(const QModelIndex & parent, int start, int end);

};

#endif
