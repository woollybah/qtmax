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

MaxQItemSelection::MaxQItemSelection(const QItemSelection & s)
	: selection(s)
{
}

MaxQItemSelection::~MaxQItemSelection()
{
}

QItemSelection & MaxQItemSelection::Selection() {
	return selection;
}

// *********************************************

MaxQItemSelectionModel::MaxQItemSelectionModel(BBObject * handle, QAbstractItemModel * model)
	: maxHandle(handle), QItemSelectionModel(model)
{
	qbind(this, handle);
}

MaxQItemSelectionModel::~MaxQItemSelectionModel()
{
	qunbind(this);
}


// *********************************************

void bmx_qt_qitemselection_free(MaxQItemSelection * selection) {
	delete selection;
}

int bmx_qt_qitemselection_contains(MaxQItemSelection * selection, MaxQModelIndex * index) {
	return static_cast<int>(selection->Selection().contains(index->Index()));
}

BBObject * bmx_qt_qitemselection_indexes(MaxQItemSelection * selection) {
	return bmx_qt_qmodelindex_createarrayfromlist(selection->Selection().indexes());
}

void bmx_qt_qitemselection_selectrange(MaxQItemSelection * selection, MaxQModelIndex * topLeft, MaxQModelIndex * bottomRight) {
	selection->Selection().select(topLeft->Index(), bottomRight->Index());
}

// *********************************************

QItemSelectionModel::SelectionFlags bmx_qt_intToSelectionFlag(int s) {
	QItemSelectionModel::SelectionFlags flags;
	
	if (s & 0x0001) flags |= QItemSelectionModel::Clear;
	if (s & 0x0002) flags |= QItemSelectionModel::Select;
	if (s & 0x0004) flags |= QItemSelectionModel::Deselect;
	if (s & 0x0008) flags |= QItemSelectionModel::Toggle;
	if (s & 0x0010) flags |= QItemSelectionModel::Current;
	if (s & 0x0020) flags |= QItemSelectionModel::Rows;
	if (s & 0x0040) flags |= QItemSelectionModel::Columns;
	
	return flags;
}

QItemSelectionModel * bmx_qt_qitemselectionmodel_create(BBObject * handle, QAbstractItemModel * model) {
	return new MaxQItemSelectionModel(handle, model);
}

void bmx_qt_qitemselectionmodel_clear(QItemSelectionModel * model) {
		model->clear();
}

void bmx_qt_qitemselectionmodel_clearselection(QItemSelectionModel * model) {
	model->clearSelection();
}

int bmx_qt_qitemselectionmodel_columnintersectsselection(QItemSelectionModel * model, int column, MaxQModelIndex * parent) {
	return static_cast<int>(model->columnIntersectsSelection(column, parent->Index()));
}

MaxQModelIndex * bmx_qt_qitemselectionmodel_currentindex(QItemSelectionModel * model) {
	return new MaxQModelIndex(model->currentIndex());
}

int bmx_qt_qitemselectionmodel_hasselection(QItemSelectionModel * model) {
	return static_cast<int>(model->hasSelection());
}

int bmx_qt_qitemselectionmodel_iscolumnselected(QItemSelectionModel * model, int column, MaxQModelIndex * parent) {
	return static_cast<int>(model->isColumnSelected(column, parent->Index()));
}

int bmx_qt_qitemselectionmodel_isrowselected(QItemSelectionModel * model, int row, MaxQModelIndex * parent) {
	return static_cast<int>(model->isRowSelected(row, parent->Index()));
}

int bmx_qt_qitemselectionmodel_isselected(QItemSelectionModel * model, MaxQModelIndex * index) {
	return static_cast<int>(model->isSelected(index->Index()));
}

void bmx_qt_qitemselectionmodel_reset(QItemSelectionModel * model) {
	model->reset();
}

int bmx_qt_qitemselectionmodel_rowintersectsselection(QItemSelectionModel * model, int row, MaxQModelIndex * parent) {
	return static_cast<int>(model->rowIntersectsSelection(row, parent->Index()));
}

void bmx_qt_qitemselectionmodel_selectindex(QItemSelectionModel * model, MaxQModelIndex * index, int command) {
	model->select(index->Index(), bmx_qt_intToSelectionFlag(command));
}

BBObject * bmx_qt_qitemselectionmodel_selectedcolumns(QItemSelectionModel * model, int row) {
	return bmx_qt_qmodelindex_createarrayfromlist(model->selectedColumns(row));
}

BBObject * bmx_qt_qitemselectionmodel_selectedindexes(QItemSelectionModel * model) {
	return bmx_qt_qmodelindex_createarrayfromlist(model->selectedIndexes());
}

BBObject * bmx_qt_qitemselectionmodel_selectedrows(QItemSelectionModel * model, int column) {
	return bmx_qt_qmodelindex_createarrayfromlist(model->selectedRows(column));
}

void bmx_qt_qitemselectionmodel_setcurrentindex(QItemSelectionModel * model, MaxQModelIndex * index, int command) {
	model->setCurrentIndex(index->Index(), bmx_qt_intToSelectionFlag(command));
}

MaxQItemSelection * bmx_qt_qitemselectionmodel_selection(QItemSelectionModel * model) {
	return new MaxQItemSelection(model->selection());
}


// NOTES :
// The moc4glue.cpp file is generated by running :  moc.sh
// It generates the custom Signal/Slot handler code that Qt uses.
// The file only needs to be re-generated whenever a new slot is added/changed to a class,
// or a new class includes the Q_OBJECT macro.
// Oh.. and it NEEDS to be at the bottom of this file, because of declarations and whatnot.

#include "moc4glue.cpp"
