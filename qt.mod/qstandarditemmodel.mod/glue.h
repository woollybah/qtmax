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

#ifndef MAX_QT_QSTANDARDITEMMODEL
#define MAX_QT_QSTANDARDITEMMODEL

#include "../core.mod/glue.h"
#include <QtCore>
#include <QStandardItemModel>

class MaxQStandardItemModel;


extern "C" {

#include <blitz.h>


}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


class MaxQStandardItemModel : public QStandardItemModel
{
	Q_OBJECT

public:
	MaxQStandardItemModel(BBObject * handle, QObject * parent);
	~MaxQStandardItemModel();

private:
	BBObject * maxHandle;

private slots:
	void onItemChanged(QStandardItem * item);
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
	void oModelReset();
	void onRowsAboutToBeInserted(const QModelIndex & parent, int start, int end);
	void onRowsAboutToBeMoved(const QModelIndex & sourceParent, int sourceStart, int sourceEnd, const QModelIndex & destinationParent, int destinationRow);
	void onRowsAboutToBeRemoved(const QModelIndex & parent, int start, int end);
	void onRowsInserted(const QModelIndex & parent, int start, int end);
	void onRowsMoved(const QModelIndex & sourceParent, int sourceStart, int sourceEnd, const QModelIndex & destinationParent, int destinationRow);
	void onRowsRemoved(const QModelIndex & parent, int start, int end);

};

#endif
