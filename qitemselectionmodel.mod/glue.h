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

#ifndef MAX_QT_QITEMSELECTIONMODEL
#define MAX_QT_QITEMSELECTIONMODEL

#include "../core.mod/glue.h"
#include "../qabstractitemmodel.mod/glue.h"
#include <QtCore>
#include <QItemSelection>

class MaxQItemSelectionModel;
class MaxQItemSelection;

extern "C" {

#include <blitz.h>

	void _qt_qitemselectionmodel_QItemSelectionModel__OnCurrentChanged(BBObject * handle, MaxQModelIndex * current, MaxQModelIndex * previous);
	void _qt_qitemselectionmodel_QItemSelectionModel__OnCurrentColumnChanged(BBObject * handle, MaxQModelIndex * current, MaxQModelIndex * previous);
	void _qt_qitemselectionmodel_QItemSelectionModel__OnCurrentRowChanged(BBObject * handle, MaxQModelIndex * current, MaxQModelIndex * previous);
	void _qt_qitemselectionmodel_QItemSelectionModel__OnSelectionChanged(BBObject * handle, MaxQItemSelection * selected, MaxQItemSelection * deselected);

	void bmx_qt_qitemselection_free(MaxQItemSelection * selection);
	int bmx_qt_qitemselection_contains(MaxQItemSelection * selection, MaxQModelIndex * index);
	BBObject * bmx_qt_qitemselection_indexes(MaxQItemSelection * selection);
	void bmx_qt_qitemselection_selectrange(MaxQItemSelection * selection, MaxQModelIndex * topLeft, MaxQModelIndex * bottomRight);



	QItemSelectionModel * bmx_qt_qitemselectionmodel_create(BBObject * handle, QAbstractItemModel * model);
	void bmx_qt_qitemselectionmodel_clear(QItemSelectionModel * model);
	void bmx_qt_qitemselectionmodel_clearselection(QItemSelectionModel * model);
	int bmx_qt_qitemselectionmodel_columnintersectsselection(QItemSelectionModel * model, int column, MaxQModelIndex * parent);
	MaxQModelIndex * bmx_qt_qitemselectionmodel_currentindex(QItemSelectionModel * model);
	int bmx_qt_qitemselectionmodel_hasselection(QItemSelectionModel * model);
	int bmx_qt_qitemselectionmodel_iscolumnselected(QItemSelectionModel * model, int column, MaxQModelIndex * parent);
	int bmx_qt_qitemselectionmodel_isrowselected(QItemSelectionModel * model, int row, MaxQModelIndex * parent);
	int bmx_qt_qitemselectionmodel_isselected(QItemSelectionModel * model, MaxQModelIndex * index);
	void bmx_qt_qitemselectionmodel_reset(QItemSelectionModel * model);
	int bmx_qt_qitemselectionmodel_rowintersectsselection(QItemSelectionModel * model, int row, MaxQModelIndex * parent);
	void bmx_qt_qitemselectionmodel_selectindex(QItemSelectionModel * model, MaxQModelIndex * index, int command);
	BBObject * bmx_qt_qitemselectionmodel_selectedcolumns(QItemSelectionModel * model, int row);
	BBObject * bmx_qt_qitemselectionmodel_selectedindexes(QItemSelectionModel * model);
	BBObject * bmx_qt_qitemselectionmodel_selectedrows(QItemSelectionModel * model, int column);
	void bmx_qt_qitemselectionmodel_setcurrentindex(QItemSelectionModel * model, MaxQModelIndex * index, int command);
	MaxQItemSelection * bmx_qt_qitemselectionmodel_selection(QItemSelectionModel * model);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxQItemSelectionModel : public QItemSelectionModel
{
	Q_OBJECT
	
public:
	MaxQItemSelectionModel(BBObject * handle, QAbstractItemModel * model);
	~MaxQItemSelectionModel();
	
private:	
	BBObject * maxHandle;

private slots:
	void onCurrentChanged(const QModelIndex & current, const QModelIndex & previous);
	void onCurrentColumnChanged(const QModelIndex & current, const QModelIndex & previous);
	void onCurrentRowChanged(const QModelIndex & current, const QModelIndex & previous);
	void onSelectionChanged(const QItemSelection & selected, const QItemSelection & deselected);

};

class MaxQItemSelection
{
public:
	MaxQItemSelection(const QItemSelection & s);
	~MaxQItemSelection();
	
	QItemSelection & Selection();

private:
	QItemSelection selection;
};

#endif
