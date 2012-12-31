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

#ifndef MAX_QT_QABSTRACTITEMMODEL
#define MAX_QT_QABSTRACTITEMMODEL

#include "../core.mod/glue.h"
#include <QtCore>
#include <QAbstractItemModel>
#include <QModelIndex>

class MaxQModelIndex;

extern "C" {

#include <blitz.h>

	BBObject * _qt_qabstractitemmodel_QModelIndex__newArray(int size);
	void _qt_qabstractitemmodel_QModelIndex__setArrayItem(BBObject * array, int index, MaxQModelIndex * value);

	MaxQModelIndex * bmx_qt_qmodelindex_child(MaxQModelIndex * index, int row, int column);
	int bmx_qt_qmodelindex_column(MaxQModelIndex * index);
	int bmx_qt_qmodelindex_flags(MaxQModelIndex * index);
	void bmx_qt_qmodelindex_internalid(MaxQModelIndex * index, BBInt64 * id);
	void * bmx_qt_qmodelindex_internalpointer(MaxQModelIndex * index);
	int bmx_qt_qmodelindex_isequal(MaxQModelIndex * index, MaxQModelIndex * other);
	int bmx_qt_qmodelindex_islessthan(MaxQModelIndex * index, MaxQModelIndex * other);
	int bmx_qt_qmodelindex_isnotequal(MaxQModelIndex * index, MaxQModelIndex * other);
	int bmx_qt_qmodelindex_isvalid(MaxQModelIndex * index);
	const QAbstractItemModel * bmx_qt_qmodelindex_model(MaxQModelIndex * index);
	MaxQModelIndex * bmx_qt_qmodelindex_parent(MaxQModelIndex * index);
	int bmx_qt_qmodelindex_row(MaxQModelIndex * index);
	MaxQModelIndex * bmx_qt_qmodelindex_sibling(MaxQModelIndex * index, int row, int column);
	void bmx_qt_qmodelindex_free(MaxQModelIndex * index);


	BBObject * bmx_qt_qmodelindex_createarrayfromlist(const QModelIndexList & list);
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQModelIndex
{
public:
	MaxQModelIndex(const QModelIndex & i);
	~MaxQModelIndex();

	QModelIndex & Index();

private:
	QModelIndex index;
};

#endif
